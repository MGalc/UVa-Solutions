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

// Just use the ellipse formula PI*A*B

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    cin >> N;
    while (N--) {
        int D, L;
        cin >> D >> L;
        
        // Find how far up the cow can go from the center of the two pillars
        double yrad = sqrt((L / 2.0) * (L / 2.0) - (D / 2.0) * (D / 2.0));
        // The cow's movement horizontally depends on the amount which the rope reaches divided by 2
        double xrad = L / 2.0;
        double res = PI * xrad * yrad;
        cout << setprecision(3) << fixed << res << endl;
    }

    //////////////end////////////////
    return 0;
}
