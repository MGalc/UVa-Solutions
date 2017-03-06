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
#define popc32(x) __builtin_popcount(x)
#define popc64(x) __builtin_popcountll(x)
#define MOD 1000007
#define INF 1e9
#define EPS 1e-9

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef unsigned long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);
vector<double> input;
vector<double> avals;

void solveavals() {
    vector<vector<double>> xvals(7, vector<double>(7));
    vector<double> colvals(7);
    for (int i = 0; i < 7; i++) {
        colvals[i] = input[i];
        ll curx = 1;
        for (int j = 0; j < 7; j++) {
            xvals[i][j] = curx;
            curx *= ((ll)i+1LL);
        }
    }

    for (int r = 0; r < xvals.size()-1; r++) {
        int largest = r;
        for (int i = r + 1; i < xvals.size(); i++) {
            if (fabs(xvals[i][r]) > fabs(xvals[largest][r]))
                largest = i;
        }
        swap(xvals[largest], xvals[r]);
        swap(colvals[largest], colvals[r]);
        for (int i = r+1; i < xvals.size(); i++) {
            double ratio = (double)xvals[i][r] / xvals[r][r];
            for (int j = r; j < xvals.size(); j++) {
                xvals[i][j] -= xvals[r][j] * ratio;
            }
            colvals[i] -= colvals[r] * ratio;
        }
    }

    avals.assign(xvals.size(), 0);
    for (int i = xvals.size()-1; i >= 0; i--) {
        double otherval = 0.0;
        for (int j = xvals[i].size()-1; j > i; j--) {
            otherval += avals[j] * xvals[i][j];
        }

        avals[i] = (colvals[i] - otherval) / xvals[i][i];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////
    
    int T;
    cin >> T;
    while (T--) {
        input.resize(1500);
        rep(i, 1500) {
            ll in;
            cin >> in;
            input[i] = in;
        }

        solveavals();

        bool good = true;

        vector<ll> llavals(avals.sz);
        rep(i, avals.size()) {
            if (avals[i] < -1e-6 || avals[i] > 1000.000001) {
                good = false;
            }
            llavals[i] = round(avals[i]);
        }
        if (good) rep(i, input.sz) {
            ll totval = 0;
            ll mult = 1;
            for (int j = 0; j < 7; j++) {
                totval += llavals[j] * mult;
                mult *= (i+1LL);
            }
            if (totval != input[i]) {
                good = false;
                break;
            }
        }

        if (good) {
            rep(i, llavals.size()) {
                if (i != 0)
                    cout << " ";
                cout << llavals[i];
            }
            cout << endl;
        }
        else {
            cout << "This is a smart sequence!" << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
