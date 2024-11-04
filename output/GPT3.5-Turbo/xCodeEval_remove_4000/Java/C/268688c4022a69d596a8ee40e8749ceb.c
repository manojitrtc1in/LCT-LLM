#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

void pushFront(Deque* deque, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front = newNode;
    }
}

void pushBack(Deque* deque, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (deque->rear == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int popFront(Deque* deque) {
    if (deque->front == NULL) {
        return -1; // Deque is empty
    }
    int value = deque->front->value;
    Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    }
    free(temp);
    return value;
}

int popBack(Deque* deque) {
    if (deque->rear == NULL) {
        return -1; // Deque is empty
    }
    int value = deque->rear->value;
    Node* temp = deque->rear;
    Node* current = deque->front;
    if (current == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        while (current->next != deque->rear) {
            current = current->next;
        }
        current->next = NULL;
        deque->rear = current;
    }
    free(temp);
    return value;
}

int isEmpty(Deque* deque) {
    return (deque->front == NULL && deque->rear == NULL);
}

void freeDeque(Deque* deque) {
    while (!isEmpty(deque)) {
        popFront(deque);
    }
    free(deque);
}

int main() {
    int n;
    scanf("%d", &n);
    Deque* dq = createDeque();
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        pushBack(dq, value);
    }
    int a = popFront(dq);
    int b = 0;
    int pre = a;
    int now;
    int cnt = 1;
    while (!isEmpty(dq)) {
        now = 0;
        while (now <= pre && !isEmpty(dq)) {
            now += popBack(dq);
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
            now += popFront(dq);
        }
        if (now != 0) {
            a += now;
            pre = now;
            cnt++;
        }
    }
    printf("%d %d %d\n", cnt, a, b);
    freeDeque(dq);
    return 0;
}
