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
static const double EARTH_RADIUS = 6371009.0;
//static const double EARTH_RADIUS = 1.0;

double gcDistance(double pLat, double pLong,
        double qLat, double qLong, double radius) 
{
    pLat *= PI / 180.0; pLong *= PI / 180.0;
    qLat *= PI / 180.0; qLong *= PI / 180.0;
    double val = cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
            cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
            sin(pLat)*sin(qLat); 
    if (val > 1.0) val = 1.0;
    else if (val < -1.0) val = -1.0;
    return radius * acos(val);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        double sLat, sLong, tLat, tLong;
        cin >> sLat >> sLong >> tLat >> tLong;

        // Convert the lat/long to x/y/z coordinates with (0,0,0) being the center of the earth.
        double sRadius = cos(sLat*(PI/180)) * EARTH_RADIUS;
        double sY = sin(sLat*(PI/180.0)) * EARTH_RADIUS;
        double sX = sin(sLong*(PI/180.0)) * sRadius;
        double sZ = cos(sLong*(PI/180.0)) * sRadius;
        double tRadius = cos(tLat*(PI/180)) * EARTH_RADIUS;
        double tY = sin(tLat*(PI/180.0)) * EARTH_RADIUS;
        double tX = sin(tLong*(PI/180.0)) * tRadius;
        double tZ = cos(tLong*(PI/180.0)) * tRadius;

        double straight = sqrt((sX-tX)*(sX-tX) + (sY-tY)*(sY-tY) + (sZ-tZ)*(sZ-tZ));
        double curved = gcDistance(sLat, sLong, tLat, tLong, EARTH_RADIUS);

        cout << setprecision(0) << fixed << curved - straight << endl;
    }

    //////////////end////////////////
    return 0;
}
