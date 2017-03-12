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
typedef unsigned long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);
ll N, B;

vii matrixMult(const vii& m1, const vii& m2) {
    if (m2.sz != 0 && m1.sz != m2[0].sz) 
        throw length_error("Matrices cannot be multiplied");
    vii answer(m1.sz, vi(m2[0].sz, 0));
    rep(i, m1.sz) { // row
        rep(j, m2[0].sz) { // col
            rep(k, m2.sz) { // loop over rows of m2
                answer[i][j] += m1[i][k] * m2[k][j];
            }
            answer[i][j] %= B;
        }
    }
    return answer;
}

vii matrixPow(vii& base, ll pow) {
    if (base.sz != 0 && base.sz != base[0].sz) 
        throw invalid_argument("base is not a square matrix");
    vii answer(base.size(), vi(base[0].size(), 0));
    rep(i, min(answer.sz, answer[0].sz))
        answer[i][i] = 1; // Create identity matrix

    while (pow > 0) {
        if (pow & 1) {
            answer = matrixMult(answer, base);
        }
        base = matrixMult(base, base);
        pow >>= 1;
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    ld answer;
    int casenum = 1;
    while (cin >> N >> B, N || B) {
        cout << "Case " << casenum++ << ": " << N << " " << B << " ";

        vii fib { { 1, 1 }, { 1, 0 } };
        vii res = matrixPow(fib, N+1);

        // We add B to avoid negative numbers.
        int answer = max(0, (int)((res[0][1] * 2 - 1 + B) % B));
        cout << answer << endl;
    }

    //////////////end////////////////
    return 0;
}
