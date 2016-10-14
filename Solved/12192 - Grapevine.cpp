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
vector<vi> grid;
int initx, inity;

inline int hbin(int dist, int max) {
    int L = 0;
    int distance = dist;
    if (grid[inity + dist][initx + dist] <= max) {
        return dist + 1;
    }
    while (distance > 0) {
        int step = (distance+1)/2;
        int val = grid[inity + L + step][initx + L + step];
        if (val > max) {
            dist = L + step - 1;
            if (grid[inity + dist][initx + dist] <= max) {
                return dist + 1;
            }
        }
        else {
            L += step;
        }
        distance = dist - L;
    }
    return dist + 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int x, y;
    while (cin >> y >> x, x || y) {
        grid.assign(y, vi());
        rep(i, y) {
            grid[i].assign(x, 0);
            rep(j, x) {
                cin >> grid[i][j];
            }
        }
        int Q;
        cin >> Q;
        rep(q, Q) {
            int q1, q2;
            cin >> q1 >> q2;
            int lmost = x+1;
            int rmost = x - 1;
            int most = 0;
            rep(yy, y) {
                auto left = lower_bound(all(grid[yy]), q1);
                if (left - grid[yy].begin() >= lmost)
                    continue;
                if (left == grid[yy].end())
                    continue;
                if (*left > q2)
                    continue;
                initx = left - grid[yy].begin();
                inity = yy;
                int ret;
                if (y - yy-1 < rmost - initx) {
                    ret = hbin(y - yy-1, q2);
                }
                else {
                    ret = hbin(rmost - initx, q2);
                }
                most = max(most, ret);
            }

            cout << most << endl;
        }
        cout << '-' << endl;
    }
    //////////////end////////////////
    return 0;
}
