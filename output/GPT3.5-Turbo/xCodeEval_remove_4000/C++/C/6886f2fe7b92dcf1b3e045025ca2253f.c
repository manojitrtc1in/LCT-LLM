#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOD 1000000007
#define MOD 998244353

typedef struct {
    unsigned long long value;
} modint;

modint modint_add(modint a, modint b) {
    modint result;
    result.value = (a.value + b.value) % MAX_MOD;
    return result;
}

modint modint_sub(modint a, modint b) {
    modint result;
    result.value = (a.value - b.value + MAX_MOD) % MAX_MOD;
    return result;
}

modint modint_mul(modint a, modint b) {
    modint result;
    result.value = (a.value * b.value) % MAX_MOD;
    return result;
}

modint modint_pow(modint a, unsigned long long b) {
    modint result;
    result.value = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = modint_mul(result, a);
        }
        a = modint_mul(a, a);
        b /= 2;
    }
    return result;
}

typedef struct {
    int first;
    int second;
} pair;

pair make_pair(int a, int b) {
    pair result;
    result.first = a;
    result.second = b;
    return result;
}

pair mp(int a, int b) {
    return make_pair(a, b);
}

int lower_bound(int* arr, int size, int target) {
    int left = 0;
    int right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int upper_bound(int* arr, int size, int target) {
    int left = 0;
    int right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

void solve() {
    int n;
    scanf("%d", &n);
    char t[300001];
    scanf("%s", t);
    int cnter[300001];
    int cnter_size = 0;
    for (int i = 0; i < strlen(t); i++) {
        if (t[i] == '0') {
            cnter[cnter_size++] = i * 2 + i % 2;
        }
    }
    modint hoge[300001];
    modint rev[300001];
    modint nexts;
    nexts.value = 1;
    for (int i = 0; i < cnter_size; i++) {
        hoge[i + 1] = hoge[i];
        hoge[i + 1] = modint_add(hoge[i + 1], modint_mul(nexts, cnter[i] % 2));
        rev[i + 1] = rev[i];
        rev[i + 1] = modint_add(rev[i + 1], modint_mul(nexts, (cnter[i] + 1) % 2));
        nexts = modint_mul(nexts, 2);
    }
    int query;
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        pair Left = mp(lower_bound(cnter, cnter_size, a * 2), lower_bound(cnter, cnter_size, (a + c) * 2));
        pair Right = mp(lower_bound(cnter, cnter_size, b * 2), lower_bound(cnter, cnter_size, (b + c) * 2));
        if (Left.second - Left.first != Right.second - Right.first) {
            printf("No\n");
            continue;
        }
        int ok = 1;
        modint aa, bb;
        aa = hoge[Left.second];
        aa = modint_sub(aa, hoge[Left.first]);
        if (a % 2 == b % 2) {
            bb = hoge[Right.second];
            bb = modint_sub(bb, hoge[Right.first]);
        } else {
            bb = rev[Right.second];
            bb = modint_sub(bb, rev[Right.first]);
        }
        if (Left.first != 0) {
            aa = modint_mul(aa, modint_pow(2, Left.first));
        }
        if (Right.first != 0) {
            bb = modint_mul(bb, modint_pow(2, Right.first));
        }
        if (aa.value != bb.value) {
            ok = 0;
        }
        if (ok == 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

int main() {
    solve();
    return 0;
}
