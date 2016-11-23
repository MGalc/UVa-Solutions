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
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const double PI = 2 * acos(0);

// for:
// abcde
// n = 119
//
// 5! = 1 * 2 * 3 * 4 * 5 = total amount of permutations
// The permutations of bcde will repeat every 4! (1*2*3*4) times so we will need to replace the
// char at the 0th index with the next highest character.
// abcde : n = 0 * 4!
// bacde : n = 1 * 4!
// cabde : n = 2 * 4!
// dabce : n = 3 * 4!
// eabcd : n = 4 * 4!
// so we do (n / 4!) to get the char at the 0th index
//
// Once we get the character at the 0th index, we sort the rest of the characters and repeat the above steps
// with n = n % (remaining chars)!

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////
    
    int N;
    cin >> N;
    while (N--) {
        string in;
        ull n;
        cin >> in >> n;
        sort(all(in));

        ull perms = 1;
        // get total amount of permutations
        rep(i, in.sz)
            perms *= (i+1);

        rep(i, in.sz) {
            sort(i + in.begin(), in.end());
            ull newperm = perms / (in.sz - i);

            ull permreps = 1;
            ull count = 1;
            for (int j = 1; j < in.sz; j++) {
                if (in[j] == in[j-1])
                    count++;
                else {
                    permreps /= count;
                    count = 1;
                }
            }

            ull div = (n % perms) / (newperm);
            perms /= in.sz-i;
            swap(in[i], in[i+div]);
        }

        cout << in << endl;
    }

    //////////////end////////////////
    return 0;
}
