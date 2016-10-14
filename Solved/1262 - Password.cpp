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

vector<vector<char>> commons;
string thestr;
int K;

bool findit(int loc, int& k) {
    if (loc == 5) {
        k++;
        if (k == K)
            return true;
        else return false;
    }

    for (int i = 0; i < commons[loc].size(); i++) {
        bool res = findit(loc+1, k);
        if (res) {
            thestr += commons[loc][i];
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        thestr = "";
        cin >> K;
        vector<string> s1(6);
        rep(i, 6) {
            cin >> s1[i];
        }
        vector<string> s2(6);
        rep(i, 6) {
            cin >> s2[i];
        }
        commons.assign(5, vector<char>());
        bool bad = false;
        rep(i, 5) {
            rep(j, 6) {
                rep(k, 6) {
                    if (s1[j][i] == s2[k][i]) {
                        if (find(all(commons[i]), s1[j][i]) == commons[i].end()) {
                            commons[i].push_back(s1[j][i]);
                            break;
                        }
                    }
                }
            }

            if (commons[i].empty())
                bad = true;
            else sort(all(commons[i]));
        }

        if (!bad) {
            int k = 0;
            bool res = findit(0, k);
            if (!res)
                bad = true;
            else  {
                reverse(all(thestr));
            }
        }
        if (bad)
            cout << "NO" << endl;
        else cout << thestr << endl;
    }

    //////////////end////////////////
    return 0;
}
