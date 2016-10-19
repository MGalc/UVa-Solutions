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

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N, K;
    while (cin >> N >> K) {
        int sq = sqrt(N);
        vpii nums;
        vector<pair<double, int>> valindx;

        nums.push_back(mp(1, 1));
        valindx.push_back(mp(1, 0));
        int indx = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                if (gcd(i, j) == 1) {
                    nums.push_back(mp(j, i));
                    valindx.push_back(mp(j/(double)i, indx++));
                }
            }
        }

        sort(all(valindx));
        int ourindx = valindx[K-1].second;

        cout << nums[ourindx].first << "/" << nums[ourindx].second << endl;

    }

    //////////////end////////////////
    return 0;
}
