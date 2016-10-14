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
    while (cin >> N) {
        vi books(N);
        rep(i, N) {
            cin >> books[i];
        }
        int total;
        cin >> total;

        sort(all(books));

        int besta = 1e8;
        int bestb = -1e8;
        bool found = false;
        for (int i = 0; i < N-1; i++) {
            vi::iterator loc = lower_bound(books.begin()+i+1, books.end(), total-books[i]);
            if (loc == books.end())
                continue;
            if (books[i] + *loc == total) {
                if (abs(besta-bestb) > abs(books[i] - *loc)) {
                    besta = books[i];
                    bestb = *loc;
                }
            }
        }

        cout << "Peter should buy books whose prices are " << besta << " and " << bestb << "." << endl << endl;
    }

    //////////////end////////////////
    return 0;
}
