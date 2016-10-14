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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ": ";
        int N, D;
        cin >> N >> D;
        vector<pair<int, bool>> rocks(N);
        for (int i = 0; i < rocks.size(); i++) {
            char BS;
            cin >> BS;
            cin.get();
            int M;
            cin >> M;
            if (BS == 'B')
                rocks[i] = mp(M, true);
            else 
                rocks[i] = mp(M, false);
        }

        auto compare = [](pair<int, bool> a, pair<int, bool> b) {return a < b;};
        sort(all(rocks), compare);

        rocks.insert(rocks.begin(), mp(0, false));
        rocks.push_back(mp(D, true));

        int maxdist = 0;
        int rsize = rocks.size();
        for (int i = 0; i < rsize - 1; i++) {
            if (rocks[i+1].second) {
                maxdist = max(maxdist, rocks[i+1].first - rocks[i].first);
            }
            else {
                maxdist = max(maxdist, rocks[i+2].first - rocks[i].first);
            }
        }

        cout << maxdist << endl;

        //////////////end////////////////
    }
    return 0;
}
