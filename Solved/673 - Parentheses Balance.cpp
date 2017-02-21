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

    int N;
    cin >> N;
    cin.ignore(100, '\n');
    while (N--) {
        string input;
        getline(cin, input);
        stack<char> p;

        bool good = true;
        for (int i = 0; i < input.size(); i++) {
            switch (input[i]) {
                case '(':
                    p.push(input[i]);
                    break;
                case ')':
                    if (!p.empty() && p.top() == '(')
                        p.pop();
                    else
                        good = false;
                    break;
                case '[':
                    p.push(input[i]);
                    break;
                case ']':
                    if (!p.empty() && p.top() == '[')
                        p.pop();
                    else
                        good = false;
                    break;
            }
            if (!good)
                break;
        }

        if (good && p.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    //////////////end////////////////
    return 0;
}
