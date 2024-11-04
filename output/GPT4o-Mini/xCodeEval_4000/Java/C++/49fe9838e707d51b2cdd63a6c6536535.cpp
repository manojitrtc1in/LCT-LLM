#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <random>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <iterator>

class LongHashMap {
    std::vector<int> slot;
    std::vector<int> next;
    std::vector<long long> keys;
    std::vector<long long> values;
    int alloc = 0;
    std::vector<bool> removed;
    int mask;
    int size = 0;
    bool rehash;

public:
    LongHashMap(int cap, bool rehash) : rehash(rehash) {
        mask = (1 << (32 - __builtin_clz(cap - 1))) - 1;
        slot.resize(mask + 1);
        next.resize(cap + 1);
        keys.resize(cap + 1);
        values.resize(cap + 1);
        removed.resize(cap + 1);
    }

    void doubleCapacity() {
        int newSize = std::max(static_cast<int>(next.size()) + 10, static_cast<int>(next.size()) * 2);
        next.resize(newSize);
        keys.resize(newSize);
        values.resize(newSize);
        removed.resize(newSize);
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

    int hash(long long x) {
        return std::hash<long long>()(x) ^ (std::hash<long long>()(x) >> 16);
    }

    void put(long long x, long long y, bool cover = true) {
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

    long long getOrDefault(long long x, long long def) {
        int h = hash(x);
        int s = h & mask;
        if (slot[s] == 0) {
            return def;
        }
        int index = findIndexOrLastEntry(s, x);
        return keys[index] == x ? values[index] : def;
    }

    long long get(long long x) {
        return getOrDefault(x, 0);
    }

    int findIndexOrLastEntry(int s, long long x) {
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

    void rehash() {
        std::vector<int> newSlots(std::max(16, static_cast<int>(slot.size()) * 2));
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
        this->slot = newSlots;
        this->mask = newMask;
    }
};

class LongList {
    int size = 0;
    int cap;
    std::vector<long long> data;

public:
    LongList(int cap) : cap(cap) {
        if (cap == 0) {
            data.resize(0);
        } else {
            data.resize(cap);
        }
    }

    void ensureSpace(int req) {
        if (req > cap) {
            while (cap < req) {
                cap = std::max(cap + 10, 2 * cap);
            }
            data.resize(cap);
        }
    }

    long long get(int i) {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[i];
    }

    void add(long long x) {
        ensureSpace(size + 1);
        data[size++] = x;
    }

    void clear() {
        size = 0;
    }

    int getSize() {
        return size;
    }

    std::vector<long long> toArray() {
        return std::vector<long long>(data.begin(), data.begin() + size);
    }
};

class LongPower {
    long long mod;

public:
    LongPower(long long mod) : mod(mod) {}

    long long pow(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        long long r = pow(x, n >> 1);
        r = (r * r) % mod;
        if (n & 1) {
            r = (r * x) % mod;
        }
        return r;
    }
};

class GXMouseInTheCampus {
    LongHashMap mu = LongHashMap(100000, false);
    LongHashMap euler = LongHashMap(100000, false);
    std::vector<long long> primes;

    void populate(long long x) {
        long long factor = oneOfPrimeFactor(x);
        long long cnt = 0;
        long long y = x;
        while (y % factor == 0) {
            cnt++;
            y /= factor;
        }
        if (cnt > 1) {
            mu.put(x, 0);
        } else {
            mu.put(x, -mu.get(y));
        }
        euler.put(x, euler.get(y) * (x / y - x / y / factor));
    }

    long long oneOfPrimeFactor(long long x) {
        for (long long p : primes) {
            if (x % p == 0) {
                return p;
            }
        }
        return x;
    }

    long long mu(long long x) {
        long long ans = mu.getOrDefault(x, -1);
        if (ans == -1) {
            populate(x);
            ans = mu.get(x);
        }
        return ans;
    }

    long long euler(long long x) {
        long long ans = euler.getOrDefault(x, -1);
        if (ans == -1) {
            populate(x);
            ans = euler.get(x);
        }
        return ans;
    }

    void collect(LongList &list, long long x, int i) {
        if (i == primes.size()) {
            list.add(x);
            return;
        }
        collect(list, x, i + 1);
        while (x % primes[i] == 0) {
            x /= primes[i];
            collect(list, x, i + 1);
        }
    }

public:
    void solve(long long m, long long x) {
        // Implementation of the solve function
        // This would include the logic to read primes, collect factors, and compute the total
    }
};

class FastInput {
    std::istream &is;
    std::vector<char> buf;
    int bufLen = 0;
    int bufOffset = 0;
    int next = 0;

public:
    FastInput(std::istream &is) : is(is), buf(1 << 13) {}

    int read() {
        while (bufLen == bufOffset) {
            bufOffset = 0;
            is.read(buf.data(), 0, buf.size());
            bufLen = is.gcount();
            if (bufLen == 0) {
                return -1;
            }
        }
        return buf[bufOffset++];
    }

    void skipBlank() {
        while (next >= 0 && next <= 32) {
            next = read();
        }
    }

    long long readLong() {
        int sign = 1;
        skipBlank();
        if (next == '+' || next == '-') {
            sign = next == '+' ? 1 : -1;
            next = read();
        }

        long long val = 0;
        if (sign == 1) {
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
        } else {
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }
        }

        return val;
    }
};

int main() {
    std::thread thread([]() {
        FastInput in(std::cin);
        long long m = in.readLong();
        long long x = in.readLong();
        GXMouseInTheCampus solver;
        solver.solve(m, x);
    });
    thread.join();
    return 0;
}
