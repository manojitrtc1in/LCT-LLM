#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 20
#define MAX_BITMASK (1 << MAX_N)
#define INF 1000000000

typedef long long ll;

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int bitCount(unsigned x) {
    int count = 0;
    while (x > 0) {
        if (x & 1) {
            count++;
        }
        x >>= 1;
    }
    return count;
}

int isSet(unsigned mask, int bit) {
    return (mask >> bit) & 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    ll a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    // Sort the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                ll temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    int d[MAX_N] = {0};
    for (int i = 0; i < n; i++) {
        ll c = a[i];
        for (ll j = 2; j * j <= c; j++) {
            while (c % j == 0) {
                d[i]++;
                c /= j;
            }
        }
        if (c != 1) {
            d[i]++;
        }
    }
    
    int reachable[MAX_BITMASK] = {INF};
    reachable[0] = 0;
    
    for (int i = 0; i < n; i++) {
        for (unsigned j = 0; j < (1 << i); j++) {
            ll rem = a[i];
            bool good = true;
            for (int k = 0; k < i; k++) {
                if (isSet(j, k)) {
                    if (rem % a[k] != 0) {
                        good = false;
                        break;
                    }
                    rem /= a[k];
                }
            }
            int qty = 0;
            for (ll c = 2; c * c <= rem; c++) {
                while (rem % c == 0) {
                    qty++;
                    rem /= c;
                }
            }
            if (rem != 1) {
                qty++;
            }
            int lim;
            if (i == 0) {
                lim = 0;
            } else {
                lim = 1 << (i - 1);
            }
            if (good) {
                for (unsigned k = 0; k < (1 << i); k++) {
                    if ((j & k) == 0 && reachable[j + k] != INF && j + k >= lim) {
                        reachable[(1 << i) + k] = min(reachable[(1 << i) + k], reachable[j + k] + qty + (d[i] == 1 ? 0 : 1));
                    }
                }
            }
        }
    }
    
    int answer = INF;
    for (unsigned i = (1 << (n - 1)); i < (1 << n); i++) {
        if (reachable[i] != 0) {
            answer = min(answer, reachable[i] + (bitCount(i) == 1 ? 0 : 1));
        }
    }
    
    printf("%d\n", answer);
    
    return 0;
}
