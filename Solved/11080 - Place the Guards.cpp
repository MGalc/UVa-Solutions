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
vii adj;
vi state;
int V, E;
int todd, teven;

bool dfs(int loc, bool lstate) {
    state[loc] = lstate;
    if (lstate)
        teven++;
    else todd++;

    for (int i = 0; i < adj[loc].sz; i++) {
        if (state[adj[loc][i]] == -1) {
            if (!dfs(adj[loc][i], !lstate))
                return false;
        }
        else if (state[adj[loc][i]] == lstate)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> V >> E;
        adj.assign(V, vi());
        state.assign(V, -1);
        todd = 0, teven = 0;

        rep(i, E) {
            int f, t;
            cin >> f >> t;
            adj[f].push_back(t);
            adj[t].push_back(f);
        }

        bool good = true;
        int total = 0;
        for (int i = 0; i < V && good; i++) {
            if (state[i] == -1) {
                todd = 0, teven = 0;
                good = dfs(i, true);
                int minn = min(todd, teven);
                if (minn == 0)
                    minn++;

                total += minn;
            }
        }

        if (!good)
            cout << "-1" << endl;
        else {
            cout << to_string(total) << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
