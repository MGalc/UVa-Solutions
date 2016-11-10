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

int dp[100];

int solve(int loc) {
    if (loc <= 0) return 1;
    if (dp[loc] != -1) return dp[loc];

    int tot = 0;
    tot += solve(loc - 2);
    if (loc - 3 > 0)
        tot += solve(loc - 3);

    return dp[loc] = tot;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    dp[1] = 1;
    int N;
    while (cin >> N) {
        int total = solve(N);
        if (N-1 > 0)
            total += solve(N-1);
        cout << total << endl;
    }

    //////////////end////////////////
    return 0;
}
