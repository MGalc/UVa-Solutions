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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    cin >> N;
    unordered_map<string, int> dict;

    rep(i, N) {
        string in;
        cin >> in;
        dict[in] = i;
    }

    cin >> N;
    static const int UNKNOWN = 0;
    static const int CORRECT = 1;
    static const int MISSPELLING = 2;
    rep(i, N) {
        int state = 0;
        string in;
        cin >> in;
        if (dict.find(in) != dict.end()) {
            state = CORRECT;
        }

        string realword;

        if (state != CORRECT) {
            // changed letter
            string tmp = in;
            rep(i, in.sz) {
                rep(j, 26) {
                    tmp[i] = j + 'a';
                    if (dict.find(tmp) != dict.end()) {
                        state = MISSPELLING;
                        if (realword.empty() || dict[realword] > dict[tmp])
                            realword = tmp;
                    }
                }
                tmp[i] = in[i];
            }

            // swapped letters
            tmp = in;
            for (int i = 0; i < in.sz-1; i++) {
                swap(tmp[i], tmp[i+1]);
                if (dict.find(tmp) != dict.end()) {
                    if (realword.empty() || dict[realword] > dict[tmp])
                        realword = tmp;
                    state = MISSPELLING;
                }
                tmp[i+1] = in[i+1];
                tmp[i] = in[i];
            }

            // additional letter
            for (int i = 0; i <= in.sz; i++) {
                tmp = "";
                int indx = 0;
                for (int j = 0; j < in.sz; j++) {
                    if (indx == i) {
                        tmp.push_back('a');
                        indx++;
                    }
                    tmp.push_back(in[j]);
                    indx++;
                }
                if (indx == i) {
                    tmp.push_back('a');
                    indx++;
                }

                for (int j = 0; j < 26; j++) {
                    tmp[i] = j + 'a';
                    if (dict.find(tmp) != dict.end()) {
                        state = MISSPELLING;
                        if (realword.empty() || dict[realword] > dict[tmp])
                            realword = tmp;
                    }
                }

            }

            // missing letter
            for (int i = 0; i < in.sz; i++) {
                string tmp = in.substr(0, i) + in.substr(i+1, in.sz - i - 1);
                if (dict.find(tmp) != dict.end()) {
                    state = MISSPELLING;

                    if (realword.empty() || dict[realword] > dict[tmp])
                        realword = tmp;
                }
            }
        }

        if (state == UNKNOWN) 
            cout << in << " is unknown" << endl;
        else if (state == MISSPELLING)
            cout << in << " is a misspelling of " << realword << endl;
        else
            cout << in << " is correct" << endl;
    }

    //////////////end////////////////
    return 0;
}
