#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define INF 2147483647
#define MOD 1000000007
#define MAX_LEN 100000

typedef long long ll;
typedef struct {
    ll val;
} Mint;

Mint toModular(ll m) {
    if (m < 0) m += MOD;
    if (m >= MOD) m -= MOD;
    Mint result = {m};
    return result;
}

Mint add(Mint a, Mint b) {
    return toModular(a.val + b.val);
}

Mint sub(Mint a, Mint b) {
    return toModular(a.val - b.val);
}

Mint mul(Mint a, Mint b) {
    return toModular(a.val * b.val % MOD);
}

Mint pow(Mint base, ll exp) {
    Mint result = {1}, m = base;
    while (exp) {
        if (exp & 1) result = mul(result, m);
        m = mul(m, m);
        exp >>= 1;
    }
    return result;
}

typedef struct {
    int size;
    Mint xp[MAX_LEN + 1];
    Mint hash[MAX_LEN + 1];
} HashTable;

Mint getHash(HashTable *ht, int l, int r) {
    assert(l <= r && r <= ht->size);
    return sub(ht->hash[l], mul(ht->hash[r + 1], ht->xp[r - l + 1]));
}

void initHashTable(HashTable *ht, char *s, Mint m) {
    int len = strlen(s);
    ht->size = len;
    ht->xp[0] = (Mint){1};
    for (int i = 1; i <= len; i++)
        ht->xp[i] = mul(ht->xp[i - 1], m);
    
    ht->hash[len] = (Mint){0};
    for (int i = len - 1; i >= 0; i--)
        ht->hash[i] = add(mul(ht->hash[i + 1], m), (Mint){s[i]});
}

ll mul_vals[] = {7, 11, 13, 17, 19};

int main() {
    int n;
    scanf("%d", &n);
    char t[MAX_LEN];
    scanf("%s", t);
    
    int zp[MAX_LEN], zpl = 0;
    for (int i = 0; i < strlen(t); i++)
        if (t[i] == '0')
            zp[zpl++] = i;
    
    Mint m = {mul_vals[rand() % 5]};
    
    char s[MAX_LEN];
    for (int i = 0; i < zpl; i++)
        s[i] = '0' + (zp[i] & 1);
    
    HashTable hash;
    initHashTable(&hash, s, m);
    
    for (int i = 0; i < zpl; i++)
        s[i] = '1' - (zp[i] & 1);
    
    HashTable rhash;
    initHashTable(&rhash, s, m);
    
    int q;
    scanf("%d", &q);
    while (q--) {
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
        
        printf("%s\n", (hash1.val == hash2.val) ? "Yes" : "No");
    }

    return 0;
}
