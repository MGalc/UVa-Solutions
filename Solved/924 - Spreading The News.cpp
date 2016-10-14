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
const int INF = 1e9;
vii graph;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    cin >> N;
    graph.assign(N, vi());
    rep(i, N) {
        int num;
        cin >> num;
        rep(j, num) {
            int x;
            cin >> x;
            graph[i].push_back(x);
        }
    }

    int T;
    cin >> T;
    rep(i, T) {
        int t;
        cin >> t;
        vi visited(N, INF);
        queue<int> q;
        q.push(t);
        vi daily(1, 0);
        visited[t] = 0;

        while (!q.empty()) {
            int val = q.front();
            q.pop();
            rep(j, graph[val].sz) {
                int nextv = graph[val][j];
                if (visited[nextv] == INF) {
                    q.push(nextv);
                    visited[nextv] = visited[val] + 1;
                    if (visited[nextv] < daily.size()) {
                        daily[visited[nextv]]++;
                    }
                    else
                        daily.push_back(1);
                }
            }
        }

        if (graph[t].sz == 0) {
            cout << "0" << endl;
        }
        else {
            int firstboom = 0, maxboom = 0;
            rep2(i, 1, daily.sz) {
                if (maxboom < daily[i]) {
                    firstboom = i;
                    maxboom = daily[i];
                }
            }

            cout << maxboom << " " << firstboom << endl;
        }
    }


    //////////////end////////////////
    return 0;
}
