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

class UF {
    vi nodes;
public:
    UF(int num) {
        nodes = vi(num);
        rep(i, num) nodes[i] = i;
    }

    int parent(int v) {
        if (nodes[v] == v)
            return v;
        else return nodes[v] = parent(nodes[v]);
    }

    bool sameSet(int v1, int v2) {
        return parent(v1) == parent(v2);
    }

    void assign(int node, int p) {
        nodes[parent(node)] = parent(p);
    }
};

const double PI = 2 * acos(0);
int M, N;
vii adj;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> M >> N, M || N) {
        UF uf(M);
        adj.assign(M, vi());
        vector<pair<ll, pii>> edges;
        ll total = 0;
        rep(i, N) {
            int x, y;
            ll z;
            cin >> x >> y >> z;
            total += z;
            edges.push_back(mp(z, mp(x, y)));
        }

        sort(all(edges));

        int edgeassigned = 0;
        ll spent = 0;
        for (int i = 0; i < edges.sz; i++) {
            if (edgeassigned >= M-1)
                break;
            if (!uf.sameSet(edges[i].second.first, edges[i].second.second)) {
                spent += edges[i].first;
                edgeassigned++;
                uf.assign(edges[i].second.first, edges[i].second.second);
            }
        }

        cout << total - spent << endl;
    }

    //////////////end////////////////
    return 0;
}
