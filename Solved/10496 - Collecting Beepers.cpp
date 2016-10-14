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

int N;
pii bl[15];
int dp[15][1 << 11];

int f(int loc, int mask) {
    if (popc(mask) == N) 
        return abs(bl[loc].first- bl[0].first) + abs(bl[loc].second - bl[0].second);

    if (dp[loc][mask] != -1)
        return dp[loc][mask];


    int minval = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i))
            continue;
        minval = min(minval, f(i+1, mask | (1 << i)) + abs(bl[loc].first- bl[i+1].first) + abs(bl[loc].second - bl[i+1].second));

    }

    return dp[loc][mask] = minval;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        memset(dp, -1, sizeof dp);
        int wx, wy;
        cin >> wx >> wy;
        int x, y;
        cin >> x >> y;

        cin >> N;
        bl[0] = mp(x, y);

        rep(i, N) {
            cin >> x >> y;
            bl[i+1] = mp(x, y);
        }

        cout << "The shortest path has length " << f(0, 0) << endl;
    }

    //////////////end////////////////
    return 0;
}
