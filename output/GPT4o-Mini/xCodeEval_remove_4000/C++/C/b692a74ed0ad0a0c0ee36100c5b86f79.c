#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXV 100
#define EOL '\n'

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector *v) {
    v->size = 0;
    v->capacity = 4;
    v->data = malloc(v->capacity * sizeof(int));
}

void vector_push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void vector_free(Vector *v) {
    free(v->data);
}

int main() {
    int n;
    scanf("%d", &n);
    
    Vector a;
    vector_init(&a);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        vector_push_back(&a, value - 1);
    }

    int ans = 0;
    int fre = -1;

    int cnt[MAXV] = {0};
    for (size_t i = 0; i < a.size; i++) {
        cnt[a.data[i]]++;
    }

    int ma = 0;
    for (int i = 0; i < MAXV; i++) {
        if (cnt[i] > ma) {
            ma = cnt[i];
        }
    }

    int mac = 0;
    for (int i = 0; i < MAXV; i++) {
        if (cnt[i] == ma) {
            mac++;
            fre = i;
        }
    }
    if (mac > 1) ans = n;

    for (int i = 0; i < MAXV; i++) {
        if (i == fre) continue;

        Vector b;
        vector_init(&b);
        vector_push_back(&b, 0);
        for (size_t j = 0; j < a.size; j++) {
            int pb = b.data[b.size - 1];
            if (a.data[j] == fre)
                pb--;
            else if (a.data[j] == i)
                pb++;
            vector_push_back(&b, pb);
        }

        int mi[2 * n + 1];
        int ma[2 * n + 1];
        for (int j = 0; j <= 2 * n; j++) {
            mi[j] = n + 1;
            ma[j] = -1;
        }

        for (size_t j = 0; j <= n; j++) {
            int va = n + b.data[j];
            if (j < mi[va]) mi[va] = j;
            if (j > ma[va]) ma[va] = j;
        }

        for (int j = 0, k = n + 1; j < 2 * n + 1; j++) {
            if (mi[j] < k) k = mi[j];
            if (ma[j] - k > ans) ans = ma[j] - k;
        }

        vector_free(&b);
    }

    printf("%d%c", ans, EOL);
    vector_free(&a);
    return 0;
}
