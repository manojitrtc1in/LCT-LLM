#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MODVALUE 1000000007

typedef long long ll;

typedef struct {
    ll val;
} Modular;

Modular id0(ll m) {
    ll val = m;
    if (val < 0) val += MODVALUE;
    if (val >= MODVALUE) val -= MODVALUE;
    Modular result;
    result.val = val;
    return result;
}

int operator_eq(Modular m1, Modular m2) {
    return m1.val == m2.val;
}

int operator_neq(Modular m1, Modular m2) {
    return !(m1.val == m2.val);
}

Modular operator_add(Modular m1, Modular m2) {
    return id0(m1.val + m2.val);
}

Modular operator_sub(Modular m1, Modular m2) {
    return id0(m1.val - m2.val);
}

Modular operator_mul(Modular m1, Modular m2) {
    return id0(m1.val * m2.val % MODVALUE);
}

Modular operator_div(Modular m1, Modular m2) {
    return id0(m1.val * m2.val);
}

Modular operator_pow(Modular m, ll power) {
    Modular ans;
    ans.val = 1;
    while (power) {
        if (power & 1) ans = operator_mul(ans, m);
        m = operator_mul(m, m);
        power >>= 1;
    }
    return ans;
}

Modular operator_inv(Modular m) {
    return operator_pow(m, MODVALUE - 2);
}

typedef struct {
    int size;
    Modular *xp;
    Modular *hash;
} HashTable;

HashTable createHashTable(char *s, Modular m) {
    int len = strlen(s);
    HashTable table;
    table.size = len;
    table.xp = (Modular *)malloc((len + 1) * sizeof(Modular));
    table.hash = (Modular *)malloc((len + 1) * sizeof(Modular));

    table.xp[0] = id0(1);
    for (int i = 1; i <= len; i++) {
        table.xp[i] = operator_mul(table.xp[i - 1], m);
    }

    table.hash[len].val = 0;
    for (int i = len - 1; i >= 0; i--) {
        table.hash[i] = operator_add(operator_mul(table.hash[i + 1], m), s[i]);
    }

    return table;
}

Modular getHash(HashTable table, int l, int r) {
    return operator_sub(table.hash[l], operator_mul(table.hash[r + 1], table.xp[r - l + 1]));
}

int main() {
    int n;
    scanf("%d", &n);
    char t[100001];
    scanf("%s", t);

    int zp[100001];
    int zpl = 0;
    for (int i = 0; i < strlen(t); i++) {
        if (t[i] == '0') {
            zp[zpl++] = i;
        }
    }

    Modular m;
    m.val = 7;

    char s[100001];
    for (int i = 0; i < zpl; i++) {
        s[i] = '0' + (zp[i] & 1);
    }
    s[zpl] = '\0';

    HashTable hash = createHashTable(s, m);

    for (int i = 0; i < zpl; i++) {
        s[i] = '1' - (zp[i] & 1);
    }

    HashTable rhash = createHashTable(s, m);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l1, l2, len;
        scanf("%d %d %d", &l1, &l2, &len);
        l1--;
        l2--;

        int d1 = 0;
        int d2 = 0;
        for (int j = 0; j < zpl; j++) {
            if (zp[j] >= l1) {
                break;
            }
            d1++;
        }
        for (int j = 0; j < zpl; j++) {
            if (zp[j] >= l2) {
                break;
            }
            d2++;
        }

        int z1 = 0;
        int z2 = 0;
        for (int j = d1; j < zpl; j++) {
            if (zp[j] >= l1 + len) {
                break;
            }
            z1++;
        }
        for (int j = d2; j < zpl; j++) {
            if (zp[j] >= l2 + len) {
                break;
            }
            z2++;
        }

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

        if (operator_eq(hash1, hash2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
