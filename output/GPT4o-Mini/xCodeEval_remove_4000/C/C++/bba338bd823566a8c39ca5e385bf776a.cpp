#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int A = /* define A */;
const int B = /* define B */;
const int P = /* define P */;
const int PMAX = /* define PMAX */;
const long long L1 = /* define L1 */;
const long long P3 = /* define P3 */;

int a[A + 1];
unsigned int b[B] = {
    0, 5761455, 11078937, 16252325, 21336326, 26355867, 31324703, 36252931, 41146179, 46009215,
    // ... (rest of the array values)
    4114105592
};
int p[P];
long long y[P];

int main() {
    long long n, n2, n3, bl, bh, ans = 0, k, kl, kh;
    int i, j, b1 = -1, b2, q2, c;

    cin >> n;

    p[0] = 2; 
    k = 1;
    for (i = 3; i <= PMAX; i += 2) {
        if (a[i] == 0) {
            p[k++] = i;
            if (i <= PMAX / i)
                for (j = i * i; j <= PMAX; j += i) 
                    a[j] = 1;
        }
    }

    for (i = 0; i < P; i++) {
        n2 = n / p[i];
        if (n2 == 0 || n2 < p[i]) break;
        b2 = (int)(n2 / A); 
        q2 = n2 % A;
        if (b1 != b2) {
            memset(a, 0, sizeof(a));
            b1 = b2;
            bl = 1ll * b1 * A;
            bh = bl + q2 + 1;
            c = (b1 == 0 ? 1 : 0);
            y[0] = -1;
            for (j = 1; j < P; j++) {
                y[j] = max(bl / p[j] * p[j] + p[j], 1ll * p[j] * p[j]) - bl;
                if ((y[j] & 1) == 0) y[j] += p[j];
            }
            for (kl = bl; kl < bh; kl += L1) {
                kh = min(kl + L1, bh) - bl;
                for (j = 1; j < P; j++) {
                    for (k = y[j]; k < kh; k += 2ll * p[j]) 
                        a[k] = 1;
                    y[j] = k;
                }
                if (kl == 0) {
                    k = 3;
                    a[2] = 1;
                } else {
                    k = kl - bl + 1;
                }
                for (; k < kh; k += 2)
                    a[k] = a[k + 1] = (a[k] == 0 ? ++c : c);
            }
        } 

        ans = ans + b[b1] + a[q2] - (i + 1);
    }

    i = 0; 
    j = P;
    for (;;) {
        k = i + (j - i) / 2;
        if (k == i)
            break;
        if (p[k] > P3)
            n3 = n + 1;
        else
            n3 = (long long)p[k] * p[k] * p[k];
        if (n3 > n)
            j = (int)k;
        else if (n3 < n)
            i = (int)k;
        else 
            break;
    }
    if (p[k] * p[k] * p[k] <= n)
        ans += k + 1;

    cout << ans << endl;
    return 0;
}
