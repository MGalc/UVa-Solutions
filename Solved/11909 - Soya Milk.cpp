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
const double RAD90 = (90.0 * PI) / 180.0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    double L, W, H, deg;
    while (cin >> L >> W >> H >> deg) {
        double fullMilkArea = L * H;

        double inRad = deg * PI/180.0;
        double diagonalRad = atan(H/L);
        double milkLeft = 0.0; // Show this as area rather than volume (without W)
        if (inRad <= diagonalRad) {
            // We tilt the milk less than the diagonal
            // Add half the milk.
            milkLeft += fullMilkArea / 2.0;

            // Sine rule
            double removedres = sin(RAD90 - inRad);
            double jseoj = sin(inRad);
            double removedHeight = (L / sin(RAD90 - inRad)) * sin(inRad);
            double removedArea = removedHeight * L / 2.0;
            milkLeft += (fullMilkArea / 2.0) - removedArea;
        }
        else {
            // We tilt the milk more than the diagonal
            double milkRads = RAD90 - inRad;
            double milkLength = tan(milkRads) * H;
            milkLeft += milkLength * H / 2.0;
        }

        cout << setprecision(3) << fixed << milkLeft * W << " mL" << endl;
    }

    //////////////end////////////////
    return 0;
}
