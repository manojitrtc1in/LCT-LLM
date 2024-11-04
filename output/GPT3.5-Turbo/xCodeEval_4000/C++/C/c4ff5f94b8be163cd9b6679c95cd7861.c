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
    int x;
    int v;
    int p;
} Car;

typedef struct {
    int l;
    int r;
} Range;

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    int p;
    int q;
} Mint;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int abs(int a) {
    return (a < 0) ? -a : a;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int inverse(int a, int m) {
    int u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a;
        int temp = a;
        a = m;
        m = temp;
        u -= t * v;
        temp = u;
        u = v;
        v = temp;
    }
    return u;
}

int normalize(int x, int mod) {
    int v;
    if (-mod <= x && x < mod) {
        v = x;
    } else {
        v = x % mod;
    }
    if (v < 0) {
        v += mod;
    }
    return v;
}

Mint modular_add(Mint a, Mint b, int mod) {
    Mint result;
    result.p = normalize(a.p + b.p, mod);
    result.q = normalize(a.q + b.q, mod);
    return result;
}

Mint modular_subtract(Mint a, Mint b, int mod) {
    Mint result;
    result.p = normalize(a.p - b.p, mod);
    result.q = normalize(a.q - b.q, mod);
    return result;
}

Mint modular_multiply(Mint a, Mint b, int mod) {
    Mint result;
    result.p = normalize(a.p * b.p, mod);
    result.q = normalize(a.q * b.q, mod);
    return result;
}

Mint modular_divide(Mint a, Mint b, int mod) {
    Mint result;
    result.p = normalize(a.p / b.p, mod);
    result.q = normalize(a.q / b.q, mod);
    return result;
}

Mint modular_power(Mint a, int b, int mod) {
    Mint result;
    result.p = 1;
    result.q = 1;
    for (int i = 0; i < b; i++) {
        result = modular_multiply(result, a, mod);
    }
    return result;
}

Mat matrix_multiply(Mat a, Mat b, int mod) {
    Mat result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result.m[i][j] = modular_add(result.m[i][j], modular_multiply(a.m[i][k], b.m[k][j], mod), mod);
            }
        }
    }
    return result;
}

Mint get_prob(Mat *a, int n) {
    Mint to_right = a[0].m[0][1];
    Mint mat = matrix_multiply(a[get_id(0, n - 2)], a[get_id(0, n - 2)], mod);
    return modular_add(modular_multiply(to_right, modular_add(mat.m[1][0], mat.m[1][1], mod), mod), modular_multiply(modular_subtract(1, to_right, mod), modular_add(mat.m[0][0], mat.m[0][1], mod), mod), mod);
}

int get_id(int l, int r) {
    return l + r | (l != r);
}

int cmp(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    if (p1->first < p2->first) {
        return -1;
    } else if (p1->first > p2->first) {
        return 1;
    } else {
        return 0;
    }
}

Mint solve(int n, Car *cars, Mint *p) {
    if (n == 1) {
        return 0;
    }
    Mat allowed_collisions[n - 1];
    for (int i = 0; i < n - 1; i++) {
        allowed_collisions[i].m[0][1] = p[i + 1];
    }
    Mat a[2 * (n - 1) - 1];
    for (int i = 0; i < 2 * (n - 1) - 1; i++) {
        a[i].m[0][0] = 0;
        a[i].m[0][1] = 0;
        a[i].m[1][0] = 0;
        a[i].m[1][1] = 0;
    }
    int (*get_prob_ptr)(Mat *, int) = get_prob;
    void (*build_ptr)(int, int, Mat *) = build;
    void (*modify_ptr)(int, int, int, Mat *) = modify;
    build_ptr(0, n - 2, a, allowed_collisions, get_prob_ptr);
    Mint prev_prob = get_prob(a, n), ans = 0;
    Pair events[3 * (n - 1)];
    for (int i = 0; i < 3 * (n - 1); i++) {
        events[i].first = 0;
        events[i].second = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int d = cars[i + 1].x - cars[i].x;
        events[i * 3].first = d * (cars[i + 1].v + cars[i].v);
        events[i * 3].second = i << 2 | 1;
        if (cars[i].v < cars[i + 1].v) {
            events[i * 3 + 1].first = d;
            events[i * 3 + 1].second = i << 2 | 0;
        } else {
            events[i * 3 + 1].first = 1;
            events[i * 3 + 1].second = 0;
        }
        if (cars[i].v > cars[i + 1].v) {
            events[i * 3 + 2].first = d;
            events[i * 3 + 2].second = i << 2 | 3;
        } else {
            events[i * 3 + 2].first = 1;
            events[i * 3 + 2].second = 0;
        }
    }
    qsort(events, 3 * (n - 1), sizeof(Pair), cmp);
    for (int i = 3 * (n - 1) - 1; i >= 0; i--) {
        int i = events[i].second >> 2;
        int dir1 = (events[i].second >> 0) & 1;
        int dir2 = (events[i].second >> 1) & 1;
        allowed_collisions[i].m[dir1][dir2] = dir2 ? p[i + 1] : 1 - p[i + 1];
        modify_ptr(0, n - 2, i, a, allowed_collisions, get_prob_ptr);
        Mint prob = get_prob(a, n);
        if (events[i].first.q != 0) {
            ans = modular_add(ans, modular_multiply(modular_subtract(prob, prev_prob, mod), events[i].first, mod), mod);
        }
        prev_prob = prob;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    Car cars[n];
    Mint p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &cars[i].x, &cars[i].v, &p[i]);
        p[i].p = modular_multiply(p[i].p, inverse(100, mod), mod);
    }
    Mint ans = solve(n, cars, p);
    printf("%d\n", ans.p);
    return 0;
}
