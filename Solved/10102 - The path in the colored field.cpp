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
    //////////////start//////////////
    ios::sync_with_stdio(false);

    int D;
    while (cin >> D) {
        vpii threes;
        vpii ones;
        cin.ignore(100, '\n');
        rep(y, D) {
            rep(x, D) {
                char in;
                cin >> in;
                if ((int)(in - '0') == 1)
                    ones.push_back(mp(x, y));
                else if ((int)(in - '0') == 3)
                    threes.push_back(mp(x, y));
            }
            cin.ignore(100, '\n');
        }

        int largest = -1;
        for (int o = 0; o < ones.size(); o++) {
            int smallest = INT_MAX;
            for (int t = 0; t < threes.size(); t++) {
                int dist = abs(ones[o].first - threes[t].first) + abs(ones[o].second - threes[t].second);
                smallest = min(smallest, dist);
            }
            largest = max(largest, smallest);
        }

        cout << largest << endl;
    }

    //////////////end////////////////
    return 0;
}
