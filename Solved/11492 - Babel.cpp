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
struct node {
    int val, loc;
    int letter;
    node(int s, int ad, int let) : val(s), loc(ad), letter(let) {}
};

struct compare {
    bool operator() (const node& a, const node& b) {
    return a.val > b.val;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int M;
    while (cin >> M, M) {
        map<string, int> langs;
        string s1, s2, s3;
        cin >> s1 >> s2;
        langs[s1] = 1;
        langs[s2] = 2;
        int indx = 3;
        int start = 0, finish = 1;

        vector<vector<node>> graph(2, vector<node>());

        rep(i, M) {
            cin >> s1 >> s2 >> s3;
            int indx1 = langs[s1], indx2 = langs[s2];
            if (indx1 == 0) {
                graph.push_back(vector<node>());
                indx1 = indx;
                langs[s1] = indx++;
            }
            if (indx2 == 0) {
                graph.push_back(vector<node>());
                indx2 = indx;
                langs[s2] = indx++;
            }

            graph[indx1-1].push_back(node(s3.sz, indx2-1, s3[0]-'a'));
            graph[indx2-1].push_back(node(s3.sz, indx1-1, s3[0]-'a'));
        }

        vii dist(indx-1, vi(26, INF));

        priority_queue<node, vector<node>, compare> q;

        q.push(node(0, start, -1));

        while (!q.empty()) {
            node tn = q.top();
            q.pop();
            
            if (tn.loc == finish) break;
            if (dist[tn.loc][tn.letter] < tn.val) continue;
            
            for (int i = 0; i < graph[tn.loc].sz; i++) {
                node n = graph[tn.loc][i];
                if (n.letter == tn.letter) continue;
                int v = tn.val + n.val;

                if (v < dist[n.loc][n.letter]) {
                    q.push(node(v, n.loc, n.letter));
                    dist[n.loc][n.letter] = v;
                }
            }
        }

        int mini = INF;
        rep(i, 26) {
            mini = min(mini, dist[finish][i]);
        }
        if (mini >= INF) {
            cout << "impossivel" << endl;;
        }
        else cout << mini << endl;
        /*if (dist[finish] == INF) {
            cout << "impossivel" << endl;;
        }
        else cout << dist[finish] << endl;*/
    }

    //////////////end////////////////
    return 0;
}
