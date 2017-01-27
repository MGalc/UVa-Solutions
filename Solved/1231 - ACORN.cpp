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
int T, H, F;
vi dp;
vii acorns;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int C;
    cin >> C;
    while (C--) {
        cin >> T >> H >> F;
        H++;

        acorns.assign(T, vi(H+5, 0));

        rep(i, T) {
            int num;
            cin >> num;
            rep(j, num) {
                int acorn;
                cin >> acorn;
                acorns[i][acorn]++;
            }
        }

        dp.assign(H+5, 0);

        for (int h = H; h >= 0; h--) {
            for (int t = 0; t < T; t++) {
                int ac = acorns[t][h];
                acorns[t][h] = acorns[t][h+1] + acorns[t][h];
                if (h+F <= H)
                    acorns[t][h] = max(acorns[t][h], ac + dp[h+F]);
                dp[h] = max(dp[h], acorns[t][h]);
            }
        }

        cout << dp[0] << endl;
    }

    //////////////end////////////////
    return 0;
}
