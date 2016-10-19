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

    int arr[21];
    memset(arr, 0, sizeof arr);

    ll nv = 4;
    ld logn = 0;
    ld logfac = 0;
    ll curindx = 0;

    for (int i = 0; i <= 20; i++) {
        ld lognv = nv;
        while (logfac < lognv) {
            curindx++;
            logfac += (logl(curindx)/logl(2));
        }
        arr[i] = curindx - 1;

        nv *= 2;
    }

    int N;
    while (cin >> N, N) {
        int indx = (N - 1960)/10;
        cout << arr[indx] << endl;
    }

    //////////////end////////////////
    return 0;
}
