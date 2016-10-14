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

ll grid [22][22][22];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////
    
    int T;
    cin >> T;
    while (T--) {
    ll largest = 0;
        int X, Y, Z;
        cin >> X >> Y >> Z;
        rep(i, X) {
            rep(j, Y) {
                rep(k, Z) {
                    ll in;
                    cin >> in;
                    largest += in;
                    if (k != 0) {
                        in += grid[i][j][k-1];
                        if (j != 0) {
                            in += grid[i][j-1][k];
                            in -= grid[i][j-1][k-1];
                        }
                    }
                    else if (j != 0) {
                        in += grid[i][j-1][k];
                    }
                    grid[i][j][k] = in;
                }
            }
        }

        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < Z; j++) {
                for (int k = 0; k <= i; k++) {
                    for (int l = 0; l <= j; l++) {
                        ll loctot = 0;
                        for (int m = 0; m < X; m++) {
                            ll tval = grid[m][i][j];
                            if (k != 0) {
                                tval -= grid[m][k-1][j];
                                if (l != 0) {
                                    tval -= grid[m][i][l-1];
                                    tval += grid[m][k-1][l-1];
                                }
                            }
                            else if (l != 0) {
                                tval -= grid[m][i][l-1];
                            }

                            if (tval + loctot < 0) {
                                largest = max(largest, tval);
                                loctot = 0;
                            }
                            else {
                                loctot += tval;
                                largest = max(largest, loctot);
                            }
                        }
                    }
                }
            }
        }

        cout << largest << endl;
        if (T)
            cout << endl;
    }


    //////////////end////////////////
    return 0;
}
