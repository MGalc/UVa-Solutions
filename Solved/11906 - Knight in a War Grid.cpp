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

int grid[105][105];
bool visited[105][105];
int R, C, M, N, W;
int val[] {1, -1};
int odd, even;
int mi;

bool inrange(int x, int y) {
    if (x >= R || y >= C || y < 0 || x < 0 || grid[x][y] == -1)
        return false;
    return true;
}

void dfs(int x, int y) {
    grid[x][y] = 1;
    int k = 0;
    rep(i, mi) {
        rep(j, 2) {
            int xx = x + M * val[j];
            int yy = y + N * val[i];
            if (inrange(xx, yy)) {
                k++;
                if (grid[xx][yy] != 1)
                    dfs(xx, yy);
            }
        }
    }
    if (M != N) rep(i, mi) {
        rep(j, 2) {
            int xx = x + N * val[i];
            int yy = y + M * val[j];
            if (inrange(xx, yy)) {
                k++;
                if (grid[xx][yy] != 1)
                    dfs(xx, yy);
            }
        }
    }
    if (k % 2 == 0)
        even++;
    else odd++;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////
    
    int T;
    cin >> T;
    rep(tt, T) {
        cout << "Case " << tt+1 << ": ";
        odd = 0; even = 0;
        memset(grid, 0, sizeof grid);
        cin >> R >> C >> M >> N >> W;
        rep(w, W) {
            int x, y;
            cin >> x >> y;
            grid[x][y] = -1;
        }

        if (!N || !M) {
            if (M == 0)
                swap(N, M);
            mi = 1;
        }
        else mi = 2;
        dfs(0, 0);

        cout << even << " " << odd << endl;
    }

    //////////////end////////////////
    return 0;
}
