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
#define INF 1e9

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

    int N;
    while (cin >> N) {
        vector<vector<vector<double>>> adj(N, vector<vector<double>>(N, vector<double>(N, 0)));
        rep(i, N) {
            rep(j, N) {
                if (i == j) {
                  continue;
                }
                cin >> adj[i][j][0];
            }
        }
        vector<vii> prevs(N, vii(N, vi(N)));
        rep(i, N) rep(j, N) rep(k, N) prevs[i][j][k] = i;

        int bestsize = 0;
        for (int s = 1; s < N; s++) {
            for (int k = 0; k < N; k++) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        double res = adj[i][k][s-1] * adj[k][j][0];
                        if (res > adj[i][j][s]) {
                            adj[i][j][s] = res;
                            prevs[i][j][s] = k;
                        }
                    }
                }
            }
        }

        bool done = false;
        int mincount = 0;
        vi path;
        for (int k = 1; k < N && !done; k++) {
            for (int i = 0; i < N && !done; i++) {
                if (adj[i][i][k] >= 1.01) {
                    done = true;
                    mincount = k;
                    int count = k;
                    int curloc = i;
                    while (count >= 0) {
                        path.push_back(curloc);
                        curloc = prevs[i][curloc][count];
                        count--;
                    }
                    path.push_back(i);
                }
            }
        }

        if (!done)
            cout << "no arbitrage sequence exists" << endl;
        else 
        {
            for (int i = path.size()-1; i >= 0; i--) {
                if (i != path.size()-1)
                    cout << " ";
                cout << path[i]+1;
            }
            cout << endl;
        }

    }

    //////////////end////////////////
    return 0;
}
