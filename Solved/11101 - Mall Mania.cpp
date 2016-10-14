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
const int INF = 1e9;
int E1, E2;
vii graph;
const int MAX = 2005;
vi xx = { 1, 0, -1, 0 };
vi yy = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> E1, E1) {
        queue<pii> q;
        int maxx = 0, maxy = 0;
        graph.assign(2005, vi(2005, INF));
        rep(i, E1) {
            int x, y;
            cin >> x >> y;
            graph[x][y] = 0;
            q.push(mp(x, y));
        }
        cin >> E2;
        rep(i, E2) {
            int x, y;
            cin >> x >> y;
            graph[x][y] = -1;
        }

        int smallest = -1;
        bool done = false;
        while (!q.empty() && !done) {
            pii top = q.front();
            q.pop();
            int v = graph[top.first][top.second];

            rep(i, 4) {
                int x = top.first + xx[i];
                int y = top.second + yy[i];
                if (x < 0 || x >= MAX || y < 0 || y >= MAX) continue;

                if (graph[x][y] == INF) {
                    graph[x][y] = v+1;
                    q.push(mp(x, y));
                }
                if (graph[x][y] == -1) {
                    smallest = v+1;
                    done = true;
                    break;
                }
            }
        }

        cout << smallest << endl;
    }

    //////////////end////////////////
    return 0;
}
