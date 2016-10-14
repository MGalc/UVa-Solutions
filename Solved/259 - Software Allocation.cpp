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

const int s = 36, t = 37;
vi prevs;
vi p;
vii edges;
vii adj;
int flow;

void augment(int l, int minflow) {
    if (l == s) {
        flow = minflow;
        return;
    }
    else if (prevs[l] != -1) {
        minflow = min(minflow, edges[prevs[l]][l]);
        augment(prevs[l], minflow);

        edges[l][prevs[l]] += flow;
        edges[prevs[l]][l] -= flow;
        if (flow > 0)
            p[l] = prevs[l];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string in;
    while (getline(cin, in)) {

        edges.assign(38, vi(38));
        adj.assign(38, vi());
        int N = 0;
        int totapps = 0;
        do {
            N++;
            ss ins(in);
            string s1, s2;
            ins >> s1 >> s2;
            totapps += s1[1] - '0';
            int app = s1[0]-'A';
            edges[s][app] = int(s1[1]-'0');
            adj[s].push_back(app);
            adj[app].push_back(s);

            for (int i = 0; s2[i] != ';'; i++) {
                int comp = s2[i]-'0'+26;
                edges[app][comp] = INF;
                adj[app].push_back(comp);
                adj[comp].push_back(app);
            }
        } while (getline(cin, in), in != "");

        for (int i = 26; i < 36; i++) {
            edges[i][t] = 1;
            adj[i].push_back(t);
            adj[t].push_back(i);
        }

        p.assign(38, -1);
        int mf = 0;
        while (1) {
            flow = 0;
            prevs.assign(38, -1);
            queue<int> q;
            q.push(s);
            prevs[s] = s;

            bool efound = false;
            while(!q.empty() && !efound) {
                int curr = q.front();
                q.pop();

                for (int i = 0; i < adj[curr].sz; i++) {
                    int v = adj[curr][i];
                    if (prevs[v] == -1 && edges[curr][v] > 0) {
                        q.push(v);
                        prevs[v] = curr;
                        if (v == t) {
                            efound = true;
                            break;
                        }
                    }
                }
            }

            augment(t, INF);
            if (flow == 0) break;

            /*string out;
            for (int i = 0; i < 10; i++) {
                if (p[26+i] == -1) out += "_";
                else out += char(p[26+i] + 'A');
            }
            cout << out << endl;*/

            mf++;
        }

        string out;
        if (mf != totapps) {
            out = "!";
        }
        else {
            for (int i = 0; i < 10; i++) {
                if (p[26+i] == -1) out += "_";
                else out += char(p[26+i] + 'A');
            }
        }

        cout << out << endl;

    }

    //////////////end////////////////
    return 0;
}
