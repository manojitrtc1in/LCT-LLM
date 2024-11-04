#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Deque;

Deque* createDeque(int capacity) {
    Deque *dq = (Deque *)malloc(sizeof(Deque));
    dq->data = (int *)malloc(capacity * sizeof(int));
    dq->front = -1;
    dq->rear = 0;
    dq->size = capacity;
    return dq;
}

bool isEmpty(Deque *dq) {
    return (dq->front == -1);
}

void addFirst(Deque *dq, int item) {
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + dq->size) % dq->size;
    }
    dq->data[dq->front] = item;
}

void addLast(Deque *dq, int item) {
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % dq->size;
    }
    dq->data[dq->rear] = item;
}

int pollFirst(Deque *dq) {
    if (isEmpty(dq)) return -1;
    int item = dq->data[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % dq->size;
    }
    return item;
}

int pollLast(Deque *dq) {
    if (isEmpty(dq)) return -1;
    int item = dq->data[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + dq->size) % dq->size;
    }
    return item;
}

void freeDeque(Deque *dq) {
    free(dq->data);
    free(dq);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        Deque *dq = createDeque(n);
        for (int i = 0; i < n; i++) {
            int value;
            scanf("%d", &value);
            addLast(dq, value);
        }
        
        int a = pollFirst(dq);
        int b = 0;
        int pre = a;
        int now;
        int cnt = 1;

        while (!isEmpty(dq)) {
            now = 0;
            while (now <= pre && !isEmpty(dq)) {
                now += pollLast(dq);
            }
            if (now != 0) {
                b += now;
                pre = now;
                cnt++;
            }

            if (isEmpty(dq)) {
                break;
            }

            now = 0;
            while (now <= pre && !isEmpty(dq)) {
                now += pollFirst(dq);
            }
            if (now != 0) {
                a += now;
                pre = now;
                cnt++;
            }
        }
        printf("%d %d %d\n", cnt, a, b);
        freeDeque(dq);
    }
    return 0;
}
