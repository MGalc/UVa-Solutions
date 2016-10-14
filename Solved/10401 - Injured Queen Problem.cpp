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
#define INF 1e9

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
vi location;
vector<vector<ll>> dp;
int gsize;

ll dpf(int loc, int prev) {
    if (loc == gsize) 
        return 1;
    if(dp[loc][prev] != -1) 
        return dp[loc][prev];

    ll total = 0;
    if (location[loc] == 0) {
        for (int i = 1; i < gsize+1; i++) {
            if (prev - 1 <= i && prev + 1 >= i) continue;
            total += dpf(loc+1, i);
        }
    }
    else if (prev - 1 > location[loc] || prev + 1 < location[loc]) {
        total += dpf(loc+1, location[loc]);
    }

    return dp[loc][prev] = total;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string in;
    while (cin >> in) {
        gsize=in.size();
        location.assign(gsize, 0);
        dp.assign(gsize, vector<ll>(gsize+1, -1));
        rep(i, in.size()) {
            if (in[i] != '?') {
                if (in[i] >= '0' && in[i] <= '9')
                    location[i] = in[i] - '0';
                else 
                    location[i] = 10 + in[i] - 'A';
            }
        }

        ll total = 0;
        if (location[0] == 0) {
            for (int i = 1; i < gsize+1; i++) {
                total += dpf(1, i);
            }
        }
        else 
            total += dpf(1, location[0]);

        if (gsize == 1) total = 1;

        cout << total << endl;
    }

    //////////////end////////////////
    return 0;
}
