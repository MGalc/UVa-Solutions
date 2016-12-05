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
string input;
vii dp;

int solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];

    if (l == r) return dp[l][r] = 1;
    if (r - l == 1) {
        if (input[l] == input[r]) return dp[l][r] = 2;
        else return dp[l][r] = 1;
    }

    if (input[l] == input[r])
        return dp[l][r] = (2 + solve(l+1, r-1));
    else
        return dp[l][r] = (max(solve(l+1, r), solve(l, r-1)));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;

    cin.ignore(255, '\n');

    while (T--) {
        getline(cin, input);
        dp.assign(input.sz, vi(input.sz, -1));

        if (input == "")
            cout << "0" << endl;
        else
            cout << solve(0, input.sz-1) << endl;
    }

    //////////////end////////////////
    return 0;
}
