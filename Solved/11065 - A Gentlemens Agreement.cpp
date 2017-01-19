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
#define popc(x) __builtin_popcount(x)
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

const double PI = 2 * acos(0);
vector<ll> adj;
int maxSet;
int totSets;
int N;

void solve(int loc, ll used, int taken) {
    if (used == (1LL << N) - 1) {
        totSets++;
        maxSet = max(maxSet, taken);
    }
    else {
        for (int i = loc; i < N; i++) {
            if (!(used & (1LL << i))) // hasn't been used
                solve(i+1, used | adj[i], taken+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    rep(tt, T) {
        int roads;
        cin >> N >> roads;
        adj.assign(N, 0LL);
        rep(i, roads) {
            ll v1, v2;
            cin >> v1 >> v2;
            adj[v1] |= 1LL << v2;
            adj[v2] |= 1LL << v1;
        }
        rep(i, N)
            adj[i] |= 1LL << i;
        maxSet = 0;
        totSets = 0;
        solve(0, 0LL, 0);
        cout << totSets << endl << maxSet << endl;
    }

    //////////////end////////////////
    return 0;
}
