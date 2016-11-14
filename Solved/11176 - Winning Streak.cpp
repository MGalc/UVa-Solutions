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
#define Idot(a,b) ((conj(a)*(b)).X)
#define IX real()
#define IY imag()
#define popc(x) __builtin_popcount(x)
#define INF 1e9
#define MOD 1000007

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
vector<vector<double>> dp;
int N;
double P;
vector<double> probpows;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    dp.assign(510, vector<double>(510, -1.0l));
    while (cin >> N >> P, N) {
        probpows.assign(N+1, 0.0);
        probpows[0] = P;
        for (int i = 1; i <= N; i++) probpows[i] = probpows[i-1] * P;

        rep(i, N+1) dp[0][i] = 1.0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                if (i <= j)
                    dp[i][j] = 1.0;
                else if (i - 1 == j)
                    dp[i][j] = dp[i-1][j] - probpows[j];
                else
                    dp[i][j] = dp[i-1][j] - (dp[i - j - 2][j] * probpows[j] * (1-P));
            }
        }

        double res = 0;
        for (int i = 1; i <= N; i++) {
            res += i * (dp[N][i] - dp[N][i-1]);
        }

        cout << fixed << setprecision(10) << res << endl;
    }

    //////////////end////////////////
    return 0;
}
