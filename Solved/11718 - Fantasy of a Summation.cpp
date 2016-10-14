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
ll mod;

// Two methods of quick log2(N) powers

// This method squares the base number and reduces the exponent by half
ll quickpow(ll n, ll k) {
    ll res = 1;
    while (k > 0) {

        // We can't divide the exponent exactly in half because exponent is odd.
        // Multiply the one 'left over' value
        if (k % 2 == 1)
            res = (res * n) % mod;

        n = (n*n) % mod;
        k /= 2;
    }

    return res;
}

// Similar to the above method, however
// this one uses factorisations of n^k for odd & even exponents.
// https://en.wikipedia.org/wiki/Exponentiation_by_squaring
ll exponentiationBySquaring(ll n, ll k) {
    n %= mod;
    if (k == 0) return 1;
    if (k == 1) return n % mod;
    if (k % 2 == 0) return (exponentiationBySquaring(n * n, k / 2)) % mod;
    if (k % 2 == 1) return (n * exponentiationBySquaring(n * n, (k-1) / 2)) % mod;

    return 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    ll N, K, T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case " << tt << ": ";
        cin >> N >> K >> mod;
        ll sum = 0;

        rep(i, N) {
            ll in;
            cin >> in;
            sum = (sum + (in % mod)) % mod;
        }

        ll res = (quickpow(N, K-1) * (K % mod) * (sum % mod)) % mod;
        //ll res2 = (exponentiationBySquaring(N, K-1) * (K % mod) * (sum % mod)) % mod;
        //assert(res == res2);

        cout << res << endl;
    }

    //////////////end////////////////
    return 0;
}
