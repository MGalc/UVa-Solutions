#include <bits/stdc++.h>

using namespace std;
string sufstr;
vector<int> SA;
vector<int> pos;
int sufgap;
string A, B;

bool sufcmp(int a, int b) {
    if (pos[a] != pos[b])
        return (pos[a] < pos[b]);

    a += sufgap;
    b += sufgap;

    return (a >= sufstr.size() && b >= sufstr.size()) ? a < b : pos[a] < pos[b];
}

void buildSA() {
    SA.assign(sufstr.size(), 0);
    pos.assign(sufstr.size(), 0);
    for (int i = 0; i < sufstr.size(); i++) {
        SA[i] = i;
        pos[i] = sufstr[i];
    }

    sufgap = 1;
    vector<int> tmp(sufstr.size());
    while (sufstr.size() > sufgap + sufgap) {
        sort(SA.begin(), SA.end(), sufcmp);

        tmp[0] = 0;
        for (int i = 0; i < tmp.size()-1; i++)
            tmp[i+1] = tmp[i] + sufcmp(SA[i], SA[i+1]);

        for (int i = 0; i < pos.size(); i++)
            pos[SA[i]] = tmp[i];

        if (tmp[tmp.size()-1] == tmp.size()-1) break;
    }
}

void printLongestSubstr() {
    int start = 2, end = 2; // skip # and $
    int maximum = 0, indx = 0;
    vector<string> best;
    int founda = 0, foundb = 0;
    int asize = A.size() + 1;
    int alast = 0, blast = 0;
    while (end <= SA.size()) {
        if (founda && foundb) {
            int common = 0;
            while (sufstr[common + SA[alast]] == sufstr[common + SA[blast]] && common < sufstr.size() - SA[alast] && common < sufstr.size() - SA[blast])
                common++;
            if (common > maximum) {
                best.clear();
                maximum = common;
                indx = start;
            }

            if (common == maximum && common > 0) {
                if (best.empty() || sufstr.substr(SA[alast], common) != best[best.size()-1])
                    best.push_back(sufstr.substr(SA[alast], common));
            }

            (SA[start] >= asize) ? foundb-- : founda--;
            start++;
        }
        else {
            if (SA[end] >= asize) {
                foundb++;
                blast = end;
            }
            else {
                founda++;
                alast = end;
            }
            end++;
        }
    }

    if (best.empty()) 
        cout << "No common sequence." << endl;
    else for (string s : best)
        cout << s << endl;
}

int main() {
    bool first = true;
    while (cin >> A >> B) {
        if (first) first = false;
        else cout << endl;
        sufstr = A + "#" + B + '$';

        buildSA();
        printLongestSubstr();
    }

    return 0;
}
