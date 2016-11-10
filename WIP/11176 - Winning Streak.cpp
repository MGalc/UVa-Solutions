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
vector<vector<ld>> dp;
int N;
ld P;

ld solve(int len, int currentstreak, int maxstreak) {
    if (len > N) return maxstreak * P;
    if (dp[currentstreak][maxstreak] != -1.0l) return dp[currentstreak][maxstreak];
    return 0ll;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N >> P, N) {
        dp.assign(N+1, vector<ld>(N+1, -1.0l));

        // n = 0
        // 0 1 2 3 STREAKS
        // -------
        // 1 1
        //
        // n = 2
        // 0 1 2 3 STREAKS
        // -------
        // 1 2 1
        //
        // n = 3
        // 0 1 2 3 STREAKS
        // -------
        // 1 4 2 1
        //
        // n = 4
        // 0 1 2 3 4 STREAKS
        // ---------
        // 1 7 5 2 1

        // LL LW WL WW
        // 0  1  1  2
        // LLL LLW LWL LWW WLL WLW WWL WWW
        // 0   1   1   2   1   1   2   3
        // LLLL WLLL LLLW WLLW LLWL WLWL LLWW WLWW LWLL WWLL LWLW WWLW LWWL WWWL LWWW WWWW
        // 0    1    1    1    1    1    2    2    1    2    1    2    2    3    3    4
    }

    //////////////end////////////////
    return 0;
}
