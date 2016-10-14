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

const long maxval = 2000000000;
const long con = 1000000;
int main() {
    //////////////start//////////////

    for (long a = 1; a < 212; a++) {
        for (long b = a; b <= 1259; b++) {
            for (long c = b; c <= 2000-a-b; c++) {
                if (a*b*c*c > maxval)
                    break;
                long xres = a*b*c;
                if (xres == con)
                    continue;
                long pres = a+b+c;
                long dres = con*pres;
                long eres = xres - con;
                if (dres % eres != 0)
                    continue;
                long d = dres/eres;
                if (d < c)
                    continue;
                xres *= d;
                pres += d;
                if (pres > 2000)
                    continue;
                if (xres > maxval)
                    continue;

                    printf("%01ld.%02ld %01ld.%02ld %01ld.%02ld %01ld.%02ld\n", a/100, a%100, b/100, b%100, c/100, c%100, d/100, d%100);
            }
        }
    }

    cout.flush();
    //////////////end////////////////
    return 0;
}


//xa = (a * b * c) va = (a + b + c)
//v = 10e6
//d*xa == (d+va)v
//d*xa = dv + va*v
//d*xa - d*v = va*v
//d(xa - v) = va*v
//d = (va*v)/(xa-v);

