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
vector<vector<char>> fingers { {}, {'q', 'a', 'z'}, {'w', 's', 'x'}, {'e', 'd', 'c'}, {'r', 'f', 'v', 't', 'g', 'b'}, {' '}, {' '}, {'y', 'h', 'n', 'u', 'j', 'm'}, {'i', 'k', ','}, {'o', 'l', '.'}, {'p', ';', '/'} };

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N, W;
    while (cin >> N >> W) {
        vector<char> canuse(128, true);
        rep(i, N) {
            int finger;
            cin >> finger;
            rep(j, fingers[finger].sz)
                canuse[fingers[finger][j]] = false;
        }

        vector<string> strings;
        int length = 0;
        rep(i, W) {
            string in;
            cin >> in;
            bool good = true;
            rep(j, in.sz) {
                if (!canuse[in[j]]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                if (in.sz > length) {
                    strings.clear();
                    length = in.sz;
                }
                if (in.sz == length) {
                    if (find(all(strings), in) == strings.end())
                        strings.push_back(in);
                }
            }
        }

        sort(all(strings));
        cout << strings.sz << endl;
        rep(i, strings.sz) {
            cout << strings[i] << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
