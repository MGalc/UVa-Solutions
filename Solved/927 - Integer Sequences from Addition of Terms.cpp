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

long long powll(long q, long r) {
    if (r == 0)
        return 1;
    long long total = q;
    for (int i = 2; i <= r; i++) {
        total *= q;
    }
    return total;
}

int main() {
    //////////////start//////////////

    int C;
    cin >> C;
    while (C--) {
        string in;
        int degree;
        cin >> degree;
        degree++;
        vi nums(degree);
        rep(i, degree) {
            cin >> nums[i];
        }
        int times, k;
        cin >> times >> k;
        int count = 1;
        int ttotal = times;

        while (ttotal < k) {
            count++;
            ttotal += (times*count);
        }

        long long total = 0;
        int n = 0;
        rep(i, degree) {
            total += ((long long)nums[i]) * powll(count, i);
        }

        cout << total << endl;
    }

    //////////////end////////////////
    return 0;
}
