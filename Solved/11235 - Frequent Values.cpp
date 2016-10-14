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
#define LEFT(x) x << 1
#define RIGHT(x) (x << 1) + 1

class fenwick {
private:
    vi tree;
    int size = 0;
public:
    fenwick(vi& input) {
        size = input.size();
        tree.assign(input.size() * 4, 0);
        build(input, 0, input.size()-1, 1);
    }

    int build(vi &input, int L, int R, int loc) {
        if (L == R){
            tree[loc] = input[L];
            return input[L];
        }
        else {
            int val = build(input, L, (L + R) / 2, LEFT(loc));
            val = max(val, build(input, ((L + R) / 2) + 1, R, RIGHT(loc)));
            tree[loc] = val;
            return val;
        }
    }

    int find(int l, int r, int L, int R, int loc) {
        if (l <= L && r >= R)
            return tree[loc];
        else if (l > R || r < L)
            return 0;

        int val = 0;
        val = find(l, r, L, (L+R)/2, LEFT(loc));
        val = max(val, find(l, r, ((L + R)/2) +1, R, RIGHT(loc)));
        return val;
    }

    int rmq(vi& start, vi& end, int l, int r) {
        int mx;
        if (end[l] == end[r])
            return (r - l + 1);
        mx = end[l] - l + 1;
        mx = max(mx, r - start[r] + 1);
        int left = end[l] + 1;
        int right = start[r] - 1;
        if (left <= right)
            mx = max(mx, find(left, right, 0, size-1, 1));
        return mx;
    }
};

int main() {
    //////////////start////////////// 
    
    std::ios::sync_with_stdio(false);
    int N, Q;
    while (cin >> N, N != 0) {
        cin >> Q;
        vi vals(N);
        vi start(N);
        vi end(N);

        int in;
        cin >> in;
        int begin = 0;
        int prev = in;
        start[0] = 0;
        rep2(i, 1, N) {
            cin >> in;
            if (in != prev) {
                int size = i - start[i-1];
                rep2(j, start[i-1], i) {
                    vals[j] = size;
                    end[j] = i-1;
                }
                begin = i;
                prev = in;
            }
            start[i] = begin;
            if (i == N-1) {
                int size = i - start[i] + 1;
                for (int j = start[i]; j <= i; j++) {
                    vals[j] = size;
                    end[j] = i;
                }
            }
        }

        fenwick f(vals);

        rep(q, Q) {
            int x, y;
            cin >> x >> y;
            cout << f.rmq(start, end, x-1, y-1) << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
