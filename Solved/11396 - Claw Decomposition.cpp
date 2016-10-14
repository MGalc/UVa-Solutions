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
int N;
vii adj;
vi state;
bool good;

void dfs(int loc, bool tstate) {
    state[loc] = tstate;

    for (int i = 0; i < adj[loc].sz && good; i++) {
        if (state[adj[loc][i]] == -1) {
            dfs(adj[loc][i], !tstate);
        }
        else if (state[adj[loc][i]] == tstate)
            good = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N, N) {
        adj.assign(N, vi());
        state.assign(N, -1);

        int x, y;
        good = true;
        while (cin >> x >> y, x || y) {
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (int i = 0; i < N && good; i++) {
            if (state[i] == -1)
                dfs(i, true);
        }

        if (good)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    //////////////end////////////////
    return 0;
}
