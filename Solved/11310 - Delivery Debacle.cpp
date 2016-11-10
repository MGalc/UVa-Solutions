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
#define NONETAKEN 0
#define BOTTAKEN 1
#define TOPTAKEN 2
#define BOTHTAKEN 3

const double PI = 2 * acos(0);
ll dp[45][4];

ll solve(int loc, int state) {
    if (dp[loc][state] != -1)
        return dp[loc][state];

    if (loc < 1) return 0;
    if (loc == 1) {
        /*if (state == NONETAKEN && !allones) 
            return dp[loc][state][allones] = 1;
        else if (state != NONETAKEN) 
            return dp[loc][state][allones] = 1;*/
        return dp[loc][state] = 1;
    }

    ll total = 0;
    if (state == NONETAKEN) {
        total += solve(loc-1, NONETAKEN); 
        total += solve(loc-1, BOTTAKEN);
        total += solve(loc-1, TOPTAKEN);
        total += solve(loc-1, BOTHTAKEN);
        total += solve(loc-1, BOTHTAKEN);
    }
    else if (state == BOTTAKEN) {
        total += solve(loc-1, NONETAKEN); 
        total += solve(loc-1, BOTHTAKEN);
    }
    else if (state == TOPTAKEN) {
        total += solve(loc-1, NONETAKEN); 
        total += solve(loc-1, BOTHTAKEN);
    }
    else {
        total += solve(loc-1, NONETAKEN); 
    }

    return dp[loc][state] = total;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    memset(dp, -1, sizeof dp);
    while (T--) {
        ll in;
        cin >> in;

        cout << solve(in, NONETAKEN) << endl;
    }

    //////////////end////////////////
    return 0;
}
