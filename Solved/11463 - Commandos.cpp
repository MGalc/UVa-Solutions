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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int TT;
    cin >> TT;
    for (int tt = 1; tt <= TT; tt++) {
        cout << "Case " << tt << ": ";

        int N, M;
        cin >> N >> M;
        vii dists(N, vi(N));
        rep(i, N) {
            rep(j, N) {
                dists[i][j] = INF;
            }
            dists[i][i] = 0;
        }

        rep(i, M) {
            int x, y;
            cin >> x >> y;
            dists[x][y] = 1;
            dists[y][x] = 1;
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
                }
            }
        }

        int s, t;
        cin >> s >> t;

        int maxdist = 0;
        for (int i = 0; i < N; i++) {
            maxdist = max(maxdist, dists[s][i] + dists[i][t]);
        }

        cout << maxdist << endl;
    }

    //////////////end////////////////
    return 0;
}
