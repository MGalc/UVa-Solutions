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
vpii input;
vii origdist;
vii orig5dist;
static const vi dx { -2, -1, 1, 2, 2, 1, -1, -2 };
static const vi dy { 1, 2, 2, 1, -1, -2, -2, -1 };
vii pointdists;

void builddists(vii& buildv, int xloc, int yloc, int n) {
    buildv.assign(n, vi(n, -1));

    queue<pii> q;
    q.push(mp(xloc,yloc));
    buildv[xloc][yloc] = 0;

    while (!q.empty()) {
        pii top = q.front();
        q.pop();
        rep(i, dx.sz) {
            int nextx = top.first + dx[i];
            int nexty = top.second + dy[i];
            if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n)
                continue;
            if (buildv[nextx][nexty] != -1)
                continue;
            buildv[nextx][nexty] = buildv[top.first][top.second] + 1;
            q.push(mp(nextx, nexty));
        }
    }
}

void buildpointdists(int n) {
    pointdists.assign(K, vi(K, 0));
    if (n > 6) {
        rep(i, K) {
            for (int j = i+1; j < K; j++) {
                pii movedj = input[j];
                movedj.first -= input[i].first;
                movedj.second -= input[i].second;

                movedj.first = max(movedj.first, - movedj.first);
                movedj.second = max(movedj.second, -movedj.second);

                if (movedj.first == 1 && movedj.second == 1) {
                    vpii corners = { {0, 0}, {0, N-1}, {N-1, 0}, {N-1, N-1} };

                    bool incorner = false;
                    rep(k, corners.sz) {
                        if (input[i] == corners[k] || input[j] == corners[k]) {
                            incorner = true;
                            break;
                        }
                    }

                    if (incorner) {
                        pointdists[i][j] = pointdists[j][i] = 4;
                    }
                    else {
                        pointdists[i][j] = pointdists[j][i] = 2;
                    }
                }
                else {
                    pointdists[i][j] = pointdists[j][i] = origdist[movedj.first][movedj.second];
                }
            }
        }
    }
    else {
        rep(i, K) {
            builddists(orig5dist, input[i].first, input[i].second, n);
            for (int j = i+1; j < K; j++) {
                pointdists[i][j] = pointdists[j][i] = orig5dist[input[j].first][input[j].second];
            }
        }
    }
}

int startloc;
vii dp;
int TSP(int loc, int mask) {
    if (mask == (1 << K)-1)
        return dp[loc][mask] = pointdists[loc][startloc];
    if (dp[loc][mask] != -1)
        return dp[loc][mask];

    int best = INF;
    rep(i, K) {
        if (mask & (1 << i)) 
            continue;
        best = min(best, TSP(i, mask | (1 << i)) + pointdists[loc][i]);
    }

    return dp[loc][mask] = best;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    builddists(origdist, 0, 0, 1000);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cout << "Case " << tc << ": ";
        cin >> N >> K;
        input.assign(K, {0,0});
        rep(i, K) {
            cin >> input[i].first >> input[i].second;
            input[i].first--;
            input[i].second--;
        }

        buildpointdists(N);

        dp.assign(K, vi((1 << K)-1, -1));
        int minv = INF;
        startloc = 0;
        minv = min(minv, TSP(0, 1 << 0));
        cout << minv << endl;
    }

    //////////////end////////////////
    return 0;
}
