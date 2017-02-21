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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string input;
    while (getline(cin, input)) {
        ss ints(input);
        ints.str(input);
        int in;
        vi weights;
        while (ints >> in)
            weights.push_back(in);

        stack<int> size;
        stack<int> insize;

        bool bad = false;
        rep(i, weights.sz) {
            if (weights[i] < 0) {
                size.push(-weights[i]);
                insize.push(0);
            }
            else {
                if (!size.empty() && size.top() == weights[i]) {
                    if (insize.top() >= size.top()) {
                        bad = true;
                        break;
                    }
                    else {
                        insize.pop();
                        if (!insize.empty()) {
                            int newweight = size.top() + insize.top();
                            insize.pop();
                            insize.push(newweight);
                        }
                        size.pop();

                    }
                }
                else {
                    bad = true;
                    break;
                }
            }
        }

        if (!size.empty())
            bad = true;

        if (!bad)
            cout << ":-) Matrioshka!" << endl;
        else
            cout << ":-( Try again." << endl;
    }

    //////////////end////////////////
    return 0;
}
