#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} PointD;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    long numerator;
    long denominator;
} Fraction;

typedef struct {
    int n;
    long* t;
} id3;

typedef struct {
    int n;
    int m;
    long** t;
} id6;

typedef struct {
    int n;
    int m;
    int l;
    long*** t;
} id10;

void init_id3(id3* tree, int n) {
    tree->n = n;
    tree->t = (long*)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        tree->t[i] = 0;
    }
}

long sum_id3(id3* tree, int xl, int xr) {
    return sum_id3(tree, xr) - sum_id3(tree, xl - 1);
}

long sum_id3(id3* tree, int x) {
    long result = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        result += tree->t[i];
    }
    return result;
}

void update_id3(id3* tree, int x, long delta) {
    for (int i = x; i < tree->n; i = (i | (i + 1))) {
        tree->t[i] += delta;
    }
}

void init_id6(id6* tree, int n, int m) {
    tree->n = n;
    tree->m = m;
    tree->t = (long**)malloc(n * sizeof(long*));
    for (int i = 0; i < n; i++) {
        tree->t[i] = (long*)malloc(m * sizeof(long));
        for (int j = 0; j < m; j++) {
            tree->t[i][j] = 0;
        }
    }
}

long sum_id6(id6* tree, int xl, int yl, int xr, int yr) {
    return sum_id6(tree, xr, yr) - sum_id6(tree, xl - 1, yr) - sum_id6(tree, xr, yl - 1) + sum_id6(tree, xl - 1, yl - 1);
}

long sum_id6(id6* tree, int x, int y) {
    long result = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
            result += tree->t[i][j];
        }
    }
    return result;
}

void update_id6(id6* tree, int x, int y, long delta) {
    for (int i = x; i < tree->n; i = (i | (i + 1))) {
        for (int j = y; j < tree->m; j = (j | (j + 1))) {
            tree->t[i][j] += delta;
        }
    }
}

void init_id10(id10* tree, int n, int m, int l) {
    tree->n = n;
    tree->m = m;
    tree->l = l;
    tree->t = (long***)malloc(n * sizeof(long**));
    for (int i = 0; i < n; i++) {
        tree->t[i] = (long**)malloc(m * sizeof(long*));
        for (int j = 0; j < m; j++) {
            tree->t[i][j] = (long*)malloc(l * sizeof(long));
            for (int k = 0; k < l; k++) {
                tree->t[i][j][k] = 0;
            }
        }
    }
}

long sum_id10(id10* tree, int xl, int yl, int zl, int xr, int yr, int zr) {
    return sum_id10(tree, xr, yr, zr) - sum_id10(tree, xl - 1, yr, zr)
        + sum_id10(tree, xl - 1, yr, zl - 1) - sum_id10(tree, xr, yr, zl - 1)
        - sum_id10(tree, xr, yl - 1, zr) + sum_id10(tree, xl - 1, yl - 1, zr)
        - sum_id10(tree, xl - 1, yl - 1, zl - 1) + sum_id10(tree, xr, yl - 1, zl - 1);
}

long sum_id10(id10* tree, int x, int y, int z) {
    long result = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
            for (int k = z; k >= 0; k = (k & (k + 1)) - 1) {
                result += tree->t[i][j][k];
            }
        }
    }
    return result;
}

void update_id10(id10* tree, int x, int y, int z, long delta) {
    for (int i = x; i < tree->n; i = (i | (i + 1))) {
        for (int j = y; j < tree->n; j = (j | (j + 1))) {
            for (int k = z; k < tree->n; k = (k | (k + 1))) {
                tree->t[i][j][k] += delta;
            }
        }
    }
}

Fraction* create_fraction(long numerator, long denominator) {
    Fraction* fraction = (Fraction*)malloc(sizeof(Fraction));
    fraction->numerator = numerator;
    fraction->denominator = denominator;
    return fraction;
}

Fraction* add_fraction(Fraction* f1, Fraction* f2) {
    Fraction* result = create_fraction(0, 1);
    result->denominator = lcm(f1->denominator, f2->denominator);
    result->numerator = f1->numerator * (result->denominator / f1->denominator) + f2->numerator * (result->denominator / f2->denominator);
    return result;
}

Fraction* subtract_fraction(Fraction* f1, Fraction* f2) {
    Fraction* result = create_fraction(0, 1);
    result->denominator = lcm(f1->denominator, f2->denominator);
    result->numerator = f1->numerator * (result->denominator / f1->denominator) - f2->numerator * (result->denominator / f2->denominator);
    return result;
}

Fraction* multiply_fraction(Fraction* f1, Fraction* f2) {
    Fraction* result = create_fraction(0, 1);
    result->numerator = f1->numerator * f2->numerator;
    result->denominator = f1->denominator * f2->denominator;
    return result;
}

Fraction* divide_fraction(Fraction* f1, Fraction* f2) {
    Fraction* result = create_fraction(0, 1);
    result->numerator = f1->numerator * f2->denominator;
    result->denominator = f1->denominator * f2->numerator;
    return result;
}

Fraction* floor_fraction(Fraction* f) {
    Fraction* result = create_fraction(0, 1);
    result->numerator = (f->numerator / f->denominator) * f->denominator;
    return result;
}

Fraction* ceil_fraction(Fraction* f) {
    Fraction* result = create_fraction(0, 1);
    result->numerator = ((f->numerator / f->denominator) + 1) * f->denominator;
    return result;
}

Fraction* binpow_fraction(Fraction* f, int n) {
    if (n == 0) {
        Fraction* result = create_fraction(1, 1);
        return result;
    }
    if ((n & 1) == 0) {
        Fraction* b = binpow_fraction(f, n / 2);
        return multiply_fraction(b, b);
    }
    else {
        return multiply_fraction(binpow_fraction(f, n - 1), f);
    }
}

void init_id3(id3* tree, int n);
long sum_id3(id3* tree, int xl, int xr);
long sum_id3(id3* tree, int x);
void update_id3(id3* tree, int x, long delta);

void init_id6(id6* tree, int n, int m);
long sum_id6(id6* tree, int xl, int yl, int xr, int yr);
long sum_id6(id6* tree, int x, int y);
void update_id6(id6* tree, int x, int y, long delta);

void init_id10(id10* tree, int n, int m, int l);
long sum_id10(id10* tree, int xl, int yl, int zl, int xr, int yr, int zr);
long sum_id10(id10* tree, int x, int y, int z);
void update_id10(id10* tree, int x, int y, int z, long delta);

int main() {
    return 0;
}
