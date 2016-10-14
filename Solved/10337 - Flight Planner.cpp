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

int alt[12][1100];
int dp[12][1100];
int X;

int f(int loc, int height) {
    if (loc == X && height == 0)
        return 0;
    if (height < 0 || loc >= X)
        return 1234567;
    if (dp[height][loc] != -1)
        return dp[height][loc];

    int minv = 1234567;
    int lostd = alt[height][loc];
    minv = min(minv, 
            min(f(loc+1, height+1) + 60 - lostd, 
                min(f(loc+1, height) + 30 - lostd, 
                    f(loc+1, height-1) + 20 - lostd) 
               )
            );
               
    return dp[height][loc] = minv;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        memset(dp, -1, sizeof dp);
        cin >> X;
        X /= 100;
        for (int i = 9; i >= 0; i--) {
            rep(j, X) {
                cin >> alt[i][j];
            }
        }

        f(2, 1);

        cout << f(0, 0) << endl << endl;
    }

    //////////////end////////////////
    return 0;
}
