#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

#define MAXN 101
#define MAXV 1001

int nA, nB, nV, mx = 0, cans;
int d[MAXN][MAXN][MAXN], prefix[MAXN][MAXV];
int c[MAXN][MAXN][MAXN];

char A[MAXN], B[MAXN], V[MAXN];
char ans[MAXN];
int ans_size = 0;

void solve() {
    scanf("%s %s %s", A, B, V);
    nA = strlen(A);
    nB = strlen(B);
    nV = strlen(V);
    
    for (int iV = 0; iV < nV; iV++) {
        for (char C = 'A'; C <= 'Z'; C++) {
            prefix[iV][C] = iV + 1;
            while (prefix[iV][C] > 0) {
                if (strncmp(V + 1, V + (iV + 2 - prefix[iV][C]), prefix[iV][C] - 1) == 0 && V[iV + 1] == C) {
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
                if (A[iA - 1] == B[iB - 1]) {
                    if (d[iA][iB][prefix[iV][A[iA - 1]]] < d[iA - 1][iB - 1][iV] + 1) {
                        d[iA][iB][prefix[iV][A[iA - 1]]] = d[iA - 1][iB - 1][iV] + 1;
                        c[iA][iB][prefix[iV][A[iA - 1]]] = iV;
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
                ans[ans_size++] = A[iA - 1];
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

void prep() {
    // Preparation code if needed
}

int main() {
    prep();
    int test_num;
    scanf("%d", &test_num);
    for (int test_count = 1; test_count <= test_num; test_count++) {
        solve();
    }
    return 0;
}
