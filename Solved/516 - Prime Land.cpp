#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define popc(x) __builtin_popcount(x)
#define INF 1e9
#define MOD 1000007

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const double PI = 2 * acos(0);
static const int LVAL = 32767;
static const int SQLVAL = 32767;
vi primes;

void calcprimes() {
    vector<bool> mprimes(SQLVAL+1, true);
    primes.push_back(2);

    for (int i = 3; i <= SQLVAL; i+=2) {
        if (mprimes[i]) {
            for (int j = i+i+i; j <= SQLVAL; j+= i+i) {
                mprimes[j] = false;
            }
            primes.push_back(i);
        }
    }
}

void getfactors(vi& facs, vi& pows, int n) {
    for (int i = 0; i < primes.sz; i++) {
        int prime = primes[i];
        if (n % prime == 0) {
            int p = 0;
            while (n % prime == 0) {
                p++;
                n /= prime;
            }
            facs.push_back(prime);
            pows.push_back(p);
        }

        if (n == 1) break;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    calcprimes();
    string in;
    while (getline(cin, in), in != "0") {
        ss strin(in);
        int N;
        int val = 1;
        while (strin >> N) {
            int p;
            strin >> p;
            while (p--) {
                val *= N;
            }
        }

        vi facs, pows;
        getfactors(facs, pows, val-1);

        for (int i = facs.sz-1; i >= 0; i--) {
            if (i != facs.sz-1) cout << " ";
            cout << facs[i] << " " << pows[i];
        }

        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
