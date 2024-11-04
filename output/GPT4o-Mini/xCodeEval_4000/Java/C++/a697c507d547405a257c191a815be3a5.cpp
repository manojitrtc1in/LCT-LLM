#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <random>
#include <stdexcept>

using namespace std;

const long MODULO = 1000000007;
const int MAX_T = 1000000000;

class SegmentTree {
public:
    SegmentTree(int n) : size(n) {
        sums.resize(size * 4);
        mins.resize(size * 4);
    }

    void updateIndex(int index, long value) {
        this->index = index;
        this->value = value;
        updateTreeIndex(1, 0, size);
    }

    int getInterval(int start, int end, long value) {
        this->start = start;
        this->end = end;
        this->value = value;
        found = false;
        foundIndex = -1;
        getTreeInterval(1, 0, size);
        return foundIndex;
    }

    long value;

private:
    int size, index, start, end, foundIndex;
    bool found;
    vector<long> sums, mins;

    void updateTreeIndex(int v, int left, int right) {
        if (left + 1 == right) {
            sums[v] = value;
            mins[v] = min(0L, value);
        } else {
            int mid = (left + right) >> 1;
            int vLeft = (v << 1), vRight = vLeft + 1;

            if (index < mid) updateTreeIndex(vLeft, left, mid);
            else updateTreeIndex(vRight, mid, right);

            updateVertex(v, vLeft, vRight);
        }
    }

    void updateVertex(int v, int vLeft, int vRight) {
        sums[v] = sums[vLeft] + sums[vRight];
        mins[v] = min(mins[vLeft], sums[vLeft] + mins[vRight]);
    }

    void getTreeInterval(int v, int left, int right) {
        if (start <= left && right <= end) {
            if (!found) {
                if (value + mins[v] <= 0) {
                    findTreeIndex(v, left, right);
                    found = true;
                } else {
                    value += sums[v];
                }
            }
        } else {
            int mid = (left + right) >> 1;
            int vLeft = (v << 1), vRight = vLeft + 1;

            if (start < mid) getTreeInterval(vLeft, left, mid);
            if (mid < end) getTreeInterval(vRight, mid, right);
        }
    }

    void findTreeIndex(int v, int left, int right) {
        if (left + 1 == right) {
            foundIndex = left;
        } else {
            int mid = (left + right) >> 1;
            int vLeft = (v << 1), vRight = vLeft + 1;

            if (value + mins[vLeft] <= 0) {
                findTreeIndex(vLeft, left, mid);
            } else {
                value += sums[vLeft];
                findTreeIndex(vRight, mid, right);
            }
        }
    }
};

class IdMap {
public:
    int registerKey(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            map[key] = size++;
        }
        return map[key];
    }

    int getId(int key) {
        return map[key];
    }

private:
    map<int, int> map;
    int size = 0;
};

class SortedIdMapper {
public:
    void addValue(int value) {
        values.push_back(value);
    }

    IdMap build() {
        sort(values.begin(), values.end());
        IdMap ids;
        vector<int> uniqueValues;

        for (size_t index = 0; index < values.size(); ++index) {
            if (index == 0 || values[index - 1] != values[index]) {
                ids.registerKey(values[index]);
                uniqueValues.push_back(values[index]);
            }
        }

        values = uniqueValues;
        return ids;
    }

    vector<int> values;
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
                int a, b;
                cin >> a >> b;
                queries[i] = {1, a, b};
            } else if (type == 2) {
                int a;
                cin >> a;
                queries[i] = {2, a};
            } else {
                int a, b, c;
                cin >> a >> b >> c;
                queries[i] = {3, a, b, c};
            }
        }

        SortedIdMapper mapper;
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
        map<int, int> timeSpeeds;

        timeSpeeds[minTime] = 0;
        timeSpeeds[maxTime] = 0;

        for (auto& query : queries) {
            query[1] = ids.getId(query[1]);
            if (query[0] == 3) query[2] = ids.getId(query[2]);
        }

        SegmentTree tree(ids.size());

        for (const auto& query : queries) {
            int type = query[0];
            if (type == 1) {
                int time = query[1];
                int realTime = times[time];
                long speed = query[2];

                auto entryBefore = timeSpeeds.lower_bound(time);
                int timeAfter = timeSpeeds.upper_bound(time)->first;
                int realTimeAfter = times[timeAfter];

                int timeBefore = prev(entryBefore)->first;
                int realTimeBefore = times[timeBefore];
                long speedBefore = entryBefore->second;

                tree.updateIndex(timeBefore, speedBefore * (realTime - realTimeBefore));
                tree.updateIndex(time, speed * (realTimeAfter - realTime));

                timeSpeeds[time] = speed;
            } else if (type == 2) {
                int time = query[1];
                int realTime = times[time];

                auto entryBefore = timeSpeeds.lower_bound(time);
                int timeAfter = timeSpeeds.upper_bound(time)->first;
                int realTimeAfter = times[timeAfter];

                int timeBefore = prev(entryBefore)->first;
                int realTimeBefore = times[timeBefore];
                long speedBefore = entryBefore->second;

                tree.updateIndex(timeBefore, speedBefore * (realTimeAfter - realTimeBefore));
                tree.updateIndex(time, 0);

                timeSpeeds.erase(time);
            } else {
                int start = query[1], end = query[2];
                long value = query[3];

                if (value == 0) {
                    cout << times[start] << endl;
                    continue;
                }

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
                        long speed = timeSpeeds.count(time) ? timeSpeeds[time] : -1;

                        int timeAfter = min(end, timeSpeeds.upper_bound(time)->first);
                        int realTimeAfter = times[timeAfter];

                        long delta = realTimeAfter - realTime;
                        long total = delta * speed;

                        if (value + total > 0) {
                            cout << -1 << endl;
                        } else {
                            double badTime = realTime + static_cast<double>(value) / abs(speed);
                            cout << fixed << setprecision(12) << badTime << endl;
                        }
                    }
                }
            }
        }
    }

    static void run() {
        C instance;
        instance.solve();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    C::run();
    return 0;
}
