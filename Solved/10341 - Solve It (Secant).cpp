//TODO: Review Newton's method, secant method and intersection.
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
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define popc(x) __builtin_popcount(x)
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
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const double PI = 2 * acos(0);

int p, q, r, s, t, u;

double f(double x) { 
    return ((p*exp(-x)) + (q * sin(x)) + (r * cos(x)) 
    + (s*tan(x)) + (t*x*x) + u);
}

double fx(double x) {
    return ((-p*exp(-x)) + (q * cos(x)) + (r * -sin(x)) 
            + (s/(cos(x)*cos(x))) + (2*t*x));
}

double calc() {
    double result = f(0);
    double x1 = 0, x2 = 1;
    while (fabs(result) > EPS) {
        double rf2 = f(x2);
        result = rf2 * ((x2 - x1)/(rf2 - f(x1)));
        x1 = x2;
        x2 -= result;
    }

    return x1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> p >> q >> r >> s >> t >> u) {
        double res = calc();
        if (res < 0 || res > 1) 
            cout << "No solution" << endl;
        else cout << setprecision(4) << fixed << res << endl;
    }

    //////////////end////////////////
    return 0;
}
