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
static const ll MAXN = 1000000000000LL;
static const ll SQMAXN = sqrt(MAXN)+1;
int N;
ll lo, hi;
vector<bool> isprime;
vector<ll> primes;
vector<ll> almostprime;

void sieve() {
    isprime.assign(SQMAXN, true);
    isprime[2] = true;
    primes.push_back(2);
    for (int i = 3; i < SQMAXN; i += 2) {
        if (!isprime[i]) continue;
        primes.push_back(i);
        for (int j = i+i+i; j < SQMAXN; j += i+i)
            isprime[j] = false;
    }
}

void buildalmost() {
    sieve();
    for (int i = 0; i < primes.size(); i++) {
        ll alprime = primes[i] * primes[i];
        while (alprime <= MAXN) {
            almostprime.push_back(alprime);
            alprime *= primes[i];
        }
    }
    sort(all(almostprime));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    buildalmost();
    cin >> N;
    while (N--) {
        cin >> lo >> hi;
        auto loit = lower_bound(all(almostprime), lo);
        auto hiit = upper_bound(all(almostprime), hi);
        cout << hiit - loit << endl;
    }

    //////////////end////////////////
    return 0;
}
