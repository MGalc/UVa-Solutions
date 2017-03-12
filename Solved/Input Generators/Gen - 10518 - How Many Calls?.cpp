#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef unsigned long long ull;

static const int TEST_CASES = 1000;
static const ull MAXN = numeric_limits<ull>::max();
static const int MAXB = 1000;

// Generate random number from 1 to 2^61-1
ull generateN() {
    ull res = ((ull)rand() << 32) | (ull)rand();
    return res &= 0x7FFFFFFFFFFFFFFF;
}

int main() {
    srand(time(NULL));
    for (int tc = 0; tc < TEST_CASES; tc++) {
        cout << generateN() << " " << rand()%MAXB+1 << endl;
    }
    cout << "0 0" << endl;
}
