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
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define popc(x) __builtin_popcount(x)

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

int dp[305][305];
int M, S;
int target = 0;
pair<int, int> coins[42];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        rep(i, 305) rep(j, 305) dp[i][j] = -1;

        cin >> M >> S;
        rep(i, M) {
            int x, y;
            cin >> coins[i].first >> coins[i].second;
            if (!coins[i].first && !coins[i].second){
                M--;
                i--;
            }
        }

        dp[0][0] = 0;
        rep(i, M) {
            for (int x = coins[i].first; x <= S; x++) {
                for (int y = coins[i].second; y <= S; y++) {
                    int pval = dp[x-coins[i].first][y-coins[i].second];
                    if (pval == -1)
                        continue;
                    else if (dp[x][y] == -1)
                        dp[x][y] = pval + 1;
                    else
                        dp[x][y] = min(dp[x][y], pval+1);
                }
            }
        }

        int Ss = S*S;
        int minimum = INT_MAX;
        for (int x = 0; x <= S; x++) {
            for (int y = 0; y <= S; y++) {
                if(dp[x][y] != -1)
                    if ((x*x) + (y*y) == Ss)
                        minimum = min(minimum, dp[x][y]);
            }
        }

        if (minimum >= (1 << 30))
            cout << "not possible" << endl;
        else cout << minimum << endl;
    }

    //////////////end////////////////
    return 0;
}
