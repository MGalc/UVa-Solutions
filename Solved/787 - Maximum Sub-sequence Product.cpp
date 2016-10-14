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

ll max(ll a, ll b) {
    return a > b ? a : b;
}
ll min(ll a, ll b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int tmp;
    while (cin >> tmp) {
        if (tmp == -999999) continue;
        vector<ll> in;
        in.push_back(tmp);
        while (cin >> tmp, tmp != -999999) {
            in.push_back(tmp);
        }

        ll largest = numeric_limits<ll>::min();
        ll lpos = 1, lneg = 1;
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == 0) {
                lpos = 1; lneg = 1;
                largest = max(largest, 0);
            }
            if (in[i] < 0) {
                if (lneg < 0) {
                    ll prevlpos = lpos;
                    lpos = lneg * in[i];
                    lneg = in[i] * prevlpos;
                    largest = max(largest, lpos);
                }
                else  {
                    lneg = in[i] * lpos;
                    lpos = 1;
                    largest = max(largest, lneg);
                }
            }
            else {
                if (lneg < 0) {
                    lneg *= in[i];
                }
                lpos *= in[i];
                largest = max(largest, lpos);
            }
        }

        cout << largest << endl;
    }
    //////////////end////////////////
    return 0;
}
