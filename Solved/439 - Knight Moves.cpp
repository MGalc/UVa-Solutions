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

vi xx { -2, -1, 1, 2, 2, 1, -1, -2 };
vi yy { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string from, to;
    while (cin >> from >> to) {
        vii grid(8, vi(8, -1));
        int Sx = from[0]-'a';
        int Sy = from[1]-'1';
        int Tx = to[0]-'a';
        int Ty = to[1]-'1';

        queue<pii> q;
        q.push(mp(Sx, Sy));
        grid[Sx][Sy] = 0;

        while (!q.empty()) {
            pii top = q.front();
            q.pop();

            for (int i = 0; i < xx.size(); i++) {
                int nextx = top.first + xx[i];
                int nexty = top.second + yy[i];
                if (nextx < 0 || nextx >= 8 || nexty < 0 || nexty >= 8)
                    continue;
                if (grid[nextx][nexty] != -1)
                    continue;
                grid[nextx][nexty] = grid[top.first][top.second] + 1;
                q.push(mp(nextx, nexty));
            }
        }

        int answer = grid[Tx][Ty];
        cout << "To get from " << from << " to " << to << " takes " << answer << " knight moves." << endl;
    }

    //////////////end////////////////
    return 0;
}
