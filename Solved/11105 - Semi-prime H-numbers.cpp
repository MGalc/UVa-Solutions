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

vector<bool> trip;
vi primes;
vi semicount;
static const int MAXN = 1000005;

void processPrimes() {
    vi isprime(MAXN, true);
    primes.clear();
    for (int i = 5; i < MAXN; i+=4) {
        if (!isprime[i]) continue;
        primes.push_back(i);
        for (int j = i+i; j < MAXN; j+=i) {
            isprime[j] = false;
        }
    }
}

void processH() {
    semicount.assign(MAXN, 0);
    
    for (int i = 0; primes[i] <= 1000; i++) {
        for (int j = i; j < primes.sz; j++) {
            if (primes[i]*primes[j] > MAXN-1) break;
            semicount[primes[i]*primes[j]] = 1;
        }
    }

    for (int i = 5; i < MAXN; i+=4) {
       semicount[i] += semicount[i-4];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    //for (int i = 1000; i <= 10000; i++)
        //cout << i << endl;
    //cout << 0 << endl;
    processPrimes();
    processH();
    int N;
    while (cin >> N, N) {
        cout << N << " " << semicount[((N-1)/4)*4+1] << endl;
    }

    //////////////end////////////////
    return 0;
}
