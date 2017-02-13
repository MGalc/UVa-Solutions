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

inline int LCM(int a, int b) {
    return (a*b)/__gcd(a,b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int C, T;
    while (cin >> C >> T, C || T) {
        vi coins(C, 0);
        vi tables(T, 0);
        rep(i, C)
            cin >> coins[i];
        rep(i, T)
            cin >> tables[i];

        vi mini(T, INF);
        vi maxi(T, -INF);

        for (int i1 = 0; i1 < C-3; i1++) {
            for (int i2 = i1+1; i2 < C-2; i2++) {
                int lcm1 = LCM(coins[i1], coins[i2]);
                for (int i3 = i2+1; i3 < C-1; i3++) {
                    int lcm2 = LCM(lcm1, coins[i3]);
                    for (int i4 = i3+1; i4 < C; i4++) {
                        int lcm3 = LCM(lcm2, coins[i4]);
                        for (int t = 0; t < T; t++) {
                            int div = tables[t]/lcm3;
                            maxi[t] = max(maxi[t], lcm3 * div);
                            mini[t] = min(mini[t], lcm3 * (div+1));
                        }
                    }
                }
            }
        }

        rep(i, T) {
            if (maxi[i] == tables[i])
                cout << tables[i] << " " << tables[i] << endl;
            else
                cout << maxi[i] << " " << mini[i] << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
