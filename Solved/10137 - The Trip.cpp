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
    while (cin >> N, N) {
        vector<ld> vals(N);
        ld total = 0;
        rep(i, N) {
            cin >> vals[i];
            total += vals[i];
        } 

        ld average = total / N;
        ld pos = 0, neg = 0;
        rep(i, N) {
            ld val = (ll)((vals[i] - average) * 100) / 100.0;
            if (val < 0.0l) neg += val;
            else pos += val;
        }

        neg = fabs(neg);
        cout << fixed << setprecision(2) << "$" << max(neg, pos) << endl;

    }

    //////////////end////////////////
    return 0;
}
