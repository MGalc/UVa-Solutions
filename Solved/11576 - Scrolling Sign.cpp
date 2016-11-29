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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        int n, w;
        cin >> n >> w;
        if (w == 0) {
            cout << "0" << endl;
            continue;
        }

        int total = 0;
        string prev;

        cin >> prev;
        total += prev.sz;

        rep2(ksi, 1, w) {
            string in;
            cin >> in;
            vi kmp(n);
            kmp[0] = -1;
            int i = 0, j = -1;
            while (i < n-1) {
                while (j >= 0 && in[i] != in[j]) j = kmp[j];
                i++, j++;
                kmp[i] = j;
            }

            i = 0, j = 0;
            while (i < n) {
                while (j >= 0 && prev[i] != in[j]) j = kmp[j];
                i++, j++;
            }

            total += n - j;

            swap(in, prev);
        }

        cout << total << endl;
    }

    //////////////end////////////////
    return 0;
}
