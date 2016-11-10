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
ll results[1000100];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    // n == 4
    // 2 3 4
    // n == 5
    // 2 4 5
    // 3 4 5
    // n == 6
    // 2 5 6
    // 3 5 6
    // 3 4 6
    // 4 5 6
    // n == 7
    // 2 6 7
    // 3 6 7
    // 3 5 7
    // 4 6 7
    // 4 5 7
    // 5 6 7
    // n == 8
    // 2 7 8
    // 3 7 8
    // 3 6 8
    // 4 7 8
    // 4 6 8
    // 4 5 8
    // 5 7 8
    // 5 6 8
    // 6 7 8
    
    // odd n = res[n-1] + (1 + 2 + ... + (n/2 - 1)) * 2
    // even n = res[n-1] + (1 + 2 + ... + (n/2 - 2)) * 2 + (n/2 - 1)
    results[0] = 0;
    results[1] = 0;
    results[2] = 0;
    results[3] = 0;
    for (int i = 4; i <= 1000000; i++) {
        if (i % 2 == 0) { // even
            ll n = i/2 - 2;
            results[i] = results[i-1] + (n*(n+1)/2) * 2 + (i/2 - 1);
        }
        else { // odd
            ll n = i/2 - 1;
            results[i] = results[i-1] + (n*(n+1)/2) * 2;
        }
    }

    int N;
    while (cin >> N, N >= 3) {
        cout << results[N] << endl;
    }

    //////////////end////////////////
    return 0;
}
