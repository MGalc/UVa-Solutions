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
vi oddfactors;
vi primefactors;
vi primepowers;

void repfactors(int loc, int curnum) {
    for (int i = loc+1; i < primefactors.sz; i++) {
        int powv = primefactors[i] * curnum;
        rep(j, primepowers[i]) {
            oddfactors.push_back(powv);
            repfactors(i, powv);
            powv *= primefactors[i];
        }
    }

}

void findfactors(int N) {

    primefactors.clear();
    primepowers.clear();
    oddfactors.clear();

    int facN = N;
    if (facN % 2 == 0) {
        while (facN % 2 == 0) {
            facN /= 2;
        }
    }

    for (int i = 3; i <= sqrt(facN); i += 2) {
        if (facN % i == 0) {
            int pow = 0;
            bool added = false;
            while (facN % i == 0) {
                facN /= i;
                if (!added) {
                    primefactors.push_back(i);
                    added = true;
                }
                pow++;
            }
            primepowers.push_back(pow);
        }
    }
    if (facN > 2) {
        primefactors.push_back(facN);
        primepowers.push_back(1);
    }

    repfactors(-1, 1);
    oddfactors.push_back(1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N >= 0) {

        int B, A, a, b;
        int small = -1, large = -1, dif = -1;
        findfactors(N);
        rep(i, oddfactors.sz) {
            B = oddfactors[i];
            A = ((2*N) / B);
            if (B > A) swap(A, B);

            a = (A + B - 1) / 2;
            b = (A - B + 1) / 2;

            if (dif < abs(b - a)) {
                small = b, large = a;
                dif = max(dif, abs(b - a));
            }

            // N = a(a+1)/2 - b(b-1)/2
            // 2N = a^2 + a - b^2 + b
            // 2N = (a + b)(a - b + 1)
            // A = a + b
            // B = a - b + 1
            // N = AB/2
            //
            // A + B = a + b + a - b + 1
            // A + B = 2a + 1
            // a = (A + B - 1) / 2
            //
            // A - B = a + b - a + b - 1
            // A - B = 2b - 1
            // b = (A - B + 1) / 2
        }

        cout << N << " = " << small << " + ... + " << large << endl;
    }

    //////////////end////////////////
    return 0;
}
