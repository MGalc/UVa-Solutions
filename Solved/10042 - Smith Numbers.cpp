#include <bits/stdc++.h>

using namespace std;
static const int MAXN = 40000;
vector<int> primes;
vector<bool> isPrime;

void generatePrimes() {
  for (int i = 4; i < MAXN; i += 2)
    isPrime[i] = false;
  primes.push_back(2);
    
  for (int k = 3; k < MAXN; k += 2) {
    if (!isPrime[k]) continue;
    primes.push_back(k);
    
    for (int i = k+k; i < MAXN; i += k)
      isPrime[i] = false;
    }
}

int sumdigits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main() {
  isPrime.assign(MAXN, true);
  isPrime[1] = false;
  isPrime[0] = false;
  
  generatePrimes();
  
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    int N;
    cin >> N;
    
    bool done = false;
    int nexthighest = N;
    while (!done) {
      nexthighest = nexthighest+1;
      int sum = 0;
      bool numprime = true;
      int n = nexthighest;
      int sq = sqrt(n);
      for (int i = 0; i < primes.size() && primes[i] <= sq; i++) {
        while (n % primes[i] == 0) {
          numprime = false;
          sum += sumdigits(primes[i]);
          n /= primes[i];
          sq = sqrt(n);
        }
      }
      if (numprime) continue;
      if (n > 2) {
        sum += sumdigits(n);
      }
      
      int numsum = sumdigits(nexthighest);
      if (numsum == sum) {
        done = true;
      }
    }
    
    cout << nexthighest << endl;
  }

  return 0;
}

