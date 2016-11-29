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
#define Idot(a,b) ((conj(a)*(b)).X)
#define IX real()
#define IY imag()
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
vii grid;
string A, B;

int counter;
string output;
int offset;
void process(int i, int j) {
    if (i == 0 && j == 0)
        return;
    else if (i == 0) {
        // can't move up anymore in grid, have to move left
        process(i, j-1);
        output += to_string(++counter) + " Insert " + to_string(j) + "," + B[j-1] + "\n";
        offset++;
    }
    else if (j == 0) {
        // can't move left anymore in grid, have to move up
        process(i-1, j);
        output += to_string(++counter) + " Delete " + to_string(i+offset) + "\n";
        offset--;
    }
    else {
        int mini = min(grid[i][j-1], min(grid[i-1][j], grid[i-1][j-1]));
        // find the best (minimum) path to take
        if (grid[i-1][j-1] == mini) {
            process(i-1, j-1);
            if (grid[i-1][j-1] != grid[i][j])
                output += to_string(++counter) + " Replace " + to_string(i+offset) + "," + B[j-1] + "\n";
        }
        else if (grid[i][j-1] == mini) {
            process(i, j-1);
            output += to_string(++counter) + " Insert " + to_string(j) + "," + B[j-1] + "\n";
            offset++;
        }
        else if (grid[i-1][j] == mini) {
            process(i-1, j);
            output += to_string(++counter) + " Delete " + to_string(i+offset) + "\n";
            offset--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    //     A B C D
    //   0 1 2 3 4
    // B 1 1 0 0 0
    // C 2 0 1 0 0
    // D 3 0 0 1 0
    // E 4 0 0 0 1
    // F 5 0 0 0 2
    
    bool first = true;
    while (getline(cin, A) && getline(cin, B)) {
        if (!first) cout << endl;
        else first = false;
        counter = 0, offset = 0;
        output = "";
        grid.assign(A.sz+1, vi(B.sz+1, INF));
        for (int i = 0; i <= A.sz; i++)
            grid[i][0] = i;
        for (int i = 0; i <= B.sz; i++)
            grid[0][i] = i;

        rep2(i, 1, A.sz+1) rep2(j, 1, B.sz+1) {
            int c = A[i-1] != B[j-1];
            grid[i][j] = min(grid[i][j], min(grid[i-1][j-1] + c, min(grid[i-1][j] + 1, grid[i][j-1] + 1)));
        }

        int x = 1, y = 1;
        process(A.sz, B.sz);

        cout << counter << endl << output;
        cout.flush();
    }

    //////////////end////////////////
    return 0;
}
