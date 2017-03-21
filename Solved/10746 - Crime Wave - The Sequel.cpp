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
typedef long long ll; typedef long double ld;

static const double PI = 2 * acos(0);

// In the adj grid:
// 0 to (M-1) are the police
// M to (M+N-1) are the banks
// M+N is S
// M+N+1 is T.
vector<vector<double>> costadj;
vector<vector<int>> visadj;
int maxnodes, S, T;
int bankoffset;
int flow;
int N, M;

double findFlow() {
    vector<double> dist(maxnodes, INF);
    dist[S] = 0;
    vector<int> prev(maxnodes, -1);
    prev[S] = S;
    for (int k = 0; k < maxnodes-1; k++) {
        for (int i = 0; i < costadj.size(); i++) {
            for (int j = 0; j < costadj.size(); j++) {
                if (visadj[i][j] <= 0)
                    continue;
                //if (costadj[i][j] <= EPS) // No negative or zero edges
                    //continue;
                if (i >= M && i < S && j < M) {
                    if (dist[j] > dist[i] - costadj[i][j]) {
                        dist[j] = dist[i] - costadj[i][j];
                        prev[j] = i;
                    }
                }
                else if (dist[j] > dist[i] + costadj[i][j]) {
                    dist[j] = dist[i] + costadj[i][j];
                    prev[j] = i;
                }
            }
        }
    }

    if (dist[T] >= INF)
        return INF;

    int curloc = T;
    while (curloc != prev[curloc]) {

        visadj[prev[curloc]][curloc]--;
        if (prev[curloc] != T && prev[curloc] != S)
            visadj[curloc][prev[curloc]]++;
        //costadj[prev[curloc]][curloc] -= dist[T];
        //costadj[curloc][prev[curloc]] += dist[T];
        curloc = prev[curloc];
    }

    return dist[T];
}

double EdmondsKarp() {
    double newflow = 0;
    double totalflow = 0;

    do {
        totalflow += newflow;
        newflow = findFlow();
    } while (newflow < INF);

    return totalflow;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    while (cin >> N >> M, N || M) {
        maxnodes = N+M+2;
        S = maxnodes - 2;
        T = maxnodes - 1;
        bankoffset = M;

        costadj.assign(maxnodes, vector<double>(maxnodes, INF));
        visadj.assign(maxnodes, vi(maxnodes, 0));
        rep(i, N) {
            rep(j, M) {
                cin >> costadj[j][M+i];
                costadj[M+i][j] = costadj[j][M+i];
                visadj[j][M+i] = 1;
            }
        }
        rep(i, M) {
            visadj[S][i] = 1;
            costadj[S][i] = 0;
        }
        rep(i, N) {
            visadj[M+i][T] = 1;
            costadj[M+i][T] = 0;
        }

        cout << setprecision(2) << fixed << EdmondsKarp()/N+EPS << endl;
    }

    //////////////end////////////////
    return 0;
}
