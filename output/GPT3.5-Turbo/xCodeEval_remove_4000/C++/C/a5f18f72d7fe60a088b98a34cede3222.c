#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef long long ll;

typedef struct {
    int* data;
    int size;
} vec;

typedef struct {
    int* data;
    int size;
} arri;

typedef struct {
    int* data;
    int dim1;
    int dim2;
} id3;

typedef struct {
    int* data;
    int dim1;
    int dim2;
    int dim3;
} id6;

typedef struct {
    int* data;
    int dim1;
    int dim2;
    int dim3;
    int dim4;
} id1;

vec create_vec(int size) {
    vec v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

arri create_arri(int size) {
    arri a;
    a.data = (int*)malloc(size * sizeof(int));
    a.size = size;
    return a;
}

id3 create_id3(int dim1, int dim2) {
    id3 i;
    i.data = (int*)malloc(dim1 * dim2 * sizeof(int));
    i.dim1 = dim1;
    i.dim2 = dim2;
    return i;
}

id6 create_id6(int dim1, int dim2, int dim3) {
    id6 i;
    i.data = (int*)malloc(dim1 * dim2 * dim3 * sizeof(int));
    i.dim1 = dim1;
    i.dim2 = dim2;
    i.dim3 = dim3;
    return i;
}

id1 create_id1(int dim1, int dim2, int dim3, int dim4) {
    id1 i;
    i.data = (int*)malloc(dim1 * dim2 * dim3 * dim4 * sizeof(int));
    i.dim1 = dim1;
    i.dim2 = dim2;
    i.dim3 = dim3;
    i.dim4 = dim4;
    return i;
}

void free_vec(vec v) {
    free(v.data);
}

void free_arri(arri a) {
    free(a.data);
}

void free_id3(id3 i) {
    free(i.data);
}

void free_id6(id6 i) {
    free(i.data);
}

void free_id1(id1 i) {
    free(i.data);
}

vec primes(int n) {
    vec res = create_vec(n);
    int* isPrime = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        isPrime[i] = 1;
    }
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime[i]) {
            res.data[count++] = i;
        }
    }
    res.size = count;
    free(isPrime);
    return res;
}

arri id7(int n) {
    arri res = create_arri(n);
    int* d = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        d[i] = 0;
    }
    if (n > 1) {
        res.data[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        if (res.data[i] == 0) {
            res.data[i] = i;
            if ((ll)i * i < n) {
                for (int j = i * i; j < n; j += i) {
                    res.data[j] = i;
                }
            }
        }
    }
    free(d);
    return res;
}

arri getQty(int* begin, int* end, int length) {
    arri res = create_arri(length);
    for (int* it = begin; it != end; it++) {
        res.data[*it]++;
    }
    return res;
}

arri getQty2(int* begin, int* end) {
    int max_val = 0;
    for (int* it = begin; it != end; it++) {
        if (*it > max_val) {
            max_val = *it;
        }
    }
    return getQty(begin, end, max_val + 1);
}

void collect(vec* all) {}

void collect2(vec* all, vec* a) {
    for (int i = 0; i < a->size; i++) {
        all->data[all->size++] = a->data[i];
    }
}

void collect3(vec* all, arri* a) {
    for (int i = 0; i < a->size; i++) {
        all->data[all->size++] = a->data[i];
    }
}

void collect4(vec* all, vec* a, arri* b) {
    collect2(all, a);
    collect3(all, b);
}

void collect5(vec* all, arri* a, arri* b) {
    collect3(all, a);
    collect3(all, b);
}

void collect6(vec* all, vec* a, arri* b, arri* c) {
    collect2(all, a);
    collect3(all, b);
    collect3(all, c);
}

void collect7(vec* all, arri* a, arri* b, arri* c) {
    collect3(all, a);
    collect3(all, b);
    collect3(all, c);
}

void replace(vec* all) {}

void replace2(vec* all, vec* a) {
    for (int i = 0; i < a->size; i++) {
        a->data[i] = lower_bound(all->data, all->data + all->size, a->data[i]) - all->data;
    }
}

void replace3(vec* all, arri* a) {
    for (int i = 0; i < a->size; i++) {
        a->data[i] = lower_bound(all->data, all->data + all->size, a->data[i]) - all->data;
    }
}

void replace4(vec* all, vec* a, arri* b) {
    replace2(all, a);
    replace3(all, b);
}

void replace5(vec* all, arri* a, arri* b) {
    replace3(all, a);
    replace3(all, b);
}

void replace6(vec* all, vec* a, arri* b, arri* c) {
    replace2(all, a);
    replace3(all, b);
    replace3(all, c);
}

void replace7(vec* all, arri* a, arri* b, arri* c) {
    replace3(all, a);
    replace3(all, b);
    replace3(all, c);
}

vec compress(vec* a, arri* b) {
    vec vals = create_vec(0);
    collect2(&vals, a);
    collect3(&vals, b);
    int* begin = vals.data;
    int* end = vals.data + vals.size;
    int* max_val = end;
    for (int* it = begin; it != end; it++) {
        if (*it > *max_val) {
            max_val = it;
        }
    }
    vec res = create_vec(*max_val + 1);
    for (int* it = begin; it != end; it++) {
        res.data[res.size++] = *it;
    }
    replace2(&res, a);
    replace3(&res, b);
    return res;
}

void DKhaotichnayaV_solve() {
    int n;
    scanf("%d", &n);
    int* k = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }

    vec p = primes(5000);
    arri d = id7(5001);
    id3 id0 = create_id3(5001, 0);
    id0.data[0] = 0;
    id0.data[1] = 0;
    for (int i = 2; i < 5001; i++) {
        id0.data[i] = id0.data[i - 1];
        if (d.data[i] == i) {
            id0.data[i]++;
        } else {
            for (int q = i; q > 1; q /= d.data[q]) {
                id0.data[i] += lower_bound(p.data, p.data + p.size, d.data[q]) - p.data;
            }
        }
    }
    ll answer = 0;
    arri q = getQty(k, k + n, 5001);
    int lost = 0;
    arri still = create_arri(5001);
    for (int i = 0; i < 5001; i++) {
        still.data[i] = 1;
    }
    arri cur = create_arri(p.size);
    while (1) {
        for (int i = 0; i < p.size; i++) {
            cur.data[i] = 0;
        }
        for (int i = 0; i < 5001; i++) {
            if (still.data[i] && id0.data[i] != 0) {
                cur.data[id0.data[i] - 1] += q.data[i];
            }
        }
        int pos = 0;
        for (int i = 0; i < cur.size; i++) {
            if (cur.data[i] > cur.data[pos]) {
                pos = i;
            }
        }
        if (cur.data[pos] <= n / 2) {
            pos = -2;
        }
        int step = 2147483647;
        for (int i = 0; i < 5001; i++) {
            if (still.data[i] && id0.data[i] - 1 != pos) {
                answer += (ll)q.data[i] * id0.data[i];
                lost += q.data[i];
                still.data[i] = 0;
            } else if (still.data[i]) {
                if (id0.data[i] != 0 && id0.data[i] < step) {
                    step = id0.data[i];
                }
            }
        }
        if (pos == -2) {
            break;
        }
        answer += (ll)step * lost;
        for (int i = 0; i < 5001; i++) {
            if (still.data[i]) {
                id0.data[i] -= step;
                if (id0.data[i] == 0) {
                    still.data[i] = 0;
                }
            }
        }
    }
    printf("%lld\n", answer);

    free(k);
    free_vec(p);
    free_arri(d);
    free_id3(id0);
    free_arri(q);
    free_arri(still);
    free_arri(cur);
}

int main() {
    DKhaotichnayaV_solve();
    return 0;
}
