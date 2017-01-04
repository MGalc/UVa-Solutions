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
vi sufstr;
string origstr;
vi SA, pos;
vi stringbelong;
int gap = 1;
vi LCP;
int N;

void radixsort(int maxsz, int dist) {
    maxsz++;
    vi bucket(maxsz, 0);
    rep(i, pos.sz) {
        int v = i + dist < SA.size() ? pos[i + dist] : 0;
        bucket[v]++;
    }
    int sum = 0;
    rep(i, maxsz) {
        int val = bucket[i]; bucket[i] = sum; sum += val;
    }

    vi tmp(SA.sz, 0);
    int tmppos = 0;
    rep(i, SA.sz)  {
        int v = SA[i] + dist < SA.size() ? pos[SA[i] + dist] : 0;
        tmp[bucket[v]++] = SA[i];
    }

    rep(i, SA.sz) {
        SA[i] = tmp[i];
    }
}

bool sufcmp(int a, int b) {
    if (pos[a] != pos[b])
        return true;

    a += gap;
    b += gap;
    
    if (a < sufstr.sz && b < sufstr.sz)
        return pos[a] != pos[b];
    else if (a < sufstr.sz || b < sufstr.sz)
        return true;
    else
        return false;
}

void buildSA() {
    SA.resize(sufstr.size());
    pos.resize(sufstr.size());
    rep(i, sufstr.size()) {
        SA[i] = i;
        pos[i] = sufstr[i];
    }

    int maxk = 260;
    gap = 1;
    vi tmp(sufstr.sz);
    while (gap < sufstr.sz) {
        // sort out SA based on the pos vector
        //sort(all(SA), sufcmp);
        radixsort(maxk, gap);
        radixsort(maxk, 0);

        tmp[0] = 0;
        // Create tmp based on comparing neighbouring SA indexes
        for (int i = 0; i < tmp.sz-1; i++)
            tmp[i+1] = tmp[i] + sufcmp(SA[i+1], SA[i]);

        // Assign the tmp values to their SA positions
        for (int i = 0; i < tmp.sz; i++)
            pos[SA[i]] = tmp[i];

        // If all the suffixes are different we can stop since no more sorting will be done
        if (tmp[tmp.sz-1] == tmp.sz-1) break;
        gap *= 2;
        maxk = tmp[tmp.sz-1];
    }
}

void buildLCP() {
    LCP.assign(SA.size(), 0);
    vi phi(SA.size(), 0);
    vi pclp(SA.size(), 0);
    phi[SA[0]] = -1;
    for (int i = 1; i < SA.sz; i++) {
        phi[SA[i]] = SA[i-1];
    }
    for (int L = 0, i = 0; i < SA.sz; i++) {
        if (phi[i] == -1) {
            pclp[i] = 0; continue;
        }
        while (sufstr[i+L] == sufstr[phi[i] + L]) L++;
        pclp[i] = L;
        L = max(L-1, 0);
    }

    rep(i, SA.sz)
        LCP[i] = pclp[SA[i]];
}

int largestv = 0;
vector<int> largeststrs;

void checkAndAdd(int loc, set<int>& strs, int thisv) {
    if (strs.size() > N/2 && thisv > largestv) {
        // set new here
        largestv = thisv;
        largeststrs.clear();
        largeststrs.push_back(SA[loc-1]);
        strs.insert(stringbelong[SA[loc-1]]);
    }
    else if (strs.size() > N/2 && thisv == largestv) {
        // add to existing here
        strs.insert(stringbelong[SA[loc-1]]);
        largeststrs.push_back(SA[loc-1]);
    }
}

void solve(int& loc, set<int>& strs, int fallthrough) {
    strs.insert(stringbelong[SA[loc-1]]);
    int thisv = LCP[loc];

    while (loc < LCP.sz && LCP[loc] > 0) {
        if (thisv <= fallthrough) break;
        else if (LCP[loc] == thisv) { // We encounter the same height
            strs.insert(stringbelong[SA[loc]]);
            loc++;
        }
        else if (LCP[loc] > thisv) { // We encounter a higher height
            set<int> tmp;
            tmp.insert(stringbelong[SA[loc-1]]);
            solve(loc, tmp, thisv);
            strs.insert(tmp.begin(), tmp.end());

            checkAndAdd(loc, strs, thisv);
        }
        else if (LCP[loc] < thisv) { // We encounter a lower height one
            checkAndAdd(loc, strs, thisv);

            if (LCP[loc] > fallthrough) {
                thisv = LCP[loc];
                strs.insert(stringbelong[SA[loc]]);
            }
            else {
                break;
            }
            loc++;
        }
    }

    checkAndAdd(loc, strs, thisv);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> N, N) {
        if (casenum++ != 1) cout << endl;

        if (N == 1) { // Special case
            string in;
            cin >> in;
            cout << in << endl;
            continue;
        }
        origstr = "";
        largeststrs.clear();
        largestv = 0;
        sufstr.clear();
        stringbelong.clear();
        rep(i, N) {
            string in;
            cin >> in;
            rep(j, in.sz)
                sufstr.push_back(N + in[j]);
            rep(j, in.sz) // Mark to which input string the index belongs to.
                stringbelong.push_back(i);

            sufstr.push_back(i);
            // End of string marker doesn't belong to any string.
            stringbelong.push_back(-1);
            origstr += in;
            origstr += " "; //anything as filler
        }
        buildSA();
        buildLCP();

        for (int i = 1; i < LCP.sz; i++) {
            if (LCP[i] > 0) {
                set<int> s;
                solve(i, s, 0);
            }
        }

        if (largeststrs.empty())
            cout << "?" << endl;
        else {
            set<string> strs;
            for (auto s : largeststrs) {
                strs.insert(origstr.substr(s, largestv));
            }
            for (set<string>::iterator it = strs.begin(); it != strs.end(); it++) {
                cout << *it << endl;
            }
        }
    }

    //////////////end////////////////
    return 0;
}
