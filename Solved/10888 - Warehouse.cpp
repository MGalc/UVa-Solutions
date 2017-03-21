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
#define popc32(x) __builtin_popcount(x)
#define popc64(x) __builtin_popcountll(x)
#define MOD 1000007
#define INF 1e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);
int N, M, S, T;
int totsize;
int startv, endv;
vii grid;
vii adj;
vii visadj;

void findpaths(int x, int y) {
    static const vi dx { -1, 0, 1, 0 };
    static const vi dy { 0, 1, 0, -1 };
    int indx = grid[x][y];
    indx--;

    vii visited(N, vi(M, -1));
    queue<pii> q;
    q.push(mp(x,y));
    visited[x][y] = 0;
    while (!q.empty()) {
        pii top = q.front();
        q.pop();

        rep(i, dx.sz) {
            int nextx = top.first + dx[i];
            int nexty = top.second + dy[i];
            if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M) continue;
            if (visited[nextx][nexty] != -1) continue;
            if (grid[nextx][nexty] == INF) continue;

            if (grid[nextx][nexty] < 0) {
                int nextindx = startv-1-grid[nextx][nexty];
                adj[indx][nextindx] = visited[top.first][top.second] + 1;
                adj[nextindx][indx] = visited[top.first][top.second] + 1;
                visadj[indx][nextindx] = 1;
            }

            visited[nextx][nexty] = visited[top.first][top.second] + 1;

            q.push(mp(nextx, nexty));
        }
    }
}

int findflow() {
    vi prev(totsize, 0);
    prev[S] = S;
    vi dist(totsize, INF);
    dist[S] = 0;

    rep(k, totsize-1) {
        rep(i, totsize) {
            rep(j, totsize) {
                if (visadj[i][j] <= 0)
                    continue;
                if (i >= startv && i < S && j < startv) {
                    if (dist[j] > dist[i] - adj[i][j]) {
                        dist[j] = dist[i] - adj[i][j];
                        prev[j] = i;
                    }
                }
                else if (dist[j] > dist[i] + adj[i][j]) {
                    prev[j] = i;
                    dist[j] = dist[i] + adj[i][j];
                }
            }
        }
    }


    rep(i, totsize) {
        rep(j, totsize) {
            if (visadj[i][j] <= 0)
                continue;
            if (dist[j] > dist[i] + adj[i][j]) {
                return 0;
            }
        }
    }

    if (dist[T] == INF)
        return 0;

    int curloc = T;
    while (prev[curloc] != curloc) {
        visadj[prev[curloc]][curloc]--;

        visadj[curloc][prev[curloc]]++;
        curloc = prev[curloc];
    }

    return dist[T];
}

int maxFlowMinCost() {
    int flow = 0, thisflow = 0;
    do {
        flow += thisflow;
        thisflow = findflow();
    } while (thisflow > 0);

    return flow;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    //volatile int v = 0;
    //rep(i, 5e8)
        //v+=2;

    int TT;
    cin >> TT;
    while (TT--) {
        cin >> N >> M;

        grid.assign(N, vi(M, 0));
        startv = 1, endv = -1;
        rep(i, N) {
            string in;
            cin >> in;
            rep(j, in.sz) {
                if (in[j] == 'B') {
                    grid[i][j] = startv++;
                }
                else if (in[j] == 'X') {
                    grid[i][j] = endv--;
                }
                else if (in[j] == '#') {
                    grid[i][j] = INF;
                }
            }
        }

        startv--; endv++;
        totsize = startv-endv+2;
        S = totsize-2;
        T = totsize-1;
        adj.assign(totsize, vi(totsize, 0));
        visadj.assign(totsize, vi(totsize, 0));

        rep(i, N) {
            rep(j, grid[i].sz) {
                if (grid[i][j] != INF && grid[i][j] > 0) {
                    findpaths(i, j);
                }
            }
        }

        rep(i, startv)
            visadj[S][i] = 1;
        rep(i, -endv)
            visadj[startv+i][T] = 1;

        cout << maxFlowMinCost() << endl;
    }

    //////////////end////////////////
    return 0;
}
