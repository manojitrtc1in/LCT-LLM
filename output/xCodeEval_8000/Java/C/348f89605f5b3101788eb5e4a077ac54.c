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

void init(FastReader* inp) {
    inp->size = 0;
}

void add(FastReader* inp, int num) {
    inp->arr[inp->size++] = num;
}

int next(FastReader* inp) {
    return inp->arr[inp->size++];
}

void sort(ArrayList* list) {
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

void ruffleSort(ArrayList* list) {
    int i, j, temp;
    for (i = 0; i < list->size; i++) {
        j = rand() % list->size;
        temp = list->arr[i];
        list->arr[i] = list->arr[j];
        list->arr[j] = temp;
    }
    sort(list);
}

long power(long x, long y) {
    long gg = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            gg = (gg * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return gg;
}

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void print(ArrayList* list) {
    int i;
    for (i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
}

void input(ArrayList* list, int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &list->arr[i]);
    }
}

void main() {
    int n, k, i, temp;
    long gg = 0;
    FastReader inp;
    ArrayList list;
    PriorityQueue pq;
    
    init(&inp);
    scanf("%d", &n);
    scanf("%d", &k);
    
    list.size = n;
    input(&list, n);
    sort(&list);
    
    for (i = 0; i < n / 2; i++) {
        temp = list.arr[i];
        list.arr[i] = list.arr[n - 1 - i];
        list.arr[n - i - 1] = temp;
    }
    
    pq.size = 0;
    for (i = 0; i <= k; i++) {
        pq.arr[pq.size++] = 0;
    }
    
    for (i = 0; i < n; i++) {
        long cur = pq.arr[0];
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
    
    printf("%ld\n", gg);
}
