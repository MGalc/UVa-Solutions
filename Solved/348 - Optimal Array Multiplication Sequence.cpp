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
#define popc32(x) __builtin_popcount(x)
#define popc64(x) __builtin_popcountll(x)
#define MOD 1000007
#define INF 2e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long double ld;

static const double PI = 2 * acos(0);
int N;
vpii input;
vii dp;
vii mid;

int solve(int i, int j) {
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == j) 
        return 0;

    int minimum = numeric_limits<int>::max();
    for (int k = i; k < j; k++) {
        int solveval = solve(i, k) + solve(k+1, j)
                + input[i].first * input[k].second * input[j].second;

        if (solveval < minimum) {
            minimum = solveval;
            mid[i][j] = k;
        }
    }

    return dp[i][j] = minimum;
}

vi open, closed;
void getBestParentheses(int i, int j) {
    if (i == j)
        return;
    open[i]++;
    closed[j]++;

    getBestParentheses(i, mid[i][j]);
    getBestParentheses(mid[i][j]+1, j);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> N, N) {
        cout << "Case " << casenum++ << ": ";

        input.resize(N);
        rep(i, N)
            cin >> input[i].first >> input[i].second;

        dp.assign(N, vi(N, -1));
        mid.assign(N, vi(N, -1));

        open.assign(N, 0);
        closed.assign(N, 0);

        solve(0, N-1);
        getBestParentheses(0, N-1);

        rep(i, N) {
            if (i != 0)
                cout << " x ";
            while (open[i] > 0) {
                cout << "(";
                open[i]--;
            }
            cout << "A" << i+1;
            while (closed[i] > 0) {
                cout << ")";
                closed[i]--;
            }
        }
        cout << endl;
        //cout << solve(0, N-1) << endl;;
    }

        //////////////end////////////////
        return 0;
}
