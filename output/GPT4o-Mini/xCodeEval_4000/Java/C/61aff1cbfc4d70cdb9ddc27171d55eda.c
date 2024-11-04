#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MODULO 1000000007
#define MAX_RND 10
#define MAX_STACK_SIZE 128

typedef struct {
    long long answer;
    long long firstOptimal;
    long long secondOptimal;
} Result;

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

long long* getAnswer(long long need, long long maxTime, long long freeDefaultTime,
                     long long firstDefaultSize, long long firstDefaultTime, long long firstDefaultCost,
                     long long secondDefaultSize, long long secondDefaultTime, long long secondDefaultCost) {
    long long answer = LLONG_MAX;
    long long firstOptimal = 0, secondOptimal = 0;

    for (long long firstCount = 0, firstSize = 0, firstTime = 0, firstCost = 0; ; 
         ++firstCount, firstSize += firstDefaultSize, firstCost += firstDefaultCost,
         firstTime += firstDefaultTime * firstDefaultSize) {

        if (firstSize >= need) {
            firstSize = need;
            firstTime = firstDefaultTime * firstSize;
        }

        long long canUseTime = maxTime - firstTime;
        long long needUseSize = need - firstSize;
        if (canUseTime >= 0) {
            if (freeDefaultTime <= secondDefaultTime) {
                long long freeTime = freeDefaultTime * needUseSize;
                if (freeTime + firstTime <= maxTime) {
                    if (answer > firstCost) {
                        answer = firstCost;
                        firstOptimal = firstCount;
                        secondOptimal = 0;
                    }
                }
            } else {
                long long lowerSideCount = needUseSize / secondDefaultSize;
                long long lowerSecondSize = secondDefaultSize * lowerSideCount;
                long long lowerFreeSize = needUseSize - lowerSecondSize;

                long long lowerSecondTime = lowerSecondSize * secondDefaultTime;
                long long lowerFreeTime = lowerFreeSize * freeDefaultTime;

                if (lowerSecondTime + lowerFreeTime <= canUseTime) {
                    if (answer > firstCost + lowerSideCount * secondDefaultCost) {
                        answer = firstCost + lowerSideCount * secondDefaultCost;
                        firstOptimal = firstCount;
                        secondOptimal = lowerSideCount;
                    }
                }

                long long upperSideCount = needUseSize / secondDefaultSize;
                if (needUseSize % secondDefaultSize != 0) ++upperSideCount;
                long long upperSecondSize = min(needUseSize, secondDefaultSize * upperSideCount);
                long long upperFreeSize = needUseSize - upperSecondSize;

                long long upperSecondTime = upperSecondSize * secondDefaultTime;
                long long upperFreeTime = upperFreeSize * freeDefaultTime;

                if (upperSecondTime + upperFreeTime <= canUseTime) {
                    if (answer > firstCost + upperSideCount * secondDefaultCost) {
                        answer = firstCost + upperSideCount * secondDefaultCost;
                        firstOptimal = firstCount;
                        secondOptimal = upperSideCount;
                    }

                    long long exactNumerator = (needUseSize * freeDefaultTime - canUseTime);
                    long long exactDenominator = (freeDefaultTime - secondDefaultTime) * secondDefaultSize;

                    long long exactSideCount = exactNumerator / exactDenominator;
                    if (exactNumerator < 0) exactSideCount = 0;
                    else if (exactNumerator % exactDenominator != 0) {
                        exactSideCount++;
                    }
                    if (exactSideCount >= 0) {
                        long long exactSecondSize = min(needUseSize, secondDefaultSize * exactSideCount);
                        long long exactFreeSize = needUseSize - exactSecondSize;

                        long long exactSecondTime = exactSecondSize * secondDefaultTime;
                        long long exactFreeTime = exactFreeSize * freeDefaultTime;

                        if (exactSecondTime + exactFreeTime <= canUseTime) {
                            if (answer > firstCost + exactSideCount * secondDefaultCost) {
                                answer = firstCost + exactSideCount * secondDefaultCost;
                                firstOptimal = firstCount;
                                secondOptimal = exactSideCount;
                            }
                        }
                    }
                }
            }
        }

        if (firstSize >= need) break;
    }

    for (long long secondCount = 0, secondSize = 0, secondCost = 0, secondTime = 0; ;
         ++secondCount, secondSize += secondDefaultSize, secondCost += secondDefaultCost,
         secondTime += secondDefaultTime * secondDefaultSize) {

        if (secondSize >= need) {
            secondSize = need;
            secondTime = secondDefaultTime * secondSize;
        }

        long long canUseTime = maxTime - secondTime;
        long long needUseSize = need - secondSize;
        if (canUseTime >= 0) {
            if (freeDefaultTime <= firstDefaultTime) {
                long long freeTime = freeDefaultTime * needUseSize;
                if (freeTime + secondTime <= maxTime) {
                    if (answer > secondCost) {
                        answer = secondCost;
                        secondOptimal = secondCount;
                        firstOptimal = 0;
                    }
                }
            } else {
                long long lowerSideCount = needUseSize / firstDefaultSize;
                long long lowerfirstSize = firstDefaultSize * lowerSideCount;
                long long lowerFreeSize = needUseSize - lowerfirstSize;

                long long lowerfirstTime = lowerfirstSize * firstDefaultTime;
                long long lowerFreeTime = lowerFreeSize * freeDefaultTime;

                if (lowerfirstTime + lowerFreeTime <= canUseTime) {
                    if (answer > secondCost + lowerSideCount * firstDefaultCost) {
                        answer = secondCost + lowerSideCount * firstDefaultCost;
                        secondOptimal = secondCount;
                        firstOptimal = lowerSideCount;
                    }
                }

                long long upperSideCount = needUseSize / firstDefaultSize;
                if (needUseSize % firstDefaultSize != 0) ++upperSideCount;
                long long upperfirstSize = min(needUseSize, firstDefaultSize * upperSideCount);
                long long upperFreeSize = needUseSize - upperfirstSize;

                long long upperfirstTime = upperfirstSize * firstDefaultTime;
                long long upperFreeTime = upperFreeSize * freeDefaultTime;

                if (upperfirstTime + upperFreeTime <= canUseTime) {
                    if (answer > secondCost + upperSideCount * firstDefaultCost) {
                        answer = secondCost + upperSideCount * firstDefaultCost;
                        secondOptimal = secondCount;
                        firstOptimal = upperSideCount;
                    }

                    long long exactNumerator = (needUseSize * freeDefaultTime - canUseTime);
                    long long exactDenominator = (freeDefaultTime - firstDefaultTime) * firstDefaultSize;

                    long long exactSideCount = exactNumerator / exactDenominator;
                    if (exactNumerator < 0) exactSideCount = 0;
                    else if (exactNumerator % exactDenominator != 0) {
                        exactSideCount++;
                    }
                    if (exactSideCount >= 0) {
                        long long exactfirstSize = min(needUseSize, firstDefaultSize * exactSideCount);
                        long long exactFreeSize = needUseSize - exactfirstSize;

                        long long exactfirstTime = exactfirstSize * firstDefaultTime;
                        long long exactFreeTime = exactFreeSize * freeDefaultTime;

                        if (exactfirstTime + exactFreeTime <= canUseTime) {
                            if (answer > secondCost + exactSideCount * firstDefaultCost) {
                                answer = secondCost + exactSideCount * firstDefaultCost;
                                secondOptimal = secondCount;
                                firstOptimal = exactSideCount;
                            }
                        }
                    }
                }
            }
        }

        if (secondSize >= need) break;
    }

    if (answer == LLONG_MAX) {
        answer = -1;
    }

    long long* result = (long long*)malloc(3 * sizeof(long long));
    result[0] = answer;
    result[1] = firstOptimal;
    result[2] = secondOptimal;
    return result;
}

long long* getBruteAnswer(int need, long long maxTime, long long freeDefaultTime,
                           int firstDefaultSize, long long firstDefaultTime, long long firstDefaultCost,
                           int secondDefaultSize, long long secondDefaultTime, long long secondDefaultCost) {
    long long answer = LLONG_MAX;
    long long firstOptimal = 0, secondOptimal = 0;

    for (int firstCount = 0; ; ++firstCount) {
        int firstSize = min(need, firstCount * firstDefaultSize);
        if (firstSize >= need) firstSize = need;

        long long firstTime = firstSize * firstDefaultTime;
        long long firstCost = firstCount * firstDefaultCost;

        int needUseSize = (need - firstSize);
        for (int secondCount = 0; ; ++secondCount) {
            int secondSize = min(needUseSize, secondCount * secondDefaultSize);
            if (secondSize >= needUseSize) secondSize = needUseSize;

            long long secondTime = secondSize * secondDefaultTime;
            long long secondCost = secondCount * secondDefaultCost;

            int freeSize = needUseSize - secondSize;
            long long freeTime = freeSize * freeDefaultTime;

            if (firstTime + secondTime + freeTime <= maxTime) {
                if (answer > firstCost + secondCost) {
                    answer = firstCost + secondCost;
                    firstOptimal = firstCount;
                    secondOptimal = secondCount;
                }
            }

            if (secondSize >= needUseSize) break;
        }

        if (firstSize >= need) break;
    }

    if (answer == LLONG_MAX) {
        answer = -1;
    }

    long long* result = (long long*)malloc(3 * sizeof(long long));
    result[0] = answer;
    result[1] = firstOptimal;
    result[2] = secondOptimal;
    return result;
}

int main() {
    srand(time(NULL));
    for (int it = 0; it < 10; ++it) {
        int need = rand() % 10000 + 1;
        long long maxTime = rand() % 10000000 + 1;
        long long freeDefaultTime = rand() % 10 + 1;

        int firstDefaultSize = rand() % 100 + 1;
        long long firstDefaultTime = rand() % 10 + 1;
        long long firstDefaultCost = rand() % 10 + 1;

        int secondDefaultSize = rand() % 100 + 1;
        long long secondDefaultTime = rand() % 10 + 1;
        long long secondDefaultCost = rand() % 10 + 1;

        long long* answer = getAnswer(need, maxTime, freeDefaultTime,
                                       firstDefaultSize, firstDefaultTime, firstDefaultCost,
                                       secondDefaultSize, secondDefaultTime, secondDefaultCost);

        long long* bruteAnswer = getBruteAnswer(need, maxTime, freeDefaultTime,
                                                 firstDefaultSize, firstDefaultTime, firstDefaultCost,
                                                 secondDefaultSize, secondDefaultTime, secondDefaultCost);

        if (answer[0] != bruteAnswer[0]) {
            fprintf(stderr, "GOTCHA\n");
            fprintf(stderr, "%lld %lld %lld\n", answer[0], bruteAnswer[0], need);
            fprintf(stderr, "%d %lld %lld\n", firstDefaultSize, firstDefaultTime, firstDefaultCost);
            fprintf(stderr, "%d %lld %lld\n", secondDefaultSize, secondDefaultTime, secondDefaultCost);
        }

        free(answer);
        free(bruteAnswer);
    }

    return 0;
}
