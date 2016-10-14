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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;

    int casenum = 1;
    while (cin >> N, N) {
        map<string, int> stoi;
        map<int, string> itos;
        int indx = 0;
        vii edges;
        rep(i, N) {
            int n;
            cin >> n;
            edges.push_back(vi());
            rep(i, n) {
                string in;
                cin >> in;
                int thisindx = stoi[in];
                if (thisindx == 0) {
                    indx++;
                    stoi[in] = indx;
                    itos[indx] = in;
                    thisindx = indx;
                }
                edges[edges.sz-1].push_back(thisindx);
            }
        }

        vii adj(indx, vi(indx, 0));

        rep(i, edges.sz) {
            int prev = -1;
            rep(j, edges[i].sz) {
                if (prev != -1)
                    adj[prev][edges[i][j]-1] = 1;

                prev = edges[i][j]-1;
            }
        }

        cin >> N;
        rep(i, N) {
            string s1, s2;
            cin >> s1 >> s2;
            int i1 = stoi[s1]-1;
            int i2 = stoi[s2]-1;
            adj[i1][i2] = 1;
        }

        for (int k = 0; k < indx; k++) {
            for (int i = 0; i < indx; i++) {
                for (int j = 0; j < indx; j++) {
                    adj[i][j] |= adj[i][k] & adj[k][j];
                }
            }
        }

        int size = 0;
        string out;
        for (int i = 0; i < indx; i++) {
            for (int j = i+1; j < indx; j++) {
                //if (i == j) continue;

                if (adj[i][j] == 0 && adj[j][i] == 0) {
                    if (size < 2) {
                        out += "(" + itos[i+1] + "," + itos[j+1] + ") ";
                    }
                    size++;
                }
            }
        }

        cout << "Case " << casenum++ << ", ";
        if (size == 0) {
            cout << "no concurrent events." << endl;
        }
        else {
            cout << size << " concurrent events:" << endl;
            cout << out << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
