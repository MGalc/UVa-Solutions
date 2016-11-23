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

struct racers {
    public:
        int time;
        string name;
        string lowername;
        racers(int min, int sec, int milli, string n) {
            time = milli;
            time += (sec * 1000);
            time += (min * 100000);
            name = n;
            rep(i, name.sz)
                lowername.push_back(tolower(name[i]));
        }
        bool operator<(const racers& a) const {
            if (time == a.time)
                return lowername < a.lowername;
            else if (time < a.time)
                return true;
            else
                return false;
        }
        bool operator>(const racers& a) {
            return !(*this < a);
        }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N) {
        string name;
        int min, sec, milli;
        string tmp;
        vector<racers> rs;
        rep(i, N) {
            cin >> name >> tmp >> min >> tmp >> sec >> tmp >> milli >> tmp;
            rs.push_back(racers(min, sec, milli, name));
        }

        sort(all(rs));

        rep(i, rs.sz) {
            if (i % 2 == 0)
                cout << "Row " << i / 2 + 1 << endl;
            cout << rs[i].name << endl;
        }

        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
