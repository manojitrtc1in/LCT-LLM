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

void bfs(ArrayList** arr, int* visited, int start, HashMap* map) {
    Queue* q = createQueue(1000);
    enqueue(q, (Node){start, 0});
    map->put(map, start, 0);
    visited[start] = 1;
    while (q->size > 0) {
        Node ob = dequeue(q);
        for (int i = 0; i < arr[ob.val]->size; i++) {
            int curr = (int)arr[ob.val]->get(arr[ob.val], i);
            if (visited[curr] == 0) {
                visited[curr] = 1;
                enqueue(q, (Node){curr, ob.dist + 1});
                map->put(map, curr, ob.dist + 1);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    ArrayList** rarr = (ArrayList**)malloc((n + 1) * sizeof(ArrayList*));
    ArrayList** arr = (ArrayList**)malloc((n + 1) * sizeof(ArrayList*));
    for (int i = 0; i < n + 1; i++) {
        ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
        rarr[i] = list;
        ArrayList* list2 = (ArrayList*)malloc(sizeof(ArrayList));
        arr[i] = list2;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a]->add(arr[a], b);
        rarr[b]->add(rarr[b], a);
    }
    
    int h;
    scanf("%d", &h);
    int* path = (int*)malloc(h * sizeof(int));
    for (int i = 0; i < h; i++) {
        scanf("%d", &path[i]);
    }
    
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    int* visited = (int*)calloc(n + 1, sizeof(int));
    bfs(rarr, visited, path[h - 1], map);
    
    int min = 0;
    int max = 0;
    
    for (int i = 0; i < h - 1; i++) {
        int count = 0;
        if (map->get(map, path[i]) == map->get(map, path[i + 1]) + 1) {
            for (int j = 0; j < arr[path[i]]->size; j++) {
                int curr = (int)arr[path[i]]->get(arr[path[i]], j);
                if (map->get(map, curr) == map->get(map, path[i]) - 1) {
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
    
    return 0;
}
