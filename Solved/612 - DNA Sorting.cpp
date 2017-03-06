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

int mergeHalves(int lo, int hi, string& s) {
    string tmp(s.begin()+lo, s.begin()+hi+1);

    int mid = (hi-lo)/2;
    int curlo = 0, curhi = mid+1;
    int sortnum = 0;
    for (int i = 0; i < tmp.sz; i++) {
        if (curlo > mid)
            s[lo+i] = tmp[curhi++];
        else if (curhi >= tmp.sz)
            s[lo+i] = tmp[curlo++];
        else {
            if (tmp[curlo] <= tmp[curhi])
                s[lo+i] = tmp[curlo++];
            else {
                s[lo+i] = tmp[curhi++];
                sortnum += (mid+1) - curlo;
            }
        }
    }

    return sortnum;
}

int sortRange(int lo, int hi, string& s) {
    if (lo == hi) return 0;
    int mid = (lo+hi)/2;
    
    int sortnum = 0;
    sortnum += sortRange(lo, mid, s);
    sortnum += sortRange(mid+1, hi, s);
    sortnum += mergeHalves(lo, hi, s);
    return sortnum;
    string tmp(s.begin()+lo, s.begin()+hi+1);
    
    int loc = lo;
    mid = (tmp.sz-1)/2, hi = tmp.sz-1, lo = 0;
    int curlo = 0, curhi = mid+1;
    for (int i = 0; i < tmp.sz; i++) {
        if (curlo > mid)
            s[loc] = tmp[curhi++];
        else if (curhi > hi)
            s[loc] = tmp[curlo++];
        else {
            if (tmp[curlo] <= tmp[curhi])
                s[loc] = tmp[curlo++];
            else {
                s[loc] = tmp[curhi++];
                sortnum += (mid+1) - curlo;
            }
        }

        loc++;
    }

    return sortnum;
}

int getsortnum(const string& s) {
    string sortedstr = s;
    return sortRange(0, s.size()-1, sortedstr);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;

    for (int tt = 0; tt < T; tt++) {
        if (tt != 0)
            cout << endl;
        int N, M;
        cin >> N >> M;
        vpii sortnum;
        vector<string> instrs(M);
        rep(i, M) {
            cin >> instrs[i];
            sortnum.push_back(mp(getsortnum(instrs[i]), i));
        }

        sort(all(sortnum));

        rep(i, sortnum.sz) {
            cout << instrs[sortnum[i].second] << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
