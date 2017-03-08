#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <cstdlib>

using namespace std;

static const int TEST_CASES = 500;
static const int MAXN = 1000;
static const int MAXK = 16;

int main() {
    srand(time(NULL));
    cout << TEST_CASES << endl;
    for (int tc = 1; tc <= TEST_CASES; tc++) {
        int N = rand()%(MAXN-4)+4, K = rand()%MAXK+1;
        cout << N << " " << K << endl;
        set<pair<int, int>> existing;

        for (int i = 0; i < K; i++) {
            int x, y;
            do {
                x = rand()%N+1;
                y = rand()%N+1;
            } while (existing.find(make_pair(x, y)) != existing.end());
            existing.insert(make_pair(x, y));
            cout << x << " " << y << endl;
        }
    }
}
