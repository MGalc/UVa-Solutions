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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    bool first = true;
    while (T--) {
        if (first) first = false;
        else cout << endl;
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        int lowerx = max(x1, x3), lowery = max(y1, y3);
        int upperx = min(x2, x4), uppery = min(y2, y4);

        if (lowerx < upperx && lowery < uppery) {
            double vx = lowerx - upperx;
            double vy = lowery - uppery;
            cout << lowerx << " " << lowery << " " << upperx << " " << uppery << endl;
        }
        else {
            cout << "No Overlap" << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
