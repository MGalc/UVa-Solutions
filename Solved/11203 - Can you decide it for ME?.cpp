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

    while (N--) {
        string in;
        cin >> in;

        bool bad = false;
        int state = 0;
        int l = 1, m = 1, r = 1;
        for (int i = 0; i < in.sz; i++) {
            if (bad) break;
            switch (state) {
                case 0:
                    if (in[i] == '?') state++;
                    else bad = true;
                    break;
                case 1:
                    if (in[i] == '?') {
                        l++;
                        continue; 
                    }
                    else if (in[i] == 'M') state++;
                    else bad = true;
                    break;
                case 2:
                    if (in[i] == '?') state++;
                    else bad = true;
                    break;
                case 3:
                    if (in[i] == '?') {
                        m++;
                        continue;
                    } 
                    else if (in[i] == 'E') state++;
                    else bad = true;
                    break;
                case 4:
                    if (in[i] == '?') state++;
                    else bad = true;
                    break;
                case 5:
                    if (in[i] == '?') {
                        r++;
                        continue;
                    }
                    else bad = true;
                    break;
            }
        }

        if (bad || state != 5 || (r - l) != m) cout << "no-theorem" << endl;
        else cout << "theorem" << endl;
    }

    //////////////end////////////////
    return 0;
}
