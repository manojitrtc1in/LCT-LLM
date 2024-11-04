#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    long *data;
    int size;
    int capacity;
} ArrayListLong;

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayListInt;

ArrayListLong* createArrayListLong(int capacity) {
    ArrayListLong *list = (ArrayListLong *)malloc(sizeof(ArrayListLong));
    list->data = (long *)malloc(capacity * sizeof(long));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

ArrayListInt* createArrayListInt(int capacity) {
    ArrayListInt *list = (ArrayListInt *)malloc(sizeof(ArrayListInt));
    list->data = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void addLong(ArrayListLong *list, long value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (long *)realloc(list->data, list->capacity * sizeof(long));
    }
    list->data[list->size++] = value;
}

void addInt(ArrayListInt *list, int value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
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

ArrayListInt* divListInt(int n) {
    ArrayListInt *div = createArrayListInt(10);
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            addInt(div, i);
            if (i * i != n) {
                addInt(div, n / i);
            }
        }
    }
    return div;
}

ArrayListLong* divListLong(long n) {
    ArrayListLong *div = createArrayListLong(10);
    for (long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            addLong(div, i);
            if (i * i != n) {
                addLong(div, n / i);
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
    ArrayListInt *dq = createArrayListInt(n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        addInt(dq, value);
    }

    int a = dq->data[0];
    int b = 0;
    int pre = a;
    int now;
    int cnt = 1;

    for (int i = 1; i < dq->size; i++) {
        now = 0;
        while (now <= pre && i < dq->size) {
            now += dq->data[dq->size - 1 - i];
            i++;
        }
        if (now != 0) {
            b += now;
            pre = now;
            cnt++;
        }
        if (i >= dq->size) break;

        now = 0;
        while (now <= pre && i < dq->size) {
            now += dq->data[i];
            i++;
        }
        if (now != 0) {
            a += now;
            pre = now;
            cnt++;
        }
    }

    printf("%d %d %d\n", cnt, a, b);
    free(dq->data);
    free(dq);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
