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

int inc[2500];
int de[2500];
int in[2500];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        rep(i, N) {
            cin >> in[i];
        }

        for (int i = N-1; i >= 0; i--) {
            inc[i] = 1;
            de[i] = 1;
            for (int j = i+1; j < N; j++) { 
                if (in[j] < in[i]) {
                    inc[i] = max(inc[i], inc[j]+1);
                }

                if (in[j] > in[i]) {
                    de[i] = max(de[i], de[j]+1);
                }
            }
        }

        int largest = 0;
        rep(i, N) {
            largest = max(largest, de[i] + inc[i] - 1);
        }

        cout << largest << endl;
    }


    //////////////end////////////////
    return 0;
}
