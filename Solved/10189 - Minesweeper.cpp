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

vi xx { -1, -1, 0, 1, 1, 1, 0, -1};
vi yy { 0, 1, 1, 1, 0, -1, -1, -1 };

vector<string> grid;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int X, Y;
    int casenum = 1;
    while (cin >> X >> Y, X || Y) {
        grid.assign(X, "");
        rep(i, X)
            cin >> grid[i];

        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (grid[i][j] == '*')
                    continue;
                int mines = 0;
                rep(k, xx.sz) {
                    int ni = i + xx[k], nj = j + yy[k];
                    if (ni < 0 || ni >= X || nj < 0 || nj >= Y) 
                        continue;
                    if (grid[ni][nj] == '*')
                        mines++;
                }
                grid[i][j] = '0' + mines;
            }
        }

        if (casenum != 1)
            cout << endl;
        cout << "Field #" << casenum++ << ":" << endl;
        rep(i, X) {
            cout << grid[i] << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
