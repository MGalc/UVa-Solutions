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

int grid[100][100];
int input[100][100];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        memset(grid, 0, sizeof(grid));
        int N;
        cin >> N;
        rep(i, N) {
            rep(j, N) {
                cin >> input[i][j];
            }
        }

        int largest = INT_MIN;
        int max = -1000;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < i+N; j++) {
                int lmin = 0, lmax = 0, total = 0;
                int min = 1000;
                for (int k = 0; k < N; k++) {
                    if (i != j)
                        grid[i][k] += input[j%N][k];
                    else grid[i][k] = input[j%N][k];
                    int cached = grid[i][k];

                    total += cached;
                    lmax += cached;
                    max = std::max(max, lmax);
                    if (lmax < 0) {
                        lmax = 0;
                    }
                    lmin += cached;
                    min = std::min(min, lmin);
                    if (lmin > 0) {
                        lmin = 0;
                    }
                }
                if (total != min)
                    max = std::max(max, total - min);
            }
        }
        cout << max << endl;
    }

    //////////////end////////////////
    return 0;
}
