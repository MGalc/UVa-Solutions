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

    string word;

    // ABCBCBCBABCBCB
    // BCBCBABCBCBCBA - R
    //
    // BCBCBABCBCB
    
    // ABDUIFHEEH
    // HEEHFIUDBA
    //
    // HEEH
    
    while (getline(cin, word)) {
        string rv = word;
        reverse(all(rv));

        vector<int> kmp(word.sz, -1);

        rep2(i, 1, rv.sz) {
            int indx = kmp[i-1] + 1;
            while (!(indx == 0 && rv[i] != rv[indx])) {
                if (rv[i] == rv[indx]) {
                    kmp[i] = indx;
                    break;
                }
                indx = kmp[indx-1] + 1;
            }
        }

        int indx = 0;
        rep(i, word.sz) {
            if (rv[indx] == word[i]) {
                indx++;
            }
            else while (!(indx == 0 && rv[indx] != word[i])) {
                if (rv[indx] == word[i]) {
                    indx++;
                    break;
                }
                indx = kmp[indx-1] + 1;
            }
        }

        cout << word << rv.substr(indx, string::npos) << endl;
    }

    //////////////end////////////////
    return 0;
}
