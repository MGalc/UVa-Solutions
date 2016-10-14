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
#define MOD 1000007

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
typedef pair<point, point> segment;
typedef pair<ld, point> circle;
typedef vector<point> polygon;

const ld PI = 2 * acos(0);

typedef pair<int, ld> pid;
vector<vector<pid>> adj;
ld total;

void tour(int loc) {
    for (int i = 0; i < adj[loc].sz; i++) {
        pid next = adj[loc][i];
        if (next.second <= 0) continue;

        total += adj[loc][i].second;
        adj[loc][i].second = -1;
        tour(adj[loc][i].first);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;

    while (T--) {

        map<pair<int, int>, int> index;

        int x, y, a, b;
        cin >> x >> y;

        pii home;
        home = mp(x, y);
        index[home] = 1;
        int indxloc = 2;

        string in;
        adj.assign(250, vector<pid>());
        getline(cin, in);
        total = 0;
        while (getline(cin, in), in != "") {
            ss ins(in);
            ins >> x >> y;
            pii input1 = pii(x, y);
            int indx1 = index[input1];
            if (indx1 == 0) {
                indx1 = indxloc;
                index[input1] = indxloc++;
            }
            ins >> a >> b;
            pii input2 = pii(a, b);
            int indx2 = index[input2];
            if (indx2 == 0) {
                indx2 = indxloc;
                index[input2] = indxloc++;
            }

            indx1--, indx2--;
            ld dist = hypot(abs(ld(input1.first) - ld(input2.first)), abs(ld(input1.second) - ld(input2.second)));
            dist = (dist / 20000) * 60;
            adj[indx1].push_back(mp(indx2, dist));
            adj[indx2].push_back(mp(indx1, dist));
            //total += dist + dist;
        }


        tour(0);

        total = round(total);

        cout << (int)total/60 << ":" << setfill('0') << setw(2) << (int)total%60 << endl;
        if (T) cout << endl;
    }

    //////////////end////////////////
    return 0;
}
