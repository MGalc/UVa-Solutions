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
        stack<char> cs;

        bool bad = false;
        int symbol = 0;
        for (int i = 0; i < input.sz; i++) {
            switch(input[i]) {
                case '(' :
                    if (i != input.sz-1 && input[i+1] == '*') {
                        cs.push('*');
                        i++;
                    }
                    else
                        cs.push('(');
                    break;
                case ')' :
                    if (!cs.empty() && cs.top() == '(')
                        cs.pop();
                    else bad = true;
                    break;
                case '[' :
                        cs.push('[');
                    break;
                case ']' :
                    if (!cs.empty() && cs.top() == '[')
                        cs.pop();
                    else bad = true;
                    break;
                case '{' :
                        cs.push('{');
                    break;
                case '}' :
                    if (!cs.empty() && cs.top() == '{')
                        cs.pop();
                    else bad = true;
                    break;
                case '<' :
                        cs.push('<');
                    break;
                case '>' :
                    if (!cs.empty() && cs.top() == '<')
                        cs.pop();
                    else bad = true;
                    break;
                case '*' :
                    if (i != input.sz-1 && input[i+1] == ')') {
                        if (!cs.empty() && cs.top() == '*') {
                            cs.pop();
                            i++;
                        }
                        else
                            bad = true;
                    }
                    break;
            }

            symbol++;
            if (bad) {
                break;
            }
        }

        if (!cs.empty() && !bad) {
            symbol++;
            bad = true;
        }

        if (!bad)
            cout << "YES" << endl;
        else
            cout << "NO " << symbol << endl;
    }

    //////////////end////////////////
    return 0;
}
