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
int R, C;
int xx[] {0, 1, 0, -1};
int yy[] {1, 0, -1, 0};
vii adj;
vii matrix;

inline int getv(int x, int y) {
    return (x*C) + y;
}

void build() {
    rep(x, R) {
        rep(y, C) {
            rep(i, 4) {
                int nextx = x + xx[i];
                int nexty = y + yy[i];
                if (nextx < 0 || nextx >= R || nexty < 0 || nexty >= C) continue;

                if (matrix[x][y] < matrix[nextx][nexty]) 
                    adj[getv(x, y)].push_back(getv(nextx, nexty));
            }
        }
    }
}

vi dp;
int dfs(int loc) {
    if (dp[loc] != -1) return dp[loc];

    int maxdist = 1;
    for (int i = 0; i < adj[loc].sz; i++) {
        int next = adj[loc][i];
        maxdist = max(maxdist, dfs(next)+1);
    }

    return dp[loc] = maxdist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        string name;
        cin >> name;
        cin >> R >> C;
        int maxN = R*C;
        matrix.assign(R, vi(C));
        adj.assign(maxN, vi());

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> matrix[i][j];
            }
        }

        build();

        int mx = 0;
        dp.assign(maxN, -1);
        rep(i, maxN) {
            mx = max(mx, dfs(i));
        }

        cout << name << ": " << mx << endl;
    }

    //////////////end////////////////
    return 0;
}
