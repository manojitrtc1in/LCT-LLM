#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define MODULO 1000000007
#define MAX_SIZE 10000

typedef struct {
    long answer;
    long firstOptimal;
    long secondOptimal;
} Result;

long max(long a, long b) { return (a > b) ? a : b; }
long min(long a, long b) { return (a < b) ? a : b; }

long* getAnswer(long need, long maxTime, long id45, long id43, long id16, long id77, long id7, long id90, long id51) {
    long* result = malloc(3 * sizeof(long));
    long answer = LONG_MAX;
    long firstOptimal = 0, secondOptimal = 0;

    for (long firstCount = 0, firstSize = 0, firstTime = 0, firstCost = 0; ; ++firstCount, firstSize += id43, firstCost += id77, firstTime += id16 * id43) {
        if (firstSize >= need) {
            firstSize = need;
            firstTime = id16 * firstSize;
        }

        long id42 = maxTime - firstTime;
        long id74 = need - firstSize;
        if (id42 >= 0) {
            if (id45 <= id90) {
                long freeTime = id45 * id74;
                if (freeTime + firstTime <= maxTime) {
                    if (answer > firstCost) {
                        answer = firstCost;
                        firstOptimal = firstCount;
                        secondOptimal = 0;
                    }
                }
            } else {
                long id68 = id74 / id7;
                long id63 = id7 * id68;
                long id50 = id74 - id63;

                long id81 = id63 * id90;
                long id15 = id50 * id45;

                if (id81 + id15 <= id42) {
                    if (answer > firstCost + id68 * id51) {
                        answer = firstCost + id68 * id51;
                        firstOptimal = firstCount;
                        secondOptimal = id68;
                    }
                }

                long id41 = id74 / id7;
                if (id74 % id7 != 0) ++id41;
                long id80 = min(id74, id7 * id41);
                long id21 = id74 - id80;

                long id97 = id80 * id90;
                long id98 = id21 * id45;

                if (id97 + id98 <= id42) {
                    if (answer > firstCost + id41 * id51) {
                        answer = firstCost + id41 * id51;
                        firstOptimal = firstCount;
                        secondOptimal = id41;
                    }

                    long id31 = ((id74 * id45 - id42));
                    long id96 = (id45 - id90) * id7;

                    long id14 = id31 / id96;
                    if (id31 < 0) id14 = 0;
                    else if (id31 % id96 != 0) {
                        id14++;
                    }
                    if (id14 >= 0) {
                        long id29 = min(id74, id7 * id14);
                        long id38 = id74 - id29;

                        long id48 = id29 * id90;
                        long id70 = id38 * id45;

                        if (id48 + id70 <= id42) {
                            if (answer > firstCost + id14 * id51) {
                                answer = firstCost + id14 * id51;
                                firstOptimal = firstCount;
                                secondOptimal = id14;
                            }
                        }
                    }
                }
            }
        }

        if (firstSize >= need) break;
    }

    for (long secondCount = 0, secondSize = 0, secondCost = 0, secondTime = 0; ; ++secondCount, secondSize += id7, secondCost += id51, secondTime += id90 * id7) {
        if (secondSize >= need) {
            secondSize = need;
            secondTime = id90 * secondSize;
        }

        long id42 = maxTime - secondTime;
        long id74 = need - secondSize;
        if (id42 >= 0) {
            if (id45 <= id16) {
                long freeTime = id45 * id74;
                if (freeTime + secondTime <= maxTime) {
                    if (answer > secondCost) {
                        answer = secondCost;
                        secondOptimal = secondCount;
                        firstOptimal = 0;
                    }
                }
            } else {
                long id68 = id74 / id43;
                long id79 = id43 * id68;
                long id50 = id74 - id79;

                long id23 = id79 * id16;
                long id15 = id50 * id45;

                if (id23 + id15 <= id42) {
                    if (answer > secondCost + id68 * id77) {
                        answer = secondCost + id68 * id77;
                        secondOptimal = secondCount;
                        firstOptimal = id68;
                    }
                }

                long id41 = id74 / id43;
                if (id74 % id43 != 0) ++id41;
                long id39 = min(id74, id43 * id41);
                long id21 = id74 - id39;

                long id83 = id39 * id16;
                long id98 = id21 * id45;

                if (id83 + id98 <= id42) {
                    if (answer > secondCost + id41 * id77) {
                        answer = secondCost + id41 * id77;
                        secondOptimal = secondCount;
                        firstOptimal = id41;
                    }

                    long id31 = ((id74 * id45 - id42));
                    long id96 = (id45 - id16) * id43;

                    long id14 = id31 / id96;
                    if (id31 < 0) id14 = 0;
                    else if (id31 % id96 != 0) {
                        id14++;
                    }
                    if (id14 >= 0) {
                        long id86 = min(id74, id43 * id14);
                        long id38 = id74 - id86;

                        long id92 = id86 * id16;
                        long id70 = id38 * id45;

                        if (id92 + id70 <= id42) {
                            if (answer > secondCost + id14 * id77) {
                                answer = secondCost + id14 * id77;
                                secondOptimal = secondCount;
                                firstOptimal = id14;
                            }
                        }
                    }
                }
            }
        }

        if (secondSize >= need) break;
    }

    if (answer == LONG_MAX) {
        answer = -1;
    }

    result[0] = answer;
    result[1] = firstOptimal;
    result[2] = secondOptimal;
    return result;
}

long* id52(int need, long maxTime, long id45, int id43, long id16, long id77, int id7, long id90, long id51) {
    long* result = malloc(3 * sizeof(long));
    long answer = LONG_MAX;
    long firstOptimal = 0, secondOptimal = 0;

    for (int firstCount = 0; ; ++firstCount) {
        int firstSize = min(need, firstCount * id43);
        if (firstSize >= need) firstSize = need;

        long firstTime = firstSize * id16;
        long firstCost = firstCount * id77;

        int id74 = (need - firstSize);
        for (int secondCount = 0; ; ++secondCount) {
            int secondSize = min(id74, secondCount * id7);
            if (secondSize >= id74) secondSize = id74;

            long secondTime = secondSize * id90;
            long secondCost = secondCount * id51;

            int freeSize = id74 - secondSize;
            long freeTime = freeSize * id45;

            if (firstTime + secondTime + freeTime <= maxTime) {
                if (answer > firstCost + secondCost) {
                    answer = firstCost + secondCost;
                    firstOptimal = firstCount;
                    secondOptimal = secondCount;
                }
            }

            if (secondSize >= id74) break;
        }

        if (firstSize >= need) break;
    }

    if (answer == LONG_MAX) {
        answer = -1;
    }

    result[0] = answer;
    result[1] = firstOptimal;
    result[2] = secondOptimal;
    return result;
}

void solve() {
    long need, maxTime, id45;
    long id43, id16, id77;
    long id7, id90, id51;

    scanf("%ld %ld %ld", &need, &maxTime, &id45);
    scanf("%ld %ld %ld", &id43, &id16, &id77);
    scanf("%ld %ld %ld", &id7, &id90, &id51);

    long* answer = getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51);
    printf("%ld\n", answer[0]);
    free(answer);
}

void timeInit(clock_t* start) {
    *start = clock();
}

void time(clock_t start) {
    clock_t end = clock();
    printf("Time = %ld\n", (end - start) * 1000 / CLOCKS_PER_SEC);
}

int main() {
    clock_t start;
    timeInit(&start);
    solve();
    time(start);
    return 0;
}
