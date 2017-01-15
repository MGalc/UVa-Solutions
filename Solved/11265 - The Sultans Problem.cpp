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

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); 
}

vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = cross(toVect(a, b), toVect(a, Q[i])), left2 = 0;
        if (i != (int)Q.size()-1) left2 = cross(toVect(a, b), toVect(a, Q[i+1]));
        if (left1 > -EPS) P.push_back(Q[i]);
        if (left1 * left2 < -EPS)
            P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front()); 
    return P; 
}

// Counter clockwise test
bool ccw(point p, point q, point r) {
    return cross(toVect(p, q), toVect(p, r)) > 0; 
}

double dotProduct(vect v1, vect v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double norm_sq(vect v) {
    return v.x*v.x + v.y*v.y;
}

double angle(point a, point o, point b) {
    vect oa = toVect(o, a), ob = toVect(o, b);
    return acos(dotProduct(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

double area(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0; 
}

// Returns true if point p is in the polygon P
bool inPolygon(point pt, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0;
    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(pt, P[i], P[i+1]))
            sum += angle(P[i], pt, P[i+1]);
        else sum -= angle(P[i], pt, P[i+1]); 
    }
    return fabs(fabs(sum) - 2*PI) < EPS; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N, W, H, X, Y;
    int casenum = 1;
    while (cin >> N >> W >> H >> X >> Y) {
        cout << "Case #" << casenum++ << ": ";
        point flowerPoint(X,Y);
        vector<point> polygon { 
            {0.0,0.0}, 
            {0.0,(double)H}, 
            {(double)W,(double)H}, 
            {(double)W,0.0},
            {0.0,0.0} };

        rep(i, N) {
            point p1, p2;
            cin >> p1.x >> p1.y >> p2.x >> p2.y;

            if (ccw(p1, p2, flowerPoint))
                polygon = cutPolygon(p1, p2, polygon);
            else
                polygon = cutPolygon(p2, p1, polygon);
        }

        cout << setprecision(3) << fixed << area(polygon) << endl;
    }

    //////////////end////////////////
    return 0;
}
