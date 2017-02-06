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
#define popc32(x) __builtin_popcount(x)
#define popc64(x) __builtin_popcountll(x)
#define MOD 1000007
#define INF 1e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);
static const int MAXN = 5000001;
static const int SQMAXN = sqrt(MAXN)+1;

vector<bool> isprime;
vi dp;

void generatePrimes() {
    dp.assign(MAXN, 0);
    isprime.assign(MAXN, true);
    isprime[0] = false;
    isprime[1] = false;

    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i; j < MAXN; j += i) {
            isprime[j] = false;
            dp[j] += i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    generatePrimes();

    vi values(MAXN, 0);
    for (int i = 2; i < MAXN; i++)
        values[i] = values[i-1] + isprime[dp[i]];

    int a, b;
    while (cin >> a >> b) {
        cout << values[b] - values[a-1] << endl;
    }

    //////////////end////////////////
    return 0;
}
