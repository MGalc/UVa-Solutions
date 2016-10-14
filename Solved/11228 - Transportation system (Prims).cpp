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

int N, R;
vector<pair<int, int>> ins;
vector<bool> visited;
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

void process(int loc) {
    visited[loc] = true;

    for (int i = 0; i < N; i++) { 
        double dist = hypot(double(ins[loc].first - ins[i].first), double(ins[loc].second - ins[i].second));
        if (!visited[i]) pq.push(mp(dist, i));
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        cin >> N >> R;
        ins.clear();
        visited.assign(N, false);
        pq = priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>();

        rep(i, N) {
            int x, y;
            cin >> x >> y;
            ins.push_back(mp(x, y));
        }

        int vertexes = 1;
        double small = 0, large = 0;
        int states = 1;
        process(0);
        while (vertexes < N) {
            pair<double, int> p = pq.top();
            pq.pop();

            if (!visited[p.second]) {
                if (p.first <= R)
                    small += p.first;
                else {
                    large += p.first;
                    states++;
                }
                process(p.second);
                vertexes++;
            }
        }

        cout << states << " " << int(round(small)) << " " << int(round(large)) << endl;
    }

    //////////////end////////////////
    return 0;
}
