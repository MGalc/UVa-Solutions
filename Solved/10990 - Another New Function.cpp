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
static constexpr int maxN = 2000010;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    vi relprimes(maxN);

    relprimes[0] = 0;
    relprimes[1] = 0;
    for (int i = 2; i < maxN; i++) relprimes[i] = i;
    bitset<maxN> mprimes;

    for (int i = 2; i < maxN; i+=2) {
        relprimes[i] -= relprimes[i] / 2;
    }

    for (int i = 3; i < maxN; i+=2) {
        if (!mprimes[i]) {
            for (int j = i; j < maxN; j+=i) {
                relprimes[j] -= relprimes[j] / i;
                mprimes[j] = true;
            }
        }
    }

    for (int i = 2; i < maxN; i++) {
        relprimes[i] = relprimes[relprimes[i]] + 1;
    }

    for (int i = 2; i < maxN; i++) {
        relprimes[i] += relprimes[i-1];
    }

    int T;
    cin >> T;
    while (T--) {
        int L, U;
        cin >> L >> U;

        cout << relprimes[U] - relprimes[L-1] << endl;
    }

    //////////////end////////////////
    return 0;
}
