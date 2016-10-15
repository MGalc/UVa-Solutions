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
#define INF 1e9
#define MOD 1000007

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

    ll N, M;
    const static ld triheight = sqrt(0.75);
    const static ld uptrioffset = (0 + triheight + triheight)/3;
    const static ld downtrioffset = (0 + 0 + triheight)/3;

    while (cin >> N >> M) {
        int srow = sqrt(N);
        int trow = sqrt(M);
        //int midsrow = ((srow+1)*(srow+1) - 1)/2;
        //int midtrow = ((trow+1)*(trow+1) - 1)/2;
        ld midsrow = ((srow*2 + 2) / 2) + (srow*srow - 1);
        ld midtrow = ((trow*2 + 2) / 2) + (trow*trow - 1);
        ld xsrow = (N - midsrow)/2;
        ld xtrow = (M - midtrow)/2;
        ld ysrow = srow*triheight, ytrow = trow*triheight;
        // if a triangle's upside down (facing down)
        if ((srow + N) % 2 == 1)
            ysrow += downtrioffset;
        else
            ysrow += uptrioffset;

        if ((trow + M) % 2 == 1)
            ytrow += downtrioffset;
        else
            ytrow += uptrioffset;

        // 2x = 0
        // 2y = 1.154700538
        // //
        // 8x = 1
        // 8y = 2.309401077
        cout << fixed << setprecision(3) << hypot(xsrow - xtrow, ysrow - ytrow) << endl;
    }

    //////////////end////////////////
    return 0;
}
