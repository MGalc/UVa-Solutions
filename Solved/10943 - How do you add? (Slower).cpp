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

int f(int loc, int cval) {
    if (loc == K) {
        if (cval == N)
            return 1;
        else return 0;
    }
    if (cval > N)
        return 0;

    if (dp[loc][cval] != -1)
        return dp[loc][cval];

    int tot = 0;
    for (int i = 0; i <= N; i++) {
        tot += f(loc+1, cval+i) % 1000000;
    }

    return dp[loc][cval] = tot % 1000000;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while(cin >> N >> K, N || K) {
        memset(dp, -1, sizeof dp);
        int tot = 0;
        for (int i = 0; i <= N; i++) {
            tot += f(1, i) % 1000000;
            tot %= 1000000;
        }
        cout << tot << endl;
    }

    //////////////end////////////////
    return 0;
}
