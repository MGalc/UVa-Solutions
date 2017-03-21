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
typedef long long ll;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef vector<vector<ll> > vii;
typedef long double ld;

static const double PI = 2 * acos(0);

vii matrixMult(const vii& m1, const vii& m2) {
    if (m1.size() == 0 || m1[0].size() != m2.size()) 
        throw length_error("Matrices cannot be multiplied");
    vii answer(m1.size(), vi(m2[0].size(), 0));
    for (int i = 0; i < m1.size(); i++) { // row
        for (int j = 0; j < m2[0].size(); j++) {
            for (int k = 0; k < m2.size(); k++) { // loop over rows of m2
                answer[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return answer;
}

vii matrixPow(vii& base, int pow) {
    if (base.size() != 0 && base.size() != base[0].size()) 
        throw invalid_argument("base is not a square matrix");
    vii answer(base.size(), vi(base[0].size(), 0));
    for (int i = 0; i < min(answer.size(), answer[0].size()); i++)
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

    int P, Q, N;
    while (cin >> P >> Q >> N && (P || Q || N)) {
        vii input { { P, -Q }, { 1, 0 } };
        vii result = matrixPow(input, N);
        vii multmatrix = { { P }, { 2 } };
        result = matrixMult(result, multmatrix);

        cout << result[1][0] << endl;
    }

    //////////////end////////////////
    return 0;
}
