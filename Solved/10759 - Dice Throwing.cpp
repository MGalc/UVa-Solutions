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
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

static const ull UNSET = numeric_limits<ull>::max();

const double PI = 2 * acos(0);
ull dp[30][175];

ull solve(int loc, int val) {
    if (loc <= 0) {
        return val <= 0;
    }

    // prevent overrun.
    if (val < 0) val = 0;

    if (dp[loc][val] != UNSET) 
        return dp[loc][val];

    // just a little speedup
    if (val <= 0) {
        ull tot = 1;
        for (int i = 0; i < loc; i++)
            tot *= 6;
        return dp[loc][val] = tot;
    }

    ull total = 0;
    for (int i = 1; i <= 6; i++) {
        total += solve(loc-1, val-i);
    }

    return dp[loc][val] = total;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    //memset(dp, 0xFF, sizeof dp);
    rep(i, 30) rep(j, 175) dp[i][j] = UNSET;
    ull n, x;
    while (cin >> n >> x, n || x) {
        ull bot = 1;
        for (int i = 0; i < n; i++)
            bot *= 6;
        ull top = solve(n, x);

        ull a = top, b = bot;
        while (b != 0) {
            ull tmp = b;
            b = a % b;
            a = tmp;
        }

        top /= a;
        bot /= a;

        if (top % bot == 0)
            cout << top/bot << endl;
        else
            cout << top << "/" << bot << endl;
    }

    //////////////end////////////////
    return 0;
}
