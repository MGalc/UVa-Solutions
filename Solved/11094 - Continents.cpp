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
int M, N;
int X, Y;
vector<string> grid;
char match = 'w';
char fillv = 'w';
int xx[] { 1, 0, -1, 0 };
int yy[] { 0, 1, 0, -1 };

int flood(int x, int y) {
    int count = 1;
    grid[x][y] = fillv;

    rep(i, 4) {
        int nextx = x + xx[i];
        int nexty = y + yy[i];
        if (nexty < 0)
            nexty += N;
        else if (nextx < 0)
            continue;
            //nextx += M;
        else if (nextx >= M)
            continue;
            //nextx = nextx - M;
        else if (nexty >= N)
            nexty = nexty - N;

        //if (nexty < 0 || nextx < 0 || nextx >= M || nexty >= N)
            //continue;
        if (grid[nextx][nexty] == match)
            count += flood(nextx, nexty);
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> M >> N) {
        grid.assign(M, "");
        rep (i, M) {
            cin >> grid[i];
        }

        char land = 'l', sea = 'w';
        bool seaset = false;

        cin >> X >> Y;
        land = grid[X][Y];
        for (int i = 0; i < M || !seaset; i++) {
            for (int j = 0; j < N || !seaset; j++) {
                if (grid[i][j] != land) {
                    sea = grid[i][j];
                    seaset = true;
                }
            }
        }
        int mx = 0;
        if (seaset) {
            match = land;
            fillv = sea;
            flood(X, Y);

            rep(i, M) {
                rep(j, N) {
                    if (grid[i][j] == match)
                        mx = max(mx, flood(i, j));
                }
            }
        }

        cout << mx << endl;
    }

    //////////////end////////////////
    return 0;
}
