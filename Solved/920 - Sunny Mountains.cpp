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
    public:
    int x, y;
    point() { x = 0; y = 0; }
    point(int tx, int ty) : x(tx), y(ty) {}
    bool operator<(const point cmp) const {
        return x < cmp.x;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<point> pts;
        rep(i, N) {
            int x, y;
            cin >> x >> y;
            pts.push_back(point(x, y));
        }
        sort(all(pts));

        int largesty = 0;
        double totlength = 0.0;
        for (int i = pts.sz - 2; i >= 0; i--) {
            if (pts[i].y <= largesty) continue;
            double lineheight = pts[i].y - pts[i+1].y;
            double sunheight = pts[i].y - largesty;
            double linelength = hypot(pts[i].x - pts[i+1].x, pts[i].y - pts[i+1].y);
            double sunlength = linelength / (lineheight / sunheight);

            totlength += sunlength;

            largesty = pts[i].y;
        }

        cout << setprecision(2) << fixed << totlength << endl;
    }

    //////////////end////////////////
    return 0;
}
