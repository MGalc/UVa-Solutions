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
int N;
vector<int> hotels;
vector<vpii> edges;
int S, T;
vpii visited;

struct curnode {
    int loc;
    int days;
    int minutes;
    curnode(int l, int d, int m) : loc(l), days(d), minutes(m) {}
    curnode() {}

    bool operator<(const curnode& b) const {
        if (days == b.days)
            return minutes < b.minutes;
        return days < b.days;
    }
    bool operator>(const curnode& b) const {
        return b < *this;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N, N) {
        S = 0;
        T = N-1;
        int H;
        cin >> H;
        H += 2;
        hotels.assign(N, -1);
        vi inhotels;
        hotels[0] = 0;
        inhotels.push_back(S);
        for (int i = 1; i < H-1; i++) {
            int hotel;
            cin >> hotel;
            hotels[hotel-1] = i;
            inhotels.push_back(hotel-1);
        }

        hotels[N-1] = H-1;
        inhotels.push_back(T);

        int M;
        cin >> M;
        edges.assign(N, vpii());
        rep(i, M) {
            int a, b, t;
            cin >> a >> b >> t;
            a--; b--;
            edges[a].push_back(mp(b, t));
            edges[b].push_back(mp(a, t));
        }

        vector<vector<bool>> hotelcons(H, vector<bool>(H, false));
        vii hoteledges(H, vi());

        for (int h = 0; h < H; h++) {
            priority_queue<pii, vpii, greater<pii>> q;
            q.push(mp(0, inhotels[h]));
            vi visited(N, INF); // Change out for hotels only maybe?
            visited[inhotels[h]] = 0;

            while (!q.empty()) {
                pii top = q.top();
                q.pop();
                if (visited[top.second] < top.first)
                    continue;

                for (int i = 0; i < edges[top.second].sz; i++) {
                    pii nextedge = edges[top.second][i];
                    if (nextedge.second + top.first > 600)
                        continue;
                    if (nextedge.second + top.first < visited[nextedge.first]) {
                        q.push(mp(nextedge.second + top.first, nextedge.first));
                        visited[nextedge.first] = nextedge.second + top.first;
                        int hotelindx = hotels[nextedge.first];
                        if (hotelindx >= 0 && !hotelcons[h][hotelindx]) {
                            hotelcons[h][hotelindx] = true;
                            hoteledges[h].push_back(hotelindx);
                            hotelcons[hotelindx][h] = true;
                            hoteledges[hotelindx].push_back(h);
                        }
                    }
                }
            }
        }

        S = 0; T = H-1;
        queue<pii> q;
        q.push(mp(S, 0));
        vector<bool> visited(H, false);
        int answer = -1;
        while (!q.empty()) {
            pii top = q.front();
            q.pop();

            for (int i = 0; i < hoteledges[top.first].sz; i++)  {
                int next = hoteledges[top.first][i];
                if (visited[next])
                    continue;
                visited[next] = true;
                if (next == T) {
                    answer = top.second;
                    break;
                }
                q.push(mp(next, top.second + 1));
            }
        }

        cout << answer << endl;
    }

    //////////////end////////////////
    return 0;
}
