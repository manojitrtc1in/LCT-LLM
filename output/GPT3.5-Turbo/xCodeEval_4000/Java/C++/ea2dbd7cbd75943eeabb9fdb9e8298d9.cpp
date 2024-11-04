#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

class DSU {
private:
    vector<int> p;
    vector<int> rank;
    vector<int> size;

public:
    DSU(int n) {
        p.resize(n);
        rank.resize(n);
        size.resize(n);
        reset();
    }

    void reset() {
        for (int i = 0; i < p.size(); i++) {
            p[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int find(int a) {
        if (p[a] == p[p[a]]) {
            return p[a];
        }
        return p[a] = find(p[a]);
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
        if (rank[a] == rank[b]) {
            rank[a]++;
        }

        if (rank[a] < rank[b]) {
            swap(a, b);
        }

        size[a] += size[b];
        p[b] = a;
    }
};

class IntegerHashMap {
private:
    vector<int> slot;
    vector<int> next;
    vector<int> keys;
    vector<int> values;
    vector<bool> removed;
    int alloc;
    int mask;
    int size;
    bool rehash;

    int hash(int x) {
        x = (x ^ 0x9e3779b9) + (x << 6) + (x >> 2);
        return x & mask;
    }

    void doubleCapacity() {
        int newSize = max(10, (int)next.size() * 2);
        next.resize(newSize);
        keys.resize(newSize);
        values.resize(newSize);
        removed.resize(newSize);
    }

    void rehash() {
        vector<int> newSlots(slot.size() * 2);
        int newMask = newSlots.size() - 1;
        for (int i = 0; i < slot.size(); i++) {
            if (slot[i] == 0) {
                continue;
            }
            int head = slot[i];
            while (head != 0) {
                int n = next[head];
                int s = hash(keys[head]) & newMask;
                next[head] = newSlots[s];
                newSlots[s] = head;
                head = n;
            }
        }
        slot = newSlots;
        mask = newMask;
    }

    int findIndexOrLastEntry(int s, int x) {
        int iter = slot[s];
        while (keys[iter] != x) {
            if (next[iter] != 0) {
                iter = next[iter];
            } else {
                return iter;
            }
        }
        return iter;
    }

public:
    IntegerHashMap(int cap, bool rehash) {
        mask = (1 << (32 - __builtin_clz(cap - 1))) - 1;
        slot.resize(mask + 1);
        next.resize(cap + 1);
        keys.resize(cap + 1);
        values.resize(cap + 1);
        removed.resize(cap + 1);
        this->rehash = rehash;
    }

    void alloc() {
        alloc++;
        if (alloc >= next.size()) {
            doubleCapacity();
        }
        next[alloc] = 0;
        removed[alloc] = false;
        size++;
    }

    void put(int x, int y) {
        put(x, y, true);
    }

    void put(int x, int y, bool cover) {
        int h = hash(x);
        int s = h & mask;
        if (slot[s] == 0) {
            alloc();
            slot[s] = alloc;
            keys[alloc] = x;
            values[alloc] = y;
        } else {
            int index = findIndexOrLastEntry(s, x);
            if (keys[index] != x) {
                alloc();
                next[index] = alloc;
                keys[alloc] = x;
                values[alloc] = y;
            } else if (cover) {
                values[index] = y;
            }
        }
        if (rehash && size >= slot.size()) {
            rehash();
        }
    }

    bool containKey(int x) {
        int h = hash(x);
        int s = h & mask;
        if (slot[s] == 0) {
            return false;
        }
        return keys[findIndexOrLastEntry(s, x)] == x;
    }

    int getOrDefault(int x, int def) {
        int h = hash(x);
        int s = h & mask;
        if (slot[s] == 0) {
            return def;
        }
        int index = findIndexOrLastEntry(s, x);
        return keys[index] == x ? values[index] : def;
    }

    int get(int x) {
        return getOrDefault(x, 0);
    }

    vector<int> keys() {
        vector<int> result;
        for (int i = 0; i < slot.size(); i++) {
            int iter = slot[i];
            while (iter != 0) {
                result.push_back(keys[iter]);
                iter = next[iter];
            }
        }
        return result;
    }
};

class IntegerMultiWayStack {
private:
    vector<int> values;
    vector<int> next;
    vector<int> heads;
    int alloc;
    int stackNum;

public:
    IntegerMultiWayStack(int qNum, int totalCapacity) {
        values.resize(totalCapacity + 1);
        next.resize(totalCapacity + 1);
        heads.resize(qNum);
        stackNum = qNum;
    }

    void addLast(int qId, int x) {
        alloc++;
        values[alloc] = x;
        next[alloc] = heads[qId];
        heads[qId] = alloc;
    }

    vector<int> get(int qId) {
        vector<int> result;
        int iter = heads[qId];
        while (iter != 0) {
            result.push_back(values[iter]);
            iter = next[iter];
        }
        return result;
    }
};

class CPointsLinesAndReadyMadeTitles {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int n;
        in >> n;
        vector<Point> pts(n);
        for (int i = 0; i < n; i++) {
            in >> pts[i].x >> pts[i].y;
        }

        IntegerHashMap x(n, false);
        IntegerHashMap y(n, false);
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            if (x.containKey(pts[i].x)) {
                dsu.merge(x.get(pts[i].x), i);
            }
            if (y.containKey(pts[i].y)) {
                dsu.merge(y.get(pts[i].y), i);
            }
            x.put(pts[i].x, i);
            y.put(pts[i].y, i);
        }

        IntegerMultiWayStack xStack(n, n);
        IntegerMultiWayStack yStack(n, n);
        for (int i = 0; i < n; i++) {
            xStack.addLast(dsu.find(i), pts[i].x);
            yStack.addLast(dsu.find(i), pts[i].y);
        }

        vector<int> xList;
        vector<int> yList;

        int mod = 1e9 + 7;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) != i) {
                continue;
            }
            xList = xStack.get(i);
            yList = yStack.get(i);
            sort(xList.begin(), xList.end());
            sort(yList.begin(), yList.end());
            xList.erase(unique(xList.begin(), xList.end()), xList.end());
            yList.erase(unique(yList.begin(), yList.end()), yList.end());

            int line = xList.size() + yList.size();
            int num = dsu.size[i];
            int local = 0;
            for (int j = 0; j <= num; j++) {
                local = (local + combination(line, j, mod)) % mod;
            }

            ans = (ans * 1LL * local) % mod;
        }

        out << ans << endl;
    }

    int combination(int m, int n, int mod) {
        if (n > m) {
            return 0;
        }
        int res = 1;
        for (int i = 0; i < n; i++) {
            res = (res * 1LL * (m - i)) % mod;
            res = (res * 1LL * inverse(i + 1, mod)) % mod;
        }
        return res;
    }

    int inverse(int x, int mod) {
        int b = mod - 2;
        int res = 1;
        while (b) {
            if (b & 1) {
                res = (res * 1LL * x) % mod;
            }
            x = (x * 1LL * x) % mod;
            b >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    CPointsLinesAndReadyMadeTitles solver;
    solver.solve(1, cin, cout);

    return 0;
}
