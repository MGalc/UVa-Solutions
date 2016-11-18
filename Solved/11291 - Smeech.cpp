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
string in;

double getdoub(int& loc) {
    int start = loc;
    while (loc < in.sz && in[loc] != ' ') loc++;
    return stod(in.substr(start, loc-start));
}

double getint(int& loc) {
    int start = loc;
    while (loc < in.sz && in[loc] != ' ' && in[loc] != ')') loc++;
    return stoi(in.substr(start, loc-start));
}

double parseexpr(int& loc) {
    double first;
    double res;
    if (in[loc] == '(') {
        double second, third;
        loc++;
        first = getdoub(loc);
        loc++;
        second = parseexpr(loc);
        loc++;
        third = parseexpr(loc);
        // remove parenthesis
        loc++;
        return (second+third) * first + (second-third) * (1 - first);
    }
    else {
        return getint(loc);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (getline(cin, in)) {
        int tmp = 0;
        if (in == "()")
            break;
        cout << fixed << setprecision(2) << parseexpr(tmp) << endl;

    }

    //////////////end////////////////
    return 0;
}
