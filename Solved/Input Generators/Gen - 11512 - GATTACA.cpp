#include <bits/stdc++.h>

using namespace std;

static const char CHARS[] { 'A', 'C', 'G', 'T' };
static const int TEST_CASES = 500;
static const int MAX_STR_SIZE = 1000;

int main() {
    srand(time(NULL));
    cout << TEST_CASES << endl;
    for (int t = 0; t < TEST_CASES; t++) {
        string s;
        for (int i = 0; i < rand() % MAX_STR_SIZE + 1; i++) {
            s += CHARS[rand() % 4];
        }

        cout << s << endl;
    }
}
