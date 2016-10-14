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
vii graph;
vector<vector<vii>> dp;
vector<vector<bool>> ip;
int N, K;
int xx[] {1, 0, 0};
int yy[] {0, -1, 1};
bool possible;

int bt(int x, int y, int k, int dir) {
    if (dp[dir][k][x][y] != -1) return dp[dir][k][x][y];
    if (x == N-1 && y == N-1) {
        possible = true;
        return graph[x][y];
    } 
    ip[x][y] = true;

    int total = -INF;
    bool unassigned = true;
    rep(i, 3) {
        int nextx = x + xx[i];
        int nexty = y + yy[i];
        int nextk = k;
        if (nextx >= N || nexty >= N || nexty < 0 || ip[nextx][nexty]) continue;

        if (graph[nextx][nexty] < 0) nextk++;
        if (nextk > K) continue;

        int res = bt(nextx, nexty, nextk, i);
        if (res != -INF) {
            if (unassigned) {
                total = res + graph[x][y];
                unassigned = false;
            }
            else 
                total = max(total, res + graph[x][y]);
        }
    }

    ip[x][y] = false;
    return dp[dir][k][x][y] = total;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int caseno = 1;
    while (cin >> N >> K, N || K) {
        cout << "Case " << caseno++ << ": ";

        ip.assign(N, vector<bool>(N, false));
        possible = false;
        dp.assign(3, vector<vii>(K+1, vii(N, vi(N, -1))));
        graph.assign(N, vi(N, 0));

        rep(i, N) {
            rep(j, N) {
                cin >> graph[i][j];
            }
        }

        int res;
        if (graph[0][0] < 0) {
            if (K > 0)
                res = bt(0, 0, 1, 0);
        }
        else {
            res = bt(0, 0, 0, 0);
        }

        if (possible) {
            cout << res << endl;
        }
        else cout << "impossible" << endl;

    }

    //////////////end////////////////
    return 0;
}
