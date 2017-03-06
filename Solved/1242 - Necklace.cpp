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
int N, M;

vector<vpii> edgevals;
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
        for (int i = 0; i < edgevals[loc].size(); i++) {
            pii nextedge = edgevals[loc][i];
            if (bfsindx[nextedge.first] == -1 && nextedge.second > 0) {
                bfsindx[nextedge.first] = bfsindx[loc] + 1;
                q.push(nextedge.first);
            }
        }
    }
    return bfsindx[T]; 
}

vector<bool> visited;
int dinicDFS(int loc, int availFlow) {
    if (visited[loc]) 
        return 0;
    visited[loc] = true;

    if (loc == T) {
        return availFlow;
    }

    int thisbfs = bfsindx[loc];
    int flowed = 0;
    for (int i = 0; i < edgevals[loc].size(); i++) {
        int nextedge = edgevals[loc][i].first;
        int nextweight = edgevals[loc][i].second;
        if (bfsindx[nextedge] == thisbfs+1 && nextweight > 0) {
            int thisflow = dinicDFS(nextedge, min(availFlow, nextweight));
            edgevals[loc][i].second -= thisflow;
            bool found = false;
            int best = 0;
            for (int j = 0; j < edgevals[nextedge].size(); j++) {
                if (edgevals[nextedge][j].first == loc) {
                    best = j;
                    if (edgevals[nextedge][j].second == -nextweight) {
                        edgevals[nextedge][i].second += thisflow;
                        found = true;
                        break;
                    }
                }
            }
            if (!found)
                edgevals[nextedge][best].second += thisflow;
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
        visited.assign(edgevals.size(), false);
        flowed += dinicDFS(S, INF);
    }

    // Here flowed variable is the amount which was able to flow to the end
    // Do whatever you want to it.
    return flowed == wantedFlow;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> N >> M, N || M) {
        cout << "Case " << casenum++ << ": ";
        maxsize = N+2;
        wantedFlow = 2;
        edgevals.assign(maxsize, vpii());
        S = N;
        T = N+1;
        rep(i, M) {
            int f, t;
            cin >> f >> t;
            f--; t--;
            edgevals[f].push_back(mp(t, 1));
            edgevals[t].push_back(mp(f, 1));
        }

        int s, t;
        cin >> s >> t;
        s--; t--;
        edgevals[S].push_back(mp(s, 2));
        edgevals[s].push_back(mp(S, 0));
        edgevals[T].push_back(mp(t, 0));
        edgevals[t].push_back(mp(T, 2));

        cout << (dinics() ? "YES" : "NO") << endl;
    }

    //////////////end////////////////
    return 0;
}
