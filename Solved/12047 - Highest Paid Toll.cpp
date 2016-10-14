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

vector<vpii> graph, rgraph;
vi mini, rmini;
int N, M, S, T, P;

struct curpos {
    int loc, cash, maxval;
    curpos(int l, int c, int m) : loc(l), cash(c), maxval(m) {}
    bool operator<(const curpos& c) const {
        return this->cash > c.cash;
    }
};

void dijkstras1() {
    priority_queue<pii, vpii, greater<pii>> q;
    q.push(mp(0, S));
    mini[S] = 0;

    while (!q.empty()) {
        pii top = q.top();
        q.pop();
        if (top.first > mini[top.second]) continue;

        for (int i = 0; i < graph[top.second].sz; i++) {
            int nextx = graph[top.second][i].second;
            int w = top.first + graph[top.second][i].first;

            if (w >= mini[nextx]) continue;

            mini[nextx] = w;
            q.push(mp(w, nextx));
        }
    }
}

void dijkstras2() {
    priority_queue<pii, vpii, greater<pii>> q;
    q.push(mp(0, T));
    rmini[T] = 0;

    while (!q.empty()) {
        pii top = q.top();
        q.pop();
        if (top.first > rmini[top.second]) continue;

        for (int i = 0; i < rgraph[top.second].sz; i++) {
            int nextx = rgraph[top.second][i].second;
            int w = top.first + rgraph[top.second][i].first;

            if (w >= rmini[nextx]) continue;

            rmini[nextx] = w;
            q.push(mp(w, nextx));
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int TT;
    cin >> TT;
    while (TT--) {
        cin >> N >> M >> S >> T >> P;
        S--; T--;
        graph.assign(N, vpii());
        rgraph.assign(N, vpii());
        mini.assign(N, INF);
        rmini.assign(N, INF);

        rep(i, M) {
            int x, y, v;
            cin >> x >> y >> v;
            graph[x-1].push_back(mp(v, y-1));
            rgraph[y-1].push_back(mp(v, x-1));
        }

        dijkstras1();
        dijkstras2();

        int maxval = -1;
        for (int i = 0; i < graph.sz; i++) {
            for (int j = 0; j < graph[i].sz; j++) {
                int x = i, y = graph[i][j].second;
                if (mini[x] + graph[i][j].first + rmini[y] > P) continue;

                maxval = max(maxval, graph[i][j].first);
            }
        }

        if (maxval >= INF)
            cout << "-1" << endl;
        else cout << maxval << endl;
    }

    //////////////end////////////////
    return 0;
}
