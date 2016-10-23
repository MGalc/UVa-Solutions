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
static const int MAXN = INT_MAX;
vector<int> primes;

void sieve() {
    primes.clear();
    long sqn = sqrt(MAXN);
    primes.push_back(2);
    vector<bool> mprimes(sqn+1, true);

    for (long i = 3; i <= sqn; i+=2) {
        if (mprimes[i]) {
            primes.push_back(i);
            for (long j = i+i+i; j <= sqn; j += i+i) {
                mprimes[j] = false;
            }
        }
    }
}

void getfactors(vector<long>& factors, long N) {
    int sqn = sqrt(N);
    for (long i = 0; i < primes.sz; i++) {
        if (primes[i] > sqn) break;
        while (N % primes[i] == 0) {
            N /= primes[i];
            factors.push_back(primes[i]);
        }
        if (N == 1) break;
    }

    if (N > 1) 
        factors.push_back(N);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////
    
    sieve();
    long N;
    while (cin >> N, N) {
        vector<long> factors;
        long n = N;
        if (N < 0) {
            factors.push_back(-1);
            n = -N;
        }

        getfactors(factors, n);

        cout << N << " =";

        rep(i, factors.sz) {
            if (!i)
                cout << " " << factors[i];
            else
                cout << " x " << factors[i];
        }

        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
