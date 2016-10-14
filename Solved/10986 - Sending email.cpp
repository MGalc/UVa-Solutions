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
    cin >> N;
    for (int tt = 1; tt <= N; tt++) {
        cout << "Case #" << tt << ": ";
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        vector<vector<pii>> graph(n);
        vi dist(n, INF);
        rep(i, m) {
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].push_back(mp(y, w));
            graph[y].push_back(mp(x, w));
        }

        priority_queue<pii, vpii, greater<pii>> q;
        q.push(mp(0, S));
        dist[S] = 0;

        while (!q.empty()) {
            pii top = q.top();
            q.pop();
            int x = top.second;
            if (top.first > dist[x]) continue;
            if (x == T) break;
            rep(i, graph[x].sz) {
                int w = top.first + graph[x][i].second;
                int nextx = graph[x][i].first;
                if (w < dist[nextx]) {
                    dist[nextx] = w;
                    q.push(mp(w, nextx));
                }
            }
        }

        if (dist[T] == INF) {
            cout << "unreachable" << endl;
        }
        else {
            cout << dist[T] << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
