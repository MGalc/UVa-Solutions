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

int N, C;
vi vals;

bool sim(int val) {
    int curval = 0;
    int count = 1;
    for (int i = 0; i < N; i++) {
        if (curval + vals[i] > val) {
            curval = 0;
            count++;
            i--;
        }
        else {
            curval += vals[i];
        }

        if (count > C)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N >> C) {
        vals.assign(N, 0);
        rep(i, N) {
            cin >> vals[i];
        }

        int lo = 0, hi = 1e9;
        int mn = 1e9;
        while (hi > lo) {
            int mid = (hi+lo)/2;
            if (sim(mid)) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }

        cout << hi << endl;
    }

    //////////////end////////////////
    return 0;
}
