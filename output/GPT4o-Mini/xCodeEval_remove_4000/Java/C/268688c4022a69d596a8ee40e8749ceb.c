#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    long *data;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList(int capacity) {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = (long *)malloc(capacity * sizeof(long));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void add(ArrayList *list, long value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (long *)realloc(list->data, list->capacity * sizeof(long));
    }
    list->data[list->size++] = value;
}

void freeArrayList(ArrayList *list) {
    free(list->data);
    free(list);
}

long repow(long b, long p) {
    long res = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            res *= b;
        }
        b *= b;
        p /= 2;
    }
    return res;
}

long gcd(long c, long d) {
    while (true) {
        long f = c % d;
        if (f == 0) {
            return d;
        }
        c = d;
        d = f;
    }
}

long lcm(long c, long d) {
    return c / gcd(c, d) * d;
}

ArrayList* divList(long n) {
    ArrayList *div = createArrayList(10);
    for (long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            add(div, i);
            if (i * i != n) {
                add(div, n / i);
            }
        }
    }
    return div;
}

bool isPrime(long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    scanf("%d", &n);
    ArrayList *dq = createArrayList(n);
    for (int i = 0; i < n; i++) {
        long value;
        scanf("%ld", &value);
        add(dq, value);
    }

    long a = dq->data[0];
    long b = 0;
    long pre = a;
    long now;
    int cnt = 1;

    int front = 1, back = dq->size - 1; // Simulating deque with indices

    while (front <= back) {
        now = 0;
        while (now <= pre && back >= front) {
            now += dq->data[back--];
        }
        if (now != 0) {
            b += now;
            pre = now;
            cnt++;
        }

        if (front > back) {
            break;
        }

        now = 0;
        while (now <= pre && back >= front) {
            now += dq->data[front++];
        }
        if (now != 0) {
            a += now;
            pre = now;
            cnt++;
        }
    }
    printf("%d %ld %ld\n", cnt, a, b);
    
    freeArrayList(dq);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
