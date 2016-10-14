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
int N, M;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int TT;
    cin >> TT;
    while (TT--) {
        cin >> N >> M;
        vector<vpii> adj(N, vpii());
        vi dist(N, INF);
        dist[0] = 0;

        rep(i, M) {
            int x, y, w;
            cin >> x >> y >> w;
            adj[x].push_back(mp(w, y));
        }
        

        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < adj[j].sz; k++) {
                    pii ok = adj[j][k];
                    dist[ok.second] = min(dist[ok.second], dist[j] + ok.first);
                }
            }
        }

        bool wormholeloop = false;
        for (int j = 0; j < N && !wormholeloop; j++) {
            for (int k = 0; k < adj[j].sz; k++) {
                pii ok = adj[j][k];
                if (dist[j] + ok.first < dist[ok.second]) {
                    wormholeloop = true;
                    break;
                }
            }
        }

        cout << (wormholeloop ? "possible" : "not possible") << endl;
    }

    //////////////end////////////////
    return 0;
}
