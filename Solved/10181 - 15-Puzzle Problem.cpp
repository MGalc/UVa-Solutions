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

// This way opposite directions add up to 3.
const int xx[] {1, 0, 0, -1};
const int yy[] {0, 1, -1, 0};
const char mvs[] {'D', 'R', 'L', 'U'};

vii grid;
string steps;
bool solved;
pii zeroloc;

bool solvable() {
    int inv = 0;
    rep(i, 16) {
        if (grid[i/4][i%4] <= 1) continue;
        for (int j = i+1; j < 16; j++) {
            if (grid[j/4][j%4] == 0) continue;
            if (grid[i/4][i%4] > grid[j/4][j%4]) {
                inv++;
            }
        }
    }
    if (zeroloc.first % 2 == 0) 
        return inv % 2 == 1;
    else
        return inv % 2 == 0;
}

inline int manhattan(int x, int y) {
    int value = grid[x][y];
    if (value == 0)
        return 0;
    else
        return abs((value-1) / 4 - x) + abs((value-1) % 4 - y);
}

inline bool validTile(int x, int y) {
    return (x >= 0 && y >= 0 && x < 4 && y < 4);
}

int maximumDepth;
int IDA(int depth, int laststep, int manhat) {
    if (manhat == 0) {
        maximumDepth = min(maximumDepth, depth);
        solved = true;
        cout << steps << endl;
        return 0;
    }
    if (depth + manhat > maximumDepth)
        return (depth + manhat + 3);

    int localMax = 100;
    rep(i, 4) {
        if (solved) return 0;
        if (i + laststep == 3) // Avoid going back to previous tile.
            continue;

        int nextx = zeroloc.first + xx[i];
        int nexty = zeroloc.second + yy[i];
        if (!validTile(nextx, nexty)) 
            continue;

        pii prevzero = zeroloc;

        // Update to new manhattan values and swap locations of the zero + other number.
        int newmanhat = manhat;
        newmanhat -= manhattan(nextx, nexty);
        swap(grid[zeroloc.first][zeroloc.second], grid[nextx][nexty]);
        newmanhat += manhattan(zeroloc.first, zeroloc.second);

        zeroloc = mp(nextx, nexty);
        steps.push_back(mvs[i]);

        localMax = min(localMax, IDA(depth+1, i, newmanhat));

        steps.pop_back();
        zeroloc = prevzero;
        swap(grid[zeroloc.first][zeroloc.second], grid[nextx][nexty]);
    }
    return localMax;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        steps = "";
        solved = false;

        int initManhattan = 0;
        grid.assign(4, vi(4, 0));
        int zerox = 0, zeroy = 0;
        initManhattan = 0;
        rep(i, 4) {
            rep(j, 4) {
                cin >> grid[i][j];
                initManhattan += manhattan(i, j);
                if (grid[i][j] == 0)
                    zeroloc = mp(i, j);
            }
        }

        if (!solvable()) {
            cout << "This puzzle is not solvable." << endl;
            continue;
        }

        maximumDepth = initManhattan;
        while (!solved) {
            int result = IDA(0, -4, initManhattan);
            if (!solved && maximumDepth == 45)  {
                cout << "This puzzle is not solvable." << endl;
                break;
            }
            maximumDepth = min(45, result);
        }
    }

    //////////////end////////////////
    return 0;
}
