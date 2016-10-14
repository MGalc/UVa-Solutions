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

int grid[110][110];
int input[110][110];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////
    
    int N;
    while (cin >> N) {
        rep(i, N) {
            if (i == 0) {
                rep (j, N) {
                    int in;
                    cin >> in;
                    input[i][j] = in;
                    grid[i][j] = in;
                }
            }
            else {
                rep (j, N) {
                    int in;
                    cin >> in;
                    input[i][j] = in;
                    grid[i][j] = in + input[i-1][j];
                }
            }
        }

        int largest = INT_MIN;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (i != j) {
                    for (int k = 0; k < N; k++) {
                        grid[i][k] += input[j][k];
                    }
                }
                int slong = 0;
                for (int k = 0; k < N; k++) {
                    slong += grid[i][k];
                    largest = max(largest, slong);
                    if (slong < 0) {
                        slong = 0;
                    }
                }
            }
        }
        cout << largest << endl;
    }

    //////////////end////////////////
    return 0;
}
