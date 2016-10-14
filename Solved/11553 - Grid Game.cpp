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

int main() {
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        int xy;
        cin >> xy;
        vii grid(xy);

        vi permrow(xy);
        rep(i, xy) {
            rep (j, xy) {
                int in;
                cin >> in;
                grid[i].push_back(in);
            }
            permrow[i] = i;
        }

        int largest = INT_MAX;
        do {
            int colmask = 0;
            int total = 0;
            for (int i : permrow) {
                int smallest = INT_MAX;
                int indx;
                for (int j = 0; j < xy; j++) {
                    if ((colmask & (1 << j)) == 0) {
                        if (grid[i][j] < smallest) {
                            smallest = grid[i][j];
                            indx = j;
                        }
                    }
                }
                colmask |= (1 << indx);
                total += smallest;
            }
            if (total < largest)
                largest = total;

        } while (next_permutation(all(permrow)));

        cout << largest << endl;

    }

    //////////////end////////////////
    return 0;
}
