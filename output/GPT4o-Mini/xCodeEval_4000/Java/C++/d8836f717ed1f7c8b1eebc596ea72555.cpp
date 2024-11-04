#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <random>
#include <cmath>
#include <limits>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

const long long MODULO = 1000 * 1000 * 1000 + 7;
const int MAX_STACK_SIZE = 128;
const int INF = numeric_limits<int>::max() / 3;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class C {
private:
    bool ONLINE_JUDGE = !ifstream("input.txt");
    static const int MULTIPLIER = 50;

    void solve() {
        int n = readInt(), k = readInt();
        vector<int> a = readIntArray(n);

        Point answer = getAnswer(n, a, k);

        cout << answer.x << endl;
        cout << answer.y << endl;
    }

    Point getAnswer(int n, vector<int>& a, int limit) {
        limit /= MULTIPLIER;

        for (int& v : a) v /= MULTIPLIER;

        int onesCount = 0, twosCount = 0;
        for (int v : a) {
            if (v == 1) ++onesCount;
            else ++twosCount;
        }

        vector<vector<long long>> c(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MODULO;
            }
        }

        int distances[2][onesCount + 1][twosCount + 1];
        long long ways[2][onesCount + 1][twosCount + 1];
        memset(distances, INF, sizeof(distances));
        memset(ways, 0, sizeof(ways));

        distances[0][onesCount][twosCount] = 0;
        ways[0][onesCount][twosCount] = 1;

        struct Triple {
            int side, ones, twos;
            Triple(int side, int ones, int twos) : side(side), ones(ones), twos(twos) {}
        };

        queue<Triple> q;
        q.push(Triple(0, onesCount, twosCount));

        while (!q.empty()) {
            Triple from = q.front();
            q.pop();

            int fromDistance = distances[from.side][from.ones][from.twos];
            long long fromWays = ways[from.side][from.ones][from.twos];
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

                        long long fromNextWays = (fromWays * c[from.ones][deltaOnes] % MODULO * c[from.twos][deltaTwos] % MODULO) % MODULO;

                        if (nextDistance > fromNextDistance) {
                            nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance;
                            q.push(Triple(nextSide, nextOnes, nextTwos));
                        }

                        if (nextDistance == fromNextDistance) {
                            ways[nextSide][nextOnes][nextTwos] = (ways[nextSide][nextOnes][nextTwos] + fromNextWays) % MODULO;
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

                        long long fromNextWays = (fromWays * c[toOnes][deltaOnes] % MODULO * c[toTwos][deltaTwos] % MODULO) % MODULO;

                        if (nextDistance > fromNextDistance) {
                            nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance;
                            q.push(Triple(nextSide, nextOnes, nextTwos));
                        }

                        if (nextDistance == fromNextDistance) {
                            ways[nextSide][nextOnes][nextTwos] = (ways[nextSide][nextOnes][nextTwos] + fromNextWays) % MODULO;
                        }
                    }
                }
            }
        }

        int distance = distances[1][0][0];
        if (INF == distance) {
            return Point(-1, 0);
        } else {
            return Point(distance, (int)ways[1][0][0]);
        }
    }

    int readInt() {
        int x;
        cin >> x;
        return x;
    }

    vector<int> readIntArray(int size) {
        vector<int> array(size);
        for (int& value : array) {
            value = readInt();
        }
        return array;
    }

public:
    void run() {
        try {
            if (ONLINE_JUDGE) {
                solve();
            } else {
                do {
                    try {
                        solve();
                    } catch (EOFException&) {
                        break;
                    }
                } while (true);
            }
        } catch (exception& e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }

    static void main() {
        C c;
        c.run();
    }
};

int main() {
    C::main();
    return 0;
}
