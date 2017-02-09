#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;
typedef long long ll;
static const int TEST_CASES = 73;
static const int MAX_WALLS = 1000;
static const ll R = 1000;
static const ll C = 1000;
static const ll increment = min((ll)RAND_MAX, R*C/MAX_WALLS);

int main() {
    srand(time(NULL));
    for (int tc = 0; tc < TEST_CASES; tc++) {
        cout << R << " " << C << " " << MAX_WALLS << endl;
        ll currentLoc = 0;
        for (int i = 0; i < MAX_WALLS; i++) {
            currentLoc += rand() % increment;
            ll row = currentLoc / C;
            ll startcol = currentLoc % R;
            ll dist = rand() % min(increment, C - startcol);
            cout << startcol << " " << row << " " << startcol+dist << " " << row << endl;
            currentLoc += dist + 1;
        }
    }
    cout << "0 0 0" << endl;
}
