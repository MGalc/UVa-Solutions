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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N, M;
    while (cin >> N >> M) {

        vi deg(N, 0);
        vii adj(N, vi());

        int x, y;
        bool bad = false;
        vector<bool> visited(N, false);
        queue<int> q;
        if (!M) {
            bad = true; goto end;
        }
        rep(i, M) {
            cin >> x >> y;
            deg[x]++;
            deg[y]++;
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        visited[x] = true;
        q.push(x);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            rep(i, adj[top].sz) {
                int next = adj[top][i];
                if (visited[next]) continue;
                q.push(next);
                visited[next] = true;
            }
        }

        rep(i, N) {
            if (deg[i] > 0 && !visited[i]) {
                bad = true; break;
            }
            if (deg[i] % 2 == 1) {
                bad = true; break;    
            }
        }

end:
        if (bad) cout << "Not Possible" << endl;
        else cout << "Possible" << endl;
    }

    //////////////end////////////////
    return 0;
}
