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
vii oddadj;
vii oddgrid;
vi dp;
vector<bool> oddedges;
int N, M;
int endmask;

int calcMatches(int mask) {
    if (dp[mask] != -1)
        return dp[mask];
    if (mask == endmask)
        return dp[mask] = 0;

    int best = INF;
    rep(i, N) {
        if (!oddedges[i] || (mask & (1 << i)))
            continue;
        rep(j, oddadj[i].size()) {
            int next = oddadj[i][j];
            if (mask & (1 << next))
                continue;
            best = min(best, calcMatches(mask | (1 << next) | (1 << i)) + oddgrid[i][next]);
        }
    }
    return dp[mask] = best;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N >> M) {
        adj.assign(N, vi());
        oddgrid.assign(N, vi(N, INF));

        int edgetotal = 0;
        rep(i, M) {
            int e1, e2, val;
            cin >> e1 >> e2 >> val;
            e1--; e2--;
            adj[e1].push_back(e2);
            adj[e2].push_back(e1);
            oddgrid[e1][e2] = min(oddgrid[e1][e2], val);
            oddgrid[e2][e1] = min(oddgrid[e2][e1], val);
            //oddgrid[e1][e2] = val;
            //oddgrid[e2][e1] = val;
            edgetotal += val;
        }

        rep(k, N) {
            rep(i, N) {
                rep(j, N) {
                    oddgrid[i][j] = min(oddgrid[i][j], oddgrid[i][k] + oddgrid[k][j]);
                }
            }
        }

        oddadj.assign(N, vi());
        oddedges.assign(N, false);
        endmask = 0;
        rep(i, N) {
            if (adj[i].size() % 2) {
                oddedges[i] = true;
                endmask |= (1 << i);
            }
        }
        rep(i, N) {
            if (!oddedges[i])
                continue;
            for (int j = i+1; j < N; j++) {
                if (!oddedges[j]) 
                    continue;
                oddadj[i].push_back(j);
                oddadj[j].push_back(i);
            }
        }

        dp.assign(1 << N, -1);
        calcMatches(0); 
        cout << edgetotal + dp[0] << endl;
    }

    //////////////end////////////////
    return 0;
}
