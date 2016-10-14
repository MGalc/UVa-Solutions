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
int memo[110][15000];
int M, N;
int cost[110];
int worth[110];

int dp(int loc, int money) {
    if (money > M && M < 1800)
        return -1000;
    if (money > M+200)
        return -1000;
    if (loc == N) {
        if (money > M && money <= 2000)
            return -1000;
        return 0;
    }

    if (memo[loc][money] != -1)
        return memo[loc][money];

    return memo[loc][money] = max(worth[loc] + dp(loc+1, money+cost[loc]), dp(loc+1, money));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> M >> N) {
        memset(memo, -1, sizeof memo);

        rep(i, N) {
            cin >> cost[i] >> worth[i];
        } 

        cout << dp(0, 0) << endl;
    }

    //////////////end////////////////
    return 0;
}
