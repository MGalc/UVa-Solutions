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
int S, N;
vector<vector<bool>> iscoprime;
int MAXS = 100;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void buildcoprimes() {
    iscoprime.assign(MAXS+1, vector<bool>(MAXS+1, false));

    for (int i = 2; i <= 100; i++) {
        for (int j = i; j <= 100; j++) {
            if (gcd(i, j) > 1) {
                iscoprime[i][j] = true;
                iscoprime[j][i] = true;
            }
        }
    }
}

vi numbers;

void solve(int loc, int total) {
    if (loc == N) {
        if (total == S) {
            for (int i = 0; i < numbers.size(); i++) {
                if (i != 0) cout << " ";
                cout << numbers[i];
            }
            cout << endl;
        }
        return;
    }

    int startloc = 1;
    int endloc = S;

    if (loc > 0) {
        if (numbers[loc-1] > 1) {
            startloc = numbers[loc-1]+1;
        }
        else {
            startloc = numbers[loc-1];
        }
        endloc = (S - total) / (N - loc);
    }
    if (loc == N-1 && startloc <= (S-total)) {
        startloc = (S-total);
        endloc = (S-total);
    }
    
    for (int i = startloc; i <= endloc; i++) {
        if (total + i > S) 
            break;

        bool bad = false;
        for (int j = loc-1; j >= 0; j--) {
            if (numbers[j] == 1) {
                break;
            }
            if (iscoprime[i][numbers[j]]) {
                bad = true;
                break;
            }
        }
        if (bad)
            continue;

        numbers[loc] = i;
        solve(loc+1, total+i);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    buildcoprimes();
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Case " << tt << ":" << endl;
        cin >> S >> N;
        numbers.assign(N, 0);

        solve(0, 0);
    }

    //////////////end////////////////
    return 0;
}
