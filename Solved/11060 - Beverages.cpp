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
int N;
vii adj;
vector<string> name;
map<string, int> indx;
vi indeg;
vi order;

void topsort(int loc) {
    indeg[loc] = -1;
    rep(i, adj[loc].sz) {
        indeg[adj[loc][i]]--;
    }

    order.push_back(loc);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int testc = 1;
    while (cin >> N) {
        cout << "Case #" << testc++ << ": Dilbert should drink beverages in this order: ";
        name.assign(N, "");
        indx.clear();
        order.clear();
        rep(i, N) {
            string in;
            cin >> in;
            name[i] = in;
            indx[in] = i;
        }

        adj.assign(N, vi());
        indeg.assign(N, 0);

        int M;
        cin >> M;
        rep(i, M) {
            string str1, str2;
            cin >> str1 >> str2;
            adj[indx[str1]].push_back(indx[str2]);
            indeg[indx[str2]]++;
        }

        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0) {
                topsort(i);
                i = -1;
            }
        }

        string out;
        for (auto it = order.begin(); it != order.end(); it++) {
            if (it != order.begin())
                out += " ";
            out += name[*it];
        }

        cout << out << "." << endl << endl;
    }

    //////////////end////////////////
    return 0;
}
