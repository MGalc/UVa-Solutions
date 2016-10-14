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

vii adj;
vi dists, sechi, hi;
pii banned;
int N;

pii diameter(int loc) {
    vector<int> visited(N, -1);
    queue<int> q;

    q.push(loc);
    visited[loc] = 0;

    int farthest = 0, indx = loc;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        rep(i, adj[top].sz) {
            int next = adj[top][i];
            if ((top == banned.first && next == banned.second) || (top == banned.second && next == banned.first)) continue;
            if (visited[next] == -1) {
                visited[next] = visited[top]+1;
                q.push(next);
                if (visited[next] > farthest) {
                    farthest = visited[next], indx = next;
                }
            }
        }
    }

    vi parent(N, -1);
    visited.assign(N, -1);

    q.empty();
    q.push(indx);
    visited[indx] = 0;
    parent[indx] = indx;

    farthest = 0;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        rep(i, adj[top].sz) {
            int next = adj[top][i];
            if ((top == banned.first && next == banned.second) || (top == banned.second && next == banned.first)) continue;
            if (visited[next] == -1) {
                visited[next] = visited[top]+1;
                parent[next] = top;
                q.push(next);
                if (visited[next] > farthest) {
                    farthest = visited[next], indx = next;
                }
            }
        }
    }

    while (parent[indx] != indx) {
        if (visited[indx] != (1+farthest)/2) indx = parent[indx];
        else break;
    }

    return mp(indx, farthest);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        adj.assign(N, vi());
        hi.assign(N, 0);
        sechi.assign(N, 0);
        dists.assign(N, 0);

        vii sedges(N, vi());
        rep(i, N-1) {
            int x, y;
            cin >> x >> y;
            x--, y--;

            adj[x].push_back(y);
            adj[y].push_back(x);
            sedges[x].push_back(y);
        }

        int mindist = INF;
        pii ban = mp(0, 0);
        pii add = mp(0, 0);
        rep(i, N) {
            rep(j, sedges[i].sz) {
                banned = mp(i, sedges[i][j]);

                pii fdi, sdi;
                fdi = diameter(i);
                sdi = diameter(sedges[i][j]);

                int newsize = max(((fdi.second+1)/2) + ((sdi.second+1)/2) + 1, max(fdi.second, sdi.second));
                if (newsize < mindist) {
                    mindist = newsize;
                    ban = mp(i, sedges[i][j]);
                    add = mp(fdi.first, sdi.first);
                }
            }
        }

        cout << mindist << endl << ban.first+1 << " " << ban.second+1 << endl << add.first+1 << " " << add.second+1 << endl;
    }

    //////////////end////////////////
    return 0;
}
