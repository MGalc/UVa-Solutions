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
#define Idot(a,b) ((conj(a)*(b)).X)
#define IX real()
#define IY imag()
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
static constexpr int maxN = 31624;
vi primes;

void sieve() {
    primes.clear();
    primes.push_back(2);
    bitset<maxN> mprimes;

    for (int i = 3; i < maxN; i+=2) {
        if (!mprimes[i]) {
            primes.push_back(i);
            for (int j = i+i+i; j < maxN; j+=i+i) {
                mprimes[j] = true;
            }
        }
    }
}

int numdivs(int n) {
    int sqn = sqrt(n);
    int factors = 1;
    for (int i = 0; i < primes.sz; i++) {
        if (primes[i] > sqn) break;
        if (n % primes[i] == 0) {
            int pow = 0;
            while (n % primes[i] == 0) {
                pow++;
                n /= primes[i];
            }
            factors *= pow+1;
        }
    }

    if (n > 1)
        factors *= 2;

    return factors;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    sieve();
    int T;
    cin >> T;
    while (T--) {
        int L, U;
        cin >> L >> U;
        int mxdivs = 0, num = 0;
        for (int i = L; i <= U; i++) {
            int f = numdivs(i);
            if (f > mxdivs) {
                num = i;
                mxdivs = f;
            }
        }

        cout << "Between " << L << " and " << U << ", " << num << " has a maximum of " << mxdivs << " divisors." << endl;
    }

    //////////////end////////////////
    return 0;
}
