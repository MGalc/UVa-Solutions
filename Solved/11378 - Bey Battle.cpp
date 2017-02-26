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

int dist(const pii& a, const pii& b) {
    return max(abs(a.first-b.first), abs(a.second-b.second));
}

struct ysort {
    bool operator() (const pii& a, const pii& b) {
        if (a.second == b.second) 
            return a.first < b.first;
        return a.second < b.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N) {
        vpii input(N);
        rep(i, N)
            cin >> input[i].first >> input[i].second;

        sort(all(input));

        set<pii, ysort> points;

        int best = INF;
        for (int i = 0; i < input.sz; i++) {
            pii loval = input[i];
            loval.second -= best;
            auto p = points.lower_bound(loval);

            while (p != points.end()) {
                if (input[i].first - p->first > best) {
                    p = points.erase(p);
                }
                else if (input[i].second - p->second > best) {
                    break;
                }
                else {
                    best = min(best, dist(input[i], *p));
                    p++;
                }
            }

            points.insert(input[i]);
        }

        cout << best << endl;
    }

    //////////////end////////////////
    return 0;
}
