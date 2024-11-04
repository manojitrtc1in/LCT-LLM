#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 200000

typedef struct {
    long long first;
    long long second;
} pii;

typedef struct {
    long long *data;
    long long size;
} vector_ll;

vector_ll data[MAX_N];

long long total = 0;

void push_back(vector_ll *v, long long value) {
    v->data = realloc(v->data, (v->size + 1) * sizeof(long long));
    v->data[v->size++] = value;
}

long long min(long long a, long long b) {
    return a < b ? a : b;
}

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main() {
    long long n;
    scanf("%lld", &n);
    
    for (long long i = 1; i <= n; i++) {
        long long k, a, x, y, m;
        scanf("%lld %lld %lld %lld %lld", &k, &a, &x, &y, &m);
        total += k;
        
        push_back(&data[i - 1], a);
        for (long long j = 2; j <= k; j++) {
            long long next_value = (data[i - 1].data[data[i - 1].size - 1] * x + y) % m;
            push_back(&data[i - 1], next_value);
        }
    }

    pii q[MAX_N];
    long long q_size = 0;

    for (long long i = 0; i < n; i++) {
        q[q_size++] = (pii){data[i].data[0], i * 1000000}; // Using a large number to represent the index
    }

    long long ans[MAX_N];
    pii sol[MAX_N];
    long long p = 0;
    
    while (total > 0) {
        long long idx = -1;
        long long min_value = 1e18;

        for (long long i = 0; i < q_size; i++) {
            if (q[i].first >= p && q[i].first < min_value) {
                min_value = q[i].first;
                idx = i;
            }
        }

        if (idx == -1) {
            idx = 0; // Reset to the first element if no valid element is found
        }

        long long v = q[idx].first;
        p = v;
        ans[total - 1] = v;
        sol[total - 1] = (pii){v, (q[idx].second / 1000000) + 1}; // Extracting the original index
        total--;

        // Remove the element from the queue
        for (long long i = idx; i < q_size - 1; i++) {
            q[i] = q[i + 1];
        }
        q_size--;

        // Insert the next value if available
        long long next_index = (q[idx].second % 1000000) + 1;
        if (next_index < data[q[idx].second / 1000000].size) {
            push_back(&q[q_size], (pii){data[q[idx].second / 1000000].data[next_index], q[idx].second});
            q_size++;
        }
    }

    long long bad = 0;
    for (long long i = 1; i < total; i++) {
        if (ans[i - 1] > ans[i]) {
            bad++;
        }
    }
    
    printf("%lld\n", bad);
    if (total <= 200000) {
        for (long long i = 0; i < total; i++) {
            printf("%lld %lld\n", sol[i].first, sol[i].second);
        }
    }

    return 0;
}
