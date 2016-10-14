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
    while (cin >> N, N) {
        vii young(26, vi(26));
        vii mature(26, vi(26));

        rep(i, 26) {
            rep(j, 26) {
                if (i == j) {
                    young[i][j] = 0;
                    mature[i][j] = 0;
                }
                else {
                    young[i][j] = INF;
                    mature[i][j] = INF;
                }
            }
        }

        rep(i, N) {
            char m, d, s, t;
            int val;
            cin >> m >> d >> s >> t >> val;
            int ss = s - 'A', tt = t - 'A';
            if (m == 'Y') {
                young[ss][tt] = min(val, young[ss][tt]);
                if (d == 'B') 
                    young[tt][ss] = min(val, young[tt][ss]);
            }
            if (m == 'M') {
                mature[ss][tt] = min(val, mature[ss][tt]);
                if (d == 'B') 
                    mature[tt][ss] = min(val, mature[tt][ss]);
            }
        }

        char y, m;
        cin >> y >> m;
        y -= 'A', m -= 'A';

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    young[i][j] = min(young[i][j], young[i][k] + young[k][j]);
                    mature[i][j] = min(mature[i][j], mature[i][k] + mature[k][j]);
                }
            }
        }

        int minval = INF;
        
        for (int i = 0; i < 26; i++) {
            if (minval > young[y][i] + mature[m][i]) {
                minval = young[y][i] + mature[m][i];
            }
        }

        if (minval >= INF)
            cout << "You will never meet." << endl;
        else {
            cout << minval;

            rep(i, 26) {
                if (young[y][i] + mature[m][i] == minval)
                    cout << " " << (char)(i+'A');
            }
            cout << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
