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
int N;
vi input;
vii dp;

int solve(int l, int r) {
    if (dp[l][r] > -INF) return dp[l][r];
    if (l > r) return dp[l][r] = 0;
    if (l == r) return dp[l][r] = input[l];

    int bestv = -INF;
    for (int i = l, tot = 0; i <= r; i++) {
        tot += input[i];
        bestv = max(bestv, tot - solve(i+1, r));
    }
    for (int i = r, tot = 0; i >= l; i--) {
        tot += input[i];
        bestv = max(bestv, tot - solve(l, i-1));
    }

    return dp[l][r] = bestv;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N, N) {
        input.assign(N, 0);
        rep(i, N)
            cin >> input[i];

        dp.assign(N+1, vi(N+1, -INF));
        cout << solve(0, N-1) << endl;
    }

    //////////////end////////////////
    return 0;
}
