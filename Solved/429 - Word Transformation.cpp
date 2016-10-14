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
vector<string> inputs;
vii graph;
queue<int> bfsstack;
vector<int> visited;

int bfs(int b) {
   while (!bfsstack.empty()) {
        int a = bfsstack.front();
        bfsstack.pop();
        rep(i, graph[a].sz) {
            if (!visited[graph[a][i]]) {
                bfsstack.push(graph[a][i]);
                visited[graph[a][i]] = visited[a] + 1;
            }

            if (graph[a][i] == b)
                return visited[graph[a][i]];
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        if (tt != 0)
            cout << endl;
        inputs.clear();

        map<string, int> strmap;

        string in;
        int count = 0;
        while (cin >> in, in != "*") {
            inputs.push_back(in);
            strmap[in] = count;
            count++;
        }

        graph.assign(inputs.sz, vi());
        rep(i, inputs.sz) {
            for (int j = i+1; j < inputs.sz; j++) {
                if (inputs[i].sz == inputs[j].sz) {
                    int difs = 0;
                    rep(k, inputs[i].sz) {
                        if (inputs[i][k] != inputs[j][k])
                            difs++;
                    }
                    if (difs == 1) {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }
        }

        getline(cin, in);
        while (getline(cin, in), !in.empty()) {
            visited.assign(count, 0);
            while (!bfsstack.empty()) bfsstack.pop();
            ss strs(in);
            string a, b;
            strs >> a >> b;
            int result = 0;
            if (a != b) {
                bfsstack.push(strmap[a]);
                result = bfs(strmap[b]);
            }
            cout << a << " " << b << " " << result << endl;
        }

    }

    //////////////end////////////////
    return 0;
}
