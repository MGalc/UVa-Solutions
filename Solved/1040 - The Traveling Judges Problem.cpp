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
int NC, DC, NR, NJ;
vector<vpii> edges;
vi judges;
int bestv, bestmask;

bool piicmp(const pii a, const pii b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int MSTCost(int required) {
    int visited = 1 << DC;

    priority_queue<pii, vpii, std::function<bool(pii, pii)>> pq(piicmp);

    rep(i, edges[DC].sz) {
        if (required & (1 << (edges[DC][i].first)))
            pq.push(edges[DC][i]);
    }

    int cost = 0;
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        if (visited & (1 << top.first)) continue;

        cost += top.second;
        if (cost > bestv)
            return INF;
        visited |= (1 << top.first);
        if (visited == required) break;

        rep(i, edges[top.first].sz) {
            int next = edges[top.first][i].first;
            if (required & (1 << (next)) && !(visited & (1 << next)))
                pq.push(edges[top.first][i]);
        }
    }

    if (visited != required) return INF;
    return cost;
}

void solve(int loc, int required) {
    if (loc == NC) {
        int val = MSTCost(required);
        if (val < bestv) {
            bestv = val;
            bestmask = required;
        }
        else if (val == bestv) {
            if (popc32(bestmask) > popc32(required)) {
                bestv = val;
                bestmask = required;
            }
        }
    }
    else if (required & (1 << loc)) {
        (solve(loc + 1, required));
    }
    else {
        solve(loc + 1, required);
        solve(loc + 1, required | (1 << loc));
    }
}

struct edgePrev {
    int cost;
    int loc;
    int prev;
    edgePrev() {}
    edgePrev(int c, int l, int p) : cost(c), loc(l), prev(p) {}
    edgePrev(pii edge, int p) {
        cost = edge.second;
        loc = edge.first;
        prev = p;
    }
    bool operator>(const edgePrev b) const {
        if (this->cost == b.cost) {
            if (this->prev == b.prev)
                return this->loc > b.loc;
            else
                return this->prev > b.prev;
        }
        return this->cost > b.cost;
    }
};

vi getPrevs(int required) {
    int visited = 1 << DC;

    priority_queue<edgePrev, vector<edgePrev>, greater<edgePrev>> pq;
    vi next(NC, -1);
    next[DC] = -1;

    rep(i, edges[DC].sz) {
        if (required & (1 << (edges[DC][i].first)))
            pq.push(edgePrev(edges[DC][i], DC));
    }

    while (!pq.empty()) {
        edgePrev top = pq.top();
        pq.pop();
        if (visited & (1 << top.loc)) continue;

        next[top.loc] = top.prev;
        visited |= (1 << top.loc);

        rep(i, edges[top.loc].sz) {
            int loc = edges[top.loc][i].first;
            if (required & (1 << (loc)) && !(visited & (1 << loc))) {
                pq.push(edgePrev(edges[top.loc][i], top.loc));
            }
        }
    }

    return next;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int tt = 1;
    while (cin >> NC, NC != -1) {
        cin >> DC >> NR;
        DC--;
        edges.assign(NC, vpii());
        rep(i, NR) {
            int loc2;
            int loc1;
            int dist;
            cin >> loc1 >> loc2 >> dist;
            edges[loc1-1].push_back(mp(loc2-1, dist));
            edges[loc2-1].push_back(mp(loc1-1, dist));
        }

        rep(i, NC)
            sort(all(edges[i])); // Make edges in lexographic order.

        int required = 1 << DC;

        cin >> NJ;
        judges.assign(NJ, 0);

        rep(i, NJ) {
            int in;
            cin >> in;
            in--;
            judges[i] = in;
            required |= (1 << in);
        }

        bestv = INF;
        bestmask = ~0;
        solve(0, required);

        cout << "Case " << tt << ": distance = " << bestv << endl;

        vi prev = getPrevs(bestmask);
        rep(i, NJ) {
            cout << "   ";
            int loc = judges[i];
            do {
                if (loc != judges[i]) cout << '-';
                cout << loc+1;
                loc = prev[loc];
            } while (loc != -1);
            cout << endl;
        }
        cout << endl;

        tt++;
    }

    //////////////end////////////////
    return 0;
}
