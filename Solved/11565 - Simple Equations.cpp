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

    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;

        bool done = false;
        int sqx = 0, sqy = 0;;
        int a = 0, b = 0, c = 0;
        for (int x = -22; x <= 22; x++) {
            sqx = x*x;
            if (sqx > C)
                continue;
            if (done)
                break;
            for (int y = -100; y <= 100; y++) {
                int sqy = sqx + y*y;
                if (sqy > C)
                    continue;
                if (y == x)
                    continue;
                if (done)
                    break;
                for (int z = -100; z <= 100; z++) {
                    if (y == z || x == z)
                        continue;
                    int add = (x + y + z);
                    if (add > A)
                        break;
                    if (add == A && (x*y*z == B) && ((sqy) + (z*z) == C)) {
                        done = true;
                        a = x; b = y; c = z;
                        break;
                    }

                }
            }
        }

        if (a > b)
            swap(a, b);

        if (done)
            cout << a << " " << b << " "<< c << endl;
        else cout << "No solution." << endl;
    }

    //////////////end////////////////
    return 0;
}
