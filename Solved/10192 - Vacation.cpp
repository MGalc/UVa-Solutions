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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string A, B;
    int casenum = 0;
    while (getline(cin, A) && A[0] != '#' && getline(cin, B)) {
        cout << "Case #" << ++casenum << ": ";

        vii grid(A.sz+1, vi(B.sz+1, 0));
        // base cases are 0
        
        for (int i = 1; i <= A.sz; i++) {
            for (int j = 1; j <= B.sz; j++) {
                // offset of -1 for the left and top padding
                int add = A[i-1] == B[j-1];
                grid[i][j] = max(grid[i-1][j-1] + add, max(grid[i-1][j], grid[i][j-1]));
            }
        }

        cout << "you can visit at most " << grid[A.sz][B.sz] << " cities." << endl;
    }

    //////////////end////////////////
    return 0;
}
