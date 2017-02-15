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
#define EPS 1e-6

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
int L, W, N;
vpii obs;
vii edges;

double dist(pii a, pii b) {
    return hypot(a.first - b.first, a.second - b.second);
}

bool canSolve(double d) {
    edges.assign(N+2, vi());
    int botedge = N;
    int topedge = N+1;

    for (int i = 0; i < obs.sz; i++) {
        for (int j = i+1; j < obs.sz; j++) {
            if (dist(obs[i], obs[j]) < d) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
        if (obs[i].second < d) {
            edges[i].push_back(botedge);
            edges[botedge].push_back(i);
        }
        if (W - obs[i].second < d) {
            edges[i].push_back(topedge);
            edges[topedge].push_back(i);
        }
    }

    queue<int> q;
    q.push(botedge);
    vector<bool> visited(N+2, false);
    visited[botedge] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = 0; i < edges[top].sz; i++) {
            int next = edges[top][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                if (next == topedge)
                    break;
            }
        }
        if (visited[topedge])
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cin >> L >> W;
        cin >> N;
        obs.assign(N, pii(0,0));
        rep(i, N)
            cin >> obs[i].first >> obs[i].second;

        double lo = 0.0, hi = W;
        while (hi - lo > EPS) {
            double mid = (lo+hi)/2.0;
            if (canSolve(mid))
                lo = mid;
            else
                hi = mid;
        }

        cout << "Maximum size in test case " << tt << " is ";
        cout << setprecision(4) << fixed << lo << "." << endl;
    }

    //////////////end////////////////
    return 0;
}
