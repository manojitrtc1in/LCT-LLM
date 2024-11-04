#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <sstream>

class LongHashMap {
    std::vector<int> slot;
    std::vector<int> next;
    std::vector<long long> keys;
    std::vector<long long> values;
    int alloc = 0;
    bool rehash;
    int mask;
    int size = 0;

public:
    LongHashMap(int cap, bool rehash) : rehash(rehash) {
        mask = (1 << (32 - __builtin_clz(cap - 1))) - 1;
        slot.resize(mask + 1, 0);
        next.resize(cap + 1, 0);
        keys.resize(cap + 1);
        values.resize(cap + 1);
    }

    void alloc() {
        alloc++;
        if (alloc >= next.size()) {
            doubleCapacity();
        }
        next[alloc] = 0;
        size++;
    }

    void doubleCapacity() {
        int newSize = std::max(next.size() + 10, next.size() * 2);
        next.resize(newSize);
        keys.resize(newSize);
        values.resize(newSize);
    }

    int hash(long long x) {
        return std::hash<long long>()(x) ^ (std::hash<long long>()(x) >> 16);
    }

    void put(long long x, long long y) {
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
        std::vector<int> newSlots(std::max(16, (int)slot.size() * 2));
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
            is.read(buf.data(), buf.size());
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

class FastOutput {
    std::ostringstream cache;

public:
    void println(long long c) {
        cache << c << "\n";
    }

    void flush(std::ostream &os) {
        os << cache.str();
        cache.str("");
        cache.clear();
    }
};

class LongPower {
    long long m;

public:
    LongPower(long long m) : m(m) {}

    long long pow(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        long long r = pow(x, n >> 1);
        r = (r * r) % m;
        if ((n & 1) == 1) {
            r = (r * x) % m;
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

    void collect(std::vector<long long> &list, long long x, int i) {
        if (i == primes.size()) {
            list.push_back(x);
            return;
        }
        collect(list, x, i + 1);
        while (x % primes[i] == 0) {
            x /= primes[i];
            collect(list, x, i + 1);
        }
    }

public:
    void solve(int testNumber, FastInput &in, FastOutput &out) {
        long long m = in.readLong();
        long long x = in.readLong();

        primes = Factorization::factorizeNumberPrime(m);
        std::vector<long long> allFactorOfM;
        std::vector<long long> tmpList;
        std::vector<long long> allPossiblePrimeFactor;
        for (long long p : primes) {
            allPossiblePrimeFactor.push_back(p);
            auto factors = Factorization::factorizeNumberPrime(p - 1);
            allPossiblePrimeFactor.insert(allPossiblePrimeFactor.end(), factors.begin(), factors.end());
        }
        std::sort(allPossiblePrimeFactor.begin(), allPossiblePrimeFactor.end());
        allPossiblePrimeFactor.erase(std::unique(allPossiblePrimeFactor.begin(), allPossiblePrimeFactor.end()), allPossiblePrimeFactor.end());

        collect(allFactorOfM, m, 0);
        LongPower power(m);

        long long total = 1;
        for (long long g : allFactorOfM) {
            if (g == m) {
                continue;
            }
            long long mg = m / g;
            tmpList.clear();
            collect(tmpList, mg, 0);
            long long cnt = 0;
            for (int j = tmpList.size() - 1; j >= 0; j--) {
                long long t = tmpList[j];
                cnt += mu(t) * ((m - 1) / (t * g));
            }

            tmpList.clear();
            long long eulerVal = euler(mg);
            std::vector<long long> primeFactors;
            for (long long p : allPossiblePrimeFactor) {
                if (eulerVal % p == 0) {
                    primeFactors.push_back(p);
                }
            }

            long long n = eulerVal;
            for (long long p : primeFactors) {
                while (n % p == 0 && power.pow(x, n / p) % mg == 1) {
                    n /= p;
                }
            }

            if (cnt % n != 0) {
                throw std::runtime_error("Illegal State");
            }
            total += cnt / n;
        }

        out.println(total);
    }
};

class Factorization {
public:
    static std::vector<long long> factorizeNumberPrime(long long x) {
        std::vector<long long> ans;
        for (long long i = 2; i * i <= x; i++) {
            if (x % i != 0) {
                continue;
            }
            ans.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
        if (x > 1) {
            ans.push_back(x);
        }
        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::thread thread([]() {
        FastInput in(std::cin);
        FastOutput out;
        GXMouseInTheCampus solver;
        solver.solve(1, in, out);
        out.flush(std::cout);
    });
    thread.join();
    return 0;
}
