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

vii grid;
vii gcost;
vii edges;
int T;
int S;
int totalPeople;
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
        rep(i, edges[loc].sz) {
            if (bfsindx[edges[loc][i]] == -1 && grid[loc][edges[loc][i]] > 0) {
                bfsindx[edges[loc][i]] = bfsindx[loc] + 1;
                q.push(edges[loc][i]);
            }
        }
    }
    return bfsindx[T];
}

int dinicDFS(int loc, int availFlow) {
    if (loc == T) {
        return availFlow;
    }

    int thisbfs = bfsindx[loc];
    int flowed = 0;
    for (int i = 0; i < edges[loc].sz; i++) {
        if (bfsindx[edges[loc][i]] == thisbfs+1 && grid[loc][edges[loc][i]] > 0) {
            int flow = dinicDFS(edges[loc][i], min(availFlow, grid[loc][edges[loc][i]]));
            grid[loc][edges[loc][i]] -= flow;
            grid[edges[loc][i]][loc] += flow;
            flowed += flow;
            availFlow -= flow;
            if (availFlow <= 0)
                break;
        }
    }

    return flowed;
}

bool dinics() {
    int totalArrived = 0;
    while (dinicBFS() > 0) {
        totalArrived += dinicDFS(S, INF);
    }

    return totalArrived == totalPeople;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int TC;
    cin >> TC;
    for (int tt = 1; tt <= TC; tt++) {
        cout << "Case #" << tt << ": ";
        
        int cities, days, flights;
        cin >> cities >> days >> flights;
        maxsize = cities*(days+1) + 1;
        int targetCity = cities-1;
        T = maxsize-2; 
        vii initgrid(maxsize, vi(maxsize, 0));
        vii locedges(maxsize, vi());
        vi costs;
        gcost.assign(maxsize, vi(maxsize, 0));

        for (int i = 0; i < maxsize - cities - 1; i++) {
            initgrid[i][i+cities] = INF; // Stay in same city
            locedges[i].push_back(i+cities);
            locedges[i+cities].push_back(i);
        }

        int edgesToEnd = 0;
        rep(i, flights) {
            int U, V, C, P, E;
            cin >> U >> V >> C >> P >> E;
            if (U == V) continue;
            costs.push_back(P);
            U--; 
            V--;
            if (V == targetCity)
                edgesToEnd += C;
            initgrid[(E*cities) + U][((E+1)*cities) + V] = C; // Move to next city
            gcost[E*cities + U][(E+1)*cities + V] = P; // Travel to the city
            gcost[(E+1)*cities + V][E*cities + U] = P; // Travel to the city (backwards)
            locedges[E*cities + U].push_back((E+1)*cities + V);
            locedges[(E+1)*cities + V].push_back(E*cities + U);
        }

        S = maxsize-1;
        totalPeople = 0;
        int pplNotAtEnd = 0;
        for (int i = 0; i < cities; i++) {
            int ppl;
            cin >> ppl;
            totalPeople += ppl;
            locedges[S].push_back(i);
            locedges[i].push_back(S);
            initgrid[S][i] = ppl;
            if (i != cities - 1) {
                pplNotAtEnd += ppl;
            }
        }

        if (pplNotAtEnd > edgesToEnd) {
            cout << "Impossible" << endl;
            continue;
        }
        if (pplNotAtEnd == 0) {
            cout << "0" << endl;
            continue;
        }

        costs.push_back(INF); // For an impossible check
        sort(all(costs));
        int hi = costs.sz-1, lo = 0;
        while (hi > lo) {
            grid = initgrid;
            int mid = (hi+lo) / 2;
            edges.assign(maxsize, vi());
            for (int i = 0; i < locedges.sz; i++) {
                for (int j = 0; j < locedges[i].sz; j++) {
                    if (gcost[i][locedges[i][j]] <= costs[mid])
                        edges[i].push_back(locedges[i][j]);
                }
            }

            if (dinics()) // We were able to get all passengers to arrive
                hi = (hi+lo)/2; // Lower the price we spend
            else
                lo = (hi+lo)/2 + 1;
        }

        if (costs[lo] == INF)
            cout << "Impossible" << endl;
        else
            cout << costs[lo] << endl;
    }

    //////////////end////////////////
    return 0;
}
