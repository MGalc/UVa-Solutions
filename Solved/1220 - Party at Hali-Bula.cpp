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

vii adj;
vector<vector<int>> dp;
vector<vector<bool>> uniq;

int solve(int loc, bool invited) {
    if (dp[loc][invited] != -1)
        return dp[loc][invited];
    if (adj[loc].size() == 0)
        return dp[loc][invited] = invited;

    int maxval = invited;
    for (int i = 0; i < adj[loc].size(); i++) {
        int thismax = 0;
        if (invited) {
            maxval += solve(adj[loc][i], false);
            uniq[loc][invited] = uniq[loc][invited] & uniq[adj[loc][i]][false];
        }
        else {
            int nexton = solve(adj[loc][i], true);
            int nextoff = solve(adj[loc][i], false);
            if (nexton == nextoff)
                uniq[loc][invited] = false;
            else if (nexton > nextoff)
                uniq[loc][invited] = uniq[loc][invited] & uniq[adj[loc][i]][true];
            else
                uniq[loc][invited] = uniq[loc][invited] & uniq[adj[loc][i]][false];

            maxval += max(nexton, nextoff);
        }
    }

    return dp[loc][invited] = maxval;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N) {
        dp.assign(N+1, vi(2, -1));
        adj.assign(N+1, vi());
        map<string, int> indxs;
        uniq.assign(N+1, vector<bool>(2, true));

        adj[0].push_back(1);
        string s1, s2;
        cin >> s1;
        indxs[s1] = 1;
        int nameindx = 2;

        for (int i = 1; i < N; i++) {
            cin >> s1 >> s2;
            if (indxs[s1] == 0)
                indxs[s1] = nameindx++;
            if (indxs[s2] == 0)
                indxs[s2] = nameindx++;

            adj[indxs[s2]].push_back(indxs[s1]);
        }

        int val = solve(0, false);
        cout << val << " " << (uniq[0][false] ? "Yes" : "No") << endl;

        // Sneaky bug
        // cout << solve(0, false) << " " << (uniq[0][false] ? "Yes" : "No") << endl;
    }

    //////////////end////////////////
    return 0;
}
