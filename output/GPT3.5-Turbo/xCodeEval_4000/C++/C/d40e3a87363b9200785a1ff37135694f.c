#include <stdio.h>
#include <stdlib.h>

typedef long long int64;

const int mod = 998244353;

typedef struct {
  int64 x;
} modint;

modint modint_create(int64 y) {
  modint m;
  m.x = (y >= 0 ? y % mod : (mod - (-y) % mod) % mod);
  return m;
}

modint modint_add(modint a, modint b) {
  modint res;
  res.x = (a.x + b.x) % mod;
  return res;
}

modint modint_sub(modint a, modint b) {
  modint res;
  res.x = (a.x + mod - b.x) % mod;
  return res;
}

modint modint_mul(modint a, modint b) {
  modint res;
  res.x = (a.x * b.x) % mod;
  return res;
}

modint modint_inverse(modint a) {
  int x = a.x, b = mod, u = 1, v = 0, t;
  while (b > 0) {
    t = x / b;
    x -= t * b;
    u -= t * v;
    t = x;
    x = b;
    b = t;
    t = u;
    u = v;
    v = t;
  }
  modint res;
  res.x = u;
  return res;
}

modint modint_pow(modint a, int64 n) {
  modint res;
  res.x = 1;
  while (n > 0) {
    if (n & 1) {
      res = modint_mul(res, a);
    }
    a = modint_mul(a, a);
    n >>= 1;
  }
  return res;
}

typedef struct {
  int num, dom;
} fraction;

fraction fraction_create(int num, int dom) {
  fraction f;
  f.num = num;
  f.dom = dom;
  return f;
}

fraction fraction_add(fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.dom + b.num * a.dom;
  res.dom = a.dom * b.dom;
  return res;
}

fraction fraction_sub(fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.dom - b.num * a.dom;
  res.dom = a.dom * b.dom;
  return res;
}

fraction fraction_mul(fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.num;
  res.dom = a.dom * b.dom;
  return res;
}

fraction fraction_div(fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.dom;
  res.dom = a.dom * b.num;
  return res;
}

typedef struct {
  int right, type;
} Node;

typedef struct {
  modint A[4][4];
} Matrix;

Matrix Matrix_create() {
  Matrix mat;
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      mat.A[i][j] = modint_create(0);
    }
  }
  return mat;
}

Matrix Matrix_I(int n) {
  Matrix mat = Matrix_create();
  int i;
  for (i = 0; i < n; i++) {
    mat.A[i][i] = modint_create(1);
  }
  return mat;
}

Matrix Matrix_add(Matrix a, Matrix b) {
  Matrix res = Matrix_create();
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      res.A[i][j] = modint_add(a.A[i][j], b.A[i][j]);
    }
  }
  return res;
}

Matrix Matrix_sub(Matrix a, Matrix b) {
  Matrix res = Matrix_create();
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      res.A[i][j] = modint_sub(a.A[i][j], b.A[i][j]);
    }
  }
  return res;
}

Matrix Matrix_mul(Matrix a, Matrix b) {
  Matrix res = Matrix_create();
  int i, j, k;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        res.A[i][j] = modint_add(res.A[i][j], modint_mul(a.A[i][k], b.A[k][j]));
      }
    }
  }
  return res;
}

Matrix Matrix_pow(Matrix a, int64 k) {
  Matrix res = Matrix_I(4);
  while (k > 0) {
    if (k & 1) {
      res = Matrix_mul(res, a);
    }
    a = Matrix_mul(a, a);
    k >>= 1;
  }
  return res;
}

Matrix Matrix_copy(Matrix a) {
  Matrix res = Matrix_create();
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      res.A[i][j] = a.A[i][j];
    }
  }
  return res;
}

Matrix Matrix_zero() {
  Matrix res = Matrix_create();
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      res.A[i][j] = modint_create(0);
    }
  }
  return res;
}

Matrix Matrix_one() {
  Matrix res = Matrix_create();
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      res.A[i][j] = modint_create(1);
    }
  }
  return res;
}

Matrix Matrix_create_from_values(modint a, modint b, modint c, modint d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][1] = b;
  res.A[1][2] = c;
  res.A[1][3] = d;
  return res;
}

Matrix Matrix_create_from_fraction(fraction a, fraction b) {
  Matrix res = Matrix_create();
  res.A[0][0] = modint_create(a.num);
  res.A[0][1] = modint_create(a.dom);
  res.A[1][2] = modint_create(b.num);
  res.A[1][3] = modint_create(b.dom);
  return res;
}

Matrix Matrix_create_from_modint(modint a, modint b) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][1] = a;
  res.A[1][2] = b;
  res.A[1][3] = b;
  return res;
}

Matrix Matrix_create_from_modint_and_fraction(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][1] = b;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction2(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction3(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction4(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction5(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction6(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction7(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction8(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction9(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction10(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction11(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction12(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction13(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction14(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction15(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction16(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction17(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction18(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction19(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction20(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction21(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][2] = modint_create(c.num);
  res.A[1][1] = a;
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = b;
  res.A[2][0] = modint_create(d.num);
  res.A[3][3] = b;
  res.A[3][1] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction22(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = a;
  res.A[0][1] = b;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction23(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction24(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction25(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction26(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction27(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction28(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction29(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction30(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction31(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction32(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction33(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction34(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction35(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction36(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction37(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction38(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction39(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction40(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction41(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction42(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction43(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction44(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction45(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction46(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction47(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction48(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction49(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_create_from_modint_and_fraction50(modint a, modint b, fraction c, fraction d) {
  Matrix res = Matrix_create();
  res.A[0][0] = b;
  res.A[0][1] = a;
  res.A[1][2] = modint_create(c.num);
  res.A[1][3] = modint_create(c.dom);
  res.A[2][2] = modint_create(d.num);
  res.A[2][3] = modint_create(d.dom);
  return res;
}

Matrix Matrix_zero() {
  return Matrix_create();
}

Matrix Matrix_one() {
  return Matrix_I(4);
}

Matrix Matrix_copy(Matrix a) {
  return a;
}

Matrix Matrix_add(Matrix a, Matrix b) {
  return Matrix_add(a, b);
}

Matrix Matrix_sub(Matrix a, Matrix b) {
  return Matrix_sub(a, b);
}

Matrix Matrix_mul(Matrix a, Matrix b) {
  return Matrix_mul(a, b);
}

Matrix Matrix_pow(Matrix a, int64 k) {
  return Matrix_pow(a, k);
}

Matrix Matrix_create_from_values(modint a, modint b, modint c, modint d) {
  return Matrix_create_from_values(a, b, c, d);
}

Matrix Matrix_create_from_fraction(fraction a, fraction b) {
  return Matrix_create_from_fraction(a, b);
}

Matrix Matrix_create_from_modint(modint a, modint b) {
  return Matrix_create_from_modint(a, b);
}

Matrix Matrix_create_from_modint_and_fraction(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction2(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction2(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction3(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction3(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction4(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction4(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction5(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction5(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction6(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction6(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction7(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction7(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction8(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction8(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction9(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction9(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction10(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction10(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction11(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction11(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction12(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction12(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction13(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction13(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction14(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction14(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction15(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction15(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction16(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction16(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction17(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction17(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction18(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction18(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction19(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction19(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction20(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction20(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction21(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction21(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction22(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction22(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction23(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction23(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction24(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction24(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction25(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction25(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction26(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction26(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction27(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction27(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction28(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction28(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction29(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction29(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction30(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction30(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction31(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction31(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction32(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction32(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction33(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction33(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction34(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction34(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction35(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction35(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction36(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction36(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction37(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction37(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction38(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction38(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction39(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction39(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction40(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction40(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction41(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction41(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction42(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction42(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction43(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction43(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction44(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction44(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction45(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction45(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction46(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction46(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction47(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction47(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction48(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction48(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction49(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction49(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction50(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction50(a, b, c, d);
}

Matrix Matrix_zero() {
  return Matrix_create();
}

Matrix Matrix_one() {
  return Matrix_I(4);
}

Matrix Matrix_copy(Matrix a) {
  return a;
}

Matrix Matrix_add(Matrix a, Matrix b) {
  return Matrix_add(a, b);
}

Matrix Matrix_sub(Matrix a, Matrix b) {
  return Matrix_sub(a, b);
}

Matrix Matrix_mul(Matrix a, Matrix b) {
  return Matrix_mul(a, b);
}

Matrix Matrix_pow(Matrix a, int64 k) {
  return Matrix_pow(a, k);
}

Matrix Matrix_create_from_values(modint a, modint b, modint c, modint d) {
  return Matrix_create_from_values(a, b, c, d);
}

Matrix Matrix_create_from_fraction(fraction a, fraction b) {
  return Matrix_create_from_fraction(a, b);
}

Matrix Matrix_create_from_modint(modint a, modint b) {
  return Matrix_create_from_modint(a, b);
}

Matrix Matrix_create_from_modint_and_fraction(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction2(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction2(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction3(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction3(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction4(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction4(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction5(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction5(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction6(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction6(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction7(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction7(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction8(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction8(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction9(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction9(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction10(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction10(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction11(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction11(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction12(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction12(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction13(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction13(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction14(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction14(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction15(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction15(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction16(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction16(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction17(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction17(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction18(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction18(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction19(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction19(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction20(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction20(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction21(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction21(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction22(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction22(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction23(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction23(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction24(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction24(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction25(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction25(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction26(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction26(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction27(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction27(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction28(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction28(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction29(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction29(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction30(modint a, modint b, fraction c, fraction d) {
  return Matrix_create_from_modint_and_fraction30(a, b, c, d);
}

Matrix Matrix_create_from_modint_and_fraction31(modint a, modint b, fraction c, fraction d) {
