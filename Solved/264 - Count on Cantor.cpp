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

    int N;

    while (cin >> N) {
        //N = n(n+1) / 2
        //2N = n(n+1)
        //2N = n^2 + n
        //0 = n(n+1) - 2N
        //0 = n^2 + n - 2N
        //n = (-1 + sqrt(1 + 8N)) / 2
         
        int iN = N-1;
        // get the diagonal the number exists in
        int diag = (-1 + (int)sqrt(1 + 8*iN)) / 2;

        // increment, as we want to start at index 1.
        diag++;
        // get starting and ending diagonal locations which N exists in
        int startdiag = 1 + diag*(diag-1) / 2;
        int enddiag = (diag * (diag + 1) / 2);

        // calculate the numerator and denominator based on N's distance from the start and end diagonal indexes
        int den = -1, num = -1;
        num = (N - startdiag) + 1;
        den = (enddiag - N) + 1;

        // if it's an odd numbered diagonal, we are travelling the opposite way, so flip the fraction
        if (diag % 2 == 1) {
            swap(num, den);
        }

        cout << "TERM " << N << " IS " << num << "/" << den << endl;
    }

    //////////////end////////////////
    return 0;
}
