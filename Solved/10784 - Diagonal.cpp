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

/*
 Pretty simple question.

 When N <= 3, n has no diagonals
 When N = 4, n = 1, 2          2 solutions
 When N = 5, n = 3, 4, 5       3 solutions
 When N = 6, n = 6, 7, 8, 9    4 solutions

 Notice a pattern?
 We can use Gauss's formula ((n*(n+1))/2 = 1 + 2 + ... + n) to solve this problem.
 Notice that we start at N = 4 rather than N = 1
 Therefore, in the formula we set n = n-3

 Writing this as an equation, we get:

 N = (n-2)(n-3)
     ----------
         2

 0 = n^2 - 5n + 6 - 2N

 solving for n:

 n = 5 + sqrt(5^2 - 4(6 - 2N))
     -------------------------
               2*1

 n = 5 + sqrt(1 + 8N)
     -----------------
            2
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    ll N;
    int casenum = 1;

    while (cin >> N, N) {
        cout << "Case " << casenum++ << ": ";
        ll answ = (5 + (int)sqrt(1 + 8*N)) / 2;
        cout << answ << endl;
    }

    //////////////end////////////////
    return 0;
}
