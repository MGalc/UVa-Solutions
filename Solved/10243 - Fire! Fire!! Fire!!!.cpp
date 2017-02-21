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

vii edges;
vii dp;

int solve(int loc, bool taken) {
    if (dp[loc][taken] != -1) return dp[loc][taken];
    int value = taken;

    rep(i, edges[loc].sz) {
        int next = edges[loc][i];
        if (!taken) {
            value += solve(next, true);
        }
        else {
            int mini = min(solve(next, false), solve(next, true));
            value += mini;
        }
    }

    return dp[loc][taken] = value;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N) {
        vii adj(N, vi());
        rep(i, N) {
            int edges;
            cin >> edges;
            rep(j, edges) {
                int next;
                cin >> next;
                adj[i].push_back(next-1);
            }
        }

        edges.assign(N, vi());
        vector<bool> visited(N, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            rep(j, adj[i].sz) {
                int next = adj[i][j];
                if (visited[next]) continue;
                visited[next] = true;
                edges[i].push_back(next);
                q.push(next);
            }
        }

        dp.assign(N, vi(2, -1));
        if (N == 1)
            cout << "1" << endl;
        else
            cout << min(solve(0, false), solve(0, true)) << endl;
    }

    //////////////end////////////////
    return 0;
}
