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

    int N;
    cin >> N;
    for (int tt = 1; tt <= N; tt++) {
        cout << "Case #" << tt << ":" << endl;

        string input;
        cin >> input;
        int height = 0;
        int maxheight = 0;
        int minheight = 0;

        rep(i, input.sz) {
            if (input[i] == 'R')
                height++;
            else if (input[i] == 'F')
                height--;

            maxheight = max(maxheight, height);
            minheight = min(minheight, height);
        }

        height = -minheight;
        int totalheight = maxheight - minheight + 1;
        vector<string> graph(totalheight);

        rep(i, input.sz) {
            if (input[i] == 'R') {
                for (int j = graph[height].sz; j < i; j++)
                    graph[height].push_back(' ');
                graph[height].push_back('/');
                height++;
            }
            if (input[i] == 'F') {
                for (int j = graph[height-1].sz; j < i; j++)
                    graph[height-1].push_back(' ');
                graph[height-1].push_back('\\');
                height--;
            }
            if (input[i] == 'C') {
                for (int j = graph[height].sz; j < i; j++)
                    graph[height].push_back(' ');
                graph[height].push_back('_');
            }

        }

        // edge case where top line is empty due to RF sequence.
        if (graph[totalheight-1].empty()) totalheight--;

        for (int i = totalheight-1; i >= 0; i--) {
            cout << "| " << graph[i] << endl;
        }
        string lastline(input.sz + 3, '-');
        lastline[0] = '+';
        cout << lastline << endl << endl;
    }

    //////////////end////////////////
    return 0;
}
