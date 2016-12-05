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
#define Idot(a,b) ((conj(a)*(b)).X)
#define IX real()
#define IY imag()
#define popc(x) __builtin_popcount(x)
#define INF 1e9
#define MOD 1000007

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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case " << tt << ": ";
        int N, P, Q;
        cin >> N >> P >> Q;

        vi visited(N*N+1, -1);
        for (int i = 0; i <= P; i++) {
            int in;
            cin >> in;
            visited[in] = i+1;
        }

        vi seq;
        for (int i = 0; i <= Q; i++) {
            int in;
            cin >> in;
            if (visited[in] != -1)
                seq.push_back(visited[in]);
        }
        
        // Longest increasing subsequence
        vi lis;
        rep(i, seq.sz) {
            vi::iterator it = lower_bound(all(lis), seq[i]);
            if (it == lis.end())
                lis.push_back(seq[i]);
            else
                *it = seq[i];
        }

        cout << lis.sz << endl;
    }

    //////////////end////////////////
    return 0;
}
