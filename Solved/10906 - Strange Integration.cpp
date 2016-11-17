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
#define Idot(a,b) ((conj(a)*(b)).X)
#define IX real()
#define IY imag()
#define popc(x) __builtin_popcount(x)
#define INF 1e9
#define MOD 1000007

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

vector<string> expressions;
vector<bool> ismult;
map<string, int> strints;
vector<string> names;

string joinvals(string& exp1, string& exp2, char mult) {
    string str1, str2;
    bool isnum1 = false, isnum2 = false;
    int exp1indx = 0, exp2indx = 0;
    if (exp1[0] >= '0' && exp1[0] <= '9')
        str1 = exp1, isnum1 = true;
    else
        exp1indx = strints[exp1], str1 = expressions[exp1indx];

    if (exp2[0] >= '0' && exp2[0] <= '9')
        str2 = exp2, isnum2 = true;
    else
        exp2indx = strints[exp2], str2 = expressions[exp2indx];

    if (mult == '+') {
        if (!isnum2 && !ismult[exp2indx])
            return str1 + "+(" + str2 + ")";
        else
            return str1 + "+" + str2;
    }
    else {
        string strout;
        if (!isnum1 && !ismult[exp1indx])
            strout += "(" + str1 + ")";
        else
            strout += str1;
        strout += "*";
        if (!isnum2)
            strout += "(" + str2 + ")";
        else
            strout += str2;
        return strout;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Expression #" << tt << ": ";
        int N;
        cin >> N;
        expressions.assign(N, "");
        ismult.assign(N, false);
        names.assign(N, "");
        strints.clear();

        for (int i = 0; i < N; i++) {
            cin >> names[i];
            strints[names[i]] = i;

            // skip equals
            string tmp;
            cin >> tmp;

            string var1, var2, operand;
            cin >> var1 >> operand >> var2;

            ismult[i] = operand[0] == '*';

            expressions[i] = joinvals(var1, var2, operand[0]);
        }

        cout << expressions[N-1] << endl;
    }

    //////////////end////////////////
    return 0;
}
