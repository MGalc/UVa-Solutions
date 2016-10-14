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

string ps;

class fenwick {
private:
vector<int> tree;
int size = 0;
public:
    fenwick() {
        tree.assign(ps.size(), 0);
        build();
    }

    int LSOne(int in) {
        return (in & -in);
    }

    void build() {
        int minval;
        rep2(i, 1, ps.size()) {
            if (ps[i] == '1')
                change(1, i);
        }
    }

    inline void change(int change, int loc) {
        while (loc <= tree.size()) {
            tree[loc] += change;
            loc = loc + LSOne(loc);
        }
    }

    inline int getValue(int x) {
        int value = tree[x];
        x = x - LSOne(x);
        if (x == 0)
            return value;
        else return value + getValue(x);
    }

    inline int between(int l, int r) {
        return getValue(r) - getValue(l-1);
    }

    inline void mutBuc(int l, int r) {
        rep2(i, l, r+1) {
            if (ps[i] == '0') {
                change(1, i);
                ps[i] = '1';
            }
        }
    }

    inline void mutBar(int l, int r) {
        rep2(i, l, r+1) {
            if (ps[i] == '1') {
                change(-1, i);
                ps[i] = '0';
            }
        }
    }

    inline void invert(int l, int r) {
        rep2(i, l, r+1) {
            if (ps[i] == '1'){
                change(-1, i);
                ps[i] = '0';
            }
            else {
                change(1, i);
                ps[i] = '1';
            }
        }
    }
};


int main() {
    //////////////start//////////////
    std::ios::sync_with_stdio(false);

    int t;
    cin >> t;
    rep(tt, t) {
        cout << "Case " << tt+1 << ":\n";
        ps = " ";
        int q;
        cin >> q;
        rep(qq, q) {
            int reps;
            cin >> reps;
            string in;
            cin >> in;
            rep(i, reps) 
                ps += in;
        }

        fenwick f;

        cin >> q;
        int query = 1;
        rep(qq, q) {
           char instr; 
           int l, r;
           cin >> instr >> l >> r;
           l++; r++;

           if (instr == 'F')
               f.mutBuc(l, r);
           else if (instr == 'E')
               f.mutBar(l, r);
           else if (instr == 'I')
               f.invert(l, r);
           else if (instr == 'S')
               cout << "Q" << query++ << ": " << f.between(l, r) << endl;
        }
    }


    //////////////end////////////////
    return 0;
}
