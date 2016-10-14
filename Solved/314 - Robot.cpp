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

#define INF 1e9

const double PI = 2 * acos(0);
int M, N;

const int xx[] {-1, 0, 0, -1};
const int yy[] {-1, -1, 0, 0};
const int nextx[] {-1, 0, 1, 0};
const int nexty[] {0, 1, 0, -1};

vector<vector<bool>> good;
vector<vector<vi>> val;
vector<vector<int>> grid;

struct node {
public:
    int x, y, dist, dir;
    node(int nx, int ny, int ndist, int ndir) : x(nx), y(ny), dist(ndist), dir(ndir) { }
    node() {}
};

bool inline oor(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N)
        return true;
    return false;
}

void processgraph() {
    int x = 0, y = 0;
    rep(i, M) {
        rep(j, N) {
            rep(k, 4) {
                x = i + xx[k];
                y = j + yy[k];
                if (oor(x, y) || grid[x][y] == 1) {
                    good[i][j] = false; break;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> M >> N, M || N ) {

        grid.assign(M, vector<int>(N, 0));
        good.assign(M, vector<bool>(N, true));
        val.assign(M, vector<vi>(N, vi(4, INF)));

        rep(i, M) rep(j, N) cin >> grid[i][j];

        processgraph();

        int b1, b2, e1, e2;
        cin >> b1 >> b2 >> e1 >> e2;
        string facing;
        cin >> facing;
        int dir = 0;
        if (facing[0] == 'n') dir = 0;
        if (facing[0] == 'e') dir = 1;
        if (facing[0] == 's') dir = 2;
        if (facing[0] == 'w') dir = 3;

        queue<node> st;
        st.push(node(b1, b2, 0, dir));
        val[b1][b2][dir] = 0;

        while (!st.empty()) {
            int x, y;
            node top;
            top = st.front();
            st.pop();
            dir = top.dir;
            int thisval = val[top.x][top.y][top.dir];
            if (top.dist > thisval) continue;

            for (int i = 1; i <= 3; i++) {
                x = top.x + (nextx[dir] * i);
                y = top.y + (nexty[dir] * i);
                if (oor(x, y) || !good[x][y]) break;
                if (val[x][y][dir] > thisval + 1) {
                    val[x][y][dir] = thisval + 1;
                    st.push(node(x, y, thisval+1, dir));
                }
            }
            for (int i = 1; i <= 3; i++) {
                int moveval = 1;
                if (i == 2) moveval = 2;
                x = top.x;
                y = top.y;
                if (oor(x, y) || !good[x][y]) break;
                int nextdir = (top.dir + i) % 4;
                if (val[x][y][nextdir] > thisval + moveval) {
                    val[x][y][nextdir] = thisval + moveval;
                    st.push(node(x, y, thisval+moveval, nextdir));
                }
            }
        }

        int smallest = INF;
        for (int i = 0; i < 4; i++) {
            smallest = min(smallest, val[e1][e2][i]);
        }
        if (smallest == INF) {
            cout << -1 << endl;
        }
        else 
            cout << smallest << endl;

    }

    //////////////end////////////////
    return 0;
}
