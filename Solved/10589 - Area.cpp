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
    double x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(double xx, double yy) : x(xx), y(yy) { }

    bool operator<(point other) const { // override less than operator
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y; 
    }
    bool operator>(const point b) const {
        return b < *this;
    }
    bool operator<=(const point b) const {
        return !(b < *this);
    }
    bool operator>=(const point b) const {
        return !(*this < b);
    }

    bool operator==(const point b) const {
        return (fabs(x - b.x) < EPS && fabs(y - b.y) < EPS);
    }
};

double distance(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int insideCircleCheck(point p, point c, double r) {
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx * dx + dy * dy, rSq = r * r;
    if (fabs(Euc - rSq) < 0) return 1; //border
    if (Euc < rSq) return 0; //inside
    return 2; //outside
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N, A;
    while (cin >> N >> A, N) {
        vector<point> points(N);
        rep(i, N) {
            double x, y;
            cin >> x >> y;
            points[i] = point(x, y);
        }

        int pointsInside = 0;
        rep(i, N) {
            int sectorsin = 0;
            point p(0.0, 0.0);
            if (insideCircleCheck(points[i], p, A) == 0 && points[i].x >= 0.0 && points[i].y >= 0.0) sectorsin++;
            p = point(A, 0.0);
            if (insideCircleCheck(points[i], p, A) == 0 && points[i].x <= A && points[i].y >= 0.0) sectorsin++;
            p = point(0.0, A);
            if (insideCircleCheck(points[i], p, A) == 0 && points[i].x >= 0.0 && points[i].y <= A) sectorsin++;
            p = point(A, A);
            if (insideCircleCheck(points[i], p, A) == 0 && points[i].x <= A && points[i].y <= A) sectorsin++;

            if (sectorsin == 4) pointsInside++;
        }

        cout << setprecision(5) << fixed << (double)pointsInside * A * A / N << endl;
    }

    //////////////end////////////////
    return 0;
}
