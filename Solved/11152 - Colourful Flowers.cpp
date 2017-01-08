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

double semiPerimeter(point a, point b, point c) {
    return (distance(a, b) + distance(a, c) + distance(b, c)) / 2.0;
}

double triangleArea(double a, double b, double c) {
    double s = (a+b+c)/2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double incircleRadius(double area, double semiperimeter) {
    return area/semiperimeter;
}

double circumcenterRadius(double a, double b, double c) {
    return (a * b * c) / (4.0 * triangleArea(a, b, c));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    double a, b, c;
    while (cin >> a >> b >> c) {
        double semiPeri = (a+b+c)/2.0;
        double triArea = triangleArea(a, b, c);
        double inrad = incircleRadius(triArea, semiPeri);
        double incircArea = PI * inrad * inrad;
        double circumrad = circumcenterRadius(a, b, c);
        double circumArea = PI * circumrad * circumrad;

        cout << setprecision(4) << fixed << circumArea - triArea << " " <<
            triArea - incircArea << " " << incircArea << endl;
    }

    //////////////end////////////////
    return 0;
}
