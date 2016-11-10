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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    ll M, N;
    while (cin >> M >> N, M || N) {
        if (N > M) swap(M, N);

        // Rows
        ll total = 2 * M * (N*(N-1)/2);
        // Columns
        total += 2 * N * (M*(M-1)/2);

        // https://mathlesstraveled.com/2007/02/20/tetrahedral-numbers-exposed/
        // diagonal corners
        ll diags = 8 * ((N-2)*(N-1)*(N)/6);
        // diagonal center
        diags += 4 * (M-N+1) * (N*(N-1)/2);

        total += diags;

        cout << total << endl;
    }

    //////////////end////////////////
    return 0;
}
