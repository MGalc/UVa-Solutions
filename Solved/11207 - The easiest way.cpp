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
#define popc(x) __builtin_popcount(x)
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

const double PI = 2 * acos(0);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N) {
        int largestindx = 0;
        double largestnum = 0;
        for (int i = 1; i <= N; i++) {
            double v1, v2;
            cin >> v1 >> v2;
            if (v1 > v2)
                swap(v1, v2);

            double largest = min(v2/4.0, v1);
            largest = max(largest, v1/2.0);

            if (largest > largestnum) {
                largestnum = largest;
                largestindx = i;
            }
        }

        cout << largestindx << endl;
    }

    //////////////end////////////////
    return 0;
}
