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
#define popc32(x) __builtin_popcount(x)
#define popc64(x) __builtin_popcountll(x)
#define MOD 1000007
#define INF 1e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);

vii flowvals; // Stores the current values of flows
vii edges; // Stores the edges
int S;
int T;
int wantedFlow; // Optional value if we are making sure our flow is atleast this number
vi bfsindx;
int maxsize;

int dinicBFS() {
    bfsindx.assign(maxsize, -1);
    queue<int> q;
    q.push(S);
    bfsindx[S] = 0;
    while (!q.empty()) {
        int loc = q.front();
        q.pop();
        for (int i = 0; i < edges[loc].size(); i++) {
            if (bfsindx[edges[loc][i]] == -1 && flowvals[loc][edges[loc][i]] > 0) {
                bfsindx[edges[loc][i]] = bfsindx[loc] + 1;
                q.push(edges[loc][i]);
            }
        }
    }
    return bfsindx[T]; 
}

vector<bool> visited;
int dinicDFS(int loc, int availFlow) {
    if (visited[loc]) return 0;
    visited[loc] = true;
    if (loc == T) {
        return availFlow;
    }

    int thisbfs = bfsindx[loc];
    int flowed = 0;
    for (int i = 0; i < edges[loc].size(); i++) {
        if (bfsindx[edges[loc][i]] == thisbfs+1 && flowvals[loc][edges[loc][i]] > 0) {
            int thisflow = dinicDFS(edges[loc][i], min(availFlow, flowvals[loc][edges[loc][i]]));
            flowvals[loc][edges[loc][i]] -= thisflow;
            flowvals[edges[loc][i]][loc] += thisflow;
            flowed += thisflow;
            availFlow -= thisflow;
            if (availFlow <= 0) // We have run out of flow. Go back.
                break;
        }
    }

    return flowed;
}

bool dinics() {
    int flowed = 0;
    while (dinicBFS() > 0) {
        visited.assign(maxsize, false);
        flowed += dinicDFS(S, INF);
    }

    // Here flowed variable is the amount which was able to flow to the end
    // Do whatever you want to it.
    return flowed == wantedFlow;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int t;
    cin >> t;
    while (t--) {
        int st, av, banks;
        cin >> st >> av >> banks;
        maxsize = 2*st*av + 2;
        S = maxsize-2;
        T = maxsize-1;
        flowvals.assign(maxsize, vi(maxsize, 0));
        edges.assign(maxsize, vi());
        wantedFlow = banks;

        int offset = st*av;
        static const int xx[] { -1, 0, 1, 0 };
        static const int yy[] { 0, 1, 0, -1 };
        rep(i, st) {
            rep(j, av) {
                flowvals[i*av + j][offset + (i*av + j)] = 1;
                edges[i*av + j].push_back(offset + (i*av + j));
                edges[offset + (i*av + j)].push_back(i*av + j);
                rep(k, 4) {
                    int nexti = i + xx[k];
                    int nextj = j + yy[k];
                    if (nexti < 0 || nextj < 0 || nexti >= st || nextj >= av)
                        continue;
                    flowvals[offset + (i*av + j)][nexti*av + nextj] = 1;
                    edges[offset + (i*av + j)].push_back(nexti*av + nextj);
                    edges[nexti*av + nextj].push_back(offset + (i*av + j));
                }
            }
        }

        rep(i, av) {
            flowvals[offset + i][T] = 1;
            edges[offset + i].push_back(T);
            edges[T].push_back(offset + i);
            flowvals[offset + i + (av*(st-1))][T] = 1;
            edges[offset + i + (av*(st-1))].push_back(T);
            edges[T].push_back(offset + i + (av*(st-1)));
        }
        for (int j = 1; j < st-1; j++) {
            flowvals[offset + (j*av)][T] = 1;
            edges[offset + (j*av)].push_back(T);
            edges[T].push_back(offset + (j*av));

            flowvals[offset + (j*av) + (av-1)][T] = 1;
            edges[offset + (j*av) + (av-1)].push_back(T);
            edges[T].push_back(offset + (j*av) + (av-1));
        }

        rep(i, banks) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            flowvals[S][x*av + y] = 1;
            edges[S].push_back(x*av + y);
            edges[x*av + y].push_back(S);
        }

        cout << (dinics() ? "possible" : "not possible") << endl;
    }

    //////////////end////////////////
    return 0;
}
