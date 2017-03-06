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
vector<pair<double, double>> airports;

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

    int N;
    while (cin >> N) {
        airports.resize(N);
        rep(i, N) {
            cin >> airports[i].first >> airports[i].second;
        }

        double bestdist = INF;
        pair<double, double> bestport = mp(-1, -1);
        for (int i = 0; i < N; i++) {
            double thismin = 0;
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
 
                thismin = max(thismin, gcDistance(
                        airports[i].first,
                        airports[i].second,
                        airports[j].first,
                        airports[j].second,
                        1.0));
            }
            if (thismin <= bestdist + EPS) {
                bestdist = thismin;
                bestport = airports[i];
            }
        }

        cout << setprecision(2) << fixed << bestport.first << " " << bestport.second << endl;
    }

    //////////////end////////////////
    return 0;
}
