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
#define popc(x) __builtin_popcount(x)
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

const double PI = 2 * acos(0);
static const int gridSz = 4;
static const int maxVals = 67108864; //2^26

unordered_map<int, int> dist;

int rollUp(int info) {
    int loc = info & 0b1111;
    if (loc < 4) 
        return -1; //We're at the top of the grid.
    loc -= 4;
    int fleaLoc = info >> 10;
    int fleaOnDie = (info >> 4) & (0b111111);
    if (fleaLoc & (1 << loc)) {
        if (fleaOnDie & 0b0010) // Both a flea on where were are rolling to and on the bottom of die
            ;
        else {
            fleaOnDie |= 0b0010;
            fleaLoc &= ~(1 << loc);
        }
    }
    else if (fleaOnDie & 0b0010) {
        fleaOnDie &= ~(0b0010);
        fleaLoc |= 1 << loc;
    }

    int newFleaOnDie = 0;
    newFleaOnDie |= (fleaOnDie >> 1) & 0b000001;
    newFleaOnDie |= (fleaOnDie >> 1) & 0b000010;
    newFleaOnDie |= (fleaOnDie >> 1) & 0b000100;
    newFleaOnDie |= (fleaOnDie << 3) & 0b001000;
    newFleaOnDie |= (fleaOnDie >> 0) & 0b010000;
    newFleaOnDie |= (fleaOnDie >> 0) & 0b100000;

    return (fleaLoc << 10) | (newFleaOnDie << 4) | loc;
}

int rollDown(int info) {
    int loc = info & 0b1111;
    if (loc > 11) 
        return -1; //We're at the bottom of the grid.
    loc += 4;
    int fleaLoc = info >> 10;
    int fleaOnDie = (info >> 4) & 0b111111;
    if (fleaLoc & (1 << loc)) {
        // Both a flea on where were are rolling to and on the bottom of die
        if (fleaOnDie & 0b1000)
            ;
        else {
            fleaOnDie |= 0b1000;
            fleaLoc &= ~(1 << loc);
        }
    }
    else if (fleaOnDie & 0b1000) {
        fleaOnDie &= ~(0b1000);
        fleaLoc |= 1 << loc;
    }

    int newFleaOnDie = 0;
    newFleaOnDie |= (fleaOnDie >> 3) & 0b000001;
    newFleaOnDie |= (fleaOnDie << 1) & 0b000010;
    newFleaOnDie |= (fleaOnDie << 1) & 0b000100;
    newFleaOnDie |= (fleaOnDie << 1) & 0b001000;
    newFleaOnDie |= (fleaOnDie >> 0) & 0b010000;
    newFleaOnDie |= (fleaOnDie >> 0) & 0b100000;

    return (fleaLoc << 10) | (newFleaOnDie << 4) | loc;
}

int rollLeft(int info) {
    int loc = info & 0b1111;
    if (loc % 4 == 0) 
        return -1; //We're at the top of the grid.
    loc -= 1;
    int fleaLoc = info >> 10;
    int fleaOnDie = (info >> 4) & (0b111111);
    if (fleaLoc & (1 << loc)) {
        if (fleaOnDie & 0b100000) // Both a flea on where were are rolling to and on the bottom of die
            ;
        else {
            fleaOnDie |= 0b100000;
            fleaLoc &= ~(1 << loc);
        }
    }
    else if (fleaOnDie & 0b100000) {
        fleaOnDie &= ~(0b100000);
        fleaLoc |= 1 << loc;
    }

    int newFleaOnDie = 0;
    newFleaOnDie |= (fleaOnDie >> 5) & 0b000001;
    newFleaOnDie |= (fleaOnDie >> 0) & 0b000010;
    newFleaOnDie |= (fleaOnDie >> 2) & 0b000100;
    newFleaOnDie |= (fleaOnDie << 0) & 0b001000;
    newFleaOnDie |= (fleaOnDie << 4) & 0b010000;
    newFleaOnDie |= (fleaOnDie << 3) & 0b100000;

    return (fleaLoc << 10) | (newFleaOnDie << 4) | loc;
}

int rollRight(int info) {
    int loc = info & 0b1111;
    if (loc % 4 == 3) 
        return -1; //We're at the right of the grid.
    loc += 1;
    int fleaLoc = info >> 10;
    int fleaOnDie = (info >> 4) & (0b111111);
    if (fleaLoc & (1 << loc)) {
        if (fleaOnDie & 0b010000) // Both a flea on where were are rolling to and on the bottom of die
            ;
        else {
            fleaOnDie |= 0b010000;
            fleaLoc &= ~(1 << loc);
        }
    }
    else if (fleaOnDie & 0b010000) {
        fleaOnDie &= ~(0b010000);
        fleaLoc |= 1 << loc;
    }

    int newFleaOnDie = 0;
    newFleaOnDie |= (fleaOnDie >> 4) & 0b000001;
    newFleaOnDie |= (fleaOnDie >> 0) & 0b000010;
    newFleaOnDie |= (fleaOnDie >> 3) & 0b000100;
    newFleaOnDie |= (fleaOnDie >> 0) & 0b001000;
    newFleaOnDie |= (fleaOnDie << 2) & 0b010000;
    newFleaOnDie |= (fleaOnDie << 5) & 0b100000;

    return (fleaLoc << 10) | (newFleaOnDie << 4) | loc;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    // MEMOISATION
    // Mem  - bits : desc
    // 16   - 0-3: Location of die
    // 2^6  - 4-9: bitset of fleas on that side of dice
    //        - 1: die facing down (towards the floor)
    //        - 2: die facing north
    //        - 3: die facing up (towards the sky)
    //        - 4: die facing south
    //        - 5: die facing east
    //        - 6: die facing west
    // 2^16 - 10-25: bitset of fleas on tiles

    int T;
    cin >> T;
    while (T--) {
        vs grid(4);
        rep(i, 4) {
            cin >> grid[i];
        }

        int info;

        int dieLoc = 0;
        int fleaLocs = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] == 'D') {
                    dieLoc = (i*4) + j;
                }
                if (grid[i][j] == 'X') {
                    fleaLocs |= 1 << ((i*4) + j);
                }
            }
        }
        info = dieLoc;
        info |= fleaLocs << 10;

        dist.clear();
        //dist.assign(maxVals, INF);
        dist[info] = 0;

        queue<pair<int, int>> q;
        q.push(mp(info, 0));
        int result = -1;

        while (!q.empty()) {
            int qdist = q.front().second;
            int qinfo = q.front().first;
            q.pop();

            int next;
            next = rollUp(qinfo);
            if (next != -1 && dist[next] == 0) {
                dist[next] = qdist+1;
                q.push(mp(next, qdist+1));
                if (((next >> 4) & 0b111111) == 0b111111) {
                    result = dist[next];
                    break;
                }
            }
            next = rollDown(qinfo);
            if (next != -1 && dist[next] == 0) {
                dist[next] = qdist+1;
                q.push(mp(next, qdist+1));
                if (((next >> 4) & 0b111111) == 0b111111) {
                    result = dist[next];
                    break;
                }
            }
            next = rollLeft(qinfo);
            if (next != -1 && dist[next] == 0) {
                dist[next] = qdist+1;
                q.push(mp(next, qdist+1));
                if (((next >> 4) & 0b111111) == 0b111111) {
                    result = dist[next];
                    break;
                }
            }
            next = rollRight(qinfo);
            if (next != -1 && dist[next] == 0) {
                dist[next] = qdist+1;
                q.push(mp(next, qdist+1));
                if (((next >> 4) & 0b111111) == 0b111111) {
                    result = dist[next];
                    break;
                }
            }
        }
        if (result == -1) 
            cout << "impossible" << endl;
        else
            cout << result << endl;
    }

    //////////////end////////////////
    return 0;
}
