#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int q;
} Frac;

typedef struct {
    int m[2][2];
} Mat;

typedef struct {
    int value;
} Mint;

Mint inverse(Mint a, Mint m) {
    Mint u = {0}, v = {1};
    while (a.value != 0) {
        Mint t = {m.value / a.value};
        m.value -= t.value * a.value;
        int temp = a.value;
        a.value = m.value;
        m.value = temp;
        u.value -= t.value * v.value;
        temp = u.value;
        u.value = v.value;
        v.value = temp;
    }
    assert(m.value == 1);
    return u;
}

Mint normalize(int x, int mod) {
    int v;
    if (-mod <= x && x < mod) {
        v = x;
    } else {
        v = x % mod;
    }
    if (v < 0) {
        v += mod;
    }
    Mint result = {v};
    return result;
}

Mint add(Mint a, Mint b, int mod) {
    Mint result = {a.value + b.value};
    if (result.value >= mod) {
        result.value -= mod;
    }
    return result;
}

Mint subtract(Mint a, Mint b, int mod) {
    Mint result = {a.value - b.value};
    if (result.value < 0) {
        result.value += mod;
    }
    return result;
}

Mint multiply(Mint a, Mint b, int mod) {
    Mint result = {a.value * b.value % mod};
    return result;
}

Mint divide(Mint a, Mint b, int mod) {
    Mint inverse_b = inverse(b, mod);
    Mint result = multiply(a, inverse_b, mod);
    return result;
}

Mat multiply_mat(Mat a, Mat b, int mod) {
    Mat c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.m[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c.m[i][j] = add(c.m[i][j], multiply(a.m[i][k], b.m[k][j], mod), mod).value;
            }
        }
    }
    return c;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    int x[n], v[n];
    Mint p[n];
    Mint id1 = divide((Mint) {1}, (Mint) {100}, 998244353);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &v[i], &p[i].value);
        p[i] = multiply(p[i], id1, 998244353);
    }

    Mat id2[n - 1];
    for (int i = 0; i < n - 1; i++) {
        id2[i].m[0][1] = p[i + 1].value;
    }

    Mat a[2 * (n - 1) - 1];
    Mint (*get_prob)() = [to_right = p[0], &mat = a[0]]() {
        return add(multiply(to_right, add(mat.m[1][0], mat.m[1][1], 998244353), 998244353),
                   multiply(subtract((Mint) {1}, to_right, 998244353), add(mat.m[0][0], mat.m[0][1], 998244353), 998244353),
                   998244353);
    };
    void (*build)(int, int) = [&](int l, int r) {
        if (l == r) {
            a[2 * l] = id2[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid);
        build(mid + 1, r);
        a[(l + r) | (l != r)].m[0][0] = add(multiply_mat(a[l << 1].m[0][0], a[l << 1].m[0][0], 998244353),
                                            multiply_mat(a[l << 1].m[0][1], a[l << 1].m[1][0], 998244353),
                                            998244353).m[0][0];
        a[(l + r) | (l != r)].m[0][1] = add(multiply_mat(a[l << 1].m[0][0], a[l << 1].m[0][1], 998244353),
                                            multiply_mat(a[l << 1].m[0][1], a[l << 1].m[1][1], 998244353),
                                            998244353).m[0][1];
        a[(l + r) | (l != r)].m[1][0] = add(multiply_mat(a[l << 1].m[1][0], a[l << 1].m[0][0], 998244353),
                                            multiply_mat(a[l << 1].m[1][1], a[l << 1].m[1][0], 998244353),
                                            998244353).m[1][0];
        a[(l + r) | (l != r)].m[1][1] = add(multiply_mat(a[l << 1].m[1][0], a[l << 1].m[0][1], 998244353),
                                            multiply_mat(a[l << 1].m[1][1], a[l << 1].m[1][1], 998244353),
                                            998244353).m[1][1];
    };
    build(0, n - 2);
    void (*modify)(int, int, int) = [&](int l, int r, int k) {
        if (l == r) {
            a[2 * l] = id2[k];
            return;
        }
        int mid = (l + r) / 2;
        if (k <= mid) {
            modify(l, mid, k);
        } else {
            modify(mid + 1, r, k);
        }
        a[(l + r) | (l != r)].m[0][0] = add(multiply_mat(a[l << 1].m[0][0], a[l << 1].m[0][0], 998244353),
                                            multiply_mat(a[l << 1].m[0][1], a[l << 1].m[1][0], 998244353),
                                            998244353).m[0][0];
        a[(l + r) | (l != r)].m[0][1] = add(multiply_mat(a[l << 1].m[0][0], a[l << 1].m[0][1], 998244353),
                                            multiply_mat(a[l << 1].m[0][1], a[l << 1].m[1][1], 998244353),
                                            998244353).m[0][1];
        a[(l + r) | (l != r)].m[1][0] = add(multiply_mat(a[l << 1].m[1][0], a[l << 1].m[0][0], 998244353),
                                            multiply_mat(a[l << 1].m[1][1], a[l << 1].m[1][0], 998244353),
                                            998244353).m[1][0];
        a[(l + r) | (l != r)].m[1][1] = add(multiply_mat(a[l << 1].m[1][0], a[l << 1].m[0][1], 998244353),
                                            multiply_mat(a[l << 1].m[1][1], a[l << 1].m[1][1], 998244353),
                                            998244353).m[1][1];
    };
    Frac events[3 * (n - 1)];
    for (int i = 0; i < n - 1; i++) {
        int d = x[i + 1] - x[i];
        events[i * 3] = (Frac) {d, v[i + 1] + v[i]};
        events[i * 3 + 1] = v[i] < v[i + 1] ? (Frac) {d, v[i + 1] - v[i]} : (Frac) {1, 0};
        events[i * 3 + 2] = v[i] > v[i + 1] ? (Frac) {d, v[i] - v[i + 1]} : (Frac) {1, 0};
    }

    for (int i = 3 * (n - 1) - 1; i >= 0; i--) {
        int j = i >> 2;
        int dir1 = (i >> 0) & 1;
        int dir2 = (i >> 1) & 1;
        id2[j].m[dir1][dir2] = dir2 ? p[j + 1].value : 1 - p[j + 1].value;
        modify(0, n - 2, j);
    }

    Mint prev_prob = get_prob().value, ans = {0};

    for (int i = 0; i < 3 * (n - 1); i++) {
        int j = events[i].q >> 2;
        int dir1 = (events[i].q >> 0) & 1;
        int dir2 = (events[i].q >> 1) & 1;
        id2[j].m[dir1][dir2] = dir2 ? p[j + 1].value : 1 - p[j + 1].value;
        modify(0, n - 2, j);
        Mint prob = get_prob().value;
        if (events[i].q != 0) {
            ans = add(ans, multiply(subtract(prob, prev_prob, 998244353), events[i], 998244353), 998244353);
        }
        prev_prob = prob;
    }

    printf("%d\n", ans.value);

    return 0;
}
