#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
static const int TEST_CASES = 100;
static const int MAXN = 1000;

int main() {
    srand(time(NULL));
    for (int tc = 1; tc <= TEST_CASES; tc++) {
        int N = rand() % (MAXN-2) + 3; // Create random number between 3 and MAXN inclusive

        cout << N << endl;
        vector<string> output(5, string(N, '\0'));

        int alfalfas = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < N; j++) {
                output[i][j] = (rand()%10 + '0'); // Create a random number from 0-10
            }
            if (rand()%2) { // 50% chance to place an alfalfa on a line
                alfalfas++;
                output[i][0] = '@';
            }
        }
        if (alfalfas == 0) // We didn't place any alfalfas down
            output[rand()%5][0] = '@'; // Place an alfalfa on any line

        for (int i = 0; i < 5; i++) {
            cout << output[i] << endl;
        }
        cout << endl;
    }
    cout << "0" << endl;
}
