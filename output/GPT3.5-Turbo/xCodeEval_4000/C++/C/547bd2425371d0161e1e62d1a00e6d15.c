#include <stdio.h>
#include <stdlib.h>

typedef long long int int64;

const int mod = 998244353;

typedef struct {
  int64 num, dom;
} fraction;

fraction make_fraction(int64 n, int64 d) {
  fraction f;
  f.num = n;
  f.dom = d;
  return f;
}

fraction add_fraction(fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.dom + b.num * a.dom;
  res.dom = a.dom * b.dom;
  return res;
}

fraction subtract_fraction(fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.dom - b.num * a.dom;
  res.dom = a.dom * b.dom;
  return res;
}

fraction multiply_fraction(fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.num;
  res.dom = a.dom * b.dom;
  return res;
}

fraction divide_fraction(fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.dom;
  res.dom = a.dom * b.num;
  return res;
}

int compare_fraction(fraction a, fraction b) {
  int64 lhs = a.num * b.dom;
  int64 rhs = b.num * a.dom;
  if (lhs < rhs) {
    return -1;
  } else if (lhs > rhs) {
    return 1;
  } else {
    return 0;
  }
}

typedef struct {
  int right, type;
} Node;

typedef struct {
  int64 x[4][4];
} Matrix;

Matrix make_matrix() {
  Matrix mat;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      mat.x[i][j] = 0;
    }
  }
  return mat;
}

Matrix identity_matrix() {
  Matrix mat = make_matrix();
  for (int i = 0; i < 4; i++) {
    mat.x[i][i] = 1;
  }
  return mat;
}

Matrix multiply_matrix(Matrix a, Matrix b) {
  Matrix res = make_matrix();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        res.x[i][j] += a.x[i][k] * b.x[k][j];
        res.x[i][j] %= mod;
      }
    }
  }
  return res;
}

Matrix power_matrix(Matrix mat, int64 k) {
  Matrix res = identity_matrix();
  while (k > 0) {
    if (k & 1) {
      res = multiply_matrix(res, mat);
    }
    mat = multiply_matrix(mat, mat);
    k >>= 1;
  }
  return res;
}

Matrix add_matrix(Matrix a, Matrix b) {
  Matrix res = make_matrix();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      res.x[i][j] = (a.x[i][j] + b.x[i][j]) % mod;
    }
  }
  return res;
}

Matrix subtract_matrix(Matrix a, Matrix b) {
  Matrix res = make_matrix();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      res.x[i][j] = (a.x[i][j] - b.x[i][j] + mod) % mod;
    }
  }
  return res;
}

Matrix segment_tree[1000000];
Matrix identity;

Matrix combine_matrix(Matrix a, Matrix b) {
  Matrix res = make_matrix();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        res.x[i][j] += a.x[i][k] * b.x[k][j];
        res.x[i][j] %= mod;
      }
    }
  }
  return res;
}

void build_segment_tree(int node, int start, int end) {
  if (start == end) {
    segment_tree[node] = identity;
    return;
  }
  int mid = (start + end) / 2;
  build_segment_tree(2 * node, start, mid);
  build_segment_tree(2 * node + 1, mid + 1, end);
  segment_tree[node] = combine_matrix(segment_tree[2 * node], segment_tree[2 * node + 1]);
}

void update_segment_tree(int node, int start, int end, int index, Matrix value) {
  if (start == end) {
    segment_tree[node] = value;
    return;
  }
  int mid = (start + end) / 2;
  if (index <= mid) {
    update_segment_tree(2 * node, start, mid, index, value);
  } else {
    update_segment_tree(2 * node + 1, mid + 1, end, index, value);
  }
  segment_tree[node] = combine_matrix(segment_tree[2 * node], segment_tree[2 * node + 1]);
}

Matrix query_segment_tree(int node, int start, int end, int left, int right) {
  if (start > right || end < left) {
    return identity;
  }
  if (start >= left && end <= right) {
    return segment_tree[node];
  }
  int mid = (start + end) / 2;
  Matrix left_result = query_segment_tree(2 * node, start, mid, left, right);
  Matrix right_result = query_segment_tree(2 * node + 1, mid + 1, end, left, right);
  return combine_matrix(left_result, right_result);
}

int main() {
  int N;
  scanf("%d", &N);
  int X[N], V[N];
  fraction P[N], Q[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d %lld", &X[i], &V[i], &P[i].num);
    P[i].dom = 100;
    Q[i] = subtract_fraction(make_fraction(1, 1), P[i]);
  }

  fraction ev[1000000];
  int ev_count = 0;
  for (int i = 1; i < N; i++) {
    if (V[i - 1] < V[i]) {
      ev[ev_count++] = make_fraction(X[i - 1] - X[i], V[i - 1] - V[i]);
    }
    ev[ev_count++] = make_fraction(X[i] - X[i - 1], V[i - 1] + V[i]);
    if (V[i - 1] > V[i]) {
      ev[ev_count++] = make_fraction(X[i - 1] - X[i], V[i] - V[i - 1]);
    }
  }

  Matrix e = identity_matrix();
  for (int i = 0; i < N; i++) {
    Matrix u = e;
    u.x[0][0] = Q[i].num;
    u.x[0][2] = Q[i].num;
    u.x[1][0] = Q[i].num;
    u.x[1][2] = Q[i].num;
    u.x[2][2] = Q[i].num;
    u.x[3][2] = Q[i].num;
    u.x[0][1] = P[i].num;
    u.x[1][1] = P[i].num;
    u.x[2][3] = P[i].num;
    u.x[3][3] = P[i].num;
    update_segment_tree(1, 0, N - 1, i, u);
  }

  fraction ret = make_fraction(0, 1);

  for (int i = 0; i < ev_count; i++) {
    fraction p = ev[i];
    Matrix uku = query_segment_tree(1, 0, N - 1, 0, N - 1);
    fraction sum = make_fraction(uku.x[0][2] + uku.x[0][3], 1);
    ret = add_fraction(ret, multiply_fraction(p, sum));
    for (int j = 0; j < N; j++) {
      Matrix now = query_segment_tree(1, 0, N - 1, j, j);
      if (compare_fraction(p, make_fraction(X[j - 1] - X[j], V[j - 1] - V[j])) == 0) {
        now.x[0][0] = 0;
        now.x[0][2] = Q[j].num;
      } else if (compare_fraction(p, make_fraction(X[j - 1] - X[j], V[j] - V[j - 1])) == 0) {
        now.x[1][1] = 0;
        now.x[1][3] = P[j].num;
      } else {
        now.x[1][0] = 0;
        now.x[1][2] = Q[j].num;
      }
      update_segment_tree(1, 0, N - 1, j, now);
    }
  }

  printf("%lld\n", ret.num);

  return 0;
}
