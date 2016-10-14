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

    unsigned int N, L, U;
    while (cin >> N >> L >> U) {
        unsigned int M = 0;
        bool lowestset = false;
        for (int i = 31; i >= 0; i--) {
            unsigned int nextM = M | (1 << i);
            unsigned int offmask = ((1 << (i))-1) | M;
            //unsigned int onmask = (1 << (i+1))-1;
            //If we don't take the bit and the resulting can be larger than L
            if (offmask >= L) {
                //If the bit in N is set (no point taking it)
                if (N & (1 << i))
                    continue;
                //If we take the bit, will we be above the value of U?
                if (nextM <= U) {
                    M = nextM;
                }
            }
            else {
                //We have no choice but to take it, since if we don't we will be smaller than L.
                M = nextM;
            }
        }

        cout << M << endl;
    }

    //////////////end////////////////
    return 0;
}


//L = 0110010
//U = 0111100
//N = 1100100
//
//a = 0111011
