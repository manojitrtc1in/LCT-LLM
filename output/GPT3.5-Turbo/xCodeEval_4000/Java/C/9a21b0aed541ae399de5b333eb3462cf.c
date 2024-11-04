#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
    void* first;
    void* second;
} Pair;

Pair* createPair(void* element, void* element1) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->first = element;
    pair->second = element1;
    return pair;
}

typedef struct Division {
    Pair* pair;
    void (*reduce)();
    void (*addWithoutReturn)();
    Division* (*addWithReturn)();
    void (*multiplyWithoutReturn)();
    Division* (*multiplyWithReturn)();
} Division;

void reduce(Division* division) {
    if (division->pair->first == (int*)division->pair->first && division->pair->second == (int*)division->pair->second) {
        int dividend = *(int*)division->pair->first;
        int divider = *(int*)division->pair->second;
        int gcd = dividend;
        int temp;
        while (divider != 0) {
            temp = gcd % divider;
            gcd = divider;
            divider = temp;
        }
        *(int*)division->pair->first = *(int*)division->pair->first / gcd;
        *(int*)division->pair->second = *(int*)division->pair->second / gcd;
    }
    else if (division->pair->first == (long*)division->pair->first && division->pair->second == (long*)division->pair->second) {
        long dividend = *(long*)division->pair->first;
        long divider = *(long*)division->pair->second;
        long gcd = dividend;
        long temp;
        while (divider != 0) {
            temp = gcd % divider;
            gcd = divider;
            divider = temp;
        }
        *(long*)division->pair->first = *(long*)division->pair->first / gcd;
        *(long*)division->pair->second = *(long*)division->pair->second / gcd;
    }
    else if (division->pair->first == (float*)division->pair->first && division->pair->second == (float*)division->pair->second) {
        float dividend = *(float*)division->pair->first;
        float divider = *(float*)division->pair->second;
        float gcd = dividend;
        float temp;
        while (divider != 0) {
            temp = fmod(gcd, divider);
            gcd = divider;
            divider = temp;
        }
        *(float*)division->pair->first = *(float*)division->pair->first / gcd;
        *(float*)division->pair->second = *(float*)division->pair->second / gcd;
    }
    else if (division->pair->first == (double*)division->pair->first && division->pair->second == (double*)division->pair->second) {
        double dividend = *(double*)division->pair->first;
        double divider = *(double*)division->pair->second;
        double gcd = dividend;
        double temp;
        while (divider != 0) {
            temp = fmod(gcd, divider);
            gcd = divider;
            divider = temp;
        }
        *(double*)division->pair->first = *(double*)division->pair->first / gcd;
        *(double*)division->pair->second = *(double*)division->pair->second / gcd;
    }
}

void addWithoutReturn(Division* division, Division* number) {
    add(division, number, 0);
}

Division* addWithReturn(Division* division, Division* number) {
    return add(division, number, 1);
}

void multiplyWithoutReturn(Division* division, Division* number) {
    multiply(division, number, 0);
}

Division* multiplyWithReturn(Division* division, Division* number) {
    return multiply(division, number, 1);
}

void add(Division* division, Division* number, int function) {
    if (division->pair->first == (int*)division->pair->first && number->pair->first == (int*)number->pair->first) {
        int dividend = *(int*)division->pair->first;
        int divider = *(int*)division->pair->second;
        int dividend1 = *(int*)number->pair->first;
        int divider1 = *(int*)number->pair->second;
        int lcm = (divider * divider1) / gcd(divider, divider1);
        if (function == 0) {
            *(int*)division->pair->first = (lcm / divider) * dividend + (lcm / divider1) * dividend1;
            *(int*)division->pair->second = lcm;
            reduce(division);
        }
        else {
            Division* result = (Division*)malloc(sizeof(Division));
            result->pair = createPair((void*)((lcm / divider) * dividend + (lcm / divider1) * dividend1), (void*)lcm);
            result->reduce = reduce;
            result->addWithoutReturn = addWithoutReturn;
            result->addWithReturn = addWithReturn;
            result->multiplyWithoutReturn = multiplyWithoutReturn;
            result->multiplyWithReturn = multiplyWithReturn;
            reduce(result);
            return result;
        }
    }
    else if (division->pair->first == (long*)division->pair->first && number->pair->first == (long*)number->pair->first) {
        long dividend = *(long*)division->pair->first;
        long divider = *(long*)division->pair->second;
        long dividend1 = *(long*)number->pair->first;
        long divider1 = *(long*)number->pair->second;
        long lcm = (divider * divider1) / gcd(divider, divider1);
        if (function == 0) {
            *(long*)division->pair->first = (lcm / divider) * dividend + (lcm / divider1) * dividend1;
            *(long*)division->pair->second = lcm;
            reduce(division);
        }
        else {
            Division* result = (Division*)malloc(sizeof(Division));
            result->pair = createPair((void*)((lcm / divider) * dividend + (lcm / divider1) * dividend1), (void*)lcm);
            result->reduce = reduce;
            result->addWithoutReturn = addWithoutReturn;
            result->addWithReturn = addWithReturn;
            result->multiplyWithoutReturn = multiplyWithoutReturn;
            result->multiplyWithReturn = multiplyWithReturn;
            reduce(result);
            return result;
        }
    }
    else if (division->pair->first == (float*)division->pair->first && number->pair->first == (float*)number->pair->first) {
        float dividend = *(float*)division->pair->first;
        float divider = *(float*)division->pair->second;
        float dividend1 = *(float*)number->pair->first;
        float divider1 = *(float*)number->pair->second;
        float lcm = (divider * divider1) / gcd(divider, divider1);
        if (function == 0) {
            *(float*)division->pair->first = (lcm / divider) * dividend + (lcm / divider1) * dividend1;
            *(float*)division->pair->second = lcm;
            reduce(division);
        }
        else {
            Division* result = (Division*)malloc(sizeof(Division));
            result->pair = createPair((void*)((lcm / divider) * dividend + (lcm / divider1) * dividend1), (void*)lcm);
            result->reduce = reduce;
            result->addWithoutReturn = addWithoutReturn;
            result->addWithReturn = addWithReturn;
            result->multiplyWithoutReturn = multiplyWithoutReturn;
            result->multiplyWithReturn = multiplyWithReturn;
            reduce(result);
            return result;
        }
    }
    else if (division->pair->first == (double*)division->pair->first && number->pair->first == (double*)number->pair->first) {
        double dividend = *(double*)division->pair->first;
        double divider = *(double*)division->pair->second;
        double dividend1 = *(double*)number->pair->first;
        double divider1 = *(double*)number->pair->second;
        double lcm = (divider * divider1) / gcd(divider, divider1);
        if (function == 0) {
            *(double*)division->pair->first = (lcm / divider) * dividend + (lcm / divider1) * dividend1;
            *(double*)division->pair->second = lcm;
            reduce(division);
        }
        else {
            Division* result = (Division*)malloc(sizeof(Division));
            result->pair = createPair((void*)((lcm / divider) * dividend + (lcm / divider1) * dividend1), (void*)lcm);
            result->reduce = reduce;
            result->addWithoutReturn = addWithoutReturn;
            result->addWithReturn = addWithReturn;
            result->multiplyWithoutReturn = multiplyWithoutReturn;
            result->multiplyWithReturn = multiplyWithReturn;
            reduce(result);
            return result;
        }
    }
}

Division* add(Division* division, Division* number, int function) {
    if (division->pair->first == (int*)division->pair->first && number->pair->first == (int*)number->pair->first) {
        int dividend = *(int*)division->pair->first;
        int divider = *(int*)division->pair->second;
        int dividend1 = *(int*)number->pair->first;
        int divider1 = *(int*)number->pair->second;
        int lcm = (divider * divider1) / gcd(divider, divider1);
        if (function == 0) {
            *(int*)division->pair->first = (lcm / divider) * dividend + (lcm / divider1) * dividend1;
            *(int*)division->pair->second = lcm;
            reduce(division);
        }
        else {
            Division* result = (Division*)malloc(sizeof(Division));
            result->pair = createPair((void*)((lcm / divider) * dividend + (lcm / divider1) * dividend1), (void*)lcm);
            result->reduce = reduce;
            result->addWithoutReturn = addWithoutReturn;
            result->addWithReturn = addWithReturn;
            result->multiplyWithoutReturn = multiplyWithoutReturn;
            result->multiplyWithReturn = multiplyWithReturn;
            reduce(result);
            return result;
        }
    }
    else if (division->pair->first == (long*)division->pair->first && number->pair->first == (long*)number->pair->first) {
        long dividend = *(long*)division->pair->first;
        long divider = *(long*)division->pair->second;
        long dividend1 = *(long*)number->pair->first;
        long divider1 = *(long*)number->pair->second;
        long lcm = (divider * divider1) / gcd(divider, divider1);
        if (function == 0) {
            *(long*)division->pair->first = (lcm / divider) * dividend + (lcm / divider1) * dividend1;
            *(long*)division->pair->second = lcm;
            reduce(division);
        }
        else {
            Division* result = (Division*)malloc(sizeof(Division));
            result->pair = createPair((void*)((lcm / divider) * dividend + (lcm / divider1) * dividend1), (void*)lcm);
            result->reduce = reduce;
            result->addWithoutReturn = addWithoutReturn;
            result->addWithReturn = addWithReturn;
            result->multiplyWithoutReturn = multiplyWithoutReturn;
            result->multiplyWithReturn = multiplyWithReturn;
            reduce(result);
            return result;
        }
    }
    else if (division->pair->first == (float*)division->pair->first && number->pair->first == (float*)number->pair->first) {
        float dividend = *(float*)division->pair->first;
        float divider = *(float*)division->pair->second;
        float dividend1 = *(float*)number->pair->first;
        float divider1 = *(float*)number->pair->second;
        float lcm = (divider * divider1) / gcd(divider, divider1);
        if (function == 0) {
            *(float*)division->pair->first = (lcm / divider) * dividend + (lcm / divider1) * dividend1;
            *(float*)division->pair->second = lcm;
            reduce(division);
        }
        else {
            Division* result = (Division*)malloc(sizeof(Division));
            result->pair = createPair((void*)((lcm / divider) * dividend + (lcm / divider1) * dividend1), (void*)lcm);
            result->reduce = reduce;
            result->addWithoutReturn = addWithoutReturn;
            result->addWithReturn = addWithReturn;
            result->multiplyWithoutReturn = multiplyWithoutReturn;
            result->multiplyWithReturn = multiplyWithReturn;
            reduce(result);
            return result;
        }
    }
    else if (division->pair->first == (double*)division->pair->first && number->pair->first == (double*)number->pair->first) {
        double dividend = *(double*)division->pair->first;
        double divider = *(double*)division->pair->second;
        double dividend1 = *(double*)number->pair->first;
        double divider1 = *(double*)number->pair->second;
        double lcm = (divider * divider1) / gcd(divider, divider1);
        if (function == 0) {
            *(double*)division->pair->first = (lcm / divider) * dividend + (lcm / divider1) * dividend1;
            *(double*)division->pair->second = lcm;
            reduce(division);
        }
        else {
            Division* result = (Division*)malloc(sizeof(Division));
            result->pair = createPair((void*)((lcm / divider) * dividend + (lcm / divider1) * dividend1), (void*)lcm);
            result->reduce = reduce;
            result->addWithoutReturn = addWithoutReturn;
            result->addWithReturn = addWithReturn;
            result->multiplyWithoutReturn = multiplyWithoutReturn;
            result->multiplyWithReturn = multiplyWithReturn;
            reduce(result);
            return result;
        }
    }
}

void multiply(Division* division, Division* number, int function) {
    if (division->pair->first == (int*)division->pair->first && number->pair->first == (int*)number->pair->first) {
        int first = *(int*)division->pair->first * *(int*)number->pair->first;
        int second = *(int*)division->pair->second * *(int*)number->pair->second;
        if (function == 0) {
            *(int*)division->pair->first = first;
            *(int*)division->pair->second = second;
            reduce(division);
        }
        else {
            Division* answer = (Division*)malloc(sizeof(Division));
            answer->pair = createPair((void*)first, (void*)second);
            answer->reduce = reduce;
            answer->addWithoutReturn = addWithoutReturn;
            answer->addWithReturn = addWithReturn;
            answer->multiplyWithoutReturn = multiplyWithoutReturn;
            answer->multiplyWithReturn = multiplyWithReturn;
            reduce(answer);
            return answer;
        }
    }
    else if (division->pair->first == (long*)division->pair->first && number->pair->first == (long*)number->pair->first) {
        long first = *(long*)division->pair->first * *(long*)number->pair->first;
        long second = *(long*)division->pair->second * *(long*)number->pair->second;
        if (function == 0) {
            *(long*)division->pair->first = first;
            *(long*)division->pair->second = second;
            reduce(division);
        }
        else {
            Division* answer = (Division*)malloc(sizeof(Division));
            answer->pair = createPair((void*)first, (void*)second);
            answer->reduce = reduce;
            answer->addWithoutReturn = addWithoutReturn;
            answer->addWithReturn = addWithReturn;
            answer->multiplyWithoutReturn = multiplyWithoutReturn;
            answer->multiplyWithReturn = multiplyWithReturn;
            reduce(answer);
            return answer;
        }
    }
    else if (division->pair->first == (float*)division->pair->first && number->pair->first == (float*)number->pair->first) {
        float first = *(float*)division->pair->first * *(float*)number->pair->first;
        float second = *(float*)division->pair->second * *(float*)number->pair->second;
        if (function == 0) {
            *(float*)division->pair->first = first;
            *(float*)division->pair->second = second;
            reduce(division);
        }
        else {
            Division* answer = (Division*)malloc(sizeof(Division));
            answer->pair = createPair((void*)first, (void*)second);
            answer->reduce = reduce;
            answer->addWithoutReturn = addWithoutReturn;
            answer->addWithReturn = addWithReturn;
            answer->multiplyWithoutReturn = multiplyWithoutReturn;
            answer->multiplyWithReturn = multiplyWithReturn;
            reduce(answer);
            return answer;
        }
    }
    else if (division->pair->first == (double*)division->pair->first && number->pair->first == (double*)number->pair->first) {
        double first = *(double*)division->pair->first * *(double*)number->pair->first;
        double second = *(double*)division->pair->second * *(double*)number->pair->second;
        if (function == 0) {
            *(double*)division->pair->first = first;
            *(double*)division->pair->second = second;
            reduce(division);
        }
        else {
            Division* answer = (Division*)malloc(sizeof(Division));
            answer->pair = createPair((void*)first, (void*)second);
            answer->reduce = reduce;
            answer->addWithoutReturn = addWithoutReturn;
            answer->addWithReturn = addWithReturn;
            answer->multiplyWithoutReturn = multiplyWithoutReturn;
            answer->multiplyWithReturn = multiplyWithReturn;
            reduce(answer);
            return answer;
        }
    }
}

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long gcd(long a, long b) {
    long temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

float gcd(float a, float b) {
    float temp;
    while (b != 0) {
        temp = fmod(a, b);
        a = b;
        b = temp;
    }
    return a;
}

double gcd(double a, double b) {
    double temp;
    while (b != 0) {
        temp = fmod(a, b);
        a = b;
        b = temp;
    }
    return a;
}

double lcm(double a, double b) {
    return (a / gcd(a, b)) * b;
}

float lcm(float a, float b) {
    return (a / gcd(a, b)) * b;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

long lcm(long a, long b) {
    return (a / gcd(a, b)) * b;
}

typedef struct Graph {
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
        graph->base[i] = (int*)malloc(quantity * sizeof(int));
    }
    for (int i = 0; i < quantity; i++) {
        int* input = value[i];
        graph->base[input[0] - 1][i * 2] = input[1] - 1;
        graph->base[input[1] - 1][i * 2] = input[0] - 1;
    }
    start(graph, length);
}

void adjacencyMatrixToDefault(Graph* graph, int length, int not, int** value) {
    graph->base = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        graph->base[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        int* inputArray = value[i];
        int buffer[length];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && inputArray[index] != not) {
                buffer[bufferIndex] = index;
                bufferIndex++;
            }
        }
        graph->base[i] = (int*)malloc(bufferIndex * sizeof(int));
        for (int index = 0; index < bufferIndex; index++) {
            graph->base[i][index] = buffer[index];
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
        }
        else {
            if (next != graph->ancestor[position]) {
                printf("Exception");
                return;
            }
        }
    }
}

int dijkstra(Graph* graph, int start, int stop, int size) {
    start--;
    stop--;
    int dist[size];
    for (int i = 0; i < size; i++) {
        if (i != start) {
            dist[i] = INT_MAX;
        }
        graph->ancestor[i] = start;
    }
    int queue[size][2];
    int queueSize = 0;
    queue[queueSize][0] = start;
    queue[queueSize][1] = 0;
    queueSize++;
    int position;
    int getQueue[2];
    while (queueSize != 0) {
        int min = INT_MAX;
        int minIndex = 0;
        for (int i = 0; i < queueSize; i++) {
            if (queue[i][1] < min) {
                min = queue[i][1];
                minIndex = i;
            }
        }
        getQueue[0] = queue[minIndex][0];
        getQueue[1] = queue[minIndex][1];
        for (int i = minIndex; i < queueSize - 1; i++) {
            queue[i][0] = queue[i + 1][0];
            queue[i][1] = queue[i + 1][1];
        }
        queueSize--;
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
                }
                else {
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

typedef struct FastSort {
    void (*sortWithoutReturn)();
    int* (*sortWithReturn)();
    void (*ShellSort)();
    void (*HeapSort)();
    void (*MergeSort)();
    void (*straightMergeSort)();
    void (*insertionSort)();
} FastSort;

void sortWithoutReturn(int* array, int length, int ShellHeapMergeMyInsertionSort) {
    sort(array, ShellHeapMergeMyInsertionSort, length);
}

int* sortWithReturn(int* array, int length, int ShellHeapMergeMyInsertionSort) {
    int* base = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        base[i] = array[i];
    }
    sort(base, ShellHeapMergeMyInsertionSort, length);
    return base;
}

void sort(int* array, int ShellHeapMergeMyInsertionSort, int length) {
    if (ShellHeapMergeMyInsertionSort < 0 || ShellHeapMergeMyInsertionSort > 4) {
        srand(time(NULL));
        ShellHeapMergeMyInsertionSort = rand() % 4;
    }
    if (ShellHeapMergeMyInsertionSort == 0) {
        ShellSort(array);
    }
    else if (ShellHeapMergeMyInsertionSort == 1) {
        HeapSort(array);
    }
    else if (ShellHeapMergeMyInsertionSort == 2) {
        MergeSort(array, 0, length - 1);
    }
    else if (ShellHeapMergeMyInsertionSort == 3) {
        straightMergeSort(array, length);
    }
    else if (ShellHeapMergeMyInsertionSort == 4) {
        insertionSort(array);
    }
}

void ShellSort(int* array) {
    int j;
    for (int gap = sizeof(array) / sizeof(int) / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < sizeof(array) / sizeof(int); i++) {
            int temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void HeapSort(int* array) {
    for (int i = sizeof(array) / sizeof(int) / 2 - 1; i >= 0; i--) {
        shiftDown(array, i, sizeof(array) / sizeof(int));
    }
    for (int i = sizeof(array) / sizeof(int) - 1; i > 0; i--) {
        swap(array, 0, i);
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
        }
        else {
            break;
        }
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
        if (i > mid) {
            Temp[k++] = array[j++];
        }
        else if (j > high) {
            Temp[k++] = array[i++];
        }
        else if (array[i] < array[j]) {
            Temp[k++] = array[i++];
        }
        else {
            Temp[k++] = array[j++];
        }
    }
    for (j = 0; j < n; j++) {
        array[low + j] = Temp[j];
    }
}

void straightMergeSort(int* array, int size) {
    if (size == 0) {
        return;
    }
    int length = size / 2 + (size % 2 == 0 ? 0 : 1);
    int** ZeroBuffer = (int**)malloc((length + length % 2) * sizeof(int*));
    int** FirstBuffer = (int**)malloc(0);
    for (int index = 0; index < length; index++) {
        int ArrayIndex = index * 2;
        int NextArrayIndex = index * 2 + 1;
        if (NextArrayIndex < size) {
            ZeroBuffer[index] = (int*)malloc(2 * sizeof(int));
            if (array[ArrayIndex] > array[NextArrayIndex]) {
                ZeroBuffer[index][0] = array[NextArrayIndex];
                ZeroBuffer[index][1] = array[ArrayIndex];
            }
            else {
                ZeroBuffer[index][0] = array[ArrayIndex];
                ZeroBuffer[index][1] = array[NextArrayIndex];
            }
        }
        else {
            ZeroBuffer[index] = (int*)malloc(sizeof(int));
            ZeroBuffer[index][0] = array[ArrayIndex];
        }
    }
    int position = 0;
    int pointer0, pointer, pointer1, number = 4, NewPointer, count;
    int** NewBuffer;
    int** OldBuffer;
    length = size / 4 + (size % 4 == 0 ? 0 : 1);
    while (1) {
        pointer0 = 0;
        count = number / 2 - 1;
        if (!position) {
            FirstBuffer = (int**)malloc((length + length % 2) * sizeof(int*));
            NewBuffer = FirstBuffer;
            OldBuffer = ZeroBuffer;
        }
        else {
            ZeroBuffer = (int**)malloc((length + length % 2) * sizeof(int*));
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
                    }
                    else if (pointer1 > count || OldBuffer[NewPointer][pointer1] == NULL) {
                        if (OldBuffer[pointer0][pointer] == NULL) {
                            continue;
                        }
                        array[g] = OldBuffer[pointer0][pointer];
                        pointer++;
                    }
                    else if (OldBuffer[pointer0][pointer] >= OldBuffer[NewPointer][pointer1]) {
                        array[g] = OldBuffer[NewPointer][pointer1];
                        pointer1++;
                    }
                    else {
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
                }
                else if (pointer1 > count || OldBuffer[NewPointer][pointer1] == NULL) {
                    if (OldBuffer[pointer0][pointer] == NULL) {
                        continue;
                    }
                    NewBuffer[i][g] = OldBuffer[pointer0][pointer];
                    pointer++;
                }
                else if (OldBuffer[pointer0][pointer] >= OldBuffer[NewPointer][pointer1]) {
                    NewBuffer[i][g] = OldBuffer[NewPointer][pointer1];
                    pointer1++;
                }
                else {
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

void insertionSort(int* elements) {
    for (int i = 1; i < sizeof(elements) / sizeof(int); i++) {
        int key = elements[i];
        int j = i - 1;
        while (j >= 0 && key < elements[j]) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
}

typedef struct IO {
    int (*readInt)();
    long (*readLong)();
    char* (*readString)();
    int* (*readArrayInt)();
    long* (*readArrayLong)();
    char** (*readArrayString)();
    void (*writeArray)();
    void (*writeInt)();
    void (*writeLong)();
    void (*writeString)();
    void (*writeBoolean)();
    void (*writeChar)();
    void (*writeEnter)();
    void (*print)();
} IO;

int readInt() {
    int number;
    scanf("%d", &number);
    return number;
}

long readLong() {
    long number;
    scanf("%ld", &number);
    return number;
}

char* readString() {
    char* word = (char*)malloc(100 * sizeof(char));
    scanf("%s", word);
    return word;
}

int* readArrayInt() {
    int* array = (int*)malloc(100 * sizeof(int));
    int index = 0;
    int number;
    while (scanf("%d", &number) == 1) {
        array[index] = number;
        index++;
    }
    return array;
}

long* readArrayLong() {
    long* array = (long*)malloc(100 * sizeof(long));
    int index = 0;
    long number;
    while (scanf("%ld", &number) == 1) {
        array[index] = number;
        index++;
    }
    return array;
}

char** readArrayString() {
    char** array = (char**)malloc(100 * sizeof(char*));
    int index = 0;
    char* word = (char*)malloc(100 * sizeof(char));
    while (scanf("%s", word) == 1) {
        array[index] = word;
        index++;
    }
    return array;
}

void writeArray(int* array, char* split, int enter) {
    int index = 0;
    while (array[index] != NULL) {
        printf("%d", array[index]);
        if (array[index + 1] != NULL) {
            printf("%s", split);
        }
        index++;
    }
    if (enter) {
        printf("\n");
    }
}

void writeInt(int number, char* end) {
    printf("%d%s", number, end);
}

void writeLong(long number, char* end) {
    printf("%ld%s", number, end);
}

void writeString(char* word, char* end) {
    printf("%s%s", word, end);
}

void writeBoolean(int value, char* end) {
    printf("%s%s", value ? "true" : "false", end);
}

void writeChar(char word, char* end) {
    printf("%c%s", word, end);
}

void writeEnter() {
    printf("\n");
}

void print() {
    return;
}

int main() {
    int i1 = readInt();
    int** countValue = (int**)malloc(i1 * sizeof(int*));
    for (int i2 = 0; i2 < i1; i2++) {
        countValue[i2] = (int*)calloc(100, sizeof(int));
        int* quantity = readArrayInt(" ");
        int* base = readArrayInt(" ");
        for (int i = 0; i < quantity[2]; i++) {
            countValue[i2][base[i]]++;
        }
        int min = 0;
        for (int i = quantity[2]; i < quantity[0]; i++) {
            countValue[i2][base[i - quantity[2]]]--;
            countValue[i2][base[i]]++;
            int count = 0;
            for (int j = 0; j < 100; j++) {
                if (countValue[i2][j] > 0) {
                    count++;
                }
            }
            if (count < min || min == 0) {
                min = count;
            }
        }
        writeInt(min, "\n");
    }
    print();
    return 0;
}
