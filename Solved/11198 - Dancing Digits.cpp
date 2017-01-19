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
static constexpr int maxN = 8;
vi visited;
vector<bool> negative;
int numbers[maxN];
int temp[maxN];
bool temp2[maxN];
static const int perms[] { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
static const bool isPrime[] { false, true, true, true, false, true, false, true, false, false, false, true, false, true, false, false };

// Put each number into each nibble of a 4 byte int.
inline int toInteger(int* nums) {
    int value = 0;
    //for (int i = maxN-1; i >= 0; i--) {
        //value |= (nums[i] << (4*i));
    //}
    // Lowest index in lower nibble.
    for (int i = 0; i < maxN; i++) {
        value |= (abs(nums[i]) << (4*i));
    }
    return value;
}

inline int getIndex(int maskV, int index) {
    return (maskV >> (4 * index)) & 0xF;
}

inline void extractVals(int maskV, int* out) {
    rep(i, maxN) {
        out[i] = getIndex(maskV, i);
    }
}

// Get the legographic permutation index of the maskInt
inline int getLexoPerm(int maskV) {
    static int lextemp[maxN];
    extractVals(maskV, lextemp);
    int lexo = 0;
    for (int i = 0; i < maxN-1; i++) {
        int smaller = 0;
        for (int j = i+1; j < maxN; j++) {
            if (lextemp[i] > lextemp[j])
                smaller++;
        }
        lexo += smaller * perms[maxN-i-1];
    }
    return lexo;
}

// Extract the original array from the lexographical index
inline void getOrigArray(int lexoVal, int* arr) {
    rep(i, maxN) temp2[i] = false;
    for (int i = 0; i < maxN; i++) {
        int div = lexoVal / perms[maxN-i-1];
        if (div > 0) {
            int larg = 0;
            // Insert the div'th lowest number remaining into the array
            for (int j = 0; j < maxN; j++) {
                if (!temp2[j]) {
                    if (larg == div) {
                        temp2[j] = true;
                        arr[i] = j;
                        break;
                    }
                    larg++;
                }
            }
            lexoVal -= div * perms[maxN-i-1];
        }
        else {
            // Insert the lowest number remaining next.
            int j = 0, larg = 0;
            for (int j = 0; j < maxN; j++) {
                if (!temp2[j]) {
                    temp2[j] = true;
                    arr[i] = j;
                    break;
                }
            }
        }
    }
}

int changePos(const int* const arr, int from, int to) {
    static int cptemp[maxN];
    rep(i, maxN) cptemp[i] = arr[i];

    int tmpv = cptemp[from];
    if (from < to) {
        for (int i = from; i < to; i++)
            cptemp[i] = cptemp[i+1];
        cptemp[to] = tmpv;
    }
    else if (to < from) {
        for (int i = from; i > to; i--)
            cptemp[i] = cptemp[i-1];
        cptemp[to] = tmpv;
    }

    return getLexoPerm(toInteger(cptemp));
}

// A pretty ugly solution.
// Could optimise it a lot more by using bitmasks rather than arrays in most places

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int firstnum = 0;
    int casenum = 1;

    while (cin >> firstnum, firstnum != 0) {
        cout << "Case " << casenum++ << ": ";
        negative.assign(maxN, false);
        visited.assign(perms[8], INF);

        if (firstnum < 0) negative[abs(firstnum)-1] = true;
        numbers[0] = abs(firstnum);

        for (int i = 1; i < maxN; i++) {
            int in;
            cin >> in;
            if (in < 0) negative[abs(in)-1] = true;
            numbers[i] = abs(in);
        }

        rep(i, maxN) numbers[i]--;

        // Check if all are positive or negative
        bool allSame = false;
        for (int i = 0; i < maxN-1; i++) {
            if (negative[i] != negative[i+1])
                allSame = false;
        }
        // If they're all the same, check if they're in the right order since we can't move any
        if (allSame) {
            bool inOrder = true;
            for (int i = 0; i < maxN; i++) {
                if (numbers[i] != i)
                    inOrder = false;
            }
            if (inOrder)
                cout << "0" << endl;
            else cout << "-1" << endl;
            continue;
        }

        int init = getLexoPerm(toInteger(numbers));
        visited[init] = 0;
        queue<pii> q;
        q.push(mp(init, 0));
        visited[init] = 0;

        bool done = false;
        while (!q.empty()) {
            if (done) break;
            int mask = q.front().first;
            int dist = q.front().second;
            q.pop();

            getOrigArray(mask, temp);

            // Negative to positive
            for (int i = 0; i < maxN && !done; i++) {
                if (negative[temp[i]]) {
                    for (int j = 0; j < maxN; j++) {
                        if (!negative[temp[j]]) {
                            if (!isPrime[temp[j] + temp[i] + 2])
                                continue;
                            int before = 0, after = 0;
                            int pbefore = 0, pafter = 0;
                            //before
                            if (j < i)
                                before = changePos(temp, i, j), after = changePos(temp, i, j+1);
                            else
                                before = changePos(temp, i, j-1), after = changePos(temp, i, j);

                            if (visited[before] > dist + 1) {
                                visited[before] = dist+1;
                                q.push(mp(before, dist+1));
                            }
                            if (visited[after] > dist + 1) {
                                visited[after] = dist+1;
                                q.push(mp(after, dist+1));
                            }

                            if (before == 0 || after == 0) {
                                done = true;
                                break;
                            }
                        }
                    }
                }

            // Positive to negative
            if (!negative[temp[i]]) {
                for (int j = 0; j < maxN; j++) {
                    if (negative[temp[j]]) {
                        if (!isPrime[temp[j] + temp[i] + 2])
                            continue;
                        int before = 0, after = 0;
                        //before
                        if (j < i)
                            before = changePos(temp, i, j), after = changePos(temp, i, j+1);
                        else
                            before = changePos(temp, i, j-1), after = changePos(temp, i, j);

                        if (visited[before] > dist + 1) {
                            visited[before] = dist+1;
                            q.push(mp(before, dist+1));
                        }
                        if (visited[after] > dist + 1) {
                            visited[after] = dist+1;
                            q.push(mp(after, dist+1));
                        }

                        if (before == 0 || after == 0) {
                            done = true;
                            break;
                        }
                    }
                }
            }
        }

    }

    if (visited[0] == INF)
        cout << "-1" << endl;
    else
        cout << visited[0] << endl;
}

//////////////end////////////////
return 0;
}
