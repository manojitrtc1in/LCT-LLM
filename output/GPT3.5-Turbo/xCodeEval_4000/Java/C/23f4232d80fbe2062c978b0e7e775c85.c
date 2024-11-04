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
    void* first;
    void* second;
} Pair;

Pair* createPair(void* element, void* element1) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->first = element;
    pair->second = element1;
    return pair;
}

typedef struct {
    Pair* pair;
    void (*useArray)(int* a);
} Array;

typedef struct {
    void (*use)();
} Method;

typedef struct {
    int** base;
    int* used;
    int quantity;
    int* ancestor;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->base = NULL;
    graph->used = NULL;
    graph->quantity = 0;
    graph->ancestor = NULL;
    return graph;
}

void start(Graph* graph, int length) {
    graph->used = (int*)calloc(length, sizeof(int));
    graph->ancestor = (int*)malloc(length * sizeof(int));
    graph->ancestor[0] = -1;
    graph->quantity = 0;
}

void ribMatrixToDefault(Graph* graph, int length, int quantity, int** value) {
    graph->base = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        graph->base[i] = (int*)malloc(length * sizeof(int));
        for (int j = 0; j < length; j++) {
            graph->base[i][j] = 0;
        }
    }
    for (int i = 0; i < quantity; i++) {
        int* input = value[i];
        graph->base[input[0] - 1][input[1] - 1] = 1;
        graph->base[input[1] - 1][input[0] - 1] = 1;
    }
    start(graph, length);
}

void adjacencyMatrixToDefault(Graph* graph, int length, int not, int** value) {
    graph->base = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        graph->base[i] = (int*)malloc(length * sizeof(int));
        for (int j = 0; j < length; j++) {
            graph->base[i][j] = 0;
        }
    }
    for (int i = 0; i < length; i++) {
        int* input = value[i];
        for (int j = 0; j < length; j++) {
            if (i != j && input[j] != not) {
                graph->base[i][j] = 1;
            }
        }
    }
    start(graph, length);
}

void dfs(Graph* graph, int position) {
    graph->used[position] = 1;
    graph->quantity++;
    int next;
    for (int index = 0; index < sizeof(graph->base[position]) / sizeof(int); index += 2) {
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
        for (int index = 0; index < sizeof(graph->base[position]) / sizeof(int); index += 2) {
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

void sort(int* array, int length, int ShellHeapMergeMyInsertionSort) {
    if (ShellHeapMergeMyInsertionSort < 0 || ShellHeapMergeMyInsertionSort > 4) {
        ShellHeapMergeMyInsertionSort = rand() % 4;
    }
    if (ShellHeapMergeMyInsertionSort == 0) {
        ShellSort(array, length);
    } else if (ShellHeapMergeMyInsertionSort == 1) {
        HeapSort(array, length);
    } else if (ShellHeapMergeMyInsertionSort == 2) {
        MergeSort(array, 0, length - 1);
    } else if (ShellHeapMergeMyInsertionSort == 3) {
        straightMergeSort(array, length);
    } else if (ShellHeapMergeMyInsertionSort == 4) {
        insertionSort(array, length);
    }
}

void ShellSort(int* array, int length) {
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

void HeapSort(int* array, int length) {
    for (int i = length / 2 - 1; i >= 0; i--)
        shiftDown(array, i, length);
    for (int i = length - 1; i > 0; i--) {
        swap(array, 0, i);
        shiftDown(array, 0, i);
    }
}

void shiftDown(int* array, int i, int n) {
    int child;
    int tmp;
    for (tmp = array[i]; 2 * i + 1 < n; i = child) {
        child = 2 * i + 1;
        if (child != n - 1 && (array[child] < array[child + 1]))
            child++;
        if (tmp < array[child])
            array[i] = array[child];
        else
            break;
    }
    array[i] = tmp;
}

void swap(int* array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void MergeSort(int* array, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(array, low, mid);
        MergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void merge(int* array, int low, int mid, int high) {
    int n = high - low + 1;
    int* Temp = (int*)malloc(n * sizeof(int));
    int i = low, j = mid + 1;
    int k = 0;
    while (i <= mid || j <= high) {
        if (i > mid)
            Temp[k++] = array[j++];
        else if (j > high)
            Temp[k++] = array[i++];
        else if (array[i] < array[j])
            Temp[k++] = array[i++];
        else
            Temp[k++] = array[j++];
    }
    for (j = 0; j < n; j++)
        array[low + j] = Temp[j];
}

void straightMergeSort(int* array, int size) {
    if (size == 0) {
        return;
    }
    int length = (size / 2) + ((size % 2) == 0 ? 0 : 1);
    int** ZeroBuffer = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        ZeroBuffer[i] = (int*)malloc(2 * sizeof(int));
    }
    int** FirstBuffer = NULL;
    for (int index = 0; index < length; index++) {
        int ArrayIndex = index * 2;
        int NextArrayIndex = index * 2 + 1;
        if (NextArrayIndex < size) {
            if (array[ArrayIndex] > array[NextArrayIndex]) {
                ZeroBuffer[index][0] = array[NextArrayIndex];
                ZeroBuffer[index][1] = array[ArrayIndex];
            } else {
                ZeroBuffer[index][0] = array[ArrayIndex];
                ZeroBuffer[index][1] = array[NextArrayIndex];
            }
        } else {
            ZeroBuffer[index][0] = array[ArrayIndex];
        }
    }
    int position = 0;
    int pointer0, pointer, pointer1, number = 4, NewPointer, count;
    int** NewBuffer;
    int** OldBuffer;
    length = (size / 4) + ((size % 4) == 0 ? 0 : 1);
    while (1) {
        pointer0 = 0;
        count = (number / 2) - 1;
        if (position == 0) {
            FirstBuffer = (int**)malloc(length * sizeof(int*));
            for (int i = 0; i < length; i++) {
                FirstBuffer[i] = (int*)malloc(number * sizeof(int));
            }
            NewBuffer = FirstBuffer;
            OldBuffer = ZeroBuffer;
        } else {
            ZeroBuffer = (int**)malloc(length * sizeof(int*));
            for (int i = 0; i < length; i++) {
                ZeroBuffer[i] = (int*)malloc(number * sizeof(int));
            }
            NewBuffer = ZeroBuffer;
            OldBuffer = FirstBuffer;
        }
        for (int i = 0; i < length; i++) {
            pointer = 0;
            pointer1 = 0;
            NewPointer = pointer0 + 1;
            if (length == 1) {
                for (int g = 0; g < size; g++) {
                    if (pointer > count || OldBuffer[pointer0][pointer] == NULL) {
                        array[g] = OldBuffer[NewPointer][pointer1];
                        pointer1++;
                    } else if (pointer1 > count || OldBuffer[NewPointer][pointer1] == NULL) {
                        if (OldBuffer[pointer0][pointer] == NULL) {
                            continue;
                        }
                        array[g] = OldBuffer[pointer0][pointer];
                        pointer++;
                    } else if (OldBuffer[pointer0][pointer] >= OldBuffer[NewPointer][pointer1]) {
                        array[g] = OldBuffer[NewPointer][pointer1];
                        pointer1++;
                    } else {
                        array[g] = OldBuffer[pointer0][pointer];
                        pointer++;
                    }
                }
                return;
            }
            for (int g = 0; g < number; g++) {
                if (pointer > count || OldBuffer[pointer0][pointer] == NULL) {
                    if (OldBuffer[NewPointer][pointer1] == NULL) {
                        continue;
                    }
                    NewBuffer[i][g] = OldBuffer[NewPointer][pointer1];
                    pointer1++;
                } else if (pointer1 > count || OldBuffer[NewPointer][pointer1] == NULL) {
                    if (OldBuffer[pointer0][pointer] == NULL) {
                        continue;
                    }
                    NewBuffer[i][g] = OldBuffer[pointer0][pointer];
                    pointer++;
                } else if (OldBuffer[pointer0][pointer] >= OldBuffer[NewPointer][pointer1]) {
                    NewBuffer[i][g] = OldBuffer[NewPointer][pointer1];
                    pointer1++;
                } else {
                    NewBuffer[i][g] = OldBuffer[pointer0][pointer];
                    pointer++;
                }
            }
            pointer0 += 2;
        }
        position = !position;
        length = length / 2 + length % 2;
        number *= 2;
    }
}

void sortWithoutReturn(int* array, int length, int ShellHeapMergeMyInsertionSort) {
    sort(array, length, ShellHeapMergeMyInsertionSort);
}

int* sortWithReturn(int* array, int length, int ShellHeapMergeMyInsertionSort) {
    int* base = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        base[i] = array[i];
    }
    sort(base, length, ShellHeapMergeMyInsertionSort);
    return base;
}

typedef struct {
    void* dividend;
    void* divider;
} Division;

Division* createDivision(void* dividend, void* divider) {
    Division* division = (Division*)malloc(sizeof(Division));
    division->dividend = dividend;
    division->divider = divider;
    return division;
}

void reduce(Division* division) {
    if (division->dividend == NULL || division->divider == NULL) {
        return;
    }
    if (division->dividend == (int*)division->dividend && division->divider == (int*)division->divider) {
        int Dividend = *(int*)division->dividend;
        int Divider = *(int*)division->divider;
        int gcd = gcd(Dividend, Divider);
        *(int*)division->dividend = Dividend / gcd;
        *(int*)division->divider = Divider / gcd;
    } else if (division->dividend == (long*)division->dividend && division->divider == (long*)division->divider) {
        long Dividend = *(long*)division->dividend;
        long Divider = *(long*)division->divider;
        long gcd = gcd(Dividend, Divider);
        *(long*)division->dividend = Dividend / gcd;
        *(long*)division->divider = Divider / gcd;
    } else if (division->dividend == (float*)division->dividend && division->divider == (float*)division->divider) {
        float Dividend = *(float*)division->dividend;
        float Divider = *(float*)division->divider;
        float gcd = gcd(Dividend, Divider);
        *(float*)division->dividend = Dividend / gcd;
        *(float*)division->divider = Divider / gcd;
    } else if (division->dividend == (double*)division->dividend && division->divider == (double*)division->divider) {
        double Dividend = *(double*)division->dividend;
        double Divider = *(double*)division->divider;
        double gcd = gcd(Dividend, Divider);
        *(double*)division->dividend = Dividend / gcd;
        *(double*)division->divider = Divider / gcd;
    }
}

void addWithoutReturn(Division* number1, Division* number2) {
    if (number1->dividend == NULL || number1->divider == NULL || number2->dividend == NULL || number2->divider == NULL) {
        return;
    }
    if (number1->dividend == (int*)number1->dividend && number1->divider == (int*)number1->divider && number2->dividend == (int*)number2->dividend && number2->divider == (int*)number2->divider) {
        int Dividend = *(int*)number1->dividend;
        int Divider = *(int*)number1->divider;
        int Dividend1 = *(int*)number2->dividend;
        int Divider1 = *(int*)number2->divider;
        int lcm = lcm(Divider, Divider1);
        *(int*)number1->dividend = (lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1;
        *(int*)number1->divider = lcm;
        reduce(number1);
    } else if (number1->dividend == (long*)number1->dividend && number1->divider == (long*)number1->divider && number2->dividend == (long*)number2->dividend && number2->divider == (long*)number2->divider) {
        long Dividend = *(long*)number1->dividend;
        long Divider = *(long*)number1->divider;
        long Dividend1 = *(long*)number2->dividend;
        long Divider1 = *(long*)number2->divider;
        long lcm = lcm(Divider, Divider1);
        *(long*)number1->dividend = (lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1;
        *(long*)number1->divider = lcm;
        reduce(number1);
    } else if (number1->dividend == (float*)number1->dividend && number1->divider == (float*)number1->divider && number2->dividend == (float*)number2->dividend && number2->divider == (float*)number2->divider) {
        float Dividend = *(float*)number1->dividend;
        float Divider = *(float*)number1->divider;
        float Dividend1 = *(float*)number2->dividend;
        float Divider1 = *(float*)number2->divider;
        float lcm = lcm(Divider, Divider1);
        *(float*)number1->dividend = (lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1;
        *(float*)number1->divider = lcm;
        reduce(number1);
    } else if (number1->dividend == (double*)number1->dividend && number1->divider == (double*)number1->divider && number2->dividend == (double*)number2->dividend && number2->divider == (double*)number2->divider) {
        double Dividend = *(double*)number1->dividend;
        double Divider = *(double*)number1->divider;
        double Dividend1 = *(double*)number2->dividend;
        double Divider1 = *(double*)number2->divider;
        double lcm = lcm(Divider, Divider1);
        *(double*)number1->dividend = (lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1;
        *(double*)number1->divider = lcm;
        reduce(number1);
    }
}

Division* addWithReturn(Division* number1, Division* number2) {
    if (number1->dividend == NULL || number1->divider == NULL || number2->dividend == NULL || number2->divider == NULL) {
        return NULL;
    }
    Division* result = createDivision(number1->dividend, number1->divider);
    addWithoutReturn(result, number2);
    return result;
}

void multiplyWithoutReturn(Division* number1, Division* number2) {
    if (number1->dividend == NULL || number1->divider == NULL || number2->dividend == NULL || number2->divider == NULL) {
        return;
    }
    if (number1->dividend == (int*)number1->dividend && number1->divider == (int*)number1->divider && number2->dividend == (int*)number2->dividend && number2->divider == (int*)number2->divider) {
        int first = *(int*)number1->dividend * *(int*)number2->dividend;
        int second = *(int*)number1->divider * *(int*)number2->divider;
        *(int*)number1->dividend = first;
        *(int*)number1->divider = second;
        reduce(number1);
    } else if (number1->dividend == (long*)number1->dividend && number1->divider == (long*)number1->divider && number2->dividend == (long*)number2->dividend && number2->divider == (long*)number2->divider) {
        long first = *(long*)number1->dividend * *(long*)number2->dividend;
        long second = *(long*)number1->divider * *(long*)number2->divider;
        *(long*)number1->dividend = first;
        *(long*)number1->divider = second;
        reduce(number1);
    } else if (number1->dividend == (float*)number1->dividend && number1->divider == (float*)number1->divider && number2->dividend == (float*)number2->dividend && number2->divider == (float*)number2->divider) {
        float first = *(float*)number1->dividend * *(float*)number2->dividend;
        float second = *(float*)number1->divider * *(float*)number2->divider;
        *(float*)number1->dividend = first;
        *(float*)number1->divider = second;
        reduce(number1);
    } else if (number1->dividend == (double*)number1->dividend && number1->divider == (double*)number1->divider && number2->dividend == (double*)number2->dividend && number2->divider == (double*)number2->divider) {
        double first = *(double*)number1->dividend * *(double*)number2->dividend;
        double second = *(double*)number1->divider * *(double*)number2->divider;
        *(double*)number1->dividend = first;
        *(double*)number1->divider = second;
        reduce(number1);
    }
}

Division* multiplyWithReturn(Division* number1, Division* number2) {
    if (number1->dividend == NULL || number1->divider == NULL || number2->dividend == NULL || number2->divider == NULL) {
        return NULL;
    }
    Division* result = createDivision(number1->dividend, number1->divider);
    multiplyWithoutReturn(result, number2);
    return result;
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
        int countValue[quantity[1]][2];
        for (int i = 0; i < quantity[1]; i++) {
            countValue[i][0] = 0;
            countValue[i][1] = 0;
        }
        int min = quantity[1];
        for (int i = 0; i < quantity[2]; i++) {
            countValue[base[i] - 1][0]++;
            countValue[base[i] - 1][1]++;
            if (countValue[base[i] - 1][0] == 1) {
                min--;
            }
        }
        for (int i = quantity[2]; i < quantity[0]; i++) {
            countValue[base[i - quantity[2]] - 1][0]--;
            if (countValue[base[i - quantity[2]] - 1][0] == 0) {
                min++;
            }
            countValue[base[i] - 1][0]++;
            if (countValue[base[i] - 1][0] == 1) {
                min--;
            }
            if (min < quantity[1]) {
                quantity[1] = min;
            }
        }
        printf("%d\n", quantity[1]);
    }
    return 0;
}
