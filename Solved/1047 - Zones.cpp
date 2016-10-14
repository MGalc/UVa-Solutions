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

int ts[22];
int shared[11];
int shvals[11];
int main() {
    //////////////start//////////////
    ios::sync_with_stdio(false);

    int N, B;
    int tcount = 1;
    while (cin >> N >> B, N || B) {
        cout << "Case Number  " << tcount++ << endl;
        rep(i, N) {
            cin >> ts[i];
        }

        int Q;
        cin >> Q;
        rep (qq, Q) {
            int q;
            cin >> q;
            int shmask = 0;
            rep(i, q) {
                int in;
                cin >> in;
                shmask |= (1 << (in-1));
            }
            int value;
            cin >> value;
            shared[qq] = shmask;
            shvals[qq] = value;
        }

        int largest = 0;
        int lmask = 0;
        for (int mask = 1; mask < (1 << N); mask++) {
            if (popc(mask) != B) 
                continue;
            int total = 0;
            
            for (int i = 0; i < N; i++) {
                if ((mask & (1 << i)) == 0)
                    continue;

                total += ts[i];
            }

            for (int i = 0; i < Q; i++) {
                int val = popc(shared[i] & mask);
                if (val >= 2)
                    total -= (val-1) * shvals[i];
            }

            if (total >= largest) {
                int good = true;
                if (total == largest) {
                    for (int k = 0; k < N; k++) {
                        if (((lmask & (1 << k)) != 0) && ((mask & (1 << k)) == 0)) {
                            good = false;
                            break;
                        }
                        else if (((lmask & (1 << k)) == 0) && ((mask & (1 << k)) != 0)) {
                            break;
                        }
                    }
                }
                if (good) {
                    largest = total;
                    lmask = mask;
                }
            }
        }

        cout << "Number of Customers: " << largest << endl;
        cout << "Locations recommended: ";
        bool first = true;
        rep(i, N) {
            if ((lmask & (1 << i)) != 0) {
                if (!first)
                    cout << " ";
                cout << i+1;
                first = false;
            }
        }

        cout << endl;
        cout << endl;
    }

    //////////////end////////////////
    return 0;
}
