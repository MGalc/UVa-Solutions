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
int N, K;
vector<vi> edges;
vector<int> nodes;
int largest;
vi nlargest;

void bt(int loc, int total) {
    if (loc == N) {
        if (total > largest) {
            largest = total;
            nlargest = nodes;
        }
        return;
    }
    
    if (nodes[loc] != -1)
        return bt(loc+1, total);

    nodes[loc] = 1;
    vi sets;
    rep(i, edges[loc].size()) {
        if (nodes[edges[loc][i]] == -1) {
            nodes[edges[loc][i]] = 0;
            sets.push_back(edges[loc][i]);
        }
    }

    bt(loc+1, total+1);

    rep(i, sets.size()) {
        nodes[sets[i]] = -1;
    }

    nodes[loc] = 0;
    bt(loc+1, total);

    nodes[loc] = -1;
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        edges.assign(N, vi());
        nodes.assign(N, -1);
        nlargest.clear();
        largest = 0;

        rep(k, K) {
            int x1, x2;
            cin >> x1 >> x2;
            edges[x1-1].push_back(x2-1);
            edges[x2-1].push_back(x1-1);
        }

        bt(0, 0);
        cout << largest << endl;
        bool first = true;
        rep(i, nlargest.size()) {
            if (nlargest[i] == 1) {
                if (!first)
                    cout << " ";
                else first = false;
                cout << i+1;
            }
        }
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
