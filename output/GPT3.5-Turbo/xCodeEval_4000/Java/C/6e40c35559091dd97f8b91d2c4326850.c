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

void addAllIntegerList(IntegerList* list, IntegerList* other) {
    addAll(list, other->data, 0, other->size);
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
    if (i < 0 || i >= list->size) {
        return;
    }
    list->data[i] = x;
}

int size(IntegerList* list) {
    return list->size;
}

int get(IntegerList* list, int i) {
    if (i < 0 || i >= list->size) {
        return 0;
    }
    return list->data[i];
}

void clear(IntegerList* list) {
    list->size = 0;
}

void freeIntegerList(IntegerList* list) {
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

int subtract(Modular* mod, int x, int y) {
    return valueOf(mod, x - y);
}

void freeModular(Modular* mod) {
    free(mod);
}

typedef struct {
    int x;
    int y;
    int g;
} ExtGCD;

ExtGCD* newExtGCD() {
    return (ExtGCD*)malloc(sizeof(ExtGCD));
}

int extgcd(ExtGCD* extGCD, int a, int b) {
    if (a >= b) {
        extGCD->g = extgcd0(extGCD, a, b);
    } else {
        extGCD->g = extgcd0(extGCD, b, a);
        int tmp = extGCD->x;
        extGCD->x = extGCD->y;
        extGCD->y = tmp;
    }
    return extGCD->g;
}

int extgcd0(ExtGCD* extGCD, int a, int b) {
    if (b == 0) {
        extGCD->x = 1;
        extGCD->y = 0;
        return a;
    }
    int g = extgcd0(extGCD, b, a % b);
    int n = extGCD->x;
    int m = extGCD->y;
    extGCD->x = m;
    extGCD->y = n - m * (a / b);
    return g;
}

void freeExtGCD(ExtGCD* extGCD) {
    free(extGCD);
}

typedef struct {
    Modular* modular;
} Power;

Power* newPower(Modular* modular) {
    Power* pow = (Power*)malloc(sizeof(Power));
    pow->modular = modular;
    return pow;
}

int pow(Power* pow, int x, int n) {
    Modular* mod = pow->modular;
    if (n == 0) {
        return valueOf(mod, 1);
    }
    long long r = pow(pow, x, n >> 1);
    r = valueOf(mod, r * r);
    if ((n & 1) == 1) {
        r = valueOf(mod, r * x);
    }
    return (int)r;
}

int inverseByFermat(Power* pow, int x) {
    return pow(pow, x, pow->modular->m - 2);
}

void freePower(Power* pow) {
    free(pow);
}

typedef struct {
    IntegerList* cm;
    int m;
    int dm;
    IntegerList* cn;
    IntegerList* buf;
    IntegerList* seq;
    Modular* mod;
    Power* pow;
} ModLinearFeedbackShiftRegister;

ModLinearFeedbackShiftRegister* newModLinearFeedbackShiftRegister(Modular* mod, int cap) {
    ModLinearFeedbackShiftRegister* lfsr = (ModLinearFeedbackShiftRegister*)malloc(sizeof(ModLinearFeedbackShiftRegister));
    lfsr->cm = newIntegerList(cap + 1);
    lfsr->m = -1;
    lfsr->dm = 0;
    lfsr->cn = newIntegerList(cap + 1);
    lfsr->buf = newIntegerList(cap + 1);
    lfsr->seq = newIntegerList(cap + 1);
    lfsr->mod = mod;
    lfsr->pow = newPower(mod);
    add(lfsr->cn, 1);
    return lfsr;
}

void add(ModLinearFeedbackShiftRegister* lfsr, int x) {
    x = valueOf(lfsr->mod, x);
    int n = size(lfsr->seq);
    add(lfsr->seq, x);
    int dn = estimateDelta(lfsr);
    if (dn == 0) {
        return;
    }
    if (lfsr->m < 0) {
        clear(lfsr->cm);
        addAllIntegerList(lfsr->cm, lfsr->cn);
        lfsr->dm = dn;
        lfsr->m = n;
        expandWith(lfsr->cn, 0, n + 2);
        return;
    }
    int ln = size(lfsr->cn) - 1;
    int len = ln > n + 1 - ln ? ln : n + 1 - ln;
    clear(lfsr->buf);
    addAllIntegerList(lfsr->buf, lfsr->cn);
    expandWith(lfsr->buf, 0, len + 1);
    int factor = mul(lfsr->mod, dn, inverseByFermat(lfsr->pow, lfsr->dm));
    int* bufData = lfsr->buf->data;
    int* cmData = lfsr->cm->data;
    for (int i = n - lfsr->m, until = n - lfsr->m + size(lfsr->cm); i < until; i++) {
        bufData[i] = subtract(lfsr->mod, bufData[i], mul(lfsr->mod, factor, cmData[i - (n - lfsr->m)]));
    }
    if (size(lfsr->cn) < size(lfsr->buf)) {
        IntegerList* tmp = lfsr->cm;
        lfsr->cm = lfsr->cn;
        lfsr->cn = tmp;
        lfsr->m = n;
        lfsr->dm = dn;
    } else {
        IntegerList* tmp = lfsr->cn;
        lfsr->cn = lfsr->buf;
        lfsr->buf = tmp;
    }
}

int length(ModLinearFeedbackShiftRegister* lfsr) {
    return size(lfsr->cn) - 1;
}

int codeAt(ModLinearFeedbackShiftRegister* lfsr, int i) {
    return valueOf(lfsr->mod, -lfsr->cn->data[i]);
}

void freeModLinearFeedbackShiftRegister(ModLinearFeedbackShiftRegister* lfsr) {
    freeIntegerList(lfsr->cm);
    freeIntegerList(lfsr->cn);
    freeIntegerList(lfsr->buf);
    freeIntegerList(lfsr->seq);
    freeModular(lfsr->mod);
    freePower(lfsr->pow);
    free(lfsr);
}

typedef struct {
    IntegerList* coe;
    Modular* mod;
    IntegerList* p;
    IntegerList* remainder;
    Power* pow;
    int n;
} LinearRecurrenceSolver;

LinearRecurrenceSolver* newLinearRecurrenceSolver(IntegerList* coe, Modular* mod) {
    LinearRecurrenceSolver* solver = (LinearRecurrenceSolver*)malloc(sizeof(LinearRecurrenceSolver));
    solver->coe = coe;
    solver->mod = mod;
    solver->n = size(coe);
    solver->pow = newPower(mod);
    solver->remainder = newIntegerList(size(coe));
    solver->p = newIntegerList(size(coe) + 1);
    for (int i = solver->n - 1; i >= 0; i--) {
        add(solver->p, -solver->coe->data[i]);
    }
    add(solver->p, 1);
    return solver;
}

void normalize(IntegerList* list) {
    retain(list, rankOf(list) + 1);
}

void mul(IntegerList* a, IntegerList* b, IntegerList* c, Modular* mod) {
    int rA = rankOf(a);
    int rB = rankOf(b);
    clear(c);
    expandWith(c, 0, rA + rB + 1);
    int* aData = a->data;
    int* bData = b->data;
    int* cData = c->data;
    for (int i = 0; i <= rA; i++) {
        for (int j = 0; j <= rB; j++) {
            cData[i + j] = plus(mod, cData[i + j], mul(mod, aData[i], bData[j]));
        }
    }
}

void divide(IntegerList* a, IntegerList* b, IntegerList* c, IntegerList* remainder, Power* pow) {
    Modular* mod = pow->modular;
    int rA = rankOf(a);
    int rB = rankOf(b);
    if (rA < rB) {
        clear(c);
        add(c, 0);
        clear(remainder);
        addAllIntegerList(remainder, a);
        return;
    }
    int rC = rA - rB > 0 ? rA - rB : 0;
    clear(c);
    expandWith(c, 0, rC + 1);
    clear(remainder);
    addAllIntegerList(remainder, a);
    int* bData = b->data;
    int* cData = c->data;
    int* rData = remainder->data;
    ExtGCD* extGCD = newExtGCD();
    if (extgcd(extGCD, b->data[rB], mod->m) != 1) {
        freeExtGCD(extGCD);
        return;
    }
    int inv = valueOf(mod, extGCD->x);
    freeExtGCD(extGCD);
    for (int i = rA, j = rC; i >= rB; i--, j--) {
        if (rData[i] == 0) {
            continue;
        }
        int factor = mul(mod, -rData[i], inv);
        cData[j] = valueOf(mod, -factor);
        for (int k = rB; k >= 0; k--) {
            rData[k + j] = plus(mod, rData[k + j], mul(mod, factor, bData[k]));
        }
    }
    normalize(remainder);
}

void module(long long k, IntegerList* p, IntegerList* remainder, Power* pow) {
    int rP = rankOf(p);
    if (rP == 0) {
        clear(remainder);
        add(remainder, 0);
        return;
    }
    IntegerList* a = newIntegerList(size(p));
    IntegerList* c = newIntegerList(size(p));
    module(k, a, p, c, remainder, rP, pow);
    freeIntegerList(a);
    freeIntegerList(c);
}

void module(long long k, IntegerList* a, IntegerList* b, IntegerList* c, IntegerList* remainder, int rb, Power* pow) {
    Modular* mod = pow->modular;
    if (k < rb) {
        clear(remainder);
        expandWith(remainder, 0, k + 1);
        set(remainder, k, 1);
        return;
    }
    module(k / 2, a, b, c, remainder, rb, pow);
    mul(remainder, remainder, a, mod);
    if (k % 2 == 1) {
        int ra = rankOf(a);
        expandWith(a, 0, ra + 2);
        int* aData = a->data;
        for (int i = ra; i >= 0; i--) {
            aData[i + 1] = aData[i];
        }
        aData[0] = 0;
    }
    divide(a, b, c, remainder, pow);
}

void freeLinearRecurrenceSolver(LinearRecurrenceSolver* solver) {
    freeIntegerList(solver->coe);
    freeModular(solver->mod);
    freeIntegerList(solver->p);
    freeIntegerList(solver->remainder);
    freePower(solver->pow);
    free(solver);
}

typedef struct {
    int m;
} TaskAdapter;

TaskAdapter* newTaskAdapter() {
    return (TaskAdapter*)malloc(sizeof(TaskAdapter));
}

void run(TaskAdapter* adapter) {
    int n;
    int k;
    scanf("%d %d", &n, &k);
    Modular* mod = newModular(1000000007);
    Power* pow = newPower(mod);
    ModLinearFeedbackShiftRegister* lfsr = newModLinearFeedbackShiftRegister(mod, 200);
    for (int i = 0; i < 2; i++) {
        add(lfsr, i + 1);
    }
    IntegerList* a = newIntegerList(200);
    for (int i = 0; i < 200; i++) {
        add(a, mul(mod, get(lfsr->seq, i), pow(pow, i + 1, k)));
        if (i > 0) {
            set(a, i, plus(mod, get(a, i), get(a, i - 1)));
        }
    }
    IntegerList* seq = newIntegerList();
    addAllIntegerList(seq, a);
    LinearRecurrenceSolver* solver = newLinearRecurrenceSolver(seq, mod);
    int ans = solve(solver, n - 1, seq);
    printf("%d\n", ans);
    freeModLinearFeedbackShiftRegister(lfsr);
    freeIntegerList(a);
    freeIntegerList(seq);
    freeLinearRecurrenceSolver(solver);
    freeModular(mod);
    freePower(pow);
    free(adapter);
}

void freeTaskAdapter(TaskAdapter* adapter) {
    free(adapter);
}

int main() {
    TaskAdapter* adapter = newTaskAdapter();
    run(adapter);
    freeTaskAdapter(adapter);
    return 0;
}
