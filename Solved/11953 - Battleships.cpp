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
int N;
vector<string> grid;
int xx[] {1, 0, -1, 0};
int yy[] {0, 1, 0, -1};

bool fill(int x, int y) {
    bool res = true;
    if (grid[x][y] == '@')
        res = false;
    grid[x][y] = '.';

    rep(i, 4) {
        int nextx = x + xx[i];
        int nexty = y + yy[i];
        if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N || grid[nextx][nexty] == '.') 
            continue;

        res |= fill(nextx, nexty);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ": ";
        cin >> N;
        grid.assign(N, "");
        rep(i, N) {
            cin >> grid[i];
        }

        int count = 0;
        rep(i, N) {
            rep(j, N) {
                if (grid[i][j] == 'x' || grid[i][j] == '@')
                    count += fill(i, j);
            }
        }

        cout << count << endl;
    }

    //////////////end////////////////
    return 0;
}
