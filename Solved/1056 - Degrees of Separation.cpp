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

    int N, M;
    int casenum = 1;
    while (cin >> N >> M, N || M) {
        cout << "Network " << casenum++ << ": ";
        map<string, int> indexes;
        vii adj(N, vi(N, INF));
        int indx = 0;
        rep(i, M) {
            string s1, s2;
            cin >> s1 >> s2;
            int s1indx = indexes[s1], s2indx = indexes[s2];
            if (s1indx == 0) {
                indx++;
                indexes[s1] = indx;
                s1indx = indx;
            }
            if (s2indx == 0) {
                indx++;
                indexes[s2] = indx;
                s2indx = indx;
            }
            adj[s1indx-1][s2indx-1] = 1;
            adj[s2indx-1][s1indx-1] = 1;
        }

        rep(k, N) {
            rep(i, N) {
                rep(j, N) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        int largest = 0;
        for (int i = 0; i < N; i++) {
            rep(j, N) {
                if (i == j) continue;
                largest = max(largest, adj[i][j]);
            }
        }

        if (largest >= INF) {
            cout << "DISCONNECTED" << endl;
        }
        else {
            cout << largest << endl;
        }
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
