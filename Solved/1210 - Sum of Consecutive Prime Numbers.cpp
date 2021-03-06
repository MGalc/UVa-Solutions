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
vector<bool> primelist(10100, true);
vi primes;
vi combs(10100, 0);

void buildprimes() {
    primelist[0] = false;
    primelist[1] = false;
    primes.push_back(2);
    for (int i = 4; i < 10100; i+=2)
        primelist[i] = false;

    for (int i = 3; i < 10100; i+=2) {
        if (primelist[i]) {
            for (int j = i; j < 10100; j+=i)
                primelist[j] = false;
            primes.push_back(i);
        }
    }

    for (int i = 0; i < primes.sz; i++) {
        int tot = 0;
        for (int j = i; j < primes.sz; j++) {
            tot += primes[j];
            if (tot >= 10100) break;

            combs[tot]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    buildprimes();
    int N;
    while (cin >> N, N) {
        cout << combs[N] << endl;
    }

    //////////////end////////////////
    return 0;
}
