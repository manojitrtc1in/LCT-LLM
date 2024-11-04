#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <random>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

const long long MODULO = 1000000007;

class C {
private:
    static const bool id3 = false;
    static const bool id6 = true;
    static const bool id30 = false;
    static const int id17 = 128;
    static const int id22 = 50;

    bool id10;
    ifstream in;
    ofstream out;

    void init() {
        id10 = !ifstream("input.txt");
        if (id10) {
            in.open("input.txt");
            out.open("output.txt");
        } else {
            in.open("input.txt");
            out.open("output.txt");
        }
    }

    void solve() {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }

        auto answer = getAnswer(n, a, k);
        out << answer.first << endl;
        out << answer.second << endl;
    }

    pair<int, int> getAnswer(int n, vector<int>& a, int limit) {
        limit /= id22;

        for (int i = 0; i < n; ++i) {
            a[i] /= id22;
        }

        int onesCount = 0, id33 = 0;
        for (int v : a) {
            if (v == 1) ++onesCount;
            else ++id33;
        }

        vector<vector<long long>> c(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MODULO;
            }
        }

        const int FROM_SIDE = 0, TO_SIDE = 1;
        const int INF = numeric_limits<int>::max() / 3;

        vector<vector<vector<int>>> distances(2, vector<vector<int>>(onesCount + 1, vector<int>(id33 + 1, INF)));
        vector<vector<vector<long long>>> ways(2, vector<vector<long long>>(onesCount + 1, vector<long long>(id33 + 1, 0)));

        distances[FROM_SIDE][onesCount][id33] = 0;
        ways[FROM_SIDE][onesCount][id33] = 1;

        struct Triple {
            int side, ones, twos;
            Triple(int s, int o, int t) : side(s), ones(o), twos(t) {}
        };

        queue<Triple> q;
        q.push(Triple(FROM_SIDE, onesCount, id33));

        while (!q.empty()) {
            Triple from = q.front();
            q.pop();

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

                        long long id23 = (fromWays * c[from.ones][id44] % MODULO * c[from.twos][id45] % MODULO) % MODULO;

                        if (nextDistance > id39) {
                            nextDistance = distances[nextSide][id24][id32] = id39;
                            q.push(Triple(nextSide, id24, id32));
                        }

                        if (nextDistance == id39) {
                            ways[nextSide][id24][id32] = (ways[nextSide][id24][id32] + id23) % MODULO;
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

                        long long id23 = (fromWays * c[id34][id44] % MODULO * c[id12][id45] % MODULO) % MODULO;

                        if (nextDistance > id39) {
                            nextDistance = distances[nextSide][id24][id32] = id39;
                            q.push(Triple(nextSide, id24, id32));
                        }

                        if (nextDistance == id39) {
                            ways[nextSide][id24][id32] = (ways[nextSide][id24][id32] + id23) % MODULO;
                        }
                    }
                }
            }
        }

        int distance = distances[TO_SIDE][0][0];
        if (INF == distance) {
            return {-1, 0};
        } else {
            return {distance, static_cast<int>(ways[TO_SIDE][0][0])};
        }
    }

public:
    void run() {
        try {
            init();
            if (id10) {
                solve();
            } else {
                do {
                    try {
                        solve();
                        out << endl;
                        out.flush();
                    } catch (ifstream::failure& e) {
                        break;
                    }
                } while (id6);
            }
            out.close();
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
