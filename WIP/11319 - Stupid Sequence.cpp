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
#define popc32(x) __builtin_popcount(x)
#define popc64(x) __builtin_popcountll(x)
#define MOD 1000007
#define INF 1e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);
vi input;
vector<double> avals;

void solveavals() {
    vector<vector<double>> xvals(7, vector<double>(7));
    vector<double> colvals(7);
    for (int i = 0; i < 7; i++) {
        colvals[i] = i+1;
        int curx = 1;
        for (int j = 0; j < 7; j++) {
            curx *= (i+1);
            xvals[i-1][j] = curx;
        }
    }

    for (int r = 0; r < xvals.size()-1; r++) {
        int largest = r;
        for (int i = r + 1; i < xvals.size(); i++) {
            if (abs(xvals[i][r]) > abs(xvals[largest][r]))
                largest = i;
        }
        swap(xvals[largest], xvals[r]);
        swap(colvals[largest], colvals[r]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        input.resize(1500);
        rep(i, 1500)
            cin >> input[i];

        avals.assign(7, 0);
        solveavals();
    }

    //////////////end////////////////
    return 0;
}
