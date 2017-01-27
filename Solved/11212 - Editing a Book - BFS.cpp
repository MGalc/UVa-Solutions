// Runs in about 7.5 seconds.
// Uses a simple BFS over all possibilities.

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
static ll SOL_VALUE = 0LL;
vi books;
int N;

ll moveFront(ll vals, ll start, ll end) {
    end++;
    if (start == end)
        return vals;
    ll numsMoved = end - start;
    // Move to front
    ll result = (((1LL << (end << 2LL)) - 1LL) & vals) >> (start << 2LL);
    result |= (((1LL << (start << 2LL)) - 1LL) & vals) << (numsMoved << 2LL);
    result |= vals >> (end << 2LL) << (end << 2LL); 

    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> N, N) {
        cout << "Case " << casenum++ << ": ";

        // Calculate the value we are looking for
        SOL_VALUE = 0LL;
        for (ll i = 1; i <= N; i++) {
            SOL_VALUE |= i << (4*(i-1));
        }

        books.assign(N, 0);
        ll mask = 0;
        rep(i, N) {
            cin >> books[i];
            mask |= (ll)books[i] << (4LL*i);
        }


        unordered_map<ll, int> dists;
        queue<ll> q;

        if (mask == SOL_VALUE) 
            goto end;

        q.push(mask);
        while (!q.empty()) {
            ll m = q.front();
            q.pop();

            int dist = dists[m];
            if (dist >= 5) break; // TODO: Possible change to 3

            for (int i = 0; i < N; i++) {
                for (int j = i; j < N; j++) {
                    ll shifted = moveFront(m, i, j);
                    int num = j+1 - i;
                    for (int k = num-1; k < N; k++) {
                        ll perm = moveFront(shifted, num, k);
                        if (dists[perm] == 0) {
                            dists[perm] = dist+1;
                            q.push(perm);
                        }
                        if (perm == SOL_VALUE)
                            goto end;
                    }
                }
            }
        }

end:
        cout << dists[SOL_VALUE] << endl;
    }

    //////////////end////////////////
    return 0;
}
