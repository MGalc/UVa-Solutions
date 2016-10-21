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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N, K;
    while (cin >> N >> K, N != -1 && K != -1) {
        N++;
        vi polys(N);
        rep(i, N)
            cin >> polys[N-1-i];
        for (int t = 0; t < N-K; t++) {
            if (!polys[t]) continue;
            polys[t+K] -= polys[t];
            polys[t] = 0;
        }

        bool taken = false;
        int end = 0;
        while (polys[end] == 0 && end < N) end++;
        if (end >= N) cout << "0";
        else for (int i = N-1; i >= end; i--) {
            if (i != N-1) cout << " ";
            cout << polys[i];
        }


        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
