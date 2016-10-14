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

inline int func(int in) {
    int c = 1;
    while (in != 1) {
        if (in % 2 == 1) {
            in = (in*3)+1;
        }
        else in /= 2;

        c++;
    }

    return c;
}

int main() {
    //////////////start//////////////

    int i, j;
    while (scanf("%d %d", &i, &j) != EOF) {
        int ii = i, jj = j;
        if (i > j)
            swap(i, j);
        int count = 0;
        rep2(r, i, j+1) {
            count = max(count, func(r));
        }

        printf("%d %d %d\n", ii, jj, count);

    }

    //////////////end////////////////
    return 0;
}
