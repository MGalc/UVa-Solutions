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

    string in;
    int setnum = 1;
    while (cin >> in && in != "9") {

        vector<string> vs;
        vs.push_back(in);

        while (cin >> in, in != "9") {
            vs.push_back(in);
        }

        bool decodable = true;
        for (int i = 0; i < vs.sz - 1 && decodable; i++) {
            for (int j = i+1; j < vs.sz && decodable; j++) {
                string* s1;
                string* s2;
                if (vs[i].sz > vs[j].sz) {
                    s1 = &vs[i];
                    s2 = &vs[j];
                }
                else {
                    s1 = &vs[j];
                    s2 = &vs[i];
                }

                bool prefixed = true;
                for (int k = 0; k < s2->size(); k++) {
                    if ((*s2)[k] != (*s1)[k]) {
                        prefixed = false;
                        break;
                    }
                }
                if (prefixed) {
                    decodable = false;
                    break;
                }
            }
        }

        if (decodable)
            cout << "Set " << setnum++ << " is immediately decodable" << endl;
        else
            cout << "Set " << setnum++ << " is not immediately decodable" << endl;
    }

    //////////////end////////////////
    return 0;
}
