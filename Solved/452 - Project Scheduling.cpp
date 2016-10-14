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

vii adj;
int values[26];
int tottime[26];

int topo(int loc) {
    if (tottime[loc] != -1) return tottime[loc];
    tottime[loc] = values[loc];

    rep(i, adj[loc].sz) {
        tottime[loc] = max(tottime[loc], topo(adj[loc][i]) + values[loc]);
    }

    return tottime[loc];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;

    string strin;

        getline(cin, strin);
        getline(cin, strin);
    while (T--) {

        memset(values, 0, sizeof values);
        memset(tottime, -1, sizeof tottime);
        adj.assign(26, vi());

        while (getline(cin, strin), !strin.empty()) {
            char a;
            int b;
            ss s(strin);
            s >> a >> b;
            a -= 'A';
            values[(int)a] = b;

            string x;
            if (s >> x) {
                rep(i, x.size()) {
                    adj[(int)a].push_back((int)x[i]-'A');
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            topo(i);
        }

        int mx = -1;
        rep(i, 26) {
            if (tottime[i] == -1) continue;
            mx = max(mx, tottime[i]);
        }

        cout << mx << endl;
        if (T) cout << endl;
    }

    //////////////end////////////////
    return 0;
}
