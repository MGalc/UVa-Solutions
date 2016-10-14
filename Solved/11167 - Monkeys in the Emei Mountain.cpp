#include <bits/stdc++.h>

using namespace std;

static const int S = 0;
int T;
int N, M;
int gsize, moff, woff;
vector<vector<int>> adj;
vector<vector<int>> matrix;
vector<int> prevs;
int flow;
vector<int> vintervals;

void augment(int loc, int minflow) {
    if (loc == S) {
        flow = minflow;
        return;
    }

    if (prevs[loc] != -1) {
        minflow = min(minflow, matrix[prevs[loc]][loc]);
        augment(prevs[loc], minflow);

        matrix[prevs[loc]][loc] -= flow;
        matrix[loc][prevs[loc]] += flow;
    }
}

int edmondskarp() {
    int totalflow = 0;
    while (1) {
        queue<int> q;
        q.push(S);
        prevs.assign(gsize, -1);
        prevs[S] = S;
        flow = 0;

        bool done = false;
        while (!q.empty() && !done) {
            int top = q.front();
            q.pop();

            for (int i = 0; i < adj[top].size(); i++) {
                int next = adj[top][i];
                if (prevs[next] != -1) continue;

                if (matrix[top][next] > 0) {
                    prevs[next] = top;
                    q.push(next);

                    if (next == T) {
                        done = true;
                        break;
                    }
                }
            }
        }

        augment(T, 1e9);
        if (flow == 0) break;
        totalflow += flow;
    }

    return totalflow;
}

void output() {
    vector<vector<pair<int, int>>> nums(N);
    for (int i = 0; i < vintervals.size()-1; i++) {
        int wloc = i + woff;
        int curloc = 0;
        for (int j = 0; j < N; j++) {
            int val = matrix[wloc][j+moff];
            if (val <= 0) continue;
            int start = vintervals[i], last = vintervals[i+1];

            if (start + curloc == last) curloc = 0;
            if (val == last - start) {
                nums[j].push_back(make_pair(start, last));
            }
            else if (start + val + curloc > last) {
                nums[j].push_back(make_pair(start + curloc, last));
                curloc = start + val - (last - curloc);
                nums[j].push_back(make_pair(start, start + curloc));
            }
            else if (start + val == last) {
                nums[j].push_back(make_pair(start + curloc, last));
                curloc = start;
            }
            else {
                nums[j].push_back(make_pair(start + curloc, start + val + curloc));
                curloc += val;
            }
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        sort(nums[i].begin(), nums[i].end());
    }

    for (int i = 0; i < nums.size(); i++) {
        string out;
        int counter = 0;
        int firstval = -1, lastval = -1;
        for (int j = 0; j < nums[i].size(); j++) {
            if (lastval == -1) {
                firstval = nums[i][j].first;
                lastval = nums[i][j].second;
                if (j == nums[i].size()-1) {
                    out += " (" + to_string(firstval) + "," + to_string(lastval) + ")";
                    counter++;
                    break;
                }
                continue;
            }

            if (nums[i][j].first == lastval) {
                lastval = nums[i][j].second;
                if (j == nums[i].size()-1) {
                    out += " (" + to_string(firstval) + "," + to_string(lastval) + ")";
                    counter++;
                    break;
                }
            }
            else {
                out += " (" + to_string(firstval) + "," + to_string(lastval) + ")";
                counter++;
                firstval = nums[i][j].first;
                lastval = nums[i][j].second;
            }

            if (j == nums[i].size()-1) {
                out += " (" + to_string(firstval) + "," + to_string(lastval) + ")";
                counter++;
                break;
            }
        }
        cout << counter << out << endl;
    }
}

int main() {
    int casenum = 1;
    while (cin >> N, N) {
        cin >> M;
        cout << "Case " << casenum++ << ": ";

        int totaldrinks = 0;
        set<int> intervals;
        vector<pair<int, int>> mintervals;
        vector<int> mvals(N);
        for (int i = 0; i < N; i++) {
            int v, x, y;
            cin >> v;
            mvals[i] = v;
            totaldrinks += v;
            cin >> x >> y;
            mintervals.push_back(make_pair(x, y));
            intervals.insert(x);
            intervals.insert(y);
        }

        gsize = N + intervals.size() + 2 - 1;
        moff = 1;
        woff = moff + N;
        T = gsize - 1;

        adj.assign(gsize, vector<int>());
        matrix.assign(gsize, vector<int>(gsize, 0));

        // s to m
        for (int i = 0; i < N; i++) {
            adj[S].push_back(i + moff);
            adj[i + moff].push_back(S);
            matrix[S][i+moff] = mvals[i];
        }

        // m to w
        vintervals = vector<int>(intervals.begin(), intervals.end());
        for (int i = 0; i < N; i++) {
            int mini = mintervals[i].first, maxi = mintervals[i].second;
            auto loc = lower_bound(vintervals.begin(), vintervals.end(), mini);
            int indx = (int)(loc - vintervals.begin());

            do {
                adj[i + moff].push_back(woff + indx);
                adj[woff + indx].push_back(i + moff);
                matrix[i + moff][woff + indx] = vintervals[indx + 1] - vintervals[indx];
                indx++;
            } while (indx != vintervals.size()-1 && vintervals[indx] < maxi); // CHECK: Might be < or <=
        }

        // w to t
        for (int i = 0; i < vintervals.size()-1; i++) {
            adj[woff + i].push_back(T);
            adj[T].push_back(woff + i);
            matrix[woff + i][T] = M * (vintervals[i+1] - vintervals[i]);
        }

        int totalflow = edmondskarp();

        //output 
        if (totaldrinks == totalflow) {
            cout << "Yes" << endl;
            output();
        }
        else {
            cout << "No" << endl;
        }
    }
}
