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
pii dp[105][20500];
int in[105];
int N, C;
const int INF = (1 << 30);
pii minimum;

pii f(int loc, int total, int count) {
    if (total >= C)
        return mp(total, count);
    if (loc == N)
        return mp(INF,INF);

    if (dp[loc][total].first != -1) {
        pii ds = dp[loc][total];
        ds.second += count;
        return ds;
    }

    pii p1 = f(loc+1, total+in[loc], count+1);
    pii p2 = f(loc+1, total, count);
    pii p11 = p1;
    p11.second -= count;
    pii p22 = p2;
    p22.second -= count;

    if (p1.first < p2.first) {
        dp[loc][total] = p11;
        return p1;
    }
    else if (p2.first < p1.first) {
        dp[loc][total] = p22;
        return p2;
    }
    else {
        if (p1.second < p2.second) {
            dp[loc][total] = p11;
            return p1;
        }
        else  {
            dp[loc][total] = p22;
            return p2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> C >> N;
        rep(i, N) {
            cin >> in[i];
        }
        minimum = mp(INF, INF);

        sort(in, in+N);

        int MAXD = C + 10000;

        memset(dp, -1, sizeof dp);

        pii mins = f(0, 0, 0);
        cout << mins.first << " " << mins.second << endl;
    }

    //////////////end////////////////
    return 0;
}
