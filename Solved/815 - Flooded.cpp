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

    int N, M;
    int casenum = 1;
    while (cin >> M >> N, M || N) {
        vector<int> heights;
        rep(i, M) {
            rep(i, N) {
                int in;
                cin >> in;
                heights.push_back(in);
            }
        }

        int water;
        cin >> water;

        sort(all(heights));

        int current = heights[0];
        int numHeights = 100;
        double waterLeft = water;
        double waterLevel = current;
        int submerged = 0;
        for (int i = 1; i < heights.sz && waterLeft > EPS; i++) {
            int nextHeight = heights[i];
            if (heights[i] == current) {
                numHeights += 100;
            }
            else {
                submerged = numHeights;
                if (double(nextHeight - current) * numHeights > waterLeft) {
                    waterLevel += waterLeft / numHeights;
                    waterLeft = 0.0;
                }
                else {
                    waterLeft -= (double)(nextHeight - current) * numHeights;
                    waterLevel = nextHeight;
                    numHeights += 100;;
                    current = nextHeight;
                }
            }
        }
        if (waterLeft > EPS) {
            waterLevel += waterLeft / numHeights;
            submerged = numHeights;
        }

        cout << "Region " << casenum++ << endl;
        cout << "Water level is " << setprecision(2) << fixed << waterLevel << " meters." << endl;
        cout << setprecision(2) << fixed << ((double)submerged / heights.sz) << " percent of the region is under water." << endl;
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
