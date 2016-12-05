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
ll MAXV = numeric_limits<int>::max();
vector<vector<ll>> dp;
string input;
vi ints;

ll solve(int x, int d, ll val) {
    if (val > MAXV) return 0;
    if (x+d >= ints.sz) return val;
    if (dp[x][d] != -1LL) return dp[x][d];

    ll thisval = val*10 + ints[x+d];

    if (thisval > MAXV) 
        dp[x][d] = solve(x+d+1, 0, 0);
    else
        dp[x][d] = max(solve(x+d+1, 0, 0) + thisval, solve(x, d+1, thisval));

    return dp[x][d];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> input;

        ints.clear();
        rep(i, input.sz) ints.push_back(input[i] - '0');
        dp.assign(input.sz, vector<ll>(11, -1LL));

        cout << solve(0, 0, 0) << endl;
    }

    //////////////end////////////////
    return 0;
}
