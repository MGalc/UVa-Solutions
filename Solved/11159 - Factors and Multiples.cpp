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
#define popc(x) __builtin_popcount(x)
#define INF 1e9
#define MOD 1000007

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
int X, Y;
vii adj;
vector<bool> visited;
vi parent;
int maxN = 250;

int match(int loc) {
    if (visited[loc]) return 0;
    visited[loc] = true;

    rep(i, adj[loc].sz) {
        int next = adj[loc][i];
        if (parent[next] == -1 || match(parent[next])) {
            parent[next] = loc;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case " << tt << ": ";


        adj.assign(maxN, vi());

        int in;

        cin >> X;
        vi inx(X);
        rep(i, X) {
            cin >> inx[i];
        }

        cin >> Y;
        vi iny(Y);
        rep(i, Y) {
            cin >> iny[i];
            for (int j = 0; j < X; j++) {
                if (inx[j] == 0 && iny[i] != 0) continue;
                if (iny[i] == 0 || (iny[i] / inx[j] > 0 && iny[i] % inx[j] == 0)) {
                    adj[j].push_back(X+i);
                }
            }
        }

        parent.assign(X+Y, -1);

        int total = 0;
        rep(i, X) {
            visited.assign(X+Y, false);
            total += match(i);
        }

        cout << total << endl;
    }

    //////////////end////////////////
    return 0;
}
