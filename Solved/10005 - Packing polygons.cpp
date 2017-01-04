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

double distance(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N) {
        vector<point> points(N);
        rep(i, N) {
            int x, y;
            cin >> x >> y;
            points[i] = point(x, y);
        }
        
        double r;
        cin >> r;
        double d = r * 2.0;

        bool good = false;
        for (int i = 0; i < N-1 && !good; i++) {
            for (int j = i+1; j < N && !good; j++) {
                point center;
                if (circle2PtsRad(points[i], points[j], r, center)) {
                    bool thisgood = true;
                    rep(i, N) {
                        if (distance(center, points[i]) > r) {
                            thisgood = false;
                            break;
                        }
                    }
                    if (thisgood) good = true;
                }
                if (circle2PtsRad(points[j], points[i], r, center)) {
                    bool thisgood = true;
                    rep(i, N) {
                        if (distance(center, points[i]) > r) {
                            thisgood = false;
                            break;
                        }
                    }
                    if (thisgood) good = true;
                }
            }
        }

        if (!good)
            cout << "There is no way of packing that polygon." << endl;
        else
            cout << "The polygon can be packed in the circle." << endl;
    }

    //////////////end////////////////
    return 0;
}
