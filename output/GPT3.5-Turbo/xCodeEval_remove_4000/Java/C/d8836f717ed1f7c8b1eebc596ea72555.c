#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MODULO (1000 * 1000 * 1000 + 7)

typedef struct {
    int x;
    int y;
} Point;

int n, k;
int a[MAX_SIZE];

long long binpow(long long base, long long power) {
    if (power == 0) return 1;
    if ((power & 1) == 0) {
        long long half = binpow(base, power >> 1);
        return (half * half) % MODULO;
    } else {
        long long prev = binpow(base, power - 1);
        return (prev * base) % MODULO;
    }
}

long long add(long long a, long long b) {
    return (a + b) % MODULO;
}

Point getAnswer(int n, int a[], int limit) {
    const int id22 = 50;

    limit /= id22;

    for (int i = 0; i < n; ++i) a[i] /= id22;

    int onesCount = 0, id33 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) ++onesCount;
        else ++id33;
    }

    long long c[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i <= n; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
        }
    }

    const int FROM_SIDE = 0, TO_SIDE = 1;
    const int INF = INT_MAX / 3;

    int distances[2][MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= onesCount; ++j) {
            for (int k = 0; k <= id33; ++k) {
                distances[i][j][k] = INF;
            }
        }
    }

    long long ways[2][MAX_SIZE][MAX_SIZE];

    distances[FROM_SIDE][onesCount][id33] = 0;
    ways[FROM_SIDE][onesCount][id33] = 1;

    typedef struct {
        int side, ones, twos;
    } Triple;

    Triple q[MAX_SIZE];
    int front = 0, rear = 0;
    q[rear++] = (Triple) {FROM_SIDE, onesCount, id33};

    while (front < rear) {
        Triple from = q[front++];

        int fromDistance = distances[from.side][from.ones][from.twos];
        long long fromWays = ways[from.side][from.ones][from.twos];
        int id39 = fromDistance + 1;

        int nextSide = FROM_SIDE + TO_SIDE - from.side;

        if (from.side == FROM_SIDE) {
            for (int id44 = 0; id44 <= from.ones; ++id44) {
                for (int id45 = 0; id45 <= from.twos; ++id45) {
                    if (id44 + id45 == 0) continue;
                    if (id44 + 2 * id45 > limit) continue;

                    int id24 = from.ones - id44;
                    int id32 = from.twos - id45;

                    int nextDistance = distances[nextSide][id24][id32];

                    if (nextDistance < id39) continue;

                    long long id23 = (fromWays * c[from.ones][id44] % MODULO) * c[from.twos][id45] % MODULO;

                    if (nextDistance > id39) {
                        nextDistance = distances[nextSide][id24][id32] = id39;
                        q[rear++] = (Triple) {nextSide, id24, id32};
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

                    long long id23 = (fromWays * c[id34][id44] % MODULO) * c[id12][id45] % MODULO;

                    if (nextDistance > id39) {
                        nextDistance = distances[nextSide][id24][id32] = id39;
                        q[rear++] = (Triple) {nextSide, id24, id32};
                    }

                    if (nextDistance == id39) {
                        ways[nextSide][id24][id32] = add(ways[nextSide][id24][id32], id23);
                    }
                }
            }
        }
    }

    int distance = distances[TO_SIDE][0][0];
    if (INF == distance) {
        return (Point) {-1, 0};
    } else {
        return (Point) {distance, (int) ways[TO_SIDE][0][0]};
    }
}

void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    Point answer = getAnswer(n, a, k);

    printf("%d\n", answer.x);
    printf("%d\n", answer.y);
}

int main() {
    solve();

    return 0;
}
