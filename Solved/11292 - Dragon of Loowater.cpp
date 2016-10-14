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

    int M, N;
    while (cin >> N >> M, N || M) {
        vi heads(N);
        vi knights(M);
        rep(i, N)
            cin >> heads[i];
        rep(i, M)
            cin >> knights[i];
        sort(all(heads));
        sort(all(knights));

        int gold = 0;
        bool good = true;
        rep(i, N) {
            if (knights.empty()) {
                good = false;
                break;
            }

            auto loc = lower_bound(all(knights), heads[i]);
            if (loc == knights.end()) {
                good = false;
                break;
            }
            else {
                gold += *loc;
                knights.erase(loc);
            }
        }
        if (good)
            cout << gold << endl;
        else cout << "Loowater is doomed!" << endl;
    }

    //////////////end////////////////
    return 0;
}
