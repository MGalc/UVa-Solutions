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

ll dp[205][100][15];
ll in[250];
int N, Q;
int D, M;

ll f(int loc, ll csum, ll rem) {
    if (rem == 0) {
        return (csum == 0);
    }
    if (loc == N)
        return 0;

    if (loc + rem > N)
        return 0;

    if (dp[loc][csum][rem] != -1)
        return dp[loc][csum][rem];

    ll ret = 0;
    ret += f(loc+1, (csum + in[loc]) % D, rem-1);
    ret += f(loc+1, csum, rem);

    dp[loc][csum][rem] = ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int set = 1;
    while (cin >> N >> Q, N || Q) {
        cout << "SET " << set << ":" << endl;
        rep(i, N) {
            cin >> in[i];
        }

        rep(qq, Q) {
            memset(dp, -1, sizeof dp);
            cin >> D >> M;
            cout << "QUERY " << qq+1 << ": " << f(0, 0, M) << endl;
        }
        ++set;
    }


    //////////////end////////////////
    return 0;
}
