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

int cToI(char c) {
    return (int)c - 'a';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    cin >> N;
    string in;
    getline(cin, in);

    while (N--) {
        getline(cin, in);
        
        bool inpara = false;
        int notted[26];
        bool good = false;
        for (int i = 0; i < in.sz; i++) {
            if (inpara) {
                if (in[i] == ')') {
                    inpara = false;
                    bool locgood = true;
                    rep(i, 26) {
                        if (notted[i] == 3)
                            locgood = false;
                    }
                    if (locgood) {
                        good = true;
                        break;
                    }
                }
                else if (in[i] == '&') continue;
                else if (in[i] == '~') {
                    notted[cToI(in[i+1])] |= 1;
                    i++;
                }
                else {
                    notted[cToI(in[i])] |= 2;
                }
            }
            else if (in[i] == '(') {

                inpara = true;
                memset(notted, 0, sizeof notted);
            }
        }

        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    //////////////end////////////////
    return 0;
}
