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
#define eps 1e-8

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
typedef double ud;

const double PI = 2 * acos(0);
int N, gsize, S, T;
ud D;
vii matrix, adj;
vi dists;

int dfs(int loc, int flow) {
    if (flow == 0) return 0;
    if (loc == T) return flow;

    int thisloc = dists[loc];
    int totalflow = 0;
    for (int i = 0; i < adj[loc].size(); i++) {
        int next = adj[loc][i];
        if (dists[next] != thisloc + 1 || matrix[loc][next] <= 0) continue;

        int mflow = dfs(next, min(flow, matrix[loc][next]));

        if (mflow > 0) {
            totalflow += mflow;
            flow -= mflow;
            matrix[loc][next] -= mflow;
            matrix[next][loc] += mflow;

            if (flow == 0) break;
        }
    }

    return totalflow;
}

bool bfs() {
    dists.assign(gsize, -1);

    queue<int> q;
    q.push(S);
    dists[S] = 0;
    
    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = 0; i < adj[top].size(); i++) {
            int next = adj[top][i];
            if (dists[next] != -1 || matrix[top][next] <= 0) continue;

            dists[next] = dists[top] + 1;
            q.push(next);
        }
    }

    return dists[T] > 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int TT;
    cin >> TT;
    vii mtr;
    while (TT--) {
        int pengcount = 0;
        cin >> N >> D;
        gsize = N*2 + 1;
        mtr.assign(gsize, vi(gsize, 0));
        adj.assign(gsize, vi());
        S = gsize-1;

        vector<pair<ud, ud>> coords;
        rep(i, N) {
            int n, m;
            int x, y;
            cin >> x >> y >> n >> m;

            coords.push_back(mp(x, y));
            rep(j, i) {
                if (hypot(coords[j].first - x, coords[j].second - y) <= D + eps) {
                    adj[j+N].push_back(i);
                    adj[i].push_back(j+N);

                    adj[i+N].push_back(j);
                    adj[j].push_back(i+N);

                    mtr[j+N][i] = INF;
                    mtr[i+N][j] = INF;
                }
            }

            if (n > 0) {
                adj[S].push_back(i);
                adj[i].push_back(S);
                mtr[S][i] = n;
                pengcount += n;
            }

            adj[i].push_back(i+N);
            adj[i+N].push_back(i);
            mtr[i][i+N] = m;
        }

        vi locations;
        rep(i, N) {
            matrix = mtr;

            T = i;
            int tot = 0;
            while (bfs()) {
                tot += dfs(S, INF);
            }

            if (tot == pengcount) {
                locations.push_back(i);
            }
        }

        if (locations.empty()) {
            cout << "-1";
        }
        else {
            rep(i, locations.sz) {
                if (i != 0)
                    cout << " ";
                
                cout << locations[i];
            }
        }

        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
