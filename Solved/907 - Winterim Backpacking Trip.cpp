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
#define popc(x) __builtin_popcount(x)
#define INF 1e9

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
vi nums;
int X, Y;

inline bool checkv(int val) {
    int nights = 0;
    int tot = 0;
    rep(i, nums.sz) {
        if (nums[i] > val) return false;
        if (tot+nums[i] > val) {
            tot = nums[i];
            nights++;
        }
        else
            tot += nums[i];
    }
    if (nights > Y) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> X >> Y) {
        X++;
        nums.assign(X, 0);
        rep(i, X)
            cin >> nums[i];

        int hi = INF, lo = 0;
        while (hi != lo) {
            int mid = (hi+lo)/2;

            bool res = checkv(mid);
            if (res) hi = mid;
            else lo = mid+1;
        }

        cout << lo << endl;
    }

    //////////////end////////////////
    return 0;
}
