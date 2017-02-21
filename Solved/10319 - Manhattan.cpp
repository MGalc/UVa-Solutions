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
int V;
vii SAT2;

int nextnum;
vi dfslo;
vi dfsnum;
vector<bool> onstack;
stack<int> curscc;
void Tarjans(int loc) {
    dfsnum[loc] = nextnum++;
    dfslo[loc] = dfsnum[loc];
    onstack[loc] = true;
    curscc.push(loc);
    for (int i = 0; i < SAT2[loc].sz; i++) {
        int next = SAT2[loc][i];
        if (dfsnum[next] == -1) {
            Tarjans(next);
            dfslo[loc] = min(dfslo[loc], dfslo[next]);
        }
        else if (onstack[next]) {
            dfslo[loc] = min(dfslo[loc], dfsnum[next]);
        }
    }

    if (dfslo[loc] == dfsnum[loc]) {
        while (curscc.top() != loc) {
            onstack[curscc.top()] = false;
            dfslo[curscc.top()] = dfslo[loc];
            curscc.pop();
        }
        onstack[curscc.top()] = false;
        curscc.pop();
    }
}

void GetSCCs() {
    nextnum = 0;
    dfsnum.assign(V, -1);
    dfslo.assign(V, -1);
    onstack.assign(V, false);
    curscc = stack<int>();

    for (int i = 0; i < V; i++) {
        if (dfsnum[i] == -1) {
            Tarjans(i);
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        int S, A, M;
        cin >> S >> A >> M;
        V = (S+A)*2;
        int negoffset = S+A;
        SAT2.assign(V, vi());

        // One route is: (x1 ^ y2) v (y1 ^ x2)
        // Transforming it to 2-SAT: (x1 v y1) ^ (x1 v x2) ^ (y2 v y1) ^ (y2 ^ x2)
        for (int i = 0; i < M; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--;
            y1 += S;
            y2 += S;
            
            bool right = y2 >= y1;
            bool down = x2 >= x1;

            if (x1 == x2 && y1 == y2)
                continue;
            if (x1 == x2) { // We don't care about including y1 and y2.
                // x1 v x2
                SAT2[!right*negoffset + x1].push_back(right*negoffset + x2);
                SAT2[!right*negoffset + x2].push_back(right*negoffset + x1);
            }
            else if (y1 == y2) { // We don't care about including y1 and y2.
                // y2 v y1
                SAT2[!down*negoffset + y2].push_back(down*negoffset + y1);
                SAT2[!down*negoffset + y1].push_back(down*negoffset + y2);
            }
            else {
                // x1 v y1
                SAT2[!right*negoffset + x1].push_back(down*negoffset + y1);
                SAT2[!down*negoffset + y1].push_back(right*negoffset + x1);
                // x1 v x2
                SAT2[!right*negoffset + x1].push_back(right*negoffset + x2);
                SAT2[!right*negoffset + x2].push_back(right*negoffset + x1);
                // y2 v y1
                SAT2[!down*negoffset + y2].push_back(down*negoffset + y1);
                SAT2[!down*negoffset + y1].push_back(down*negoffset + y2);
                // y2 v x2
                SAT2[!down*negoffset + y2].push_back(right*negoffset + x2);
                SAT2[!right*negoffset + x2].push_back(down*negoffset + y2);
            }
        }

        GetSCCs();

        bool bad = false;
        for (int i = 0; i < S+A; i++) {
            if (dfslo[i] == dfslo[i+negoffset]) {
                bad = true;
                break;
            }
        }

        if (bad) 
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    //////////////end////////////////
    return 0;
}
