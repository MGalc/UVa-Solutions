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

    int f, r;
    while (cin >> f, f != 0) {
        cin >> r;
        vi fs(f), rs(r);
        rep(i, f)
            cin >> fs[i];
        rep(i, r)
            cin >> rs[i];

        multiset<double> ms;
        rep(i, f) {
            rep(j, r) {
                ms.insert(double(rs[j] / double(fs[i])));
            }
        }

        double largest = 0;
        for (auto i = ms.begin(); i != prev(ms.end()); i++) {
            largest = fmax(largest, (*next(i) / *i));
        }

        cout << fixed << setprecision(2) << largest << endl;
    }
    //////////////end////////////////
    return 0;
}
