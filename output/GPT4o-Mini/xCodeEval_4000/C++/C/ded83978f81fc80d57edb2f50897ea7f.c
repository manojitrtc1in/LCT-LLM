#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 101
#define MAXV 1001

unsigned long long pow2(int n) { return 1llu << n; }
unsigned long long pow10(int n) { unsigned long long T = 1; for (int i = 1; i <= n; i++) T *= 10; return T; }
unsigned long long pow(int b, int n) { unsigned long long T = 1; for (int i = 1; i <= n; i++) T *= b; return T; }
unsigned long long factorial(int n) { unsigned long long T = 1; for (int i = 2; i <= n; i++) T *= i; return T; }
unsigned long long permutation(int n, int r) { unsigned long long T = 1; for (int i = n - r + 1; i <= n; i++) T *= i; return T; }
unsigned long long combination(int n, int r) { unsigned long long T = permutation(n, r); for (int i = 2; i <= r; i++) T /= i; return T; }
int get_digit(unsigned long long n, int d) { return (n / pow10(d)) % 10; }
int eq(double a, double b) { return fabs(a - b) <= 0.00000001; }

int nA, nB, nV, mx = 0, cans, d[MAXN][MAXN][MAXN], prefix[MAXN][MAXV];
int c[MAXN][MAXN][MAXN];

char A[MAXN], B[MAXN], V[MAXN];
char ans[MAXN];
int ans_size = 0;

void solve() {
    scanf("%s %s %s", A + 1, B + 1, V + 1);
    nA = strlen(A + 1);
    nB = strlen(B + 1);
    nV = strlen(V + 1);
    A[0] = '#'; A[nA + 1] = '#';
    B[0] = '#'; B[nB + 1] = '#';
    V[0] = '#'; V[nV + 1] = '#';

    for (int iV = 0; iV < nV; iV++) {
        for (char C = 'A'; C <= 'Z'; C++) {
            prefix[iV][C] = iV + 1;
            while (prefix[iV][C] > 0) {
                if (strncmp(V + 1, V + iV + 2 - prefix[iV][C], prefix[iV][C] - 1) == 0 && V[iV + 2 - prefix[iV][C] + prefix[iV][C] - 1] == C) {
                    break;
                }
                prefix[iV][C]--;
            }
        }
    }

    for (int iA = 1; iA <= nA; iA++) {
        for (int iB = 1; iB <= nB; iB++) {
            for (int iV = 0; iV < nV; iV++) {
                d[iA][iB][iV] = -1;
                if (d[iA][iB][iV] < d[iA - 1][iB][iV]) {
                    d[iA][iB][iV] = d[iA - 1][iB][iV];
                    c[iA][iB][iV] = -1;
                }
                if (d[iA][iB][iV] < d[iA][iB - 1][iV]) {
                    d[iA][iB][iV] = d[iA][iB - 1][iV];
                    c[iA][iB][iV] = -2;
                }
            }
            for (int iV = 0; iV < nV; iV++) {
                if (A[iA] == B[iB]) {
                    if (d[iA][iB][prefix[iV][A[iA]]] < d[iA - 1][iB - 1][iV] + 1) {
                        d[iA][iB][prefix[iV][A[iA]]] = d[iA - 1][iB - 1][iV] + 1;
                        c[iA][iB][prefix[iV][A[iA]]] = iV;
                    }
                }
            }
        }
    }

    for (int iV = 0; iV < nV; iV++) {
        if (mx < d[nA][nB][iV]) {
            mx = d[nA][nB][iV];
            cans = iV;
        }
    }

    if (mx == 0) {
        printf("0\n");
    } else {
        int iA = nA, iB = nB, iV = cans;
        while (iA > 0 && iB > 0) {
            if (c[iA][iB][iV] == -1) {
                iA--;
            } else if (c[iA][iB][iV] == -2) {
                iB--;
            } else {
                ans[ans_size++] = A[iA];
                iV = c[iA][iB][iV];
                iA--;
                iB--;
            }
        }
    }

    for (int i = ans_size - 1; i >= 0; i--) {
        printf("%c", ans[i]);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}
