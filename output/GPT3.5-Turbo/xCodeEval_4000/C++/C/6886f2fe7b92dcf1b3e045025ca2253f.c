#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOD 1000000007LL
#define MOD 998244353LL

typedef struct {
    long long value;
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

modint modint_pow(modint a, long long b) {
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
    modint first;
    modint second;
} pair;

pair make_pair(modint first, modint second) {
    pair result;
    result.first = first;
    result.second = second;
    return result;
}

pair hoge[300000];
pair rev[300000];

void solve() {
    int n;
    scanf("%d", &n);
    char t[300001];
    scanf("%s", t);
    int cnter[300000];
    int cnter_size = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == '0') {
            cnter[cnter_size++] = i * 2 + i % 2;
        }
    }
    pair nexts;
    nexts.first.value = 1;
    nexts.second.value = 1;
    for (int i = 0; i < cnter_size; i++) {
        hoge[i + 1] = hoge[i];
        hoge[i + 1].first = modint_add(hoge[i + 1].first, modint_mul(nexts.first, modint_make(cnter[i] % 2)));
        hoge[i + 1].second = modint_add(hoge[i + 1].second, modint_mul(nexts.second, modint_make(cnter[i] % 2)));
        rev[i + 1] = rev[i];
        rev[i + 1].first = modint_add(rev[i + 1].first, modint_mul(nexts.first, modint_make((cnter[i] + 1) % 2)));
        rev[i + 1].second = modint_add(rev[i + 1].second, modint_mul(nexts.second, modint_make((cnter[i] + 1) % 2)));
        nexts.first = modint_mul(nexts.first, modint_make(2));
        nexts.second = modint_mul(nexts.second, modint_make(2));
    }
    int query;
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        int Left = 0, Right = 0;
        for (int j = 0; j < cnter_size; j++) {
            if (cnter[j] >= a * 2 && cnter[j] < (a + c) * 2) {
                Left++;
            }
            if (cnter[j] >= b * 2 && cnter[j] < (b + c) * 2) {
                Right++;
            }
        }
        if (Left != Right) {
            printf("No\n");
            continue;
        }
        int ok = 1;
        pair aa, bb;
        aa = hoge[Left];
        if (Left != 0) {
            aa.first = modint_sub(aa.first, hoge[Left - 1].first);
            aa.second = modint_sub(aa.second, hoge[Left - 1].second);
            aa.first = modint_div(aa.first, modint_pow(modint_make(2), Left));
            aa.second = modint_div(aa.second, modint_pow(modint_make(2), Left));
        }
        if (a % 2 == b % 2) {
            bb = hoge[Right];
            if (Right != 0) {
                bb.first = modint_sub(bb.first, hoge[Right - 1].first);
                bb.second = modint_sub(bb.second, hoge[Right - 1].second);
                bb.first = modint_div(bb.first, modint_pow(modint_make(2), Right));
                bb.second = modint_div(bb.second, modint_pow(modint_make(2), Right));
            }
        } else {
            bb = rev[Right];
            if (Right != 0) {
                bb.first = modint_sub(bb.first, rev[Right - 1].first);
                bb.second = modint_sub(bb.second, rev[Right - 1].second);
                bb.first = modint_div(bb.first, modint_pow(modint_make(2), Right));
                bb.second = modint_div(bb.second, modint_pow(modint_make(2), Right));
            }
        }
        if (aa.first.value != bb.first.value || aa.second.value != bb.second.value) {
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
