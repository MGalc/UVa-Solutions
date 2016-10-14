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

int N, K, M;
long dp[55][55][55];

long f(int loc, int streak, int change) { 
    if (change > K || streak > M)
        return 0L;
    if (loc == N) {
        if (change == K) return 1;
        else return 0;
    }
    if (dp[streak][loc][change] != -1) 
        return dp[streak][loc][change];

    long count = f(loc+1, streak+1, change) + f(loc+1, 1, change+1);

    return dp[streak][loc][change] = count;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N >> K >> M) {
        std::fill_n((long*)dp, sizeof(dp)/8, -1);
        cout << f(1, 1, 1) << endl;
    }


    //////////////end////////////////
    return 0;
}
