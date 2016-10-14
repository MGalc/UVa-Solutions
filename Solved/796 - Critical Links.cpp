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
vpii critlinks;
int N, curnum;

void dfs(int loc) {
    dfsnum[loc] = dfslow[loc] = curnum++;

    for (int i = 0; i < adj[loc].sz; i++) {
        int v = adj[loc][i];
        if (dfsnum[v] == -1) {
            parent[v] = loc;
            dfs(v);

            if (dfslow[v] > dfsnum[loc]) {
                if (loc > v)
                    critlinks.push_back(mp(v, loc));
                else 
                    critlinks.push_back(mp(loc, v));
            }

            dfslow[loc] = min(dfslow[loc], dfslow[v]);
        }
        else if (parent[loc] != v)
            dfslow[loc] = min(dfslow[loc], dfslow[v]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    bool first = true;
    while (cin >> N) {
        adj.assign(N, vi());
        dfsnum.assign(N, -1);
        dfslow.assign(N, -1);
        parent.assign(N, -1);
        critlinks.clear();
        curnum = 0;

        cin.ignore(100, '\n');
        rep(i, N) {
            string line;
            getline(cin, line);
            ss in(line);
            int server;
            in >> server;
            string tmp;
            in >> tmp;
            if (tmp[1] == '0')
                continue;
            int inval;
            while (in >> inval) {
                adj[server].push_back(inval);
                adj[inval].push_back(server);
            }
        }

        rep(i, N) {
            if (dfsnum[i] == -1)
                dfs(i);
        }

        sort(all(critlinks));

        cout << critlinks.sz << " critical links" << endl;
        for (auto i : critlinks) {
            cout << i.first << " - " << i.second << endl;
        }
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
