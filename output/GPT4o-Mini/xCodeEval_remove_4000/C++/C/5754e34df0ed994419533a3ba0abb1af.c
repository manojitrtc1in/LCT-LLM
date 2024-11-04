#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_K 100

typedef long long ll;
typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v) {
    v->size = 0;
    v->capacity = 1;
    v->data = (int *)malloc(v->capacity * sizeof(int));
}

void vector_push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

ll vector_sum(Vector *v) {
    ll sum = 0;
    for (int i = 0; i < v->size; i++) {
        sum += v->data[i];
    }
    return sum;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

void dijkstra(int n, int k, Vector arrs[], ll sums[], ll dps[13][MAX_K + 1]) {
    // Initialize dp array
    memset(dps, 0, sizeof(ll) * 13 * (MAX_K + 1));
    
    for (int i = 0; i < n; i++) {
        ll v = sums[i];
        int k1 = arrs[i].size;
        for (int j = k; j >= k1; j--) {
            dps[i + 1][j] = max(dps[i + 1][j], dps[i][j - k1] + v);
        }
    }
}

ll solve(int n, int k, Vector arrs[]) {
    ll sums[MAX_N];
    for (int i = 0; i < n; i++) {
        sums[i] = vector_sum(&arrs[i]);
    }

    ll dps[13][MAX_K + 1];
    dijkstra(n, k, arrs, sums, dps);

    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, dps[n][i]);
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    Vector arrs[MAX_N];
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        vector_init(&arrs[i]);
        for (int j = 0; j < t; j++) {
            int value;
            scanf("%d", &value);
            vector_push_back(&arrs[i], value);
        }
    }

    ll result = solve(n, k, arrs);
    printf("%lld\n", result);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(arrs[i].data);
    }

    return 0;
}
