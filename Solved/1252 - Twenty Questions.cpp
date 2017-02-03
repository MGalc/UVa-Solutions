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
int N, M;
vii dp;
vector<int> inputs;

int solve(int q, int a) {
    if (dp[q][a] != -1)
        return dp[q][a];

    int same = 0;
    rep(i, N) {
        if ((inputs[i] & q) == a)
            same++;
    }

    if (same <= 1)
        return dp[q][a] = 0;

    int lowest = INF;
    for (int i = 0; i < M; i++) {
        if (q & (1 << i))
            continue;
        int r1 = 1 + solve(q | (1 << i), a);
        
        // Bit of optimisation, don't run the second one if first one already exceeds lowest.
        if (r1 > lowest) continue; 
        int r2 = 1 + solve(q | (1 << i), a | (1 << i));
        lowest = min(lowest, max(r1, r2));
    }

    return dp[q][a] = lowest;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> M >> N, N || M) {
        dp.assign((1 << M), vi(1 << M, -1));
        inputs.assign(N, 0);

        rep(i, N) {
            string in;
            cin >> in;
            int bin = 0;
            rep(j, M) {
                bin |= (in[j] == '1') << j;
            }
            inputs[i] = bin;
        }

        cout << solve(0, 0) << endl;
    }

    //////////////end////////////////
    return 0;
}
