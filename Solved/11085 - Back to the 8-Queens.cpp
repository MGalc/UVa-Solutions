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

int locs[8];
int sets[8];

bool valid(int loc, int d) {
    int h = loc + d;
    rep(i, loc) {
        if(abs(loc - i) == abs(d - sets[i]))
            return false;
        if (sets[i] == d)
            return false;
    }
    return true;
}

int bt(int loc) {
    if (loc == 8) return 0;
    
    int mn = 100;
    rep(i, 8) {
        if (valid(loc, i)) {
            sets[loc] = i;

            mn = min(mn, (locs[loc] == i) ? bt(loc+1) : (bt(loc+1) + 1));
        }
    }

    return mn;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string input;
    int cas = 1;
    while (getline(cin, input)) {
        cout << "Case " << cas++ << ": ";
        ss stream(input);
        rep(i, 8) {
            stream >> locs[i];
            locs[i]--;
        }

        cout << bt(0) << endl;
    }

    //////////////end////////////////
    return 0;
}
