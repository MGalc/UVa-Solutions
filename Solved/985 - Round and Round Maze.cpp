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
static const int N = 0, E = 1, S = 2, W = 3;
static const vi xx {-1, 0, 1, 0};
static const vi yy {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int R, C;
    while (cin >> R >> C) {
        vii gridmask(R, vi(C, 0));
        vii dist(R, vi(C, 0));
        int maxV = R*C-1;
        rep(r, R) {
            rep(c, C) {
                if (r == R-1 && c == C-1) break;
                string in;
                cin >> in;
                //mask is NESW
                int mask = 0;
                rep(j, in.sz) {
                    switch (in[j]) {
                        case 'N': mask |= 1 << N; break;
                        case 'E': mask |= 1 << E; break;
                        case 'S': mask |= 1 << S; break;
                        case 'W': mask |= 1 << W; break;
                    }
                }
                gridmask[r][c] = mask;
            }
        }

        vector<vii> grid(R, vii(C, vi(4, INF)));
        grid[0][0][0] = 0;

        queue<pair<pii, int>> q;
        q.push(mp(pii(0, 0), 0));

        bool reachedEnd = false;
        while (!q.empty() && !reachedEnd) {
            pii loc = q.front().first;
            int time = q.front().second;
            q.pop();
            int offset = time & 0x3;
            int thismask = gridmask[loc.first][loc.second];
            int newgridmask = ((thismask << offset) | (thismask >> (4-offset))) & 0xF;

            rep(i, 4) {
                pii next(loc.first + xx[i], loc.second + yy[i]);

                // Out of bounds check
                if (next.first >= R || next.first < 0 || next.second >= C || next.second < 0)
                    continue;

                // Check rotating tile
                if (!(newgridmask & (1 << i)))
                    continue;

                // Check if we've been the before.
                if (grid[next.first][next.second][(time+1)&3] > time + 1) {
                    grid[next.first][next.second][(time+1)&3] = time+1;
                    q.push(mp(next, time + 1));
                    if (next.first == R-1 && next.second == C-1) {
                        reachedEnd = true;
                        break;
                    }
                }
            }
        }

        // Kinda yuck
        if (grid[R-1][C-1][0] != INF)
            cout << grid[R-1][C-1][0] << endl;
        else if (grid[R-1][C-1][1] != INF)
            cout << grid[R-1][C-1][1] << endl;
        else if (grid[R-1][C-1][2] != INF)
            cout << grid[R-1][C-1][2] << endl;
        else if (grid[R-1][C-1][3] != INF)
            cout << grid[R-1][C-1][3] << endl;
        else 
            cout << "no path to exit" << endl;
    }

    //////////////end////////////////
    return 0;
}
