#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

double lcm(double a, double b) {
    return a / gcd(a, b) * b;
}

float lcm(float a, float b) {
    return a / gcd(a, b) * b;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

long lcm(long a, long b) {
    return a / gcd(a, b) * b;
}

typedef struct {
    int first;
    int second;
} Pair;

Pair createPair(int element, int element1) {
    Pair pair;
    pair.first = element;
    pair.second = element1;
    return pair;
}

typedef struct {
    int dividend;
    int divider;
} Division;

Division createDivision(int dividend, int divider) {
    Division division;
    division.dividend = dividend;
    division.divider = divider;
    return division;
}

void reduce(Division* number) {
    int gcd;
    if (number->dividend % number->divider == 0) {
        gcd = number->dividend / number->divider;
    } else {
        gcd = gcd(number->dividend, number->divider);
    }
    number->dividend /= gcd;
    number->divider /= gcd;
}

void add(Division* number, Division* number1) {
    int lcm = lcm(number->divider, number1->divider);
    number->dividend = (lcm / number->divider) * number->dividend + (lcm / number1->divider) * number1->dividend;
    number->divider = lcm;
    reduce(number);
}

void multiply(Division* number, Division* number1) {
    number->dividend *= number1->dividend;
    number->divider *= number1->divider;
    reduce(number);
}

typedef struct {
    int** base;
    int* used;
    int quantity;
    int* ancestor;
} Graph;

Graph createGraph(int length) {
    Graph graph;
    graph.base = (int**)malloc(length * sizeof(int*));
    graph.used = (int*)calloc(length, sizeof(int));
    graph.quantity = 0;
    graph.ancestor = (int*)malloc(length * sizeof(int));
    graph.ancestor[0] = -1;
    return graph;
}

void start(Graph* graph, int length) {
    free(graph->used);
    free(graph->ancestor);
    graph->used = (int*)calloc(length, sizeof(int));
    graph->ancestor = (int*)malloc(length * sizeof(int));
    graph->ancestor[0] = -1;
    graph->quantity = 0;
}

void dfs(Graph* graph, int position) {
    graph->used[position] = 1;
    graph->quantity++;
    int next;
    for (int index = 0; index < graph->base[position][0]; index += 2) {
        next = graph->base[position][index];
        if (!graph->used[next]) {
            graph->ancestor[next] = position;
            dfs(graph, next);
        } else {
            if (next != graph->ancestor[position]) {
                printf("Exception\n");
                exit(0);
            }
        }
    }
}

int dijkstra(Graph* graph, int start, int stop, int size) {
    start--;
    stop--;
    int* dist = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        if (i != start) {
            dist[i] = INT_MAX;
        }
        graph->ancestor[i] = start;
    }

    int** queue = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        queue[i] = (int*)malloc(2 * sizeof(int));
    }
    int position;
    int* getQueue;
    int queueSize = 0;
    while (queueSize != 0) {
        getQueue = queue[0];
        position = getQueue[0];
        if (getQueue[1] > dist[position]) {
            continue;
        }
        for (int index = 0; index < graph->base[position][0]; index += 2) {
            if (dist[position] + graph->base[position][index + 1] < dist[graph->base[position][index]] && !graph->used[graph->base[position][index]]) {
                dist[graph->base[position][index]] = dist[position] + graph->base[position][index + 1];
                graph->ancestor[graph->base[position][index]] = position;
                queue[queueSize][0] = graph->base[position][index];
                queue[queueSize][1] = dist[graph->base[position][index]];
                queueSize++;
            }
        }
        graph->used[position] = 1;
    }
    return dist[stop] == INT_MAX ? -1 : dist[stop];
}

void floydWarshall(int** base, int length, int not) {
    for (int k = 0; k < length; k++) {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (base[i][k] == not || base[k][j] == not) {
                    continue;
                }
                int total = base[i][k] + base[k][j];
                if (base[i][j] != not) {
                    base[i][j] = base[i][j] < total ? base[i][j] : total;
                } else {
                    base[i][j] = total;
                }
            }
        }
    }
    for (int index = 0; index < length; index++) {
        if (base[index][index] != 0) {
            printf("Exception\n");
            exit(0);
        }
    }
}

void shellSort(int* array, int length) {
    int j;
    for (int gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i++) {
            int temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void heapSort(int* array, int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        shiftDown(array, i, length);
    }
    for (int i = length - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        shiftDown(array, 0, i);
    }
}

void shiftDown(int* array, int i, int n) {
    int child;
    int tmp;
    for (tmp = array[i]; 2 * i + 1 < n; i = child) {
        child = 2 * i + 1;
        if (child != n - 1 && array[child] < array[child + 1]) {
            child++;
        }
        if (tmp < array[child]) {
            array[i] = array[child];
        } else {
            break;
        }
    }
    array[i] = tmp;
}

void merge(int* array, int low, int mid, int high) {
    int n = high - low + 1;
    int* temp = (int*)malloc(n * sizeof(int));
    int i = low, j = mid + 1;
    int k = 0;
    while (i <= mid || j <= high) {
        if (i > mid) {
            temp[k++] = array[j++];
        } else if (j > high) {
            temp[k++] = array[i++];
        } else if (array[i] < array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }
    for (j = 0; j < n; j++) {
        array[low + j] = temp[j];
    }
    free(temp);
}

void mergeSort(int* array, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void insertionSort(int* array, int length) {
    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    int i1;
    scanf("%d", &i1);
    for (int i = 0; i < i1; i++) {
        int quantity[3];
        scanf("%d %d %d", &quantity[0], &quantity[1], &quantity[2]);
        int* base = (int*)malloc(quantity[2] * sizeof(int));
        for (int j = 0; j < quantity[2]; j++) {
            scanf("%d", &base[j]);
        }
        int min = 0;
        int* countValue = (int*)calloc(quantity[0], sizeof(int));
        for (int j = 0; j < quantity[2]; j++) {
            countValue[base[j]]++;
            if (countValue[base[j]] == 1) {
                min++;
            }
        }
        for (int j = quantity[2]; j < quantity[0]; j++) {
            countValue[base[j - quantity[2]]]--;
            if (countValue[base[j - quantity[2]]] == 0) {
                min--;
            }
            countValue[base[j]]++;
            if (countValue[base[j]] == 1) {
                min++;
            }
            if (min < countValue[base[j]]) {
                min = countValue[base[j]];
            }
        }
        printf("%d\n", min);
        free(base);
        free(countValue);
    }
    return 0;
}
