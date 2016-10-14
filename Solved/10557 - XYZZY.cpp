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
    while (cin >> N, N != -1) {
        vii edges(N, vi());
        vi nodeval(N);

        rep(i, N) {
            int v, n;
            cin >> v >> n;
            nodeval[i] = -v;
            rep(j, n) {
                int nv;
                cin >> nv;
                edges[i].push_back(nv-1);
            }
        }

        vi dists(N, INF);
        vi reach(N, INF);
        if (N != 0)
            dists[0] = -100;

        for (int k = 0; k < N-1; k++) {
            for (int i =0; i < N; i++) {
                for (int j = 0; j < edges[i].sz; j++) {
                    int nextnode = edges[i][j];
                    if (dists[nextnode] > dists[i] + nodeval[nextnode] && !(dists[i] + nodeval[nextnode] >= 0)) {
                        dists[nextnode] = dists[i] + nodeval[nextnode];
                    }
                }
            }
        }

        bool cycled = false;
        for (int i = 0; i < N && !cycled; i++) {
            for (int j = 0; j < edges[i].sz && !cycled; j++) {
                int nextnode = edges[i][j];
                if (dists[nextnode] > dists[i] + nodeval[nextnode] && !(dists[i] + nodeval[nextnode] >= 0)) {

                    queue<int> q;
                    q.push(nextnode);
                    vector<bool> visited(N, false);
                    while (!q.empty() && !cycled) {
                        int top = q.front();
                        q.pop();
                        for (int k = 0; k < edges[top].sz; k++) {
                            if (edges[top][k] == N-1) {
                                cycled = true;
                                break;
                            }
                            else if (!visited[edges[top][k]]) {
                                q.push(edges[top][k]);
                                visited[edges[top][k]] = true;
                            }
                        }
                    }
                }
            }
        }

        if (cycled || dists[N-1] < 0) {
            cout << "winnable" << endl;
        }
        else
            cout << "hopeless" << endl;
    }

    //////////////end////////////////
    return 0;
}
