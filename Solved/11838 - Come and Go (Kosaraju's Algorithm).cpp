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
int N, M;
vii adj, radj;
vi st;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    rep(i, radj[u].sz) {
        int v = radj[u][i];
        if (!visited[v])
            dfs(v);
    }
}

void transpose(int u) {
    visited[u] = true;
    rep(i, adj[u].sz) {
        int v = adj[u][i];
        if (!visited[v])
            transpose(v);
    }

    st.push_back(u);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N >> M, N || M) {
        adj.assign(N, vi());
        radj.assign(N, vi());
        st.clear();

        rep(i, M) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].push_back(v);
            radj[v].push_back(u);
            if (w == 2) {
                adj[v].push_back(u);
                radj[u].push_back(v);
            }
        }

        visited.assign(N, false);
        rep(i, N) {
            if (visited[i] == false)
                transpose(i);
        }

        int tot = 0;
        visited.assign(N, false);
        for (int i = N-1; i >= 0; i--) {
            if (!visited[st[i]]) {
                tot++;
                dfs(st[i]);
            }
        }

        if (tot > 1)
            cout << "0" << endl;
        else cout << "1" << endl;
    }

    //////////////end////////////////
    return 0;
}
