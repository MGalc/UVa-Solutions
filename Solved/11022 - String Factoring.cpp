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
#define Idot(a,b) ((conj(a)*(b)).X)
#define IX real()
#define IY imag()
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
vii dp;
string input;

int solve(int x, int y) {
    //BABABABABAB
    if (x > y || y >= input.sz) return 0;
    if (dp[x][y] != INF) return dp[x][y];
    for (int i = 1; i <= (y-x+1) / 2; i++) {
        int matched = 1;
        bool done = false;
        int k = 0;
        int nextx = x + i;
        while (!done) {
            if (y < nextx + i - 1) {
                done = false;
                break;
            }
            for (int j = 0; j < i; j++) {
                if (input[x+j] != input[nextx+j]) {
                    done = true;
                    break;
                }
            }
            if (!done) {
                matched++;
                nextx += i;
            }
        }
        if (matched) {
            dp[x][y] = min(dp[x][y], solve(x, x+i-1) + solve(nextx, y));
        }
        //dp[x][y] = min(dp[x][y], solve(x+i, y) + i);
    }
    for (int i = 1; i <= y-x; i++)
        dp[x][y] = min(dp[x][y], solve(x, x+i-1) + solve(x+i, y));

    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> input, input != "*") {
        dp.assign(input.sz, vi(input.sz, INF));
        rep(i, input.sz) dp[i][i] = 1;

        int res = solve(0, input.sz-1);
        cout << res << endl;
    } 

    //////////////end////////////////
    return 0;
}
