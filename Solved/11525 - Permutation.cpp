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
#define popc32(x) __builtin_popcount(x)
#define popc64(x) __builtin_popcountll(x)
#define MOD 1000007
#define INF 1e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);

#define LEFT(x) (x << 1)
#define RIGHT(x) (x << 1) + 1

struct segtree {
    vi tree;
    int N;
    segtree(int n) {
        N = n;
        tree.assign(n*4, 0);
        buildtree(1, 1, n);
    }

    void buildtree(int loc, int l, int h) {
        tree[loc] = (h-l)+1;
        if (l == h) return;
        buildtree(LEFT(loc), l, (h+l) >> 1);
        buildtree(RIGHT(loc), ((h+l) >> 1) + 1, h);
    }

    int returnNthHighest(int loc, int l, int h, int n) {
        int retval = 0;
        if (l == h) {
            retval = l;
        }
        else {
            if (tree[LEFT(loc)] >= n)
                retval = returnNthHighest(LEFT(loc), l, (h+l) >> 1, n);
            else
                retval = returnNthHighest(RIGHT(loc), ((h+l) >> 1)+1, h, n - tree[LEFT(loc)]);
        }
        tree[loc]--;
        return retval;
    }

    int getNthHighest(int n) {
        return returnNthHighest(1, 1, N, n);
    }
};

// I used a modified segment tree for this.
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> K;
        segtree ST(K);

        bool first = true;
        rep(i, K) {
            if (first)
                first = false;
            else 
                cout << ' ';

            int input;
            cin >> input;
            cout << ST.getNthHighest(input+1);
        }
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
