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
int R, C, N;
int tiles;
vector<int> dp;
vi dirs;
vi movex {0, 1, 1, 1, 0, -1, -1, -1};
vi movey {-1, -1, 0, 1, 1, 1, 0, -1};

bool oneZero(int mask) {
    int zCount = 0;
    for (int i = 0; i < tiles; i++) {
        if (mask & (1 << i))
            zCount++;
    }
    return zCount == 1;
}

int inRange(int from, int indx) {
    bool good = true;
    int col = from % C;
    int row = from / C;
    if (movey[indx] == 1 && row == R-1) good = false;
    if (movey[indx] == -1 && row == 0) good = false;
    if (movex[indx] == 1 && col == C-1) good = false;
    if (movex[indx] == -1 && col == 0) good = false;

    return good;
}

int solve(int mask) {
    if (dp[mask] != -1)
        return dp[mask];

    if (oneZero(mask)) {
        return dp[mask] = 1;
    }

    dp[mask] = 0;
    int solutions = 0;
    for (int i = 0; i < tiles; i++) {
        if (!(mask & (1 << i))) // No blob at the location
            continue;
        rep(j, dirs.sz) {
            int jumpover = i + dirs[j]; 
            // If not in range or a blob is not there
            if (!inRange(i, j) || !(mask & (1 << jumpover))) 
                continue;

            int jumploc = i + movedirs[j];
            // If not in range or a blob is there
            if (!inRange(jumpover, j) || (mask & (1 << jumploc))) 
                continue;

            // Add new blob location and remove initial blob loc and blob we jumped over
            solutions += solve((mask | (1 << jumploc)) & ~((1 << jumpover) | (1 << i))); 
        }
    }

    return dp[mask] = solutions;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case " << tt << ": ";
        cin >> R >> C >> N;
        dp.assign(1 << (R*C), -1);
        tiles = R*C;

        int initmask = 0;
        rep(i, N) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            initmask |= 1 << (x*C + y);
        }

        dirs.clear(); // Store adjacent directions
        dirs.push_back(-C);   // Up
        dirs.push_back(-C+1); // UpRight
        dirs.push_back(1);    // Right
        dirs.push_back(C+1);  // DownRight
        dirs.push_back(C);    // Down
        dirs.push_back(C-1); // DownLeft
        dirs.push_back(-1);   // Left
        dirs.push_back(-C-1);  // UpLeft

        cout << solve(initmask) << endl;
    }

    //////////////end////////////////
    return 0;
}
