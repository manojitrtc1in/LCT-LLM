#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 200000

typedef struct {
    int L[MAX_SIZE];
    int R[MAX_SIZE];
    int A[MAX_SIZE];
    int B[MAX_SIZE];
    int C[MAX_SIZE];
    int max[MAX_SIZE];
    int best[MAX_SIZE];
    int orderV[MAX_SIZE];
    int orderC[MAX_SIZE];
    int n, m;
    int idx;
    int L_size, R_size, A_size, B_size, C_size, max_size, best_size, orderV_size, orderC_size;
    long array[MAX_SIZE * 4 + 1];
    int n_size;
} Task;

typedef struct {
    int left;
    int right;
    int middle;
} Interval;

void update(Task *task, int pos, long x);
void update_helper(Task *task, int node, int left, int right, int pos, long val);
long query(Task *task, int from, int to);
long query_helper(Task *task, int node, int left, int right, int from, int to);
void solve(Task *task);
void process1(Task *task);
void process2(Task *task);
void process3(Task *task);
void init(Task *task);
void init_helper(Task *task, int root, int left, int right);
void init_leaf(Task *task, int root, int index);
void id5(Task *task, int root, int left, int right, int from, int to, long delta, int middle);
void id10(Task *task, int root, int left, int right, int from, int to, long delta, int middle);
void update_full(Task *task, int root, int left, int right, int from, int to, long delta);
long id8(Task *task, int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult);
void id9(Task *task, int root, int left, int right, int from, int to, int middle);
long query_full(Task *task, int root, int left, int right, int from, int to);
long id0();

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void update(Task *task, int pos, long x) {
    update_helper(task, 0, 0, task->n - 1, pos, x);
}

void update_helper(Task *task, int node, int left, int right, int pos, long val) {
    if (left == right) {
        task->array[node] = val;
        return;
    }
    int middle = (left + right) / 2;
    if (pos <= middle) {
        update_helper(task, 2 * node + 1, left, middle, pos, val);
    } else {
        update_helper(task, 2 * node + 2, middle + 1, right, pos, val);
    }
    task->array[node] = (task->array[2 * node + 1] > task->array[2 * node + 2]) ? task->array[2 * node + 1] : task->array[2 * node + 2];
}

long query(Task *task, int from, int to) {
    return query_helper(task, 0, 0, task->n - 1, from, to);
}

long query_helper(Task *task, int node, int left, int right, int from, int to) {
    if (left > to || right < from) {
        return 0;
    }
    if (left >= from && right <= to) {
        return task->array[node];
    }
    int middle = (left + right) / 2;
    return (query_helper(task, 2 * node + 1, left, middle, from, to) > query_helper(task, 2 * node + 2, middle + 1, right, from, to)) ? query_helper(task, 2 * node + 1, left, middle, from, to) : query_helper(task, 2 * node + 2, middle + 1, right, from, to);
}

void solve(Task *task) {
    int i, j, x, v, c, ret, idx, aux;
    long length, a, b, ret;
    bool flag = task->n == 200000 && task->m == 200000;
    for (i = 0; i < task->n; i++) {
        task->orderV[i] = i;
    }
    for (i = 0; i < task->m; i++) {
        task->orderC[i] = i;
    }
    qsort(task->orderV, task->n, sizeof(int), compare);
    qsort(task->orderC, task->m, sizeof(int), compare);
    int arr[2 * (task->n + task->m)];
    for (i = 0; i < task->n; i++) {
        arr[2 * i] = task->L[i];
        arr[2 * i + 1] = task->R[i];
    }
    for (i = 0; i < task->m; i++) {
        arr[2 * (task->n + i)] = task->A[i];
        arr[2 * (task->n + i) + 1] = task->B[i];
    }
    qsort(arr, 2 * (task->n + task->m), sizeof(int), compare);
    task->idx = 0;
    for (i = 0; i < 2 * (task->n + task->m); i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            task->map[arr[i]] = task->idx++;
        }
    }
    init(task);
    process1(task);
    process2(task);
    process3(task);
    ret = 0;
    aux = -1;
    for (i = 0; i < task->m; i++) {
        ret = 1L * task->max[i] * task->C[i];
        if (ret > ret) {
            ret = ret;
            aux = i;
        }
    }
    printf("%ld\n", ret);
    if (ret > 0) {
        printf("%d %d\n", task->best[aux] + 1, aux + 1);
    }
}

void process1(Task *task) {
    int i, j, x, v, c, ret, idx;
    for (i = 0; i < task->n || c < task->m; ) {
        for (; i < task->n && (c == task->m || task->L[task->orderV[i]] <= task->A[task->orderC[c]]); i++) {
            x = task->orderV[i];
            if (task->R[x] > ret) {
                ret = task->R[x];
                idx = x;
            }
        }
        for (; c < task->m && (i == task->n || task->A[task->orderC[c]] < task->L[task->orderV[i]]); c++) {
            x = task->orderC[c];
            length = (task->B[x] - task->A[x]) < ret ? (task->B[x] - task->A[x]) : ret;
            if (length > task->max[x]) {
                task->max[x] = length;
                task->best[x] = idx;
            }
        }
    }
}

void process2(Task *task) {
    int i, j, x, v, c, ret, idx;
    for (i = task->n - 1, c = task->m - 1; i >= 0 || c >= 0; ) {
        for (; i >= 0 && (c == -1 || task->R[task->orderV[i]] >= task->B[task->orderC[c]]); i--) {
            x = task->orderV[i];
            if (task->L[x] < ret) {
                ret = task->L[x];
                idx = x;
            }
        }
        for (; c >= 0 && (i == -1 || task->B[task->orderC[c]] > task->R[task->orderV[i]]); c--) {
            x = task->orderC[c];
            length = task->B[x] - (task->A[x] > ret ? task->A[x] : ret);
            if (length > task->max[x]) {
                task->max[x] = length;
                task->best[x] = idx;
            }
        }
    }
}

void process3(Task *task) {
    int i, j, x, v, c, ret, idx;
    for (i = 0; i < task->n || c < task->m; ) {
        for (; i < task->n && (c == task->m || task->L[task->orderV[i]] <= task->A[task->orderC[c]]); i++) {
            x = task->orderV[i];
            if (task->R[x] > ret) {
                ret = task->R[x];
                idx = x;
            }
        }
        for (; c < task->m && (i == task->n || task->A[task->orderC[c]] < task->L[task->orderV[i]]); c++) {
            x = task->orderC[c];
            length = task->B[x] - (task->A[x] > ret ? task->A[x] : ret);
            if (length > task->max[x]) {
                task->max[x] = length;
                task->best[x] = idx;
            }
        }
    }
}

void init(Task *task) {
    init_helper(task, 0, 0, task->n - 1);
}

void init_helper(Task *task, int root, int left, int right) {
    if (left == right) {
        init_leaf(task, root, left);
    } else {
        int middle = (left + right) / 2;
        init_before(task, root, left, right, middle);
        init_helper(task, 2 * root + 1, left, middle);
        init_helper(task, 2 * root + 2, middle + 1, right);
        init_after(task, root, left, right, middle);
    }
}

void init_leaf(Task *task, int root, int index) {
    task->array[root] = init_value(task, index);
}

void id5(Task *task, int root, int left, int right, int from, int to, long delta, int middle) {
    task->array[root] = join_value(task, task->array[2 * root + 1], task->array[2 * root + 2]);
}

void id10(Task *task, int root, int left, int right, int from, int to, long delta, int middle) {
    push_down(task, root, left, middle, right);
}

void push_down(Task *task, int root, int left, int middle, int right) {
    task->array[2 * root + 1] = accumulate(task, task->array[2 * root + 1], task->delta[root], middle - left + 1);
    task->array[2 * root + 2] = accumulate(task, task->array[2 * root + 2], task->delta[root], right - middle);
    task->delta[2 * root + 1] = join_delta(task, task->delta[2 * root + 1], task->delta[root]);
    task->delta[2 * root + 2] = join_delta(task, task->delta[2 * root + 2], task->delta[root]);
    task->delta[root] = neutral_delta(task);
}

void update_full(Task *task, int root, int left, int right, int from, int to, long delta) {
    task->array[root] = accumulate(task, task->array[root], delta, right - left + 1);
    task->delta[root] = join_delta(task, task->delta[root], delta);
}

