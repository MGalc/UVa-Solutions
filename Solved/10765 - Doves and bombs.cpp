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
vi parent;
vi dfsnum;
vi dfslow;
int N, M, curnum;
vpii best;

void dfs(int u) {
    dfsnum[u] = dfslow[u] = curnum++;

    int cuts = 0;
    for (int i = 0; i < adj[u].sz; i++) {
        int v = adj[u][i];
        if (dfsnum[v] == -1) {
            parent[v] = u;
            dfs(v);
            if (dfslow[v] >= dfsnum[u])
                cuts++;
            dfslow[u] = min(dfslow[u], dfslow[v]);
        }
        else if (parent[u] != v)
            dfslow[u] = min(dfslow[u], dfslow[v]);
    }
    //if (parent[u] != -1 && dfslow[u] >= dfsnum[parent[u]])
        //cuts++;
    if (parent[u] != -1)
        cuts++;
    best.push_back(mp(cuts, u));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N >> M, N || M) {
        adj.assign(N, vi());
        parent.assign(N, -1);
        dfsnum.assign(N, -1);
        dfslow.assign(N, -1);
        best.clear();
        curnum = 0;
        int x, y;
        while (cin >> x >> y, x != -1 && y != -1) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        rep(i, N) {
            if (dfsnum[i] == -1)
                dfs(i);
        }
        auto sorter = [] (pii x, pii y) {
            if (x.first > y.first) return true;
            else if (x.first == y.first) {
                return x.second < y.second;
            }
            else return false;
        };
        sort(all(best), sorter);
        rep(i, M) {
            cout << best[i].second << " " << best[i].first << endl;
        }
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
