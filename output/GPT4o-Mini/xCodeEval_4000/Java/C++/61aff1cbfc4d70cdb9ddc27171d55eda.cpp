#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <set>
#include <queue>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

class C {
private:
    static const long MODULO = 1000 * 1000 * 1000 + 7;
    static const int MAX_RND = 10;
    static random_device rd;
    static mt19937 rnd;

    long readLong() {
        long x;
        cin >> x;
        return x;
    }

    int readInt() {
        int x;
        cin >> x;
        return x;
    }

    long long getAnswer(long need, long maxTime, long freeDefaultTime,
                        long firstDefaultSize, long firstDefaultTime, long firstDefaultCost,
                        long secondDefaultSize, long secondDefaultTime, long secondDefaultCost) {
        long answer = numeric_limits<long>::max();
        long firstOptimal = 0, secondOptimal = 0;

        for (long firstCount = 0, firstSize = 0, firstTime = 0, firstCost = 0; ; 
             ++firstCount, firstSize += firstDefaultSize,
             firstCost += firstDefaultCost,
             firstTime += firstDefaultTime * firstDefaultSize) {

            if (firstSize >= need) {
                firstSize = need;
                firstTime = firstDefaultTime * firstSize;
            }

            long canUseTime = maxTime - firstTime;
            long needUseSize = need - firstSize;
            if (canUseTime >= 0) {
                if (freeDefaultTime <= secondDefaultTime) {
                    long freeTime = freeDefaultTime * needUseSize;
                    if (freeTime + firstTime <= maxTime) {
                        if (answer > firstCost) {
                            answer = firstCost;
                            firstOptimal = firstCount;
                            secondOptimal = 0;
                        }
                    }
                } else {
                    long lowerSideCount = needUseSize / secondDefaultSize;
                    long lowerSecondSize = secondDefaultSize * lowerSideCount;
                    long lowerFreeSize = needUseSize - lowerSecondSize;

                    long lowerSecondTime = lowerSecondSize * secondDefaultTime;
                    long lowerFreeTime = lowerFreeSize * freeDefaultTime;

                    if (lowerSecondTime + lowerFreeTime <= canUseTime) {
                        if (answer > firstCost + lowerSideCount * secondDefaultCost) {
                            answer = firstCost + lowerSideCount * secondDefaultCost;
                            firstOptimal = firstCount;
                            secondOptimal = lowerSideCount;
                        }
                    }

                    long upperSideCount = needUseSize / secondDefaultSize;
                    if (needUseSize % secondDefaultSize != 0) ++upperSideCount;
                    long upperSecondSize = min(needUseSize, secondDefaultSize * upperSideCount);
                    long upperFreeSize = needUseSize - upperSecondSize;

                    long upperSecondTime = upperSecondSize * secondDefaultTime;
                    long upperFreeTime = upperFreeSize * freeDefaultTime;

                    if (upperSecondTime + upperFreeTime <= canUseTime) {
                        if (answer > firstCost + upperSideCount * secondDefaultCost) {
                            answer = firstCost + upperSideCount * secondDefaultCost;
                            firstOptimal = firstCount;
                            secondOptimal = upperSideCount;
                        }

                        long exactNumerator = (needUseSize * freeDefaultTime - canUseTime);
                        long exactDenominator = (freeDefaultTime - secondDefaultTime) * secondDefaultSize;

                        long exactSideCount = exactNumerator / exactDenominator;
                        if (exactNumerator < 0) exactSideCount = 0;
                        else if (exactNumerator % exactDenominator != 0) {
                            exactSideCount++;
                        }
                        if (exactSideCount >= 0) {
                            long exactSecondSize = min(needUseSize, secondDefaultSize * exactSideCount);
                            long exactFreeSize = needUseSize - exactSecondSize;

                            long exactSecondTime = exactSecondSize * secondDefaultTime;
                            long exactFreeTime = exactFreeSize * freeDefaultTime;

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

        for (long secondCount = 0, secondSize = 0, secondCost = 0, secondTime = 0; ;
             ++secondCount, secondSize += secondDefaultSize,
             secondCost += secondDefaultCost,
             secondTime += secondDefaultTime * secondDefaultSize) {

            if (secondSize >= need) {
                secondSize = need;
                secondTime = secondDefaultTime * secondSize;
            }

            long canUseTime = maxTime - secondTime;
            long needUseSize = need - secondSize;
            if (canUseTime >= 0) {
                if (freeDefaultTime <= firstDefaultTime) {
                    long freeTime = freeDefaultTime * needUseSize;
                    if (freeTime + secondTime <= maxTime) {
                        if (answer > secondCost) {
                            answer = secondCost;
                            secondOptimal = secondCount;
                            firstOptimal = 0;
                        }
                    }
                } else {
                    long lowerSideCount = needUseSize / firstDefaultSize;
                    long lowerfirstSize = firstDefaultSize * lowerSideCount;
                    long lowerFreeSize = needUseSize - lowerfirstSize;

                    long lowerfirstTime = lowerfirstSize * firstDefaultTime;
                    long lowerFreeTime = lowerFreeSize * freeDefaultTime;

                    if (lowerfirstTime + lowerFreeTime <= canUseTime) {
                        if (answer > secondCost + lowerSideCount * firstDefaultCost) {
                            answer = secondCost + lowerSideCount * firstDefaultCost;
                            secondOptimal = secondCount;
                            firstOptimal = lowerSideCount;
                        }
                    }

                    long upperSideCount = needUseSize / firstDefaultSize;
                    if (needUseSize % firstDefaultSize != 0) ++upperSideCount;
                    long upperfirstSize = min(needUseSize, firstDefaultSize * upperSideCount);
                    long upperFreeSize = needUseSize - upperfirstSize;

                    long upperfirstTime = upperfirstSize * firstDefaultTime;
                    long upperFreeTime = upperFreeSize * freeDefaultTime;

                    if (upperfirstTime + upperFreeTime <= canUseTime) {
                        if (answer > secondCost + upperSideCount * firstDefaultCost) {
                            answer = secondCost + upperSideCount * firstDefaultCost;
                            secondOptimal = secondCount;
                            firstOptimal = upperSideCount;
                        }

                        long exactNumerator = (needUseSize * freeDefaultTime - canUseTime);
                        long exactDenominator = (freeDefaultTime - firstDefaultTime) * firstDefaultSize;

                        long exactSideCount = exactNumerator / exactDenominator;
                        if (exactNumerator < 0) exactSideCount = 0;
                        else if (exactNumerator % exactDenominator != 0) {
                            exactSideCount++;
                        }
                        if (exactSideCount >= 0) {
                            long exactfirstSize = min(needUseSize, firstDefaultSize * exactSideCount);
                            long exactFreeSize = needUseSize - exactfirstSize;

                            long exactfirstTime = exactfirstSize * firstDefaultTime;
                            long exactFreeTime = exactFreeSize * freeDefaultTime;

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

        if (answer == numeric_limits<long>::max()) {
            answer = -1;
        }

        return answer;
    }

    void solve() {
        long need = readLong();
        long maxTime = readLong();
        long freeDefaultTime = readLong();

        long firstDefaultSize = readLong();
        long firstDefaultTime = readLong();
        long firstDefaultCost = readLong();

        long secondDefaultSize = readLong();
        long secondDefaultTime = readLong();
        long secondDefaultCost = readLong();

        long answer = getAnswer(need, maxTime, freeDefaultTime,
                                firstDefaultSize, firstDefaultTime, firstDefaultCost,
                                secondDefaultSize, secondDefaultTime, secondDefaultCost);

        cout << answer << endl;
    }

public:
    void run() {
        try {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            solve();
        } catch (exception &e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }

    static void main() {
        C c;
        c.run();
    }
};

random_device C::rd;
mt19937 C::rnd(C::rd());

int main() {
    C::main();
    return 0;
}
