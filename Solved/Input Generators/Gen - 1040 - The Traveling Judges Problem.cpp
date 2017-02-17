#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>

using namespace std;

static const int TEST_CASES = 500;
static const int MAX_CITIES = 10;

int main() {
    srand(time(NULL));

    for (int tt = 0; tt < TEST_CASES; tt++) {
        if (tt != 0) cout << endl;

        cout << MAX_CITIES << endl;
        cout << rand()%MAX_CITIES + 1 << endl;
        cout << (MAX_CITIES*(MAX_CITIES-1))/2 << endl;

        for (int i = 1; i <= MAX_CITIES; i++) {
            for (int j = i+1; j <= MAX_CITIES; j++) {
                cout << i << " " << j << " " << rand()%11+1 << endl;
            }
        }

        set<int> judges;
        for (int i = 0; i < MAX_CITIES/2+1; i++) {
            judges.insert(rand()%MAX_CITIES + 1);
        }

        cout << judges.size() << endl;

        for (auto it = judges.begin(); it != judges.end(); it++) {
            if (it != judges.begin()) cout << " ";
            cout << *it;
        }
        cout << endl;
    }

    cout << -1 << endl;
}
