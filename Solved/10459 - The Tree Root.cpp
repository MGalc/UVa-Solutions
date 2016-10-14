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
int N;
vi high, sechigh, totals;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;

    for (int i = 0; i < adj[v].sz; i++) {
        int next = adj[v][i];
        if (visited[next]) continue;
        dfs(next);
        sechigh[v] = max(sechigh[v], high[next] + 1);
        if (high[v] < sechigh[v]) swap(high[v], sechigh[v]);
    }
}

void dfs2(int v, int size) {
    visited[v] = true;
    totals[v] = size;

    for (int i = 0; i < adj[v].sz; i++) {
        int next = adj[v][i];
        if (visited[next]) continue;
        int nextv;
        if (high[next] + 1 == high[v])
            nextv = sechigh[v];
        else
            nextv = high[v];
        dfs2(next, max(size,nextv)+1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N) {
        adj.assign(N, vi());
        high.assign(N, 0);
        sechigh.assign(N, 0);
        totals.assign(N, 0);
        rep(i, N) {
            int n;
            cin >> n;
            rep(j, n) {
                int in;
                cin >> in;
                adj[i].push_back(in-1);
            }
        }

        visited.assign(N, false);
        dfs(0);
        visited.assign(N, false);
        dfs2(0, 0);

        int largest = 0;
        int smallest = INF;
        rep(i, N) {
            totals[i] = max(totals[i], max(high[i], sechigh[i]));
            largest = max(largest, totals[i]);
            smallest = min(smallest, totals[i]);
        }

        cout << "Best Roots  :";
        rep(i, N) {
            if (totals[i] == smallest)
                cout << " " << i + 1;
        }
        cout << endl;
        cout << "Worst Roots :";
        rep(i, N) {
            if (totals[i] == largest)
                cout << " " << i + 1;
        }
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
