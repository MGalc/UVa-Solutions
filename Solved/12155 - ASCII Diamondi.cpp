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

void generatecases(int amount) {
    srand(time(NULL));
    rep(i, amount) {
        cout << (rand() % 200) + 1;
        int col1 = rand() % 200, row1 = rand() % 200;
        int col2 = rand() % 200, row2 = rand() % 200;
        if (col1 > col2) swap(col1, col2);
        if (row1 > row2) swap(row1, row2);
        cout << " " << row1 << " " << col1 << " " << row2 << " " << col2 << endl;
    }
    cout << "0 0 0 0 0" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    //generatecases(200);
    int N, row1, col1, row2, col2;
    int casenum = 1;
    while (cin >> N >> row1 >> col1 >> row2 >> col2, N) {
        cout << "Case " << casenum++ << ":" << endl;
        // Size of the rows and columns of each diamond
        int rowcolsz = N * 2 - 1;
        for (int i = row1; i <= row2; i++) {
            // cols = size of the current line of the diamond
            int cols;
            if ((i % rowcolsz) > rowcolsz / 2) {
                cols = (rowcolsz - 1 - (i % rowcolsz)) * 2 + 1;
            }
            else {
                cols = 1 + (2 * (i % rowcolsz));
            }

            string out;
            // Notice that the relationship between the values in the diamond are
            // related to both columns and rows.
            // The value of the letter = N - (row distance from center of diamond - col distance from center of diamond)
            int difrows = abs(N - ((rowcolsz) - cols) / 2);
            // Just optimisation stuff
            int colsdiv2 = cols / 2;
            int mid = N-1;
            for (int j = col1; j <= col2; j++) {
                int jmod = j % rowcolsz;
                if (jmod > mid + colsdiv2 || jmod < mid - colsdiv2)
                    out.push_back('.');
                else {
                    int difcols = abs(N - jmod - 1);
                    out.push_back((char)((N - (difrows - difcols)) % 26) + 'a');
                }
            }

            cout << out << endl;
        }
    }

    //////////////end////////////////
    return 0;
}
