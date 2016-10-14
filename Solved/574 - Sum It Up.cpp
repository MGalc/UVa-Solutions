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
set<vi, greater<vi>> adds;
int T, N;
int sum[20];

inline void bt(int loc, int total, int vloc) {
    if (loc == N)
        return;

    for (int i = loc; i < N; i++) {
        sum[vloc] = nums[i];
        int ltotal = total + nums[i];
        if (ltotal > T)
            continue;
        else if (ltotal == T) {
            vi tmp;
            rep(i, vloc+1) {
                tmp.push_back(sum[i]);
            }
            adds.insert(tmp);
            continue;
        }

        bt(i+1, ltotal, vloc+1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> T >> N, N != 0) {
        adds.clear();
        rep(i, N) {
            cin >> nums[i];
        }
        sort(nums, nums+N, greater<int>());

        bt(0, 0, 0);

        cout << "Sums of " << T << ":" << endl;
        if (adds.empty())
            cout << "NONE" << endl;
        else {
            for(auto i = adds.begin(); i != adds.end(); i++) {
                rep(j, i->size()) {
                    cout << (*i)[j];
                    if (j != i->size()-1)
                        cout << "+";
                }
                cout << endl;
            }
        }
    }

    //////////////end////////////////
    return 0;
}
