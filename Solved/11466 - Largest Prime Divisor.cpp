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
static const ll maxN = 100000000000000;
static const ll sqmaxN = 10000000;

vi primes;

void sieve() {
    bitset<10000100> mprimes;
    primes.push_back(2);
    for (int i = 3; i <= sqmaxN; i+=2) {
        if (!mprimes[i]) {
            primes.push_back(i);
            for (int j = i+i+i; j <= sqmaxN; j+=i+i) {
                mprimes[j] = true;
            }
        }
    }
}

ll largestfac(ll N) {
    ll maxp = 0;
    ll divp = 0;
    ll sqN = sqrt(N);
    for (int i = 0; i < primes.sz; i++) {
        int prime = primes[i];
        if (prime > sqN) break;
        if (N % prime == 0) {
            maxp = max(maxp, (ll)prime);
            divp++;
            while (N % prime == 0) {
                N /= prime;
            }
        }
    }

    if (N > 1) {
        maxp = max(maxp, N);
        divp++;
    }

    if (divp > 1)
        return maxp;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    sieve();

    ll N;
    while (cin >> N, N) {
        if (N < 0) N = -N;
        cout << largestfac(N) << endl;
    }

    //////////////end////////////////
    return 0;
}
