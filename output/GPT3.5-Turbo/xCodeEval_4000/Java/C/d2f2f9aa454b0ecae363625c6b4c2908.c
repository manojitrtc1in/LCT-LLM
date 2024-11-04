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

    Division(void* dividend, void* divider) {
        pair = createPair(dividend, divider);
        reduce();
    }

    void reduce() {
        if (pair->first == NULL || pair->second == NULL) {
            return;
        }
        if (pair->first == pair->second) {
            pair->first = 1;
            pair->second = 1;
            return;
        }
        int a = *(int*)pair->first;
        int b = *(int*)pair->second;
        int gcd = a % b;
        while (gcd != 0) {
            a = b;
            b = gcd;
            gcd = a % b;
        }
        pair->first = *(int*)pair->first / b;
        pair->second = *(int*)pair->second / b;
    }

    void addWithoutReturn(Division* number) {
        add(number, 0);
    }

    Division* addWithReturn(Division* number) {
        return add(number, 1);
    }

    void multiplyWithoutReturn(Division* number) {
        multiply(number, 0);
    }

    Division* multiplyWithReturn(Division* number) {
        return multiply(number, 1);
    }

    Division* add(Division* number, int function) {
        if (pair->first == NULL || pair->second == NULL || number->pair->first == NULL || number->pair->second == NULL) {
            return NULL;
        }
        int a = *(int*)pair->first;
        int b = *(int*)pair->second;
        int c = *(int*)number->pair->first;
        int d = *(int*)number->pair->second;
        int lcm = (b / gcd(b, d)) * d;
        if (function == 0) {
            pair->first = (lcm / b) * a + (lcm / d) * c;
            pair->second = lcm;
            reduce();
            return NULL;
        }
        Division* result = (Division*)malloc(sizeof(Division));
        result->pair = createPair((lcm / b) * a + (lcm / d) * c, lcm);
        result->reduce();
        return result;
    }

    Division* multiply(Division* number, int function) {
        if (pair->first == NULL || pair->second == NULL || number->pair->first == NULL || number->pair->second == NULL) {
            return NULL;
        }
        int a = *(int*)pair->first;
        int b = *(int*)pair->second;
        int c = *(int*)number->pair->first;
        int d = *(int*)number->pair->second;
        if (function == 0) {
            pair->first = a * c;
            pair->second = b * d;
            reduce();
            return NULL;
        }
        Division* answer = (Division*)malloc(sizeof(Division));
        answer->pair = createPair(a * c, b * d);
        answer->reduce();
        return answer;
    }

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
} Division;

typedef struct Graph {
    int** base;
    int* used;
    int quantity;
    int* ancestor;

    int** getBase() {
        return base;
    }

    int* getUsed() {
        return used;
    }

    int getQuantity() {
        return quantity;
    }

    int* getAncestor() {
        return ancestor;
    }

    void start(int length) {
        used = (int*)calloc(length, sizeof(int));
        ancestor = (int*)malloc(length * sizeof(int));
        ancestor[0] = -1;
        quantity = 0;
    }

    void ribMatrixToDefault(int length, int quantity, int readConsole, int** value) {
        base = (int**)malloc(length * sizeof(int*));
        for (int i = 0; i < length; i++) {
            base[i] = (int*)malloc(length * sizeof(int));
            for (int j = 0; j < length; j++) {
                base[i][j] = 0;
            }
        }
        for (int i = 0; i < quantity; i++) {
            int* input = readConsole ? readArrayInt(" ") : value[i];
            base[input[0] - 1][input[1] - 1] = 1;
            base[input[1] - 1][input[0] - 1] = 1;
        }
        start(length);
    }

    void adjacencyMatrixToDefault(int length, int not, int readConsole, int** value) {
        base = (int**)malloc(length * sizeof(int*));
        for (int i = 0; i < length; i++) {
            base[i] = (int*)malloc(length * sizeof(int));
            for (int j = 0; j < length; j++) {
                base[i][j] = 0;
            }
        }
        for (int i = 0; i < length; i++) {
            int* input = readConsole ? readArrayInt(" ") : value[i];
            for (int j = 0; j < length; j++) {
                if (i != j && input[j] != not) {
                    base[i][j] = 1;
                }
            }
        }
        start(length);
    }

    void dfs(int position) {
        used[position] = 1;
        quantity++;
        int next;
        for (int index = 0; index < base[position].length; index += 2) {
            next = base[position][index];
            if (!used[next]) {
                ancestor[next] = position;
                dfs(next);
            } else {
                if (next != ancestor[position]) {
                    printf("Exception\n");
                    return;
                }
            }
        }
    }

    int dijkstra(int start, int stop, int size) {
        start--;
        stop--;
        int* dist = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            if (i != start) {
                dist[i] = INT_MAX;
            }
            ancestor[i] = start;
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
            for (int index = 0; index < base[position].length; index += 2) {
                if (dist[position] + base[position][index + 1] < dist[base[position][index]] && !used[base[position][index]]) {
                    dist[base[position][index]] = dist[position] + base[position][index + 1];
                    ancestor[base[position][index]] = position;
                    queue[queueSize][0] = base[position][index];
                    queue[queueSize][1] = dist[base[position][index]];
                    queueSize++;
                }
            }
            used[position] = 1;
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
} Graph;

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
    for (tmp = array[i]; leftChild(i) < n; i = child) {
        child = leftChild(i);
        if (child != n - 1 && (array[child] < array[child + 1]))
            child++;
        if (tmp < array[child])
            array[i] = array[child];
        else
            break;
    }
    array[i] = tmp;
}

int leftChild(int i) {
    return 2 * i + 1;
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
    int** FirstBuffer = (int**)malloc(0 * sizeof(int*));
    int position = 0;
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

void insertionSort(int* elements, int length) {
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

int* readArrayInt(char* split) {
    int* array = (int*)malloc(100 * sizeof(int));
    int index = 0;
    char* token = strtok(readString(), split);
    while (token != NULL) {
        array[index++] = atoi(token);
        token = strtok(NULL, split);
    }
    return array;
}

long* readArrayLong(char* split) {
    long* array = (long*)malloc(100 * sizeof(long));
    int index = 0;
    char* token = strtok(readString(), split);
    while (token != NULL) {
        array[index++] = atol(token);
        token = strtok(NULL, split);
    }
    return array;
}

char** readArrayString(char* split) {
    char** array = (char**)malloc(100 * sizeof(char*));
    int index = 0;
    char* token = strtok(readString(), split);
    while (token != NULL) {
        array[index++] = token;
        token = strtok(NULL, split);
    }
    return array;
}

void writeArray(int* array, char* split, int length, int enter) {
    for (int index = 0; index < length; index++) {
        printf("%d", array[index]);
        if (index + 1 != length) {
            printf("%s", split);
        }
    }
    if (enter) {
        printf("\n");
    }
}

void writeArray(long* array, char* split, int length, int enter) {
    for (int index = 0; index < length; index++) {
        printf("%ld", array[index]);
        if (index + 1 != length) {
            printf("%s", split);
        }
    }
    if (enter) {
        printf("\n");
    }
}

void writeArray(char** array, char* split, int length, int enter) {
    for (int index = 0; index < length; index++) {
        printf("%s", array[index]);
        if (index + 1 != length) {
            printf("%s", split);
        }
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
    return 0;
}
