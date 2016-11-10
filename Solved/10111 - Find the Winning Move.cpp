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
#define Idot(a,b) ((conj(a)*(b)).X)
#define IX real()
#define IY imag()
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
vector<string> grid;

bool solved(int x, int y) {

    bool solved = false;
    if (x == y) {
        /*solved |= grid[0][0] == grid[1][1];
        solved |= grid[1][1] == grid[2][2];
        solved |= grid[0][0] == grid[1][1];*/
        solved |= ((grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]) && (grid[2][2] == grid[3][3]));
    }
    else if (x + y == 3) {
        solved |= ((grid[0][3] == grid[1][2]) && (grid[1][2] == grid[2][1]) && (grid[2][1] == grid[3][0]));
    }

    solved |= ((grid[0][y] == grid[1][y]) && (grid[1][y] == grid[2][y]) && (grid[2][y] == grid[3][y]));
    solved |= ((grid[x][0] == grid[x][1]) && (grid[x][1] == grid[x][2]) && (grid[x][2] == grid[x][3]));

    return solved;
}

bool solve(char turn, int added) {
    if (added == 16) return false;
    rep(i, 4) rep(j, 4) {
        if (grid[i][j] != '.') continue;

        bool good = false;
        grid[i][j] = turn;
        if (solved(i, j)) {
            grid[i][j] = '.';
            if (turn == 'x')
                return true;
            else return false;
        }

        bool ret = solve(turn == 'x' ? 'o' : 'x', added+1);
        grid[i][j] = '.';
        if (turn == 'x' && ret) return true;
        if (turn == 'o' && !ret) return false;
    }

    if (turn == 'o') return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string cont;
    while (cin >> cont, cont != "$") {
        grid.assign(4, "");
        rep(i, 4) cin >> grid[i];

        bool done = false;
        for (int i = 0; i < 4 && !done; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] == '.') {
                    grid[i][j] = 'x';
                    if (solved(i, j)) done = true;
                    else done = solve('o', 1);
                    grid[i][j] = '.';
                    if (done) {
                        cout << "(" << i << "," << j << ")" << endl;
                        break;
                    }
                }
            }
        }

        if (!done)
            cout << "#####" << endl;
    }

    //////////////end////////////////
    return 0;
}
