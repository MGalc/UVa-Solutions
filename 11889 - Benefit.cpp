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
static constexpr int maxN = 10000000;
static constexpr int sqmaxN = 3164;

vi primes;

void sieve() {
    bitset<sqmaxN> mprimes;
    primes.push_back(2);
    for (int i = 3; i < sqmaxN; i+=2) {
        if (!mprimes[i]) {
            primes.push_back(i);
            for (int j = i+i+i; j < sqmaxN; j+=i+i) {
                mprimes[j] = true;
            }
        }
    }
}

void primefactors(int n, vpii& factors) {
    for (int i = 0; i < primes.sz; i++) {
        if (n == 1) break;
        if (n % primes[i] == 0) {
            int pow = 0;
            while (n % primes[i] == 0) {
                pow++;
                n /= primes[i];
            }
            factors.push_back(mp(primes[i], pow));
        }
    }

    if (n > 1)
            factors.push_back(mp(n, 1));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    sieve();
    int T;
    cin >> T;
    while (T--) {
        int a, c;
        cin >> a >> c;
        if (c % a != 0) {
            cout << "NO SOLUTION" << endl;
            continue;
        }

        vpii cfactors;
        primefactors(c, cfactors);
        ll b = 1;
        rep(i, cfactors.sz) {
            bool bad = false;
            rep(j, cfactors[i].second) {
                if (a % cfactors[i].first == 0)
                    a /= cfactors[i].first;
                else {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                rep(j, cfactors[i].second)
                    b *= cfactors[i].first;
            }
        }

        cout << b << endl;
    }

    //////////////end////////////////
    return 0;
}
