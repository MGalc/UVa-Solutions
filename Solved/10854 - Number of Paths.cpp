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

enum input {
    IF = 'F',
    ELSE = 'L',
    ENDIF = 'N',
    ENDPROG = 'P',
    ENDINPUT = 'E'
};

const double PI = 2 * acos(0);

char lasttoken;
char nexttoken;

input getinput() {
    string in;
    while (getline(cin, in)) {
        if (in.sz == 2)
            return IF;
        if (in.sz == 4)
            return ELSE;
        if (in.sz == 6)
            return ENDIF;
        if (in.sz == 10)
            return ENDPROG;
    }

    return ENDPROG;
}

int countpaths() {
    input c;
    int paths = 1;
    while (c = getinput(), c != ENDPROG) {
        if (c == ELSE || c == ENDIF) return paths;

        paths *= countpaths() + countpaths();
    }
    return paths;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    cin >> N;

    rep(i, N) {
        int total = countpaths();

        if (total == 0) total = 1;
        cout << total << endl;
    }

    //////////////end////////////////
    return 0;
}
