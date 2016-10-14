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

int getv(int v) {
    if (v == 1) return 1;

    int nval = 1;
    int count = 0;
    while (nval <= v) {
        if (nval * 2 >= v)
            break;
        nval *= 2;
    }

    return 2 * (v - nval);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////
    
    int N;
    while (cin >> N, N) {
        cout << getv(N) << endl;
    }
    
    /*int oN = N;
    list<int> l;
    for (int i = N; i > 0; i--) l.push_back(i);

    while (N > 1) {
    l.erase(prev(l.end()));
    l.push_front(*prev(l.end()));
    l.erase(prev(l.end()));
    N--;
    }

    cout << "FINAL FOR " << oN << ": " << *prev(l.end()) << endl;*/

    // 8 7 6 5 4 3 2 1
    // 2 8 7 6 5 4 3
    // 4 2 8 7 6 5
    // 6 4 2 8 7
    // 8 6 4 2
    // 4 8 6
    // 8 4
    // 8

    // 7 6 5 4 3 2 1
    // 2 7 6 5 4 3
    // 4 2 7 6 5
    // 6 4 2 7
    // 2 6 4
    // 6 2
    // 6

    // 6 5 4 3 2 1
    // 2 6 5 4 3
    // 4 2 6 5
    // 6 4 2
    // 4 6
    // 4

    // 5 4 3 2 1
    // 2 5 4 3
    // 4 2 5
    // 2 4
    // 2

    // 4 3 2 1
    // 2 4 3
    // 4 2
    // 4

    // 3 2 1
    // 2 3
    // 2

    // 2 1
    // 2
    //
    // 1

    //////////////end////////////////
    return 0;
}
