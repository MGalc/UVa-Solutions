#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
static constexpr int maxN = 1000100;
int mu[maxN];
int M[maxN];
bitset<maxN> composite;

int main() {
  for (int i = 0; i < maxN; i++) mu[i]=1;
  for (ll i = 2; i < maxN; i++) {
    if (!composite[i]) {
      for (int j = i; j < maxN; j+=i) {
        composite[j] = true;
        mu[j] = -mu[j];
      }
      ll next = i*i;
      for (ll j = next; j < maxN; j+=next) {
        mu[j] = 0;
      }
    }
  }
  
  //memset(M, 0, sizeof M);
  M[1] = 1;
  for (int i = 2; i < maxN; i++) {
    M[i] = M[i-1] + mu[i];
  }

  int N;
  while (cin >> N, N) {
    cout << setw(8) << N <<  setw(8) << mu[N] << setw(8) << M[N] << endl;
  }
}

