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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    vector<string> dictionary;
    string in;
    while(getline(cin, in), in != "#") dictionary.push_back(in);

    string line;
    getline(cin, line);

    string bestout = line;
    int bestmatch = 0;

    for (int i = 0; i < 28; i++) {
        int matched = 0;
        for (string s : dictionary) {
            if (line.find(s) != string::npos)
                matched++;
        }

        if (matched > bestmatch) bestout = line, bestmatch = matched;

        if (i == 27) break;
        rep(i, line.sz) {
            if (line[i] == 'Z') line[i] = ' ';
            else if (line[i] == ' ') line[i] = 'A';
            else line[i]++;
        }
    }

    string output;
    string tmpword;
    rep(i, bestout.sz) {
        if (bestout[i] == ' ') {
            tmpword.push_back(' ');
            if (output.sz + tmpword.sz > 60) {
                while (output[output.sz-1] == ' ') output.pop_back();
                cout << output << endl;
                output = tmpword;
                tmpword = "";
            }
            else {
                output += tmpword;
                tmpword = "";
            }
        }
        else tmpword.push_back(bestout[i]);
    }

    if (output.sz + tmpword.sz > 60) {
        while (output[output.sz-1] == ' ') output.pop_back();
        cout << output << endl;
        while (tmpword[tmpword.sz-1] == ' ') tmpword.pop_back();
        cout << tmpword << endl;
    }
    else {
        while (tmpword[tmpword.sz-1] == ' ') tmpword.pop_back();
        if (tmpword == "")
            while (output[output.sz-1] == ' ') output.pop_back();
        cout << output << tmpword << endl;
    }


    //////////////end////////////////
    return 0;
}
