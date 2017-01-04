#include <bits/stdc++.h>

using namespace std;
char chars[] {'a', 'b', 'c', 'd'};

static const int NUM_TEST_CASES = 1000;
static const int MAX_STRINGS = 100;
static const int STRING_MAX_LENGTH = 100;

int main() {
    srand(time(NULL));
    // Test Cases
    for (int i = 0; i < NUM_TEST_CASES; i++) {

        // # of strings
        int maxj = rand()%MAX_STRINGS + 1;
        cout << maxj << endl;
        for (int j = 0; j < maxj; j++) {

            // Strings
            int length = rand()%STRING_MAX_LENGTH +1;
            string out;
            for (int i = 0; i < length; i++) {
                out += chars[rand()%4];
            }
            cout << out << endl;
        }
    }

    cout << "0" << endl;
    return 0;
}
