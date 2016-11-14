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
vector<int> fibos {1};
map<int, int> fibindx;

void build() {
    fibindx[0] = 1;
    unsigned int nextv = 1;
    int indx = 1;
    while (nextv < (unsigned int)numeric_limits<int>::max()) {
        fibos.push_back(nextv);
        fibindx[nextv] = indx;
        indx++;
        nextv = (unsigned int)fibos[indx-1] + (unsigned int)fibos[indx-2];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    build();

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vi nums(N);
        rep(i, N) cin >> nums[i];
        string in;
        getline(cin, in);
        getline(cin, in);

        string informat;
        rep(i, in.sz)
            if (in[i] >= 'A' && in[i] <= 'Z') informat.push_back(in[i]);

        string out(105, ' ');

        rep(i, nums.sz) {
            out[fibindx[nums[i]]-1] = informat[i];
        }

        while (out[out.sz-1] == ' ') out.pop_back();
        cout << out << endl;
    }

    //////////////end////////////////
    return 0;
}
