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
double a, b, s, v;
int A;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////
    
    while (cin >> a >> b >> v >> A >> s, a || b || v || A || s) {
        bool right = true, up = true;
        double ballx = a/2, bally = b/2;

        int bounceh = 0, bouncev = 0;
        double distrem = (v*s)/2;
        double out = tan(0);
        double out2 = cos(0);
        double out3 = sin(0);
        while (1) {
            //to vertical wall
            double fromhwall, hchange, hloc;
            if (up) fromhwall = b - bally;
            else fromhwall = bally;
            hchange = fromhwall * tan(((90-A)*PI)/180);
            if (!right) hchange = -hchange;
            hloc = ballx + hchange;

            double fromvwall, vchange, vloc;
            if (right) fromvwall = a - ballx;
            else fromvwall = ballx;
            vchange = fromvwall * tan((A*PI)/180);
            if (!up) vchange = -vchange;
            vloc = bally + vchange;

            if ((vloc == b || vloc == 0) && (hloc == a || hloc == 0)) {
                //distrem -= fromvwall / (cos((A*PI)/180));
                distrem -= sqrt(fromvwall*fromvwall + fromhwall*fromhwall);
                if (distrem < 0) break;
                bounceh++, bouncev++;
                ballx = hloc, bally = vloc;
                up = !up; right = !right;
            }
            else if (vloc <= b && vloc >= 0) {
                //distrem -= fromvwall / (cos((A*PI)/180));
                distrem -= sqrt(fromvwall*fromvwall + vchange*vchange);
                if (distrem < 0) break;

                bally = vloc;
                if (right) ballx = a;
                else ballx = 0;
                right = !right;
                bouncev++;
            }
            else if (hloc <= a && hloc >= 0) {
                //distrem -= fromhwall / (cos(((90-A)*PI)/180));
                distrem -= sqrt(fromhwall*fromhwall + hchange*hchange);
                if (distrem < 0) break;

                ballx = hloc;
                if (up) bally = b;
                else bally = 0;
                up = !up;
                bounceh++;
            }
        }

        cout << bouncev << " " << bounceh << endl;

    }

    //////////////end////////////////
    return 0;
}
