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
vi dfsnum;
vi dfslow;
vi parent;
int num, totalart;

void dfs(int u) {

    dfsnum[u] = num;
    dfslow[u] = num;
    num++;

    int children = 0;
    bool isart = false;
    for (int i = 0; i < adj[u].sz; i++) {
        int v = adj[u][i];
        if (dfsnum[v] == -1) {
            children++;

            parent[v] = u;
            dfs(v);
            dfslow[u] = min(dfslow[u], dfslow[v]);

            if (parent[u] != -1 && dfslow[v] >= dfsnum[u])
                isart = true;
        }
        else if (parent[u] != v)
            dfslow[u] = min(dfslow[u], dfsnum[v]);
    }

    if (parent[u] == -1 && children >= 2)
        isart = true;

    if (isart)
        totalart++;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N) {
        num = totalart = 0;
        adj.assign(N, vi());
        dfslow.assign(N, -1);
        dfsnum.assign(N, -1);
        parent.assign(N, -1);

        string in;
        cin.ignore(100, '\n');
        while (getline(cin, in) && in != "0") {
            ss strin(in);
            int tok;
            int first;
            strin >> first;
            first--;
            while (strin >> tok) {
                tok--;
                adj[first].push_back(tok);
                adj[tok].push_back(first);
            }
        }

        rep(i, N) {
            if (dfsnum[i] == -1)
                dfs(i);
        }

        cout << totalart << endl;
    }

    //////////////end////////////////
    return 0;
}
