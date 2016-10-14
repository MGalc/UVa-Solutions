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
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define popc(x) __builtin_popcount(x)

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
vi email;
vi seen;
vi visited;
vi deep;

int f(int loc, int depth) {
    if (email[loc] == -1 || email[loc] == loc)
        return -1;

    deep[loc] = depth;

    visited[loc] = 1;
    int retval = -1;
    int next = email[loc];
    if (visited[next] == 1) {
        seen[loc] = 1 + depth - deep[next];
        retval = next;
    }
    else if (visited[next] == 2) {
        seen[loc] = seen[next] + 1;
        retval = -1;
    }
    else {
        int ret = f(next, depth+1);
        if (ret != -1) {
            seen[loc] = seen[next];
            if (ret == loc) {
                retval = -1;
            }
            else retval = ret;
        }
        else {
            seen[loc] = seen[next] + 1;
            retval = -1;
        }
    }
    visited[loc] = 2;
    return retval;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case " << tt << ": ";
        int N;
        cin >> N;
        email.assign(N, -1);
        seen.assign(N, -1);
        visited.assign(N, -1);
        deep.assign(N, -1);
        rep(i, N) {
            int x, y;
            cin >> x >> y;
            email[x-1] = y-1;
        }

        int mx = -1;
        int indx = -1;
        rep(i, N) {
            if (visited[i] == -1) {
                f(i, 1);
                if (seen[i] > mx) {
                    mx = seen[i];
                    indx = i;
                }
            }
        }

        cout << indx+1 << endl;
    }

    //////////////end////////////////
    return 0;
}
