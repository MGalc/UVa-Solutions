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

const int maxN = 50;
int cols[maxN];
vii adj;
list<int> path;
int N;
int first, last;

void eulerpath(int loc) {
    if (first == -1) first = loc;
    last = loc;
    for (int i = 0; i < maxN; i++) {
        if (adj[loc][i] <= 0) continue;
         
        while (adj[loc][i]) {
            adj[loc][i]--;
            adj[i][loc]--;

            eulerpath(i);
            cout << i+1 << " " << loc+1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case #" << tt << endl;

        memset(cols, 0, sizeof cols);
        adj.assign(maxN, vi(maxN, 0));
        cin >> N;
        rep(i, N) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            adj[x][y]++;
            adj[y][x]++;

            cols[y]++;
            cols[x]++;
        }

        path.clear();

        int mini = 0, start = 0;
        bool bad = false;
        rep(i, maxN) {
            if (cols[i] % 2 == 1) {
                bad = true;
                goto end;
            }
            if (cols[i] > mini) {
                start = i;
                mini = cols[i];
            }
        }

        first = -1, last = -1;
        eulerpath(start);

        end:

        if (bad) {
            cout << "some beads may be lost" << endl;
        }
        if (tt != T) cout << endl;
    }

    //////////////end////////////////
    return 0;
}
