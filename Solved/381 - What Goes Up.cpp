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

    int in;
    vpii nums;
    vpii solved;
    int indx = 0;
    cin >> in;
    solved.push_back(mp(in, indx));
    nums.push_back(mp(in, -1));
    while (cin >> in) {
        indx++;

        auto loc = lower_bound(all(solved), mp(in, 0));
        if (loc == solved.begin()) {
            nums.push_back(mp(in, -1));
            solved[0] = mp(in, indx);
        }
        else if (loc == solved.end()) {
            nums.push_back(mp(in, prev(loc)->second));
            solved.push_back(mp(in, indx));
        }
        else {
            nums.push_back(mp(in, prev(loc)->second));
            *loc = mp(in, indx);
        }
    }

    //string out = solved.size() + "\n-\n";
    string out;
    int prev = solved[solved.size()-1].second;
    while (prev != -1) {
        out.insert(0, to_string(nums[prev].first) + "\n");
        prev = nums[prev].second;
    }

    out.insert(0, to_string(solved.size()) + "\n-\n");

    cout << out;

    //////////////end////////////////
    return 0;
}
