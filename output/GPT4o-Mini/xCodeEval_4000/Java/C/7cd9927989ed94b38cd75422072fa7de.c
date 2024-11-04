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
    list->size = 0;
    list->capacity = 10;
    list->data = (int *)malloc(list->capacity * sizeof(int));
    return list;
}

void add(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

int get(ArrayList *list, int index) {
    return list->data[index];
}

int bfs(ArrayList **arr, int *visited, int start, int *map) {
    Pair *queue = (Pair *)malloc(MAX_N * sizeof(Pair));
    int front = 0, rear = 0;
    
    queue[rear++] = (Pair){start, 0};
    map[start] = 0;
    visited[start] = 1;

    while (front < rear) {
        Pair ob = queue[front++];
        
        for (int i = 0; i < arr[ob.val]->size; i++) {
            int curr = get(arr[ob.val], i);
            if (visited[curr] == 0) {
                visited[curr] = 1;
                queue[rear++] = (Pair){curr, ob.dist + 1};
                map[curr] = ob.dist + 1;
            }
        }
    }
    free(queue);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    ArrayList **arr = (ArrayList **)malloc((n + 1) * sizeof(ArrayList *));
    ArrayList **rarr = (ArrayList **)malloc((n + 1) * sizeof(ArrayList *));
    
    for (int i = 0; i <= n; i++) {
        arr[i] = createArrayList();
        rarr[i] = createArrayList();
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(arr[a], b);
        add(rarr[b], a);
    }
    
    int h;
    scanf("%d", &h);
    int *path = (int *)malloc(h * sizeof(int));
    for (int i = 0; i < h; i++) {
        scanf("%d", &path[i]);
    }
    
    int *map = (int *)malloc((n + 1) * sizeof(int));
    int *visited = (int *)calloc(n + 1, sizeof(int));
    
    for (int i = 0; i <= n; i++) {
        map[i] = -1; // Initialize map with -1
    }
    
    bfs(rarr, visited, path[h - 1], map);
    
    int min = 0, max = 0;
    
    for (int i = 0; i < h - 1; i++) {
        int count = 0;
        if (map[path[i]] == map[path[i + 1]] + 1) {
            for (int j = 0; j < arr[path[i]]->size; j++) {
                int curr = get(arr[path[i]], j);
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
        free(arr[i]->data);
        free(arr[i]);
        free(rarr[i]->data);
        free(rarr[i]);
    }
    free(arr);
    free(rarr);
    free(path);
    free(map);
    free(visited);
    
    return 0;
}
