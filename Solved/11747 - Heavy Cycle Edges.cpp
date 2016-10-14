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
int N, M;
vector<pair<ll, pii>> edges;

class UnionFind {
private:
    vi nums;
public:
    UnionFind(int n) { rep(i, n) nums.push_back(i); }
    int root(int node) {
        if (nums[node] == node)
            return node;
        else return nums[node] = root(nums[node]);
    }
    void set(int node, int parent) {
        nums[root(node)] = root(parent);
    }
    bool sameset(int n1, int n2) {
        return (root(n1) == root(n2));
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N >> M, N || M) {
        edges.clear();
        rep(i, M) {
            int x, y;
            ll w;
            cin >> x >> y >> w;
            edges.push_back(mp(w, mp(x, y)));
        }

        sort(all(edges));

        vector<ll> outputs;
        UnionFind uf(N);
        for (int i = 0; i < edges.sz; i++) {
            int x = edges[i].second.first; int y = edges[i].second.second;
            if (!uf.sameset(x, y)) {
                uf.set(x, y);
            }
            else {
                outputs.push_back(edges[i].first);
            }
        }

        string out = "";
        if (outputs.empty())
            out = "forest";
        else {
            rep(i, outputs.sz) {
                out += to_string(outputs[i]);
                if (i != outputs.sz-1) {
                    out += " ";
                }
            }
        }

        cout << out << endl;
    }

    //////////////end////////////////
    return 0;
}
