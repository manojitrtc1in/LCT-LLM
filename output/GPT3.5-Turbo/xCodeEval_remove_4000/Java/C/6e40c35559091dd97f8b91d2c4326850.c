#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int cap;
} IntegerList;

IntegerList* newIntegerList(int cap) {
    IntegerList* list = (IntegerList*)malloc(sizeof(IntegerList));
    list->data = (int*)malloc(sizeof(int) * cap);
    list->size = 0;
    list->cap = cap;
    return list;
}

void ensureSpace(IntegerList* list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = (list->cap + 10) * 2;
        }
        list->data = (int*)realloc(list->data, sizeof(int) * list->cap);
    }
}

void add(IntegerList* list, int x) {
    ensureSpace(list, list->size + 1);
    list->data[list->size++] = x;
}

void addAll(IntegerList* list, int* x, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size++] = x[offset + i];
    }
}

void expandWith(IntegerList* list, int x, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size++] = x;
    }
}

void retain(IntegerList* list, int n) {
    if (n < 0) {
        return;
    }
    if (n >= list->size) {
        return;
    }
    list->size = n;
}

void set(IntegerList* list, int i, int x) {
    list->data[i] = x;
}

int size(IntegerList* list) {
    return list->size;
}

int* toArray(IntegerList* list) {
    int* arr = (int*)malloc(sizeof(int) * list->size);
    for (int i = 0; i < list->size; i++) {
        arr[i] = list->data[i];
    }
    return arr;
}

void clear(IntegerList* list) {
    list->size = 0;
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

int subtract(Modular* mod, int x, int y) {
    return valueOf(mod, x - y);
}

typedef struct {
    int x;
    int y;
    int g;
} id11;

id11* newid11() {
    id11* id8 = (id11*)malloc(sizeof(id11));
    id8->x = 0;
    id8->y = 0;
    id8->g = 0;
    return id8;
}

int id3(id11* id8, int a, int b) {
    if (a >= b) {
        id1(id8, a, b);
    } else {
        id1(id8, b, a);
        int tmp = id8->x;
        id8->x = id8->y;
        id8->y = tmp;
    }
    return id8->g;
}

void id1(id11* id8, int a, int b) {
    if (b == 0) {
        id8->x = 1;
        id8->y = 0;
        id8->g = a;
        return;
    }
    id1(id8, b, a % b);
    int n = id8->x;
    int m = id8->y;
    id8->x = m;
    id8->y = n - m * (a / b);
}

typedef struct {
    Modular* mod;
    IntegerList* coe;
    IntegerList* p;
    IntegerList* remainder;
    id11* pow;
    int n;
} id9;

id9* newid9(IntegerList* coe, Modular* mod) {
    id9* id6 = (id9*)malloc(sizeof(id9));
    id6->coe = coe;
    id6->mod = mod;
    id6->n = coe->size;
    id6->pow = newid11();
    id6->remainder = newIntegerList(coe->size);
    id6->p = newIntegerList(coe->size + 1);
    for (int i = id6->n - 1; i >= 0; i--) {
        add(id6->p, valueOf(id6->mod, -coe->data[i]));
    }
    add(id6->p, 1);
    return id6;
}

id9* newid2(IntegerList* seq, Modular* mod) {
    id9* id6 = newid9(newIntegerList(seq->size), mod);
    for (int i = 0; i < seq->size; i++) {
        add(id6->coe, seq->data[i]);
    }
    return id6;
}

int solve(id9* solver, long long k, IntegerList* a) {
    if (k < a->size) {
        return a->data[k];
    }
    int rP = size(solver->p) - 1;
    if (rP == 0) {
        clear(solver->remainder);
        add(solver->remainder, 0);
        return 0;
    }
    IntegerList* buf = newIntegerList(size(solver->p));
    IntegerList* cn = newIntegerList(size(solver->p));
    IntegerList* cm = newIntegerList(size(solver->p));
    IntegerList* tmp;
    int* bufData = buf->data;
    int* cnData = cn->data;
    int* cmData = cm->data;
    for (int i = 0; i < size(solver->cn); i++) {
        cnData[i] = solver->cn->data[i];
    }
    int m = -1;
    int dm;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int dn = 0;
        for (int j = 0; j < size(cn); j++) {
            dn = plus(solver->mod, dn, mul(solver->mod, cnData[j], solver->seq->data[size(solver->seq) - 1 - j]));
        }
        if (dn == 0) {
            continue;
        }
        if (m < 0) {
            clear(cm);
            for (int j = 0; j < size(cn); j++) {
                cmData[j] = cnData[j];
            }
            dm = dn;
            m = size(solver->seq);
            expandWith(cn, 0, m + 2);
            continue;
        }
        int ln = size(cn) - 1;
        int len = ln > m + 1 - ln ? ln : m + 1 - ln;
        clear(buf);
        for (int j = 0; j < size(cn); j++) {
            bufData[j] = cnData[j];
        }
        expandWith(buf, 0, len + 1);
        int factor = mul(solver->mod, dn, solver->pow->id7(dm));
        for (int j = m - size(cn) + 1, k = 0; j <= m; j++, k++) {
            bufData[j] = subtract(solver->mod, bufData[j], mul(solver->mod, factor, cmData[k]));
        }
        if (size(cn) < size(buf)) {
            tmp = cm;
            cm = cn;
            cn = tmp;
            m = size(solver->seq);
            dm = dn;
        } else {
            tmp = cn;
            cn = buf;
            buf = tmp;
        }
    }
    for (int i = 0; i < size(cn); i++) {
        ans = plus(solver->mod, ans, mul(solver->mod, solver->remainder->data[i], cn->data[i]));
    }
    return ans;
}

int main() {
    int n;
    int k;
    scanf("%d %d", &n, &k);
    IntegerList* seq = newIntegerList(200);
    IntegerList* fib = newIntegerList(200);
    IntegerList* a = newIntegerList(200);
    add(seq, 1);
    add(seq, 2);
    add(fib, 1);
    add(fib, 2);
    for (int i = 2; i < 200; i++) {
        add(fib, plus(newModular(1000000007), fib->data[i - 1], fib->data[i - 2]));
    }
    Modular* mod = newModular(1000000007);
    for (int i = 0; i < 200; i++) {
        add(a, mul(mod, fib->data[i], pow(i + 1, k)));
        if (i > 0) {
            set(a, i, plus(mod, a->data[i], a->data[i - 1]));
        }
    }
    IntegerList* cn = newIntegerList(200);
    addAll(cn, a->data, 0, a->size);
    id9* solver = newid9(cn, mod);
    int ans = solve(solver, n - 1, cn);
    printf("%d\n", ans);
    return 0;
}
