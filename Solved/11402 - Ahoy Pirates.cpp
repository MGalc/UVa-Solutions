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

#define LEFT(x) (x << 1)
#define RIGHT(x) (x << 1) + 1
string ps;

class segtree {
public:
    enum flag {none = 0, inv = 1, set = 2, clear = 3};
private:
    vector<flag> lazy;
    vi tree;
    int size;
    int lindx = 0;
public:
    segtree() {
        size = ps.size();
        tree.assign(4 * size, 0);
        lazy.assign(4 * size, none);
        build(0, size-1, 1);
    }

    int build(int L, int R, int loc) {
        if (L == R) {
            if (loc > lindx) lindx = loc;
            tree[loc] = ps[L] - (int)'0';
            return tree[loc];
        }

        int val = build(L, (L+R)/2, LEFT(loc));
        val += build(((L+R)/2)+1, R, RIGHT(loc));
        tree[loc] = val;
        return val;
    }

    int setflag(int L, int R, int loc, flag f) {
        if (loc > lindx || loc < 1)
            return 0;
        int initval = tree[loc];
        if (f == inv) {
            if (lazy[loc] == none) {
                lazy[loc] = inv;
                tree[loc] = R - L + 1 - tree[loc];
            }
            else if (lazy[loc] == set) {
                lazy[loc] = clear;
                tree[loc] = 0;
            }
            else if (lazy[loc] == clear) {
                lazy[loc] = set;
                tree[loc] = R - L + 1;
            }
            else if (lazy[loc] == inv) {
                lazy[loc] = none;
                tree[loc] = R - L + 1 - tree[loc];
            }
        }
        else if (f == set) {
                lazy[loc] = set;
                tree[loc] = R - L + 1;
            }
        else if (f == clear) {
                lazy[loc] = clear;
                tree[loc] = 0;
        }
        return (tree[loc] - initval);
    }

    void updateback(int change, int loc) {
        loc /= 2;
        while (loc >= 1) {
            tree[loc] += change;
            loc /= 2;
        }
    }

    void setval(int l, int r, flag f) { setval(l, r, f, 0, size-1, 1); }
    void setval(int l, int r, flag f, int L, int R, int loc) {
        if (l > R || r < L)
            return;

        if (l <= L && R <= r) { //maybe go after next if statement?
            int change = setflag(L, R, loc, f);
            if (change != 0)
                updateback(change, loc);
            return;
        }

        if (lazy[loc] != none) {
            setflag(L, (L+R)/2, LEFT(loc), lazy[loc]);
            setflag(((L+R)/2)+1, R, RIGHT(loc), lazy[loc]);
            lazy[loc] = none;
        }

        setval(l, r, f, L, (L+R)/2, LEFT(loc));
        setval(l, r, f, ((L+R)/2)+1, R, RIGHT(loc));
    }

    int count(int l, int r) { return count(l, r, 0, size-1, 1); }
    int count(int l, int r, int L, int R, int loc) {
        if (l > R || r < L)
            return 0;
        if (l <= L && R <= r)
            return tree[loc];

        if (lazy[loc] != none) {
            setflag(L, (L+R)/2, LEFT(loc), lazy[loc]);
            setflag(((L+R)/2)+1, R, RIGHT(loc), lazy[loc]);
            lazy[loc] = none;
        }

        int val;
        val = count(l, r, L, (L+R)/2, LEFT(loc));
        val += count(l, r, ((L+R)/2)+1, R, RIGHT(loc));

        return val;
    }
};

int main() {
    //////////////start//////////////

    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    rep(tt, T) {
        cout << "Case " << tt+1 << ":\n";
        ps = "";
        int q;
        cin >> q;
        rep(qq, q) {
            int reps; 
            cin >> reps;
            string in;
            cin >> in;
            rep(r, reps) {
                ps += in;
            }
        }

        segtree st;

        cin >> q;
        int count = 1;
        rep(qq, q) {
            char instr;
            int l, r;
            cin >> instr >> l >> r;

            if (instr == 'F')
                st.setval(l, r, segtree::flag::set);
            else if (instr == 'E')
                st.setval(l, r, segtree::flag::clear);
            else if (instr == 'I')
                st.setval(l, r, segtree::flag::inv);
            else if (instr == 'S')
                cout << "Q" << count++ << ": " << st.count(l, r) << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
