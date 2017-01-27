#include <vector>
#include <iostream>

using namespace std;

static const int TEST_CASES = 100;

int main() {
    srand(time(NULL));
    for (int t = 0; t < TEST_CASES; t++) {

        int numbers = rand() % 29 + 2; // From 2 - 30
        for (int num = 0; num < numbers; num++) {
            int nextNum = rand() % 100;
            if (num == 0)  {
                cout << nextNum;
            }
            else {
                cout << (rand() % 2 ? " + " : " - ");
                cout << nextNum;
            }
        }
        cout << endl;
    }
}
