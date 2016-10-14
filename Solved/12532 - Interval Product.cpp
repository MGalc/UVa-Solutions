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

vi input;
#define LEFT(x) (x << 1)
#define RIGHT(x) (x << 1) + 1

inline int trimval(int v) {
    if (v < 0)
        return -1;
    if (v > 0)
        return 1;
    else return 0;
}
class segtree {
private:
    vi tree;
    int size;
public:
    segtree() {
        size = input.size();
        tree.assign(size * 4, 0);
        build(0, size-1, 1);
    }

    int build(int L, int R, int loc) {
        if (L == R) {
            tree[loc] = input[L];
            return tree[loc];
        }

        int tot = build(L, (L+R)/2, LEFT(loc));
        tot *= build(((L+R)/2)+1, R, RIGHT(loc));
        tree[loc] = tot;
        return tot;
    }

    void change(int l, int val) { change(l, l, 0, size-1, 1, val); }
    int change(int l, int r, int L, int R, int loc, int val) {
        if (l > R || r < L)
            return tree[loc];
        if (l <= L && R <= r) {
            tree[loc] = val;
            return val;
        }

        int vv = change(l, r, L, (L+R)/2, LEFT(loc), val);
        vv *= change(l, r, ((L+R)/2)+1, R, RIGHT(loc), val);
        tree[loc] = vv;
        return vv;
    }

    int getval(int l, int r) { return getval(l, r, 0, size-1, 1); }
    int getval(int l, int r, int L, int R, int loc) {
        if (l > R || r < L)
            return 1;
        if (l <= L && R <= r) {
            return tree[loc];
        }

        int vv = getval(l, r, L, (L+R)/2, LEFT(loc));
        vv *= getval(l, r, ((L+R)/2)+1, R, RIGHT(loc));
        return vv;
    }
};

int main() {
    //////////////start//////////////
    ios::sync_with_stdio(false);

    int N, Q;
    while (cin >> N >> Q) {
        input.assign(N+1, 1);
        rep(nn, N) {
            int in;
            cin >> in;
            input[nn] = trimval(in);
        }
        //trim the value when changing
        
        segtree st;
        
        rep(qq, Q) {
            char c;
            int l, r;
            cin >> c >> l >> r;
            if (c == 'P') {
                int ret = st.getval(l-1, r-1);
                if (ret == 0)
                    cout << '0';
                else if (ret > 0)
                    cout << '+';
                else cout << '-';
            }
            else if (c == 'C') {
                st.change(l-1, trimval(r));
            }
        }
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
