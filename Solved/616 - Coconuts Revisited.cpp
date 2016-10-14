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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N >= 0) {
        int getf = N-1;
        vi factors;

        int hi = N-1;
        int lo = 1;

        while (lo <= hi) {
            hi = getf/lo;
            if (getf % lo != 0) {
                lo++;
                continue;
            }
            factors.push_back(lo);
            if (lo != hi)
                factors.push_back(hi);

            lo++;
        }

        sort(all(factors), greater<int>());

        int cur = 0;
        int best = -1;
        for (cur = 0; cur < factors.sz && best == -1; cur++) {
            int factor = factors[cur];
            int cocos = N;
            bool bad = false;
            for (int i = 0; i < factor; i++) {
                if (cocos % factor != 1) {
                    bad = true;
                    break;
                }
                cocos /= factor;
                cocos *= factor-1;
            }
            if (bad) continue;
            if (cocos % factor == 0) best = factor;
        }

        if (best == -1) 
            cout << N << " coconuts, no solution" << endl;
        else
            cout << N << " coconuts, " << best << " people and 1 monkey" << endl;
    }

    //////////////end////////////////
    return 0;
}
