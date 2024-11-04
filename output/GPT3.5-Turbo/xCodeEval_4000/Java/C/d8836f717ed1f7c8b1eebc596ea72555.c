#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_STACK_SIZE 128
#define MODULO 1000000007

typedef struct {
    int x;
    int y;
} Point;

int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int* readIntArray(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = readInt();
    }
    return array;
}

long long add(long long a, long long b) {
    return (a + b) % MODULO;
}

long long mult(long long a, long long b) {
    return (a * b) % MODULO;
}

Point getAnswer(int n, int* a, int limit) {
    const int MULTIPLIER = 50;

    limit /= MULTIPLIER;

    for (int i = 0; i < n; i++) {
        a[i] /= MULTIPLIER;
    }

    int onesCount = 0, twosCount = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) onesCount++;
        else twosCount++;
    }

    long long c[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
        }
    }

    const int FROM_SIDE = 0, TO_SIDE = 1;
    const int INF = INT_MAX / 3;

    int distances[2][onesCount + 1][twosCount + 1];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= onesCount; j++) {
            for (int k = 0; k <= twosCount; k++) {
                distances[i][j][k] = INF;
            }
        }
    }

    long long ways[2][onesCount + 1][twosCount + 1];

    distances[FROM_SIDE][onesCount][twosCount] = 0;
    ways[FROM_SIDE][onesCount][twosCount] = 1;

    typedef struct {
        int side;
        int ones;
        int twos;
    } Triple;

    Triple q[MAX_STACK_SIZE];
    int front = 0, rear = 0;
    q[rear++] = (Triple){FROM_SIDE, onesCount, twosCount};

    while (front < rear) {
        Triple from = q[front++];

        int fromDistance = distances[from.side][from.ones][from.twos];
        long long fromWays = ways[from.side][from.ones][from.twos];
        int fromNextDistance = fromDistance + 1;

        int nextSide = FROM_SIDE + TO_SIDE - from.side;

        if (from.side == FROM_SIDE) {
            for (int deltaOnes = 0; deltaOnes <= from.ones; deltaOnes++) {
                for (int deltaTwos = 0; deltaTwos <= from.twos; deltaTwos++) {
                    if (deltaOnes + deltaTwos == 0) continue;
                    if (deltaOnes + 2 * deltaTwos > limit) continue;

                    int nextOnes = from.ones - deltaOnes;
                    int nextTwos = from.twos - deltaTwos;

                    int nextDistance = distances[nextSide][nextOnes][nextTwos];

                    if (nextDistance < fromNextDistance) continue;

                    long long fromNextWays = mult(fromWays,
                        mult(c[from.ones][deltaOnes], c[from.twos][deltaTwos])
                    );

                    if (nextDistance > fromNextDistance) {
                        nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance;
                        q[rear++] = (Triple){nextSide, nextOnes, nextTwos};
                    }

                    if (nextDistance == fromNextDistance) {
                        ways[nextSide][nextOnes][nextTwos] = add(
                            ways[nextSide][nextOnes][nextTwos],
                            fromNextWays
                        );
                    }
                }
            }
        } else {
            int toOnes = onesCount - from.ones;
            int toTwos = twosCount - from.twos;

            for (int deltaOnes = 0; deltaOnes <= toOnes; deltaOnes++) {
                for (int deltaTwos = 0; deltaTwos <= toTwos; deltaTwos++) {
                    if (deltaOnes + deltaTwos == 0) continue;
                    if (deltaOnes + 2 * deltaTwos > limit) continue;

                    int nextOnes = from.ones + deltaOnes;
                    int nextTwos = from.twos + deltaTwos;

                    int nextDistance = distances[nextSide][nextOnes][nextTwos];

                    if (nextDistance < fromNextDistance) continue;

                    long long fromNextWays = mult(fromWays,
                        mult(c[toOnes][deltaOnes], c[toTwos][deltaTwos])
                    );

                    if (nextDistance > fromNextDistance) {
                        nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance;
                        q[rear++] = (Triple){nextSide, nextOnes, nextTwos};
                    }

                    if (nextDistance == fromNextDistance) {
                        ways[nextSide][nextOnes][nextTwos] = add(
                            ways[nextSide][nextOnes][nextTwos],
                            fromNextWays
                        );
                    }
                }
            }
        }
    }

    int distance = distances[TO_SIDE][0][0];
    if (INF == distance) {
        return (Point){-1, 0};
    } else {
        return (Point){distance, (int)ways[TO_SIDE][0][0]};
    }
}

void solve() {
    int n = readInt();
    int k = readInt();
    int* a = readIntArray(n);

    Point answer = getAnswer(n, a, k);

    printf("%d\n", answer.x);
    printf("%d\n", answer.y);
}

int main() {
    solve();
    return 0;
}
