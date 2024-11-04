#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    int dist;
} Node;

typedef struct Queue {
    Node* arr;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (Node*)malloc(capacity * sizeof(Node));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

void enqueue(Queue* queue, Node node) {
    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = node;
    queue->size++;
}

Node dequeue(Queue* queue) {
    Node node = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    queue->size--;
    return node;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void bfs(int** arr, int* visited, int start, int n, int* map) {
    Queue* queue = createQueue(n + 1);
    enqueue(queue, (Node){start, 0});
    map[start] = 0;
    visited[start] = 1;
    while (!isEmpty(queue)) {
        Node ob = dequeue(queue);
        for (int i = 0; i < n + 1; i++) {
            int curr = arr[ob.val][i];
            if (visited[curr] == 0) {
                visited[curr] = 1;
                enqueue(queue, (Node){curr, ob.dist + 1});
                map[curr] = ob.dist + 1;
            }
        }
    }
    free(queue->arr);
    free(queue);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** rarr = (int**)malloc((n + 1) * sizeof(int*));
    int** arr = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i < n + 1; i++) {
        rarr[i] = (int*)malloc(n * sizeof(int));
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            rarr[i][j] = 0;
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        rarr[b][a] = 1;
    }

    int h;
    scanf("%d", &h);
    int* path = (int*)malloc(h * sizeof(int));
    for (int i = 0; i < h; i++) {
        scanf("%d", &path[i]);
    }

    int* map = (int*)malloc((n + 1) * sizeof(int));
    int* visited = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n + 1; i++) {
        map[i] = 0;
        visited[i] = 0;
    }

    bfs(rarr, visited, path[h - 1], n, map);

    int min = 0;
    int max = 0;

    for (int i = 0; i < h - 1; i++) {
        int count = 0;
        if (map[path[i]] == map[path[i + 1]] + 1) {
            for (int j = 0; j < n + 1; j++) {
                int curr = arr[path[i]][j];
                if (map[curr] == map[path[i]] - 1) {
                    count++;
                }
            }

            if (count > 1) {
                max++;
            }
        } else {
            min++;
            max++;
        }
    }

    printf("%d %d\n", min, max);

    for (int i = 0; i < n + 1; i++) {
        free(rarr[i]);
        free(arr[i]);
    }
    free(rarr);
    free(arr);
    free(path);
    free(map);
    free(visited);

    return 0;
}
