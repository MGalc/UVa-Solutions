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

ll grid[150][150];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int N, M;
        ll K;
        cin >> N >> M >> K;
        rep(i, N) {
            rep(j, M) {
                cin >> grid[i][j];
            }
        }

        int larea = -1, lmax = INT_MIN;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                int tail = 0;
                int height = (j - i) + 1, lval = 0;
                for (int k = 0; k < M; k++) {
                    if (i != j)
                        grid[i][k] += grid[j][k];

                    lval += grid[i][k];

                    while (lval > K) {
                        lval -= grid[i][tail];
                        tail++;
                    }

                    int area = (k - tail + 1) * height;
                    if (area > larea) {
                        larea = area;
                        lmax = lval;
                    }
                    else if (area == larea) {
                        if (lval < lmax) {
                            lmax = lval;
                            larea = area;
                        }
                    }
                }
            }
        }

        cout << "Case #" << tt << ": " <<  larea << " " << lmax << endl;
    }

    //////////////end////////////////
    return 0;
}
