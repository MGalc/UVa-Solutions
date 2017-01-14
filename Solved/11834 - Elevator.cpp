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

    int W, H, R1, R2;
    while (cin >> W >> H >> R1 >> R2, W || H || R1 || R2) {
        bool good = false;
        int D1 = R1*2;
        int D2 = R2*2;
        
        // Put two circles in opposite corners.
        // If the distance between them is greater than their radiuses combined,
        // It's possible to fit them in the elevator
        int height = (H - R2) - R1;
        int width = (W - R2) - R1;
        if (height * height + width * width >= (R1 + R2) * (R1 + R2) && max(D1, D2) <= min(W, H)) {
            good = true;
        }

        if (good)
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }

    //////////////end////////////////
    return 0;
}
