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
static const int maxN = 368;
static const int maxD = 800;
int fac[maxN][maxD] {};

void calc() {
    memset(fac, 0, sizeof fac);

    fac[1][0] = 1;
    for (int i = 1; i < maxN-1; i++) {
        for (int j = 0; j < maxD-1; j++) {
            fac[i][j+1] += fac[i][j] / 10;
            fac[i][j] %= 10;
            fac[i+1][j] = fac[i][j] * (i+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    calc();
    int N;
    while (cin >> N, N) {
        vi nums(10);
        int zeros = 0;
        for (int i = 0; i < maxD; i++) {
            if (fac[N][i] == 0)
                zeros++;
            else {
                nums[fac[N][i]]++;
                nums[0] += zeros;
                zeros = 0;
            }
        }

        cout << N << "! --" << endl;
        for (int i = 0; i <= 4; i++) {
            if (!i) cout << "   ";
            else cout << "    ";
            cout << "(" << i << ")";

            cout << setw(5) << nums[i];
        }
        cout << endl;
        for (int i = 5; i <= 9; i++) {
            if (i==5) cout << "   ";
            else cout << "    ";
            cout << "(" << i << ")";

            cout << setw(5) << nums[i];
        }
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
