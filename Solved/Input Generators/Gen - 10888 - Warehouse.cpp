#include <bits/stdc++.h>

using namespace std;

static const int TEST_CASES = 100;
static const int MAXH = 40;
static const int MAXW = 40;
static const int MAXBOXES = 15;

int main() {
    srand(time(NULL));
    cout << TEST_CASES << endl;

    for (int tt = 1; tt <= TEST_CASES; tt++) {
        int h = rand() % MAXH + 1, w = rand() % MAXW + 1;
        cout << h << " " << w << endl;
        int nodes = h*w;
        vector<string> output(h, "");
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                output[i] += ".";
            }
        }

        int boxes = min(nodes/4, rand()%MAXBOXES+1);
        int end = boxes;
        while (boxes) {
            int x = rand()%h, y = rand()%w;
            if (output[x][y] == '.') {
                output[x][y] = 'B';
                boxes--;
            }
        }
        while (end) {
            int x = rand()%h, y = rand()%w;
            if (output[x][y] == '.') {
                output[x][y] = 'X';
                end--;
            }
        }

        // Pretty bad logic for inserting obstacles.
        // Would need to do a BFS from all boxes to see if all ends are reachable
        // but this works for simple cases with large grids.
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (output[i][j] == '.' && rand()%5 == 0)
                    output[i][j] = '#';
            }
        }

        for (int i = 0; i < h; i++) 
            cout << output[i] << endl;
        cout << endl;
    }
}
