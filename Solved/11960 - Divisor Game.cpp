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
#define popc32(x) __builtin_popcount(x)
#define popc64(x) __builtin_popcountll(x)
#define MOD 1000007
#define INF 1e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);
static const int MAXN = 10000000;
vi answer;

void build() {
    vi divs(MAXN+1, true);
    answer.assign(MAXN+1, 1);
    for (int i = 2; i <= MAXN/2; i++) {
        for (int j = i+i; j <= MAXN; j+=i) {
            divs[j]++;
        }
    }

    int largestdiv = 1;
    int divmax = 1;

    for (int i = 2; i <= MAXN; i++) {
        if (divs[i] > divmax) {
            divmax = divs[i];
            largestdiv = i;
        }
        else if (divs[i] == divmax)
            largestdiv = i;
        answer[i] = largestdiv;
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
        cout << answer[N] << endl;
    }

    //////////////end////////////////
    return 0;
}
