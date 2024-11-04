#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long ll;

typedef struct {
    ll x, y;
} vector_2d;

typedef struct {
    vector_2d p, q;
} segment_2d;

ll cross_product(vector_2d a, vector_2d b) {
    return a.x * b.y - b.x * a.y;
}

int contains(segment_2d a, vector_2d b) {
    return abs(cross_product((vector_2d){a.q.x - a.p.x, a.q.y - a.p.y}, (vector_2d){b.x - a.p.x, b.y - a.p.y})) < 1e-8 &&
           (b.x - a.p.x) * (b.x - a.q.x) < 1e-8;
}

int main() {
    int n;
    scanf("%d", &n);
    
    vector_2d *a = (vector_2d *)malloc(n * sizeof(vector_2d));
    int *index = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &a[i].x, &a[i].y);
        index[i] = i + 1;
    }
    
    char d[100];
    scanf("%s", d);
    int d_len = strlen(d);
    
    // Reverse the string d
    for (int i = 0; i < d_len / 2; i++) {
        char temp = d[i];
        d[i] = d[d_len - 1 - i];
        d[d_len - 1 - i] = temp;
    }
    
    vector_2d *ans = (vector_2d *)malloc(n * sizeof(vector_2d));
    ans[0] = a[0];
    int ans_size = 1;
    
    for (int i = 1; i < n; i++) {
        a[i - 1] = a[i];
    }
    n--;
    
    while (n > 0) {
        int td;
        if (d_len == 0) {
            td = 1;
        } else if (d[d_len - 1] == 'L') {
            td = 1;
        } else {
            td = -1;
        }
        if (d_len > 0) {
            d_len--;
        }
        
        int cur = 0;
        for (int i = 1; i < n; i++) {
            if (cross_product((vector_2d){a[cur].x - ans[ans_size - 1].x, a[cur].y - ans[ans_size - 1].y}, 
                                  (vector_2d){a[i].x - ans[ans_size - 1].x, a[i].y - ans[ans_size - 1].y}) * td < 0) {
                cur = i;
            }
        }
        
        ans[ans_size++] = a[cur];
        for (int i = cur; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;
    }
    
    for (int i = 0; i < ans_size; i++) {
        printf("%d ", index[ans[i].x]);
    }
    printf("\n");
    
    free(a);
    free(index);
    free(ans);
    
    return 0;
}
