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
int N, K;
vpii redinput;
vpii blueinput;
vii bigraph;
vi parents;

double dist(pii a, pii b) {
    return hypot(a.first - b.first, a.second - b.second);
}

vector<bool> visited;
int match(int red) {
    if (visited[red])
        return 0;
    visited[red] = true;

    rep(i, bigraph[red].sz) {
        int next = bigraph[red][i];
        if (parents[next] == -1) {
            parents[next] = red;
            return 1; // We were able to match
        }
        else if (parents[next] != red) {
            if (match(parents[next]) == 1) {
                parents[next] = red;
                return 1;
            }
        }
    }

    return 0;
}

int MCBM(int maxdist) {
    bigraph.assign(N, vi());
    parents.assign(N, -1);
    int reds = redinput.sz;
    int blus = blueinput.sz;

    rep(i, redinput.sz) {
        rep(j, blueinput.sz) {
            if (dist(redinput[i], blueinput[j]) <= (double)maxdist) {
                bigraph[i].push_back(reds+j);
            }
        }
    }

    int matched = 0;
    rep(i, reds) {
        visited.assign(N, false);
        matched += match(i);
    }

    return matched;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        redinput.clear();
        blueinput.clear();

        rep(i, N) {
            int a, b;
            string col;
            cin >> a >> b >> col;
            if (col == "red") 
                redinput.push_back(mp(a, b));
            else 
                blueinput.push_back(mp(a, b));
        }

        int hi = 0;
        rep(i, redinput.sz) {
            rep(j, blueinput.sz) {
                hi = max(hi, (int)dist(redinput[i], blueinput[j]) + 10);
            }
        }
        int impossibleval = hi;

        int lo = 0;
        while (hi > lo) {
            int mid = (hi+lo) / 2;
            int matched = MCBM(mid);
            if (matched >= K) // We were able to match the amount we needed
                hi = mid; // Lower the value
            else
                lo = mid+1; // Unable to match, raise our distance range
        }

        if (lo == impossibleval) 
            cout << "Impossible" << endl;
        else
            cout << lo << endl;
    }

    //////////////end////////////////
    return 0;
}
