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
typedef long double ld;

const double PI = 2 * acos(0);

pii comps[11];
int smallest[11];
int N;
ld sval;

bool f(int loc, ld total, int mask) {
    int cnt = popc(mask);
    if (cnt == N) {
        if (total < sval) {
            sval = total;
            smallest[N] = loc;
            return true;
        }
        else return false;
    }

    bool ret = false;
    for(int i = 1; i <= N; i++) {
        if (mask & (1 << (i-1)))
            continue;

        ret |= f(i,
            total + hypot(ld(comps[loc].first - comps[i].first), ld(comps[loc].second - comps[i].second)),
            mask | (1 << (i-1))
        );
    }

    if (ret)
        smallest[cnt] = loc;

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int tt = 1;
    while (cin >> N, N) {
        sval = 1e10;
        for (int i = 1; i <= N; i++) {
            int x, y;
            cin >> x >> y;
            comps[i] = mp(x, y);
        }

        rep(i, N) {
            f(i+1, 0, 1 << i);
        }

        cout << "**********************************************************" << endl;
        cout << "Network #" << tt++ << endl;
        for (int i = 1; i < N; i++) {
            pii s1 = comps[smallest[i]];
            pii s2 = comps[smallest[i+1]];
            cout << "Cable requirement to connect (" << s1.first << "," << s1.second \
                << ") to (" << s2.first << "," << s2.second << ") is " << \
                setprecision(2) << fixed << hypot(ld(s1.first - s2.first), ld(s1.second - s2.second)) + 16.0L << " feet." << endl;
        }
        cout << setprecision(2) << fixed << "Number of feet of cable required is " << sval + (16.0L * (N-1)) << "." << endl;
    }

    //////////////end////////////////
    return 0;
}
