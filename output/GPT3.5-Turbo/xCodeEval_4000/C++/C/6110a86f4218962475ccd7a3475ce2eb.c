#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) ((int)(a.size()))
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < (int)(n); i++) 
#define fore(i, l, r) for(int i = (int)(l); i < (int)(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

typedef struct {
    li x;
    int y;
} Pair;

typedef struct {
    int front;
    int rear;
    int size;
    int* array;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->array = (int*)malloc(size * sizeof(int));
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == -1;
}

bool isQueueFull(Queue* queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->array[queue->rear] = item;
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
    return item;
}

void freeQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

li min(li a, li b) {
    return a < b ? a : b;
}

void add(li* mn, int k, li x) {
    Queue* q = createQueue(k);
    forn(i, k) {
        enqueue(q, i);
    }
    while (!isQueueEmpty(q)) {
        int v = dequeue(q);
        if (mn[v] + x < mn[(v + x) % k]) {
            mn[(v + x) % k] = mn[v] + x;
            enqueue(q, (v + x) % k);
        }
    }
    freeQueue(q);
}

void recalc(set<pt, greater<pt>>* cur, bool* used, li* mn, Pair* a, int n, int k) {
    cur->clear();
    forn(i, n) {
        if (!used[i] && mn[a[i].x % k] <= a[i].x) {
            cur->insert(mp(a[i].y, -i));
        }
    }
}

void solve() {
    int n, m, k;
    li h;
    scanf("%lld%d%d%d", &h, &n, &m, &k);
    Pair* a = (Pair*)malloc(n * sizeof(Pair));
    forn(i, n) {
        scanf("%lld%d", &a[i].x, &a[i].y);
    }
    li* mn = (li*)malloc(k * sizeof(li));
    forn(i, k) {
        mn[i] = h + 1;
    }
    mn[1] = 1;
    bool* used = (bool*)malloc(n * sizeof(bool));
    memset(used, 0, n * sizeof(bool));
    set<pt, greater<pt>> cur;
    recalc(&cur, used, mn, a, n, k);
    forn(i, m) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            li x;
            scanf("%lld", &x);
            add(mn, k, x);
            recalc(&cur, used, mn, a, n, k);
        } else if (t == 2) {
            int x, y;
            scanf("%d%d", &x, &y);
            --x;
            if (mn[a[x].x % k] <= a[x].x) {
                cur.erase(mp(a[x].y, -x));
            }
            a[x].y -= y;
            if (mn[a[x].x % k] <= a[x].x) {
                cur.insert(mp(a[x].y, -x));
            }
        } else if (!cur.empty()) {
            printf("%d\n", cur.begin()->x);
            used[-cur.begin()->y] = true;
            cur.erase(cur.begin());
        } else {
            puts("0");
        }
    }
    free(a);
    free(mn);
    free(used);
}

int main() {
    while (true) {
        if (!read()) {
            break;
        }
        solve();
    }
    return 0;
}
