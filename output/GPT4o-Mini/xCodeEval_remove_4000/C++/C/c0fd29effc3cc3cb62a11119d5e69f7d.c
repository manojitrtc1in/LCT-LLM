#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MOD 1000000007

typedef long long ll;
typedef struct {
    ll val;
} Mint;

Mint id0(ll m) {
    if (m < 0) m += MOD;
    if (m >= MOD) m -= MOD;
    Mint result = {m};
    return result;
}

bool operator_eq(Mint a, Mint b) {
    return a.val == b.val;
}

Mint operator_add(Mint a, Mint b) {
    return id0(a.val + b.val);
}

Mint operator_mul(Mint a, Mint b) {
    return id0(a.val * b.val % MOD);
}

Mint operator_pow(Mint base, ll exp) {
    Mint result = {1};
    while (exp) {
        if (exp & 1) result = operator_mul(result, base);
        base = operator_mul(base, base);
        exp >>= 1;
    }
    return result;
}

typedef struct {
    int size;
    Mint *xp;
    Mint *hash;
} HashTable;

Mint getHash(HashTable *ht, int l, int r) {
    assert(l <= r && r < ht->size);
    return operator_add(ht->hash[l], operator_mul(ht->hash[r + 1], operator_pow(ht->xp[r - l + 1], MOD - 2)));
}

HashTable createHashTable(char *s, Mint m) {
    int len = strlen(s);
    HashTable ht;
    ht.size = len;
    ht.xp = (Mint *)malloc((len + 1) * sizeof(Mint));
    ht.hash = (Mint *)malloc((len + 1) * sizeof(Mint));

    ht.xp[0] = (Mint){1};
    for (int i = 1; i <= len; i++)
        ht.xp[i] = operator_mul(ht.xp[i - 1], m);

    ht.hash[len] = (Mint){0};
    for (int i = len - 1; i >= 0; i--)
        ht.hash[i] = operator_add(operator_mul(ht.hash[i + 1], m), (Mint){s[i]});
    
    return ht;
}

ll mul[] = {7, 11, 13, 17, 19};

int main() {
    int n;
    scanf("%d", &n);
    char t[100000];
    scanf("%s", t);

    int zp[100000], zpl = 0;
    for (int i = 0; i < strlen(t); i++)
        if (t[i] == '0')
            zp[zpl++] = i;

    Mint m = {mul[rand() % 5]};

    char s[100000];
    for (int i = 0; i < zpl; i++)
        s[i] = '0' + (zp[i] & 1);

    HashTable hash = createHashTable(s, m);

    for (int i = 0; i < zpl; i++)
        s[i] = '1' - (zp[i] & 1);

    HashTable rhash = createHashTable(s, m);

    for (int q = 0; q < n; q++) {
        int l1, l2, len;
        scanf("%d %d %d", &l1, &l2, &len);
        l1--; l2--;

        int d1 = 0, d2 = 0;
        while (d1 < zpl && zp[d1] < l1) d1++;
        while (d2 < zpl && zp[d2] < l2) d2++;

        int z1 = 0, z2 = 0;
        while (d1 + z1 < zpl && zp[d1 + z1] <= l1 + len - 1) z1++;
        while (d2 + z2 < zpl && zp[d2 + z2] <= l2 + len - 1) z2++;

        if (z1 != z2) {
            printf("No\n");
            continue;
        }

        if (z1 == 0) {
            printf("Yes\n");
            continue;
        }

        Mint hash1 = getHash(&hash, d1, d1 + z1 - 1);
        Mint hash2 = ((l1 & 1) == (l2 & 1)) ? getHash(&hash, d2, d2 + z1 - 1) : getHash(&rhash, d2, d2 + z1 - 1);

        printf("%s\n", operator_eq(hash1, hash2) ? "Yes" : "No");
    }

    free(hash.xp);
    free(hash.hash);
    free(rhash.xp);
    free(rhash.hash);

    return 0;
}
