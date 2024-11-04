#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

const long long MODULO = 1000000007;
const int id69 = 10;

class C {
private:
    static random_device rd;
    static mt19937 rnd;

    void solve1() {
        for (int it = 0; it < 10; ++it) {
            int need = rnd() % 10000 + 1;
            long long maxTime = rnd() % 10000000 + 1;
            long long id45 = rnd() % 10 + 1;

            int id43 = rnd() % 100 + 1;
            long long id16 = rnd() % 10 + 1;
            long long id77 = rnd() % 10 + 1;

            int id7 = rnd() % 100 + 1;
            long long id90 = rnd() % 10 + 1;
            long long id51 = rnd() % 10 + 1;

            auto answer = getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51);
            auto id59 = id52(need, maxTime, id45, id43, id16, id77, id7, id90, id51);

            if (answer[0] != id59[0]) {
                cerr << "GOTCHA" << endl;
                cerr << answer[0] << " " << id59[0] << endl;
                cerr << need << " " << maxTime << " " << id16 << endl;
                cerr << id43 << " " << id16 << " " << id77 << endl;
                cerr << id7 << " " << id90 << " " << id51 << endl;
            }
        }
    }

    void solve() {
        long long need, maxTime, id45, id43, id16, id77, id7, id90, id51;
        cin >> need >> maxTime >> id45 >> id43 >> id16 >> id77 >> id7 >> id90 >> id51;

        auto answer = getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51);
        cout << answer[0] << endl;
    }

    vector<long long> getAnswer(long long need, long long maxTime, long long id45,
                                 long long id43, long long id16, long long id77,
                                 long long id7, long long id90, long long id51) {
        long long answer = LLONG_MAX;
        long long firstOptimal = 0, secondOptimal = 0;

        for (long long firstCount = 0, firstSize = 0, firstTime = 0, firstCost = 0; ; ++firstCount, firstSize += id43, firstCost += id77, firstTime += id16 * id43) {
            if (firstSize >= need) {
                firstSize = need;
                firstTime = id16 * firstSize;
            }

            long long id42 = maxTime - firstTime;
            long long id74 = need - firstSize;
            if (id42 >= 0) {
                if (id45 <= id90) {
                    long long freeTime = id45 * id74;
                    if (freeTime + firstTime <= maxTime) {
                        if (answer > firstCost) {
                            answer = firstCost;
                            firstOptimal = firstCount;
                            secondOptimal = 0;
                        }
                    }
                } else {
                    long long id68 = id74 / id7;
                    long long id63 = id7 * id68;
                    long long id50 = id74 - id63;

                    long long id81 = id63 * id90;
                    long long id15 = id50 * id45;

                    if (id81 + id15 <= id42) {
                        if (answer > firstCost + id68 * id51) {
                            answer = firstCost + id68 * id51;
                            firstOptimal = firstCount;
                            secondOptimal = id68;
                        }
                    }

                    long long id41 = id74 / id7;
                    if (id74 % id7 != 0) ++id41;
                    long long id80 = min(id74, id7 * id41);
                    long long id21 = id74 - id80;

                    long long id97 = id80 * id90;
                    long long id98 = id21 * id45;

                    if (id97 + id98 <= id42) {
                        if (answer > firstCost + id41 * id51) {
                            answer = firstCost + id41 * id51;
                            firstOptimal = firstCount;
                            secondOptimal = id41;
                        }

                        long long id31 = ((id74 * id45 - id42));
                        long long id96 = (id45 - id90) * id7;

                        long long id14 = id31 / id96;
                        if (id31 < 0) id14 = 0;
                        else if (id31 % id96 != 0) {
                            id14++;
                        }
                        if (id14 >= 0) {
                            long long id29 = min(id74, id7 * id14);
                            long long id38 = id74 - id29;

                            long long id48 = id29 * id90;
                            long long id70 = id38 * id45;

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

        for (long long secondCount = 0, secondSize = 0, secondCost = 0, secondTime = 0; ; ++secondCount, secondSize += id7, secondCost += id51, secondTime += id90 * id7) {
            if (secondSize >= need) {
                secondSize = need;
                secondTime = id90 * secondSize;
            }

            long long id42 = maxTime - secondTime;
            long long id74 = need - secondSize;
            if (id42 >= 0) {
                if (id45 <= id16) {
                    long long freeTime = id45 * id74;
                    if (freeTime + secondTime <= maxTime) {
                        if (answer > secondCost) {
                            answer = secondCost;
                            secondOptimal = secondCount;
                            firstOptimal = 0;
                        }
                    }
                } else {
                    long long id68 = id74 / id43;
                    long long id79 = id43 * id68;
                    long long id50 = id74 - id79;

                    long long id23 = id79 * id16;
                    long long id15 = id50 * id45;

                    if (id23 + id15 <= id42) {
                        if (answer > secondCost + id68 * id77) {
                            answer = secondCost + id68 * id77;
                            secondOptimal = secondCount;
                            firstOptimal = id68;
                        }
                    }

                    long long id41 = id74 / id43;
                    if (id74 % id43 != 0) ++id41;
                    long long id39 = min(id74, id43 * id41);
                    long long id21 = id74 - id39;

                    long long id83 = id39 * id16;
                    long long id98 = id21 * id45;

                    if (id83 + id98 <= id42) {
                        if (answer > secondCost + id41 * id77) {
                            answer = secondCost + id41 * id77;
                            secondOptimal = secondCount;
                            firstOptimal = id41;
                        }

                        long long id31 = ((id74 * id45 - id42));
                        long long id96 = (id45 - id16) * id43;

                        long long id14 = id31 / id96;
                        if (id31 < 0) id14 = 0;
                        else if (id31 % id96 != 0) {
                            id14++;
                        }
                        if (id14 >= 0) {
                            long long id86 = min(id74, id43 * id14);
                            long long id38 = id74 - id86;

                            long long id92 = id86 * id16;
                            long long id70 = id38 * id45;

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

        if (answer == LLONG_MAX) {
            answer = -1;
        }

        return { answer, firstOptimal, secondOptimal };
    }

    vector<long long> id52(int need, long long maxTime, long long id45,
                            int id43, long long id16, long long id77,
                            int id7, long long id90, long long id51) {
        long long answer = LLONG_MAX;
        long long firstOptimal = 0, secondOptimal = 0;

        for (int firstCount = 0; ; ++firstCount) {
            int firstSize = min(need, firstCount * id43);
            if (firstSize >= need) firstSize = need;

            long long firstTime = firstSize * id16;
            long long firstCost = firstCount * id77;

            int id74 = (need - firstSize);
            for (int secondCount = 0; ; ++secondCount) {
                int secondSize = min(id74, secondCount * id7);
                if (secondSize >= id74) secondSize = id74;

                long long secondTime = secondSize * id90;
                long long secondCost = secondCount * id51;

                int freeSize = id74 - secondSize;
                long long freeTime = freeSize * id45;

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

        if (answer == LLONG_MAX) {
            answer = -1;
        }

        return { answer, firstOptimal, secondOptimal };
    }

    static long long add(long long a, long long b) { return (a + b) % MODULO; }
    static long long subtract(long long a, long long b) { return add(a, MODULO - b) % MODULO; }
    static long long mult(long long a, long long b) { return (a * b) % MODULO; }

public:
    void run() {
        try {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout << fixed << setprecision(10);

            solve();
        } catch (exception& e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }

    static void main() {
        C().run();
    }
};

random_device C::rd;
mt19937 C::rnd(C::rd());

int main() {
    C::main();
    return 0;
}
