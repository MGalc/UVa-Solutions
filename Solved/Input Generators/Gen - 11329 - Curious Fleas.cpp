#include <bits/stdc++.h>

using namespace std;

static const int NUM_TEST_CASES = 100;

int main() {
    cout << NUM_TEST_CASES << endl << endl;

    for (int t = 0; t < NUM_TEST_CASES; t++) {
        vector<string> out { "....", "....", "....", "...." };
        vector<int> nums(16);
        for (int i = 0; i < 16; i++) nums[i] = i;
        
        // This means each grid square is used only once.
        random_shuffle(nums.begin(), nums.end());

        // Place the die
        out[nums[0]/4][nums[0]%4] = 'D';

        // Place in the fleas
        for (int i = 1; i <= 6; i++) 
            out[nums[i]/4][nums[i]%4] = 'X';

        // Output the lines
        for (int i = 0; i < 4; i++) {
            cout << out[i] << endl;
        }
        cout << endl;
    }
}
