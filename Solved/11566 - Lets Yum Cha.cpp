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
int N, K, T, X;
int fav[120];
int memo[120][25][1200];
int price [120];

int f(int loc, int dishes, int cash) {
    int ceiled = ceil((long double)cash*1.1L); //Fails without long double, wooo!
    if (ceiled > X || dishes > N*2)
        return -1000000;
    if (ceiled == X || loc >= K || dishes == N*2)
        return 0;

    if (memo[loc][dishes][cash] != -1)
        return memo[loc][dishes][cash];

    int ret = f(loc+1, dishes, cash);
    ret = max(ret, f(loc+1, dishes+1, cash + price[loc]) + fav[loc]);
    ret = max(ret, f(loc+1, dishes+2, cash + (price[loc]*2)) + (fav[loc] * 2));
    return memo[loc][dishes][cash] = ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int inX;
    while (cin >> N >> X >> T >> K, N || X || T || K) {
        N++;
        X *= N;
        T *= N;
        //memset(fav, 0, sizeof fav);
        memset(memo, -1, sizeof memo);

        rep(i, K) {
            cin >> price[i];
            int favour = 0;
            rep(j, N) {
                int tmp;
                cin >> tmp;
                favour += tmp;
            }
            fav[i] = favour;
        }

        cout << setprecision(2) << fixed << double(f(0, 0, T)) / double(N) << endl;
    }

    //////////////end////////////////
    return 0;
}
