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

    bool operator<(const point b) const {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
    bool operator>(const point b) const {
        return b < *this;
    }
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

double cross(vect a, vect b) {
    return a.x * b.y - a.y * b.x; 
}

// Counter clockwise test
bool ccw(point p, point q, point r) {
    return cross(toVect(p, q), toVect(p, r)) > 0; 
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

double distance(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVect(p, q), toVect(p, r))) < EPS; 
}

point pivot(0, 0);
// compare two angles
bool angleCmp(point a, point b) {
    if (collinear(pivot, a, b))
        return distance(pivot, a) < distance(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; 
}

vector<point> CH(vector<point> P) {
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
        return P; 
    }
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;
    while (i < n) {
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
        else S.pop_back(); 
    }
    return S; 
}

vect scale(vect v, double s) {
    // nonnegative s = [<1 .. 1 .. >1]
    return vect(v.x * s, v.y * s); 
}

// shorter.same.longer
point translate(point p, vect v) {
    // translate p according to v
    return point(p.x + v.x , p.y + v.y); 
}

double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vect ap = toVect(a, p), ab = toVect(a, b);
    double u = dotProduct(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return distance(p, c); 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    int casenum = 1;
    while (cin >> N, N) {
        cout << "Case " << casenum++ << ": ";

        vector<point> poly;
        rep(i, N) {
            double x, y;
            cin >> x >> y;
            poly.push_back(point(x, y));
        }
        if (!poly.empty()) 
            poly.push_back(poly[0]);

        vector<point> conhull = CH(poly);

        double minDist = INF;
        for (int i = 1; i < conhull.sz; i++) {
            double localMax = 0.0;
            for (int j = 1; j < conhull.sz; j++) {
                if (j == i || j == i-1) continue;
                point tmp;
                double dist = distToLine(conhull[j], conhull[i-1], conhull[i], tmp);
                localMax = max(localMax, dist);
            }
            minDist = min(minDist, localMax);
        }

        cout << setprecision(2) << fixed << minDist << endl;
    }

    //////////////end////////////////
    return 0;
}
