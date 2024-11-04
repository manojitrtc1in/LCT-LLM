#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

float gcd(float a, float b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

double gcd(double a, double b) {
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
    if (number->dividend % 1 == 0 && number->divider % 1 == 0) {
        int Dividend = number->dividend;
        int Divider = number->divider;
        int gcd = gcd(Dividend, Divider);
        number->dividend = Dividend / gcd;
        number->divider = Divider / gcd;
    }
}

void add(Division* number, Division* number1) {
    if (number->dividend % 1 == 0 && number->divider % 1 == 0 && number1->dividend % 1 == 0 && number1->divider % 1 == 0) {
        int Dividend = number->dividend;
        int Divider = number->divider;
        int Dividend1 = number1->dividend;
        int Divider1 = number1->divider;
        int lcm = lcm(Divider, Divider1);
        number->dividend = (lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1;
        number->divider = lcm;
        reduce(number);
    }
}

void multiply(Division* number, Division* number1) {
    if (number->dividend % 1 == 0 && number->divider % 1 == 0 && number1->dividend % 1 == 0 && number1->divider % 1 == 0) {
        int first = number->dividend * number1->dividend;
        int second = number->divider * number1->divider;
        number->dividend = first;
        number->divider = second;
        reduce(number);
    }
}

typedef struct {
    int** base;
    int* used;
    int quantity;
    int* ancestor;
} Graph;

Graph* createGraph() {
    Graph* graph = malloc(sizeof(Graph));
    graph->base = NULL;
    graph->used = NULL;
    graph->quantity = 0;
    graph->ancestor = NULL;
    return graph;
}

void start(Graph* graph, int length) {
    graph->used = malloc(length * sizeof(int));
    graph->ancestor = malloc(length * sizeof(int));
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
                exit(1);
            }
        }
    }
}

int dijkstra(Graph* graph, int start, int stop, int size) {
    start--;
    stop--;
    int* dist = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        if (i != start) {
            dist[i] = INT_MAX;
        }
        graph->ancestor[i] = start;
    }

    int** queue = malloc(size * sizeof(int*));
    int queueSize = 0;
    queue[queueSize] = malloc(2 * sizeof(int));
    queue[queueSize][0] = start;
    queue[queueSize][1] = 0;
    queueSize++;
    int position;
    int* getQueue;
    while (queueSize != 0) {
        int minIndex = 0;
        for (int i = 1; i < queueSize; i++) {
            if (queue[i][1] < queue[minIndex][1]) {
                minIndex = i;
            }
        }
        getQueue = queue[minIndex];
        position = getQueue[0];
        if (getQueue[1] > dist[position]) {
            continue;
        }
        for (int index = 0; index < graph->base[position][0]; index += 2) {
            if (dist[position] + graph->base[position][index + 1] < dist[graph->base[position][index]] && !graph->used[graph->base[position][index]]) {
                dist[graph->base[position][index]] = dist[position] + graph->base[position][index + 1];
                graph->ancestor[graph->base[position][index]] = position;
                queue[queueSize] = malloc(2 * sizeof(int));
                queue[queueSize][0] = graph->base[position][index];
                queue[queueSize][1] = dist[graph->base[position][index]];
                queueSize++;
            }
        }
        graph->used[position] = 1;
        queueSize--;
        free(queue[minIndex]);
        for (int i = minIndex; i < queueSize; i++) {
            queue[i] = queue[i + 1];
        }
    }
    int result = dist[stop] == INT_MAX ? -1 : dist[stop];
    free(dist);
    for (int i = 0; i < queueSize; i++) {
        free(queue[i]);
    }
    free(queue);
    return result;
}

int** createBase(int length, int quantity, int** value) {
    int** base = malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        base[i] = malloc((value[i][0] + 1) * sizeof(int));
        base[i][0] = value[i][0];
        for (int j = 1; j <= value[i][0]; j++) {
            base[i][j] = value[i][j];
        }
    }
    return base;
}

void freeBase(int** base, int length) {
    for (int i = 0; i < length; i++) {
        free(base[i]);
    }
    free(base);
}

int** createBase2(int length, int not, int** value) {
    int** base = malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        int count = 0;
        for (int j = 0; j < length; j++) {
            if (i != j && value[i][j] != not) {
                count++;
            }
        }
        base[i] = malloc((count + 1) * sizeof(int));
        base[i][0] = count;
        int index = 1;
        for (int j = 0; j < length; j++) {
            if (i != j && value[i][j] != not) {
                base[i][index] = j;
                index++;
            }
        }
    }
    return base;
}

void freeBase2(int** base, int length) {
    for (int i = 0; i < length; i++) {
        free(base[i]);
    }
    free(base);
}

int floydWarshall(int** base, int length, int not) {
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
            return 0;
        }
    }
    return 1;
}

void fastSort(int* array, int length, int id15) {
    if (id15 < 0 || id15 > 4) {
        id15 = rand() % 4;
    }
    if (id15 == 0) {
        shellSort(array, length);
    } else if (id15 == 1) {
        heapSort(array, length);
    } else if (id15 == 2) {
        mergeSort(array, 0, length - 1);
    } else if (id15 == 3) {
        insertionSort(array, length);
    } else if (id15 == 4) {
        bubbleSort(array, length);
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

void mergeSort(int* array, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void merge(int* array, int low, int mid, int high) {
    int n = high - low + 1;
    int* temp = malloc(n * sizeof(int));
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

void bubbleSort(int* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i1;
    scanf("%d", &i1);
    for (int i2 = 0; i2 < i1; i2++) {
        int quantity[3];
        scanf("%d %d %d", &quantity[0], &quantity[1], &quantity[2]);
        int base[quantity[0]];
        for (int i = 0; i < quantity[0]; i++) {
            scanf("%d", &base[i]);
        }
        int countValue[quantity[1] + 1];
        for (int i = 0; i <= quantity[1]; i++) {
            countValue[i] = 0;
        }
        for (int i = 0; i < quantity[2]; i++) {
            int value;
            scanf("%d", &value);
            countValue[value]++;
        }
        int min = 0;
        for (int i = 1; i <= quantity[1]; i++) {
            if (countValue[i] > 0) {
                min++;
            }
        }
        for (int i = quantity[2]; i < quantity[0]; i++) {
            countValue[base[i - quantity[2]]]--;
            if (countValue[base[i - quantity[2]]] == 0) {
                min--;
            }
            countValue[base[i]]++;
            if (countValue[base[i]] == 1) {
                min++;
            }
            if (min < countValue[0]) {
                countValue[0] = min;
            }
        }
        printf("%d\n", countValue[0]);
    }
    return 0;
}
