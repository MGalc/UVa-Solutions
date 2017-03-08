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
vpii dp(30100, mp(-1,-1));

pii solve(int val) {
    if (dp[val].first != -1)
        return dp[val];

    int msb = 31 - __builtin_clz(val);
    int nextval = (((val ^ (1 << msb)) << 1) | 1);
    if (nextval == val)
        return dp[val] = mp(0, val);
    pii ret = solve(nextval);
    ret.first++;
    return dp[val] = ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////
    dp[1] = mp(0, 1);
    for (int i = 2; i < 30100; i<<=2)
        dp[i] = mp(1, 1);

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case " << tt << ": ";

        int n;
        cin >> n;
        pii result = solve(n);
        cout << result.first << " " << result.second << endl;
    }

    //////////////end////////////////
    return 0;
}
