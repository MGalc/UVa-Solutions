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

double d(int n) {
    return log10(n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    bool firstloop = true;
    while (cin >> N) {
        if (!firstloop)
            cout << endl;
        else
            firstloop = false;

        vii result(N, vi(N, -1));

        int xloc = 0;
        int yloc = N/2;
        int curval = 1;
        rep(i, N*N) {
            result[xloc][yloc] = curval++;
            
            int nextx = xloc-1, nexty = yloc+1;
            if (nextx < 0) {
                nextx = N-1;
            }
            if (nexty >= N) {
                nexty = 0;
            }

            if (result[nextx][nexty] != -1) {
                nextx = xloc+1;
                nexty = yloc;
                if (nextx >= N)
                    nextx = 0;
            }
            xloc = nextx;
            yloc = nexty;
        }

        int totsum = 0;
        rep(i, N)
            totsum += result[0][i];

        cout << "n=" << N << ", sum=" << totsum << endl;
        int width = ceil(log10(N*N));
        rep(i, N) {
            rep(j, N) {
                cout << " " << setfill(' ') << setw(width) << result[i][j];
            }
            cout << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
