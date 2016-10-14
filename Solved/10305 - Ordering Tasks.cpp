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
bool visited[110];
vii adj;
vi order;

void topsort(int loc) {
    visited[loc] = true;

    rep(i, adj[loc].sz) {
        if (!visited[adj[loc][i]])
            topsort(adj[loc][i]);
    }

    order.push_back(loc+1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N >> M, N || M) {
        order.clear();
        memset(visited, false, sizeof visited);
        adj.assign(N, vi());
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            adj[x-1].push_back(y-1);
        }

        rep(i, N) {
            if (!visited[i])
                topsort(i);
        }

        string strout;
        for (auto i = order.rbegin(); i != order.rend(); i++) {
            if (i != order.rbegin())
                strout += " ";
            strout += to_string(*i);
        }

        cout << strout << endl;
    }

    //////////////end////////////////
    return 0;
}
