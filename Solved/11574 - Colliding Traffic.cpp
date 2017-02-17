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

// Equation =
// r = collision distance
// x = initial x location
// y = initial y location
// sx = speed moving in x direction
// sy = speed moving in y direction
// dx = x1 - x2
// dsx = sx1 - sx2
// dy = y1 - y2
// dsy = sy1 - sy2
//
// We have:
// r = sqrt(((x1 + t*sx1) - (x2 + t*sx2))^2 + ((y1 + t*sy1) - (y2 + t*sy2)^2))
// r^2 = (dx + t*dsx)^2 + (dy + t*dsy)^2
// 0 = dsx^2*t^2 + dsy^2*t^2 + 2*dx*dsx*t + 2*dy*dsy*t + dx^2 + dy^2 - r^2
// Then we can use the quadratic formula to get a value for t.

struct boat {
    double x, y, rads, s;
    double speedx, speedy;
    boat(double x, double y, double degs, double s) : x(x), y(y), s(s) 
    {
        rads = degs * (PI / 180.0);
        speedx = s * sin(rads);
        speedy = s * cos(rads);
    }
    boat() {}
};

int N;
double R, RR;

double collisionTime(const boat& b1, const boat& b2) {
    double dx = b1.x - b2.x;
    double dy = b1.y - b2.y;
    double dsx = b1.speedx - b2.speedx;
    double dsy = b1.speedy - b2.speedy;
    double a = dsx * dsx + dsy * dsy;
    if (fabs(a) < EPS)
        return INF; // Dividing by 0
    double b = 2.0 * dx * dsx + 2.0 * dy * dsy;
    double c = dx * dx + dy * dy - RR;
    if (c < 0.0) // This means that these boats start in a collision.
        return 0.0;

    double sqtop = sqrt(b*b - 4.0*a*c);
    if (sqtop < -EPS)
        return INF; // Sq root of negative

    double time1 = (-b + sqtop) / (2.0*a);
    double time2 = (-b - sqtop) / (2.0*a);

    if (time1 > time2) swap(time1, time2);


    if (time1 < -EPS) {
        if (time2 > -EPS)
            return time2;
        else return INF;
    }
    else
        return time1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> R;
        RR = R*R;
        vector<boat> boats(N);

        rep(i, N) {
            double x, y, d, s;
            cin >> x >> y >> d >> s;
            boats[i] = boat(x, y, d, s);
        }

        double lowest = INF;
        for (int i = 0; i < boats.size(); i++) {
            for (int j = i+1; j < boats.size(); j++) {
                lowest = min(lowest, collisionTime(boats[i], boats[j]));
            }
        }

        if (lowest >= INF)
            cout << "No collision." << endl;
        else
            cout << setprecision(0) << fixed << lowest << endl;
    }

    //////////////end////////////////
    return 0;
}
