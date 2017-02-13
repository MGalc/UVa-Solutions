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

double cross(vect a, vect b) {
    return a.x * b.y - a.y * b.x; 
}

bool ccw(point p, point q, point r) {
    return cross(toVect(p, q), toVect(p, r)) > 0; 
}

struct tower {
    int x, y, p;
    tower(int x, int y, int p) : x(x), y(y), p(p) {}
    tower() {};
};
int N, R;

vector<int> LHS;
vector<int> RHS;
vector<vector<int>> bigraph;
vector<int> parents;
vector<bool> visited;

int match(int left) {
    if (visited[left])
        return 0;
    visited[left] = true;

    for (int i = 0; i < bigraph[left].size(); i++) {
        int right = bigraph[left][i];
        if (parents[right] == -1) {
            parents[right] = left;
            return 1;
        }
        else if (parents[right] != left) {
            if (match(parents[right]) == 1) {
                parents[right] = left;
                return 1;
            }
        }
    }

    return 0;
}

int MCBM(int maxdist) {
    int totNodes = LHS.size() + RHS.size();
    bigraph.assign(totNodes, vector<int>());
    parents.assign(totNodes, -1);

    for (int i = 0; i < LHS.size(); i++) {
        for (int j = 0; j < RHS.size(); j++) {
            bigraph[i].push_back(LHS.size()+j);
        }
    }

    int matched = 0;
    for (int i = 0; i < LHS.size(); i++) {
        visited.assign(totNodes, false);
        matched += match(i);
    }

    return matched;
}

double dist(tower a, tower b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> N, N) {
        cout << "Case " << casenum++ << ": ";

        vector<tower> towers(N);
        rep(i, N) {
            cin >> towers[i].x >> towers[i].y >> towers[i].p;
        }

        int w1, w2;
        cin >> w1 >> w2 >> R;
        w1--; 
        w2--;
        point p1 = point(towers[w1].x, towers[w1].y);
        point p2 = point(towers[w2].x, towers[w2].y);

        towers.erase(towers.begin() + w1); // Kinda bad but oh well.
        if (w2 > w1)
            towers.erase(towers.begin() + w2 - 1);
        else
            towers.erase(towers.begin() + w2);

        for (auto it = towers.begin(); it != towers.end();) {
            if (it->p <= 0)
                towers.erase(it);
            else
                it++;
        }

        LHS.clear(); // Left of the line
        RHS.clear(); // Right of the line
        for (int i = 0; i < towers.sz; i++) {
            if (ccw(p1, p2, point(towers[i].x, towers[i].y))) {
                LHS.push_back(i);
            }
            else {
                RHS.push_back(i);
            }
        }
        if (LHS.size() > RHS.size()) // We want the LHS to be smaller.
            LHS.swap(RHS);

        int totNodes = LHS.size() + RHS.size();
        bigraph.assign(totNodes, vector<int>());
        parents.assign(totNodes, -1);

        for (int i = 0; i < LHS.size(); i++) {
            for (int j = 0; j < RHS.size(); j++) {
                if (dist(towers[LHS[i]], towers[RHS[j]]) <= R && towers[LHS[i]].p > towers[RHS[j]].p) {
                    bigraph[i].push_back(LHS.size()+j);
                }
            }
        }

        int matched = 0;
        for (int i = 0; i < LHS.size(); i++) {
            visited.assign(totNodes, false);
            matched += match(i);
        }

        cout << matched << endl;
    }


    //////////////end////////////////
    return 0;
}
