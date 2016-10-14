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
int s, t, c;
vii adj;
vii val;
int flow;
vi parent;

void augment(int loc, int minflow) {
    if (loc == s) {
        flow = minflow; return;
    }
    else if (parent[loc] != -1) {
        minflow = min(minflow, val[parent[loc]][loc]);
        augment(parent[loc], minflow);

        val[parent[loc]][loc] -= flow;
        val[loc][parent[loc]] += flow;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    int casenum = 1;
    while (cin >> N, N) {
        cout << "Network " << casenum++ << endl;
        adj.assign(N, vi());
        val.assign(N, vi(N, 0));
        cin >> s >> t >> c;
        s--;
        t--;
        rep(i, c) {
            int x, y, z;
            cin >> x >> y >> z;
            x--;
            y--;
            if (x == y) continue;
            adj[x].push_back(y);
            adj[y].push_back(x);
            val[x][y] += z;
            val[y][x] += z;
        }

        int mf = 0;
        while (1) {
            flow = 0;
            parent.assign(N, -1);
            vi dist(N, INF);
            queue<int> q;
            q.push(s);

            bool done = false;
            while (!q.empty() && !done) {
                int top = q.front();
                q.pop();

                for (int i = 0; i < adj[top].sz; i++) {
                    int v = adj[top][i];

                    if (parent[v] == -1 && val[top][v] > 0) {
                        q.push(v);
                        parent[v] = top;
                        if (v == t) {
                            done = true;
                            break;
                        }
                    }
                }
            }

            augment(t, INF);
            if (flow == 0) break;
            mf += flow;
        }

        cout << "The bandwidth is " << mf << "." << endl << endl;
    }

    //////////////end////////////////
    return 0;
}
