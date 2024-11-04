#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll gcd(ll a, ll b, ll* x, ll* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll d = gcd(b % a, a, y, x);
    *x -= (b / a) * (*y);
    return d;
}

typedef struct {
    int n;
} modint;

modint modint_init(ll n, int special) {
    modint m;
    if (special) {
        m.n = -1;
        return m;
    }
    if (n >= 0 && n < mod) {
        m.n = n;
        return m;
    }
    n %= mod;
    if (n < 0) {
        n += mod;
    }
    m.n = n;
    return m;
}

modint modint_add(modint a, modint b) {
    if (a.n == -1 || b.n == -1) {
        printf("Illegal state\n");
        exit(1);
    }
    a.n += b.n;
    if (a.n >= mod) {
        a.n -= mod;
    }
    return a;
}

modint modint_sub(modint a, modint b) {
    if (a.n == -1 || b.n == -1) {
        printf("Illegal state\n");
        exit(1);
    }
    a.n -= b.n;
    if (a.n < 0) {
        a.n += mod;
    }
    return a;
}

modint modint_mul(modint a, modint b) {
    if (a.n == -1 || b.n == -1) {
        printf("Illegal state\n");
        exit(1);
    }
    a.n = ((ll)a.n * b.n) % mod;
    return a;
}

modint modint_div(modint a, modint b) {
    if (b.n == 0) {
        printf("Division by zero\n");
        exit(1);
    }
    if (a.n == -1 || b.n == -1) {
        printf("Illegal state\n");
        exit(1);
    }
    return modint_mul(a, modint_inverse(b));
}

modint modint_neg(modint a) {
    if (a.n == -1) {
        printf("Illegal state\n");
        exit(1);
    }
    if (a.n == 0) {
        return a;
    }
    return modint_init(mod - a.n, 0);
}

modint modint_inverse(modint a) {
    if (a.n == -1) {
        printf("Illegal state\n");
        exit(1);
    }
    ll x, y;
    ll g = gcd((ll)a.n, (ll)mod, &x, &y);
    if (g != 1) {
        printf("not inversable\n");
        exit(1);
    }
    return modint_init(x, 0);
}

int modint_log(modint a, modint alpha) {
    if (a.n == -1 || alpha.n == -1) {
        printf("Illegal state\n");
        exit(1);
    }
    int base[mod];
    int exp = 0;
    modint pow = modint_init(1, 0);
    modint inv = a;
    modint alInv = modint_inverse(alpha);
    while (exp * exp < mod) {
        if (inv.n == 1) {
            return exp;
        }
        base[inv.n] = exp++;
        pow = modint_mul(pow, alpha);
        inv = modint_mul(inv, alInv);
    }
    modint step = pow;
    for (int i = 1; ; i++) {
        if (base[pow.n]) {
            return exp * i + base[pow.n];
        }
        pow = modint_mul(pow, step);
    }
}

int mod = 1000000007;

typedef struct {
    int size;
    modint* value;
} id7;

id7 id7_init(int size) {
    id7 ft;
    ft.size = size;
    ft.value = (modint*)malloc(size * sizeof(modint));
    for (int i = 0; i < size; i++) {
        ft.value[i] = modint_init(0, 0);
    }
    return ft;
}

void id7_add(id7* ft, int at, modint v) {
    while (at < ft->size) {
        ft->value[at] = modint_add(ft->value[at], v);
        at |= (at + 1);
    }
}

modint id7_get(const id7* ft, int to) {
    if (to < 0 || to >= ft->size) {
        printf("Out of bounds\n");
        exit(1);
    }
    modint result = modint_init(0, 0);
    while (to >= 0) {
        result = modint_add(result, ft->value[to]);
        to = (to & (to + 1)) - 1;
    }
    return result;
}

modint id7_get_range(const id7* ft, int from, int to) {
    if (from >= to) {
        return modint_init(0, 0);
    }
    return modint_sub(id7_get(ft, to - 1), id7_get(ft, from - 1));
}

void id7_clear(id7* ft) {
    for (int i = 0; i < ft->size; i++) {
        ft->value[i] = modint_init(0, 0);
    }
}

typedef struct {
    int n;
} NumberIterator;

NumberIterator NumberIterator_init(int v) {
    NumberIterator ni;
    ni.n = v;
    return ni;
}

NumberIterator NumberIterator_inc(NumberIterator* ni) {
    ni->n--;
    return *ni;
}

typedef struct {
    NumberIterator first;
    NumberIterator second;
} RevRange;

RevRange RevRange_init(int begin, int end) {
    RevRange rr;
    rr.first = NumberIterator_init(begin - 1);
    rr.second = NumberIterator_init(begin < end ? begin : end - 1);
    return rr;
}

NumberIterator RevRange_begin(const RevRange* rr) {
    return rr->first;
}

NumberIterator RevRange_end(const RevRange* rr) {
    return rr->second;
}

typedef struct {
    int n;
    modint* b;
} arr;

arr arr_init(int n) {
    arr a;
    a.n = n;
    a.b = (modint*)malloc(n * sizeof(modint));
    return a;
}

arr arr_init_with_value(int n, modint init) {
    arr a = arr_init(n);
    for (int i = 0; i < n; i++) {
        a.b[i] = init;
    }
    return a;
}

modint arr_get(const arr* a, int at) {
    if (at < 0 || at >= a->n) {
        printf("Out of bounds\n");
        exit(1);
    }
    return a->b[at];
}

void arr_set(arr* a, int at, modint v) {
    if (at < 0 || at >= a->n) {
        printf("Out of bounds\n");
        exit(1);
    }
    a->b[at] = v;
}

typedef struct {
    int d1;
    int d2;
    int sz;
    modint* b;
} id2;

id2 id2_init(int d1, int d2) {
    id2 a;
    a.d1 = d1;
    a.d2 = d2;
    a.sz = d1 * d2;
    a.b = (modint*)malloc(a.sz * sizeof(modint));
    return a;
}

int id2_size(const id2* a) {
    return a->sz;
}

int id2_dim1(const id2* a) {
    return a->d1;
}

int id2_dim2(const id2* a) {
    return a->d2;
}

modint id2_get(const id2* a, int i1, int i2) {
    if (i1 < 0 || i1 >= a->d1 || i2 < 0 || i2 >= a->d2) {
        printf("Out of bounds\n");
        exit(1);
    }
    return a->b[i1 * a->d2 + i2];
}

void id2_set(id2* a, int i1, int i2, modint v) {
    if (i1 < 0 || i1 >= a->d1 || i2 < 0 || i2 >= a->d2) {
        printf("Out of bounds\n");
        exit(1);
    }
    a->b[i1 * a->d2 + i2] = v;
}

arr id2_get_row(const id2* a, int at) {
    if (at < 0 || at >= a->d1) {
        printf("Out of bounds\n");
        exit(1);
    }
    arr res = arr_init(a->d2);
    for (int i = 0; i < a->d2; i++) {
        res.b[i] = a->b[at * a->d2 + i];
    }
    return res;
}

typedef struct {
    int begin;
    int end;
} range;

range range_init(int begin, int end) {
    range r;
    r.begin = begin;
    r.end = begin < end ? begin : end;
    return r;
}

typedef struct {
    int v;
} id0;

id0 id0_init(int v) {
    id0 i;
    i.v = v;
    return i;
}

id0 id0_inc(id0* i) {
    --i->v;
    return *i;
}

typedef struct {
    int n;
    modint* b;
} id1;

id1 id1_init(int n) {
    id1 i;
    i.n = n;
    i.b = (modint*)malloc(n * sizeof(modint));
    return i;
}

void id1_set(id1* i, int at, modint v) {
    if (at < 0 || at >= i->n) {
        printf("Out of bounds\n");
        exit(1);
    }
    i->b[at] = v;
}

modint id1_get(const id1* i, int at) {
    if (at < 0 || at >= i->n) {
        printf("Out of bounds\n");
        exit(1);
    }
    return i->b[at];
}

typedef struct {
    int n;
    modint* b;
} id3;

id3 id3_init(int n) {
    id3 i;
    i.n = n;
    i.b = (modint*)malloc(n * sizeof(modint));
    return i;
}

void id3_set(id3* i, int at, modint v) {
    if (at < 0 || at >= i->n) {
        printf("Out of bounds\n");
        exit(1);
    }
    i->b[at] = v;
}

modint id3_get(const id3* i, int at) {
    if (at < 0 || at >= i->n) {
        printf("Out of bounds\n");
        exit(1);
    }
    return i->b[at];
}

typedef struct {
    int id1;
    int bufSize;
    char* buf;
    int bufRead;
    int bufAt;
} Input;

Input Input_init() {
    Input i;
    i.id1 = 0;
    i.bufSize = 4096;
    i.buf = (char*)malloc(i.bufSize * sizeof(char));
    i.bufRead = 0;
    i.bufAt = 0;
    return i;
}

int Input_get(Input* i) {
    if (i->id1) {
        printf("Input id1\n");
        exit(1);
    }
    if (i->bufRead == i->bufAt) {
        i->bufRead = fread(i->buf, sizeof(char), i->bufSize, stdin);
        i->bufAt = 0;
    }
    if (i->bufRead == i->bufAt) {
        i->id1 = 1;
        return EOF;
    }
    return i->buf[i->bufAt++];
}

int Input_peek(const Input* i) {
    if (i->id1) {
        return EOF;
    }
    if (i->bufRead == i->bufAt) {
        i->bufRead = fread(i->buf, sizeof(char), i->bufSize, stdin);
        i->bufAt = 0;
    }
    if (i->bufRead == i->bufAt) {
        i->id1 = 1;
        getchar();
        return EOF;
    }
    return i->buf[i->bufAt];
}

int Input_skipWhitespace(Input* i) {
    int c;
    while ((c = Input_get(i)) != EOF && (c == ' ' || c == '\t' || c == '\n' || c == '\r'));
    return c;
}

int Input_readInt(Input* i) {
    int c = Input_skipWhitespace(i);
    int sgn = 1;
    if (c == '-') {
        sgn = -1;
        c = Input_get(i);
    } else if (c == '+') {
        c = Input_get(i);
    }
    int res = 0;
    do {
        if (c < '0' || c > '9') {
            printf("Number format error\n");
            exit(1);
        }
        res *= 10;
        res += c - '0';
        c = Input_get(i);
    } while (c != EOF && c != ' ' && c != '\t' && c != '\n' && c != '\r');
    return res * sgn;
}

typedef struct {
    int size;
    modint* b;
} id4;

id4 id4_init(int size) {
    id4 a;
    a.size = size;
    a.b = (modint*)malloc(size * sizeof(modint));
    return a;
}

void id4_set(id4* a, int at, modint v) {
    if (at < 0 || at >= a->size) {
        printf("Out of bounds\n");
        exit(1);
    }
    a->b[at] = v;
}

modint id4_get(const id4* a, int at) {
    if (at < 0 || at >= a->size) {
        printf("Out of bounds\n");
        exit(1);
    }
    return a->b[at];
}

typedef struct {
    int d1;
    int d2;
    int sz;
    modint* b;
} id5;

id5 id5_init(int d1, int d2) {
    id5 a;
    a.d1 = d1;
    a.d2 = d2;
    a.sz = d1 * d2;
    a.b = (modint*)malloc(a.sz * sizeof(modint));
    return a;
}

int id5_size(const id5* a) {
    return a->sz;
}

int id5_dim1(const id5* a) {
    return a->d1;
}

int id5_dim2(const id5* a) {
    return a->d2;
}

modint id5_get(const id5* a, int i1, int i2) {
    if (i1 < 0 || i1 >= a->d1 || i2 < 0 || i2 >= a->d2) {
        printf("Out of bounds\n");
        exit(1);
    }
    return a->b[i1 * a->d2 + i2];
}

void id5_set(id5* a, int i1, int i2, modint v) {
    if (i1 < 0 || i1 >= a->d1 || i2 < 0 || i2 >= a->d2) {
        printf("Out of bounds\n");
        exit(1);
    }
    a->b[i1 * a->d2 + i2] = v;
}

typedef struct {
    int id1;
    FILE* out;
} Output;

Output Output_init(FILE* out) {
    Output o;
    o.id1 = 0;
    o.out = out;
    return o;
}

void Output_print(Output* o) {
    if (o->id1) {
        printf("Output id1\n");
        exit(1);
    }
}

void Output_print_single(Output* o, int value) {
    fprintf(o->out, "%d", value);
}

void Output_print_single_arr(Output* o, const arr* array) {
    for (int i = 0; i < array->n; i++) {
        fprintf(o->out, "%d", array->b[i].n);
        if (i + 1 != array->n) {
            fprintf(o->out, " ");
        }
    }
}

void Output_print_single_id2(Output* o, const id2* array) {
    for (int i = 0; i < array->d1; i++) {
        for (int j = 0; j < array->d2; j++) {
            fprintf(o->out, "%d", array->b[i * array->d2 + j].n);
            if (j + 1 != array->d2) {
                fprintf(o->out, " ");
            }
        }
        if (i + 1 != array->d1) {
            fprintf(o->out, "\n");
        }
    }
}

void Output_print_single(Output* o, const id2* array) {
    Output_print_single_id2(o, array);
}

void Output_print_single(Output* o, const id4* array) {
    for (int i = 0; i < array->size; i++) {
        fprintf(o->out, "%d", array->b[i].n);
        if (i + 1 != array->size) {
            fprintf(o->out, " ");
        }
    }
}

void Output_print_single(Output* o, const id5* array) {
    for (int i = 0; i < array->d1; i++) {
        for (int j = 0; j < array->d2; j++) {
            fprintf(o->out, "%d", array->b[i * array->d2 + j].n);
            if (j + 1 != array->d2) {
                fprintf(o->out, " ");
            }
        }
        if (i + 1 != array->d1) {
            fprintf(o->out, "\n");
        }
    }
}

void Output_print_single(Output* o, const modint* value) {
    fprintf(o->out, "%d", value->n);
}

void Output_print_single(Output* o, const char* value) {
    fprintf(o->out, "%s", value);
}

void Output_print_single(Output* o, const char value) {
    fprintf(o->out, "%c", value);
}

void Output_print_single(Output* o, const char* value, int size) {
    for (int i = 0; i < size; i++) {
        fprintf(o->out, "%c", value[i]);
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset) {
    for (int i = offset; i < offset + size; i++) {
        fprintf(o->out, "%c", value[i]);
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride) {
    for (int i = offset; i < offset + size; i += stride) {
        fprintf(o->out, "%c", value[i]);
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(o->out, "%c", value[offset + i * stride]);
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2) {
    for (int i = 0; i < count; i++) {
        fprintf(o->out, "%c", value[offset + i * stride + offset2]);
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2) {
    for (int i = 0; i < count; i++) {
        fprintf(o->out, "%c", value[offset + i * stride + offset2 * stride2]);
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2) {
    for (int i = 0; i < count2; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3) {
    for (int i = 0; i < count2; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3) {
    for (int i = 0; i < count2; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3) {
    for (int i = 0; i < count3; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4) {
    for (int i = 0; i < count3; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4) {
    for (int i = 0; i < count3; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4) {
    for (int i = 0; i < count4; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5) {
    for (int i = 0; i < count4; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5) {
    for (int i = 0; i < count4; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5) {
    for (int i = 0; i < count5; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6) {
    for (int i = 0; i < count5; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6, int stride6) {
    for (int i = 0; i < count5; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6 * stride6]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6, int stride6, int count6) {
    for (int i = 0; i < count6; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6 * stride6]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6, int stride6, int count6, int offset7) {
    for (int i = 0; i < count6; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6 * stride6 + offset7]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6, int stride6, int count6, int offset7, int stride7) {
    for (int i = 0; i < count6; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6 * stride6 + offset7 * stride7]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const char* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6, int stride6, int count6, int offset7, int stride7, int count7) {
    for (int i = 0; i < count7; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%c", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6 * stride6 + offset7 * stride7]);
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size) {
    for (int i = 0; i < size; i++) {
        fprintf(o->out, "%d", value[i].n);
        if (i + 1 != size) {
            fprintf(o->out, " ");
        }
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset) {
    for (int i = offset; i < offset + size; i++) {
        fprintf(o->out, "%d", value[i].n);
        if (i + 1 != offset + size) {
            fprintf(o->out, " ");
        }
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride) {
    for (int i = offset; i < offset + size; i += stride) {
        fprintf(o->out, "%d", value[i].n);
        if (i + stride != offset + size) {
            fprintf(o->out, " ");
        }
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(o->out, "%d", value[offset + i * stride].n);
        if (i + 1 != count) {
            fprintf(o->out, " ");
        }
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2) {
    for (int i = 0; i < count; i++) {
        fprintf(o->out, "%d", value[offset + i * stride + offset2].n);
        if (i + 1 != count) {
            fprintf(o->out, " ");
        }
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2) {
    for (int i = 0; i < count; i++) {
        fprintf(o->out, "%d", value[offset + i * stride + offset2 * stride2].n);
        if (i + 1 != count) {
            fprintf(o->out, " ");
        }
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2) {
    for (int i = 0; i < count2; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3) {
    for (int i = 0; i < count2; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3) {
    for (int i = 0; i < count2; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3) {
    for (int i = 0; i < count3; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4) {
    for (int i = 0; i < count3; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4) {
    for (int i = 0; i < count3; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4) {
    for (int i = 0; i < count4; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5) {
    for (int i = 0; i < count4; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5) {
    for (int i = 0; i < count4; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5) {
    for (int i = 0; i < count5; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6) {
    for (int i = 0; i < count5; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6, int stride6) {
    for (int i = 0; i < count5; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6 * stride6].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6, int stride6, int count6) {
    for (int i = 0; i < count6; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6 * stride6].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6, int stride6, int count6, int offset7) {
    for (int i = 0; i < count6; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6 * stride6 + offset7].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

void Output_print_single(Output* o, const modint* value, int size, int offset, int stride, int count, int offset2, int stride2, int count2, int offset3, int stride3, int count3, int offset4, int stride4, int count4, int offset5, int stride5, int count5, int offset6, int stride6, int count6, int offset7, int stride7) {
    for (int i = 0; i < count6; i++) {
        for (int j = 0; j < count; j++) {
            fprintf(o->out, "%d", value[offset + j * stride + (offset2 + i * stride2) * stride + offset3 * stride3 + offset4 * stride4 + offset5 * stride5 + offset6 * stride6 + offset7 * stride7].n);
            if (j + 1 != count) {
                fprintf(o->out, " ");
            }
        }
        fprintf(o->out, "\n");
    }
}

