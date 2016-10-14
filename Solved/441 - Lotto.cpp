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

int main() {
    //////////////start//////////////
    ios::sync_with_stdio(false);

    int N;
    int first = true;
    while (cin >> N, N != 0) {
        if (!first)
            cout << endl;
        else first = false;

        vi nums(N);
        rep(i, N) {
            cin >> nums[i];
        }

        int i1 = 0, i2 = 1, i3 = 2, i4 = 3, i5 = 4, i6 = 5;
        for (i1 = 0; i1 < i2; i1++) {
            for (i2 = i1+1; i2 < i3; i2++) {
                for (i3 = i2+1; i3 < i4; i3++) {
                    for (i4 = i3+1; i4 < i5; i4++) {
                        for (i5 = i4+1; i5 < i6; i5++) {
                            for (i6 = i5+1; i6 < N; i6++) {
                                cout << nums[i1] << " " << nums[i2] << " " << nums[i3] << " " << nums[i4] << " " << nums[i5] << " " << nums[i6] << endl;
                            }
                        }
                    }
                }
            }
        }
    }


    //////////////end////////////////
    return 0;
}
