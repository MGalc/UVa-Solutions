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
int N, X, Y;
vi pieces;
vii dp;
int endmask;
vi sums; 

inline int getsum(int mask) {
    if (sums[mask] != -1) // DP this speeds the solution up quite a lot (0.5secs in submission)
        return sums[mask];

    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) {
            sum += pieces[i];
        }
    }
    return sums[mask] = sum;
}

bool solve(int width, int mask) {
    if (dp[width][mask] != -1)
        return dp[width][mask];

    int inverse = endmask & ~(mask);
    if (popc32(inverse) == 1) {
        return dp[width][mask] = true;
    }

    int height = getsum(inverse) / width;

    bool good = false;
    for (int perm = inverse & (inverse - 1); perm != 0; perm = (perm-1) & inverse) {
        int secondhalf = inverse ^ perm;
        if (perm < secondhalf) break; // We've done more than half
        int count1 = getsum(perm);
        int count2 = getsum(secondhalf);

        if (count1 % width == 0 && count2 % width == 0)
            good |= solve(width, mask | perm) && solve(width, mask | secondhalf);
        if (good) 
            break;

        if (count1 % height == 0 && count2 % height == 0)
            good |= solve(width - count1/height, mask | perm) && solve(width - count2/height, mask | secondhalf);
        if (good) 
            break;
    }

    return dp[width][mask] = good;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> N, N) {
        sums.assign(1 << N, -1);
        endmask = (1 << N) - 1;
        cout << "Case " << casenum++ << ": ";
        cin >> X >> Y;
        int area = X*Y;

        pieces.resize(N);
        int piecesarea = 0;
        rep(i, N) {
            cin >> pieces[i];
            piecesarea += pieces[i];
        }

        bool result = false;
        if (piecesarea == area) {
            dp.assign(X+1, vector<int>(1 << N, -1)); 
            result = solve(X, 0);
        }

        cout << (result ? "Yes" : "No")  << endl;
    }

    //////////////end////////////////
    return 0;
}
