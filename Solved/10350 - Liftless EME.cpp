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
int N, M;
int maxN;
vi dp;
vector<vpii> adj;

int dfs(int loc) {
    if (dp[loc] != INF) return dp[loc];

    int mindist = INF;
    rep(i, adj[loc].sz) {
        mindist = min(mindist, dfs(adj[loc][i].first) + adj[loc][i].second);
    }

    return dp[loc] = mindist;
}

inline int gval(int i, int j) {
    return i*M + j;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string name;
    while (cin >> name) {
        cin >> N >> M;
        maxN = (N-1)*M + 1;
        adj.assign(maxN, vpii());
        dp.assign(maxN, INF);

        rep(i, N-1) {
            rep(j, M) {
                int thisv = gval(i, j);
                rep(k, M) {
                    int x;
                    cin >> x;
                    if (i != 0) x+=2;

                    if (i == N-2) {
                        adj[thisv].push_back(mp(maxN-1, x));
                    }
                    else {
                        adj[thisv].push_back(mp(gval(i+1, k), x));
                    }
                }
            }
        }

        int mini = INF;
        dp[maxN-1] = 2;
        rep(i, M) {
            mini = min(mini, dfs(i));
        }

        cout << name << endl << mini << endl;
    }

    //////////////end////////////////
    return 0;
}
