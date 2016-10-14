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
int N, K;
int dp[105][105];

int f(int cval, int loc) {
    if (loc == 1) {
        return 1;
    }

    if (dp[cval][loc] != -1)
        return dp[cval][loc];

    int total = 0;
    int limit = min(N, cval);
    for (int i = 0; i <= limit; i++) {
        total += f(cval-i, loc-1) % 1000000;
    }
    return dp[cval][loc] = total % 1000000;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    memset(dp, -1, sizeof dp);
    while(cin >> N >> K, N || K) {
        cout << f(N, K) << endl;
    }

    //////////////end////////////////
    return 0;
}
