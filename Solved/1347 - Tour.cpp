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
vpii points;
vector<vector<double>> dp;

double dist(pii a, pii b) {
    return hypot(a.first - b.first, a.second - b.second);
}

double solve(int l, int r) {
    if (dp[l][r] != -1.0)
        return dp[l][r];
    int curindx = max(l, r);
    if (curindx == points.sz-2) {
        return dp[l][r] = dist(points[r], points[points.sz-1]) + dist(points[l], points[points.sz-1]);
    }
    int next = curindx+1;

    double maxval = INF;
    maxval = min(dist(points[l], points[next]) + solve(next, r), dist(points[r], points[next]) + solve(l, next));

    return dp[l][r] = maxval;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N) {
        points.assign(N, {0, 0});
        rep(i, N) {
            int x, y;
            cin >> x >> y;
            points[i] = mp(x, y);
        }

        dp.assign(N, vector<double>(N, -1));
        cout << setprecision(2) << fixed << solve(0, 0) << endl;
    }

    //////////////end////////////////
    return 0;
}
