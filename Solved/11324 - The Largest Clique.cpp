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
#define popc32(x) __builtin_popcount(x)
#define popc64(x) __builtin_popcountll(x)
#define MOD 1000007
#define INF 1e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);
int V, E;
vector<vector<bool>> G;
vii Gedges;

int nextnum;
vi dfslo;
vi dfsnum;
vector<bool> onstack;
stack<int> curscc;

void getSCCs(int loc) {
    dfsnum[loc] = nextnum++;
    dfslo[loc] = dfsnum[loc];
    onstack[loc] = true;
    curscc.push(loc);
    for (int i = 0; i < Gedges[loc].sz; i++) {
        int next = Gedges[loc][i];
        if (dfsnum[next] == -1) {
            getSCCs(next);
            dfslo[loc] = min(dfslo[loc], dfslo[next]);
        }
        else if (onstack[next]) {
            dfslo[loc] = min(dfslo[loc], dfsnum[next]);
        }
    }

    if (dfslo[loc] == dfsnum[loc]) {
        while (curscc.top() != loc) {
            onstack[curscc.top()] = false;
            dfslo[curscc.top()] = dfslo[loc];
            curscc.pop();
        }
        onstack[curscc.top()] = false;
        curscc.pop();
    }
}

vii dirscc;
vi sccnodes;

int dfscontr(int loc) {
    int maxv = 0;
    for (int i = 0; i < dirscc[loc].sz; i++) {
        maxv = max(maxv, dfscontr(dirscc[loc][i]));
    }

    return maxv + sccnodes[loc];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> V >> E;
        G.assign(V, vector<bool>(V, 0));
        Gedges.assign(V, vi());
        rep(i, E) {
            int a, b;
            cin >> a >> b;
            //G[a-1][b-1] = true;
            Gedges[a-1].push_back(b-1);
        }

        nextnum = 0;
        dfsnum.assign(V, -1);
        dfslo.assign(V, -1);
        onstack.assign(V, false);
        curscc = stack<int>();

        for (int i = 0; i < V; i++) {
            if (dfsnum[i] == -1) {
                getSCCs(i);
            }
        }

        dirscc.assign(V, vi());
        sccnodes.assign(V, 0);
        rep(i, V) {
            sccnodes[dfslo[i]]++;
        }

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < Gedges[i].sz; j++) {
                int next = Gedges[i][j];
                if (dfslo[i] == dfslo[next] || G[dfslo[i]][dfslo[next]])
                    continue;

                G[dfslo[i]][dfslo[next]] = true;
                dirscc[dfslo[i]].push_back(dfslo[next]);
            }
        }

        int maxv = 0;
        rep(i, V) {
            if (dirscc[i].empty())
                maxv = max(maxv, sccnodes[i]);
            else
                maxv = max(maxv, dfscontr(i));
        }

        cout << maxv << endl;
    }

    //////////////end////////////////
    return 0;
}
