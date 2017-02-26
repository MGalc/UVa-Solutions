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
vi input;
int N;

bool solve() {
    // Remove if the input is already sorted
    sort(all(input), greater<int>());

    if (input[N-1] < 0) return false;

    vi sum(N, 0);
    sum[N-1] = input[N-1];
    for (int i = N-2; i >= 0; i--)
        sum[i] = sum[i+1] + input[i];
    if (sum[0] % 2 == 1)
        return false;

    int totk = 0;
    // totk <= (k*(k+1)) + summin
    for (int k = 0; k < N; k++) {
        totk += input[k];
        int rhs = k*(k+1);
        int i;
        for (i = N-1; i > k; i--) {
            if (input[i] >= (k+1))
                break;
        }
        if (i < N-1)
            rhs += sum[i+1];
        rhs += (i - k) * (k+1);

        if (totk > rhs) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N, N) {
        input.resize(N);
        /*rep(i, N) {
            cin >> input[i];
        }*/
        int zeros = 0;
        rep(i, N) {
            int in;
            cin >> in;
            if (in == 0) {
                zeros++;
            }
            else {
                input[i-zeros] = in;
            }
        }
        N -= zeros;
        input.resize(N);
        if (N == 0 || solve())
            cout << "Possible" << endl;
        else
            cout << "Not possible" << endl;
    }

    //////////////end////////////////
    return 0;
}
