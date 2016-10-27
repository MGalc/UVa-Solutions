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
#define MOD 131071

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

    string in;
    while (getline(cin, in)) {
        int num = 0;
        bool done = false;
        while (!done) {
            rep(i, in.sz) {
                if (in[i] == '#') {
                    done = true; 
                    break;
                }

                num = (num << 1) | (in[i] - '0');
                num %= MOD;
            }
            if (!done)
                getline(cin, in);
        }

        if (num == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    //////////////end////////////////
    return 0;
}
