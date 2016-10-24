#include <bits/stdc++.h>

using namespace std;

static constexpr int maxN = 1000100;
int factors[maxN];
bitset<maxN> mprime;

int main() {
  memset(factors, 0, sizeof factors);
  
  for (int i = 2; i < maxN; i += 2)
    factors[i]++;
    
  for (int i = 3; i < maxN; i+=2) {
    if (!mprime[i]) {
      for (int j = i; j < maxN; j+=i) {
        factors[j]++;
        mprime[j] = true;
      }
    }
  }
  
  int N;
  while (cin >> N, N) {
    cout << N << " : " << factors[N] << endl;
  }
  
}
