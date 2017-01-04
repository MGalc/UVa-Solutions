#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

// Overengineered to hell but I just wanted to get tries working with this solution for practice.
// Can be solved with simple backtracking/dp.

vector<vector<char>> grid;
vector<vector<int>> trie;
vector<char> origchar;
static const vector<int> scores { 0, 0, 0, 1, 1, 2, 3, 5, 11, 11, 11, 11, 11, 11, 11, 11, 11 };

void trieinsert(string& str) {
    int graphIndex = 0;
    for (const char c : str) {
        bool assigned = false;
        for (int i = 0; i < trie[graphIndex].size(); i++) {
            if (origchar[trie[graphIndex][i]] == c) { // The character already exists.
                graphIndex = trie[graphIndex][i];
                assigned = true;
                break;
            }
        }
        if (!assigned) { // We are adding a new branch.
            origchar.push_back(c);
            trie[graphIndex].push_back(trie.size());
            trie.push_back(vector<int>());
            graphIndex = trie.size()-1;
        }
    }

    // Add leaf identifier.
    trie[graphIndex].push_back(-(scores[str.size()]));
}

vector<int> xch {1, -1, 0, 0, 1, 1, -1, -1};
vector<int> ych {0, 0, 1, -1, 1, -1, 1, -1};
vector<vector<bool>> visited;
int dfs(int x, int y, int trieindx) {

    int points = 0;
    bool haschildren = false;
    for (int i = 0; i < trie[trieindx].size(); i++) {
        if (trie[trieindx][i] < 0) {
            points += -trie[trieindx][i];
            trie[trieindx][i] = 0; // Don't give any more points for this word find.
        }
        if (origchar[trie[trieindx][i]] > 0)
            haschildren = true;
    }

    // There's no more paths here. Just return.
    // This causes a large reduction in run time.
    if (!haschildren) {
        origchar[trieindx] = 0;
        return points;
    }

    for (int i = 0; i < xch.size(); i++) {
        int nextx = x + xch[i];
        int nexty = y + ych[i];

        // If the next tile is out of bounds or visited
        if (nextx < 0 || nextx >= 4 || nexty < 0 || nexty >= 4 || visited[nextx][nexty]) continue;

        for (int j = 0; j < trie[trieindx].size(); j++) {
            if (origchar[trie[trieindx][j]] == grid[nextx][nexty] && origchar[trie[trieindx][j]] != 0) {
                visited[nextx][nexty] = true;
                points += dfs(nextx, nexty, trie[trieindx][j]);
                visited[nextx][nexty] = false;
            }
        }
    }
    return points;
}

int main() {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        cout << "Score for Boggle game #" << tt << ": ";

        trie.assign(1, vector<int>());
        origchar.assign(1, 0);

        grid.assign(4, vector<char>(4));
        for (int i = 0; i < 4; i++) {
            string in;
            cin >> in;
            for (int j = 0; j < 4; j++)
                grid[i][j] = in[j];
        }

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string in;
            cin >> in;
            if (in.size() <= 16)
                trieinsert(in);
        }

        visited.assign(4, vector<bool>(4, false));

        int totalpoints = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < trie[0].size(); k++) {
                    if (origchar[trie[0][k]] == grid[i][j]) {
                        visited[i][j] = true;
                        totalpoints += dfs(i, j, trie[0][k]);
                        visited[i][j] = false;
                        break;
                    }
                }
            }
        }

        cout << totalpoints << endl;
    }

    return 0;
}
