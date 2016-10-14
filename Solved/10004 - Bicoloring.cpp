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
int N, E;
vii adj;
vector<int> state;

bool dfs(int loc, bool tstate) {
    state[loc] = tstate;

    rep(i, adj[loc].sz) {
        if (state[adj[loc][i]] == -1) {
            if (!dfs(adj[loc][i], !tstate))
                return false;
        }
        else if (state[adj[loc][i]] == tstate)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N, N) {
        cin >> E;
        adj.assign(N, vi());
        state.assign(N, -1);
        rep(i, E) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        bool good = dfs(0, true);

        if (good) 
            cout << "BICOLORABLE." << endl;
        else 
            cout << "NOT BICOLORABLE." << endl;
    }

    //////////////end////////////////
    return 0;
}
