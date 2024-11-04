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

double log_base(double value, int base) {
    return log(value) / log(base);
}

long factorial(int number) {
    if (number < 0) {
        return 0;
    }
    long result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

typedef struct {
    int value;
} Int;

int compare_int(const void* a, const void* b) {
    const Int* int_a = (const Int*)a;
    const Int* int_b = (const Int*)b;
    return int_a->value - int_b->value;
}

typedef struct {
    void* dividend;
    void* divider;
} Fraction;

Fraction* create_fraction(void* dividend, void* divider) {
    Fraction* fraction = malloc(sizeof(Fraction));
    fraction->dividend = dividend;
    fraction->divider = divider;
    return fraction;
}

void reduce_fraction(Fraction* fraction, int type) {
    if (type == 0) {
        int* dividend = (int*)fraction->dividend;
        int* divider = (int*)fraction->divider;
        int gcd_value = gcd(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    } else if (type == 1) {
        long* dividend = (long*)fraction->dividend;
        long* divider = (long*)fraction->divider;
        long gcd_value = gcd_long(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    } else if (type == 2) {
        float* dividend = (float*)fraction->dividend;
        float* divider = (float*)fraction->divider;
        float gcd_value = gcd_float(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    } else if (type == 3) {
        double* dividend = (double*)fraction->dividend;
        double* divider = (double*)fraction->divider;
        double gcd_value = gcd_double(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    }
}

void add_fraction(Fraction* fraction, Fraction* number, int function, int type) {
    if (type == 0) {
        int* dividend = (int*)fraction->dividend;
        int* divider = (int*)fraction->divider;
        int* dividend1 = (int*)number->dividend;
        int* divider1 = (int*)number->divider;
        int lcm_value = lcm_int(*divider, *divider1);
        if (function == 0) {
            *dividend = (lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1;
            *divider = lcm_value;
            reduce_fraction(fraction, type);
        } else {
            Fraction* result = create_fraction((lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1, lcm_value);
            reduce_fraction(result, type);
            fraction->dividend = result->dividend;
            fraction->divider = result->divider;
            free(result);
        }
    } else if (type == 1) {
        long* dividend = (long*)fraction->dividend;
        long* divider = (long*)fraction->divider;
        long* dividend1 = (long*)number->dividend;
        long* divider1 = (long*)number->divider;
        long lcm_value = lcm_long(*divider, *divider1);
        if (function == 0) {
            *dividend = (lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1;
            *divider = lcm_value;
            reduce_fraction(fraction, type);
        } else {
            Fraction* result = create_fraction((lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1, lcm_value);
            reduce_fraction(result, type);
            fraction->dividend = result->dividend;
            fraction->divider = result->divider;
            free(result);
        }
    } else if (type == 2) {
        float* dividend = (float*)fraction->dividend;
        float* divider = (float*)fraction->divider;
        float* dividend1 = (float*)number->dividend;
        float* divider1 = (float*)number->divider;
        float lcm_value = lcm_float(*divider, *divider1);
        if (function == 0) {
            *dividend = (lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1;
            *divider = lcm_value;
            reduce_fraction(fraction, type);
        } else {
            Fraction* result = create_fraction((lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1, lcm_value);
            reduce_fraction(result, type);
            fraction->dividend = result->dividend;
            fraction->divider = result->divider;
            free(result);
        }
    } else if (type == 3) {
        double* dividend = (double*)fraction->dividend;
        double* divider = (double*)fraction->divider;
        double* dividend1 = (double*)number->dividend;
        double* divider1 = (double*)number->divider;
        double lcm_value = lcm_double(*divider, *divider1);
        if (function == 0) {
            *dividend = (lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1;
            *divider = lcm_value;
            reduce_fraction(fraction, type);
        } else {
            Fraction* result = create_fraction((lcm_value / *divider) * *dividend + (lcm_value / *divider1) * *dividend1, lcm_value);
            reduce_fraction(result, type);
            fraction->dividend = result->dividend;
            fraction->divider = result->divider;
            free(result);
        }
    }
}

Fraction* subtract_fraction(Fraction* fraction, Fraction* number, int type) {
    if (type == 0) {
        int* dividend = (int*)fraction->dividend;
        int* divider = (int*)fraction->divider;
        int* dividend1 = (int*)number->dividend;
        int* divider1 = (int*)number->divider;
        int lcm_value = lcm_int(*divider, *divider1);
        Fraction* result = create_fraction((lcm_value / *divider) * *dividend - (lcm_value / *divider1) * *dividend1, lcm_value);
        reduce_fraction(result, type);
        return result;
    } else if (type == 1) {
        long* dividend = (long*)fraction->dividend;
        long* divider = (long*)fraction->divider;
        long* dividend1 = (long*)number->dividend;
        long* divider1 = (long*)number->divider;
        long lcm_value = lcm_long(*divider, *divider1);
        Fraction* result = create_fraction((lcm_value / *divider) * *dividend - (lcm_value / *divider1) * *dividend1, lcm_value);
        reduce_fraction(result, type);
        return result;
    } else if (type == 2) {
        float* dividend = (float*)fraction->dividend;
        float* divider = (float*)fraction->divider;
        float* dividend1 = (float*)number->dividend;
        float* divider1 = (float*)number->divider;
        float lcm_value = lcm_float(*divider, *divider1);
        Fraction* result = create_fraction((lcm_value / *divider) * *dividend - (lcm_value / *divider1) * *dividend1, lcm_value);
        reduce_fraction(result, type);
        return result;
    } else if (type == 3) {
        double* dividend = (double*)fraction->dividend;
        double* divider = (double*)fraction->divider;
        double* dividend1 = (double*)number->dividend;
        double* divider1 = (double*)number->divider;
        double lcm_value = lcm_double(*divider, *divider1);
        Fraction* result = create_fraction((lcm_value / *divider) * *dividend - (lcm_value / *divider1) * *dividend1, lcm_value);
        reduce_fraction(result, type);
        return result;
    }
    return NULL;
}

Fraction* multiply_fraction(Fraction* fraction, Fraction* number, int function, int type) {
    if (type == 0) {
        int* dividend = (int*)fraction->dividend;
        int* divider = (int*)fraction->divider;
        int* dividend1 = (int*)number->dividend;
        int* divider1 = (int*)number->divider;
        int first = *dividend * *dividend1;
        int second = *divider * *divider1;
        if (function == 0) {
            *dividend = first;
            *divider = second;
            reduce_fraction(fraction, type);
        } else {
            Fraction* result = create_fraction(first, second);
            reduce_fraction(result, type);
            return result;
        }
    } else if (type == 1) {
        long* dividend = (long*)fraction->dividend;
        long* divider = (long*)fraction->divider;
        long* dividend1 = (long*)number->dividend;
        long* divider1 = (long*)number->divider;
        long first = *dividend * *dividend1;
        long second = *divider * *divider1;
        if (function == 0) {
            *dividend = first;
            *divider = second;
            reduce_fraction(fraction, type);
        } else {
            Fraction* result = create_fraction(first, second);
            reduce_fraction(result, type);
            return result;
        }
    } else if (type == 2) {
        float* dividend = (float*)fraction->dividend;
        float* divider = (float*)fraction->divider;
        float* dividend1 = (float*)number->dividend;
        float* divider1 = (float*)number->divider;
        float first = *dividend * *dividend1;
        float second = *divider * *divider1;
        if (function == 0) {
            *dividend = first;
            *divider = second;
            reduce_fraction(fraction, type);
        } else {
            Fraction* result = create_fraction(first, second);
            reduce_fraction(result, type);
            return result;
        }
    } else if (type == 3) {
        double* dividend = (double*)fraction->dividend;
        double* divider = (double*)fraction->divider;
        double* dividend1 = (double*)number->dividend;
        double* divider1 = (double*)number->divider;
        double first = *dividend * *dividend1;
        double second = *divider * *divider1;
        if (function == 0) {
            *dividend = first;
            *divider = second;
            reduce_fraction(fraction, type);
        } else {
            Fraction* result = create_fraction(first, second);
            reduce_fraction(result, type);
            return result;
        }
    }
    return NULL;
}

typedef struct {
    int** base;
    int* used;
    int quantity;
    int* ancestor;
} Graph;

Graph* create_graph() {
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
    for (int i = 0; i < length; i++) {
        graph->used[i] = 0;
        graph->ancestor[i] = -1;
    }
    graph->quantity = 0;
}

void id22(Graph* graph, int length, int quantity, int readConsole, int** value) {
    graph->base = malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        graph->base[i] = malloc(quantity * sizeof(int));
    }
    for (int i = 0; i < quantity; i++) {
        int* input = readConsole ? id9(" ") : value[i];
        graph->base[input[0] - 1][i] = input[1] - 1;
        graph->base[input[1] - 1][i] = input[0] - 1;
    }
    start(graph, length);
}

void id11(Graph* graph, int length, int not, int readConsole, int** value) {
    graph->base = malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        graph->base[i] = malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        int* input = readConsole ? id9(" ") : value[i];
        int buffer[length];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && input[index] != not) {
                buffer[bufferIndex++] = index;
            }
        }
        for (int index = 0; index < bufferIndex; index++) {
            graph->base[i][index] = buffer[index];
        }
        start(graph, length);
    }
}

void dfs(Graph* graph, int position) {
    graph->used[position] = 1;
    graph->quantity++;
    int next;
    for (int index = 0; index < sizeof(graph->base[position]) / sizeof(int); index++) {
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
        int minIndex = 0;
        int minValue = INT_MAX;
        for (int i = 0; i < queueSize; i++) {
            if (queue[i][1] < minValue) {
                minValue = queue[i][1];
                minIndex = i;
            }
        }
        getQueue[0] = queue[minIndex][0];
        getQueue[1] = queue[minIndex][1];
        queue[minIndex][0] = queue[queueSize - 1][0];
        queue[minIndex][1] = queue[queueSize - 1][1];
        queueSize--;
        if (getQueue[1] > dist[getQueue[0]]) {
            continue;
        }
        for (int index = 0; index < sizeof(graph->base[getQueue[0]]) / sizeof(int); index += 2) {
            if (dist[getQueue[0]] + graph->base[getQueue[0]][index + 1] < dist[graph->base[getQueue[0]][index]] && !graph->used[graph->base[getQueue[0]][index]]) {
                dist[graph->base[getQueue[0]][index]] = dist[getQueue[0]] + graph->base[getQueue[0]][index + 1];
                graph->ancestor[graph->base[getQueue[0]][index]] = getQueue[0];
                queue[queueSize][0] = graph->base[getQueue[0]][index];
                queue[queueSize][1] = dist[graph->base[getQueue[0]][index]];
                queueSize++;
            }
        }
        graph->used[getQueue[0]] = 1;
    }
    return dist[stop] == INT_MAX ? -1 : dist[stop];
}

int id0(int** base, int length, int not) {
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
    long sum;
    int** answer;
} Pair;

Pair* id16(int** edgesMatrix, int countVertex, int indexSort) {
    int** answer = malloc((countVertex - 1) * sizeof(int*));
    for (int i = 0; i < countVertex - 1; i++) {
        answer[i] = malloc(2 * sizeof(int));
    }
    long sum = 0;
    qsort(edgesMatrix, countVertex, sizeof(int*), compare_int);
    int index = 0;
    for (int i = 0; i < countVertex; i++) {
        make_set(i);
    }
    for (int i = 0; i < countVertex; i++) {
        int* value = edgesMatrix[i];
        if (merge_sets(value[0], value[1])) {
            sum += value[indexSort];
            answer[index][0] = value[0];
            answer[index][1] = value[1];
            index++;
        }
    }
    if (index < countVertex - 1) {
        return NULL;
    }
    Pair* result = malloc(sizeof(Pair));
    result->sum = sum;
    result->answer = answer;
    return result;
}

typedef struct {
    int* segmentArray;
    int (*function)(int, int);
} SegmentTree;

SegmentTree* create_segment_tree() {
    SegmentTree* segment_tree = malloc(sizeof(SegmentTree));
    segment_tree->segmentArray = NULL;
    segment_tree->function = NULL;
    return segment_tree;
}

void id4(SegmentTree* segment_tree, int* segmentArray) {
    segment_tree->segmentArray = segmentArray;
}

int* id23(SegmentTree* segment_tree) {
    return segment_tree->segmentArray;
}

void set_function(SegmentTree* segment_tree, int (*function)(int, int)) {
    segment_tree->function = function;
}

int get_function(SegmentTree* segment_tree) {
    return segment_tree->function;
}

SegmentTree* create_segment_tree(int* startBase, int neutral, int (*function)(int, int)) {
    SegmentTree* segment_tree = malloc(sizeof(SegmentTree));
    segment_tree->function = function;
    int length = sizeof(startBase) / sizeof(int);
    int* base;
    if ((length & (length - 1)) != 0) {
        int pow = 0;
        while (length > 0) {
            length >>= 1;
            pow++;
        }
        pow--;
        base = malloc((2 << pow) * sizeof(int));
        memcpy(base, startBase, length * sizeof(int));
        for (int i = length; i < (2 << pow); i++) {
            base[i] = neutral;
        }
    } else {
        base = startBase;
    }
    segment_tree->segmentArray = malloc((2 * sizeof(base)) * sizeof(int));
    memset(segment_tree->segmentArray, neutral, (2 * sizeof(base)) * sizeof(int));
    in_depth(base, 1, 0, length - 1);
    return segment_tree;
}

void in_depth(int* base, int position, int low, int high) {
    if (low == high) {
        segmentArray[position] = base[low];
    } else {
        int mid = (low + high) >> 1;
        in_depth(base, position << 1, low, mid);
        in_depth(base, (position << 1) + 1, mid + 1, high);
        segmentArray[position] = function(segmentArray[position << 1], segmentArray[(position << 1) + 1]);
    }
}

int get_value(SegmentTree* segment_tree, int left, int right, int neutral) {
    return find_value(1, 0, ((sizeof(segment_tree->segmentArray) / sizeof(int)) >> 1) - 1, left, right, neutral);
}

int find_value(int position, int low, int high, int left, int right, int neutral) {
    if (left > right) {
        return neutral;
    }
    if (left == low && right == high) {
        return segmentArray[position];
    }
    int mid = (low + high) >> 1;
    return function(find_value(position << 1, low, mid, left, min(right, mid), neutral),
                    find_value((position << 1) + 1, mid + 1, high, max(left, mid + 1), right, neutral));
}

void replace_value(SegmentTree* segment_tree, int index, int value) {
    update(1, 0, (sizeof(segment_tree->segmentArray) / sizeof(int) >> 1) - 1, index, value);
}

void update(int position, int low, int high, int index, int value) {
    if (low == high) {
        segmentArray[position] = value;
    } else {
        int mid = (low + high) >> 1;
        if (index <= mid) {
            update(position << 1, low, mid, index, value);
        } else {
            update((position << 1) + 1, mid + 1, high, index, value);
        }
        segmentArray[position] = function(segmentArray[position << 1], segmentArray[(position << 1) + 1]);
    }
}

int compare_int(const void* a, const void* b) {
    const int* int_a = (const int*)a;
    const int* int_b = (const int*)b;
    return *int_a - *int_b;
}

int** sort(int** array, int id17, int length) {
    if (id17 == 0) {
        qsort(array, length, sizeof(int*), compare_int);
    } else if (id17 == 1) {
        heap_sort(array, length);
    } else if (id17 == 2) {
        merge_sort(array, 0, length - 1);
    } else if (id17 == 3) {
        insertion_sort(array, length);
    } else if (id17 == 4) {
        selection_sort(array, length);
    }
    return array;
}

void heap_sort(int** array, int length) {
    for (int i = (length >> 1) - 1; i >= 0; i--) {
        shift_down(array, i, length);
    }
    for (int i = length - 1; i > 0; i--) {
        swap(array, 0, i);
        shift_down(array, 0, i);
    }
}

void shift_down(int** array, int i, int n) {
    int child;
    int* tmp;
    for (tmp = array[i]; left_child(i) < n; i = child) {
        child = left_child(i);
        if (child != n - 1 && (*array[child] < *array[child + 1])) {
            child++;
        }
        if (*tmp < *array[child]) {
            array[i] = array[child];
        } else {
            break;
        }
    }
    array[i] = tmp;
}

int left_child(int i) {
    return (i << 1) + 1;
}

void swap(int** array, int i, int j) {
    int* temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void merge_sort(int** array, int low, int high) {
    if (low < high) {
        int mid = (low + high) >> 1;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void merge(int** array, int low, int mid, int high) {
    int n = high - low + 1;
    int* temp = malloc(n * sizeof(int));
    int i = low, j = mid + 1;
    int k = 0;
    while (i <= mid || j <= high) {
        if (i > mid) {
            temp[k++] = *array[j++];
        } else if (j > high) {
            temp[k++] = *array[i++];
        } else if (*array[i] < *array[j]) {
            temp[k++] = *array[i++];
        } else {
            temp[k++] = *array[j++];
        }
    }
    for (j = 0; j < n; j++) {
        *array[low + j] = temp[j];
    }
    free(temp);
}

void insertion_sort(int** array, int length) {
    for (int i = 1; i < length; i++) {
        int* key = array[i];
        int j = i - 1;
        while (j >= 0 && *key < *array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void selection_sort(int** array, int length) {
    for (int i = 0; i < length - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (*array[j] < *array[min_index]) {
                min_index = j;
            }
        }
        swap(array, i, min_index);
    }
}

int** create_2d_array(int rows, int cols) {
    int** array = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        array[i] = malloc(cols * sizeof(int));
    }
    return array;
}

void free_2d_array(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    int g, sh, j, p, priceFirst, priceSecond;
    long answer;
    scanf("%d %d %d %d %d %d", &g, &sh, &j, &p, &priceFirst, &priceSecond);
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
