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
static const vi dx { -1, 0, 1 };
static const vi dy { 0, 1, 0 };
vector<string> input;
int totnodes;
int offset;
vi nodevals;
int S, T;

struct edge {
    int to, cost, flow;
    edge() { to = cost = flow = 0; }
    edge(int t, int c, int f) : to(t), cost(c), flow(f) {}
};
vector<vector<edge>> edges;

void printpath(vi& prevs) {
    int curloc = T;
    stack<int> st;

    while (prevs[curloc] != curloc) {
        st.push(curloc);
        curloc = prevs[curloc];
    }
    st.push(S);

    bool first = true;
    while (!st.empty()) {
        if (first) first = false;
        else cout << " -> ";
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int getflow() {
    vi visited(totnodes, INF);
    vi prev(totnodes, -1);
    prev[S] = S;
    visited[S] = 0;
    priority_queue<pii, vpii, greater<pii>> q;
    q.push(mp(0, S));

    while (!q.empty()) {
        pii top = q.top();
        q.pop();
        if (visited[top.second] < top.first)
            continue;
        if (top.second == T)
            break;

        for (int i = 0; i < edges[top.second].sz; i++) {
            if (edges[top.second][i].flow <= 0)
                continue;

            edge next = edges[top.second][i];
            if (visited[top.second] + next.cost >= visited[next.to])
                continue;

            //cout << top.second << " -> " << next.to << "    with cost: " << visited[top.second] + next.cost << endl;
            q.push(mp(visited[top.second] + next.cost, next.to));
            visited[next.to] = visited[top.second] + next.cost;
            prev[next.to] = top.second;
        }
    }

    if (prev[T] == -1)
        return -1;

    int forloc = T;
    while (forloc != prev[forloc]) {
        for (int i = 0; i < edges[forloc].sz; i++) {
            if (edges[forloc][i].to == prev[forloc]) {
                edges[forloc][i].flow += 1;
            }
        }
        for (int i = 0; i < edges[prev[forloc]].sz; i++) {
            if (edges[prev[forloc]][i].to == forloc) {
                edges[prev[forloc]][i].flow -= 1;
            }
        }
        forloc = prev[forloc];
    }

    return visited[T];
}

int MFMC() {
    int flow = 0, total = 0;
    do {
        total += flow;
        flow = getflow();
    } while (flow != -1);

    return total;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N) {
        input.assign(5, "");
        rep(i, 5)
            cin >> input[i];

        totnodes = (10 * N) + 2;
        S = totnodes - 2;
        T = totnodes - 1;
        offset = 5*N;
        edges.assign(totnodes, vector<edge>());
        nodevals.assign(totnodes, 0);

        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < N; c++) {
                int enter = r*N + c;
                int exit = r*N + c + offset;
                int value = 0;
                if (input[enter/N][enter%N] > '0' && input[enter/N][enter%N] <= '9')
                    value = input[enter/N][enter%N] - '0';
                edges[enter].push_back(edge(exit, value, 1));
                edges[exit].push_back(edge(enter, -value, 0));

                if (c == N-1) continue;
                for (int i = 0; i < dx.sz; i++) {
                    if (dx[i] + r < 0 || dx[i] + r >= 5) continue;
                    if (dy[i] + c < 0 || dy[i] + c >= N) continue;
                    int next = enter + (dx[i] * N) + dy[i];
                    //if (next < 0 || next >= S) 
                        //continue;
                    edges[exit].push_back(edge(next, 0, 1));
                    edges[next].push_back(edge(exit, 0, 0));
                }
            }
        }

        rep(i, 5) {
            edges[N*(i+1) - 1 + offset].push_back(edge(T, 0, 1));
            if (input[i][0] == '@') {
                edges[S].push_back(edge(N*i, 0, 1));
            }
        }

        cout << MFMC() << endl;
    }

    //////////////end////////////////
    return 0;
}
