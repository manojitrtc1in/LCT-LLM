#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007
#define mod2 998244353

typedef struct {
    int *arr;
    int size;
    int capacity;
} ArrayList;

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

typedef struct {
    char *str;
    int size;
    int capacity;
} StringBuilder;

typedef struct {
    FILE *file;
} PrintWriter;

typedef struct {
    FILE *file;
} FastReader;

void initArrayList(ArrayList *list) {
    list->arr = (int *)malloc(sizeof(int) * 10);
    list->size = 0;
    list->capacity = 10;
}

void addArrayList(ArrayList *list, int element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (int *)realloc(list->arr, sizeof(int) * list->capacity);
    }
    list->arr[list->size++] = element;
}

void sortArrayList(ArrayList *list) {
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = 0; j < list->size - i - 1; j++) {
            if (list->arr[j] > list->arr[j + 1]) {
                int temp = list->arr[j];
                list->arr[j] = list->arr[j + 1];
                list->arr[j + 1] = temp;
            }
        }
    }
}

void initQueue(Queue *queue, int capacity) {
    queue->arr = (int *)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
}

void enqueue(Queue *queue, int element) {
    if (queue->rear == queue->capacity - 1) {
        queue->rear = -1;
    }
    queue->arr[++queue->rear] = element;
}

int dequeue(Queue *queue) {
    int element = queue->arr[queue->front++];
    if (queue->front == queue->capacity) {
        queue->front = 0;
    }
    return element;
}

int isEmptyQueue(Queue *queue) {
    return queue->rear + 1 == queue->front || queue->front + queue->capacity - 1 == queue->rear;
}

void initStack(Stack *stack, int capacity) {
    stack->arr = (int *)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
}

void push(Stack *stack, int element) {
    stack->arr[++stack->top] = element;
}

int pop(Stack *stack) {
    return stack->arr[stack->top--];
}

int isEmptyStack(Stack *stack) {
    return stack->top == -1;
}

void initStringBuilder(StringBuilder *builder) {
    builder->str = (char *)malloc(sizeof(char) * 10);
    builder->size = 0;
    builder->capacity = 10;
}

void appendStringBuilder(StringBuilder *builder, char ch) {
    if (builder->size == builder->capacity) {
        builder->capacity *= 2;
        builder->str = (char *)realloc(builder->str, sizeof(char) * builder->capacity);
    }
    builder->str[builder->size++] = ch;
}

void printStringBuilder(StringBuilder *builder) {
    for (int i = 0; i < builder->size; i++) {
        printf("%c", builder->str[i]);
    }
    printf("\n");
}

void initPrintWriter(PrintWriter *writer) {
    writer->file = stdout;
}

void print(PrintWriter *writer, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        fprintf(writer->file, "%d ", arr[i]);
    }
    fprintf(writer->file, "\n");
}

void initFastReader(FastReader *reader) {
    reader->file = stdin;
}

int nextInt(FastReader *reader) {
    int num;
    fscanf(reader->file, "%d", &num);
    return num;
}

long nextLong(FastReader *reader) {
    long num;
    fscanf(reader->file, "%ld", &num);
    return num;
}

double nextDouble(FastReader *reader) {
    double num;
    fscanf(reader->file, "%lf", &num);
    return num;
}

char *nextLine(FastReader *reader) {
    char *str = (char *)malloc(sizeof(char) * 100);
    fscanf(reader->file, "%[^\n]", str);
    return str;
}

void inputIntArray(int arr[], int size, FastReader *reader) {
    for (int i = 0; i < size; i++) {
        arr[i] = nextInt(reader);
    }
}

void inputLongArray(long arr[], int size, FastReader *reader) {
    for (int i = 0; i < size; i++) {
        arr[i] = nextLong(reader);
    }
}

long power(long x, long y) {
    long gg = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            gg = (gg * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return gg;
}

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void mainFunction() {
    int mod = 1000000007;
    int mod2 = 998244353;
    FastReader inp;
    PrintWriter out;
    initFastReader(&inp);
    out.file = stdout;

    int n = nextInt(&inp);
    long *a = (long *)malloc(sizeof(long) * n);
    inputLongArray(a, n, &inp);
    if (n > 66) {
        fprintf(out.file, "1\n");
        return;
    }
    long *pref = (long *)malloc(sizeof(long) * (n + 1));
    pref[1] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i + 1] = pref[i] ^ a[i];
    }
    int gg = 34;
    for (int c = 0; c < n - 1; c++) {
        for (int left = c; left >= 0; left--) {
            for (int right = c + 1; right < n; right++) {
                if (xor(left, c, pref) > xor(c + 1, right, pref)) {
                    gg = gg < right - left - 1 ? gg : right - left - 1;
                }
            }
        }
    }
    fprintf(out.file, "%d\n", gg == 34 ? -1 : gg);
}

long xor(int i, int j, long *pref) {
    return pref[j + 1] ^ pref[i];
}

int main() {
    mainFunction();
    return 0;
}
