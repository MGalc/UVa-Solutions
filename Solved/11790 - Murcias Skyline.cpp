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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int N;
        cin >> N;
        vi heights(N);
        vi widths(N);
        rep(i, N) {
            cin >> heights[i];
        }
        rep(i, N) {
            cin >> widths[i];
        }

        vi inc(N);
        vi de(N);

        int ldec = 0, linc = 0;
        for (int i = 0; i < N; i++) {
            inc[i] = widths[i];
            de[i] = widths[i];
            for (int j = i-1; j >= 0; j--) {
                if (heights[j] > heights[i]) {
                    de[i] = max(de[i], widths[i]+de[j]);
                }
                if (heights[j] < heights[i]) {
                    inc[i] = max(inc[i], widths[i]+inc[j]);
                }
            }

            ldec = max(ldec, de[i]);
            linc = max(linc, inc[i]);
        }

        cout << "Case " << tt << ". ";
        if (linc >= ldec) {
            cout << "Increasing (" << linc << "). Decreasing (" << ldec << ")." << endl;;
        }
        else {
            cout << "Decreasing (" << ldec << "). Increasing (" << linc << ")." << endl;;
        }
    }

    //////////////end////////////////
    return 0;
}
