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
typedef pair<ll, int> vv;

const double PI = 2 * acos(0);
int M, N;
vector<vector<pair<ll, int>>> adj;
vector<bool> taken;
priority_queue<vv, vector<vv>, greater<vv> > edges;

void process(int loc) {
    taken[loc] = true;
    rep(i, adj[loc].sz) edges.push(adj[loc][i]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> M >> N, M || N) {
        taken.assign(M, false);
        adj.assign(M, vector<pair<ll, int>>());
        edges = priority_queue<vv, vector<vv>, greater<vv> >();
        ll total = 0;
        rep(i, N) {
            int x, y;
            ll z;
            cin >> x >> y >> z;
            total += z;
            adj[x].push_back(mp(z, y));
            adj[y].push_back(mp(z, x));
        }

        process(0);
        int nodestaken = 1;
        ll spent = 0;
        while (nodestaken != M && !edges.empty()) {
            pair<ll, int> cost = edges.top();
            edges.pop();
            if (!taken[cost.second]) {
                spent += cost.first;
                nodestaken++;
                process(cost.second);
            }
        }

        cout << total - spent << endl;
    }

    //////////////end////////////////
    return 0;
}
