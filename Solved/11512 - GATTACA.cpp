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
int N;

vi SA;
vi RA;
int gap;

bool sorter(int a, int b) {
    if (RA[a] != RA[b]) return RA[a] < RA[b];

    a += gap;
    b += gap;

    if (a < RA.sz && b < RA.sz) return RA[a] < RA[b];
    else return a < b;
}

// NOTE: suffixStr should have a delimiter at the end which is smaller than the rest of it.
void buildSA(const string& suffixStr) {
    SA.clear();
    RA.clear();
    gap = 1;

    for (int i = 0; i < suffixStr.size(); i++) {
        SA.push_back(i);
        RA.push_back(suffixStr[i]);
    }

    vi temp(SA.size());
    while (gap < SA.size()) {
        sort(SA.begin(), SA.end(), sorter);

        temp[0] = 0;
        for (int i = 1; i < SA.size(); i++)
            temp[i] = temp[i-1] + sorter(SA[i-1], SA[i]);

        for (int i = 0; i < RA.size(); i++)
            RA[SA[i]] = temp[i];

        if (RA[SA[SA.size()-1]] == RA.size()-1) break;

        gap *= 2;
    }
    //if (RA[RA.size()] != RA.size()-1) throw "wrong";
    int breaks = 0;
}

vi LCP;
// Will only work if RA has everything individually ranked.
void buildLCP(const string& suffixStr) {
    vi prevInSA(SA.size());
    LCP.resize(SA.size());
    prevInSA[SA[0]] = -1;
    for (int i = 1; i < SA.size(); i++)
        prevInSA[SA[i]] = SA[i-1];

    int matched = 0;
    for (int i = 0; i < SA.size(); i++) {
        if (prevInSA[i] == -1) {
            LCP[RA[i]] = 0;
            continue;
        }
        while (suffixStr[i + matched] == suffixStr[matched + prevInSA[i]])
            matched++;

        LCP[RA[i]] = matched;
        matched = max(0, matched-1);
    }
}

bool findLRS(int& largestv, int& stringindx, int& amount) {
    largestv = 0;
    stringindx = -1;
    amount = 0;

    int largestindx;
    for (int i = 0; i < LCP.size(); i++) {
        if (LCP[i] > largestv) {
            largestv = LCP[i];
            largestindx = i;
            stringindx = SA[i];
        }
    }

    if (largestv == 0)
        return false;

    amount = 1;
    int i = largestindx;
    while (i != LCP.size() && LCP[i] == largestv)
        amount++, i++;

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ////////////start//////////////

    cin >> N;

    while (N--) {
        string instr;
        cin >> instr;
        instr.push_back('\0');

        buildSA(instr);
        buildLCP(instr);

        int largestv, stringindx, amount;
        if (findLRS(largestv, stringindx, amount))
            cout << instr.substr(stringindx, largestv) << " " << amount << endl;
        else
            cout << "No repetitions found!" << endl;
    }

    ////////////end////////////////
    return 0;
}
