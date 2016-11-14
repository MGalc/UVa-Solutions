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
vector<char> alph;
map<char, int> amap;

string assign(char a, char b) {
    int aval = amap[a] - 1, bval = amap[b] - 1;
    // same row
    if (aval / 5 == bval / 5) {
        string c;
        c += alph[(aval / 5) * 5 + (amap[a] % 5)];
        c += alph[(bval / 5) * 5 + (amap[b] % 5)];
        return c;
    }
    // same column
    if ((aval % 5) == (bval % 5)) {
        string c;
        c += alph[(aval + 5) % 25];
        c += alph[(bval + 5) % 25];
        return c;
    }

    string c;
    c += alph[(aval / 5 * 5) + (bval % 5)];
    c += alph[(bval / 5 * 5) + (aval % 5)];
    return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    string in;
    getline(cin, in);
    while (T--) {
        getline(cin, in);
        alph.clear();
        amap.clear();

        rep2(i, 0, in.sz) {
            if (in[i] == ' ') continue;
            if (amap[in[i]] == 0) {
                alph.push_back(in[i]);
                amap[in[i]] = alph.sz;
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (c != 'q' && amap[c] == 0) {
                alph.push_back(c);
                amap[c] = alph.sz;
            } 
        }

        string mess;
        getline(cin, mess);

        string out;
        for (int i = 0; i < mess.sz; i++) {
            int next1 = i;
            while (next1 < mess.sz && mess[next1] == ' ') next1++;
            if (next1 >= mess.sz) break;

            int next2 = next1+1;
            while (next2 < mess.sz && mess[next2] == ' ') next2++;
            if (next2 >= mess.sz) {
                out += assign(mess[next1], 'x');
                i = next2;
            }
            else if (mess[next1] == mess[next2]) {
                out += assign(mess[next1], 'x');
                i = next1;
            }
            else  {
                out += assign(mess[next1], mess[next2]);
                i = next2;
            }

        }

        rep(i, out.sz) out[i] = toupper(out[i]);
        cout << out << endl;
    }

    //////////////end////////////////
    return 0;
}
