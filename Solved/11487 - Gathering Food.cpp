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
#define MOD 20437

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
vector<string> graph;
int xx[] {1, 0, -1, 0};
int yy[] {0, 1, 0, -1};
int dist, ways;

int bfs(pii xy, pii goal, char dest) {
    vii visited(N, vi(N, 0));
    vii dists(N, vi(N, INF));
    int founddist = INF;
    int foundcount = 0;

    queue<pair<int, pii>> q;
    q.push(mp (0, xy));
    visited[xy.first][xy.second] = 1;
    dists[xy.first][xy.second] = 0;

    while (!q.empty()) {
        int v = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (v > founddist) break;
        rep(i, 4) {
            int nextx = x + xx[i];
            int nexty = y + yy[i];
            if (nextx < 0 || nexty < 0 || nextx >= N || nexty >= N) continue;

            if (graph[nextx][nexty] == dest) {
                visited[nextx][nexty] += visited[x][y];
                founddist = dists[x][y]+1;
                foundcount++;
            }
            else if (graph[nextx][nexty] != '.') continue;
            else {
                if (dists[nextx][nexty] < v+1) continue;
                else if (dists[nextx][nexty] == v+1) {
                    visited[nextx][nexty] += visited[x][y];
                }
                else {
                    visited[nextx][nexty] = visited[x][y];
                    dists[nextx][nexty] = v+1;
                    q.push(mp(v+1, mp(nextx, nexty)));
                }
            }

        }
    }
    ways = visited[goal.first][goal.second];

    return founddist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int caseno = 1;
    while (cin >> N, N) {
        cout << "Case " << caseno++ << ": ";
        graph.assign(N, "");
        int startx = 0, starty = 0;
        vpii locs(30);
        int fn = 0;
        rep(i, N) {
            cin >> graph[i];
            rep(j, N) {
                if (graph[i][j] >= 'A' && graph[i][j] <= 'Z') {
                    locs[graph[i][j] - 'A'] = mp(i, j);
                    fn = max(fn, 1 + graph[i][j] - 'A');
                }
            }
        }
        //if (fn == 0) {
            //cout << "Impossible" << endl; continue;;
        //}

        int totways = 1, length = 0;
        bool bad = false;
        for (int c = 0; c < fn-1; c++) {
            int l = bfs(locs[c], locs[c+1], c+'A'+1);
            if (l == INF)  {
                bad = true; break;
            }
            length += l;
            totways *= ways;
            totways %= MOD;
            graph[locs[c].first][locs[c].second] = '.';
        }

        if (bad) 
            cout << "Impossible" << endl;
        else 
            cout << length << " " << totways << endl;
    }

    //////////////end////////////////
    return 0;
}
