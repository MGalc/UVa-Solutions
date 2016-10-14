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

    int N;
    bool begin = true;
    while (cin >> N, N) {
        if (begin) begin = false;
        else cout << endl;
        vi bags(N);
        rep(i, N)
            cin >> bags[i];
        sort(all(bags));

        int mrep = 1;
        for (int i = 0; i < N-1; i++) {
            int j;
            for (j = i+1; j < N; j++) {
                if (bags[i] != bags[j]) {
                    break;
                }
            }
            mrep = max(mrep, j-i);
            i = j-1;
        }

        vii pieces(mrep);
        rep(i, N) {
            pieces[i%mrep].push_back(bags[i]);
        }

        cout << pieces.size() << endl;
        rep(i, pieces.size()) {
            rep(j, pieces[i].size()) {
                if (j != 0) cout << " ";
                cout << pieces[i][j];
            }
            cout << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
