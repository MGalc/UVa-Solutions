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

struct point {
    double x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(double xx, double yy) : x(xx), y(yy) { }

    bool operator==(const point b) const {
        return (fabs(x - b.x) < EPS && fabs(y - b.y) < EPS);
    }
};

struct vect {
    double x, y;
    vect() { x = 0; y = 0; }
    vect(double xx, double yy) { x = xx; y = yy; }
};

vect toVect(point p1, point p2) {
    vect v;
    v.x = p2.x - p1.x;
    v.y = p2.y - p1.y;
    return v;
}


double cross(vect a, vect b) {
    return a.x * b.y - a.y * b.x; 
}

// Counter clockwise test
// Returns true if r is left of line pq
bool ccw(point p, point q, point r) {
    return cross(toVect(p, q), toVect(p, r)) >= 0.0; 
}

bool isConvex(const vector<point> &P) {
    int size = (int)P.size();
    if (size <= 3) return false;
    bool isLeft = ccw(P[0], P[1], P[2]);
    for (int i = 1; i < size-1; i++)
        if (ccw(P[i], P[i+1], P[(i+2) == size ? 1 : i+2]) != isLeft)
            return false;
    return true; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N) {
        vector<point> poly;
        rep(i, N) {
            int x, y;
            cin >> x >> y;
            poly.push_back(point(x, y));
        }
        poly.push_back(poly[0]);

        cout << (!isConvex(poly) ? "Yes" : "No") << endl;
    }

    //////////////end////////////////
    return 0;
}
