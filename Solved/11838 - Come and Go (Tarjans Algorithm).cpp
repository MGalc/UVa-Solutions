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
vii adj;
vi low, num, instack;
stack<int> st;
int nextnum, scccount;

void dfs(int u) {
    low[u] = num[u] = nextnum++;
    instack[u] = true;
    st.push(u);

    rep(i, adj[u].sz) {
        int v = adj[u][i];
        if (num[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instack[v]) 
            low[u] = min(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        scccount++;
        int next = -1;
        while (next != u) {
            next = st.top();
            instack[next] = false;
            st.pop();
        } 
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N >> M, N || M) {
        adj.assign(N, vi());
        low.assign(N, -1);
        num.assign(N, -1);
        instack.assign(N, false);
        while (!st.empty()) st.pop();
        nextnum = scccount = 0;

        rep(i, M) {
            int v, w, p;
            cin >> v >> w >> p;
            v--; w--;
            adj[v].push_back(w);
            if (p == 2) {
                adj[w].push_back(v);
            }
        }

        for (int i = 0; i < N; i++) {
            if (num[i] == -1)
                dfs(i);
        }

        if (scccount > 1)
            cout << "0" << endl;
        else cout << "1" << endl;
    }

    //////////////end////////////////
    return 0;
}
