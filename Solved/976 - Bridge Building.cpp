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
#define INF 2e7
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
int R, C, B, S;

vii grid;
vi xx {-1, 0, 1, 0};
vi yy {0, 1, 0, -1};
vi dists;
vii dp;

int solve(int loc, int remBridges) {
    if (remBridges == 0)
        return 0;
    if (loc >= C)
        return INF;
    if (dp[loc][remBridges] != -1)
        return dp[loc][remBridges];
    if ((remBridges - 1) * S + remBridges > C - loc)
        return dp[loc][remBridges] = INF;

    int bestval = INF;
    for (int i = loc; i < C; i++) {
        bestval = min(bestval, solve(loc+1, remBridges));
        bestval = min(bestval, dists[loc] + solve(loc+S+1, remBridges-1));
    }

    return dp[loc][remBridges] = bestval;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> R >> C) {
        cin >> B >> S;
        grid.assign(R, vi(C, 0));
        rep(i, R) {
            string in;
            cin >> in;
            rep(k, in.sz) {
                if (in[k] == '#') {
                    grid[i][k] = 1;
                }
            }
        }

        // Just seperate the two islands for ease (don't need to worry about lakes within island)
        queue<pii> q;
        q.push(pii(0, 0));
        grid[0][0] = 2;
        while(!q.empty()) {
            pii v = q.front();
            q.pop();
            rep(i, 4) {
                pii nextv = mp(v.first + xx[i], v.second + yy[i]);
                if (nextv.first < 0 || nextv.first >= R || nextv.second < 0 || nextv.second >= C)
                    continue;
                if (grid[nextv.first][nextv.second] == 1) {
                    grid[nextv.first][nextv.second] = 2;
                    q.push(nextv);
                }
            }
        }

        dists.assign(C, 0);
        rep(i, C) {
            int d = 0;
            rep(j, R) {
                if (grid[j][i] == 2)
                    d = 0;
                else if (grid[j][i] == 1)
                    break;
                else 
                    d++;
            }
            dists[i] = d;
        }

        dp.assign(C, vi(B+1, -1));
        cout << solve(0, B) << endl;
    }

    //////////////end////////////////
    return 0;
}
