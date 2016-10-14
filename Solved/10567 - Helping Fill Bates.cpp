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
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define popc(x) __builtin_popcount(x)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const double PI = 2 * acos(0);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string input;
    cin >> input;
    vector<vi> chars(255);
    rep(i, input.size()) {
        chars[input[i]].push_back(i);
    }

    int T;
    cin >> T;
    while (T--) {
        string q;
        cin >> q;
        bool bad = false;
        int begin = 0;
        if (chars[q[0]].empty()) {
            bad = true;
        }
        else {
            begin = chars[q[0]][0];
        }

        int current = begin;

        for (int i = 1; i < q.size() && !bad; i++) {
            auto loc = lower_bound(all(chars[q[i]]), current);
            auto end = chars[q[i]].end();
            if (loc == end)
                bad = true;
            else {
                if (current == *loc) {
                    loc++;
                    if (loc == end) {
                        bad = true;
                        break;
                    }
                }
                current = *loc;
                while (i+1 < q.size() && q[i+1] == q[i]) {
                    loc++;
                    if (loc == end) {
                        bad = true;
                        break;
                    }
                    current = *loc;
                    i++;
                }
            }
        }

        if (bad)
            cout << "Not matched" << endl;
        else
            cout << "Matched " << begin << " " << current << endl;
    }

    //////////////end////////////////
    return 0;
}
