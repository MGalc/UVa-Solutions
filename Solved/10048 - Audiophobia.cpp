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
typedef vector<pair<int, pii>> ees;

const double PI = 2 * acos(0);
int C, S, Q, A, B;
ees edges;
vector<vector<pair<int, int>>> graph;

class UnionFind {
private:
    vi parent;
public:
    UnionFind(int n) {
        parent = vi(n);
        rep(i, n)
            parent[i] = i;
    }
    int findroot(int n) {
        if (n == parent[n])
            return n;
        else return parent[n] = findroot(parent[n]);
    }
    bool issameset(int a, int b) {
        return findroot(a) == findroot(b);
    }
    void join(int p, int a) {
        parent[findroot(p)] = parent[findroot(a)];
    }
};

int findpath(int loc, int prev) {
    rep(i, graph[loc].size()) {
        if (graph[loc][i].first == prev)
            continue;
        if (graph[loc][i].first == B)
            return graph[loc][i].second;
        else {
            int ret = findpath(graph[loc][i].first, loc);
            if (ret != -1)
                return max(ret, graph[loc][i].second);
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> C >> S >> Q, C || S || Q) {
        if (casenum != 1)
            cout << endl;
        cout << "Case #" << casenum++ << endl;

        UnionFind uf(C);
        edges.clear();
        graph.assign(C, vector<pii>());
        rep(i, S) {
            int a, b, w;
            cin >> a >> b >> w;
            a--; b--;
            edges.push_back(mp(w, mp(a, b)));
            edges.push_back(mp(w, mp(b, a)));
        }

        sort(all(edges));

        int totedges = 0;
        rep(i, edges.sz) {
            if (totedges == C-1)
                break;
            int a = edges[i].second.first;
            int b = edges[i].second.second;
            int w = edges[i].first;

            vii ok;

            if (!uf.issameset(a, b)) {
                uf.join(a, b);
                graph[a].push_back(mp(b, w));
                graph[b].push_back(mp(a,w));
            }
        }

        rep(i, Q) {
            cin >> A >> B;
            A--; B--;
            int total = findpath(A, -1);
            if (total == -1)
                cout << "no path" << endl;
            else cout << total << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
