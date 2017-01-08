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

double distance(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double triangleArea(double base, double height) {
    return 0.5 * base * height;
}

double semiPerimeter(point a, point b, point c) {
    return (distance(a, b) + distance(a, c) + distance(b, c)) / 2.0;
}

double triangleArea(point a, point b, point c) {
    double s = semiPerimeter(a, b, c);
    double ab = distance(a, b);
    double ac = distance(a, c);
    double bc = distance(b, c);
    return sqrt(s * (s - ab) * (s - ac) * (s - bc));
}

double circumcenterRadius(point a, point b, point c) {
    return (distance(a, b) * distance(a, c) * distance(b, c)) / (4.0 * triangleArea(a, b, c));
}

struct line { double a, b, c; };

line pointsToLine(point p1, point p2) {
    line l;
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    return l;
}

bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); 
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true; 
}

line perpendicularLineAtPoint(point p, line l) {
    line newl = l;

    if (fabs(l.b) < EPS) {
        newl.a = 0.0;
        newl.b = 1.0;
        newl.c = p.y;
    }
    else if (fabs(l.a) > EPS) {
        newl.a = -1.0 / newl.a;
        newl.c = newl.c + (l.a - newl.a) * p.x;
    }
    else {
        newl.a = 1.0;
        newl.b = 0.0;
        newl.c = p.x;
    }
    return newl;
}

point circumcenterCenter(point a, point b, point c) {
    line l1, l2;
    line ab = pointsToLine(a, b);
    point p1((a.x+b.x)/2.0, (a.y+b.y)/2.0);
    l1 = perpendicularLineAtPoint(p1, ab);
    
    line ac;
    ac = pointsToLine(a, c);
    point p3((a.x+c.x)/2.0, (a.y+c.y)/2.0);

    l2 = perpendicularLineAtPoint(p3, ac);
    point ctr;
    bool ok = areIntersect(l1, l2, ctr);
    return ctr;
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; 
} // to get the other center, reverse p1 and p2

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

void toUnitVect(vect& v) {
    double dist = hypot(v.x, v.y);
    v.x /= dist;
    v.y /= dist;
}

double toRadians(double angle) {
    return angle * (PI / 180.0);
}

void rotateVector(vect& v, double radians) {
    vect res = v;
    v.x = res.x * cos(radians) - res.y * sin(radians);
    v.y = res.x * sin(radians) + res.y * cos(radians);
}

vect scale(vect v, double s) {
    return vect(v.x * s, v.y * s); 
}

point translate(point p, vect v) {
    return point(p.x + v.x , p.y + v.y); 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    int casenum = 1;

    while (cin >> N, N) {
        cout << "Polygon " << casenum++ << ": ";
        point a, b, c;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;

        double circumradius = circumcenterRadius(a, b, c);
        point ccenter = circumcenterCenter(a, b, c);
        double cangle = 360.0 / N;
        double rads = toRadians(cangle);

        double maxx = a.x, maxy = a.y, minx = a.x, miny = a.y;
        point curp = a;
        vect v(curp.x - ccenter.x, curp.y - ccenter.y);
        toUnitVect(v);
        for (int i = 1; i < N; i++) {
            point nextp; 

            rotateVector(v, rads);
            vect scaledv = scale(v, circumradius);
            nextp = translate(ccenter, scaledv);

            curp = nextp;

            maxx = max(maxx, curp.x); maxy = max(maxy, curp.y);
            minx = min(minx, curp.x); miny = min(miny, curp.y);
        }
        double area = (maxx - minx) * (maxy - miny);
        cout << setprecision(3) << fixed << area << endl;
    }

    //////////////end////////////////
    return 0;
}
