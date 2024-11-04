#include <stdio.h>
#include <stdlib.h>

typedef long long int64;

const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

typedef struct {
  int right, type;
} Node;

typedef struct {
  int x;
} modint;

modint ModInt(int64_t y) {
  modint m;
  m.x = y >= 0 ? y % mod : (mod - (-y) % mod) % mod;
  return m;
}

modint operator+(const modint a, const modint b) {
  modint res;
  res.x = (a.x + b.x) % mod;
  return res;
}

modint operator-(const modint a, const modint b) {
  modint res;
  res.x = (a.x + mod - b.x) % mod;
  return res;
}

modint operator*(const modint a, const modint b) {
  modint res;
  res.x = (int)(((long long)a.x * b.x) % mod);
  return res;
}

modint operator/(const modint a, const modint b) {
  modint res;
  modint inv = b;
  inv.x = mod - inv.x;
  res = a * inv;
  return res;
}

modint operator-(const modint a) {
  modint res;
  res.x = mod - a.x;
  return res;
}

bool operator==(const modint a, const modint b) {
  return a.x == b.x;
}

bool operator!=(const modint a, const modint b) {
  return a.x != b.x;
}

modint inverse(const modint a) {
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
  u %= mod;
  if (u < 0) u += mod;
  modint res;
  res.x = u;
  return res;
}

modint pow(const modint a, int64_t n) {
  modint ret = ModInt(1), mul = a;
  while (n > 0) {
    if (n & 1) ret = ret * mul;
    mul = mul * mul;
    n >>= 1;
  }
  return ret;
}

typedef struct {
  modint num, dom;
} fraction;

fraction Fraction(int64_t n, int64_t d) {
  fraction f;
  f.num = ModInt(n);
  f.dom = ModInt(d);
  return f;
}

fraction operator+(const fraction a, const fraction b) {
  fraction res;
  res.num = a.num * b.dom + b.num * a.dom;
  res.dom = a.dom * b.dom;
  return res;
}

fraction operator-(const fraction a, const fraction b) {
  fraction res;
  res.num = a.num * b.dom - b.num * a.dom;
  res.dom = a.dom * b.dom;
  return res;
}

fraction operator*(const fraction a, const fraction b) {
  fraction res;
  res.num = a.num * b.num;
  res.dom = a.dom * b.dom;
  return res;
}

fraction operator/(const fraction a, const fraction b) {
  fraction res;
  res.num = a.num * b.dom;
  res.dom = a.dom * b.num;
  return res;
}

fraction operator*(const fraction a, int64_t k) {
  fraction res;
  res.num = a.num * k;
  res.dom = a.dom;
  return res;
}

fraction operator/(const fraction a, int64_t k) {
  fraction res;
  res.num = a.num;
  res.dom = a.dom * k;
  return res;
}

bool operator<(const fraction a, const fraction b) {
  return a.num * b.dom < b.num * a.dom;
}

bool operator>(const fraction a, const fraction b) {
  return a.num * b.dom > b.num * a.dom;
}

bool operator==(const fraction a, const fraction b) {
  return a.num * b.dom == b.num * a.dom;
}

bool operator!=(const fraction a, const fraction b) {
  return a.num * b.dom != b.num * a.dom;
}

bool operator<=(const fraction a, const fraction b) {
  return a.num * b.dom <= b.num * a.dom;
}

bool operator>=(const fraction a, const fraction b) {
  return a.num * b.dom >= b.num * a.dom;
}

typedef struct {
  modint A[4][4];
} Matrix;

Matrix MatrixI(int n) {
  Matrix mat;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat.A[i][j] = i == j ? ModInt(1) : ModInt(0);
    }
  }
  return mat;
}

Matrix operator+(const Matrix a, const Matrix b) {
  Matrix res;
  int n = sizeof(a.A) / sizeof(a.A[0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res.A[i][j] = a.A[i][j] + b.A[i][j];
    }
  }
  return res;
}

Matrix operator-(const Matrix a, const Matrix b) {
  Matrix res;
  int n = sizeof(a.A) / sizeof(a.A[0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res.A[i][j] = a.A[i][j] - b.A[i][j];
    }
  }
  return res;
}

Matrix operator*(const Matrix a, const Matrix b) {
  Matrix res;
  int n = sizeof(a.A) / sizeof(a.A[0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res.A[i][j] = ModInt(0);
      for (int k = 0; k < n; k++) {
        res.A[i][j] = res.A[i][j] + a.A[i][k] * b.A[k][j];
      }
    }
  }
  return res;
}

Matrix operator^(const Matrix a, int64_t k) {
  Matrix res = MatrixI(sizeof(a.A) / sizeof(a.A[0]));
  while (k > 0) {
    if (k & 1) res = res * a;
    a = a * a;
    k >>= 1;
  }
  return res;
}

Matrix operator+=(Matrix a, const Matrix b) {
  int n = sizeof(a.A) / sizeof(a.A[0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a.A[i][j] = a.A[i][j] + b.A[i][j];
    }
  }
  return a;
}

Matrix operator-=(Matrix a, const Matrix b) {
  int n = sizeof(a.A) / sizeof(a.A[0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a.A[i][j] = a.A[i][j] - b.A[i][j];
    }
  }
  return a;
}

Matrix operator*=(Matrix a, const Matrix b) {
  int n = sizeof(a.A) / sizeof(a.A[0]);
  Matrix res;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res.A[i][j] = ModInt(0);
      for (int k = 0; k < n; k++) {
        res.A[i][j] = res.A[i][j] + a.A[i][k] * b.A[k][j];
      }
    }
  }
  return res;
}

Matrix operator^=(Matrix a, int64_t k) {
  Matrix res = MatrixI(sizeof(a.A) / sizeof(a.A[0]));
  while (k > 0) {
    if (k & 1) res = res * a;
    a = a * a;
    k >>= 1;
  }
  return res;
}

Matrix operator-(const Matrix a) {
  Matrix res;
  int n = sizeof(a.A) / sizeof(a.A[0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res.A[i][j] = -a.A[i][j];
    }
  }
  return res;
}

typedef struct {
  int sz;
  Matrix *seg;
  Matrix (*f)(const Matrix, const Matrix);
  Matrix M1;
} SegmentTree;

SegmentTree SegmentTreeInit(int n, Matrix (*f)(const Matrix, const Matrix), Matrix M1) {
  SegmentTree seg;
  seg.sz = 1;
  while (seg.sz < n) seg.sz <<= 1;
  seg.seg = (Matrix *)malloc(sizeof(Matrix) * seg.sz * 2);
  seg.f = f;
  seg.M1 = M1;
  for (int i = 0; i < seg.sz * 2; i++) {
    seg.seg[i] = M1;
  }
  return seg;
}

void SegmentTreeSet(SegmentTree *seg, int k, Matrix x) {
  seg->seg[k + seg->sz] = x;
}

void SegmentTreeBuild(SegmentTree *seg) {
  for (int k = seg->sz - 1; k > 0; k--) {
    seg->seg[k] = seg->f(seg->seg[2 * k], seg->seg[2 * k + 1]);
  }
}

void SegmentTreeUpdate(SegmentTree *seg, int k, Matrix x) {
  k += seg->sz;
  seg->seg[k] = x;
  while (k >>= 1) {
    seg->seg[k] = seg->f(seg->seg[2 * k], seg->seg[2 * k + 1]);
  }
}

Matrix SegmentTreeQuery(SegmentTree *seg, int a, int b) {
  Matrix L = seg->M1, R = seg->M1;
  for (a += seg->sz, b += seg->sz; a < b; a >>= 1, b >>= 1) {
    if (a & 1) L = seg->f(L, seg->seg[a++]);
    if (b & 1) R = seg->f(seg->seg[--b], R);
  }
  return seg->f(L, R);
}

Matrix SegmentTreeGet(SegmentTree *seg, int k) {
  return seg->seg[k + seg->sz];
}

int SegmentTreeId0(SegmentTree *seg, int a, int (*check)(const Matrix), Matrix *M, int type) {
  while (a < seg->sz) {
    Matrix nxt = type ? seg->f(seg->seg[2 * a + type], *M) : seg->f(*M, seg->seg[2 * a + type]);
    if (check(nxt)) {
      a = 2 * a + type;
    } else {
      *M = nxt;
      a = 2 * a + 1 - type;
    }
  }
  return a - seg->sz;
}

int SegmentTreeFindFirst(SegmentTree *seg, int a, int (*check)(const Matrix)) {
  Matrix L = seg->M1;
  if (a <= 0) {
    if (check(seg->f(L, seg->seg[1]))) {
      return SegmentTreeId0(seg, 1, check, &L, 0);
    }
    return -1;
  }
  int b = seg->sz;
  for (a += seg->sz, b += seg->sz; a < b; a >>= 1, b >>= 1) {
    if (a & 1) {
      Matrix nxt = seg->f(L, seg->seg[a]);
      if (check(nxt)) {
        return SegmentTreeId0(seg, a, check, &L, 0);
      }
      L = nxt;
      ++a;
    }
  }
  return -1;
}

int SegmentTreeFindLast(SegmentTree *seg, int b, int (*check)(const Matrix)) {
  Matrix R = seg->M1;
  if (b >= seg->sz) {
    if (check(seg->f(seg->seg[1], R))) {
      return SegmentTreeId0(seg, 1, check, &R, 1);
    }
    return -1;
  }
  int a = seg->sz;
  for (b += seg->sz; a < b; a >>= 1, b >>= 1) {
    if (b & 1) {
      Matrix nxt = seg->f(seg->seg[--b], R);
      if (check(nxt)) {
        return SegmentTreeId0(seg, b, check, &R, 1);
      }
      R = nxt;
    }
  }
  return -1;
}

unsigned mul(unsigned a, unsigned b) {
  unsigned long long x = (unsigned long long)a * b;
  unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
  asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod));
  return m;
}

int main() {
  int N;
  scanf("%d", &N);
  int *X = (int *)malloc(sizeof(int) * N);
  int *V = (int *)malloc(sizeof(int) * N);
  modint *P = (modint *)malloc(sizeof(modint) * N);
  modint *Q = (modint *)malloc(sizeof(modint) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &X[i], &V[i], &P[i]);
    P[i] = P[i] / 100;
    Q[i] = ModInt(1) - P[i];
  }

  typedef Matrix (*F)(const Matrix, const Matrix);
  Matrix e = MatrixI(4);
  F f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  *f = (F)malloc(sizeof(F));
  (*f)->A[0][0] = Q[i];
  (*f)->A[0][2] = Q[i];
  (*f)->A[1][0] = Q[i];
  (*f)->A[1][2] = Q[i];
  (*f)->A[2][2] = Q[i];
  (*f)->A[3][2] = Q[i];
  (*f)->A[0][1] = P[i];
  (*f)->A[1][1] = P[i];
  (*f)->A[2][3] = P[i];
  (*f)->A[3][3] = P[i];
  SegmentTree seg = SegmentTreeInit(N, f, e);
  for (int i = 0; i < N; i++) {
    Matrix u = e;
    u.A[0][0] = Q[i];
    u.A[0][2] = Q[i];
    u.A[1][0] = Q[i];
    u.A[1][2] = Q[i];
    u.A[2][2] = Q[i];
    u.A[3][2] = Q[i];
    u.A[0][1] = P[i];
    u.A[1][1] = P[i];
    u.A[2][3] = P[i];
    u.A[3][3] = P[i];
    SegmentTreeSet(&seg, i, u);
  }
  SegmentTreeBuild(&seg);

  modint ret = ModInt(0);

  for (auto &p : ev) {
    auto &vs = p.second;
    for (auto &tt : vs) {
      Matrix now = SegmentTreeGet(&seg, tt.right);
      if (tt.type == 0) {
        now.A[0][0] = 0;
        now.A[0][2] = Q[tt.right];
      } else if (tt.type == 1) {
        now.A[1][1] = 0;
        now.A[1][3] = P[tt.right];
      } else {
        now.A[1][0] = 0;
        now.A[1][2] = Q[tt.right];
      }
      SegmentTreeUpdate(&seg, tt.right, now);
    }
    Matrix uku = SegmentTreeGet(&seg, 1);
    modint sum = uku.A[0][2] + uku.A[0][3];
    ret = ret + modint(p.first.num) / p.first.dom * sum;
    for (auto &tt : vs) {
      Matrix now = SegmentTreeGet(&seg, tt.right);
      if (tt.type == 0) {
        now.A[0][2] = 0;
        now.A[2][2] = 0;
      } else if (tt.type == 1) {
        now.A[1][3] = 0;
        now.A[3][3] = 0;
      } else {
        now.A[1][2] = 0;
        now.A[3][2] = 0;
      }
      SegmentTreeUpdate(&seg, tt.right, now);
    }
  }
  printf("%d\n", ret.x);
  return 0;
}
