#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

const int pr[8] = {2, 3, 5, 7, 11, 13, 17, 19};
const int num[100][2] = {
    {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7},
    {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7},
    {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7},
    {6, 0}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7}, {7, 0}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6}, {7, 7}, {7, 8},
    {8, 1}, {8, 3}, {8, 4}, {8, 5}, {8, 6}, {8, 7}, {8, 8}, {8, 9}, {9, 3}, {9, 5}, {9, 6}, {9, 7}, {9, 8}, {9, 9}, {9, 10},
    {10, 7}
};

int L[300][100];
int ans[300][300];
int cnt = 0;

void init(int i, int x, int la, int v[100]) {
    memcpy(L[cnt], v, sizeof(int) * 100);
    cnt++;
    int sz = 0;
    while (v[sz] != 0) {
        sz++;
    }
    v[sz] = 0;
    for (int d = 1; d <= la && (x /= pr[i]); d++) {
        v[sz]++;
        init(i + 1, x, d, v);
    }
    v[sz] = 0;
}

int mp[MAX + 1];

int get(int x) {
    int v[100];
    int sz = 0;
    while (x > 1) {
        int p = mp[x];
        int c = 0;
        while (x % p == 0) {
            x /= p;
            c++;
        }
        v[sz++] = -c;
    }
    qsort(v, sz, sizeof(int), cmp);
    for (int i = 0; i < sz; i++) {
        v[i] *= -1;
    }
    int l = 0, r = cnt - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int cmp = memcmp(L[mid], v, sizeof(int) * sz);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    char s[] = "(:LW:LYL]Uee1CUCUb]eCUUdU:L]L]iegUceib]jjfCUaUcegUccb]jjUd`L]h]jlUeeceliejfCUL]]L\\cUdUcbCUb]jh]d]k]eZUe]kmejjkL]]k]keeCUUdU]ZUce]dUeeeL\\cCTSUZT[(:L(:L:LZUc^1CQCUL\\_CSUZP:LYL]UdCUUdUL]]]1CUCUUdCUUUL]]ZU\\:L]L]]gUccUdjUd]1CRL[YLUSUZUUICUL]]L\\[]b\\bCUb]eUd]]`L[]b]cc_CSUZT[CUUb\\ZUcc`LUQCKCTCLG1C'1C1CRL[V(:H:LCTW:JLRG1CQCUL\\:LL\\LCUUU(:L:LL\\:LLLCUURLT1CUCUU`L[[L\\cL\\U(:ICSQCLJLRLL@:LCUUCTSUZTZ:LZU]L\\UUXCSUZU[[W:JLRKS:LLZTRL[[XCLH:B:K:C?1@'1@1C:LL&(:(:ICL(::K:/1C1CRLP:JLRICSSP(:H:JLP:JJICSS:KG1CQCSU:LLJLURLSN(:1CC1BJ:K:JI(:ICSQCKCTCL@:LCTYLSST1CCTCTLL(::K:C@:JLCK:LLL1BJ(98:@9A(9/(80:9CC/ 1'1@:C 11B18(:0:ICG1ACI@:JJI/1@1ACG1AA@:JJ1B@(:H:JL1CCACLICJG 1(::(9A1B1A@/1@:JH:B:K:C91C:KQCJJK8::K:KCC/11B1:91AC:B1CCC(9A 0/181:(A/(8099BA/ 0'109? /1728(90:9B/11B18:::A/1819B/1118::9198(:0::G1AA1BJ1B:/ /(86(1/1711)/10::(98:@9@A1A:C1B::B89:@:AAA/01708A19@991AA@(1/ '/08AGJ8'A019:B8&)/(018&'(.+A/2819:8(09(A191J8(A09:8(0(A19288A/1819@(8889A8918&('0/ (((0((";
    int i = 0, j = 1;
    for (int c = 0; s[c] != '\0'; c++) {
        for (int t = 0; t < 2; t++) {
            int x = num[s[c] - 32][t];
            ans[i][j] = ans[j][i] = x;
            if (++j == cnt) {
                j = ++i + 1;
            }
        }
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", ans[get(a)][get(b)]);
    }
    return 0;
}
