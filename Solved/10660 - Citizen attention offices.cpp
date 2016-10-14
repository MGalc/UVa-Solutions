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

const int SZ = 25;
int grid[SZ];
inline int distc(int loc, int loc2) {
    return abs(loc%5 - loc2%5) + abs(loc/5 - loc2/5);
}

int main() {
    //////////////start//////////////
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) {
        memset(grid, 0, sizeof(grid));
        int nums;
        cin >> nums;
        rep(i, nums) {
            int x, y, v;
            cin >> x >> y >> v;
            grid[(x*5) + y] += v;
        }

        int best = INT_MAX;
        vi res {-1, -1, -1, -1, -1};
        for (int a = 0; a < SZ-4; a++) {
            for (int b = a+1; b < SZ-3; b++) {
                for (int c = b+1; c < SZ-2; c++) {
                    for (int d = c+1; d < SZ-1; d++) {
                        for (int e = d+1; e < SZ; e++) {
                            int v[5] {a,b,c,d,e};
                            int totdist = 0;
                            for (int i = 0; i < SZ; i++) {
                                int min = INT_MAX;
                                for (int j = 0; j < 5; j++) {
                                    int dist = distc(i, v[j]) * grid[i];
                                    if (dist < min)
                                        min = dist;
                                }
                                totdist += min;
                            }
                            if (totdist < best) {
                                res = {a,b,c,d,e};
                                best = totdist;
                            }
                        }
                    }
                }
            }
        }

        rep(i, res.size()) {
            cout << res[i];
            if (i != res.size()-1)
                cout << " ";
        }
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
