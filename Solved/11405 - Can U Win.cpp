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
static const int gridN = 8;

int moves;
int pawns;
vs grid;
vector<vector<vii>> dp;

vi xx { -2, -1, 1, 2, 2, 1, -1, -2 };
vi yy { 1, 2, 2, 1, -1, -2, -2, -1 };

inline bool inrange(int x, int y) {
    return (x >= 0 && y >= 0 && x < gridN && y < gridN);
}

bool solved = false;
int solve(int x, int y, int depth, int pawnstaken) {
    if (depth > moves) return false;
    if (dp[x][y][depth][pawnstaken] != -1)
        return dp[x][y][depth][pawnstaken];
    if (pawnstaken == (1 << pawns) - 1) // We solved it!
        solved = true;
    if (pawns - popc32(pawnstaken) + depth > moves) // Prune some values
        return dp[x][y][depth][pawnstaken] = false;
    if (solved) return dp[x][y][depth][pawnstaken] = true;

    dp[x][y][depth][pawnstaken] = false;
    bool solvable = false;
    for (int i = 0; i < xx.sz; i++) {
        int nextx = x + xx[i];
        int nexty = y + yy[i];
        if (!inrange(nextx, nexty)) continue;
        if (grid[nextx][nexty] < pawns) // There's a pawn there
            solvable |= solve(nextx, nexty, depth+1, pawnstaken | (1 << grid[nextx][nexty]));
        else if (grid[nextx][nexty] == '.')
            solvable |= solve(nextx, nexty, depth+1, pawnstaken);
    }

    return dp[x][y][depth][pawnstaken] = solvable;
}

// CP3 book recommends solving this problem using BFS then TSP
// However, you can easily solve this problem just using DP
// The max search space is:
//     = kLocation * maxdepth * pawnspickedup
//     =    8*8    *    64    *      2^8
//     = ~ 1 million
//
// There could be more pruning done to this solution (manhattan distance),
// however it currently runs in 0.00s without
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> moves;
        grid.assign(gridN, "");
        rep(i, gridN)
            cin >> grid[i];

        pii startk;
        pawns = 0;
        rep(i, gridN) {
            rep(j, gridN) {
                if (grid[i][j] == 'k') {
                    startk = mp(i, j);
                    grid[i][j] = '.';
                }
                else if (grid[i][j] == 'P')
                    grid[i][j] = pawns++;
            }
        }

        dp.assign(gridN, vector<vii>(gridN, vii(moves+1, vi((1 << pawns), -1))));
        solved = false;
        cout << (solve(startk.first, startk.second, 0, 0) ? "Yes" : "No") << endl;

    }

    //////////////end////////////////
    return 0;
}
