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
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const double PI = 2 * acos(0);
int N;
vi ins;
int digits[] {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011 };

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N, N) {
        ins.clear();
        rep(i, N) {
            string in;
            cin >> in;
            int val = 0;
            rep(i, in.size()) {
                if (in[i] == 'Y')
                    val |= (1 << (6 - i));
            }
            ins.push_back(val);
        }

        bool done = false;
        for (int n = 9; n >= N-1 && !done; n--) {
            bool check = true;
            int actives = (1 << 7) - 1;
            for (int i = n, j = 0; j < N && check; i--, j++) {
                if ((actives & ins[j]) != ins[j]) check = false;
                if ((digits[i] & ins[j]) != ins[j]) check = false;
                int dead = digits[i] & ~ins[j];
                actives &= ~dead;
            }
            done = check;
        }
        if (done) {
            cout << "MATCH" << endl;
        }
        else cout << "MISMATCH" << endl;
    }

    //////////////end////////////////
    return 0;
}
