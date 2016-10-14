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
typedef vector<vector<int>> vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const double PI = 2 * acos(0);
vector<pair<int, pii>> edges;

class UF {
private:
    vi parents;
public:
    UF(int n) {
        rep(i, n) parents.push_back(i);
    }
    int findroot(int a) {
        if (parents[a] == a)
            return a;
        else return parents[a] = findroot(parents[a]);
    }
    int issameset(int a, int b) {
        return findroot(a) == findroot(b);
    }
    void assign(int a, int b) {
        parents[findroot(a)] = parents[findroot(b)];
    }
    void unassign(int a) {
        parents[a] = a;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        edges.clear();
        int N, M;
        cin >> N >> M;

        rep(i, M) {
            int a, b, w;
            cin >> a >> b >> w;
            a--; b--;
            edges.push_back(mp(w, mp(a, b)));
        }
        
        UF uf(N);
        sort(all(edges));

        int cheapest = 0;
        int edgescount = 0;
        vi taken;
        rep(i, edges.sz) {
            if (edgescount == N-1) break;
            int a = edges[i].second.first, b = edges[i].second.second;
            if (!uf.issameset(a, b)) {
                cheapest += edges[i].first;
                edgescount++;
                uf.assign(a, b);
                taken.push_back(i);
            }
        }

        if (N == M-1) {
            cout << cheapest << " " << cheapest << endl;
            continue;
        }

        int seccheapest = 1000000000;
        rep(j, taken.sz) {
            edgescount = 0;
            int total = 0;
            UF uf(N);
            rep(i, edges.sz) {
                if (i == taken[j]) continue;
                int a = edges[i].second.first, b = edges[i].second.second;
                if (!uf.issameset(a, b)) {
                    total += edges[i].first;
                    edgescount++;
                    uf.assign(a, b);
                }
            }
            if (edgescount == N-1)
                seccheapest = min(seccheapest, total);
        }

        cout << cheapest << " " << seccheapest << endl;
    }

    //////////////end////////////////
    return 0;
}
