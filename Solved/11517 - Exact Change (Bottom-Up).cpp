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
int dp[20100];
int in[105];
int N, C;
const int INF = (1 << 30);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> C >> N;
        int mv = -1;
        rep(i, N) {
            cin >> in[i];
            if (in[i] > mv)
                mv = in[i];
        }

        int MAXD = C + mv;

        for (int i = 0; i < MAXD; i++) {
            dp[i] = INF;
        } 

        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = MAXD; j >= in[i]; j--) {
                dp[j] = min(dp[j], dp[j - in[i]]+1);
            }
        }

        int indx = -1;
        for (int i = C; i <= MAXD; i++) {
            if (dp[i] < INF) {
                indx = i;
                break;
            }
        }
        cout << indx << " " << dp[indx] << endl;
    }

    //////////////end////////////////
    return 0;
}
