#include <bits/stdc++.h>

using namespace std;
static const int TEST_CASES = 20;

int main() {
    srand(time(NULL));
    for (int tt = 0; tt < TEST_CASES; tt++) {
        int numBooks = rand() % 8 + 2; // From 2-9
        //int numBooks = 9;
        cout << numBooks << endl;

        vector<int> books(numBooks);
        for (int i = 0; i < books.size(); i++) 
            books[i] = i+1;

        random_shuffle(books.begin(), books.end());

        for (int i = 0; i < books.size(); i++) {
            cout << books[i];
            if (i != books.size()-1)
                cout << " ";
        }
        cout << endl;
    }
    
    cout << "0" << endl;
}
