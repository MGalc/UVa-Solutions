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
#define popc32(x) __builtin_popcount(x)
#define popc64(x) __builtin_popcountll(x)
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

static const double PI = 2 * acos(0);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int N;
    while (cin >> N, N != -1) {
        cout << "Round " << N << endl;
        string word, guess;
        cin >> word >> guess;

        vector<bool> wletters(26, false);
        int letters = 0;
        rep(i, word.sz)
            wletters[word[i]-'a'] = true;
        rep(i, 26)
            letters += wletters[i];

        vector<bool> guessed(26, false);
        bool won = false;
        int wrong = 0;
        rep(i, guess.sz) {
            if (guessed[guess[i]-'a']) continue;
            guessed[guess[i]-'a'] = true;
            if (wletters[guess[i]-'a']) {
                wletters[guess[i]-'a'] = false;
                letters--;
            }
            else {
                wrong++;
            }
            if (wrong >= 7) break;
            if (letters == 0) {
                won = true;
                break;
            }

        }

        if (won)
            cout << "You win." << endl;
        else if (wrong >= 7)
            cout << "You lose." << endl;
        else
            cout << "You chickened out." << endl;

    }

    //////////////end////////////////
    return 0;
}
