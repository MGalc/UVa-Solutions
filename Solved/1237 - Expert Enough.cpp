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

int L[10100], H[10100];
string S[10100];

int main() {
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        int reps;
        cin >> reps;
        rep(i, reps) {
            cin >> S[i] >> L[i] >> H[i];
        }

        int Q;
        cin >> Q;
        rep(qq, Q) {
            int good = false;
            int mon;
            cin >> mon;
            int nindx = -1;
            rep(i, reps) {
                if (mon >= L[i] && mon <= H[i]) {
                    if (good) {
                        good = false;
                        break;
                    }
                    nindx = i;
                    good = true;
                }
            }
            if (good)
                cout << S[nindx] << endl;
            else cout << "UNDETERMINED" << endl;
        }
            if (T != 0)
                cout << endl;
    }

    //////////////end////////////////
    return 0;
}
