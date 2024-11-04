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
    void* first;
    void* second;
} Pair;

Pair* createPair(void* first, void* second) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->first = first;
    pair->second = second;
    return pair;
}

void* getFirst(Pair* pair) {
    return pair->first;
}

void* getSecond(Pair* pair) {
    return pair->second;
}

void setFirst(Pair* pair, void* element) {
    pair->first = element;
}

void setSecond(Pair* pair, void* element) {
    pair->second = element;
}

typedef struct {
    void* dividend;
    void* divider;
} Division;

Division* createDivision(void* dividend, void* divider) {
    Division* division = (Division*)malloc(sizeof(Division));
    division->dividend = dividend;
    division->divider = divider;
    reduce(division);
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

void add(Division* number1, Division* number2) {
    if (number1->dividend == NULL || number1->divider == NULL || number2->dividend == NULL || number2->divider == NULL) {
        return;
    }
    if (number1->dividend == (int*)number1->dividend && number1->divider == (int*)number1->divider && number2->dividend == (int*)number2->dividend && number2->divider == (int*)number2->divider) {
        int Dividend1 = *(int*)number1->dividend;
        int Divider1 = *(int*)number1->divider;
        int Dividend2 = *(int*)number2->dividend;
        int Divider2 = *(int*)number2->divider;
        int lcm = lcm(Divider1, Divider2);
        *(int*)number1->dividend = (lcm / Divider1) * Dividend1 + (lcm / Divider2) * Dividend2;
        *(int*)number1->divider = lcm;
        reduce(number1);
    } else if (number1->dividend == (long*)number1->dividend && number1->divider == (long*)number1->divider && number2->dividend == (long*)number2->dividend && number2->divider == (long*)number2->divider) {
        long Dividend1 = *(long*)number1->dividend;
        long Divider1 = *(long*)number1->divider;
        long Dividend2 = *(long*)number2->dividend;
        long Divider2 = *(long*)number2->divider;
        long lcm = lcm(Divider1, Divider2);
        *(long*)number1->dividend = (lcm / Divider1) * Dividend1 + (lcm / Divider2) * Dividend2;
        *(long*)number1->divider = lcm;
        reduce(number1);
    } else if (number1->dividend == (float*)number1->dividend && number1->divider == (float*)number1->divider && number2->dividend == (float*)number2->dividend && number2->divider == (float*)number2->divider) {
        float Dividend1 = *(float*)number1->dividend;
        float Divider1 = *(float*)number1->divider;
        float Dividend2 = *(float*)number2->dividend;
        float Divider2 = *(float*)number2->divider;
        float lcm = lcm(Divider1, Divider2);
        *(float*)number1->dividend = (lcm / Divider1) * Dividend1 + (lcm / Divider2) * Dividend2;
        *(float*)number1->divider = lcm;
        reduce(number1);
    } else if (number1->dividend == (double*)number1->dividend && number1->divider == (double*)number1->divider && number2->dividend == (double*)number2->dividend && number2->divider == (double*)number2->divider) {
        double Dividend1 = *(double*)number1->dividend;
        double Divider1 = *(double*)number1->divider;
        double Dividend2 = *(double*)number2->dividend;
        double Divider2 = *(double*)number2->divider;
        double lcm = lcm(Divider1, Divider2);
        *(double*)number1->dividend = (lcm / Divider1) * Dividend1 + (lcm / Divider2) * Dividend2;
        *(double*)number1->divider = lcm;
        reduce(number1);
    }
}

void multiply(Division* number1, Division* number2) {
    if (number1->dividend == NULL || number1->divider == NULL || number2->dividend == NULL || number2->divider == NULL) {
        return;
    }
    if (number1->dividend == (int*)number1->dividend && number1->divider == (int*)number1->divider && number2->dividend == (int*)number2->dividend && number2->divider == (int*)number2->divider) {
        int Dividend1 = *(int*)number1->dividend;
        int Divider1 = *(int*)number1->divider;
        int Dividend2 = *(int*)number2->dividend;
        int Divider2 = *(int*)number2->divider;
        *(int*)number1->dividend = Dividend1 * Dividend2;
        *(int*)number1->divider = Divider1 * Divider2;
        reduce(number1);
    } else if (number1->dividend == (long*)number1->dividend && number1->divider == (long*)number1->divider && number2->dividend == (long*)number2->dividend && number2->divider == (long*)number2->divider) {
        long Dividend1 = *(long*)number1->dividend;
        long Divider1 = *(long*)number1->divider;
        long Dividend2 = *(long*)number2->dividend;
        long Divider2 = *(long*)number2->divider;
        *(long*)number1->dividend = Dividend1 * Dividend2;
        *(long*)number1->divider = Divider1 * Divider2;
        reduce(number1);
    } else if (number1->dividend == (float*)number1->dividend && number1->divider == (float*)number1->divider && number2->dividend == (float*)number2->dividend && number2->divider == (float*)number2->divider) {
        float Dividend1 = *(float*)number1->dividend;
        float Divider1 = *(float*)number1->divider;
        float Dividend2 = *(float*)number2->dividend;
        float Divider2 = *(float*)number2->divider;
        *(float*)number1->dividend = Dividend1 * Dividend2;
        *(float*)number1->divider = Divider1 * Divider2;
        reduce(number1);
    } else if (number1->dividend == (double*)number1->dividend && number1->divider == (double*)number1->divider && number2->dividend == (double*)number2->dividend && number2->divider == (double*)number2->divider) {
        double Dividend1 = *(double*)number1->dividend;
        double Divider1 = *(double*)number1->divider;
        double Dividend2 = *(double*)number2->dividend;
        double Divider2 = *(double*)number2->divider;
        *(double*)number1->dividend = Dividend1 * Dividend2;
        *(double*)number1->divider = Divider1 * Divider2;
        reduce(number1);
    }
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
    int* dist = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        if (i != start) {
            dist[i] = __INT_MAX__;
        }
        graph->ancestor[i] = start;
    }

    typedef struct {
        int position;
        int distance;
    } QueueElement;

    QueueElement* queue = (QueueElement*)malloc(size * sizeof(QueueElement));
    int queueSize = 0;
    queue[queueSize].position = start;
    queue[queueSize].distance = 0;
    queueSize++;
    int position;
    int getQueue;
    while (queueSize != 0) {
        int minDistance = __INT_MAX__;
        int minIndex = -1;
        for (int i = 0; i < queueSize; i++) {
            if (queue[i].distance < minDistance) {
                minDistance = queue[i].distance;
                minIndex = i;
            }
        }
        getQueue = queue[minIndex].position;
        position = getQueue;
        if (minDistance > dist[position]) {
            continue;
        }
        for (int index = 0; index < graph->base[position][0]; index += 2) {
            if (dist[position] + graph->base[position][index + 1] < dist[graph->base[position][index]] && !graph->used[graph->base[position][index]]) {
                dist[graph->base[position][index]] = dist[position] + graph->base[position][index + 1];
                graph->ancestor[graph->base[position][index]] = position;
                queue[queueSize].position = graph->base[position][index];
                queue[queueSize].distance = dist[graph->base[position][index]];
                queueSize++;
            }
        }
        graph->used[position] = 1;
        queueSize--;
        for (int i = minIndex; i < queueSize; i++) {
            queue[i] = queue[i + 1];
        }
    }
    free(queue);
    int result = dist[stop] == __INT_MAX__ ? -1 : dist[stop];
    free(dist);
    return result;
}

int** createBase(int length, int quantity, int** value) {
    int** base = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        base[i] = (int*)malloc(quantity * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < quantity; j++) {
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

int** createGraphInput(int length, int quantity, int readConsole, int** value) {
    int** base = createBase(length, quantity, value);
    int** inputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        inputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            inputBase[i][index] = -1;
        }
    }
    for (int i = 0; i < quantity; i++) {
        int* input = readConsole ? readInts(" ", 2) : value[i];
        inputBase[input[0] - 1][inputBase[input[0] - 1][0] + 1] = input[1] - 1;
        inputBase[input[0] - 1][inputBase[input[0] - 1][0] + 2] = input[2];
        inputBase[input[0] - 1][0] += 2;

        inputBase[input[1] - 1][inputBase[input[1] - 1][0] + 1] = input[0] - 1;
        inputBase[input[1] - 1][inputBase[input[1] - 1][0] + 2] = input[2];
        inputBase[input[1] - 1][0] += 2;
    }
    freeBase(base, length);
    return inputBase;
}

void freeGraphInput(int** inputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(inputBase[i]);
    }
    free(inputBase);
}

int** createGraphOutput(int length, int not, int readConsole, int** value) {
    int** base = createBase(length, length, value);
    int** outputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        outputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            outputBase[i][index] = -1;
        }
    }
    int* buffer = (int*)malloc(length * sizeof(int));
    int* InputArray;
    for (int i = 0; i < length; i++) {
        InputArray = readConsole ? readInts(" ", length) : value[i];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && InputArray[index] != not) {
                buffer[bufferIndex] = index;
                bufferIndex++;
            }
        }
        for (int index = 0; index < bufferIndex; index++) {
            outputBase[i][index + 1] = buffer[index];
        }
        outputBase[i][0] = bufferIndex;
    }
    free(buffer);
    freeBase(base, length);
    return outputBase;
}

void freeGraphOutput(int** outputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(outputBase[i]);
    }
    free(outputBase);
}

int** createGraphInput2(int length, int quantity, int readConsole, int** value) {
    int** base = createBase(length, quantity, value);
    int** inputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        inputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            inputBase[i][index] = -1;
        }
    }
    for (int i = 0; i < quantity; i++) {
        int* input = readConsole ? readInts(" ", 2) : value[i];
        inputBase[input[0] - 1][inputBase[input[0] - 1][0] + 1] = input[1] - 1;
        inputBase[input[0] - 1][0] += 1;

        inputBase[input[1] - 1][inputBase[input[1] - 1][0] + 1] = input[0] - 1;
        inputBase[input[1] - 1][0] += 1;
    }
    freeBase(base, length);
    return inputBase;
}

void freeGraphInput2(int** inputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(inputBase[i]);
    }
    free(inputBase);
}

int** createGraphOutput2(int length, int not, int readConsole, int** value) {
    int** base = createBase(length, length, value);
    int** outputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        outputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            outputBase[i][index] = -1;
        }
    }
    int* buffer = (int*)malloc(length * sizeof(int));
    int* InputArray;
    for (int i = 0; i < length; i++) {
        InputArray = readConsole ? readInts(" ", length) : value[i];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && InputArray[index] != not) {
                buffer[bufferIndex] = index;
                bufferIndex++;
            }
        }
        for (int index = 0; index < bufferIndex; index++) {
            outputBase[i][index + 1] = buffer[index];
        }
        outputBase[i][0] = bufferIndex;
    }
    free(buffer);
    freeBase(base, length);
    return outputBase;
}

void freeGraphOutput2(int** outputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(outputBase[i]);
    }
    free(outputBase);
}

int** createGraphInput3(int length, int quantity, int readConsole, int** value) {
    int** base = createBase(length, quantity, value);
    int** inputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        inputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            inputBase[i][index] = -1;
        }
    }
    for (int i = 0; i < quantity; i++) {
        int* input = readConsole ? readInts(" ", 2) : value[i];
        inputBase[input[0] - 1][inputBase[input[0] - 1][0] + 1] = input[1] - 1;
        inputBase[input[0] - 1][0] += 1;
    }
    freeBase(base, length);
    return inputBase;
}

void freeGraphInput3(int** inputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(inputBase[i]);
    }
    free(inputBase);
}

int** createGraphOutput3(int length, int not, int readConsole, int** value) {
    int** base = createBase(length, length, value);
    int** outputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        outputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            outputBase[i][index] = -1;
        }
    }
    int* buffer = (int*)malloc(length * sizeof(int));
    int* InputArray;
    for (int i = 0; i < length; i++) {
        InputArray = readConsole ? readInts(" ", length) : value[i];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && InputArray[index] != not) {
                buffer[bufferIndex] = index;
                bufferIndex++;
            }
        }
        for (int index = 0; index < bufferIndex; index++) {
            outputBase[i][index + 1] = buffer[index];
        }
        outputBase[i][0] = bufferIndex;
    }
    free(buffer);
    freeBase(base, length);
    return outputBase;
}

void freeGraphOutput3(int** outputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(outputBase[i]);
    }
    free(outputBase);
}

int** createGraphInput4(int length, int quantity, int readConsole, int** value) {
    int** base = createBase(length, quantity, value);
    int** inputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        inputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            inputBase[i][index] = -1;
        }
    }
    for (int i = 0; i < quantity; i++) {
        int* input = readConsole ? readInts(" ", 2) : value[i];
        inputBase[input[0] - 1][inputBase[input[0] - 1][0] + 1] = input[1] - 1;
        inputBase[input[0] - 1][0] += 1;
    }
    freeBase(base, length);
    return inputBase;
}

void freeGraphInput4(int** inputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(inputBase[i]);
    }
    free(inputBase);
}

int** createGraphOutput4(int length, int not, int readConsole, int** value) {
    int** base = createBase(length, length, value);
    int** outputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        outputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            outputBase[i][index] = -1;
        }
    }
    int* buffer = (int*)malloc(length * sizeof(int));
    int* InputArray;
    for (int i = 0; i < length; i++) {
        InputArray = readConsole ? readInts(" ", length) : value[i];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && InputArray[index] != not) {
                buffer[bufferIndex] = index;
                bufferIndex++;
            }
        }
        for (int index = 0; index < bufferIndex; index++) {
            outputBase[i][index + 1] = buffer[index];
        }
        outputBase[i][0] = bufferIndex;
    }
    free(buffer);
    freeBase(base, length);
    return outputBase;
}

void freeGraphOutput4(int** outputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(outputBase[i]);
    }
    free(outputBase);
}

int** createGraphInput5(int length, int quantity, int readConsole, int** value) {
    int** base = createBase(length, quantity, value);
    int** inputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        inputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            inputBase[i][index] = -1;
        }
    }
    for (int i = 0; i < quantity; i++) {
        int* input = readConsole ? readInts(" ", 2) : value[i];
        inputBase[input[0] - 1][inputBase[input[0] - 1][0] + 1] = input[1] - 1;
        inputBase[input[0] - 1][0] += 1;
    }
    freeBase(base, length);
    return inputBase;
}

void freeGraphInput5(int** inputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(inputBase[i]);
    }
    free(inputBase);
}

int** createGraphOutput5(int length, int not, int readConsole, int** value) {
    int** base = createBase(length, length, value);
    int** outputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        outputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            outputBase[i][index] = -1;
        }
    }
    int* buffer = (int*)malloc(length * sizeof(int));
    int* InputArray;
    for (int i = 0; i < length; i++) {
        InputArray = readConsole ? readInts(" ", length) : value[i];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && InputArray[index] != not) {
                buffer[bufferIndex] = index;
                bufferIndex++;
            }
        }
        for (int index = 0; index < bufferIndex; index++) {
            outputBase[i][index + 1] = buffer[index];
        }
        outputBase[i][0] = bufferIndex;
    }
    free(buffer);
    freeBase(base, length);
    return outputBase;
}

void freeGraphOutput5(int** outputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(outputBase[i]);
    }
    free(outputBase);
}

int** createGraphInput6(int length, int quantity, int readConsole, int** value) {
    int** base = createBase(length, quantity, value);
    int** inputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        inputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            inputBase[i][index] = -1;
        }
    }
    for (int i = 0; i < quantity; i++) {
        int* input = readConsole ? readInts(" ", 2) : value[i];
        inputBase[input[0] - 1][inputBase[input[0] - 1][0] + 1] = input[1] - 1;
        inputBase[input[0] - 1][0] += 1;
    }
    freeBase(base, length);
    return inputBase;
}

void freeGraphInput6(int** inputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(inputBase[i]);
    }
    free(inputBase);
}

int** createGraphOutput6(int length, int not, int readConsole, int** value) {
    int** base = createBase(length, length, value);
    int** outputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        outputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            outputBase[i][index] = -1;
        }
    }
    int* buffer = (int*)malloc(length * sizeof(int));
    int* InputArray;
    for (int i = 0; i < length; i++) {
        InputArray = readConsole ? readInts(" ", length) : value[i];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && InputArray[index] != not) {
                buffer[bufferIndex] = index;
                bufferIndex++;
            }
        }
        for (int index = 0; index < bufferIndex; index++) {
            outputBase[i][index + 1] = buffer[index];
        }
        outputBase[i][0] = bufferIndex;
    }
    free(buffer);
    freeBase(base, length);
    return outputBase;
}

void freeGraphOutput6(int** outputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(outputBase[i]);
    }
    free(outputBase);
}

int** createGraphInput7(int length, int quantity, int readConsole, int** value) {
    int** base = createBase(length, quantity, value);
    int** inputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        inputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            inputBase[i][index] = -1;
        }
    }
    for (int i = 0; i < quantity; i++) {
        int* input = readConsole ? readInts(" ", 2) : value[i];
        inputBase[input[0] - 1][inputBase[input[0] - 1][0] + 1] = input[1] - 1;
        inputBase[input[0] - 1][0] += 1;
    }
    freeBase(base, length);
    return inputBase;
}

void freeGraphInput7(int** inputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(inputBase[i]);
    }
    free(inputBase);
}

int** createGraphOutput7(int length, int not, int readConsole, int** value) {
    int** base = createBase(length, length, value);
    int** outputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        outputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            outputBase[i][index] = -1;
        }
    }
    int* buffer = (int*)malloc(length * sizeof(int));
    int* InputArray;
    for (int i = 0; i < length; i++) {
        InputArray = readConsole ? readInts(" ", length) : value[i];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && InputArray[index] != not) {
                buffer[bufferIndex] = index;
                bufferIndex++;
            }
        }
        for (int index = 0; index < bufferIndex; index++) {
            outputBase[i][index + 1] = buffer[index];
        }
        outputBase[i][0] = bufferIndex;
    }
    free(buffer);
    freeBase(base, length);
    return outputBase;
}

void freeGraphOutput7(int** outputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(outputBase[i]);
    }
    free(outputBase);
}

int** createGraphInput8(int length, int quantity, int readConsole, int** value) {
    int** base = createBase(length, quantity, value);
    int** inputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        inputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            inputBase[i][index] = -1;
        }
    }
    for (int i = 0; i < quantity; i++) {
        int* input = readConsole ? readInts(" ", 2) : value[i];
        inputBase[input[0] - 1][inputBase[input[0] - 1][0] + 1] = input[1] - 1;
        inputBase[input[0] - 1][0] += 1;
    }
    freeBase(base, length);
    return inputBase;
}

void freeGraphInput8(int** inputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(inputBase[i]);
    }
    free(inputBase);
}

int** createGraphOutput8(int length, int not, int readConsole, int** value) {
    int** base = createBase(length, length, value);
    int** outputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        outputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            outputBase[i][index] = -1;
        }
    }
    int* buffer = (int*)malloc(length * sizeof(int));
    int* InputArray;
    for (int i = 0; i < length; i++) {
        InputArray = readConsole ? readInts(" ", length) : value[i];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && InputArray[index] != not) {
                buffer[bufferIndex] = index;
                bufferIndex++;
            }
        }
        for (int index = 0; index < bufferIndex; index++) {
            outputBase[i][index + 1] = buffer[index];
        }
        outputBase[i][0] = bufferIndex;
    }
    free(buffer);
    freeBase(base, length);
    return outputBase;
}

void freeGraphOutput8(int** outputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(outputBase[i]);
    }
    free(outputBase);
}

int** createGraphInput9(int length, int quantity, int readConsole, int** value) {
    int** base = createBase(length, quantity, value);
    int** inputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        inputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            inputBase[i][index] = -1;
        }
    }
    for (int i = 0; i < quantity; i++) {
        int* input = readConsole ? readInts(" ", 2) : value[i];
        inputBase[input[0] - 1][inputBase[input[0] - 1][0] + 1] = input[1] - 1;
        inputBase[input[0] - 1][0] += 1;
    }
    freeBase(base, length);
    return inputBase;
}

void freeGraphInput9(int** inputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(inputBase[i]);
    }
    free(inputBase);
}

int** createGraphOutput9(int length, int not, int readConsole, int** value) {
    int** base = createBase(length, length, value);
    int** outputBase = (int**)malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++) {
        outputBase[i] = (int*)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        for (int index = 0; index < length; index++) {
            outputBase[i][index] = -1;
        }
    }
    int* buffer = (int*)malloc(length * sizeof(int));
    int* InputArray;
    for (int i = 0; i < length; i++) {
        InputArray = readConsole ? readInts(" ", length) : value[i];
        int bufferIndex = 0;
        for (int index = 0; index < length; index++) {
            if (i != index && InputArray[index] != not) {
                buffer[bufferIndex] = index;
                bufferIndex++;
            }
        }
        for (int index = 0; index < bufferIndex; index++) {
            outputBase[i][index + 1] = buffer[index];
        }
        outputBase[i][0] = bufferIndex;
    }
    free(buffer);
    freeBase(base, length);
    return outputBase;
}

void freeGraphOutput9(int** outputBase, int length) {
    for (int i = 0; i < length; i++) {
        free(outputBase[i]);
    }
    free(outputBase);
}

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

int main() {
    int i1;
    scanf("%d", &i1);
    for (int i2 = 0; i2 < i1; i2++) {
        int* quantity = readInts(" ", 3);
        int* base = readInts(" ", quantity[2]);
        int* countValue = (int*)calloc(quantity[2], sizeof(int));
        for (int i = 0; i < quantity[2]; i++) {
            countValue[base[i]]++;
        }
        int min = 0;
        for (int i = quantity[2]; i < quantity[0]; i++) {
            countValue[base[i - quantity[2]]]--;
            if (countValue[base[i - quantity[2]]] == 0) {
                min--;
            }
            countValue[base[i]]++;
            if (countValue[base[i]] == 1) {
                min++;
