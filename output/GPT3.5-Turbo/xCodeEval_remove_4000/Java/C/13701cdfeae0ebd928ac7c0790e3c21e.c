#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int cap;
} IntList;

IntList* newIntList(int cap) {
    IntList* list = (IntList*)malloc(sizeof(IntList));
    list->size = 0;
    list->cap = cap;
    list->data = (int*)malloc(sizeof(int) * cap);
    return list;
}

IntList* cloneIntList(IntList* list) {
    IntList* clone = newIntList(list->cap);
    clone->size = list->size;
    for (int i = 0; i < list->size; i++) {
        clone->data[i] = list->data[i];
    }
    return clone;
}

void ensureSpace(IntList* list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = list->cap + 10;
        }
        list->data = (int*)realloc(list->data, sizeof(int) * list->cap);
    }
}

void checkRange(IntList* list, int i) {
    if (i < 0 || i >= list->size) {
        printf("ArrayIndexOutOfBoundsException\n");
        exit(1);
    }
}

int getInt(IntList* list, int i) {
    checkRange(list, i);
    return list->data[i];
}

void addAll(IntList* list, int* x, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size + i] = x[offset + i];
    }
    list->size += len;
}

void addAllIntList(IntList* list, IntList* other) {
    addAll(list, other->data, 0, other->size);
}

void expandWith(IntList* list, int x, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size + i] = x;
    }
    list->size += len;
}

void retain(IntList* list, int n) {
    if (n < 0) {
        printf("IllegalArgumentException\n");
        exit(1);
    }
    if (n >= list->size) {
        return;
    }
    list->size = n;
}

int size(IntList* list) {
    return list->size;
}

int* toArray(IntList* list) {
    int* arr = (int*)malloc(sizeof(int) * list->size);
    for (int i = 0; i < list->size; i++) {
        arr[i] = list->data[i];
    }
    return arr;
}

void clear(IntList* list) {
    list->size = 0;
}

void printIntList(IntList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

void freeIntList(IntList* list) {
    free(list->data);
    free(list);
}

typedef struct {
    int m;
} Modular;

Modular* newModular(int m) {
    Modular* mod = (Modular*)malloc(sizeof(Modular));
    mod->m = m;
    return mod;
}

int valueOf(Modular* mod, int x) {
    x %= mod->m;
    if (x < 0) {
        x += mod->m;
    }
    return x;
}

int mul(Modular* mod, int x, int y) {
    return valueOf(mod, (long long)x * y);
}

int plus(Modular* mod, int x, int y) {
    return valueOf(mod, x + y);
}

typedef struct {
    Modular* mod;
    int g;
    int* wCache;
    int* invCache;
    int* data;
    int size;
} id8;

id8* newid8(Modular* mod) {
    id8* ntt = (id8*)malloc(sizeof(id8));
    ntt->mod = mod;
    ntt->g = mod->m == 998244353 ? 3 : 2;
    ntt->wCache = (int*)malloc(sizeof(int) * 30);
    ntt->invCache = (int*)malloc(sizeof(int) * 30);
    ntt->data = NULL;
    ntt->size = 0;
    return ntt;
}

void dotMul(id8* ntt, int* a, int* b, int* c, int m) {
    for (int i = 0, n = 1 << m; i < n; i++) {
        c[i] = mul(ntt->mod, a[i], b[i]);
    }
}

void dft(id8* ntt, int* p, int m) {
    int n = 1 << m;

    int shift = 32 - __builtin_clz(n - 1);
    for (int i = 1; i < n; i++) {
        int j = __builtin_bswap32(i << shift);
        if (i < j) {
            int temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }

    int w = 0;
    int t = 0;
    for (int d = 0; d < m; d++) {
        int w1 = ntt->wCache[d];
        int s = 1 << d;
        int s2 = s << 1;
        for (int i = 0; i < n; i += s2) {
            w = 1;
            for (int j = 0; j < s; j++) {
                int a = i + j;
                int b = a + s;
                t = mul(ntt->mod, w, p[b]);
                p[b] = plus(ntt->mod, p[a], -t);
                p[a] = plus(ntt->mod, p[a], t);
                w = mul(ntt->mod, w, w1);
            }
        }
    }
}

void idft(id8* ntt, int* p, int m) {
    dft(ntt, p, m);

    int n = 1 << m;
    int invN = ntt->invCache[m];

    p[0] = mul(ntt->mod, p[0], invN);
    p[n / 2] = mul(ntt->mod, p[n / 2], invN);
    for (int i = 1, until = n / 2; i < until; i++) {
        int a = p[n - i];
        p[n - i] = mul(ntt->mod, p[i], invN);
        p[i] = mul(ntt->mod, a, invN);
    }
}

void pow2(id8* ntt, int* a) {
    int rankAns = (ntt->size - 1) * 2;
    int proper = 32 - __builtin_clz(rankAns + 1);
    expandWith(ntt, 0, 1 << proper);
    dft(ntt, ntt->data, proper);
    dotMul(ntt, ntt->data, ntt->data, ntt->data, proper);
    idft(ntt, ntt->data, proper);
    ntt->size = rankAns + 1;
}

void id1(id8* ntt, IntList** lists, int listsSize, IntList* ans) {
    IntList** pqs = (IntList**)malloc(sizeof(IntList*) * listsSize);
    for (int i = 0; i < listsSize; i++) {
        pqs[i] = cloneIntList(lists[i]);
    }
    int pqsSize = listsSize;

    while (pqsSize > 1) {
        IntList* a = pqs[0];
        IntList* b = pqs[1];
        dft(ntt, a->data, 32 - __builtin_clz(a->size - 1));
        dft(ntt, b->data, 32 - __builtin_clz(b->size - 1));
        dotMul(ntt, a->data, b->data, a->data, 32 - __builtin_clz(a->size - 1));
        idft(ntt, a->data, 32 - __builtin_clz(a->size - 1));
        retain(a, rankOf(a) + 1);
        freeIntList(b);
        for (int i = 1; i < pqsSize - 1; i++) {
            pqs[i] = pqs[i + 1];
        }
        pqsSize--;
    }

    IntList* last = pqs[0];
    clear(ans);
    addAllIntList(ans, last);
    freeIntList(last);
    free(pqs);
}

typedef struct {
    int m;
} TaskG;

TaskG* newTaskG() {
    TaskG* task = (TaskG*)malloc(sizeof(TaskG));
    return task;
}

void solve(TaskG* task, int testNumber, int n, int k, int* allow, int allowSize, int* ans) {
    Modular* mod = newModular(998244353);

    IntList* p = newIntList(10);
    addAll(p, allow, 0, allowSize);

    int m = n / 2;
    IntList* last = cloneIntList(p);
    id8* ntt = newid8(mod);
    IntList** lists = (IntList**)malloc(sizeof(IntList*) * 30);
    int listsSize = 0;
    while (m > 1) {
        if (m % 2 == 1) {
            lists[listsSize++] = cloneIntList(last);
        }
        pow2(ntt, last->data);
        normalize(last);
        m /= 2;
    }
    lists[listsSize++] = last;

    IntList* prod = newIntList(1 << 20);
    id1(ntt, lists, listsSize, prod);

    int sum = 0;
    for (int i = 0; i < prod->size; i++) {
        int plus = prod->data[i];
        sum = plus(mod, sum, mul(mod, plus, plus));
    }

    *ans = sum;

    freeIntList(p);
    freeIntList(last);
    freeid8(ntt);
    for (int i = 0; i < listsSize; i++) {
        freeIntList(lists[i]);
    }
    free(lists);
    freeIntList(prod);
    freeModular(mod);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int* allow = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &allow[i]);
    }

    int ans;
    TaskG* task = newTaskG();
    solve(task, 1, n, k, allow, k, &ans);
    printf("%d\n", ans);

    free(allow);
    free(task);

    return 0;
}
