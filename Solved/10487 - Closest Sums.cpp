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
    int N;
    int count = 1;
    while (cin >> N, N != 0) {
        cout << "Case " << count++ << ":\n";
        vi nums;
        rep(i, N) {
            int in;
            cin >> in;
            nums.insert(upper_bound(all(nums), in), in);
        }

        cin >> N;
        rep(i, N) {
            int in;
            cin >> in;
            int mn = nums[0] + nums[1];
            rep(ii, nums.size()-1) {
                int ch = nums[ii] + nums[ii+1];
                if (abs(in - mn) > abs(in - ch))
                    mn = ch;
                if (ch > in)
                    break;
                rep2(iii, ii+1, nums.size()) {
                    ch = nums[ii] + nums[iii];
                    if (abs(in - mn) > abs(in - ch))
                        mn = ch;
                    if (ch > in)
                        break;
                }
            }
            cout << "Closest sum to " << in << " is " << mn << "." << endl;

        }
    }


    //////////////end////////////////
    return 0;
}
