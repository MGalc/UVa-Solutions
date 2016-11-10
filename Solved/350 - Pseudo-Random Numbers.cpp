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

int Z, L, I, M;
    
inline int getval(int l) {
    return (Z * l + I) % M;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> Z >> I >> M >> L, Z || I || M || L) {

        cout << "Case " << casenum++ << ": ";

        int T = getval(L), H = getval(getval(L));
        while (T != H) {
            T = getval(T);
            H = getval(getval(H));
        } 

        H = L;
        int u = 0;
        while (T != H) {
            u++;
            T = getval(T);
            H = getval(H);
        } 

        int k = 1;
        H = getval(T);
        while (T != H) {
            k++;
            H = getval(H);
        }

        cout << k << endl;
    }

    //////////////end////////////////
    return 0;
}
