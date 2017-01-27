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

struct binfo {
    int value;
    int moves;

    binfo (int v, int m) : value(v), moves(m) {}

    bool operator<(const binfo rhs) const {
        if (value == rhs.value)
            return (moves > rhs.moves);
        else 
            return value < rhs.value;
    }
    bool operator>(const binfo rhs) const {
        return rhs < *this;
    }
    binfo& operator+(const binfo rhs) {
        value += rhs.value;
        moves += rhs.moves;
        return *this;
    }
};

vi valN, valS, osN, osS;
int N, S;
vector<vector<binfo>> dp;

binfo search(int n, int s) {
    if (n >= N || s >= S) 
        return {0,0};
    if (dp[n][s].value != -1) 
        return dp[n][s];

    binfo mx = {-1,-1};
    if (osN[n] == osS[s]) {
        mx = max(mx, binfo(valN[n] + valS[s], 1) + search(n+1, s+1));
    }
    mx = max(mx, search(n, s+1));
    mx = max(mx, search(n+1, s));

    return dp[n][s] = mx;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        map<string, int> OS;
        int OSindx = 1;

        cin >> N;

        valN.assign(N, 0);
        osN.assign(N, 0);

        rep(i, N) {
            string name, os;
            int value;
            cin >> name >> os >> value;
            int osindx = OS[os];
            if (osindx == 0)
                OS[os] = osindx = OSindx++;
            valN[i] = value;
            osN[i] = osindx;
        }

        cin >> S;

        valS.assign(S, 0);
        osS.assign(S, 0);

        rep(i, S) {
            string name, os;
            int value;
            cin >> name >> os >> value;
            int osindx = OS[os];
            if (osindx == 0)
                OS[os] = osindx = OSindx++;
            valS[i] = value;
            osS[i] = osindx;
        }

        dp.assign(N, vector<binfo>(S, {-1,-1}));

        binfo answ = search(0, 0);
        cout << answ.value << " " << answ.moves << endl;
    }

    //////////////end////////////////
    return 0;
}
