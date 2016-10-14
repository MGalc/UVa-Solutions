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
vii adj;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (true) {
        vi mapped(110, -1);
        adj.assign(110, vi(110, 1000000));
        string in;
        getline(cin, in);
        ss kk(in);
        int x, y;
        int indx = 0;
        while (kk >> x >> y, x || y) {
            x--; y--;
            if (mapped[x] == -1)
                mapped[x] = indx++;
            if (mapped[y] == -1)
                mapped[y] = indx++;

            adj[mapped[x]][mapped[y]] = 1;
        }

        if (indx == 0)
            break;

        for (int k = 0; k < indx; k++) {
            for (int i = 0; i < indx; i++) {
                for (int j = 0; j < indx; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        int tot = 0;
        rep(i, indx) {
            rep(j, indx) {
                if (i == j) continue;
                tot += adj[i][j];
            }
        }

        cout << "Case " << casenum++ << ": average length between pages = " << fixed << setprecision(3) << tot/(double)(indx*(indx-1)) << " clicks" << endl;
    }

    //////////////end////////////////
    return 0;
}
