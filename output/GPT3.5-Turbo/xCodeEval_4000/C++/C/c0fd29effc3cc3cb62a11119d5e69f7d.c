#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MODVALUE 1000000007

typedef long long ll;

typedef struct {
    ll val;
} Modular;

Modular toModular(ll m) {
    ll val = m;
    if (val < 0) val += MODVALUE;
    if (val >= MODVALUE) val -= MODVALUE;
    Modular result;
    result.val = val;
    return result;
}

Modular add(Modular a, Modular b) {
    return toModular(a.val + b.val);
}

Modular subtract(Modular a, Modular b) {
    return toModular(a.val - b.val);
}

Modular multiply(Modular a, Modular b) {
    return toModular(a.val * b.val % MODVALUE);
}

Modular power(Modular a, ll p) {
    Modular m = a;
    Modular ans;
    ans.val = 1;
    while (p) {
        if (p & 1) ans = multiply(ans, m);
        m = multiply(m, m);
        p >>= 1;
    }
    return ans;
}

Modular inverse(Modular a) {
    return power(a, MODVALUE - 2);
}

typedef struct {
    int size;
    Modular *xp;
    Modular *hash;
} HashTable;

Modular getHash(HashTable *table, int l, int r) {
    if (l > r || r >= table->size) {
        printf("Invalid range\n");
        exit(1);
    }
    return subtract(table->hash[l], multiply(table->hash[r + 1], table->xp[r - l + 1]));
}

HashTable *createHashTable(char *s, Modular m) {
    int len = strlen(s);
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = len;
    table->xp = (Modular *)malloc((len + 1) * sizeof(Modular));
    table->hash = (Modular *)malloc((len + 1) * sizeof(Modular));

    table->xp[0].val = 1;
    for (int i = 1; i <= len; i++)
        table->xp[i] = multiply(table->xp[i - 1], m);

    table->hash[len].val = 0;
    for (int i = len - 1; i >= 0; i--)
        table->hash[i] = add(multiply(table->hash[i + 1], m), s[i]);

    return table;
}

int main() {
    int n;
    scanf("%d", &n);
    char t[100001];
    scanf("%s", t);

    int zp[100000];
    int zpl = 0;
    for (int i = 0; i < strlen(t); i++)
        if (t[i] == '0')
            zp[zpl++] = i;

    Modular m;
    m.val = 7;

    char s[100000];
    for (int i = 0; i < zpl; i++)
        s[i] = ('0' + zp[i] & 1);
    s[zpl] = '\0';

    HashTable *hash = createHashTable(s, m);

    for (int i = 0; i < zpl; i++)
        s[i] = ('1' - zp[i] & 1);
    s[zpl] = '\0';

    HashTable *rhash = createHashTable(s, m);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l1, l2, len;
        scanf("%d %d %d", &l1, &l2, &len);
        l1--;
        l2--;

        int d1 = 0;
        while (d1 < zpl && zp[d1] < l1)
            d1++;

        int d2 = 0;
        while (d2 < zpl && zp[d2] < l2)
            d2++;

        int z1 = 0;
        while (z1 < zpl && zp[z1] < l1 + len - 1)
            z1++;

        int z2 = 0;
        while (z2 < zpl && zp[z2] < l2 + len - 1)
            z2++;

        if (z1 != z2) {
            printf("No\n");
            continue;
        }

        if (z1 == 0) {
            printf("Yes\n");
            continue;
        }

        Modular hash1 = getHash(hash, d1, d1 + z1 - 1);
        Modular hash2 = ((l1 & 1) == (l2 & 1) ? getHash(hash, d2, d2 + z1 - 1) : getHash(rhash, d2, d2 + z1 - 1));

        printf("%s\n", (hash1.val == hash2.val) ? "Yes" : "No");
    }

    free(hash->xp);
    free(hash->hash);
    free(hash);
    free(rhash->xp);
    free(rhash->hash);
    free(rhash);

    return 0;
}
