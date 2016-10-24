#include <bits/stdc++.h>

using namespace std;
int factnums[1001];

void calc() {
  for (int i = 1; i <= 1000; i++) {
    int sqi = sqrt(i);
    int sum = 0;
    for (int j = 1; j <= sqi; j++) {
      if (i % j == 0) {
        if (j*j == i)
          sum += j;
        else
          sum += j + (i / j);
      }
    }
    if (sum <= 1000)
      factnums[sum] = i;
  }
}

int main() {
  int casenum = 1;
  memset(factnums, -1, sizeof factnums);
  calc();
  int N;
  while (cin >> N, N) {
    cout << "Case " << casenum++ << ": " << factnums[N] << endl;
  }
}

