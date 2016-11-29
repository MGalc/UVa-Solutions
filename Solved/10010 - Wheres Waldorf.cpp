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

static const int xx[] {1, -1, 0, 0, 1, -1, -1, 1};
static const int yy[] {0, 0, 1, -1, 1, 1, -1, -1};
const double PI = 2 * acos(0);
vector<string> grid;
int M, N, T;

pii solve(const string& in) {
    pii best = mp(INF, INF);

    rep(re, 8) {
        bool done = false;
        rep(i, M) if (done) break; else rep(j, N) {
            if (grid[i][j] != in[0]) continue;

            int endx = i + (int)in.size() * xx[re];
            if (xx[re] < 0) endx++;
            if (xx[re] > 0) endx--;
            int endy = j + (int)in.size() * yy[re];
            if (yy[re] < 0) endy++;
            if (yy[re] > 0) endy--;

            if (endx < 0 || endx >= M || endy < 0 || endy >= N) continue;

            rep(k, in.sz) {
                if (grid[i+k*xx[re]][j+k*yy[re]] != in[k]) break;
                if (k == in.sz - 1) done = true;
            }

            if (done) {
                best = min(best, mp(i, j));
                break;
            }
        }
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        if (tt != 1) cout << endl;
        cin >> M >> N;
        grid.assign(M, "");
        rep(i, M) {
            cin >> grid[i];
            rep(j, N) grid[i][j] = tolower(grid[i][j]);
        }

        int Q;
        cin >> Q;
        rep(i, Q) {
            string in;
            cin >> in;
            rep(j, in.sz) in[j] = tolower(in[j]);
            pii best = solve(in);

            cout << best.first + 1 << " " << best.second + 1 << endl;

        }
    }

    //////////////end////////////////
    return 0;
}
