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
int N, M;
vii adj;
vector<bool> taken;
vi dist;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case #" << tt << ":" << endl;

        cin >> N >> M;

        adj.assign(N+M, vi(N+M, INF));
        //for (int i = 0; i < N+M; i++) adj[i][i] = 0;

        int edgenum = N;
        rep(i, M) {
            int x, y;
            cin >> x >> y;
            adj[x][edgenum] = 1;
            adj[y][edgenum] = 1;
            adj[edgenum][x] = 1;
            adj[edgenum][y] = 1;
            edgenum++;
        }

        for (int k = 0; k < edgenum; k++) {
            for (int i = 0; i < edgenum; i++) {
                for (int j = 0; j < edgenum; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        int mx = INF;
        for (int i = 0; i < edgenum; i++) {
            int lmax = 0;
            rep(j, N) {
                lmax = max(lmax, adj[i][j]);
            }
            mx = min(mx, lmax);
        }

        cout << mx << endl << endl;
    }

    //////////////end////////////////
    return 0;
}
