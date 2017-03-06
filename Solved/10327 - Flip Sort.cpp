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

int mergehalves(int lo, int hi, vi& v) {
    vi tmp(v.begin()+lo, v.begin()+hi+1);
    int mid = (tmp.sz-1)/2;
    int curlo = 0, curhi = mid+1;

    int swaps = 0;
    for (int i = 0; i < tmp.sz; i++) {
        if (curlo > mid) {
            v[lo+i] = tmp[curhi++];
        }
        else if (curhi >= tmp.sz) {
            v[lo+i] = tmp[curlo++];
        }
        else {
            if (tmp[curlo] <= tmp[curhi])
                v[lo+i] = tmp[curlo++];
            else {
                v[lo+i] = tmp[curhi++];
                swaps += (mid-curlo+1);
            }
        }

    }
    return swaps;
}

int sortrange(int lo, int hi, vi& v) {
    if (lo == hi) return 0;
    int mid = (lo+hi)/2;
    int swaps = 0;
    swaps += sortrange(lo, mid, v);
    swaps += sortrange(mid+1, hi, v);
    swaps += mergehalves(lo, hi, v);
    return swaps;
}

int mergeSort(vi& v) {
    return sortrange(0, v.sz-1, v);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N) {
        vi input(N);
        rep(i, N) {
            cin >> input[i];
        }

        cout << "Minimum exchange operations : " << mergeSort(input) << endl;

    }

    //////////////end////////////////
    return 0;
}
