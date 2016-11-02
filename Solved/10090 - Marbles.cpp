#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll m1, m2, GCD;
void extendedEuler(ll a, int b) {
    if (b == 0) {
        m1 = 1; m2 = 0; GCD = a;
        return;
    }
    extendedEuler(b, a%b);
    ll tmp = m2;
    m2 = m1 - m2 * (a/b);
    m1 = tmp;
}

int main() {
    ll N, n1, n2, c1, c2;
    while (cin >> N, N) {
        cin >> c1 >> n1 >> c2 >> n2;

        // Swap values just to keep the small one in front.

        extendedEuler(n1, n2);

        // GCD can't divide N means we can't create any combination of n1 and n2 to satisfy N.
        if (N % GCD != 0) {
            cout << "failed" << endl;
            continue;
        }

        // Get m1 and m2 in regards to N rather than the GCD.
        n1 /= GCD; n2 /= GCD; N /= GCD;
        m1 *= N;
        m2 *= N;

        // N = n1*m1 + n2*m2
        // cost = c1*m1 + c2*m2
        //
        // We can get combinations of all solutions by:
        // r1 = m1 + k*n2
        // r2 = m2 - k*n1
        // Which can be derived from the first equation in this comment block.
        
        // Factorising these equations we get:
        // n1*m1*(c1/n1 - c2/n2) + const
        // we need to maximise m1 whenever c2/n2 is larger than c1/n1 and vice versa.
        ll k = 0;
        if ((double)c1/n1 > (double)c2/n2) {
            // Minimise r1
            // Since r1 = m1 + k*n2
            // r2 = 0 = m1 + k*n2
            // k = -m1/n2
            k = -m1 / n2;
            if (m1 + k*n2 < 0) {
                // k wasn't rounded properly, as the result of r1 is out of range.
                // round it correctly now.
                if (m1 + (k+1)*n2 >= 0)
                    k++;
                else 
                    k++;
            }
        }
        else {
            // Minimise r2
            // Since r2 = m2 - k*n1
            // r2 = 0 = m2 - k*n1
            // k = m2/n1
            k = m2 / n1;
            if (m2 - k*n1 < 0) {
                // k wasn't rounded properly, as the result of r2 is out of range.
                // round it correctly now.
                if (m2 - (k+1)*n1 >= 0)
                    k++;   
                else
                    k--;
            }
        }

        ll r1 = m1 + k * n2, r2 = m2 - k * n1;
        if (r1 < 0 || r2 < 0)
            cout << "failed" << endl;
        else
            cout << r1 << " " << r2 << endl;
    }

    return 0;
}
