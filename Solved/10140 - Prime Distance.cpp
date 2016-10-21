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
static const int MAX_PRIMES = 47000;
static const int MAX_DIFF = 1000000;

vector<bool> primer;
vi primes;
vector<bool> mprimes(47000, true);

void sieve() {
    mprimes[1] = false;
    primes.push_back(2);
    for (int i = 3; i < MAX_PRIMES; i+=2) {
        if (mprimes[i]) {
            primes.push_back(i);
            for (int j = i+i+i; j < MAX_PRIMES; j+=i+i) {
                mprimes[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    sieve();
    int L, U;
    while (cin >> L >> U) {
        int N = (U-L)+1;
        primer.assign(N, true);

        int sqU = sqrt(U);
        for (int i = 0; i < primes.sz; i++) {
            if (primes[i] > sqU) break;

            int startv = 0;
            if (L % primes[i] == 0) 
                startv = 0;
            else  {
                startv = primes[i] - (L % primes[i]);
                if (startv < 0) startv+=primes[i];
            }

            for (; startv < N; startv += primes[i]) {
                primer[startv] = false;
            }

            // When the prime lands within L & U
            if (primes[i] >= L && primes[i] <= U)
                primer[primes[i]-L] = true;
        }

        if (L == 1) primer[0] = false;

        int c1 = 0, c2 = 0, d1 = 0, d2 = 0;
        int prev = -1;
        for (int i = 0; i < primer.sz; i++) {
            if (primer[i]) {
                if (prev != -1) {
                    if (!c2) {
                        c1 = prev+L;
                        c2 = i+L;
                    }
                    else if (c2 - c1 > i - prev) {
                        c1 = prev+L;
                        c2 = i+L;
                    }

                    if (!d2) {
                        d1 = prev+L;
                        d2 = i+L;
                    }
                    else if (d2 - d1 < i - prev) {
                        d1 = prev+L;
                        d2 = i+L;
                    }
                }

                prev = i;
            }
        }

        if (c2 == 0)
            cout << "There are no adjacent primes." << endl;
        else {
            cout << c1 << "," << c2 << " are closest, " << d1 << "," << d2 << " are most distant." << endl;
        }

    }

    //////////////end////////////////
    return 0;
}
