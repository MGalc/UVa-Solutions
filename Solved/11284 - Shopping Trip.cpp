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

int adj[55][55];
int grid[15][15];
int cost[15];
int dp[15][1 << 15];
int fmask;
int N, M, P;

int f(int loc, int mask) {
    if (popc(mask) == P)
        return grid[loc][0];
    if (dp[loc][mask] != -1)
        return dp[loc][mask];

    int minv = grid[loc][0];
    for (int i = 1; i <= P; i++) {
        if (mask & (1 << (i-1))) continue;

        minv = min(minv, f(i, mask | (1 << (i-1))) + grid[loc][i]);
    }
    return dp[loc][mask] = minv;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        N++;
        rep(i, 15) rep(j, 1 << 15) dp[i][j] = -1;
        rep(i, 55) rep(j, 55) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = 10000000;
        }
            
        for (int i = 0; i < M; i++) {
            int x, y;
            double cost;
            cin >> x >> y >> cost;
            adj[x][y] = min(adj[x][y], (int)round(cost*100));
            adj[y][x] = min(adj[y][x], (int)round(cost*100));
        }

        rep(k, N) rep(i, N) rep(j, N) {
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }

        cin >> P;
        vector<pair<int, int>> ins;
        ins.push_back( {0, 0} );
        rep(i, P) {
            int x; double y;
            cin >> x >> y;
            ins.push_back(mp(x, round(y * 100)));
        }
        sort(all(ins));

        for (int i = 0; i < ins.size(); i++) {
            for (int j = 0; j < ins.size(); j++) {
                grid[i][j] = adj[ins[i].first][ins[j].first] - ins[j].second;
            }
        }

        int ret = f(0, 0);

        cout.width(2);
        cout.fill('0');
        if (ret < 0)  {
            cout << "Daniel can save $" << -ret/100 << ".";
        
            std::cout.fill ('0');
            std::cout.width (2);
            std::cout << right << -ret%100 << '\n';
        }
        else cout << "Don't leave the house" << endl;
    }

    //////////////end////////////////
    return 0;
}
