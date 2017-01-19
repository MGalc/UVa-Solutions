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
vector<int> grid;
const static int MAXV = 10;
int minvalue;

void flip(int x, int y, vector<int>& grid) {
    grid[x] ^= 1 << y;
    if (x-1 >= 0)
        grid[x-1] ^= 1 << y;
    if (x+1 < MAXV)
        grid[x+1] ^= 1 << y;
    if (y-1 >= 0)
        grid[x] ^= 1 << (y-1);
    if (y+1 < MAXV)
        grid[x] ^= 1 << (y+1);
}

void solve(int moves) {
    vi newgrid = grid;
    for (int i = 1; i < MAXV; i++) {
        for (int j = 0; j < MAXV; j++) {
            if (newgrid[i-1] & (1 << j)) {
                flip(i, j, newgrid);
                moves++;
            }
        }
    }

    bool lastEmpty = true;
    for (int i = 0; i < MAXV; i++) {
        if (newgrid[MAXV-1] & (1 << i)) {
            lastEmpty = false;
            break;
        }
    }

    if (lastEmpty)
        minvalue = min(minvalue, moves);
}

void brute(int loc, int moves) {
    solve(moves);
    for (int i = loc; i < MAXV; i++) {
        flip(0, i, grid);
        brute(i+1, moves+1);
        flip(0, i, grid);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string name;
    //while (cin >> name, name != "end") {
    while (getline(cin, name)) {
        if (name == "end") break;
        grid.assign(MAXV, 0);
        rep(i, MAXV) {
            string in;
            cin >> in;
            rep(j, in.size()) {
                if (in[j] == 'O')
                    grid[i] |= 1 << j;
            }
        }

        minvalue = INF;
        brute(0, 0);
        if (minvalue > 100) minvalue = -1;
        cout << name << " " << minvalue << endl;
        cin.ignore(100, '\n');
    }

    //////////////end////////////////
    return 0;
}
