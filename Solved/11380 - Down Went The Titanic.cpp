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
const int xx[] {0, 1, 0, -1};
const int yy[] {1, 0, -1, 0};

int X, Y, P;
int S, T, gridsize;
int poff;
vii adj;
vii matrix;
vi dists;
vector<string> ins;

int dfs(int loc, int flow) {
    if (flow == 0) return 0;
    if (loc == T){
        return flow;
    }

    for (int i = 0; i < adj[loc].sz; i++) {
        int next = adj[loc][i];
        if (dists[next] != dists[loc]+1 || matrix[loc][next] <= 0) continue;

        int mflow = dfs(next, min(flow, matrix[loc][next]));

        if (mflow > 0) {
            matrix[loc][next] -= mflow;
            matrix[next][loc] += mflow;
            return mflow;
        }
    }

    return 0;
}

bool bfs() {
    dists.assign(gridsize, -1);
    dists[S] = 0;
    queue<int> q;
    q.push(S);

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < adj[top].sz; i++) {
            int next = adj[top][i];
            if (dists[next] == -1 && matrix[top][next] > 0) {
                q.push(next);
                dists[next] = dists[top] + 1;
            }
        }
    }

    return (dists[T] != -1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> X >> Y >> P) {
        ins.assign(X, string());
        rep(i, X) {
            cin >> ins[i];
        }

        gridsize = (X*Y)*2 + 2, S = 0, T = gridsize-1;
        matrix.assign(gridsize, vi(gridsize, 0));
        adj.assign(gridsize, vi());
        poff = 1;

        rep(i, X) {
            rep(j, Y) {
                if (ins[i][j] == '~') continue;
                int outnode = (i*Y + j + 1) * 2 - 1;
                adj[outnode].push_back(outnode + 1);
                adj[outnode+1].push_back(outnode);

                char thischar = ins[i][j];
                if (thischar == '.') {
                    matrix[outnode][outnode+1] = 1;
                }
                else if (thischar == '*') {
                    matrix[outnode][outnode+1] = 1;
                    matrix[S][outnode] = 1;
                    adj[S].push_back(outnode);
                    adj[outnode].push_back(S);
                }
                else if (thischar == '@') {
                    matrix[outnode][outnode+1] = INF;
                }
                else if (thischar == '#') {
                    matrix[outnode][outnode+1] = INF;
                    matrix[outnode+1][T] = P;
                    adj[outnode+1].push_back(T);
                    adj[T].push_back(outnode+1);
                }

                rep(k, 4) {
                    int nextx = i + xx[k];
                    int nexty = j + yy[k];
                    if (nextx < 0 || nextx >= X || nexty < 0 || nexty >= Y) continue;

                    int innode = (nextx*Y + nexty + 1) * 2 - 1;
                    char nextchar = ins[nextx][nexty];
                    if (nextchar != '~') {
                        adj[outnode+1].push_back(innode);
                        adj[innode].push_back(outnode+1);
                        matrix[outnode+1][innode] = INF;
                    }
                }
            }
        }

        int total = 0;
        while (bfs()) {
            total += dfs(S, INF);
        }

        cout << total << endl;
    }

    //////////////end////////////////
    return 0;
}
