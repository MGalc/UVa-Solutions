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

int xx[] {-1, 0, 1, 1, 0, -1};
int yy[] {0, -1, -1, 0, 1, 1};
//int xx[] {-1, 0, 1, 1, 0, -1};
//int yy[] {1, 1, 1, -1, -1, -1};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N) {
        if (N == 1) {
            cout << "0 0" << endl;
            continue;
        }

        int Nv = N-1;
        int circle = 0;
        // derived from modified summation formula, N = 3n(n+1) + n + 2, solving for n
        circle = (-2 + sqrt(2 + 3*Nv))/3;
        // set first circle to start at index 1.
        //circle++;
        
        int edgeside = circle+1;

        // get the starting node from N = 3n(n+1) + n + 2
        int curn = 3*circle*(circle+1) + circle + 2;
        int x = 0, y = edgeside;
        rep(i, 6) {
            int e = edgeside;
            
            // account for longer 5th side
            if (i == 4) e += 1;

            // if we're on the node we should finish on, stop
            if (N == curn) {
                break;
            }

            // endn = the node we will end on after this edge traversal
            int endn = curn + e;
            if (endn >= N) { // if the N node we want is on this edge
                int change = N - curn;
                x += xx[i] * change;
                y += yy[i] * change;
                break;
            }
            else { // traverse the whole edge, N is not on this edge.
                x += xx[i] * e;
                y += yy[i] * e;
                curn += e;
            }
        }

        cout << x << " " << y << endl;
    }

    //////////////end////////////////
    return 0;
}
