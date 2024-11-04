#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector *v) {
    v->size = 0;
    v->capacity = 1;
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

ll sum(Vector *v) {
    ll total = 0;
    for (size_t i = 0; i < v->size; i++) {
        total += v->data[i];
    }
    return total;
}

void read_int(int *f) {
    char c;
    bool positive = true;
    while ((c = getchar()) != EOF && (c < '0' || c > '9') && c != '-' && c != '+');
    if (c == '-') {
        positive = false;
        c = getchar();
    } else if (c == '+') {
        c = getchar();
    }
    *f = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') {
        *f = (*f * 10) + (c - '0');
    }
    if (!positive) *f = -(*f);
}

void print_int(int f) {
    if (f < 0) {
        putchar('-');
        f = -f;
    }
    if (f == 0) {
        putchar('0');
        return;
    }
    char buffer[20];
    int i = 0;
    while (f > 0) {
        buffer[i++] = (f % 10) + '0';
        f /= 10;
    }
    while (--i >= 0) {
        putchar(buffer[i]);
    }
}

void dijkstra(Vector *arrs, int n, int k) {
    ll *sums = malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        sums[i] = sum(&arrs[i]);
    }

    ll **dps = malloc(13 * sizeof(ll *));
    for (int i = 0; i < 13; i++) {
        dps[i] = malloc((k + 1) * sizeof(ll));
        memset(dps[i], 0, (k + 1) * sizeof(ll));
    }

    // Implement the recursive function and logic here
    // This is a placeholder for the actual logic
    ll ans = 0;

    // Print the answer
    print_int(ans);
    putchar('\n');

    free(sums);
    for (int i = 0; i < 13; i++) {
        free(dps[i]);
    }
    free(dps);
}

int main() {
    int n, k;
    read_int(&n);
    read_int(&k);
    
    Vector *arrs = malloc(n * sizeof(Vector));
    for (int i = 0; i < n; i++) {
        int t;
        read_int(&t);
        vector_init(&arrs[i]);
        for (int j = 0; j < t; j++) {
            int value;
            read_int(&value);
            vector_push_back(&arrs[i], value);
        }
        if (t > k) {
            arrs[i].size = k; // Resize to k
        }
    }

    dijkstra(arrs, n, k);

    for (int i = 0; i < n; i++) {
        vector_free(&arrs[i]);
    }
    free(arrs);
    return 0;
}
