#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long gcd_long(long a, long b) {
    if (b == 0) {
        return a;
    }
    return gcd_long(b, a % b);
}

float gcd_float(float a, float b) {
    if (b == 0) {
        return a;
    }
    return gcd_float(b, fmod(a, b));
}

double gcd_double(double a, double b) {
    if (b == 0) {
        return a;
    }
    return gcd_double(b, fmod(a, b));
}

double lcm_double(double a, double b) {
    return a / gcd_double(a, b) * b;
}

float lcm_float(float a, float b) {
    return a / gcd_float(a, b) * b;
}

int lcm_int(int a, int b) {
    return a / gcd(a, b) * b;
}

long lcm_long(long a, long b) {
    return a / gcd_long(a, b) * b;
}

double logarithm(double value, int base) {
    return log(value) / log(base);
}

long factorial(int number) {
    if (number < 0) {
        return 0;
    }
    if (number == 0) {
        return 1;
    }
    return factorial(number - 1) * number;
}

typedef struct {
    int value;
} Int;

int compareInt(const void* a, const void* b) {
    return (*(Int*)a).value - (*(Int*)b).value;
}

typedef struct {
    void* dividend;
    void* divider;
} Fraction;

Fraction* createFraction(void* dividend, void* divider) {
    Fraction* fraction = (Fraction*)malloc(sizeof(Fraction));
    fraction->dividend = dividend;
    fraction->divider = divider;
    return fraction;
}

void reduce(Fraction* fraction, char type) {
    if (type == 'i') {
        int* dividend = (int*)fraction->dividend;
        int* divider = (int*)fraction->divider;
        int gcd_value = gcd(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    } else if (type == 'l') {
        long* dividend = (long*)fraction->dividend;
        long* divider = (long*)fraction->divider;
        long gcd_value = gcd_long(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    } else if (type == 'f') {
        float* dividend = (float*)fraction->dividend;
        float* divider = (float*)fraction->divider;
        float gcd_value = gcd_float(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    } else if (type == 'd') {
        double* dividend = (double*)fraction->dividend;
        double* divider = (double*)fraction->divider;
        double gcd_value = gcd_double(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    }
}

void addWithoutReturn(Fraction* fraction, Fraction* number, char type) {
    if (type == 'i') {
        int* dividend = (int*)fraction->dividend;
        int* divider = (int*)fraction->divider;
        int* dividend1 = (int*)number->dividend;
        int* divider1 = (int*)number->divider;
        int lcm_value = lcm_int(*divider, *divider1);
        *dividend = (lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1;
        *divider = lcm_value;
        reduce(fraction, type);
    } else if (type == 'l') {
        long* dividend = (long*)fraction->dividend;
        long* divider = (long*)fraction->divider;
        long* dividend1 = (long*)number->dividend;
        long* divider1 = (long*)number->divider;
        long lcm_value = lcm_long(*divider, *divider1);
        *dividend = (lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1;
        *divider = lcm_value;
        reduce(fraction, type);
    } else if (type == 'f') {
        float* dividend = (float*)fraction->dividend;
        float* divider = (float*)fraction->divider;
        float* dividend1 = (float*)number->dividend;
        float* divider1 = (float*)number->divider;
        float lcm_value = lcm_float(*divider, *divider1);
        *dividend = (lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1;
        *divider = lcm_value;
        reduce(fraction, type);
    } else if (type == 'd') {
        double* dividend = (double*)fraction->dividend;
        double* divider = (double*)fraction->divider;
        double* dividend1 = (double*)number->dividend;
        double* divider1 = (double*)number->divider;
        double lcm_value = lcm_double(*divider, *divider1);
        *dividend = (lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1;
        *divider = lcm_value;
        reduce(fraction, type);
    }
}

Fraction* addWithReturn(Fraction* fraction, Fraction* number, char type) {
    Fraction* result = createFraction(fraction->dividend, fraction->divider);
    addWithoutReturn(result, number, type);
    return result;
}

void multiplyWithoutReturn(Fraction* fraction, Fraction* number, char type) {
    if (type == 'i') {
        int* dividend = (int*)fraction->dividend;
        int* divider = (int*)fraction->divider;
        int* dividend1 = (int*)number->dividend;
        int* divider1 = (int*)number->divider;
        *dividend = *dividend * *dividend1;
        *divider = *divider * *divider1;
        reduce(fraction, type);
    } else if (type == 'l') {
        long* dividend = (long*)fraction->dividend;
        long* divider = (long*)fraction->divider;
        long* dividend1 = (long*)number->dividend;
        long* divider1 = (long*)number->divider;
        *dividend = *dividend * *dividend1;
        *divider = *divider * *divider1;
        reduce(fraction, type);
    } else if (type == 'f') {
        float* dividend = (float*)fraction->dividend;
        float* divider = (float*)fraction->divider;
        float* dividend1 = (float*)number->dividend;
        float* divider1 = (float*)number->divider;
        *dividend = *dividend * *dividend1;
        *divider = *divider * *divider1;
        reduce(fraction, type);
    } else if (type == 'd') {
        double* dividend = (double*)fraction->dividend;
        double* divider = (double*)fraction->divider;
        double* dividend1 = (double*)number->dividend;
        double* divider1 = (double*)number->divider;
        *dividend = *dividend * *dividend1;
        *divider = *divider * *divider1;
        reduce(fraction, type);
    }
}

Fraction* multiplyWithReturn(Fraction* fraction, Fraction* number, char type) {
    Fraction* result = createFraction(fraction->dividend, fraction->divider);
    multiplyWithoutReturn(result, number, type);
    return result;
}

typedef struct {
    int first;
    int second;
} Pair;

Pair* createPair(int first, int second) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->first = first;
    pair->second = second;
    return pair;
}

int comparePair(const void* a, const void* b) {
    return (*(Pair*)a).first - (*(Pair*)b).first;
}

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
    for (int i = 0; i < length; i++) {
        graph->ancestor[i] = -1;
    }
    graph->quantity = 0;
}

void edgesMatrixToDefault(Graph* graph, int length, int quantity, int** value) {
    graph->base = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        graph->base[i] = (int*)malloc(quantity * sizeof(int));
    }
    int** inputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        inputBase[i] = (int*)malloc(quantity * sizeof(int));
    }
    for (int i = 0; i < quantity; i++) {
        int* input = value[i];
        inputBase[input[0] - 1][i] = input[1] - 1;
        inputBase[input[1] - 1][i] = input[0] - 1;
    }
    for (int i = 0; i < length; i++) {
        int count = 0;
        for (int j = 0; j < quantity; j++) {
            if (inputBase[i][j] != -1) {
                graph->base[i][count++] = inputBase[i][j];
            }
        }
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
        int count = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && inputArray[index] != not) {
                graph->base[i][count++] = index;
            }
        }
    }
    start(graph, length);
}

void dfs(Graph* graph, int position) {
    graph->used[position] = 1;
    graph->quantity++;
    int next;
    for (int index = 0; index < sizeof(graph->base[position]) / sizeof(graph->base[position][0]); index++) {
        next = graph->base[position][index];
        if (!graph->used[next]) {
            graph->ancestor[next] = position;
            dfs(graph, next);
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
        for (int index = 0; index < sizeof(graph->base[position]) / sizeof(graph->base[position][0]); index += 2) {
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

int solveFloydWarshall(int** base, int length, int not) {
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

typedef struct {
    int first;
    int second;
} Pair;

Pair* solveKruskal(int** edgesMatrix, int countVertex, int indexSort) {
    Pair* answer = (Pair*)malloc((countVertex - 1) * sizeof(Pair));
    long sum = 0;
    qsort(edgesMatrix, countVertex, sizeof(edgesMatrix[0]), comparePair);
    int* dsu = (int*)malloc(countVertex * sizeof(int));
    for (int i = 0; i < countVertex; i++) {
        dsu[i] = i;
    }
    int index = 0;
    for (int i = 0; i < countVertex; i++) {
        int* value = edgesMatrix[i];
        int first = value[0];
        int second = value[1];
        if (dsu[first] != dsu[second]) {
            sum += value[indexSort];
            answer[index].first = first;
            answer[index].second = second;
            index++;
            int old = dsu[second];
            for (int j = 0; j < countVertex; j++) {
                if (dsu[j] == old) {
                    dsu[j] = dsu[first];
                }
            }
        }
    }
    if (index < countVertex - 1) {
        return NULL;
    }
    return answer;
}

typedef struct {
    int* segmentArray;
    int (*function)(int, int);
} SegmentTree;

SegmentTree* createSegmentTree() {
    SegmentTree* segmentTree = (SegmentTree*)malloc(sizeof(SegmentTree));
    segmentTree->segmentArray = NULL;
    segmentTree->function = NULL;
    return segmentTree;
}

void setSegmentArray(SegmentTree* segmentTree, int* segmentArray) {
    segmentTree->segmentArray = segmentArray;
}

void setFunction(SegmentTree* segmentTree, int (*function)(int, int)) {
    segmentTree->function = function;
}

int getValue(SegmentTree* segmentTree, int left, int right, int neutral) {
    return findValue(segmentTree, 1, 0, ((sizeof(segmentTree->segmentArray) / sizeof(segmentTree->segmentArray[0])) >> 1) - 1, left, right, neutral);
}

int findValue(SegmentTree* segmentTree, int position, int low, int high, int left, int right, int neutral) {
    if (left > right) {
        return neutral;
    }
    if (left == low && right == high) {
        return segmentTree->segmentArray[position];
    }
    int mid = (low + high) >> 1;
    return segmentTree->function(findValue(segmentTree, position << 1, low, mid, left, mid < right ? mid : right, neutral),
                                 findValue(segmentTree, (position << 1) + 1, mid + 1, high, mid < right ? mid + 1 : left, right, neutral));
}

void replaceValue(SegmentTree* segmentTree, int index, int value) {
    update(segmentTree, 1, 0, (sizeof(segmentTree->segmentArray) / sizeof(segmentTree->segmentArray[0])) >> 1, index, value);
}

void update(SegmentTree* segmentTree, int position, int low, int high, int index, int value) {
    if (low == high) {
        segmentTree->segmentArray[position] = value;
    } else {
        int mid = (low + high) >> 1;
        if (index <= mid) {
            update(segmentTree, position << 1, low, mid, index, value);
        } else {
            update(segmentTree, (position << 1) + 1, mid + 1, high, index, value);
        }
        segmentTree->segmentArray[position] = segmentTree->function(segmentTree->segmentArray[position << 1], segmentTree->segmentArray[(position << 1) + 1]);
    }
}

typedef struct {
    void* segmentArray;
    void* (*function)(void*, void*);
} SegmentTreeGeneric;

SegmentTreeGeneric* createSegmentTreeGeneric() {
    SegmentTreeGeneric* segmentTreeGeneric = (SegmentTreeGeneric*)malloc(sizeof(SegmentTreeGeneric));
    segmentTreeGeneric->segmentArray = NULL;
    segmentTreeGeneric->function = NULL;
    return segmentTreeGeneric;
}

void setSegmentArrayGeneric(SegmentTreeGeneric* segmentTreeGeneric, void* segmentArray) {
    segmentTreeGeneric->segmentArray = segmentArray;
}

void setFunctionGeneric(SegmentTreeGeneric* segmentTreeGeneric, void* (*function)(void*, void*)) {
    segmentTreeGeneric->function = function;
}

void* getValueGeneric(SegmentTreeGeneric* segmentTreeGeneric, int left, int right, void* neutral) {
    return findValueGeneric(segmentTreeGeneric, 1, 0, ((sizeof(segmentTreeGeneric->segmentArray) / sizeof(segmentTreeGeneric->segmentArray[0])) >> 1) - 1, left, right, neutral);
}

void* findValueGeneric(SegmentTreeGeneric* segmentTreeGeneric, int position, int low, int high, int left, int right, void* neutral) {
    if (left > right) {
        return neutral;
    }
    if (left == low && right == high) {
        return segmentTreeGeneric->segmentArray[position];
    }
    int mid = (low + high) >> 1;
    return segmentTreeGeneric->function(findValueGeneric(segmentTreeGeneric, position << 1, low, mid, left, mid < right ? mid : right, neutral),
                                        findValueGeneric(segmentTreeGeneric, (position << 1) + 1, mid + 1, high, mid < right ? mid + 1 : left, right, neutral));
}

void replaceValueGeneric(SegmentTreeGeneric* segmentTreeGeneric, int index, void* value) {
    updateGeneric(segmentTreeGeneric, 1, 0, (sizeof(segmentTreeGeneric->segmentArray) / sizeof(segmentTreeGeneric->segmentArray[0])) >> 1, index, value);
}

void updateGeneric(SegmentTreeGeneric* segmentTreeGeneric, int position, int low, int high, int index, void* value) {
    if (low == high) {
        segmentTreeGeneric->segmentArray[position] = value;
    } else {
        int mid = (low + high) >> 1;
        if (index <= mid) {
            updateGeneric(segmentTreeGeneric, position << 1, low, mid, index, value);
        } else {
            updateGeneric(segmentTreeGeneric, (position << 1) + 1, mid + 1, high, index, value);
        }
        segmentTreeGeneric->segmentArray[position] = segmentTreeGeneric->function(segmentTreeGeneric->segmentArray[position << 1], segmentTreeGeneric->segmentArray[(position << 1) + 1]);
    }
}

void solveFastSort(int* array, int ShellHeapMergeMyInsertionSort, int length) {
    if (ShellHeapMergeMyInsertionSort < 0 || ShellHeapMergeMyInsertionSort > 4) {
        ShellHeapMergeMyInsertionSort = rand() % 4;
    }
    if (ShellHeapMergeMyInsertionSort == 0) {
        solveShellSort(array, length);
    } else if (ShellHeapMergeMyInsertionSort == 1) {
        solveHeapSort(array, length);
    } else if (ShellHeapMergeMyInsertionSort == 2) {
        solveMergeSort(array, 0, length - 1);
    } else if (ShellHeapMergeMyInsertionSort == 3) {
        solveStraightMergeSort(array, length);
    } else if (ShellHeapMergeMyInsertionSort == 4) {
        solveInsertionSort(array, length);
    }
}

void solveShellSort(int* array, int length) {
    int j;
    for (int gap = (length >> 1); gap > 0; gap >>= 1) {
        for (int i = gap; i < length; i++) {
            int temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void solveHeapSort(int* array, int length) {
    for (int i = (length >> 1) - 1; i >= 0; i--)
        solveShiftDown(array, i, length);
    for (int i = length - 1; i > 0; i--) {
        solveSwap(array, 0, i);
        solveShiftDown(array, 0, i);
    }
}

void solveShiftDown(int* array, int i, int n) {
    int child;
    int tmp;
    for (tmp = array[i]; solveLeftChild(i) < n; i = child) {
        child = solveLeftChild(i);
        if (child != n - 1 && (array[child] < array[child + 1]))
            child++;
        if (tmp < array[child])
            array[i] = array[child];
        else
            break;
    }
    array[i] = tmp;
}

int solveLeftChild(int i) {
    return (i << 1) + 1;
}

void solveSwap(int* array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void solveMergeSort(int* array, int low, int high) {
    if (low < high) {
        int mid = (low + high) >> 1;
        solveMergeSort(array, low, mid);
        solveMergeSort(array, mid + 1, high);
        solveMerge(array, low, mid, high);
    }
}

void solveMerge(int* array, int low, int mid, int high) {
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

void solveStraightMergeSort(int* array, int size) {
    if (size == 0) {
        return;
    }
    int length = (size >> 1) + ((size % 2) == 0 ? 0 : 1);
    int** ZeroBuffer = (int**)malloc(length * sizeof(int*));
    int** FirstBuffer = (int**)malloc(0 * sizeof(int*));
    for (int index = 0; index < length; index++) {
        int ArrayIndex = index << 1;
        int NextArrayIndex = (index << 1) + 1;
        if (NextArrayIndex < size) {
            ZeroBuffer[index][0] = array[NextArrayIndex];
            ZeroBuffer[index][1] = array[ArrayIndex];
        } else {
            ZeroBuffer[index][0] = array[ArrayIndex];
        }
    }
    int position = 0;
    int pointer0, pointer, pointer1, number = 4, NewPointer, count;
    int** NewBuffer;
    int** OldBuffer;
    length = (size >> 2) + ((size % 4) == 0 ? 0 : 1);
    while (1) {
        pointer0 = 0;
        count = (number >> 1) - 1;
        if (!position) {
            FirstBuffer = (int**)malloc(length * sizeof(int*));
            NewBuffer = FirstBuffer;
            OldBuffer = ZeroBuffer;
        } else {
            ZeroBuffer = (int**)malloc(length * sizeof(int*));
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
        length = (length >> 1) + length % 2;
        number <<= 1;
    }
}

void solveInsertionSort(int* elements, int length) {
    for (int i = 1; i < length; i++) {
        int key = elements[i];
        int j = i - 1;
        while (j >= 0 && key < elements[j]) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
}

int main() {
    int g, sh, j, p, priceFirst, priceSecond;
    long answer = 0;
    scanf("%d%d%d%d%d%d", &g, &sh, &j, &p, &priceFirst, &priceSecond);
    if (priceFirst <= priceSecond) {
        answer = fmin(fmin(sh, j), p);
        p -= answer;
        answer *= priceSecond;
        answer += (fmin(p, g) * priceFirst);
    } else {
        answer = fmin(g, p);
        p -= answer;
        answer *= priceFirst;
        answer += (fmin(fmin(sh, j), p) * priceSecond);
    }
    printf("%ld\n", answer);
    return 0;
}
