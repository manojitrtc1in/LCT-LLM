#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

typedef struct {
    int m;
} Modular;

Modular new_Modular(int m) {
    Modular mod;
    mod.m = m;
    return mod;
}

int Modular_valueOf(Modular mod, int x) {
    x %= mod.m;
    if (x < 0) {
        x += mod.m;
    }
    return x;
}

int Modular_mul(Modular mod, int x, int y) {
    return Modular_valueOf(mod, (long long)x * y);
}

int Modular_plus(Modular mod, int x, int y) {
    return Modular_valueOf(mod, x + y);
}

typedef struct {
    int size;
    int cap;
    int *data;
} IntList;

IntList new_IntList(int cap) {
    IntList list;
    list.size = 0;
    list.cap = cap;
    if (cap == 0) {
        list.data = NULL;
    } else {
        list.data = (int *)malloc(cap * sizeof(int));
    }
    return list;
}

void IntList_ensureSpace(IntList *list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = list->cap + 10 > list->cap * 2 ? list->cap + 10 : list->cap * 2;
        }
        list->data = (int *)realloc(list->data, list->cap * sizeof(int));
    }
}

void IntList_addAll(IntList *list, int *x, int offset, int len) {
    IntList_ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size + i] = x[offset + i];
    }
    list->size += len;
}

void IntList_addAll_IntList(IntList *list, IntList *other) {
    IntList_addAll(list, other->data, 0, other->size);
}

void IntList_expandWith(IntList *list, int x, int len) {
    IntList_ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size + i] = x;
    }
    list->size += len;
}

void IntList_retain(IntList *list, int n) {
    if (n < 0) {
        return;
    }
    if (n >= list->size) {
        return;
    }
    list->size = n;
}

int IntList_size(IntList *list) {
    return list->size;
}

int *IntList_toArray(IntList *list) {
    int *arr = (int *)malloc(list->size * sizeof(int));
    for (int i = 0; i < list->size; i++) {
        arr[i] = list->data[i];
    }
    return arr;
}

void IntList_clear(IntList *list) {
    list->size = 0;
}

IntList IntList_clone(IntList *list) {
    IntList clone = new_IntList(list->cap);
    IntList_addAll_IntList(&clone, list);
    return clone;
}

int CachedLog2_ceilLog(int x) {
    int ans = CachedLog2_floorLog(x);
    if ((1 << ans) < x) {
        ans++;
    }
    return ans;
}

int CachedLog2_floorLog(int x) {
    int BITS = 16;
    int LIMIT = 1 << BITS;
    char CACHE[LIMIT];
    int b = 0;
    for (int i = 0; i < LIMIT; i++) {
        while ((1 << (b + 1)) <= i) {
            b++;
        }
        CACHE[i] = b;
    }
    return x < LIMIT ? CACHE[x] : (BITS + CACHE[x >> BITS]);
}

typedef struct {
    int m;
    int *wCache;
    int *invCache;
} NumberTheoryTransform;

NumberTheoryTransform new_NumberTheoryTransform(Modular mod, int g) {
    NumberTheoryTransform ntt;
    ntt.m = mod.m;
    ntt.wCache = (int *)malloc(30 * sizeof(int));
    ntt.invCache = (int *)malloc(30 * sizeof(int));
    for (int i = 0; i < 30; i++) {
        int s = 1 << i;
        ntt.wCache[i] = pow(g, (mod.m - 1) / 2 / s, mod.m);
        ntt.invCache[i] = pow(s, mod.m - 2, mod.m);
    }
    return ntt;
}

void NumberTheoryTransform_dotMul(NumberTheoryTransform *ntt, int *a, int *b, int *c, int m) {
    int n = 1 << m;
    for (int i = 0; i < n; i++) {
        c[i] = Modular_mul(new_Modular(ntt->m), a[i], b[i]);
    }
}

void NumberTheoryTransform_prepareReverse(int *r, int b) {
    int n = 1 << b;
    r[0] = 0;
    for (int i = 1; i < n; i++) {
        r[i] = (r[i >> 1] >> 1) | ((1 & i) << (b - 1));
    }
}

void NumberTheoryTransform_dft(NumberTheoryTransform *ntt, int *p, int m) {
    int n = 1 << m;

    int *rev = (int *)malloc(n * sizeof(int));
    NumberTheoryTransform_prepareReverse(rev, m);

    for (int i = 0; i < n; i++) {
        if (rev[i] > i) {
            int tmp = p[i];
            p[i] = p[rev[i]];
            p[rev[i]] = tmp;
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
                t = Modular_mul(new_Modular(ntt->m), w, p[b]);
                p[b] = Modular_plus(new_Modular(ntt->m), p[a], -t);
                p[a] = Modular_plus(new_Modular(ntt->m), p[a], t);
                w = Modular_mul(new_Modular(ntt->m), w, w1);
            }
        }
    }

    free(rev);
}

void NumberTheoryTransform_idft(NumberTheoryTransform *ntt, int *p, int m) {
    NumberTheoryTransform_dft(ntt, p, m);

    int n = 1 << m;
    int invN = ntt->invCache[m];

    p[0] = Modular_mul(new_Modular(ntt->m), p[0], invN);
    p[n / 2] = Modular_mul(new_Modular(ntt->m), p[n / 2], invN);
    for (int i = 1, until = n / 2; i < until; i++) {
        int a = p[n - i];
        p[n - i] = Modular_mul(new_Modular(ntt->m), p[i], invN);
        p[i] = Modular_mul(new_Modular(ntt->m), a, invN);
    }
}

void NumberTheoryTransform_mulByPQ(NumberTheoryTransform *ntt, IntList *lists, IntList *ans) {
    int size = IntList_size(lists);
    IntList *pqs = (IntList *)malloc(size * sizeof(IntList));
    for (int i = 0; i < size; i++) {
        pqs[i] = IntList_clone(&lists[i]);
    }
    while (size > 1) {
        IntList *a = &pqs[0];
        IntList *b = &pqs[1];
        NumberTheoryTransform_multiplyAndStoreAnswerIntoA(ntt, a, b);
        IntList_clear(b);
        free(b->data);
        for (int i = 1; i < size - 1; i++) {
            pqs[i] = pqs[i + 1];
        }
        size--;
    }

    IntList *last = &pqs[0];
    IntList_clear(ans);
    IntList_addAll_IntList(ans, last);
    free(last->data);
    free(pqs);
}

void NumberTheoryTransform_multiplyAndStoreAnswerIntoA(NumberTheoryTransform *ntt, IntList *a, IntList *b) {
    int rankAns = a->size - 1 + b->size - 1;
    int proper = CachedLog2_ceilLog(rankAns + 1);
    IntList_expandWith(a, 0, 1 << proper);
    IntList_expandWith(b, 0, 1 << proper);
    NumberTheoryTransform_dft(ntt, a->data, proper);
    NumberTheoryTransform_dft(ntt, b->data, proper);
    NumberTheoryTransform_dotMul(ntt, a->data, b->data, a->data, proper);
    NumberTheoryTransform_idft(ntt, a->data, proper);
    IntList_retain(a, rankAns + 1);
}

typedef struct {
    int m;
    int *factors;
    Modular mod;
    Power pow;
    int phi;
} PrimitiveRoot;

PrimitiveRoot new_PrimitiveRoot(Modular x) {
    PrimitiveRoot root;
    root.mod = x;
    root.pow = new_Power(x);
    root.factors = NULL;
    root.phi = x.m - 1;
    return root;
}

PrimitiveRoot new_PrimitiveRoot_int(int x) {
    return new_PrimitiveRoot(new_Modular(x));
}

int PrimitiveRoot_findMinPrimitiveRoot(PrimitiveRoot *root) {
    return PrimitiveRoot_findMinPrimitiveRoot_since(root, 2);
}

int PrimitiveRoot_findMinPrimitiveRoot_since(PrimitiveRoot *root, int since) {
    for (int i = since; i < root->mod.m; i++) {
        int flag = 1;
        for (int j = 0; j < root->phi; j++) {
            if (root->pow.pow(i, root->phi / root->factors[j]) == 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}

typedef struct {
    int m;
    int *factors;
} PollardRho;

PollardRho new_PollardRho() {
    PollardRho rho;
    rho.m = 0;
    rho.factors = NULL;
    return rho;
}

int PollardRho_findFactor(PollardRho *rho, int n) {
    if (n % 2 == 0) {
        return 2;
    }
    if (n % 3 == 0) {
        return 3;
    }
    if (n % 5 == 0) {
        return 5;
    }
    if (n % 7 == 0) {
        return 7;
    }
    if (n % 11 == 0) {
        return 11;
    }
    if (n % 13 == 0) {
        return 13;
    }
    if (n % 17 == 0) {
        return 17;
    }
    if (n % 19 == 0) {
        return 19;
    }
    if (n % 23 == 0) {
        return 23;
    }
    if (n % 29 == 0) {
        return 29;
    }
    if (n % 31 == 0) {
        return 31;
    }
    if (n % 37 == 0) {
        return 37;
    }
    if (n % 41 == 0) {
        return 41;
    }
    if (n % 43 == 0) {
        return 43;
    }
    if (n % 47 == 0) {
        return 47;
    }
    if (n % 53 == 0) {
        return 53;
    }
    if (n % 59 == 0) {
        return 59;
    }
    if (n % 61 == 0) {
        return 61;
    }
    if (n % 67 == 0) {
        return 67;
    }
    if (n % 71 == 0) {
        return 71;
    }
    if (n % 73 == 0) {
        return 73;
    }
    if (n % 79 == 0) {
        return 79;
    }
    if (n % 83 == 0) {
        return 83;
    }
    if (n % 89 == 0) {
        return 89;
    }
    if (n % 97 == 0) {
        return 97;
    }
    if (n % 101 == 0) {
        return 101;
    }
    if (n % 103 == 0) {
        return 103;
    }
    if (n % 107 == 0) {
        return 107;
    }
    if (n % 109 == 0) {
        return 109;
    }
    if (n % 113 == 0) {
        return 113;
    }
    if (n % 127 == 0) {
        return 127;
    }
    if (n % 131 == 0) {
        return 131;
    }
    if (n % 137 == 0) {
        return 137;
    }
    if (n % 139 == 0) {
        return 139;
    }
    if (n % 149 == 0) {
        return 149;
    }
    if (n % 151 == 0) {
        return 151;
    }
    if (n % 157 == 0) {
        return 157;
    }
    if (n % 163 == 0) {
        return 163;
    }
    if (n % 167 == 0) {
        return 167;
    }
    if (n % 173 == 0) {
        return 173;
    }
    if (n % 179 == 0) {
        return 179;
    }
    if (n % 181 == 0) {
        return 181;
    }
    if (n % 191 == 0) {
        return 191;
    }
    if (n % 193 == 0) {
        return 193;
    }
    if (n % 197 == 0) {
        return 197;
    }
    if (n % 199 == 0) {
        return 199;
    }
    if (n % 211 == 0) {
        return 211;
    }
    if (n % 223 == 0) {
        return 223;
    }
    if (n % 227 == 0) {
        return 227;
    }
    if (n % 229 == 0) {
        return 229;
    }
    if (n % 233 == 0) {
        return 233;
    }
    if (n % 239 == 0) {
        return 239;
    }
    if (n % 241 == 0) {
        return 241;
    }
    if (n % 251 == 0) {
        return 251;
    }
    if (n % 257 == 0) {
        return 257;
    }
    if (n % 263 == 0) {
        return 263;
    }
    if (n % 269 == 0) {
        return 269;
    }
    if (n % 271 == 0) {
        return 271;
    }
    if (n % 277 == 0) {
        return 277;
    }
    if (n % 281 == 0) {
        return 281;
    }
    if (n % 283 == 0) {
        return 283;
    }
    if (n % 293 == 0) {
        return 293;
    }
    if (n % 307 == 0) {
        return 307;
    }
    if (n % 311 == 0) {
        return 311;
    }
    if (n % 313 == 0) {
        return 313;
    }
    if (n % 317 == 0) {
        return 317;
    }
    if (n % 331 == 0) {
        return 331;
    }
    if (n % 337 == 0) {
        return 337;
    }
    if (n % 347 == 0) {
        return 347;
    }
    if (n % 349 == 0) {
        return 349;
    }
    if (n % 353 == 0) {
        return 353;
    }
    if (n % 359 == 0) {
        return 359;
    }
    if (n % 367 == 0) {
        return 367;
    }
    if (n % 373 == 0) {
        return 373;
    }
    if (n % 379 == 0) {
        return 379;
    }
    if (n % 383 == 0) {
        return 383;
    }
    if (n % 389 == 0) {
        return 389;
    }
    if (n % 397 == 0) {
        return 397;
    }
    if (n % 401 == 0) {
        return 401;
    }
    if (n % 409 == 0) {
        return 409;
    }
    if (n % 419 == 0) {
        return 419;
    }
    if (n % 421 == 0) {
        return 421;
    }
    if (n % 431 == 0) {
        return 431;
    }
    if (n % 433 == 0) {
        return 433;
    }
    if (n % 439 == 0) {
        return 439;
    }
    if (n % 443 == 0) {
        return 443;
    }
    if (n % 449 == 0) {
        return 449;
    }
    if (n % 457 == 0) {
        return 457;
    }
    if (n % 461 == 0) {
        return 461;
    }
    if (n % 463 == 0) {
        return 463;
    }
    if (n % 467 == 0) {
        return 467;
    }
    if (n % 479 == 0) {
        return 479;
    }
    if (n % 487 == 0) {
        return 487;
    }
    if (n % 491 == 0) {
        return 491;
    }
    if (n % 499 == 0) {
        return 499;
    }
    if (n % 503 == 0) {
        return 503;
    }
    if (n % 509 == 0) {
        return 509;
    }
    if (n % 521 == 0) {
        return 521;
    }
    if (n % 523 == 0) {
        return 523;
    }
    if (n % 541 == 0) {
        return 541;
    }
    if (n % 547 == 0) {
        return 547;
    }
    if (n % 557 == 0) {
        return 557;
    }
    if (n % 563 == 0) {
        return 563;
    }
    if (n % 569 == 0) {
        return 569;
    }
    if (n % 571 == 0) {
        return 571;
    }
    if (n % 577 == 0) {
        return 577;
    }
    if (n % 587 == 0) {
        return 587;
    }
    if (n % 593 == 0) {
        return 593;
    }
    if (n % 599 == 0) {
        return 599;
    }
    if (n % 601 == 0) {
        return 601;
    }
    if (n % 607 == 0) {
        return 607;
    }
    if (n % 613 == 0) {
        return 613;
    }
    if (n % 617 == 0) {
        return 617;
    }
    if (n % 619 == 0) {
        return 619;
    }
    if (n % 631 == 0) {
        return 631;
    }
    if (n % 641 == 0) {
        return 641;
    }
    if (n % 643 == 0) {
        return 643;
    }
    if (n % 647 == 0) {
        return 647;
    }
    if (n % 653 == 0) {
        return 653;
    }
    if (n % 659 == 0) {
        return 659;
    }
    if (n % 661 == 0) {
        return 661;
    }
    if (n % 673 == 0) {
        return 673;
    }
    if (n % 677 == 0) {
        return 677;
    }
    if (n % 683 == 0) {
        return 683;
    }
    if (n % 691 == 0) {
        return 691;
    }
    if (n % 701 == 0) {
        return 701;
    }
    if (n % 709 == 0) {
        return 709;
    }
    if (n % 719 == 0) {
        return 719;
    }
    if (n % 727 == 0) {
        return 727;
    }
    if (n % 733 == 0) {
        return 733;
    }
    if (n % 739 == 0) {
        return 739;
    }
    if (n % 743 == 0) {
        return 743;
    }
    if (n % 751 == 0) {
        return 751;
    }
    if (n % 757 == 0) {
        return 757;
    }
    if (n % 761 == 0) {
        return 761;
    }
    if (n % 769 == 0) {
        return 769;
    }
    if (n % 773 == 0) {
        return 773;
    }
    if (n % 787 == 0) {
        return 787;
    }
    if (n % 797 == 0) {
        return 797;
    }
    if (n % 809 == 0) {
        return 809;
    }
    if (n % 811 == 0) {
        return 811;
    }
    if (n % 821 == 0) {
        return 821;
    }
    if (n % 823 == 0) {
        return 823;
    }
    if (n % 827 == 0) {
        return 827;
    }
    if (n % 829 == 0) {
        return 829;
    }
    if (n % 839 == 0) {
        return 839;
    }
    if (n % 853 == 0) {
        return 853;
    }
    if (n % 857 == 0) {
        return 857;
    }
    if (n % 859 == 0) {
        return 859;
    }
    if (n % 863 == 0) {
        return 863;
    }
    if (n % 877 == 0) {
        return 877;
    }
    if (n % 881 == 0) {
        return 881;
    }
    if (n % 883 == 0) {
        return 883;
    }
    if (n % 887 == 0) {
        return 887;
    }
    if (n % 907 == 0) {
        return 907;
    }
    if (n % 911 == 0) {
        return 911;
    }
    if (n % 919 == 0) {
        return 919;
    }
    if (n % 929 == 0) {
        return 929;
    }
    if (n % 937 == 0) {
        return 937;
    }
    if (n % 941 == 0) {
        return 941;
    }
    if (n % 947 == 0) {
        return 947;
    }
    if (n % 953 == 0) {
        return 953;
    }
    if (n % 967 == 0) {
        return 967;
    }
    if (n % 971 == 0) {
        return 971;
    }
    if (n % 977 == 0) {
        return 977;
    }
    if (n % 983 == 0) {
        return 983;
    }
    if (n % 991 == 0) {
        return 991;
    }
    if (n % 997 == 0) {
        return 997;
    }
    return -1;
}

void PollardRho_findAllFactors(PollardRho *rho, int n, int *factors, int *factorsLen) {
    *factorsLen = 0;
    while (n > 1) {
        int f = PollardRho_findFactor(rho, n);
        factors[(*factorsLen)++] = f;
        while (n % f == 0) {
            n /= f;
        }
    }
}

typedef struct {
    int m;
    Power power;
    int *random;
} MillerRabin;

MillerRabin new_MillerRabin() {
    MillerRabin mr;
    mr.m = 0;
    mr.power = new_Power(new_Modular(0));
    mr.random = NULL;
    return mr;
}

int MillerRabin_mr(MillerRabin *mr, int n, int s) {
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    mr->m = n;
    mr->power = new_Power(new_Modular(n));
    mr->random = (int *)malloc(s * sizeof(int));
    for (int i = 0; i < s; i++) {
        mr->random[i] = rand() % (n - 2) + 2;
    }
    for (int i = 0; i < s; i++) {
        int x = mr->random[i];
        if (!MillerRabin_mr0(mr, x, n)) {
            free(mr->random);
            return 0;
        }
    }
    free(mr->random);
    return 1;
}

int MillerRabin_mr0(MillerRabin *mr, int x, int n) {
    int exp = n - 1;
    while (1) {
        int y = mr->power.pow(mr->power, x, exp);
        if (y != 1 && y != n - 1) {
            return 0;
        }
        if (y != 1 || exp % 2 == 1) {
            break;
        }
        exp = exp / 2;
    }
    return 1;
}

typedef struct {
    int m;
    Power power;
    MillerRabin millerRabin;
} NumberTheory;

NumberTheory new_NumberTheory(int m) {
    NumberTheory nt;
    nt.m = m;
    nt.power = new_Power(new_Modular(m));
    nt.millerRabin = new_MillerRabin();
    return nt;
}

int NumberTheory_pow(NumberTheory *nt, int x, int n) {
    return nt->power.pow(nt->power, x, n);
}

int NumberTheory_inverse(NumberTheory *nt, int x) {
    return nt->power.inverse(nt->power, x);
}

typedef struct {
    int m;
    Power power;
    NumberTheory numberTheory;
} FastOutput;

FastOutput new_FastOutput() {
    FastOutput fo;
    fo.m = 998244353;
    fo.power = new_Power(new_Modular(998244353));
    fo.numberTheory = new_NumberTheory(998244353);
    return fo;
}

FastOutput FastOutput_println(FastOutput fo, int c) {
    printf("%d\n", c);
    return fo;
}

void FastOutput_flush(FastOutput fo) {
    fflush(stdout);
}

typedef struct {
    int size;
    int cap;
    int *data;
} Deque;

Deque new_Deque(int cap) {
    Deque deque;
    deque.size = 0;
    deque.cap = cap;
    deque.data = (int *)malloc(cap * sizeof(int));
    return deque;
}

void Deque_ensureSpace(Deque *deque, int req) {
    if (req > deque->cap) {
        while (deque->cap < req) {
            deque->cap = deque->cap + 10 > deque->cap * 2 ? deque->cap + 10 : deque->cap * 2;
        }
        deque->data = (int *)realloc(deque->data, deque->cap * sizeof(int));
    }
}

void Deque_addLast(Deque *deque, int x) {
    Deque_ensureSpace(deque, deque->size + 1);
    deque->data[deque->size++] = x;
}

int Deque_removeFirst(Deque *deque) {
    return deque->data[--deque->size];
}

int Deque_size(Deque *deque) {
    return deque->size;
}

int Deque_get(Deque *deque, int i) {
    return deque->data[i];
}

typedef struct {
    int m;
    int *factors;
    Modular mod;
    Power pow;
    int phi;
    PrimitiveRoot root;
} NumberTheoryTransform;

NumberTheoryTransform new_NumberTheoryTransform(Modular mod) {
    NumberTheoryTransform ntt;
    ntt.m = mod.m;
    ntt.mod = mod;
    ntt.pow = new_Power(mod);
    ntt.factors = NULL;
    ntt.phi = mod.m - 1;
    ntt.root = new_PrimitiveRoot(mod);
    return ntt;
}

NumberTheoryTransform new_NumberTheoryTransform_int(int m) {
    return new_NumberTheoryTransform(new_Modular(m));
}

void NumberTheoryTransform_dotMul(NumberTheoryTransform *ntt, int *a, int *b, int *c, int m) {
    int n = 1 << m;
    for (int i = 0; i < n; i++) {
        c[i] = Modular_mul(new_Modular(ntt->m), a[i], b[i]);
    }
}

void NumberTheoryTransform_prepareReverse(int *r, int b) {
    int n = 1 << b;
    r[0] = 0;
    for (int i = 1; i < n; i++) {
        r[i] = (r[i >> 1] >> 1) | ((1 & i) << (b - 1));
    }
}

void NumberTheoryTransform_dft(NumberTheoryTransform *ntt, int *p, int m) {
    int n = 1 << m;

    int *rev = (int *)malloc(n * sizeof(int));
    NumberTheoryTransform_prepareReverse(rev, m);

    for (int i = 0; i < n; i++) {
        if (rev[i] > i) {
            int tmp = p[i];
            p[i] = p[rev[i]];
            p[rev[i]] = tmp;
        }
    }

    int w = 0;
    int t = 0;
    for (int d = 0; d < m; d++) {
        int w1 = ntt->root.findMinPrimitiveRoot_since(&ntt->root, 2);
        int s = 1 << d;
        int s2 = s << 1;
        for (int i = 0; i < n; i += s2) {
            w = 1;
            for (int j = 0; j < s; j++) {
                int a = i + j;
                int b = a + s;
                t = Modular_mul(new_Modular(ntt->m), w, p[b]);
                p[b] = Modular_plus(new_Modular(ntt->m), p[a], -t);
                p[a] = Modular_plus(new_Modular(ntt->m), p[a], t);
                w = Modular_mul(new_Modular(ntt->m), w, w1);
            }
        }
    }

    free(rev);
}

void NumberTheoryTransform_idft(NumberTheoryTransform *ntt, int *p, int m) {
    NumberTheoryTransform_dft(ntt, p, m);

    int n = 1 << m;
    int invN = ntt->pow.inverse(&ntt->pow, n);

    p[0] = Modular_mul(new_Modular(ntt->m), p[0], invN);
    p[n / 2] = Modular_mul(new_Modular(ntt->m), p[n / 2], invN);
    for (int i = 1, until = n / 2; i < until; i++) {
        int a = p[n - i];
        p[n - i] = Modular_mul(new_Modular(ntt->m), p[i], invN);
        p[i] = Modular_mul(new_Modular(ntt->m), a, invN);
    }
}

void NumberTheoryTransform_mulByPQ(NumberTheoryTransform *ntt, IntList *lists, IntList *ans) {
    int size = IntList_size(lists);
    IntList *pqs = (IntList *)malloc(size * sizeof(IntList));
    for (int i = 0; i < size; i++) {
        pqs[i] = IntList_clone(&lists->data[i]);
    }
    while (size > 1) {
        IntList *a = &pqs[0];
        IntList *b = &pqs[1];
        NumberTheoryTransform_multiplyAndStoreAnswerIntoA(ntt, a, b);
        IntList_clear(b);
        free(b->data);
        for (int i = 1; i < size - 1; i++) {
            pqs[i] = pqs[i + 1];
        }
        size--;
    }

    IntList *last = &pqs[0];
    IntList_clear(ans);
    IntList_addAll_IntList(ans, last);
    free(last->data);
    free(pqs);
}

void NumberTheoryTransform_multiplyAndStoreAnswerIntoA(NumberTheoryTransform *ntt, IntList *a, IntList *b) {
    int rankAns = a->size - 1 + b->size - 1;
    int proper = CachedLog2_ceilLog(rankAns + 1);
    IntList_expandWith(a, 0, 1 << proper);
    IntList_expandWith(b, 0, 1 << proper);
    NumberTheoryTransform_dft(ntt, a->data, proper);
    NumberTheoryTransform_dft(ntt, b->data, proper);
    NumberTheoryTransform_dotMul(ntt, a->data, b->data, a->data, proper);
    NumberTheoryTransform_idft(ntt, a->data, proper);
    IntList_retain(a, rankAns + 1);
}

typedef struct {
    int m;
    int *factors;
    Modular mod;
    Power pow;
    int phi;
    NumberTheoryTransform ntt;
} Polynomials;

Polynomials new_Polynomials(Modular mod) {
    Polynomials poly;
    poly.m = mod.m;
    poly.mod = mod;
    poly.pow = new_Power(mod);
    poly.factors = NULL;
    poly.phi = mod.m - 1;
    poly.ntt = new_NumberTheoryTransform(mod);
    return poly;
}

int Polynomials_rankOf(Polynomials *poly, IntList *p) {
    int r = p->size - 1;
    while (r >= 0 && p->data[r] == 0) {
        r--;
    }
    return r > 0 ? r : 0;
}

void Polynomials_normalize(Polynomials *poly, IntList *list) {
    IntList_retain(list, Polynomials_rankOf(poly, list) + 1);
}

typedef struct {
    int m;
    Power power;
    NumberTheoryTransform ntt;
} Power;

Power new_Power(Modular mod) {
    Power power;
    power.m = mod.m;
    power.power = new_Power(mod);
    power.ntt = new_NumberTheoryTransform(mod);
    return power;
}

int Power_pow(Power *power, int x, int n) {
    return power->power.pow(&power->power, x, n);
}

int Power_inverse(Power *power, int x) {
    return power->power.inverse(&power->power, x);
}

typedef struct {
    int m;
    Power power;
    Random random;
} Randomized;

Randomized new_Randomized() {
    Randomized random;
    random.m = 0;
    random.power = new_Power(new_Modular(0));
    random.random = NULL;
    return random;
}

int Randomized_nextInt(Randomized *random, int n) {
    return random->random() % n;
}

typedef struct {
    int m;
    Power power;
    Randomized random;
} PrimitiveRoot;

PrimitiveRoot new_PrimitiveRoot(Modular x) {
    PrimitiveRoot root;
    root.m = x.m;
    root.power = new_Power(x);
    root.random = new_Randomized();
    return root;
}

PrimitiveRoot new_PrimitiveRoot_int(int x) {
    return new_PrimitiveRoot(new_Modular(x));
}

int PrimitiveRoot_findMinPrimitiveRoot(PrimitiveRoot *root) {
    return PrimitiveRoot_findMinPrimitiveRoot_since(root, 2);
}

int PrimitiveRoot_findMinPrimitiveRoot_since(PrimitiveRoot *root, int since) {
    for (int i = since; i < root->m; i++) {
        int flag = 1;
        for (int j = 0; j < root->phi; j++) {
            if (root->power.pow(&root->power, i, root->phi / root->factors[j]) == 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}

typedef struct {
    int m;
    Power power;
    NumberTheory numberTheory;
} PrimitiveRoot;

PrimitiveRoot new_PrimitiveRoot(Modular x) {
    PrimitiveRoot root;
    root.m = x.m;
    root.power = new_Power(x);
    root.numberTheory = new_NumberTheory(x.m);
    return root;
}

PrimitiveRoot new_PrimitiveRoot_int(int x) {
    return new_PrimitiveRoot(new_Modular(x));
}

int PrimitiveRoot_findMinPrimitiveRoot(PrimitiveRoot *root) {
    return PrimitiveRoot_findMinPrimitiveRoot_since(root, 2);
}

int PrimitiveRoot_findMinPrimitiveRoot_since(PrimitiveRoot *root, int since) {
    for (int i = since; i < root->m; i++) {
        int flag = 1;
        for (int j = 0; j < root->numberTheory.phi; j++) {
            if (root->power.pow(&root->power, i, root->numberTheory.phi / root->numberTheory.factors[j]) == 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}

typedef struct {
    int m;
    Power power;
    NumberTheory numberTheory;
} CachedLog2;

CachedLog2 new_CachedLog2() {
    CachedLog2 log2;
    log2.m = 0;
    log2.power = new_Power(new_Modular(0));
    log2.numberTheory = new_NumberTheory(0);
    return log2;
}

int CachedLog2_ceilLog(CachedLog2 *log2, int x) {
    return CachedLog2_ceilLog_int(x);
}

int CachedLog2_ceilLog_int(int x) {
    int BITS = 16;
    int LIMIT = 1 << BITS;
    char CACHE[LIMIT];
    int b = 0;
    for (int i = 0; i < LIMIT; i++) {
        while ((1 << (b + 1)) <= i) {
            b++;
        }
        CACHE[i] = b;
    }
    return x < LIMIT ? CACHE[x] : (BITS + CACHE[x >> BITS]);
}

typedef struct {
    int m;
    Power power;
    NumberTheory numberTheory;
} GCDs;

GCDs new_GCDs() {
    GCDs gcds;
    gcds.m = 0;
    gcds.power = new_Power(new_Modular(0));
    gcds.numberTheory = new_NumberTheory(0);
    return gcds;
}

int GCDs_gcd(GCDs *gcds, int a, int b) {
    return gcds->numberTheory.numberTheory.gcd(&gcds->numberTheory.numberTheory, a, b);
}

typedef struct {
    int m;
    Power power;
    NumberTheory numberTheory;
} FastInput;

FastInput new_FastInput() {
    FastInput fi;
    fi.m = 0;
    fi.power = new_Power(new_Modular(0));
    fi.numberTheory = new_NumberTheory(0);
    return fi;
}

void FastInput_skipBlank(FastInput *fi) {
    while (fi->m >= 0 && fi->m <= 32) {
        fi->m = getchar();
    }
}

int FastInput_readInt(FastInput *fi) {
    int sign = 1;

    FastInput_skipBlank(fi);
    if (fi->m == '+' || fi->m == '-') {
        sign = fi->m == '+' ? 1 : -1;
        fi->m = getchar();
    }

    int val = 0;
    if (sign == 1) {
        while (fi->m >= '0' && fi->m <= '9') {
            val = val * 10 + fi->m - '0';
            fi->m = getchar();
        }
    } else {
        while (fi->m >= '0' && fi->m <= '9') {
            val = val * 10 - fi->m + '0';
            fi->m = getchar();
        }
    }

    return val;
}

typedef struct {
    int m;
    Power power;
    NumberTheory numberTheory;
} TaskG;

TaskG new_TaskG() {
    TaskG task;
    task.m = 0;
    task.power = new_Power(new_Modular(0));
    task.numberTheory = new_NumberTheory(0);
    return task;
}

void TaskG_solve(TaskG *task, int testNumber, FastInput *in, FastOutput *out) {
    int n = FastInput_readInt(in);
    int k = FastInput_readInt(in);
    int *allow = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < k; i++) {
        allow[FastInput_readInt(in)] = 1;
    }
    IntList p = new_IntList(0);
    IntList_addAll(&p, allow, 0, 10);

    int m = n / 2;
    IntList last = IntList_clone(&p);
    NumberTheoryTransform ntt = new_NumberTheoryTransform_int(998244353);

    IntList *lists = (IntList *)malloc(100 * sizeof(IntList));
    int listsLen = 0;
    while (m > 1) {
        if (m % 2 == 1) {
            lists[listsLen++] = IntList_clone(&last);
        }
        int proper = CachedLog2_ceilLog(2 * last.size);
        IntList_expandWith(&last, 0, 1 << proper);
        NumberTheoryTransform_dft(&ntt, last.data, proper);
        NumberTheoryTransform_dotMul(&ntt, last.data, last.data, last.data, proper);
        NumberTheoryTransform_idft(&ntt, last.data, proper);
        Polynomials_normalize(&ntt, &last);
        m /= 2;
    }
    lists[listsLen++] = IntList_clone(&last);

    IntList prod = new_IntList(0);
    NumberTheoryTransform_mulByPQ(&ntt, lists, &prod);

    int ans = 0;
    for (int i = 0; i < prod.size; i++) {
        int plus = prod.data[i];
        ans = Modular_plus(new_Modular(ntt.m), ans, Modular_mul(new_Modular(ntt.m), plus, plus));
    }

    FastOutput_println(out, ans);
}

int main() {
    TaskG task = new_TaskG();
    FastInput in = new_FastInput();
    FastOutput out = new_FastOutput();
    TaskG_solve(&task, 1, &in, &out);
    FastOutput_flush(out);
    return 0;
}
