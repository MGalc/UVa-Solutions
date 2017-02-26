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
typedef pair<double, double> pdd;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);

inline double dist(pdd a, pdd b) {
    return hypot(a.first - b.first, a.second - b.second);
}

struct ysort {
    bool operator()(const pdd& a, const pdd& b) {
        if (a.second == b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N) {
        vector<pdd> input(N);
        rep(i, N) {
            pdd in;
            cin >> in.first >> in.second;
            input[i] = in;
        }
        sort(all(input));

        set<pdd, ysort> sorted;
        double bestdist = INF;
        rep(i, input.sz) {
            pdd loend = input[i];
            loend.second -= bestdist;
            auto search = sorted.lower_bound(loend);

            while (search != sorted.end()) {
                if (input[i].first - search->first > bestdist) {
                    search = sorted.erase(search);
                }
                else if (input[i].second - search->second > bestdist) {
                    break;
                }
                else {
                    bestdist = min(bestdist, dist(input[i], *search));
                    search++;
                }
            }
            sorted.insert(input[i]);
        }

        if (bestdist < 9999.9999500000)
            cout << setprecision(4) << fixed << bestdist << endl;
        else
            cout << "INFINITY" << endl;

    }


    //////////////end////////////////
    return 0;
}
