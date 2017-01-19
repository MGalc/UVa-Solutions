#include <bits/stdc++.h>

using namespace std;

static const int maxN = 8;
static const int TEST_CASES = 100;

int main() {
    srand(time(NULL));
    for (int i = 0; i < TEST_CASES; i++) {
        vector<int> numbers {1, 2, 3, 4, 5, 6, 7, 8};

        random_shuffle(numbers.begin(), numbers.end());
        for (int j = 0; j < numbers.size(); j++) {
            if (rand() % 2)
                cout << "-";
            cout << numbers[j];
            if (j != numbers.size()-1)
                cout << " ";
        }
        cout << endl;
    }

    cout << 0 << endl;

    return 0;
}
