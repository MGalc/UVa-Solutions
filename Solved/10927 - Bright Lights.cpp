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
#define EPS 1e-11 // Caused the WAs when set to 1e-9 :-(

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

struct lightinfo {
    int height;
    double distFromOrigin;
    double gradient;
    int x, y;
    lightinfo(int tx, int ty, int tz) {
        x = tx;
        y = ty;
        height = tz;
        distFromOrigin = hypot(x, y);
        if (x == 0) gradient = INF;
        else gradient = (double)y/x;
    }
};

bool sortLights(const lightinfo a, const lightinfo b) {
    if (a.gradient < b.gradient) return true;
    if (b.gradient < a.gradient) return false;

    if (a.distFromOrigin < b.distFromOrigin) return true;
    if (b.distFromOrigin < a.distFromOrigin) return false;

    if (a.height > b.height) return true;
    if (b.height > a.height) return false;

    return false;
}

struct point {
    int x, y;
    point(int xx, int yy) : x(xx), y(yy) {}
    bool operator<(const point b) const {
        if (x < b.x) return true;
        else if (b.x < x) return false;

        else return y < b.y;
    }
};

void findbadpoints(vector<lightinfo> lis, vector<point>& badpoints) {
    int pheight = 0;
    for (int i = 0; i < lis.sz; i++) {
        if (i != 0) {
            if (abs(lis[i].gradient - lis[i-1].gradient) < EPS) {
                if (lis[i].height <= pheight) {
                    badpoints.push_back(point(lis[i].x, lis[i].y));
                }
                pheight = max(pheight, lis[i].height);
            }
            else {
                pheight = lis[i].height;
            }
        }
        else pheight = lis[i].height;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    int casenum = 1;
    while (cin >> N, N) {
        cout << "Data set " << casenum++ << ":" << endl;
        vector<lightinfo> leftlis;
        vector<lightinfo> rightlis;

        rep(i, N) {
            int x, y, z;
            cin >> x >> y >> z;
            lightinfo li(x, y, z);
            if (x > 0 || (x == 0 && y > 0))
                rightlis.push_back(li);
            else
                leftlis.push_back(li);
        }
        sort(leftlis.begin(), leftlis.end(), sortLights);
        sort(rightlis.begin(), rightlis.end(), sortLights);
        vector<point> badpoints;

        findbadpoints(leftlis, badpoints);
        findbadpoints(rightlis, badpoints);

        if (badpoints.empty()) {
            cout << "All the lights are visible." << endl;
        }
        else {
            cout << "Some lights are not visible:" << endl;
            sort(all(badpoints));
            rep(i, badpoints.sz) {
                cout << "x = " << badpoints[i].x << ", y = " << badpoints[i].y;
                if (i == badpoints.sz - 1) cout << ".";
                else cout << ";";
                cout << endl;
            }
        }
    }

    //////////////end////////////////
    return 0;
}
