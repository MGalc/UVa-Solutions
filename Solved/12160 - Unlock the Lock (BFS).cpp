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
#define INF 1e9

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
int L, U, R;
vi nums;
int dist[10000];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> L >> U >> R, L || U || R) {
        cout << "Case " << casenum++ << ": ";

        nums.resize(R);
        memset(dist, -1, sizeof dist);
        queue<int> q;
        rep(i, R) {
            cin >> nums[i];
        }
        q.push(L);
        dist[L] = 0;

        bool done = false;
        int totdist = -1;
        while (!done && !q.empty()) {
            int top = q.front();
            q.pop();
            rep(i, R) {
                int next = (top + nums[i]) % 10000;
                if (next == U) {
                    totdist = dist[top] + 1;
                    done = true;
                    break;
                }
                if (dist[next] == -1) {
                    q.push(next);
                    dist[next] = dist[top] + 1;
                }
            }
        }

        if (totdist == -1)
            cout << "Permanently Locked" << endl;
        else 
            cout << totdist << endl;
    }

    //////////////end////////////////
    return 0;
}
