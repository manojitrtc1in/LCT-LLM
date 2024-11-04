#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

#define FAST_ALLOCATOR_MEMORY 1e6 + 42
int allocator_pos = 0;
char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];

typedef struct {
    char *s;
    int size;
    int *MOD;
    int *POW;
    int **hash;
    int **pows;
} id1;

void id1_init(id1 *str, const char *s, int n) {
    str->s = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(str->s, s);
    str->size = strlen(s);
    str->MOD = (int *)malloc(sizeof(int) * n);
    str->POW = (int *)malloc(sizeof(int) * n);
    str->hash = (int **)malloc(sizeof(int *) * n);
    str->pows = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        str->MOD[i] = id11();
        str->POW[i] = id11();
        str->hash[i] = (int *)malloc(sizeof(int) * (str->size + 1));
        str->pows[i] = (int *)malloc(sizeof(int) * (str->size + 1));
        str->hash[i][0] = 0;
        str->pows[i][0] = 1;
    }
}

void id1_destroy(id1 *str) {
    free(str->s);
    free(str->MOD);
    free(str->POW);
    for (int i = 0; i < n; i++) {
        free(str->hash[i]);
        free(str->pows[i]);
    }
    free(str->hash);
    free(str->pows);
}

void id1_add_char(id1 *str, char c) {
    str->s = (char *)realloc(str->s, sizeof(char) * (str->size + 2));
    str->s[str->size] = c;
    str->s[str->size + 1] = '\0';
    for (int i = 0; i < n; i++) {
        int m = str->MOD[i];
        int p = str->POW[i];
        int cp = str->pows[i][str->size];
        int cm = str->hash[i][str->size];
        cm = (cm * p + c) % m;
        cp = cp * p % m;
        str->hash[i][str->size + 1] = cm;
        str->pows[i][str->size + 1] = cp;
    }
    str->size++;
}

char *id1_substr(id1 *str, int L, int n) {
    char *substr = (char *)malloc(sizeof(char) * (n + 1));
    strncpy(substr, str->s + L, n);
    substr[n] = '\0';
    return substr;
}

bool id1_equal(id1 *str, int L1, int R1, int L2, int R2) {
    for (int i = 0; i < n; i++) {
        if (str->hash[i][R1] - str->hash[i][L1] * str->pows[i][R1 - L1] != str->hash[i][R2] - str->hash[i][L2] * str->pows[i][R2 - L2]) {
            return false;
        }
    }
    return true;
}

typedef struct {
    int t;
    int y;
    long long prefix_sum;
    long long speed;
    long long push;
    long long min_prefix_sum_in_subtree;
    struct Treap *left;
    struct Treap *right;
} Treap;

Treap *new_Treap(int t, long long val, long long speed) {
    Treap *node = (Treap *)malloc(sizeof(Treap));
    node->t = t;
    node->y = rand();
    node->prefix_sum = val;
    node->speed = speed;
    node->push = 0;
    node->min_prefix_sum_in_subtree = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void vertex_add(Treap *a, long long push) {
    a->prefix_sum += push;
    a->min_prefix_sum_in_subtree += push;
    a->push += push;
}

void push(Treap *a) {
    long long push = a->push;
    if (!push) return;
    if (a->left) {
        vertex_add(a->left, push);
    }
    if (a->right) {
        vertex_add(a->right, push);
    }
    a->push = 0;
}

long long smin(Treap *a) {
    return a ? a->min_prefix_sum_in_subtree : INF;
}

void recalc(Treap *a) {
    a->min_prefix_sum_in_subtree = min(smin(a->left), min(smin(a->right), a->prefix_sum));
}

Treap *merge(Treap *a, Treap *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->y < b->y) {
        push(a);
        a->right = merge(a->right, b);
        recalc(a);
        return a;
    }
    else {
        push(b);
        b->left = merge(a, b->left);
        recalc(b);
        return b;
    }
}

Treap *id12(Treap *a) {
    push(a);
    if (!a->left) {
        return a;
    }
    return id12(a->left);
}

Treap *id7(Treap *a) {
    push(a);
    if (!a->right) {
        return a;
    }
    return id7(a->right);
}

Treap *id2(Treap *a, long long v) {
    push(a);
    if (smin(a->left) <= v) {
        return id2(a->left, v);
    }
    if (a->prefix_sum <= v) return a;
    return id2(a->right, v);
}

void print_tree(Treap *a) {
    if (!a) return;
    print_tree(a->left);
    printf("%d ", a->t);
    print_tree(a->right);
}

int main() {
    srand(time(0));
    Treap *root = new_Treap(0, 0, 0);
    root = merge(root, new_Treap(2e9, 0, 0));
    int q = readInt();
    int t;
    int s, type;
    for (int i = 0; i < q; ++i) {
        type = readInt();
        if (type == 1) {
            t = readInt();
            s = readInt();
            Treap *l, *r;
            split(root, t, &l, &r);
            Treap *vr = id12(r);
            Treap *vl = id7(l);
            long long psum = vl->prefix_sum + (t - vl->t) * vl->speed;
            long long id5 = psum + (vr->t - t) * s;
            vertex_add(r, id5 - vr->prefix_sum);
            root = merge(l, merge(new_Treap(t, psum, s), r));
        }
        else if (type == 2) {
            t = readInt();
            Treap *l, *tr;
            split(root, t, &l, &tr);
            Treap *y, *r;
            split(tr, t + 1, &y, &r);
            Treap *vl = id7(l);
            Treap *vr = id12(r);
            long long id5 = vl->prefix_sum + (vr->t - vl->t) * vl->speed;
            vertex_add(r, id5 - vr->prefix_sum);
            root = merge(l, r);
        }
        else {
            int L = readInt();
            int R = readInt();
            long long v = readInt();
            if (v == 0) {
                printf("%d\n", L);
                continue;
            }
            Treap *l, *yr;
            split(root, L, &l, &yr);
            Treap *y, *r;
            split(yr, R + 1, &y, &r);
            if (!y) {
                printf("-1\n");
            }
            else {
                Treap *vl = id12(y);
                Treap *vr = id7(y);
                long long id13 = vl->prefix_sum - v;
                if (y->min_prefix_sum_in_subtree > id13) {
                    long long id5 = vr->prefix_sum + (R - vr->t) * vr->speed;
                    if (id5 > id13) {
                        printf("-1\n");
                    }
                    else {
                        printf("%lld\n", vr->t + (ld)(id13 - vr->prefix_sum) / vr->speed);
                    }
                }
                else {
                    Treap *h = id2(y, id13);
                    Treap *yl, *yr;
                    split(y, h->t, &yl, &yr);
                    Treap *vyl = id7(yl);
                    printf("%lld\n", vyl->t + (ld)(id13 - vyl->prefix_sum) / vyl->speed);
                    y = merge(yl, yr);
                }
            }
            root = merge(l, merge(y, r));
        }
    }
    return 0;
}

int buf_size = 4096;
unsigned char buf[buf_size];
int buf_len = 0, buf_pos = 0;

char readChar() {
    if (buf_pos == buf_len) {
        buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
        if (buf_pos == buf_len)
            return -1;
    }
    return buf[buf_pos++];
}

int peekChar() {
    if (buf_pos == buf_len) {
        buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
        if (buf_pos == buf_len)
            return -1;
    }
    return buf[buf_pos];
}

bool id6() {
    int c;
    while ((c = peekChar()) != -1 && c <= 32)
        buf_pos++;
    return c == -1;
}

void id10() {
    while (!id6() && buf[buf_pos] <= 32U)
        buf_pos++;
}

int readChar() {
    int c = getChar();
    while (c != -1 && c <= 32)
        c = getChar();
    return c;
}

int readUInt() {
    int c = readChar(), x = 0;
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return x;
}

template <class T>
T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    else if (c == '+')
        c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

double readDouble() {
    int s = 1, c = readChar();
    double x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    if (c == '.') {
        c = getChar();
        double coef = 1;
        while ('0' <= c && c <= '9')
            x += (c - '0') * (coef *= 1e-1), c = getChar();
    }
    return s == 1 ? x : -x;
}

void readWord(char *s) {
    int c = readChar();
    while (c > 32)
        *s++ = c, c = getChar();
    *s = 0;
}

bool readLine(char *s) {
    int c = getChar();
    while (c != '\n' && c != -1)
        *s++ = c, c = getChar();
    *s = 0;
    return c != -1;
}

int id3 = 0;
char write_buf[buf_size];

void writeChar(int x) {
    if (id3 == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), id3 = 0;
    write_buf[id3++] = x;
}

void flush() {
    if (id3)
        fwrite(write_buf, 1, id3, stdout), id3 = 0;
}

template <class T>
void writeInt(T x, char end, int output_len) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n < output_len)
        s[n++] = '0';
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

void writeWord(const char *s) {
    while (*s)
        writeChar(*s++);
}

void writeDouble(double x, int output_len) {
    if (x < 0)
        writeChar('-'), x = -x;
    int t = (int)x;
    writeInt(t), x -= t;
    writeChar('.');
    for (int i = output_len - 1; i > 0; i--) {
        x *= 10;
        t = std::min(9, (int)x);
        writeChar('0' + t), x -= t;
    }
    x *= 10;
    t = std::min(9, (int)(x + 0.5));
    writeChar('0' + t);
}
