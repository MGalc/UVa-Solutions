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
int N;
vii adj;
vi vals;
vi indeg;
vector<bool> visited;
int total = 0;

void dfs(int loc, int val) {
    if (vals[loc] == -1) {
        total += val;
        return;
    }
    indeg[loc]--;
    vals[loc] += val;
    if (indeg[loc] > 0) {
        return;
    }

    rep(i, adj[loc].sz) {
        dfs(adj[loc][i], vals[loc]);
    }
}

void setupindegrees(int loc) {
    visited[loc] = true;

    rep(i, adj[loc].sz) {
        int next = adj[loc][i];
        if (!visited[next])
            setupindegrees(next);
        indeg[next]++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    bool start = true;
    while (cin >> N) {
        if (start) start = false;
        else cout << endl;
        vals.assign(N, 0);
        indeg.assign(N, 0);
        adj.assign(N, vi());
        total = 0;

        rep(i, N) {
            int n;
            cin >> n;
            if (!n){
                vals[i] = -1;
                continue;
            } 

            rep(j, n) {
                int x;
                cin >> x;
                adj[i].push_back(x);
                //indeg[x]++;
            }
        }

        visited.assign(N, false);
        setupindegrees(0);
        dfs(0, 1);

        cout << total << endl;
    }

    //////////////end////////////////
    return 0;
}
