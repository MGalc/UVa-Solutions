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

int N, B1, B2;
vpii islands;
vector<vector<double>> dp;

double dist(pii a, pii b) {
    return hypot(a.first - b.first, a.second - b.second);
}

double solve(int l, int r) {
    if (dp[l][r] != -1.0)
        return dp[l][r];
    int latest = max(l, r);
    if (latest == N-1) {
        double thispath = dist(islands[l], islands[N-1]) + dist(islands[r], islands[N-1]);
        return dp[l][r] = thispath;
    }

    double bestdist = INF;
    int next = latest+1;
    // We visit it when going left
    if (next != B2) // Make sure it's not the right refueler
        bestdist = min(bestdist, dist(islands[l], islands[next]) + solve(next, r));

    if (next != B1) // Make sure it's not the right refueler
        bestdist = min(bestdist, dist(islands[r], islands[next]) + solve(l, next));

    return dp[l][r] = bestdist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int tc = 1;
    while (cin >> N >> B1 >> B2, N || B1 || B2) {
        islands.assign(N, {0,0});
        rep(i, N) {
            int x, y;
            cin >> x >> y;
            islands[i] = mp(x, y);
        }

        dp.assign(N, vector<double>(N, -1.0));
        double answer = solve(0, 0);
        vi ls, rs;
        ls.push_back(0);
        rs.push_back(0);

        int l = 0, r = 0;
        double totdist = 0.0;

        for (int i = 1; i < N; i++) {
            double ldist = dist(islands[l], islands[i]);
            double rdist = dist(islands[r], islands[i]);
            if (dp[l][i] == -1) {
                ls.push_back(i);
                l = i;
            }
            else if (dp[i][r] == -1) {
                rs.push_back(i);
                r = i;
            }
            else if (dp[l][i] + rdist < dp[i][r] + ldist) {
                rs.push_back(i);
                r = i;
            }
            else {
                ls.push_back(i);
                l = i;
            }
        }

        cout << "Case " << tc++ << ": " << setprecision(2) << fixed << answer << endl;

        if (ls[1] == 1) {
            for (int i = 0; i < ls.sz; i++) {
                if (i != 0)
                    cout << " ";
                cout << ls[i];
            }
            for (int i = rs.sz-1; i >= 0; i--) {
                cout << " " << rs[i];
            }
        }
        else {
            for (int i = 0; i < rs.sz; i++) {
                if (i != 0)
                    cout << " ";
                cout << rs[i];
            }
            for (int i = ls.sz-1; i >= 0; i--) {
                cout << " " << ls[i];
            }
        }

        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
