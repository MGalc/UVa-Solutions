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
#define Idot(a,b) ((conj(a)*(b)).X)
#define IX real()
#define IY imag()
#define popc(x) __builtin_popcount(x)
#define INF 1e9
#define MOD 1000007
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
    point() { x = 0; y = 0; }
    point(double xx, double yy) { x = xx; y = yy; }
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

vect toUnitVect(point p1, point p2) {
    double dist = hypot(p1.x - p2.x, p1.y - p2.y);
    vect v;
    v.x = (p2.x - p1.x)/dist;
    v.y = (p2.y - p1.y)/dist;
    return v;
}

double dotProduct(vect v1, vect v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double distance(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    double X, Y;
    while (cin >> X >> Y) {
        point p(X, Y);
        int N;
        cin >> N;
        double tmpx, tmpy;
        cin >> tmpx >> tmpy;
        point a(tmpx, tmpy);
        point b;

        double bestdist = INF;
        double bestx = 0, besty = 0;
        rep(i, N) {
            cin >> tmpx >> tmpy;
            b = point(tmpx, tmpy);

            vect vab = toVect(a, b);
            vect vap = toVect(a, p);
            double dot = dotProduct(vab, vap);

            // Dot product is the reflection of A onto B multiplied by the length of B or vice verca.
            // A.B = lengthOfProjectionOnB * |B| or...
            // A.B = |A|cos(theta) * |B|
            // |A|cos(theta) = A.B / |B|
            // divide |B| on both sides:
            // |A|cos(theta) / |B| = A.B / (B.x^2 + B.y^2) aka...
            // ratioOfProjectionToB = A.B / (B.x^2 + B.y^2)
            double ratioOfProjectionToB = dot / (vab.x * vab.x + vab.y * vab.y);
            double dist = INF;
            double thisx, thisy;
            if (ratioOfProjectionToB < 0.0) { // projection out of bounds
                dist = distance(a, p);
                thisx = a.x;
                thisy = a.y;
            }
            else if (ratioOfProjectionToB > 1.0) { // projection out of bounds
                dist = distance(b, p);
                thisx = b.x;
                thisy = b.y;
            }
            else { // projection within bounds
                point c = a;
                vab.x *= ratioOfProjectionToB;
                vab.y *= ratioOfProjectionToB;
                c.x += vab.x;
                c.y += vab.y;
                dist = distance(c, p);
                thisx = c.x;
                thisy = c.y;
            }
            if (dist < bestdist) {
                bestdist = dist;
                bestx = thisx;
                besty = thisy;
            }
            a = b;
        }

        //if (N == 0) { // edge case
            //bestx = a.x;
            //besty = a.y;
        //}

        cout << setprecision(4) << fixed << bestx << endl;
        cout << setprecision(4) << fixed << besty << endl;

    }

    //////////////end////////////////
    return 0;
}
