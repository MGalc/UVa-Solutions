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
int A, N;
vi houses;

bool solve(double dist) {
    int remA = A;
    double nextloc = -1.0;
    for (int i = 0; i < N; i++) {
        if (remA >= N - i)
            return true;
        if (houses[i] > nextloc) {
            if (remA <= 0)
                return false;
            remA--;
            nextloc = houses[i] + dist + dist;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> A >> N;
        houses.resize(N);
        rep(i, N) 
            cin >> houses[i];

        sort(all(houses));

        double lo = 0, hi = 1000000; // Change to better hi val l8r
        while ((hi - lo) > 0.024) {
            double mid = (lo+hi)/2;
            if (solve(mid))
                hi = mid;
            else
                lo = mid;
        }

        cout << setprecision(1) << fixed << round(lo*10)/10 << endl;
    }

    //////////////end////////////////
    return 0;
}
