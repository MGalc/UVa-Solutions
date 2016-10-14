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
vector<pair<double, pii>> edges;
vpii input;

class UnionFind {
private:
    vi parents;
public:
    UnionFind(int n) {
        rep(i, n) parents.push_back(i);
    }
    int findroot(int n) {
        if (parents[n] == n)
            return n;
        else return parents[n] = findroot(parents[n]);
    }
    bool sameset(int a, int b) {
        return (findroot(a) == findroot(b));
    }
    void join(int a, int b) {
        parents[findroot(a)] = parents[findroot(b)];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> M >> N;
        edges.clear();
        input.clear();
        UnionFind uf(N);

        rep(i, N) {
            int a, b;
            cin >> a >> b;
            input.push_back(pii(a, b));
        }

        for (int i = 0; i < input.sz-1; i++) {
            for (int j = i+1; j < input.sz; j++) {
                double res = hypot(double(input[i].first - input[j].first), double(input[i].second - input[j].second));
                edges.push_back(mp(res, mp(i, j)));
            }
        }

        sort(all(edges));
        double largest = 0;
        int taken = 0;
        for (int i = 0; i < edges.sz; i++) {
            if (taken >= (N - M))
                break;
            int a = edges[i].second.first, b = edges[i].second.second;
            double weight = edges[i].first;
            if (!uf.sameset(a, b)) {
                uf.join(a, b);
                largest = weight;
                taken++;
            }
        }

        cout << setprecision(2) << fixed << largest << endl;
    }

    //////////////end////////////////
    return 0;
}
