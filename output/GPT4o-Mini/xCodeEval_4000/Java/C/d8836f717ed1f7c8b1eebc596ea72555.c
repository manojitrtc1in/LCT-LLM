#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 128
#define MODULO 1000000007
#define INF (INT_MAX / 3)
#define MULTIPLIER 50

typedef struct {
    int x, y;
} Point;

typedef struct {
    int side, ones, twos;
} Triple;

long add(long a, long b) { return (a + b) % MODULO; }
long mult(long a, long b) { return (a * b) % MODULO; }

long binpow(long base, long power) {
    if (power == 0) return 1;
    if (power % 2 == 0) {
        long half = binpow(base, power / 2);
        return mult(half, half);
    } else {
        return mult(base, binpow(base, power - 1));
    }
}

long inverse(long x) {
    return binpow(x, MODULO - 2);
}

void swap(int *array, int i, int j) {
    if (i != j) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

void readIntArray(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }
}

Point getAnswer(int n, int *a, int limit) {
    limit /= MULTIPLIER;

    for (int i = 0; i < n; ++i) a[i] /= MULTIPLIER;

    int onesCount = 0, twosCount = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) ++onesCount;
        else ++twosCount;
    }

    long c[n + 1][n + 1];
    for (int i = 0; i <= n; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
        }
    }

    int distances[2][onesCount + 1][twosCount + 1];
    long ways[2][onesCount + 1][twosCount + 1];
    memset(distances, INF, sizeof(distances));
    memset(ways, 0, sizeof(ways));

    distances[0][onesCount][twosCount] = 0;
    ways[0][onesCount][twosCount] = 1;

    Triple q[MAX_STACK_SIZE];
    int front = 0, rear = 0;
    q[rear++] = (Triple){0, onesCount, twosCount};

    while (front < rear) {
        Triple from = q[front++];

        int fromDistance = distances[from.side][from.ones][from.twos];
        long fromWays = ways[from.side][from.ones][from.twos];
        int fromNextDistance = fromDistance + 1;

        int nextSide = 1 - from.side;

        if (from.side == 0) {
            for (int deltaOnes = 0; deltaOnes <= from.ones; ++deltaOnes) {
                for (int deltaTwos = 0; deltaTwos <= from.twos; ++deltaTwos) {
                    if (deltaOnes + deltaTwos == 0) continue;
                    if (deltaOnes + 2 * deltaTwos > limit) continue;

                    int nextOnes = from.ones - deltaOnes;
                    int nextTwos = from.twos - deltaTwos;

                    int nextDistance = distances[nextSide][nextOnes][nextTwos];

                    if (nextDistance < fromNextDistance) continue;

                    long fromNextWays = mult(fromWays, mult(c[from.ones][deltaOnes], c[from.twos][deltaTwos]));

                    if (nextDistance > fromNextDistance) {
                        nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance;
                        q[rear++] = (Triple){nextSide, nextOnes, nextTwos};
                    }

                    if (nextDistance == fromNextDistance) {
                        ways[nextSide][nextOnes][nextTwos] = add(ways[nextSide][nextOnes][nextTwos], fromNextWays);
                    }
                }
            }
        } else {
            int toOnes = onesCount - from.ones;
            int toTwos = twosCount - from.twos;

            for (int deltaOnes = 0; deltaOnes <= toOnes; ++deltaOnes) {
                for (int deltaTwos = 0; deltaTwos <= toTwos; ++deltaTwos) {
                    if (deltaOnes + deltaTwos == 0) continue;
                    if (deltaOnes + 2 * deltaTwos > limit) continue;

                    int nextOnes = from.ones + deltaOnes;
                    int nextTwos = from.twos + deltaTwos;

                    int nextDistance = distances[nextSide][nextOnes][nextTwos];

                    if (nextDistance < fromNextDistance) continue;

                    long fromNextWays = mult(fromWays, mult(c[toOnes][deltaOnes], c[toTwos][deltaTwos]));

                    if (nextDistance > fromNextDistance) {
                        nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance;
                        q[rear++] = (Triple){nextSide, nextOnes, nextTwos};
                    }

                    if (nextDistance == fromNextDistance) {
                        ways[nextSide][nextOnes][nextTwos] = add(ways[nextSide][nextOnes][nextTwos], fromNextWays);
                    }
                }
            }
        }
    }

    int distance = distances[1][0][0];
    if (INF == distance) {
        return (Point){-1, 0};
    } else {
        return (Point){distance, (int)ways[1][0][0]};
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    readIntArray(a, n);

    Point answer = getAnswer(n, a, k);

    printf("%d\n", answer.x);
    printf("%d\n", answer.y);

    return 0;
}
