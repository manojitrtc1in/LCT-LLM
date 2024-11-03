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
    return (int_a->value - int_b->value);
}

typedef struct {
    void* dividend;
    void* divider;
} Fraction;

Fraction* create_fraction(void* dividend, void* divider) {
    Fraction* fraction = (Fraction*)malloc(sizeof(Fraction));
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
            fraction = result;
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
            fraction = result;
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
            fraction = result;
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
            fraction = result;
        }
    }
}

void multiply_fraction(Fraction* fraction, Fraction* number, int function, int type) {
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
            fraction = result;
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
            fraction = result;
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
            fraction = result;
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
            fraction = result;
        }
    }
}

typedef struct {
    int** base;
    int* used;
    int quantity;
    int* ancestor;
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->base = NULL;
    graph->used = NULL;
    graph->quantity = 0;
    graph->ancestor = NULL;
    return graph;
}

void set_graph_base(Graph* graph, int** base) {
    graph->base = base;
}

void set_graph_used(Graph* graph, int* used) {
    graph->used = used;
}

void set_graph_quantity(Graph* graph, int quantity) {
    graph->quantity = quantity;
}

void set_graph_ancestor(Graph* graph, int* ancestor) {
    graph->ancestor = ancestor;
}

void start_graph(Graph* graph, int length) {
    graph->used = (int*)malloc(sizeof(int) * length);
    graph->ancestor = (int*)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        graph->used[i] = 0;
        graph->ancestor[i] = -1;
    }
    graph->quantity = 0;
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
    int* dist = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        if (i != start) {
            dist[i] = INT_MAX;
        }
        graph->ancestor[i] = start;
    }

    int** queue = (int**)malloc(sizeof(int*) * size);
    int queue_size = 0;
    queue[queue_size] = (int*)malloc(sizeof(int) * 2);
    queue[queue_size][0] = start;
    queue[queue_size][1] = 0;
    queue_size++;
    int position;
    int* get_queue;
    while (queue_size != 0) {
        int min_index = 0;
        int min_value = INT_MAX;
        for (int i = 0; i < queue_size; i++) {
            if (queue[i][1] < min_value) {
                min_index = i;
                min_value = queue[i][1];
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
                queue[queue_size] = (int*)malloc(sizeof(int) * 2);
                queue[queue_size][0] = graph->base[position][index];
                queue[queue_size][1] = dist[graph->base[position][index]];
                queue_size++;
            }
        }
        graph->used[position] = 1;
        queue_size--;
        for (int i = min_index; i < queue_size; i++) {
            queue[i] = queue[i + 1];
        }
    }
    return dist[stop] == INT_MAX ? -1 : dist[stop];
}

int** create_base(int length, int quantity, int read_console, int** value) {
    int** base = (int**)malloc(sizeof(int*) * length);
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(sizeof(int) * quantity);
    }
    for (int i = 0; i < quantity; i++) {
        int* input = read_console ? id9(" ") : value[i];
        base[input[0] - 1][i * 2] = input[1] - 1;
        base[input[0] - 1][i * 2 + 1] = input[2];
        base[input[1] - 1][i * 2] = input[0] - 1;
        base[input[1] - 1][i * 2 + 1] = input[2];
    }
    return base;
}

int** create_base2(int length, int not, int read_console, int** value) {
    int** base = (int**)malloc(sizeof(int*) * length);
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(sizeof(int) * length);
    }
    for (int i = 0; i < length; i++) {
        int* input = read_console ? id9(" ") : value[i];
        int buffer[length];
        int buffer_size = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && input[index] != not) {
                buffer[buffer_size] = index;
                buffer_size++;
            }
        }
        for (int index = 0; index < buffer_size; index++) {
            base[i][index] = buffer[index];
        }
    }
    return base;
}

int** create_base3(int length, int quantity, int read_console, int** value) {
    int** base = (int**)malloc(sizeof(int*) * length);
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(sizeof(int) * quantity);
    }
    for (int i = 0; i < length; i++) {
        int* input = read_console ? id9(" ") : value[i];
        for (int index = 0; index < length; index++) {
            if (i != index && input[index] != 0) {
                base[i][index] = input[index];
            }
        }
    }
    return base;
}

int** create_base4(int length, int quantity, int read_console, int** value) {
    int** base = (int**)malloc(sizeof(int*) * length);
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(sizeof(int) * quantity);
    }
    for (int i = 0; i < length; i++) {
        int* input = read_console ? id9(" ") : value[i];
        for (int index = 0; index < length; index++) {
            if (i != index && input[index] != 0) {
                base[i][index] = input[index];
            }
        }
    }
    return base;
}

int** create_base5(int length, int quantity, int read_console, int** value) {
    int** base = (int**)malloc(sizeof(int*) * length);
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(sizeof(int) * quantity);
    }
    for (int i = 0; i < length; i++) {
        int* input = read_console ? id9(" ") : value[i];
        for (int index = 0; index < length; index++) {
            if (i != index && input[index] != 0) {
                base[i][index] = input[index];
            }
        }
    }
    return base;
}

int** create_base6(int length, int quantity, int read_console, int** value) {
    int** base = (int**)malloc(sizeof(int*) * length);
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(sizeof(int) * quantity);
    }
    for (int i = 0; i < length; i++) {
        int* input = read_console ? id9(" ") : value[i];
        for (int index = 0; index < length; index++) {
            if (i != index && input[index] != 0) {
                base[i][index] = input[index];
            }
        }
    }
    return base;
}

int** create_base7(int length, int quantity, int read_console, int** value) {
    int** base = (int**)malloc(sizeof(int*) * length);
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(sizeof(int) * quantity);
    }
    for (int i = 0; i < length; i++) {
        int* input = read_console ? id9(" ") : value[i];
        for (int index = 0; index < length; index++) {
            if (i != index && input[index] != 0) {
                base[i][index] = input[index];
            }
        }
    }
    return base;
}

int** create_base8(int length, int quantity, int read_console, int** value) {
    int** base = (int**)malloc(sizeof(int*) * length);
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(sizeof(int) * quantity);
    }
    for (int i = 0; i < length; i++) {
        int* input = read_console ? id9(" ") : value[i];
        for (int index = 0; index < length; index++) {
            if (i != index && input[index] != 0) {
                base[i][index] = input[index];
            }
        }
    }
    return base;
}

int** create_base9(int length, int quantity, int read_console, int** value) {
    int** base = (int**)malloc(sizeof(int*) * length);
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(sizeof(int) * quantity);
    }
    for (int i = 0; i < length; i++) {
        int* input = read_console ? id9(" ") : value[i];
        for (int index = 0; index < length; index++) {
            if (i != index && input[index] != 0) {
                base[i][index] = input[index];
            }
        }
    }
    return base;
}

int** create_base10(int length, int quantity, int read_console, int** value) {
    int** base = (int**)malloc(sizeof(int*) * length);
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(sizeof(int) * quantity);
    }
    for (int i = 0; i < length; i++) {
        int* input = read_console ? id9(" ") : value[i];
        for (int index = 0; index < length; index++) {
            if (i != index && input[index] != 0) {
                base[i][index] = input[index];
            }
        }
    }
    return base;
}

int main() {
    int g, sh, j, p, priceFirst, priceSecond;
    long answer = 0;
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
