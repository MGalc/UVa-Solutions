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
int N, R;
double B, V, E, F;
vi cps;
vd dp;
vd dists;

double solve(int loc) {
    if (loc == N-1) // At the end
        return 0.0;
    if (dp[loc] != -1.0) 
        return dp[loc];

    double pitTime = 0.0;
    if (loc != 0) {
        pitTime = B;
    }

    double bestTime = INF;
    for (int i = loc+1; i < N; i++) {
        int lastRefuelDist = cps[i] - cps[loc];

        bestTime = min(bestTime, pitTime + dists[lastRefuelDist] + solve(i));
    }

    return dp[loc] = bestTime;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N, N) {
        N++;
        cps.assign(N, 0);
        cps[0] = 0;
        rep2(i, 1, N)
            cin >> cps[i];
        cin >> B >> R >> V >> E >> F;

        // Store distances so we don't have to recalculate
        double dist = 0.0;
        dists.clear();
        dists.push_back(dist);
        rep(i, cps[cps.sz-1]) {
            if (i < R)
                dist += 1.0 / (V - F * (R - i));
            else
                dist += 1.0 / (V - E * (i - R));
            dists.push_back(dist);
        }

        dp.assign(N, -1.0);

        cout << setprecision(4) << fixed << solve(0) << endl;
    }

    //////////////end////////////////
    return 0;
}
