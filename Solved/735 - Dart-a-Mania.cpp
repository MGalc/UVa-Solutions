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

int vals[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60 };
int size = 43;
int main() {
    //////////////start//////////////
    ios::sync_with_stdio(false);
    
    int score;
    while (cin >> score, score > 0) {
        int perms = 0;
        int combs = 0;
        if (score > 180)
            goto end;

        for (int a = 0; a < size; a++) {
            int aval = vals[a];
            if (aval > score)
                break;
            for (int b = a; b < size; b++) {
                int bval = vals[b] + aval;
                if (bval > score)
                    break;
                for (int c = b; c < size; c++) {
                    int cval = bval + vals[c];
                    if (cval == score) {
                        combs++;
                        int p = 0;
                        if (a != b) 
                            p += 3;
                        if (c != a && c != b)
                            p += 3;
                        if (p == 0)
                            p = 1;
                        perms += p;
                    }
                    else if (cval > score)
                        break;
                }
            }
        }


end:
        if (perms == 0) {
            cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS." << endl;
        }
        else { 
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << combs << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << perms << "." << endl;
        }
        cout << "**********************************************************************" << endl;
    }

    cout << "END OF OUTPUT" << endl;

    //////////////end////////////////
    return 0;
}
