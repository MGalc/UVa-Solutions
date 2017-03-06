#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;
static const int TEST_CASES = 50;
static const int MAX_VAL = 50;

int main() {
    srand(time(NULL));
    cout << TEST_CASES << endl;
    for (int tc = 1; tc <= TEST_CASES; tc++) {
        //int row = rand() % 50 + 1, col = rand() % 50 + 1;
        int row = 50, col = 50;
        int banks = 0;
        string outbanks;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (rand() % 15 == 0) {
                    outbanks += to_string(i+1) + " " + to_string(j+1) + "\n";
                    banks++;
                }
            }
        }
        if (banks == 0) {
            tc--;
            continue;
        }
        cout << row << " " << col << " " << banks << endl;
        cout << outbanks;
    }
}
