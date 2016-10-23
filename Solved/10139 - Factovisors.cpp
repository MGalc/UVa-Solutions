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

#define MAXSQN 46341
const double PI = 2 * acos(0);
vi primes;

void sieve() {
    bitset<MAXSQN+1> mprimes;

    primes.push_back(2);
    for (int i = 3; i <= MAXSQN; i+=2) {
        //bitset vals are inverted, not set = prime, set = not prime
        if (!mprimes[i]) {
            primes.push_back(i);
            for (int j = i+i+i; j <= MAXSQN; j+=i+i) {
                mprimes[i] = true;
            }
        }
    }
}

void primefactors(int N, vector<int>& factors, vi& amount) {

    int sqn = sqrt(N);
    for (int i = 0; i < primes.sz; i++) {
        if (primes[i] > sqn) break;

        if (N % primes[i] == 0) {
            int count = 0;
            while (N % primes[i] == 0) {
                N /= primes[i];
                count++;
            }
            factors.push_back(primes[i]);
            amount.push_back(count);
        }
    }

    if (N > 1) {
        factors.push_back(N);
        amount.push_back(1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    sieve();

    ll N, M;
    while (cin >> N >> M) {
        vector<int> factors, count;
        primefactors(M, factors, count);

        vector<bool> factnum(min((ll)MAXSQN+1, N+1), false);

        bool good = true;
        rep(i, factors.sz) {
            int val = N;
            int c = count[i];
            while (c > 0 && val > 1) {
                c -= val / factors[i];
                val /= factors[i];
            }
            if (c > 0)
                good = false;
        }

        if (good)
            cout << M << " divides " << N << "!" << endl;
        else 
            cout << M << " does not divide " << N << "!" << endl;
    }

    //////////////end////////////////
    return 0;
}
