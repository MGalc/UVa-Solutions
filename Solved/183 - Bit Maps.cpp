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
int y, x;
string in;
vii grid;
string out;

void toB(int& loc, int r, int c, int fr, int fc) {
    int localloc = loc;
    loc++;
    if (in[localloc] == 'D') {
        //topleft
        toB(loc, r, c, (fr+r)/2, (fc+c)/2);
        //topright
        if (c != fc)
            toB(loc, r, ((fc+c)/2)+1, (fr+r)/2, fc);
        //botleft
        if (r != fr)
            toB(loc, ((fr+r)/2)+1, c, fr, (fc+c)/2);
        //botright
        if (r != fr && c != fc)
            toB(loc, ((fr+r)/2)+1, ((fc+c)/2)+1, fr, fc);
    }
    else {
        char fill = in[localloc] - '0';
        
        for (int i = r; i <= fr; i++) {
            for (int j = c; j <= fc; j++) {
                grid[i][j] = fill;
            }
        }
    }
}

void toD(int r, int c, int fr, int fc) {
    int init = grid[r][c];
    bool bad = false;
    for (int i = r; i <= fr && !bad; i++) {
        for (int j = c; j <= fc; j++) {
            if (grid[i][j] != init) {
                out += "D";
                //topleft
                toD(r, c, (fr+r)/2, (fc+c)/2);
                //topright
                if (c != fc)
                    toD(r, ((fc+c)/2)+1, (fr+r)/2, fc);
                //botleft
                if (r != fr)
                    toD(((fr+r)/2)+1, c, fr, (fc+c)/2);
                //botright
                if (r != fr && c != fc)
                    toD(((fr+r)/2)+1, ((fc+c)/2)+1, fr, fc);
                bad = true;
                break;
            }
        }
    }
    if (!bad)
        out += init == 1 ? "1" : "0";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    char type;
    while (cin >> type, type != '#') {
        cin >> y >> x;
        cin >> in;
        while (in.size() < y*x) {
            string inl;
            getline(cin, inl);
            if (inl[1] == ' ') {
                for(int i = inl.size(); i >= 0; i--)
                    cin.putback(inl[i]);
                break;
            }
            else {
                in += inl;
            }
        }
        out = "";

        grid.assign(y, vi(x));
        if (type == 'B') {
            int loc = 0;
            rep(i, y) {
                rep(j, x) {
                    grid[i][j] = in[loc++] - '0';
                }
            }
            cout << "D" << std::right << setw(4) << y << setw(4) << x << endl;
            toD(0, 0, y-1, x-1);
            for(int i = ((out.size()-1)/50)*50; i > 0; i-=50)
                out.insert(out.begin()+i, '\n');
            cout << out << endl;
        }
        else if (type == 'D') {
            cout << "B" << std::right << setw(4) << y << setw(4) << x << endl;
            int loc = 0;
            toB(loc, 0, 0, y-1, x-1);

            int count = 0;
            rep(i, y) {
                rep(j, x) {
                    count++;
                    if (count > 50) {
                        cout << endl;
                        count = 1;
                    }
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
