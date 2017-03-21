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
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<double> vd;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long double ld;

static const double PI = 2 * acos(0);

vii matrixMult(const vii& m1, const vii& m2) {
    if (m1.size() == 0 || m1[0].size() != m2.size()) 
        throw length_error("Matrices cannot be multiplied");
    vii answer(m1.size(), vi(m2[0].size(), 0));
    for (int i = 0; i < m1.size(); i++) { // row
        for (int j = 0; j < m2[0].size(); j++) {
            for (int k = 0; k < m2.size(); k++) { // loop over rows of m2
                answer[i][j] = (answer[i][j] + ((ll)m1[i][k] * (ll)m2[k][j])%MOD) % MOD;
            }
        }
    }
    return answer;
}

vii matrixPow(const vii& base, int pow) {
    vii tmpbase = base;
    if (base.size() != 0 && base.size() != base[0].size()) 
        throw invalid_argument("base is not a square matrix");
    vii answer(base.size(), vi(base[0].size(), 0));
    for (int i = 0; i < min(answer.size(), answer[0].size()); i++)
        answer[i][i] = 1; // Create identity matrix

    while (pow > 0) {
        if (pow & 1) {
            answer = matrixMult(answer, tmpbase);
        }
        tmpbase = matrixMult(tmpbase, tmpbase);
        pow >>= 1ll;
    }

    return answer;
}

// Checks if we can move from mask m1 to mask m2
// returns true if we can, false otherwise
bool canmove(int m1, int m2) {
    int s1 = 0, s2 = 0;

    while (s1 < 7 && s2 < 7) {
        while (s1 < 7 && !(m1 & (1 << s1)))
            s1++;
        while (s2 < 7 && !(m2 & (1 << s2)))
            s2++;

        if (s1 >= 7 && s2 >= 7)
            break;
        if (abs(s1 - s2) == 1) {
            s1++;
            s2++;
        }
        else if (s1 == s2 && (m1 & (1 << (s1+1))) && (m2 & (1 << (s2+1)))) {
            s1 += 2;
            s2 += 2;
        }
        else 
            return false;
    }
    return true;
}

map<int, int> statetoloc;
vii buildadj() {
    int count = 0;
    vi loctostate;

    for (int i = 0; i < 7; i++) {
        for (int j = i+1; j < 7; j++) {
            for (int k = j+1; k < 7; k++) {
                for (int l = k+1; l < 7; l++) {
                    // Get all states of four bits set on in a 7 bit mask
                    int state = (1 << i) | (1 << j) | (1 << k) | (1 << l);
                    statetoloc[state] = loctostate.size();
                    loctostate.push_back(state);
                    count++;
                }
            }
        }
    }

    vii adj(loctostate.sz, vi(loctostate.sz, 0));

    // Here we build our adjacency matrix
    for (int i = 0; i < loctostate.sz; i++) {
        for (int j = 0; j < loctostate.sz; j++) {
            if (canmove(loctostate[i], loctostate[j]))
                adj[i][j] = 1;
        }
    }

    return adj;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    vii adj = buildadj();

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int mask = 0;
        for (int i = 0; i < 7; i++) {
            int in;
            cin >> in;
            if (in != 0)
                mask |= (1 << i);
        }

        int stateindx = statetoloc[mask];
        vii result = matrixPow(adj, N-1);

        vii initstate(1, vi(statetoloc.sz, 0));
        initstate[0][stateindx] = 1;
        result = matrixMult(initstate, result);

        int tot = 0;
        rep(i, result.sz) {
            rep(j, result[i].sz) {
                tot = (tot + result[i][j]) % MOD;
            }
        }

        cout << tot << endl;
    }

    //////////////end////////////////
    return 0;
}
