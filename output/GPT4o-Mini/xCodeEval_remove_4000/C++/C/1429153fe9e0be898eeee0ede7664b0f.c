#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} Array;

void read_array(Array *arr) {
    scanf("%d", &arr->size);
    arr->data = (int *)malloc(arr->size * sizeof(int));
    for (int i = 0; i < arr->size; i++) {
        scanf("%d", &arr->data[i]);
    }
}

int sum(int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int filter(int f, int s, int n) {
    return (f == s || f == n - 1 - s || f == n / 2 || s == n / 2);
}

void solve() {
    int n;
    scanf("%d", &n);
    
    Array a;
    read_array(&a);
    
    int *idx = (int *)malloc(n * sizeof(int));
    int idx_count = 0;
    
    for (int f = 0; f < n; f++) {
        for (int s = 0; s < n; s++) {
            if (filter(f, s, n)) {
                idx[idx_count++] = a.data[f];
            }
        }
    }
    
    int result = sum(idx, idx_count);
    printf("%d\n", result);
    
    free(a.data);
    free(idx);
}

int main() {
    solve();
    return 0;
}
