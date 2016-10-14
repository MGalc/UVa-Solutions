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

int sur = 0, def = 0;

int cvals[20];
int fval(int loc, int tot, int ctot) {
    if (loc == 13) {
        if (tot < 0) {
            return ctot;
        }
        else return INT_MIN;
    }

    int mx = INT_MIN;
    if (loc < 5) {
        cvals[loc] = sur;
        mx = max(mx, fval(loc+1, tot + sur, ctot+sur));
        cvals[loc] = def;
        mx = max(mx, fval(loc+1, tot + def, ctot+def));
    }
    else {
        int ltot = tot - cvals[loc-5];
        if (ltot + sur < 0) {
            cvals[loc] = sur;
            mx = max(mx, fval(loc+1, ltot + sur, ctot + sur));
        }
        if (ltot + def < 0) {
            cvals[loc] = def;
            mx = max(mx, fval(loc+1, ltot + def, ctot + def));
        }
    }

    return mx;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    cvals[0] = 0;
    while (cin >> sur >> def) {
        def = -def;
        int ret = fval(1, 0, 0);
        if (ret < 0) {
            cout << "Deficit" << endl;
        }
        else cout << ret << endl;
    }

    //////////////end////////////////
    return 0;
}
