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
static const int MAXN = 1000100;
vector<bool> mprimes(MAXN, true);
vi primes;

void sieve() {
    for (int i = 3; i < MAXN; i += 2) {
        if (mprimes[i]) {
            primes.push_back(i);
            for (int j = i+i+i; j < MAXN; j+=i+i) {
                mprimes[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    sieve();
    int N;
    while (cin >> N, N) {
        int a = 0, b = 0;

        for (int i = 0; i < primes.sz; i++) {
            if (primes[i]*2 > N) break;
            if (mprimes[N - primes[i]]) {
                a = primes[i];
                b = N - primes[i];
                break;
            }
        }
        if (!a)
            cout << "Goldbach's conjecture is wrong." << endl;
        else 
            cout << N << " = " << a << " + " << b << endl;
    }

    //////////////end////////////////
    return 0;
}
