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
    return solve_factorial(number);
}

long solve_factorial(int number) {
    if (number > 0) {
        return solve_factorial(number - 1) * number;
    }
    return 1;
}

typedef struct {
    int value;
} Int;

int compare_to_int(const void *a, const void *b) {
    const Int *int_a = (const Int *)a;
    const Int *int_b = (const Int *)b;
    return (int_a->value < int_b->value) ? -1 : ((int_a->value == int_b->value) ? 0 : 1);
}

typedef struct {
    void *dividend;
    void *divider;
} Fraction;

Fraction *create_fraction(void *dividend, void *divider) {
    Fraction *fraction = malloc(sizeof(Fraction));
    fraction->dividend = dividend;
    fraction->divider = divider;
    return fraction;
}

void reduce_fraction(Fraction *fraction, int type) {
    if (type == 0) {
        int *dividend = (int *)fraction->dividend;
        int *divider = (int *)fraction->divider;
        int gcd_value = gcd(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    } else if (type == 1) {
        long *dividend = (long *)fraction->dividend;
        long *divider = (long *)fraction->divider;
        long gcd_value = gcd_long(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    } else if (type == 2) {
        float *dividend = (float *)fraction->dividend;
        float *divider = (float *)fraction->divider;
        float gcd_value = gcd_float(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    } else if (type == 3) {
        double *dividend = (double *)fraction->dividend;
        double *divider = (double *)fraction->divider;
        double gcd_value = gcd_double(*dividend, *divider);
        *dividend /= gcd_value;
        *divider /= gcd_value;
    }
}

void add_fraction(Fraction *fraction1, Fraction *fraction2, int function, int type) {
    if (type == 0) {
        int *dividend1 = (int *)fraction1->dividend;
        int *divider1 = (int *)fraction1->divider;
        int *dividend2 = (int *)fraction2->dividend;
        int *divider2 = (int *)fraction2->divider;
        int lcm_value = lcm_int(*divider1, *divider2);
        if (function == 0) {
            *dividend1 = (lcm_value / *divider1) * *dividend1 + (lcm_value / *divider2) * *dividend2;
            *divider1 = lcm_value;
            reduce_fraction(fraction1, type);
        } else {
            int *dividend = malloc(sizeof(int));
            int *divider = malloc(sizeof(int));
            *dividend = (lcm_value / *divider1) * *dividend1 + (lcm_value / *divider2) * *dividend2;
            *divider = lcm_value;
            reduce_fraction(create_fraction(dividend, divider), type);
        }
    } else if (type == 1) {
        long *dividend1 = (long *)fraction1->dividend;
        long *divider1 = (long *)fraction1->divider;
        long *dividend2 = (long *)fraction2->dividend;
        long *divider2 = (long *)fraction2->divider;
        long lcm_value = lcm_long(*divider1, *divider2);
        if (function == 0) {
            *dividend1 = (lcm_value / *divider1) * *dividend1 + (lcm_value / *divider2) * *dividend2;
            *divider1 = lcm_value;
            reduce_fraction(fraction1, type);
        } else {
            long *dividend = malloc(sizeof(long));
            long *divider = malloc(sizeof(long));
            *dividend = (lcm_value / *divider1) * *dividend1 + (lcm_value / *divider2) * *dividend2;
            *divider = lcm_value;
            reduce_fraction(create_fraction(dividend, divider), type);
        }
    } else if (type == 2) {
        float *dividend1 = (float *)fraction1->dividend;
        float *divider1 = (float *)fraction1->divider;
        float *dividend2 = (float *)fraction2->dividend;
        float *divider2 = (float *)fraction2->divider;
        float lcm_value = lcm_float(*divider1, *divider2);
        if (function == 0) {
            *dividend1 = (lcm_value / *divider1) * *dividend1 + (lcm_value / *divider2) * *dividend2;
            *divider1 = lcm_value;
            reduce_fraction(fraction1, type);
        } else {
            float *dividend = malloc(sizeof(float));
            float *divider = malloc(sizeof(float));
            *dividend = (lcm_value / *divider1) * *dividend1 + (lcm_value / *divider2) * *dividend2;
            *divider = lcm_value;
            reduce_fraction(create_fraction(dividend, divider), type);
        }
    } else if (type == 3) {
        double *dividend1 = (double *)fraction1->dividend;
        double *divider1 = (double *)fraction1->divider;
        double *dividend2 = (double *)fraction2->dividend;
        double *divider2 = (double *)fraction2->divider;
        double lcm_value = lcm_double(*divider1, *divider2);
        if (function == 0) {
            *dividend1 = (lcm_value / *divider1) * *dividend1 + (lcm_value / *divider2) * *dividend2;
            *divider1 = lcm_value;
            reduce_fraction(fraction1, type);
        } else {
            double *dividend = malloc(sizeof(double));
            double *divider = malloc(sizeof(double));
            *dividend = (lcm_value / *divider1) * *dividend1 + (lcm_value / *divider2) * *dividend2;
            *divider = lcm_value;
            reduce_fraction(create_fraction(dividend, divider), type);
        }
    }
}

void multiply_fraction(Fraction *fraction1, Fraction *fraction2, int function, int type) {
    if (type == 0) {
        int *dividend1 = (int *)fraction1->dividend;
        int *divider1 = (int *)fraction1->divider;
        int *dividend2 = (int *)fraction2->dividend;
        int *divider2 = (int *)fraction2->divider;
        int first = *dividend1 * *dividend2;
        int second = *divider1 * *divider2;
        if (function == 0) {
            *dividend1 = first;
            *divider1 = second;
            reduce_fraction(fraction1, type);
        } else {
            int *dividend = malloc(sizeof(int));
            int *divider = malloc(sizeof(int));
            *dividend = first;
            *divider = second;
            reduce_fraction(create_fraction(dividend, divider), type);
        }
    } else if (type == 1) {
        long *dividend1 = (long *)fraction1->dividend;
        long *divider1 = (long *)fraction1->divider;
        long *dividend2 = (long *)fraction2->dividend;
        long *divider2 = (long *)fraction2->divider;
        long first = *dividend1 * *dividend2;
        long second = *divider1 * *divider2;
        if (function == 0) {
            *dividend1 = first;
            *divider1 = second;
            reduce_fraction(fraction1, type);
        } else {
            long *dividend = malloc(sizeof(long));
            long *divider = malloc(sizeof(long));
            *dividend = first;
            *divider = second;
            reduce_fraction(create_fraction(dividend, divider), type);
        }
    } else if (type == 2) {
        float *dividend1 = (float *)fraction1->dividend;
        float *divider1 = (float *)fraction1->divider;
        float *dividend2 = (float *)fraction2->dividend;
        float *divider2 = (float *)fraction2->divider;
        float first = *dividend1 * *dividend2;
        float second = *divider1 * *divider2;
        if (function == 0) {
            *dividend1 = first;
            *divider1 = second;
            reduce_fraction(fraction1, type);
        } else {
            float *dividend = malloc(sizeof(float));
            float *divider = malloc(sizeof(float));
            *dividend = first;
            *divider = second;
            reduce_fraction(create_fraction(dividend, divider), type);
        }
    } else if (type == 3) {
        double *dividend1 = (double *)fraction1->dividend;
        double *divider1 = (double *)fraction1->divider;
        double *dividend2 = (double *)fraction2->dividend;
        double *divider2 = (double *)fraction2->divider;
        double first = *dividend1 * *dividend2;
        double second = *divider1 * *divider2;
        if (function == 0) {
            *dividend1 = first;
            *divider1 = second;
            reduce_fraction(fraction1, type);
        } else {
            double *dividend = malloc(sizeof(double));
            double *divider = malloc(sizeof(double));
            *dividend = first;
            *divider = second;
            reduce_fraction(create_fraction(dividend, divider), type);
        }
    }
}

typedef struct {
    int **base;
    int *used;
    int quantity;
    int *ancestor;
} Graph;

Graph *create_graph() {
    Graph *graph = malloc(sizeof(Graph));
    graph->base = NULL;
    graph->used = NULL;
    graph->quantity = 0;
    graph->ancestor = NULL;
    return graph;
}

void set_base(Graph *graph, int **base) {
    graph->base = base;
}

void set_used(Graph *graph, int *used) {
    graph->used = used;
}

void set_quantity(Graph *graph, int quantity) {
    graph->quantity = quantity;
}

void set_ancestor(Graph *graph, int *ancestor) {
    graph->ancestor = ancestor;
}

void start(Graph *graph, int length) {
    graph->used = malloc(length * sizeof(int));
    graph->ancestor = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        graph->used[i] = 0;
        graph->ancestor[i] = -1;
    }
    graph->quantity = 0;
}

void edges_matrix_to_default(Graph *graph, int length, int quantity, int **value) {
    graph->base = malloc(length * sizeof(int *));
    for (int i = 0; i < length; i++) {
        graph->base[i] = malloc(quantity * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < quantity; j++) {
            graph->base[i][j] = value[j][i];
        }
    }
    start(graph, length);
}

void adjacency_matrix_to_default(Graph *graph, int length, int not, int **value) {
    graph->base = malloc(length * sizeof(int *));
    for (int i = 0; i < length; i++) {
        int count = 0;
        for (int j = 0; j < length; j++) {
            if (i != j && value[i][j] != not) {
                count++;
            }
        }
        graph->base[i] = malloc(count * sizeof(int));
        count = 0;
        for (int j = 0; j < length; j++) {
            if (i != j && value[i][j] != not) {
                graph->base[i][count] = j;
                count++;
            }
        }
    }
    start(graph, length);
}

void dfs(Graph *graph, int position) {
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

int dijkstra(Graph *graph, int start, int stop, int size) {
    start--;
    stop--;
    int *dist = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        if (i != start) {
            dist[i] = INT_MAX;
        }
        graph->ancestor[i] = start;
    }

    int **queue = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        queue[i] = malloc(2 * sizeof(int));
    }
    int position;
    int *get_queue;
    while (size != 0) {
        int min_index = 0;
        int min_value = INT_MAX;
        for (int i = 0; i < size; i++) {
            if (queue[i][1] < min_value) {
                min_value = queue[i][1];
                min_index = i;
            }
        }
        get_queue = queue[min_index];
        position = get_queue[0];
        if (get_queue[1] > dist[position]) {
            continue;
        }
        for (int index = 0; index < sizeof(graph->base[position]) / sizeof(int); index += 2) {
            if (dist[position] + graph->base[position][index + 1] < dist[graph->base[position][index]] && !graph->used[graph->base[position][index]]) {
                dist[graph->base[position][index]] = dist[position] + graph->base[position][index + 1];
                graph->ancestor[graph->base[position][index]] = position;
                queue[size - 1][0] = graph->base[position][index];
                queue[size - 1][1] = dist[graph->base[position][index]];
                size--;
            }
        }
        graph->used[position] = 1;
        for (int i = min_index; i < size - 1; i++) {
            queue[i] = queue[i + 1];
        }
    }
    return dist[stop] == INT_MAX ? -1 : dist[stop];
}

int solve_floyd_warshall(int **base, int length, int not) {
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
    int **edges_matrix;
    int count_vertex;
    int index_sort;
} Kruskal;

Kruskal *create_kruskal() {
    Kruskal *kruskal = malloc(sizeof(Kruskal));
    kruskal->edges_matrix = NULL;
    kruskal->count_vertex = 0;
    kruskal->index_sort = 0;
    return kruskal;
}

void set_edges_matrix(Kruskal *kruskal, int **edges_matrix) {
    kruskal->edges_matrix = edges_matrix;
}

void set_count_vertex(Kruskal *kruskal, int count_vertex) {
    kruskal->count_vertex = count_vertex;
}

void set_index_sort(Kruskal *kruskal, int index_sort) {
    kruskal->index_sort = index_sort;
}

void solve_kruskal(Kruskal *kruskal, long *sum, int ***answer) {
    int count_vertex = kruskal->count_vertex;
    int **edges_matrix = kruskal->edges_matrix;
    int index_sort = kruskal->index_sort;
    int **sorted_edges_matrix = malloc(count_vertex * sizeof(int *));
    for (int i = 0; i < count_vertex; i++) {
        sorted_edges_matrix[i] = malloc(2 * sizeof(int));
    }
    for (int i = 0; i < count_vertex; i++) {
        sorted_edges_matrix[i][0] = edges_matrix[i][0];
        sorted_edges_matrix[i][1] = edges_matrix[i][1];
    }
    qsort(sorted_edges_matrix, count_vertex, sizeof(int *), compare_to_int);
    int **temp_answer = malloc((count_vertex - 1) * sizeof(int *));
    for (int i = 0; i < count_vertex - 1; i++) {
        temp_answer[i] = malloc(2 * sizeof(int));
    }
    int index = 0;
    for (int i = 0; i < count_vertex; i++) {
        if (merge_sets(answer, sorted_edges_matrix[i][0], sorted_edges_matrix[i][1])) {
            *sum += sorted_edges_matrix[i][index_sort];
            temp_answer[index][0] = sorted_edges_matrix[i][0];
            temp_answer[index][1] = sorted_edges_matrix[i][1];
            index++;
        }
    }
    if (index < count_vertex - 1) {
        *sum = -1;
        *answer = NULL;
    } else {
        *answer = temp_answer;
    }
}

int merge_sets(int ***answer, int first, int second) {
    first = find_set(*answer, first);
    second = find_set(*answer, second);
    if (first != second) {
        if ((*answer)[first][1] < (*answer)[second][1]) {
            int number = first;
            first = second;
            second = number;
        }
        (*answer)[second][0] = first;
        if ((*answer)[first][1] == (*answer)[second][1]) {
            (*answer)[first][1]++;
        }
        return 1;
    }
    return 0;
}

int find_set(int **answer, int value) {
    if (value == answer[value][0]) {
        return value;
    }
    return answer[value][0] = find_set(answer, answer[value][0]);
}

typedef struct {
    int *segment_array;
    int (*function)(int, int);
} SegmentTree;

SegmentTree *create_segment_tree() {
    SegmentTree *segment_tree = malloc(sizeof(SegmentTree));
    segment_tree->segment_array = NULL;
    segment_tree->function = NULL;
    return segment_tree;
}

void set_segment_array(SegmentTree *segment_tree, int *segment_array) {
    segment_tree->segment_array = segment_array;
}

void set_function(SegmentTree *segment_tree, int (*function)(int, int)) {
    segment_tree->function = function;
}

void in_depth(SegmentTree *segment_tree, int *base, int position, int low, int high) {
    if (low == high) {
        segment_tree->segment_array[position] = base[low];
    } else {
        int mid = (low + high) >> 1;
        in_depth(segment_tree, base, position << 1, low, mid);
        in_depth(segment_tree, base, (position << 1) + 1, mid + 1, high);
        segment_tree->segment_array[position] = segment_tree->function(segment_tree->segment_array[position << 1], segment_tree->segment_array[(position << 1) + 1]);
    }
}

int get_value(SegmentTree *segment_tree, int left, int right, int neutral) {
    return find_value(segment_tree, 1, 0, ((sizeof(segment_tree->segment_array) / sizeof(int)) >> 1) - 1, left, right, neutral);
}

int find_value(SegmentTree *segment_tree, int position, int low, int high, int left, int right, int neutral) {
    if (left > right) {
        return neutral;
    }
    if (left == low && right == high) {
        return segment_tree->segment_array[position];
    }
    int mid = (low + high) >> 1;
    return segment_tree->function(find_value(segment_tree, position << 1, low, mid, left, (right < mid) ? right : mid, neutral),
                                  find_value(segment_tree, (position << 1) + 1, mid + 1, high, (left > mid + 1) ? left : mid + 1, right, neutral));
}

void replace_value(SegmentTree *segment_tree, int index, int value) {
    update(segment_tree, 1, 0, (sizeof(segment_tree->segment_array) / sizeof(int) >> 1) - 1, index, value);
}

void update(SegmentTree *segment_tree, int position, int low, int high, int index, int value) {
    if (low == high) {
        segment_tree->segment_array[position] = value;
    } else {
        int mid = (low + high) >> 1;
        if (index <= mid) {
            update(segment_tree, position << 1, low, mid, index, value);
        } else {
            update(segment_tree, (position << 1) + 1, mid + 1, high, index, value);
        }
        segment_tree->segment_array[position] = segment_tree->function(segment_tree->segment_array[position << 1], segment_tree->segment_array[(position << 1) + 1]);
    }
}

int compare_to_int(const void *a, const void *b) {
    const int *int_a = (const int *)a;
    const int *int_b = (const int *)b;
    return (*int_a < *int_b) ? -1 : ((*int_a == *int_b) ? 0 : 1);
}

void fast_sort(int *array, int shell_heap_merge_my_insertion_sort, int length) {
    if (shell_heap_merge_my_insertion_sort == 0) {
        shell_sort(array, length);
    } else if (shell_heap_merge_my_insertion_sort == 1) {
        heap_sort(array, length);
    } else if (shell_heap_merge_my_insertion_sort == 2) {
        merge_sort(array, 0, length - 1);
    } else if (shell_heap_merge_my_insertion_sort == 3) {
        straight_merge_sort(array, length);
    } else if (shell_heap_merge_my_insertion_sort == 4) {
        insertion_sort(array, length);
    }
}

void shell_sort(int *array, int length) {
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

void heap_sort(int *array, int length) {
    for (int i = (length >> 1) - 1; i >= 0; i--)
        shift_down(array, i, length);
    for (int i = length - 1; i > 0; i--) {
        swap(array, 0, i);
        shift_down(array, 0, i);
    }
}

void shift_down(int *array, int i, int n) {
    int child;
    int tmp;
    for (tmp = array[i]; left_child(i) < n; i = child) {
        child = left_child(i);
        if (child != n - 1 && (array[child] < array[child + 1]))
            child++;
        if (tmp < array[child])
            array[i] = array[child];
        else
            break;
    }
    array[i] = tmp;
}

int left_child(int i) {
    return (i << 1) + 1;
}

void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void merge_sort(int *array, int low, int high) {
    if (low < high) {
        int mid = (low + high) >> 1;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void merge(int *array, int low, int mid, int high) {
    int n = high - low + 1;
    int *temp = malloc(n * sizeof(int));
    int i = low, j = mid + 1;
    int k = 0;
    while (i <= mid || j <= high) {
        if (i > mid)
            temp[k++] = array[j++];
        else if (j > high)
            temp[k++] = array[i++];
        else if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    for (j = 0; j < n; j++)
        array[low + j] = temp[j];
}

void straight_merge_sort(int *array, int size) {
    if (size == 0) {
        return;
    }
    int length = (size >> 1) + ((size % 2) == 0 ? 0 : 1);
    int **zero_buffer = malloc(length * sizeof(int *));
    for (int i = 0; i < length; i++) {
        zero_buffer[i] = malloc(2 * sizeof(int));
    }
    int **first_buffer = NULL;
    for (int index = 0; index < length; index++) {
        int array_index = index << 1;
        int next_array_index = (index << 1) + 1;
        if (next_array_index < size) {
            if (array[array_index] > array[next_array_index]) {
                zero_buffer[index][0] = array[next_array_index];
                zero_buffer[index][1] = array[array_index];
            } else {
                zero_buffer[index][0] = array[array_index];
                zero_buffer[index][1] = array[next_array_index];
            }
        } else {
            zero_buffer[index][0] = array[array_index];
        }
    }
    int position = 0;
    int pointer0, pointer, pointer1, number = 4, new_pointer, count;
    int **new_buffer;
    int **old_buffer;
    length = (size >> 2) + ((size % 4) == 0 ? 0 : 1);
    while (1) {
        pointer0 = 0;
        count = (number >> 1) - 1;
        if (!position) {
            first_buffer = malloc(length * sizeof(int *));
            for (int i = 0; i < length; i++) {
                first_buffer[i] = malloc(number * sizeof(int));
            }
            new_buffer = first_buffer;
            old_buffer = zero_buffer;
        } else {
            zero_buffer = malloc(length * sizeof(int *));
            for (int i = 0; i < length; i++) {
                zero_buffer[i] = malloc(number * sizeof(int));
            }
            new_buffer = zero_buffer;
            old_buffer = first_buffer;
        }
        for (int i = 0; i < length; i++) {
            pointer = 0;
            pointer1 = 0;
            new_pointer = pointer0 + 1;
            if (length == 1) {
                for (int g = 0; g < size; g++) {
                    if (pointer > count || old_buffer[pointer0][pointer] == NULL) {
                        array[g] = old_buffer[new_pointer][pointer1];
                        pointer1++;
                    } else if (pointer1 > count || old_buffer[new_pointer][pointer1] == NULL) {
                        if (old_buffer[pointer0][pointer] == NULL) {
                            continue;
                        }
                        array[g] = old_buffer[pointer0][pointer];
                        pointer++;
                    } else if (old_buffer[pointer0][pointer] >= old_buffer[new_pointer][pointer1]) {
                        array[g] = old_buffer[new_pointer][pointer1];
                        pointer1++;
                    } else {
                        array[g] = old_buffer[pointer0][pointer];
                        pointer++;
                    }
                }
                return;
            }
            for (int g = 0; g < number; g++) {
                if (pointer > count || old_buffer[pointer0][pointer] == NULL) {
                    if (old_buffer[new_pointer][pointer1] == NULL) {
                        continue;
                    }
                    new_buffer[i][g] = old_buffer[new_pointer][pointer1];
                    pointer1++;
