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

pii first;
pii last;
vector<bool> used;
vpii doms;
vpii curr;
int spaces;
int pcs;

bool bt(int loc) {
    if (loc == spaces+1) {
        if (last.first == curr[curr.size() - 1].second) {
            return true;
        }
    }

    bool good = false;
    for (int i = 0; i < doms.size() && !good; i++) { 
        if (used[i])
            continue;

        used[i] = true;
        if (loc == 1) {
            if (doms[i].first == first.second) {
                curr.push_back(doms[i]);
                good = bt(loc+1);
                curr.pop_back();
            }
            if (good) return true;
            if (doms[i].second == first.second) {
                pii locp = doms[i];
                swap(locp.first, locp.second);

                curr.push_back(locp);
                good = bt(loc+1);
                curr.pop_back();
            }
        }
        else {
            if (doms[i].first == curr[curr.size()-1].second) {
                curr.push_back(doms[i]);
                good = bt(loc+1);
                curr.pop_back();
            }
            if (good) return true;
            if (doms[i].second == curr[curr.size()-1].second) {
                pii locp = doms[i];
                swap(locp.first, locp.second);

                curr.push_back(locp);
                good = bt(loc+1);
                curr.pop_back();
            }
        }
        used[i] = false;
    }

    return good;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> spaces, spaces != 0) {
        doms.clear();
        cin >> pcs;
        int x1, x2;
        cin >> x1 >> x2;
        first = mp(x1, x2);
        cin >> x1 >> x2;
        last = mp(x1, x2);

        used.assign(pcs, false);
        for (int i = 1; i <= pcs; i++) {
            cin >> x1 >> x2;
            doms.push_back(mp(x1,x2));
        }

        if (bt(1))
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    //////////////end////////////////
    return 0;
}
