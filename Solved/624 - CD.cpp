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

int N;
int tracks[30];
int t;
int maxi = 0;
vi adds;
void find(int loc, int tot) {
    while (loc < t && maxi != N) {
        int thisval = tot+tracks[loc];
        if (thisval > N)
            return;
        if (thisval > maxi) {
            maxi = thisval;
            adds.clear();
            adds.push_back(tracks[loc]);
        }
        int prevmax = maxi;
        find(loc+1, thisval);
        if (prevmax != maxi) {
            adds.push_back(tracks[loc]);
        }
        loc++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    //////////////start//////////////

    while (cin >> N) {
        maxi = 0;
        adds.clear();
        cin >> t;
        rep(i, t) {
            cin >> tracks[i];
        }
        sort(tracks, tracks+t);

        find(0, 0);

        rep(i, adds.sz) {
            cout << adds[i] << " ";
        }
        cout << "sum:" << maxi << endl;
    }

    //////////////end////////////////
    return 0;
}
