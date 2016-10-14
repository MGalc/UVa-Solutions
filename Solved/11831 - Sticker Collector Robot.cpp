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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int M, N, S;
    while (cin >> N >> M >> S, S || M || N) {
        pii start = mp(-1,-1);
        vector<string> map(N);
        rep(i, N) {
            cin >> map[i];
        }

        int facing = 10000000;
        bool found = false;
        pii pos = mp(0,0);
        for (int i = 0; i < N && !found; i++) {
            rep(j, M) {
                char v = map[i][j];
                if (v == 'N') {
                    facing += 0;
                    found = true;
                    pos = mp(i, j);
                    break;
                }
                else if (v == 'S') {
                    facing += 2;
                    found = true;
                    pos = mp(i, j);
                    break;
                }
                else if (v == 'L') {
                    facing += 1;
                    found = true;
                    pos = mp(i, j);
                    break;
                }
                else if (v == 'O') {
                    facing += 3;
                    found = true;
                    pos = mp(i, j);
                    break;
                }
            }
        }

        string instr;
        cin >> instr;

        int stickers = 0;
        rep(i, instr.size()) {
            if (instr[i] == 'D')
                facing++;
            else if (instr[i] == 'E')
                facing--;
            else {
                int res = abs(facing % 4);
                pii move = pos;
                if (res == 0)
                    move.first--;
                if (res == 1)
                    move.second++;
                if (res == 2)
                    move.first++;
                if (res == 3)
                    move.second--;
                
                if (move.second >= M || move.second < 0)
                    continue;
                if (move.first >= N || move.first < 0)
                    continue;
                if (map[move.first][move.second] == '#') 
                    continue;
                pos = move;
                if (map[pos.first][pos.second] == '*') {
                    stickers++;
                    map[pos.first][pos.second] = '.';
                }
            }
        }

        cout << stickers << endl;
    }

    //////////////end////////////////
    return 0;
}
