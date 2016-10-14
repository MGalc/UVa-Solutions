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
const vi xx { 0, 1, 0, -1 };
const vi yy { 1, 0, -1, 0 };
vii graph;
vii dist;
int R, C;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> R >> C;
        graph.assign(R, vi(C));
        dist.assign(R, vi(C, INF));
        rep(i, R) {
            rep(j, C) {
                cin >> graph[i][j];
            }
        }

        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
        q.push(mp(graph[0][0], mp(0, 0)));
        dist[0][0] = graph[0][0];

        while (!q.empty()) {
            pair<int, pii> top = q.top();
            q.pop();
            int v = top.first;
            int x = top.second.first, y = top.second.second;
            if (x == R-1 && y == C-1) break;
            if (v > dist[x][y]) continue;
            rep(i, 4) {
                int nextx = x + xx[i];
                int nexty = y + yy[i];
                if (nextx < 0 || nextx >= R || nexty < 0 || nexty >= C) continue;

                int nextv = v + graph[nextx][nexty];
                if (nextv >= dist[nextx][nexty]) continue;

                dist[nextx][nexty] = nextv;
                q.push(mp(nextv, mp(nextx, nexty)));
            }
        }

        cout << dist[R-1][C-1] << endl;
    }

    //////////////end////////////////
    return 0;
}
