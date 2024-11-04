#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define forn(i, n) for(int i = 0; i < n; i++)
#define sz(v) ((int)(v).size())
#define mp make_pair

typedef long long li;
typedef long double ld;
typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    li first;
    int second;
} pair;

typedef struct {
    int front;
    int rear;
    int size;
    unsigned capacity;
    int* array;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void freeQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

li INF = 1000000000;
li INF64 = 1000000000000000000;
int MOD = INF + 7;
ld EPS = 1e-9;
ld PI = acos(-1.0);

int N = 100000 + 13;

int n, m, k;
li h;
pair a[100000 + 13];

bool read() {
    if (scanf("%lld%d%d%d", &h, &n, &m, &k) != 4)
        return false;
    forn(i, n)
        scanf("%lld%d", &a[i].first, &a[i].second);
    return true;
}

bool used[100000 + 13];
li mn[100000 + 13];
pt cur[100000 + 13];

void add(li x) {
    Queue* q = createQueue(k);
    forn(i, k)
        enqueue(q, i);
    while (!isEmpty(q)) {
        int v = dequeue(q);
        if (mn[v] + x < mn[(v + x) % k]) {
            mn[(v + x) % k] = mn[v] + x;
            enqueue(q, (v + x) % k);
        }
    }
    freeQueue(q);
}

void recalc() {
    forn(i, n) {
        if (!used[i] && mn[a[i].first % k] <= a[i].first) {
            cur[i].x = a[i].second;
            cur[i].y = -i;
        }
    }
}

void solve() {
    forn(i, k)
        mn[i] = h + 1;
    mn[1] = 1;
    memset(used, 0, sizeof(used));
    recalc();
    forn(i, m) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            li x;
            scanf("%lld", &x);
            add(x);
            recalc();
        }
        else if (t == 2) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--;
            if (mn[a[x].first % k] <= a[x].first) {
                cur[x].x = a[x].second;
                cur[x].y = -x;
            }
            a[x].second -= y;
            if (mn[a[x].first % k] <= a[x].first) {
                cur[x].x = a[x].second;
                cur[x].y = -x;
            }
        }
        else if (cur[0].x != 0) {
            printf("%d\n", cur[0].x);
            used[-cur[0].y] = true;
            forn(j, n) {
                cur[j] = cur[j + 1];
            }
        }
        else {
            puts("0");
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int tt = clock();
    while (read()) {
        solve();
    }
    printf("TIME = %d\n", clock() - tt);
    return 0;
}
