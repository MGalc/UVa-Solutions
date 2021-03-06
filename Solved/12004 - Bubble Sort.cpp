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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;

    ll N;

    for (int tt = 1; tt <= T; tt++) {
        cout << "Case " << tt << ": ";

        cin >> N;
        N--;

        ll res = N*(N+1)/2;

        if (res % 2 == 1) {
            cout << res << "/2" << endl;
        }
        else
            cout << res/2 << endl;

        // 1 2 3
        // 0 swaps
        //
        // 1 3 2
        // 1 swap
        //
        // 2 1 3
        // 1 swap
        //
        // 2 3 1
        // 2 swaps
        //
        // 3 1 2
        // 2 swaps
        //
        // 3 2 1
        // 3 swaps
        //

    }

    //////////////end////////////////
    return 0;
}
