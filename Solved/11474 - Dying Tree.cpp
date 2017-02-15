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
int M, N, K, D;
int KK, DD;

struct tree {
    bool visited = false;
    int begin, end;
    tree() {}
};

bool inrange(pii& a, pii& b, int range) {
    return ((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second) <= range);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M >> K >> D;
        DD = D*D;
        KK = K*K;

        vpii branches(M);
        vi belongsto(M);
        vector<tree> trees(N+1);
        rep(i, M) {
            cin >> branches[i].first >> branches[i].second;
            belongsto[i] = -1;
        }
        trees[0].begin = 0;
        trees[0].end = M;
        int branchloc = M;

        for (int i = 1; i < trees.sz; i++) {
            int b;
            cin >> b;
            trees[i].begin = branchloc;
            rep(j, b) {
                pii loc;
                cin >> loc.first >> loc.second;
                belongsto.push_back(i);
                branches.push_back(loc);
                branchloc++;
            }
            trees[i].end = branchloc;
        }

        queue<int> q;
        q.push(1);
        trees[1].visited = true;

        bool solved = false;
        while (!q.empty()) {
            int top = q.front();
            q.pop();

            rep(i, trees.sz) {
                if (trees[i].visited) continue;
                bool found = false;
                for (int j = trees[i].begin; j < trees[i].end; j++) {
                    for (int k = trees[top].begin; k < trees[top].end; k++) {
                        if (i == 0) {
                            if (inrange(branches[j], branches[k], DD)) {
                                solved = true;
                                found = true;
                                break;
                            }
                        }
                        else if (inrange(branches[j], branches[k], KK)) {
                            trees[i].visited = true;
                            q.push(i);
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
            }
            if (solved) break;
        }

        if (solved) 
            cout << "Tree can be saved :)" << endl;
        else
            cout << "Tree can't be saved :(" << endl;
    }

    //////////////end////////////////
    return 0;
}
