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
static constexpr int maxN = 31625;
vi primes;

void sieve() {
    bitset<maxN> mprimes;
    primes.push_back(2);

    for (int i = 3; i < maxN; i+=2) {
        if (!mprimes[i]) {
            primes.push_back(i);
            for (int j = i+i+i; j < maxN; j+=i+i) {
                mprimes[j] = true;
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
        int init = N;
        int answ = N;
        rep(i, primes.sz) {
            if (N < primes[i]) break;
            if (N % primes[i] == 0) answ -= answ/primes[i];
            while (N % primes[i] == 0) N /= primes[i];
        }

        if (N > 1) answ -= answ/N;

        cout << answ << endl;
    }

    //////////////end////////////////
    return 0;
}
