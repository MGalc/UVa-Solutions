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
int N, M, curnum;
vii adj;
vi dfsnum;
vi dfslow;
stack<int> st;
vii circles;
vi instack;
map<string, int> indexes;
vector<string> names;

void dfs(int u) {
    dfsnum[u] = dfslow[u] = curnum++;
    instack[u] = 1;
    st.push(u);

    rep(i, adj[u].sz) {
        int v = adj[u][i];
        if (dfsnum[v] == -1) {
            dfs(v);
            dfslow[u] = min(dfslow[u], dfslow[v]);
        }
        else if (instack[v])
            dfslow[u] = min(dfslow[u], dfsnum[v]);
    }

    if (dfsnum[u] == dfslow[u]) {
        circles.push_back(vi());
        bool done = false;
        int first = true;
        while (!done) {
            if (!first)
                cout << ", ";
            first = false;

            if (st.top() == u)
                done = true;
            cout << names[st.top()];
            circles[circles.sz-1].push_back(st.top());
            instack[st.top()] = 0;
            st.pop();
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int setnum = 1;
    while (cin >> N >> M, N || M) {
        if (setnum > 1)
            cout << endl;
        while (!st.empty()) st.pop();
        curnum = 0;
        adj.assign(N, vi());
        circles.assign(0, vi());
        dfsnum.assign(N, -1);
        dfslow.assign(N, -1);
        instack.assign(N, -1);
        names.assign(N, "");
        indexes.clear();

        int curindx = 0;
        rep(i, M) {
            string s1, s2;
            cin >> s1 >> s2;
            auto r1 = indexes.find(s1);
            auto r2 = indexes.find(s2);
            int i1, i2;
            if (r1 == indexes.end()) {
                indexes[s1] = curindx;
                names[curindx] = s1;
                i1 = curindx;
                curindx++;
            }
            else i1 = r1->second;
            if (r2 == indexes.end()) {
                indexes[s2] = curindx;
                names[curindx] = s2;
                i2 = curindx;
                curindx++;
            }
            else i2 = r2->second;

            adj[i1].push_back(i2);
        }

        cout << "Calling circles for data set " << setnum++ << ":\n";
        rep(i, N) {
            if (dfsnum[i] == -1)
                dfs(i);
        }

        //rep(i, circles.sz) {
        //string strout = "";
            //rep(j, circles[i].sz) {
                //if (j != 0)
                    //strout += ", ";
                //strout += names[circles[i][j]];
            //}
            //cout << strout << endl;
        //}

    }

    //////////////end////////////////
    return 0;
}
