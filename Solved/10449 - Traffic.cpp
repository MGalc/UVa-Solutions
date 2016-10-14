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

    int N;
    int cases = 1;
    while (cin >> N) {
        cout << "Set #" << cases++ << endl;
        vi traffic(N);
        rep(i, N)
            cin >> traffic[i];

        int R;
        cin >> R;
        vector<vpii> edges(N, vpii());
        rep(i, R) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            int v = traffic[y] - traffic[x];
            edges[x].push_back(mp(v * v * v, y));
        }

        vi dist(N, INF);
        if (!dist.empty()) dist[0] = 0;

        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < edges[j].sz; k++) {
                    if (dist[j] == INF) continue;
                    pii edge = edges[j][k];
                    dist[edge.second] = min(dist[edge.second], edge.first + dist[j]);
                }
            }
        }

        vector<bool> bad(N, false);
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < edges[j].sz; k++) {
                    pii edge = edges[j][k];
                    if (dist[edge.second] > edge.first + dist[j]) {
                        bad[edge.second] = true;
                        dist[edge.second] = edge.first + dist[j];
                    }
                }
            }
        }

        int q;
        cin >> q;
        rep(i, q) {
            int rq;
            cin >> rq;
            rq--;
            if (dist[rq] < 3 || bad[rq] || dist[rq] >= INF) 
                cout << "?" << endl;
            else 
                cout << dist[rq] << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
