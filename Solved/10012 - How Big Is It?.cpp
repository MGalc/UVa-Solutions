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
typedef vector<bool> vb;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);
vd radii;
vd prevrad;
vd prevlength;
vb circused;
double best;

void solve(int loc) {
    if (loc == prevrad.sz) {
        double locmax = 0.0;
        rep(i, radii.sz)
            locmax = max(locmax, prevlength[i] + prevrad[i]);
        best = min(best, locmax);
        return;
    }

    for (int i = 0; i < radii.sz; i++) {
        if (circused[i]) continue;
        
        // If there's no existing circles
        if (loc == 0) {
            circused[i] = true;
            prevrad[loc] = radii[i];
            prevlength[loc] = radii[i];
            solve(loc+1);
            circused[i] = false;
        }
        else {
            circused[i] = true;
            prevrad[loc] = radii[i];
            double dy = prevrad[loc-1] - prevrad[loc];
            double hyp = prevrad[loc-1] + prevrad[loc];
            prevlength[loc] = prevlength[loc-1] + sqrt(hyp*hyp - dy*dy);

            // Make sure that our circle doesn't extend over past the left side of the box.
            prevlength[loc] = max(prevlength[loc], prevrad[loc]);

            for (int j = loc-1; j >= 0; j--) {
                // Check whether the circle we just placed is overlapping another circle
                // If it is we have to reposition it horizontally.
                if (hypot(prevrad[loc] - prevrad[j], prevlength[loc] - prevlength[j])
                    < prevrad[loc] + prevrad[j]) 
                {
                    dy = prevrad[j] - prevrad[loc];
                    hyp = prevrad[j] + prevrad[loc];
                    prevlength[loc] = prevlength[j] + sqrt(hyp*hyp - dy*dy);
                }
            }

            solve(loc+1);
            circused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        radii.assign(N, 0.0);

        rep(i, N)
            cin >> radii[i];

        prevrad.assign(N, 0.0);
        prevlength.assign(N, 0.0);
        circused.assign(N, false);
        best = INF;
        solve(0);
        cout << setprecision(3) << fixed << best << endl;
    }

    //////////////end////////////////
    return 0;
}
