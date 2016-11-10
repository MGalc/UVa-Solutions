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
#define Idot(a,b) ((conj(a)*(b)).X)
#define IX real()
#define IY imag()
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

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case " << tt << ": ";
        string in;
        cin >> in;

        int total = 0;
        int moves = 0;
        rep(i, in.sz) {
            total += in[i] - '0';
            if (in[i] % 3 == 0) moves++;
        }

        if (in.sz != moves && total % 3 != 0) rep(i, in.sz) {
            if ((total - (in[i] - '0')) % 3 == 0) {
                moves++;
                break;
            } 
        }

        if (moves == in.sz - 1) moves = in.sz;

        if (moves % 2 == 0) cout << "T" << endl;
        else cout << "S" << endl;
    }

    //////////////end////////////////
    return 0;
}
