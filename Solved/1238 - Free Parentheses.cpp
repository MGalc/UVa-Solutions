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

vi numbers;
int offset;
vector<bool> pos;
vector<vector<vector<bool>>> visited;
vector<bool> used;

void solve(int loc, int parentheses, int value) {
    if (loc == numbers.sz) {
        used[value+offset] = true;
        return;
    }

    if (visited[loc][parentheses][value+offset])
        return;
    visited[loc][parentheses][value+offset] = true;

    bool isNeg = ((!pos[loc] && ((parentheses & 1) == 0)) || (pos[loc] && (parentheses & 1)));
    int nextVal = value + (isNeg ? -numbers[loc] : numbers[loc]);

    if (!pos[loc])
        solve(loc+1, parentheses+1, nextVal);

    if (parentheses > 0)
        solve(loc+1, parentheses-1, nextVal);

    solve(loc+1, parentheses, nextVal);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    string input;
    while (getline(cin, input)) {
        pos.clear();
        numbers.clear();

        ss str(input);

        pos.push_back(true); // For the first number it is always positive.
        int num, sum = 0;
        while (str >> num) {
            numbers.push_back(num);
            sum += num;

            char sign;
            if (str >> sign) {
                pos.push_back(sign == '+');
            }
        }
        offset = sum+5;

        visited.assign(numbers.sz, vector<vector<bool>>(numbers.sz, vector<bool>(offset*2, false)));
        used.assign(offset*2, false);

        solve(0, 0, 0);

        int answer = 0;
        for (int i = 0; i < used.sz; i++) {
            if (used[i])
                answer++;
        }

        cout << answer << endl;
    }

    //////////////end////////////////
    return 0;
}
