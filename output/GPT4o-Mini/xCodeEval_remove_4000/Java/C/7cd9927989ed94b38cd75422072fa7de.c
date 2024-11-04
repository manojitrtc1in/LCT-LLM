#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

typedef struct {
    int val;
    int dist;
} Pair;

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList() {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = (int *)malloc(sizeof(int) * 2);
    list->size = 0;
    list->capacity = 2;
    return list;
}

void add(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, sizeof(int) * list->capacity);
    }
    list->data[list->size++] = value;
}

ArrayList* rarr[MAX_N + 1];
ArrayList* arr[MAX_N + 1];

void bfs(ArrayList *arr[], int visited[], int start, int map[]) {
    Pair queue[MAX_N];
    int front = 0, rear = 0;
    queue[rear++] = (Pair){start, 0};
    map[start] = 0;
    visited[start] = 1;

    while (front < rear) {
        Pair ob = queue[front++];
        for (int i = 0; i < arr[ob.val]->size; i++) {
            int curr = arr[ob.val]->data[i];
            if (visited[curr] == 0) {
                visited[curr] = 1;
                queue[rear++] = (Pair){curr, ob.dist + 1};
                map[curr] = ob.dist + 1;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) {
        rarr[i] = createArrayList();
        arr[i] = createArrayList();
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(arr[a], b);
        add(rarr[b], a);
    }

    int h;
    scanf("%d", &h);
    int path[h];
    for (int i = 0; i < h; i++) {
        scanf("%d", &path[i]);
    }

    int map[MAX_N + 1] = {0};
    int visited[MAX_N + 1] = {0};
    bfs(rarr, visited, path[h - 1], map);

    int min = 0, max = 0;

    for (int i = 0; i < h - 1; i++) {
        int count = 0;
        if (map[path[i]] == map[path[i + 1]] + 1) {
            for (int j = 0; j < arr[path[i]]->size; j++) {
                int curr = arr[path[i]]->data[j];
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

    for (int i = 0; i <= n; i++) {
        free(rarr[i]->data);
        free(rarr[i]);
        free(arr[i]->data);
        free(arr[i]);
    }

    return 0;
}
