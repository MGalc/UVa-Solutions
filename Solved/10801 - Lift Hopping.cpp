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

    int n, k;
    while (cin >> n >> k) {
        vi time(n);
        rep(i, n) {
            cin >> time[i];
        }

        string instr;
        getline(cin, instr);

        vector<vector<pii>> graph(100, vpii());

        rep(i, n) {
            getline(cin, instr);
            ss strs(instr);
            vi floors;

            int floor;
            while (strs >> floor) {
                for (int j = 0; j < floors.sz; j++) {
                    int dist = abs(floors[j] - floor) * time[i];
                    graph[floor].push_back(mp(dist, floors[j]));
                    graph[floors[j]].push_back(mp(dist, floor));
                }
                floors.push_back(floor);
            }
        }

        vi dist(100, INF);

        dist[0] = 0;

        priority_queue<pii, vpii, greater<pii>> q;
        q.push(mp(0, 0));

        while (!q.empty()) {
            pii top = q.top();
            int x = top.second, v = top.first;
            q.pop();

            if (x == k) break;
            
            if (v > dist[x]) continue;

            if (x != 0) v += 60;

            for (int i = 0; i < graph[x].sz; i++) {
                int nextx = graph[x][i].second;
                int w = v + graph[x][i].first;

                if (w < dist[nextx]) {
                    q.push(mp(w, nextx));
                    dist[nextx] = w;
                }
            }
        }

        if (dist[k] == INF) cout << "IMPOSSIBLE" << endl;
        else cout << dist[k] << endl;
    }

    //////////////end////////////////
    return 0;
}
