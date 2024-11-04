#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int nA, nB, nV, len, mx = 0, cans;
int d[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int prefix[MAX_SIZE][MAX_SIZE];
int c[MAX_SIZE][MAX_SIZE][MAX_SIZE];

char A[MAX_SIZE], B[MAX_SIZE], V[MAX_SIZE], t[MAX_SIZE];

void solve() {
    scanf("%s %s %s", A + 1, B + 1, V + 1);
    nA = strlen(A + 1);
    nB = strlen(B + 1);
    nV = strlen(V + 1);
    A[0] = '#';
    B[0] = '#';
    V[0] = '#';
    A[nA + 1] = '#';
    B[nB + 1] = '#';
    V[nV + 1] = '#';
    for (int iV = 0; iV < nV; iV++) {
        for (char C = 'A'; C <= 'Z'; C++) {
            prefix[iV][C] = iV + 1;
            while (prefix[iV][C] > 0) {
                if (strncmp(V + 1, V + iV + 2 - prefix[iV][C], prefix[iV][C] - 1) == 0 && V[iV + 1] == C) {
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
                if (d[iA - 1][iB][iV] > d[iA][iB][iV]) {
                    d[iA][iB][iV] = d[iA - 1][iB][iV];
                    c[iA][iB][iV] = -1;
                }
                if (d[iA][iB - 1][iV] > d[iA][iB][iV]) {
                    d[iA][iB][iV] = d[iA][iB - 1][iV];
                    c[iA][iB][iV] = -2;
                }
            }
            for (int iV = 0; iV < nV; iV++) {
                if (A[iA] == B[iB]) {
                    if (d[iA - 1][iB - 1][iV] + 1 > d[iA][iB][prefix[iV][A[iA]]]) {
                        d[iA][iB][prefix[iV][A[iA]]] = d[iA - 1][iB - 1][iV] + 1;
                        c[iA][iB][prefix[iV][A[iA]]] = iV;
                    }
                }
            }
        }
    }
    for (int iV = 0; iV < nV; iV++) {
        if (d[nA][nB][iV] > mx) {
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
                t[mx--] = A[iA];
                iV = c[iA][iB][iV];
                iA--;
                iB--;
            }
        }
        for (int i = 1; i <= cans; i++) {
            printf("%c", t[i]);
        }
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}
