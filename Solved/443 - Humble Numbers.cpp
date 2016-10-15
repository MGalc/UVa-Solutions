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
#define INF 2e9
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

    vi primes;

    for (ll i = 0; i < 35; i++) {
        ll thisi = 1;
        rep(ii, i) thisi *= 2;
        if (thisi > INF) break;

        for (ll j = 0; j < 30; j++) {
            ll thisj = 1;
            rep(ii, j) thisj *= 3;
            thisj *= thisi;
            if (thisj > INF) break;

            for (ll k = 0; k < 30; k++) {
                ll thisk = 1;
                rep(ii, k) thisk *= 5;
                thisk *= thisj;
                if (thisk > INF) break;

                for (ll l = 0; l < 30; l++) {
                    ll thisl = 1;
                    rep(ii, l) thisl *= 7;
                    thisl *= thisk;
                    if (thisl > INF) break;

                    primes.push_back(thisl);
                }
            }
        }
    }

    sort(all(primes));

    int N;
    while (cin >> N, N) {
        cout << "The " << N;
        if (N % 100 == 11 || N % 100 == 12 || N % 100 == 13)
            cout << "th ";
        else if (N % 10 == 1)
            cout << "st ";
        else if (N % 10 == 2)
            cout << "nd ";
        else if (N % 10 == 3)
            cout << "rd ";
        else
            cout << "th ";

        cout << "humble number is " << primes[N-1] << "." << endl;
    }

    //////////////end////////////////
    return 0;
}
