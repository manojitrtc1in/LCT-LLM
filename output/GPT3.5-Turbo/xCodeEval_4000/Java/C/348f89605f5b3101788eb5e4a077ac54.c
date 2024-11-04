#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000
#define MOD 1000000007
#define MOD2 998244353

typedef struct {
    int arr[MAX_SIZE];
    int size;
} PriorityQueue;

typedef struct {
    int arr[MAX_SIZE];
    int size;
} ArrayList;

typedef struct {
    int arr[MAX_SIZE];
    int size;
} FastReader;

void init(FastReader *fr) {
    fr->size = 0;
}

void add(FastReader *fr, int num) {
    fr->arr[fr->size++] = num;
}

int next(FastReader *fr) {
    return fr->arr[fr->size++];
}

void sort(ArrayList *list) {
    int i, j, temp;
    for (i = 0; i < list->size; i++) {
        for (j = i + 1; j < list->size; j++) {
            if (list->arr[i] > list->arr[j]) {
                temp = list->arr[i];
                list->arr[i] = list->arr[j];
                list->arr[j] = temp;
            }
        }
    }
}

void ruffleSort(ArrayList *list) {
    int i, j, temp;
    for (i = 0; i < list->size; i++) {
        j = rand() % list->size;
        temp = list->arr[i];
        list->arr[i] = list->arr[j];
        list->arr[j] = temp;
    }
    sort(list);
}

void input(ArrayList *list, int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &list->arr[i]);
    }
    list->size = n;
}

long long mul(long long a, long long b) {
    return (a * b) % MOD;
}

long long power(long long x, long long y) {
    long long gg = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            gg = mul(gg, x);
        }
        x = mul(x, x);
        y /= 2;
    }
    return gg;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void print(ArrayList *list) {
    int i;
    for (i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
}

int main() {
    int n, k, i;
    long long a[MAX_SIZE], temp, cur, gg;
    ArrayList list;
    PriorityQueue pq;
    FastReader fr;

    init(&fr);
    scanf("%d", &n);
    scanf("%d", &k);
    input(&fr, n);

    list.size = fr.size;
    for (i = 0; i < list.size; i++) {
        list.arr[i] = fr.arr[i];
    }

    sort(&list);

    for (i = 0; i < n / 2; i++) {
        temp = list.arr[i];
        list.arr[i] = list.arr[n - 1 - i];
        list.arr[n - i - 1] = temp;
    }

    pq.size = 0;
    while (k-- >= 0) {
        pq.arr[pq.size++] = 0;
    }

    gg = 0;
    for (i = 0; i < n; i++) {
        cur = pq.arr[0];
        gg += cur;
        cur += list.arr[i];
        pq.arr[0] = cur;

        // Heapify
        int parent = 0;
        int leftChild = 2 * parent + 1;
        int rightChild = 2 * parent + 2;

        while (leftChild < pq.size) {
            int largest = parent;
            if (pq.arr[leftChild] > pq.arr[largest]) {
                largest = leftChild;
            }
            if (rightChild < pq.size && pq.arr[rightChild] > pq.arr[largest]) {
                largest = rightChild;
            }
            if (largest == parent) {
                break;
            }
            temp = pq.arr[parent];
            pq.arr[parent] = pq.arr[largest];
            pq.arr[largest] = temp;

            parent = largest;
            leftChild = 2 * parent + 1;
            rightChild = 2 * parent + 2;
        }
    }

    printf("%lld\n", gg);

    return 0;
}
