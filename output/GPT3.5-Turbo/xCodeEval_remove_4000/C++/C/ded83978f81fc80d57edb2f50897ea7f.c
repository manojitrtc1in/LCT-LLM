#include <stdio.h>
#include <string.h>

#define max_set(a, b) ((a) = ((a) > (b) ? (a) : (b)))

int nA, nB, nV, len, mx = 0, cans;
int d[101][101][101], prefix[101][1001];
int c[101][101][101];

char A[101], B[101], V[101], t[101];

void solve()
{
    scanf("%s %s %s", A, B, V);
    nA = strlen(A);
    nB = strlen(B);
    nV = strlen(V);

    for (int iV = 0; iV < nV; iV++)
    {
        for (char C = 'A'; C <= 'Z'; C++)
        {
            prefix[iV][C] = iV + 1;
            while (prefix[iV][C] > 0)
            {
                if (strncmp(V + 1, V + iV + 2 - prefix[iV][C], prefix[iV][C] - 1) == 0 && V[iV + 1] == C)
                {
                    break;
                }
                prefix[iV][C]--;
            }
        }
    }

    for (int iA = 1; iA <= nA; iA++)
    {
        for (int iB = 1; iB <= nB; iB++)
        {
            for (int iV = 0; iV < nV; iV++)
            {
                d[iA][iB][iV] = -1;
                if (d[iA - 1][iB][iV] > d[iA][iB][iV])
                {
                    d[iA][iB][iV] = d[iA - 1][iB][iV];
                    c[iA][iB][iV] = -1;
                }
                if (d[iA][iB - 1][iV] > d[iA][iB][iV])
                {
                    d[iA][iB][iV] = d[iA][iB - 1][iV];
                    c[iA][iB][iV] = -2;
                }
            }
            for (int iV = 0; iV < nV; iV++)
            {
                if (A[iA - 1] == B[iB - 1])
                {
                    if (d[iA - 1][iB - 1][iV] + 1 > d[iA][iB][prefix[iV][A[iA - 1]]])
                    {
                        d[iA][iB][prefix[iV][A[iA - 1]]] = d[iA - 1][iB - 1][iV] + 1;
                        c[iA][iB][prefix[iV][A[iA - 1]]] = iV;
                    }
                }
            }
        }
    }

    for (int iV = 0; iV < nV; iV++)
    {
        if (d[nA][nB][iV] > mx)
        {
            mx = d[nA][nB][iV];
            cans = iV;
        }
    }

    if (mx == 0)
    {
        printf("0\n");
    }
    else
    {
        int iA = nA, iB = nB, iV = cans;
        while (iA > 0 && iB > 0)
        {
            if (c[iA][iB][iV] == -1)
            {
                iA--;
            }
            else if (c[iA][iB][iV] == -2)
            {
                iB--;
            }
            else
            {
                t[mx - 1] = A[iA - 1];
                iV = c[iA][iB][iV];
                iA--;
                iB--;
                mx--;
            }
        }
        printf("%s\n", t);
    }
}

int main()
{
    solve();
    return 0;
}
