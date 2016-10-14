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

vi money {5, 10, 25, 50};
ll dp[31000];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////
    std::fill(dp, dp+31000, 1);

    for (int i = 0; i < 4; i++) {
        for (int j = money[i]; j < 31000; j++) {
            dp[j] += dp[j - money[i]];
        }
    }

    int in;
    while (cin >> in) {
        if (dp[in] == 1)
            cout << "There is only 1 way to produce " << in << " cents change.";
        else 
            cout << "There are " << dp[in] << " ways to produce " << in << " cents change.";
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
