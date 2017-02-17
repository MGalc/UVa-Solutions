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
typedef long long ll;
typedef long double ld;

static const double PI = 2 * acos(0);

class Fenwick {
private:
    inline int LoBit(int val) {
        return val & -val;
    }

public:
    vi tree;
    Fenwick(vi& values) {
        tree.assign(values.sz+1, 0);

        for (int i = 1; i < tree.sz; i++) {
            adjust(i, values[i-1]);
        }
    }
    Fenwick(int n) {
        tree.assign(n + 1, 0);
    }

    void adjust(int loc, int value) {
        for (int i = loc; i < tree.size(); i += LoBit(i)) {
            tree[i] += value;
        }
    }

    // Returns cumulative values between lo and hi inclusive.
    int getValue(int lo, int hi) {
        return getValueFromStart(hi) - (lo == 0 ? 0 : getValueFromStart(lo-1));
    }

    // Gets a value at a single location.
    int getValueSingle(int loc) {
        return getValue(loc, loc);
    }

    // Returns the cumulative value from 0 - loc.
    int getValueFromStart(int loc) {
        int total = 0;
        while (loc != 0) {
            total += tree[loc];
            loc -= LoBit(loc);
        }
        return total;
    }

};

vi primes;
vi r_primes;
vi factors;
map<int, int> indexes;

static const int MILLION = 1000000;
void build() {
    vector<bool> isprime(MILLION+1, true);
    isprime[2] = false;
    r_primes.push_back(2000000);
    primes.push_back(2);
    vi fs(MILLION+1, 0);

    for (int i = 3; i <= MILLION; i+=2) {
        if (!isprime[i]) continue;
        primes.push_back(i);
        int rprime = 0;
        int tmp = i;
        while (tmp != 0) {
            rprime *= 10;
            rprime += tmp%10;
            tmp /= 10;
        }
        while (rprime < MILLION)
            rprime *= 10;

        r_primes.push_back(rprime);
        for (int j = i+i+i; j <= MILLION; j += i+i)
            isprime[j] = false;
    }

    sort(all(r_primes));
    factors.assign(r_primes.sz, 0);

    for (int i = 0; i < r_primes.size(); i++) {
        indexes[r_primes[i]] = i;
        int value = r_primes[i];
        for (int j = 0; j < primes.sz && primes[j] <= sqrt(MILLION) && primes[j] <= value; j++) {
            while (value % primes[j] == 0) {
                factors[i]++;
                value /= primes[j];
                if (value == 1) break;
            }
        }
        if (value > 1) factors[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    build();
    Fenwick ft(factors);
    Fenwick tally(factors.size());
    rep(i, factors.size())
        tally.adjust(i+1, 1);

    string command;
    int number;
    while (cin >> command >> number) {
        if (command[0] == 'd') {
            int indx = indexes[number]+1;
            ft.adjust(indx, -ft.getValue(indx, indx));
            tally.adjust(indx, -1);
        }
        else {
            number++;
            int lo = indexes[number]+1;
            int hi = factors.size()+1;
            while (lo < hi) {
                int mid = (hi+lo)/2;
                if (tally.getValue(0, mid) < number)
                    lo = mid+1;
                else
                    hi = mid;
            }

            cout << ft.getValue(0, lo) << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
