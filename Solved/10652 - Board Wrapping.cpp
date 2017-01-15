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

point rotate(point p, double theta) {
    double rad = theta * (PI/180);
    // multiply theta with PI / 180.0
    return point(p.x * cos(rad) - p.y * sin(rad),
            p.x * sin(rad) + p.y * cos(rad));
}

struct vect {
    double x, y;
    vect() { x = 0; y = 0; }
    vect(double xx, double yy) { x = xx; y = yy; }
};

point translate(point p, vect v) {
    // translate p according to v
    return point(p.x + v.x , p.y + v.y); 
}

double cross(vect a, vect b) {
    return a.x * b.y - a.y * b.x; 
}

vect toVect(point p1, point p2) {
    vect v;
    v.x = p2.x - p1.x;
    v.y = p2.y - p1.y;
    return v;
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVect(p, q), toVect(p, r))) < EPS; 
}


bool ccw(point p, point q, point r) {
    return cross(toVect(p, q), toVect(p, r)) > 0; 
}

double distance(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
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

double area(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<point> points;
        double mouldArea = 0;
        for (int j = 0; j < N; j++) {
            double x, y, w, h, deg;
            cin >> x >> y >> w >> h >> deg;
            point p(-w/2.0, h/2.0);
            p = rotate(p, -deg);
            p = translate(p, vect(x,y));
            // Top left
            points.push_back(translate(rotate(point(-w/2.0, h/2.0), -deg), vect(x, y))); 
            // Top right
            points.push_back(translate(rotate(point(w/2.0, h/2.0), -deg), vect(x, y))); 
            // Bot right
            points.push_back(translate(rotate(point(w/2.0, -h/2.0), -deg), vect(x, y))); 
            // Bot left
            points.push_back(translate(rotate(point(-w/2.0, -h/2.0), -deg), vect(x, y))); 
            mouldArea += w*h;
        }

        vector<point> conHull = CH(points);

        double conHullArea = area(conHull);

        cout << setprecision(1) << fixed << (mouldArea / conHullArea) * 100 << " %" << endl;

    }

    //////////////end////////////////
    return 0;
}
