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

int nums[20];

bool isprime(int in) {
    if (in%2 == 0)
        return true;
    for (int i = 3; i < in; i+=2) {
        if (in % i == 0)
            return true;
    }
    return false;
}

void bt(int maxv, int loc) {
    if (loc == maxv) {
        if (!isprime(1 + nums[maxv-1])) {
            bool begin = true;
            rep(i, maxv) {
                if (begin)
                    begin = false;
                else cout << " ";
                cout << nums[i];
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i <= maxv; i++) {
        if (find(nums, nums+loc, i) != nums+loc)
            continue;

        if (!isprime(i + nums[loc-1])) {
            nums[loc] = i;
            bt(maxv, loc+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int in;
    int cas = 1;
    nums[0] = 1;
    while (cin >> in) {
        if (cas != 1)
            cout << endl;
        cout << "Case " << cas++ << ":\n";
        bt(in, 1);
    }
    cout.flush();

    //////////////end////////////////
    return 0;
}
