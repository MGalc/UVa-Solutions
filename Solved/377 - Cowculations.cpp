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

int toInt(char c) {
    switch (c) {
        case 'V':
            return 0;
        case 'U':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
    }
    return 0;
}

int toChar(int in) {
    switch (in) {
        case 0:
            return 'V';
        case 1:
            return 'U';
        case 2:
            return 'C';
        case 3:
            return 'D';
    }
    return 'V';
}

string tostr(int in) {
    string out;
    for (int i = 0; i < 8; i++) {
        out.insert(out.begin(), toChar(in % 4));
        in /= 4;
    }

    return out;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    cout << "COWCULATIONS OUTPUT" << endl;

    rep(tt, T) {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = 0, n2 = 0;
        int multval = 1;
        for (int i = s1.sz-1; i >= 0; i--) {
            n1 += toInt(s1[i]) * multval;
            multval *= 4;
        }
        multval = 1;
        for (int i = s2.sz-1; i >= 0; i--) {
            n2 += toInt(s2[i]) * multval;
            multval *= 4;
        }

        rep(m, 3) {
            string in;
            cin >> in;
            if (in[0] == 'A') n2 = n1 + n2;
            if (in[0] == 'L') n2 *= 4;
            if (in[0] == 'R') n2 /= 4;
        }

        string finalstr;
        cin >> finalstr;
        string mystr = tostr(n2);

        if (finalstr == mystr)
            cout << "YES";
        else cout << "NO";
        cout << endl;

    }

    cout << "END OF OUTPUT" << endl;

    //////////////end////////////////
    return 0;
}
