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

const double PI = 2 * acos(0);
vector<vector<bool>> grid;
vi cutoffs;
vpii checkpoints;
int M, N;
int totalSqs;
static const int xx[] {1, 0, -1, 0};
static const int yy[] {0, 1, 0, -1};
int answer;

struct sMove {
    int x;
    int y;
    ll visited;
    int move;
    sMove(int r, int c, ll v, int m) : x(r), y(c), visited(v), move(m) {}
};

inline bool isValidTile(int x, int y) {
    return (x >= 0 && y >= 0 && x < M && y < N);
}

bool validGraph(int taken) {
    if (grid[0][1]) {
        if (taken == totalSqs)
            return true;
        else
            return false;
    }

    vector<vector<bool>> localgrid = grid;
    localgrid[0][1] = true;
    taken++;

    queue<pii> q;
    q.push(mp(0, 1));
    while (!q.empty()) {
        pii top = q.front();
        q.pop();

        rep(i, 4) {
            int nextx = top.first + xx[i];
            int nexty = top.second + yy[i];
            if (isValidTile(nextx, nexty) && !localgrid[nextx][nexty]) {
                q.push(mp(nextx, nexty));
                taken++;
                localgrid[nextx][nexty] = true;
            }
        }
    }

    return (taken == totalSqs);
}

int manhattan(int x, int y, int cp) {
    int cpx = checkpoints[cp].first;
    int cpy = checkpoints[cp].second;
    return abs(x - cpx) + abs(y - cpy);
}

void bt(int x, int y, int depth) {
    if (depth == totalSqs) {
        answer++;
        return;
    }

    rep(i, 4) {
        if (depth < cutoffs[i] && grid[checkpoints[i].first][checkpoints[i].second]) return;
        if (depth > cutoffs[i] && !grid[checkpoints[i].first][checkpoints[i].second]) return;
    }
    rep(i, 4) {
        if (depth < cutoffs[i] && cutoffs[i] < depth + manhattan(x, y, i)) return;
    }

    if (!validGraph(depth)) return;

    // Check is any neighbours only have one empty tile to go to
    // If multiple neighbours only have a single tile to go to, the graph cannot be be entirely visited.
    int oneNeighbourCnt = 0;
    int neighbourx = 0, neighboury = 0;
    rep(i, 4) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        // Make sure to check for edge case of last square. May cause WA
        if (!isValidTile(nx, ny) || grid[nx][ny] || (nx == 0 && ny == 1))
            continue;
        int totNeighbours = 0;
        rep(j, 4) {
            int nnx = nx + xx[j];
            int nny = ny + yy[j];
            if (!isValidTile(nnx, nny) || grid[nnx][nny])
                continue;
            totNeighbours++;
        }

        // Unvisited tile has no neighbours, return
        if (totNeighbours == 0)
            return;

        if (totNeighbours == 1) {
            oneNeighbourCnt++;
            neighbourx = nx;
            neighboury = ny;
        }
    }

    // Graph cannot be entirely visited now
    if (oneNeighbourCnt > 1)
        return;
    // We HAVE to go down the singular neighbour's path
    if (oneNeighbourCnt == 1)  {
        grid[neighbourx][neighboury] = true;
        bt(neighbourx, neighboury, depth+1);
        grid[neighbourx][neighboury] = false;
        return;
    }

    rep(k, 4) {
        int nextx = x + xx[k];
        int nexty = y + yy[k];
        if (!isValidTile(nextx, nexty) || grid[nextx][nexty]) continue;

        grid[nextx][nexty] = true;
        bt(nextx, nexty, depth+1);
        grid[nextx][nexty] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> M >> N, M || N) {
        cout << "Case " << casenum++ << ": ";
        answer = 0;
        totalSqs = M*N;
        grid.assign(M, vector<bool>(N, false));

        checkpoints.assign(4, {0,0});
        checkpoints[0] = mp(0, 0);
        rep(i, 3)
            cin >> checkpoints[i].first >> checkpoints[i].second;
        checkpoints[3] = mp(0, 1); // End location.

        cutoffs.assign(4, 0);
        for (int i = 0; i < 4; i++) {
            cutoffs[i] = (i+1)*totalSqs/4;
        }

        grid[0][0] = true;
        bt(0, 0, 1);

        cout << answer << endl;
    }

    //////////////end////////////////
    return 0;
}
