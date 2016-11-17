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
int loc;
bool bad;
bool returning;

int nextint() {
    if (in[loc] < '0' || in[loc] > '9') {
        bad = true;
        return 0;
    }

    int digit = 1;
    int num = 0;
    while (loc >= 0 && in[loc] >= '0' && in[loc] <= '9') {
        num += (in[loc] - '0') * digit;
        digit *= 10;
        loc--;
    }
    return num;
}

int solve() {
    if (loc < 0) {
        bad = true;
        return 0;
    } 

    int total = 0;
    if (in[loc] == ')') {
        loc--;
        total += solve();
        if (returning == false) {
            bad = true;
            return 0;
        }
        returning = false;
    }
    else {
        total += nextint();
        if (bad) return 0;
    }

    while (!bad && loc >= 0) {
        if (in[loc] == '(') {
            loc--;
            returning = true;
            return total;
        }
        else if (returning) return total;

        if (in[loc] == '+') {
            loc--;
            total += solve();
        }
        else if (in[loc] == '*') {
            loc--;
            if (in[loc] >= '0' && in[loc] <= '9')
                total *= nextint();
            else if (in[loc] == ')'){
                loc--;
                total *= solve();
                if (returning == false) {
                    bad = true;
                    return 0;
        }
                returning = false;
            }
        }
        else {
            bad = true;
            return 0;
        }
    }

    if (bad) return 0;
    else return total;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    cin >> N;
    getline(cin, in);

    while (N--) {
        getline(cin, in);

        bad = false;
        loc = in.sz - 1;
        returning = false;
        int res = solve();

        if (bad || returning)
            cout << "ERROR" << endl;
        else cout << res << endl;

    }

    //////////////end////////////////
    return 0;
}
