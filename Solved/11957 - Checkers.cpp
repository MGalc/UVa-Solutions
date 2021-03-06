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
vector<string> str;
int N;
vii dp;
int xx[] {1, 1};
int yy[] {1, -1};

int bt(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];

    if (x == N-1) return 1;

    int total = 0;
    rep(i, 2) {
        int nextx = x + xx[i];
        int nexty = y + yy[i];
        if (nexty < 0 || nexty >= N) continue;
        if (str[nextx][nexty] == 'B') {
            nextx = x + xx[i]*2;
            nexty = y + yy[i]*2;
            if (nexty < 0 || nexty >= N || nextx >= N || str[nextx][nexty] == 'B') continue;
            total += bt(nextx, nexty) % MOD;
        }
        else {
            total += bt(nextx, nexty) % MOD;
        }
    }

    return dp[x][y] = total % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case " << tt << ": ";
        cin >> N;
        str.assign(N, "");
        dp.assign(N, vi(N, -1));
        int wx = -1, wy = -1;
        for (int i = N-1; i >= 0; i--) {
            cin >> str[i];
            if (wx == -1) {
                rep(j, N) {
                    if (str[i][j] == 'W')
                        wx = i, wy = j;
                }
            } 
        }

        int ret = bt(wx, wy);

        cout << ret << endl;
    }

    //////////////end////////////////
    return 0;
}
