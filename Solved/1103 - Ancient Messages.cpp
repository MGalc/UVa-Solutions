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
int H, W;
bool input[220][500];
int visited[220][500];
int xx[4] {1, 0, -1, 0};
int yy[4] {0, 1, 0, -1};
char outs[6] { 'W', 'A', 'K', 'J', 'S', 'D' };

void fillblack(int x, int y, int fillval) {
    visited[x][y] = fillval;
    
    rep(i, 4) {
        rep(j, 4) {
            int nextx = x+xx[i];
            int nexty = y+yy[i];
            if (nextx < 0 || nexty < 0 || nextx >= H || nexty >= W)
                continue;
            if (input[nextx][nexty] == true && visited[nextx][nexty] == -1)
                fillblack(nextx, nexty, fillval);
        }
    }
}

int fillwhite(int x, int y) {
    visited[x][y] = 0;
    
    int surround = -1;
    rep(i, 4) {
        rep(j, 4) {
            int nextx = x+xx[i];
            int nexty = y+yy[i];
            if (nextx < 0 || nexty < 0 || nextx >= H || nexty >= W) {
                surround = -2;
                continue;
            }
            if (input[nextx][nexty] == false) {
                if (visited[nextx][nexty] == -1) {
                    int ret = fillwhite(nextx, nexty);
                    if (ret == -2)
                        surround = -2;
                    else if (surround != -2)
                        surround = ret;
                }
            }
            else {
                if (surround != -2)
                    surround = visited[nextx][nexty];
            }
        }
    }

    return surround;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> H >> W, H || W) {
        cout << "Case " << casenum++ << ": ";
        W *= 4;
        memset(visited, -1, sizeof visited);
        memset(input, false, sizeof input);
        rep(i, H) {
            string in;
            cin >> in;
            rep(j, in.size()) {
                char inbyte;
                if (in[j] <= '9')
                    inbyte = in[j] - '0';
                else
                    inbyte = (in[j] - 'a') + 10;

                for (int k = 3; k >= 0; k--) {
                    input[i][(3-k) + (j*4)] = (inbyte & (1 << k)) > 0;
                }
            }
        }

        int count = 0;
        rep(i, H) {
            rep(j, W) {
                if (visited[i][j] == -1 && input[i][j] == true) {
                    fillblack(i, j, count++);
                }
            }
        }
        vi surround(count);
        rep(i, H) {
            rep(j, W) {
                if (visited[i][j] == -1 && input[i][j] == false) {
                    int ret = fillwhite(i, j);
                    if (ret != -2)
                        surround[ret]++;
                }
            }
        }

        string out = "";
        rep(i, surround.sz) {
            out += outs[surround[i]];
        }

        sort(all(out));
        cout << out << endl;
    }

    //////////////end////////////////
    return 0;
}
