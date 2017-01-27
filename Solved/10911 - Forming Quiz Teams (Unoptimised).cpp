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
#define INF 1e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);
vector<pair<double, double>> input;
int N, N2;
int COMPLETE_VAL;
vector<double> dp;

double dfs(int mask) {
    if (dp[mask] != -1.0)
        return dp[mask];
    if (mask == COMPLETE_VAL) 
        return 0.0;

    double minvalue = INF;
    for (int i = 0; i < N2-1; i++) {
        if (mask & (1 << i)) // If we've used the value already
            continue; 

        for (int j = i+1; j < N2; j++) {
            if (mask & (1 << j)) // If we've used the value already
                continue; 

            double pointsDist = hypot(input[i].first - input[j].first, input[i].second - input[j].second);
            minvalue = min(minvalue, dfs(mask | (1 << j) | (1 << i)) + pointsDist);
        }
    }

    return dp[mask] = minvalue;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> N, N) {
        cout << "Case " << casenum++ << ": ";
        N2 = 2*N;
        COMPLETE_VAL = (1 << (2*N)) - 1;
        dp.assign(COMPLETE_VAL+1, -1.0);
        input.clear();

        string name;
        for (int i = 0; i < 2*N; i++) {
            double x, y;
            cin >> name >> x >> y;
            input.push_back(mp(x, y));
        }

        cout << setprecision(2) << fixed << dfs(0) << endl;
    }

    //////////////end////////////////
    return 0;
}
