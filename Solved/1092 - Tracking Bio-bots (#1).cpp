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
ll R, C, W;

struct piiv {
    int y, x1, x2;
    piiv(int row, int x1v, int x2v) : y(row), x1(x1v), x2(x2v) {}
    piiv() {}
};
bool sortpiiv(piiv a, piiv b) {
    if (a.y > b.y)
        return true;
    else if (a.y < b.y)
        return false;
    else
        return a.x2 > b.x2;
}

inline void split(piiv wall, list<pii>& curvals) {
    for (auto i = curvals.begin(); !curvals.empty() && i != curvals.end();) {
        if (i->first > wall.x2) {
            i++;
            continue;
        }
        if (i->second < wall.x1)
            break;

        if (i->first >= wall.x1) { 
            if (i->second <= wall.x2) {
                // Our value is within the wall, remove it completely
                i = curvals.erase(i);
            }
            else {
                // Our value extends over to the right
                i->first = max(i->first, wall.x2) + 1;
                i++;
            }
        }
        else if (i->second <= wall.x2) {
            // Right part of our value gets cut off by the wall
            i->second = min(i->second, wall.x1) - 1;
            i++;
        }
        else {
            // The wall is in the middle of our value
            // Split the current value into two
            pii tmp = *i;
            i->second = wall.x1 - 1;
            tmp.first = wall.x2 + 1;
            curvals.insert(i, tmp);
            i++;
            i++;
        }
    }
}

inline void expandLeft(piiv wall, list<pii>& curvals, list<pii>::iterator& curloc) {
    list<pii> test = curvals;
    bool expanded = false;
    while (curloc != curvals.end()) {
        if (curloc->second < wall.x1) return;

        if (expanded)
            curloc = curvals.erase(curloc);
        else {
            expanded = true;
            curloc->first = wall.x2+1;
            curloc++;
        }
    }
}

inline int counttot(list<pii>& vals) {
    int total = 0;
    For(i, vals) {
        total += i->second - i->first + 1;
    }
    return total;
}

#define gc getchar_unlocked
void scanint(int &x)
{
	int c=gc();
	x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void scanint(long long int &x)
{
	int c=gc();
	x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main() {
    //////////////start//////////////
    ios::sync_with_stdio(false);
    int casenum = 1;
    list<pii> currow;
    vector<piiv> walls;
    vector<piiv> inwalls;
    while (scanint(R), scanint(C), scanint(W), R || C || W) {
        cout << "Case " << casenum++ << ": ";
        if (W == 0) {
            cout << "0" << endl;
            continue;
        }
        inwalls.clear();
        ll totwall = 0;
        rep(i, W) {
            int x1, x2, r;
            scanint(x1);
            scanint(r);
            scanint(x2);
            scanint(r);
            inwalls.push_back(piiv(r, x1, x2));
            totwall += x2 - x1 + 1;
        }
        sort(all(inwalls), sortpiiv);
        inwalls.push_back(piiv(-1, -1, -1));

        walls.clear();
        for (int i = 0; i < inwalls.sz-1; i++) {
            piiv toadd = inwalls[i];
            while (inwalls[i].y == inwalls[i+1].y && inwalls[i].x1-1 == inwalls[i+1].x2) {
                toadd.x1 = inwalls[i+1].x1;
                i++;
            }
            walls.push_back(toadd);
        }
        walls.push_back(piiv(-1, 0, C-1)); // Final blocking row

        int prevrow = R;
        currow.clear();
        int startloc = 0;
        if (walls[0].y == R-1) {
            if (walls[0].x2 != C-1)
                currow.push_back(mp(walls[0].x2+1, C-1));
            while (startloc < walls.sz && walls[startloc].y == R-1)
                startloc++;
        }
        else
            currow.push_back(mp(0, C-1));

        ll reached = 0;
        for (int i = 0; i < walls.sz;) {
            if (currow.empty()) break; // Break out early if we have no available paths
            if (walls[i].y != prevrow - 1) { // We're not on the row after the one last processed
                currow.resize(1);
                currow.begin()->first = 0;
                reached += (ll)counttot(currow) * (ll)(prevrow - walls[i].y - 1);
            }

            prevrow = walls[i].y;
            int startindx = i;
            while (i < walls.sz && walls[i].y == prevrow) {
                split(walls[i], currow);
                i++;
            }
            if (currow.empty()) break;
            i = startindx;
            auto curit = currow.begin();
            while (i < walls.sz && walls[i].y == prevrow) {
                expandLeft(walls[i], currow, curit);
                i++;
            }
            expandLeft(piiv(0, -1, -1), currow, curit); // Left side expansion to edge

            reached += counttot(currow);
        }

        cout << (R*C) - (reached + (ll)totwall) << endl;
    }

    //////////////end////////////////
    return 0;
}
