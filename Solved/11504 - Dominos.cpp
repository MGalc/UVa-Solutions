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
vi low, num;
vector<bool> instack, child;
vii adj;
stack<int> st;
int curscc, nextnum;
vi sccindx;

void dfs(int u) {
    num[u] = low[u] = nextnum++;
    instack[u] = true;
    st.push(u);
    for (int i = 0; i < adj[u].sz; i++) {
        int v = adj[u][i];
        if (num[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instack[v])
            low[u] = min(num[v], low[u]);

        if (sccindx[v] != -1) {
            child[sccindx[v]] = true;
        }
    }

    if (low[u] == num[u]) {
        int val = -1;
        while(val != u) {
            val = st.top();
            st.pop();
            sccindx[val] = curscc;
            instack[val] = false;
        }
        child.push_back(false);
        curscc++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;

        curscc = 0;
        while (!st.empty()) st.pop();
        low.assign(N, -1);
        num.assign(N, -1);
        instack.assign(N, false);
        adj.assign(N, vi());
        sccindx.assign(N, -1);
        child.clear();
        nextnum = 0;

        rep(i, M) {
            int x, y;
            cin >> x >> y;
            adj[x-1].push_back(y-1);
        }

        rep(i, N) {
            if (num[i] == -1)
                dfs(i);
        }

        int tot = 0;
        rep(i, child.sz) {
            if (!child[i])
                tot++;
        }

        cout << tot << endl;
    }

    //////////////end////////////////
    return 0;
}
