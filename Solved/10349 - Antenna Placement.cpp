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
vector<string> graph;
vii adj;
int X, Y;
vector<int> match;
vector<bool> visited;

inline int getv(int a, int b) {
    return (Y * a) + b;
}

int matcher(int loc) {
    if (visited[loc]) return 0;
    visited[loc] = true;
    
    rep(i, adj[loc].sz) {
        int next = adj[loc][i];
        if (match[next] == -1 || matcher(match[next])) {
            match[next] = loc; return 1;
        }
    }

    return 0;
}

/*vii vis;
int xx[] {1, 0, -1, 0};
int yy[] {0, 1, 0, -1};
int bfs(int x, int y) {
    int tot = 0;
    queue<pii> q;
    q.push(mp(x, y));
    vis[x][y] = true;

    while (!q.empty()) {
        tot++;
        pii top = q.front();
        q.pop();
        rep(i, 4) {
            int nextx = top.first + xx[i];
            int nexty = top.second + yy[i];
            if (nextx < 0 || nextx >= X || nexty < 0 || nexty >= Y || graph[nextx][nexty] != '*') continue;
            if (vis[nextx][nexty]) continue;
            vis[nextx][nexty] = true;
            q.push(mp(nextx, nexty));
        }
    }
    return tot;
}
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> X >> Y;

        graph.assign(X, "");
        vector<bool> starred(X*Y, false);
        rep(i, X) {
            cin >> graph[i];
        }

        int stars = 0;
        adj.assign(X * Y, vi());
        rep(i, X) {
            rep(j, Y) {
                if (graph[i][j] == 'o') continue;
                stars++;
                if ((i + j) % 2 != 0) continue;
                starred[getv(i, j)] = true;

                if (i+1 < X && graph[i+1][j] == '*') adj[getv(i, j)].push_back(getv(i+1, j));
                if (i-1 >= 0 && graph[i-1][j] == '*') adj[getv(i, j)].push_back(getv(i-1, j));
                if (j+1 < Y && graph[i][j+1] == '*') adj[getv(i, j)].push_back(getv(i, j+1));
                if (j-1 >= 0 && graph[i][j-1] == '*') adj[getv(i, j)].push_back(getv(i, j-1));
            }
        }

        match.assign(X*Y, -1);
        int tot = 0;
        rep(i, X*Y) {
            visited.assign(X*Y, false);
            if (match[i] != -1 || !starred[i]) continue;
            match[i] = i;
            tot += matcher(i);
        }

        cout << stars - tot << endl;

    }

    //////////////end////////////////
    return 0;
}
