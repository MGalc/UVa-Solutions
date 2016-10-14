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

vector<char> ins;
vector<bool> visited;
vector<vector<bool>> bad;
vector<int> past;
vector<bool> allbad;
map<char, int> cm;
bool none = true;

void bt(int loc) {
    rep(i, past.sz) {
        if (bad[loc][past[i]])
            return;
    }

    visited[loc] = true;
    past.push_back(loc);

    if (past.sz == ins.sz) {
        string strout;
        rep(i, ins.sz) {
            strout += ins[past[i]];
            if (i != ins.sz-1)
                strout += " ";
        }

        cout << strout << endl;
        past.pop_back();
        visited[loc] = false;
        none = false;
        return;
    }

    for (int i = 0; i < ins.sz; i++) {
        if (!visited[i]) {
            bt(i);
        }
    }
    visited[loc] = false;
    past.pop_back();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;

    bool first = true;
    while (T--) {
        ins.clear();
        past.clear();
        bad.clear();
        cm.clear();
        none = true;
        if (!first) cout << endl;
        else {
            cin.ignore(100, '\n');
            first = false;
        }

        cin.ignore(100, '\n');
        string in;
        getline(cin, in);
        ss strs(in);
        char c;
        while (strs >> c) {
            ins.push_back(c);
        }
        sort(all(ins));
        rep(i, ins.sz)
            cm[ins[i]] = i;
        visited.assign(ins.size(), false);

        bad.assign(ins.sz, vector<bool>(ins.sz, false));
        allbad.assign(ins.sz, false);

        getline(cin, in);
        strs.clear();
        strs.str(in);
        string token;
        while (strs >> token) {
            char t1 = token[0], t2 = token[2];
            bad[cm[t1]][cm[t2]] = true;
            allbad[cm[t2]] = true;
        }

        rep(i, ins.sz) {
            if (!allbad[i])
                bt(i);
        }
        if (none)
            cout << "NO" << endl;
    }

    //////////////end////////////////
    return 0;
}
