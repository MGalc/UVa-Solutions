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

#define INF 1e9
const double PI = 2 * acos(0);
int xx[] {1, 0, -1, 0};
int yy[] {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int R, C;
    while (cin >> R >> C, R || C) {

        vector<vector<int>> taken(R, vector<int>(C, INF));

        int rows;
        cin >> rows;
        rep(i, rows) {
            int v, num;
            cin >> v >> num;
            rep(j, num) {
                int x;
                cin >> x;
                taken[v][x] = -1;
            }
        }

        int bx, by, fx, fy;
        cin >> bx >> by;
        cin >> fx >> fy;

        queue<pii> q;
        taken[bx][by] = 0;

        q.push(pii(bx, by));

        int dist = -1;
        while (!q.empty() && dist == -1) {
            pii tq = q.front();
            q.pop();
            int qw = taken[tq.first][tq.second];

            for (int i = 0; i < 4; i++) {
                int nextx = tq.first + xx[i];
                if (nextx < 0 || nextx >= R) continue;

                int nexty = tq.second + yy[i];
                if (nexty < 0 || nexty >= C) continue;

                if (taken[nextx][nexty] <= qw+1) continue;

                taken[nextx][nexty] = qw + 1;

                if (nextx == fx && nexty == fy) {
                    dist = taken[nextx][nexty];
                    break;
                }

                q.push(mp(nextx, nexty));
            }
        }

        cout << dist << endl;
    }

    //////////////end////////////////
    return 0;
}
