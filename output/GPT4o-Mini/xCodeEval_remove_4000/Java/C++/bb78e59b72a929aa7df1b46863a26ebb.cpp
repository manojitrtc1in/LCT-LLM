#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <random>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

const long MODULO = 1000000007;
const int MAX_T = 1000000000;

class SegmentTree {
public:
    int size;
    vector<long> sums;
    vector<long> mins;

    SegmentTree(int n) : size(n), sums(4 * n), mins(4 * n) {}

    int index;
    long value;

    void updateIndex(int index, long value) {
        this->index = index;
        this->value = value;
        id26(1, 0, size);
    }

private:
    void id26(int v, int left, int right) {
        if (left + 1 == right) {
            sums[v] = value;
            mins[v] = min(0LL, value);
        } else {
            int mid = (left + right) >> 1;
            int vLeft = (v << 1), vRight = vLeft + 1;

            if (index < mid) id26(vLeft, left, mid);
            else id26(vRight, mid, right);

            updateVertex(v, vLeft, vRight);
        }
    }

    void updateVertex(int v, int vLeft, int vRight) {
        sums[v] = sums[vLeft] + sums[vRight];
        mins[v] = min(mins[vLeft], sums[vLeft] + mins[vRight]);
    }

public:
    bool found;
    int foundIndex;

    int start, end;
    int getInterval(int start, int end, long value) {
        this->start = start;
        this->end = end;
        this->value = value;

        this->found = false;
        this->foundIndex = -1;

        id12(1, 0, size);

        return foundIndex;
    }

private:
    void id12(int v, int left, int right) {
        if (start <= left && right <= end) {
            if (!found) {
                if (value + mins[v] <= 0) {
                    id19(v, left, right);
                    found = true;
                } else {
                    value += sums[v];
                }
            }
        } else {
            int mid = (left + right) >> 1;
            int vLeft = (v << 1), vRight = vLeft + 1;

            if (start < mid) id12(vLeft, left, mid);
            if (mid < end) id12(vRight, mid, right);
        }
    }

    void id19(int v, int left, int right) {
        if (left + 1 == right) {
            foundIndex = left;
        } else {
            int mid = (left + right) >> 1;
            int vLeft = (v << 1), vRight = vLeft + 1;

            if (value + mins[vLeft] <= 0) {
                id19(vLeft, left, mid);
            } else {
                value += sums[vLeft];
                id19(vRight, mid, right);
            }
        }
    }
};

class IdMap {
public:
    map<int, int> idMap;

    int registerKey(int key) {
        auto it = idMap.find(key);
        if (it == idMap.end()) {
            idMap[key] = idMap.size();
        }
        return idMap[key];
    }

    int getId(int key) {
        return idMap[key];
    }
};

class Id23 {
public:
    vector<int> values;

    void addValue(int value) {
        values.push_back(value);
    }

    IdMap build() {
        sort(values.begin(), values.end());
        IdMap ids;
        vector<int> uniqueValues;

        for (size_t index = 0; index < values.size(); ++index) {
            int value = values[index];
            if (index == 0 || values[index - 1] != value) {
                ids.registerKey(value);
                uniqueValues.push_back(value);
            }
        }

        values = uniqueValues;
        return ids;
    }
};

class C {
public:
    void solve() {
        int q;
        cin >> q;
        vector<vector<int>> queries(q);
        for (int i = 0; i < q; ++i) {
            int type;
            cin >> type;
            if (type == 1) {
                int time, speed;
                cin >> time >> speed;
                queries[i] = {1, time, speed};
            } else if (type == 2) {
                int time;
                cin >> time;
                queries[i] = {2, time};
            } else {
                int start, end, value;
                cin >> start >> end >> value;
                queries[i] = {3, start, end, value};
            }
        }

        Id23 mapper;
        mapper.addValue(0);
        mapper.addValue(MAX_T + 1);

        for (const auto& query : queries) {
            mapper.addValue(query[1]);
            if (query[0] == 3) {
                mapper.addValue(query[2]);
            }
        }

        IdMap ids = mapper.build();
        vector<int> times = mapper.values;

        int minTime = ids.getId(0), maxTime = ids.getId(MAX_T + 1);
        map<int, int> id33;

        id33[minTime] = 0;
        id33[maxTime] = 0;

        for (auto& query : queries) {
            query[1] = ids.getId(query[1]);
            if (query[0] == 3) query[2] = ids.getId(query[2]);
        }

        SegmentTree tree(ids.idMap.size());

        for (const auto& query : queries) {
            int type = query[0];
            if (type == 1) {
                int time = query[1];
                int realTime = times[time];
                long speed = query[2];

                auto entryBefore = id33.lower_bound(time);
                int timeAfter = id33.upper_bound(time)->first;
                int id10 = times[timeAfter];

                int timeBefore = entryBefore->first;
                int id38 = times[timeBefore];
                long speedBefore = entryBefore->second;

                tree.updateIndex(timeBefore, speedBefore * (realTime - id38));
                tree.updateIndex(time, speed * (id10 - realTime));

                id33[time] = speed;
            } else if (type == 2) {
                int time = query[1];
                int realTime = times[time];

                auto entryBefore = id33.lower_bound(time);
                int timeAfter = id33.upper_bound(time)->first;
                int id10 = times[timeAfter];

                int timeBefore = entryBefore->first;
                int id38 = times[timeBefore];
                long speedBefore = entryBefore->second;

                tree.updateIndex(timeBefore, speedBefore * (id10 - id38));
                tree.updateIndex(time, 0);

                id33.erase(time);
            } else {
                int start = query[1], end = query[2];
                long value = query[3];

                int foundIndex = tree.getInterval(start, end, value);
                if (foundIndex == -1) {
                    cout << -1 << endl;
                } else {
                    value = tree.value;

                    int time = foundIndex;
                    int realTime = times[time];

                    if (value == 0) {
                        cout << realTime << endl;
                    } else {
                        long speed = id33.count(time) ? id33[time] : -1;

                        int timeAfter = min(end, id33.upper_bound(time)->first);
                        int id10 = times[timeAfter];

                        long delta = id10 - realTime;
                        long total = delta * speed;

                        if (value + total > 0) {
                            cout << -1 << endl;
                        } else {
                            double badTime = realTime + static_cast<double>(value) / abs(speed);
                            cout << fixed << setprecision(10) << badTime << endl;
                        }
                    }
                }
            }
        }
    }

    void run() {
        try {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            solve();
        } catch (exception& e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }
};

int main() {
    C c;
    c.run();
    return 0;
}
