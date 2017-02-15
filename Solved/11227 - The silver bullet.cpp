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

struct point {
    double x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(double xx, double yy) : x(xx), y(yy) { }

    bool operator==(const point b) const {
        return (fabs(x - b.x) < EPS && fabs(y - b.y) < EPS);
    }
};


struct line { double a, b, c; };

line pointsToLine(point p1, point p2) {
    line l;
    if (fabs(p1.x - p2.x) < EPS) {
        // vertical line is fine
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
        // default values
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    return l;
}

bool areParallel(line l1, line l2) {
    // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); 
}

bool areSame(line l1, line l2) {
    // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int N;
        cin >> N;

        vector<point> ps;

        for (int i = 0; i < N; i++) {
            point p;
            cin >> p.x >> p.y;
            bool exists = false;
            for (int j = 0; j < ps.size(); j++) {
                if (ps[j] == p) {
                    exists = true;
                    break;
                }
            }
            if (!exists)
                ps.push_back(p);
        }

        int best = 0;
        for (int i = 0; i < ps.sz; i++) {
            int thisbest = 1;
            vector<line> lines;
            for (int j = i+1; j < ps.sz; j++) {
                lines.push_back(pointsToLine(ps[i], ps[j]));
            }
            for (int j = 0; j < lines.sz; j++) {
                int thissame = 2;
                for (int k = j+1; k < lines.sz; k++) {
                    if (areSame(lines[j], lines[k]))
                        thissame++;
                }
                thisbest = max(thisbest, thissame);
            }
            best = max(best, thisbest);
        }

        if (ps.sz > 1) 
            cout << "Data set #" << tt << " contains " << ps.sz << " gnus, out of which a maximum of " << best << " are aligned." << endl;
        else
            cout << "Data set #" << tt << " contains a single gnu." << endl;
    }

    //////////////end////////////////
    return 0;
}
