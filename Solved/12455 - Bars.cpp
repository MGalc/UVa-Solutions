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

int bars[21];
int main() {
    ios::sync_with_stdio(false);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        int n, p;
        cin >> n >> p;

        rep(i, p) {
            cin >> bars[i];
        }
        sort(bars, bars+p);

        bool good = false;
        for (int mask = 1; mask < (1 << p) && !good; mask++) {
            int count = 0;
            for (int i = 0; i < p; i++) {
                if (((mask & (1 << i)) != 0)) {
                    count += bars[i];
                }
                if (count == n) {
                    good = true;
                    break;
                }
                if (count > n)
                    continue;
            }
        }

        if (good)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    //////////////end////////////////
    return 0;
}
