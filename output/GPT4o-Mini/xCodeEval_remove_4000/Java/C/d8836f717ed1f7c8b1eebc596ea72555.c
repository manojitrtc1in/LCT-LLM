#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MODULO 1000000007
#define INF (INT_MAX / 3)

typedef struct {
    int x, y;
} Point;

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

void swap(int* array, int i, int j) {
    if (i != j) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

int* readArray(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        array[i] = readInt();
    }
    return array;
}

Point getAnswer(int n, int* a, int limit) {
    limit /= 50;

    for (int i = 0; i < n; ++i) a[i] /= 50;

    int onesCount = 0, id33 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) ++onesCount;
        else ++id33;
    }

    long c[n + 1][n + 1];
    for (int i = 0; i <= n; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
        }
    }

    int distances[2][onesCount + 1][id33 + 1];
    long ways[2][onesCount + 1][id33 + 1];

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= onesCount; ++j) {
            for (int k = 0; k <= id33; ++k) {
                distances[i][j][k] = INF;
                ways[i][j][k] = 0;
            }
        }
    }

    distances[0][onesCount][id33] = 0;
    ways[0][onesCount][id33] = 1;

    typedef struct {
        int side, ones, twos;
    } Triple;

    Triple queue[100000];
    int front = 0, rear = 0;
    queue[rear++] = (Triple){0, onesCount, id33};

    while (front < rear) {
        Triple from = queue[front++];

        int fromDistance = distances[from.side][from.ones][from.twos];
        long fromWays = ways[from.side][from.ones][from.twos];
        int id39 = fromDistance + 1;

        int nextSide = 1 - from.side;

        if (from.side == 0) {
            for (int id44 = 0; id44 <= from.ones; ++id44) {
                for (int id45 = 0; id45 <= from.twos; ++id45) {
                    if (id44 + id45 == 0) continue;
                    if (id44 + 2 * id45 > limit) continue;

                    int id24 = from.ones - id44;
                    int id32 = from.twos - id45;

                    int nextDistance = distances[nextSide][id24][id32];

                    if (nextDistance < id39) continue;

                    long id23 = mult(fromWays, mult(c[from.ones][id44], c[from.twos][id45]));

                    if (nextDistance > id39) {
                        nextDistance = distances[nextSide][id24][id32] = id39;
                        queue[rear++] = (Triple){nextSide, id24, id32};
                    }

                    if (nextDistance == id39) {
                        ways[nextSide][id24][id32] = add(ways[nextSide][id24][id32], id23);
                    }
                }
            }
        } else {
            int id34 = onesCount - from.ones;
            int id12 = id33 - from.twos;

            for (int id44 = 0; id44 <= id34; ++id44) {
                for (int id45 = 0; id45 <= id12; ++id45) {
                    if (id44 + id45 == 0) continue;
                    if (id44 + 2 * id45 > limit) continue;

                    int id24 = from.ones + id44;
                    int id32 = from.twos + id45;

                    int nextDistance = distances[nextSide][id24][id32];

                    if (nextDistance < id39) continue;

                    long id23 = mult(fromWays, mult(c[id34][id44], c[id12][id45]));

                    if (nextDistance > id39) {
                        nextDistance = distances[nextSide][id24][id32] = id39;
                        queue[rear++] = (Triple){nextSide, id24, id32};
                    }

                    if (nextDistance == id39) {
                        ways[nextSide][id24][id32] = add(ways[nextSide][id24][id32], id23);
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

void solve() {
    int n = readInt(), k = readInt();
    int* a = readArray(n);

    Point answer = getAnswer(n, a, k);

    printf("%d\n", answer.x);
    printf("%d\n", answer.y);

    free(a);
}

int main() {
    solve();
    return 0;
}
