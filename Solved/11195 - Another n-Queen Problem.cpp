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
#define popc(x) __builtin_popcount(x)
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

const double PI = 2 * acos(0);
vector<string> bads;
int numCombs;
int N;

void solve(int col, int row, int ldiag, int rdiag) {
    if (row == (1 << N)-1) {
        numCombs++;
        return;
    }
    int remaining = ~(row | ldiag | rdiag) & ((1 << N) - 1);
    while (remaining) {
        for (int i = 0; i < N; i++) {
            int shift = 1 << i;
            if (remaining & shift) {
                remaining &= ~shift;
                if (bads[i][col] != '*')
                    solve(col + 1, row | shift, (ldiag | shift) << 1, (rdiag | shift) >> 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> N, N) {
        cout << "Case " << casenum++ << ": ";
        bads.resize(N);
        rep(i, N) {
            cin >> bads[i];
        }

        numCombs = 0;
        solve(0, 0, 0, 0);
        cout << numCombs << endl;
    }


    //////////////end////////////////
    return 0;
}
