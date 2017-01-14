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
#define popc(x) __builtin_popcount(x)
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

const double PI = 2 * acos(0);
struct point {
    int x, y, z;
    point(int x1, int y1, int z1) {
        x = x1; y = y1; z = z1;
    }
    point() {};
};

struct cube {
    point p1, p2;
    cube(point p, int width) {
        p1 = p;
        p2 = point(p.x + width, p.y + width, p.z + width);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N) {
        point lo(-INF, -INF, -INF), hi(INF, INF, INF);
        rep(i, N) {
            int x, y, z, w;
            cin >> x >> y >> z >> w;

            hi.x = min(hi.x, x+w);
            hi.y = min(hi.y, y+w);
            hi.z = min(hi.z, z+w);

            lo.x = max(lo.x, x);
            lo.y = max(lo.y, y);
            lo.z = max(lo.z, z);
        }

        int interception = 0;
        if (lo.x < hi.x && lo.y < hi.y && lo.z < hi.z) {
            interception = (hi.x-lo.x) * (hi.y-lo.y) * (hi.z-lo.z);
        }

        cout << interception << endl;
    }

    //////////////end////////////////
    return 0;
}
