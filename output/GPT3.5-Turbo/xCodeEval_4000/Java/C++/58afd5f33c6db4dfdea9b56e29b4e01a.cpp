#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class LongHashMap {
private:
    vector<int> slot;
    vector<int> next;
    vector<long long> keys;
    vector<long long> values;
    int alloc;
    vector<bool> removed;
    int mask;
    int size;
    bool rehash;

    void doubleCapacity() {
        int newSize = max(static_cast<int>(next.size() + 10), static_cast<int>(next.size() * 2));
        next.resize(newSize);
        keys.resize(newSize);
        values.resize(newSize);
        removed.resize(newSize);
    }

    void rehash() {
        vector<int> newSlots(max(16, static_cast<int>(slot.size() * 2)));
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

    int hash(long long x) {
        int h = hash<long long>()(x);
        return h ^ (h >> 16);
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

public:
    LongHashMap(int cap, bool rehash) {
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

    void put(long long x, long long y) {
        put(x, y, true);
    }

    void put(long long x, long long y, bool cover) {
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

    class LongEntryIterator {
    private:
        int index;
        int readIndex;
    public:
        LongEntryIterator() {
            index = 1;
            readIndex = -1;
        }

        bool hasNext() {
            while (index <= alloc && removed[index]) {
                index++;
            }
            return index <= alloc;
        }

        void next() {
            if (!hasNext()) {
                throw runtime_error("No next element");
            }
            readIndex = index;
            index++;
        }

        long long getEntryKey() {
            return keys[readIndex];
        }

        long long getEntryValue() {
            return values[readIndex];
        }
    };

    LongEntryIterator iterator() {
        return LongEntryIterator();
    }
};

class LongList {
private:
    int size;
    int cap;
    vector<long long> data;

public:
    LongList(int cap) {
        this->cap = cap;
        if (cap == 0) {
            data = vector<long long>();
        } else {
            data = vector<long long>(cap);
        }
    }

    LongList(const LongList& list) {
        size = list.size;
        cap = list.cap;
        data = vector<long long>(list.data.begin(), list.data.begin() + size);
    }

    LongList() {
        this->cap = 0;
    }

    void ensureSpace(int req) {
        if (req > cap) {
            while (cap < req) {
                cap = max(cap + 10, 2 * cap);
            }
            data.resize(cap);
        }
    }

    void checkRange(int i) {
        if (i < 0 || i >= size) {
            throw out_of_range("Index out of range");
        }
    }

    long long get(int i) {
        checkRange(i);
        return data[i];
    }

    void add(long long x) {
        ensureSpace(size + 1);
        data[size++] = x;
    }

    void addAll(const vector<long long>& x, int offset, int len) {
        ensureSpace(size + len);
        copy(x.begin() + offset, x.begin() + offset + len, data.begin() + size);
        size += len;
    }

    void addAll(const LongList& list) {
        addAll(list.data, 0, list.size);
    }

    void sort() {
        if (size <= 1) {
            return;
        }
        random_shuffle(data.begin(), data.begin() + size);
        sort(data.begin(), data.begin() + size);
    }

    void unique() {
        if (size <= 1) {
            return;
        }

        sort();
        int wpos = 1;
        for (int i = 1; i < size; i++) {
            if (data[i] != data[wpos - 1]) {
                data[wpos++] = data[i];
            }
        }
        size = wpos;
    }

    int getSize() {
        return size;
    }

    vector<long long> toArray() {
        return vector<long long>(data.begin(), data.begin() + size);
    }

    void clear() {
        size = 0;
    }

    string toString() {
        vector<long long> arr = toArray();
        string str = "{";
        for (int i = 0; i < arr.size(); i++) {
            str += to_string(arr[i]);
            if (i != arr.size() - 1) {
                str += ",";
            }
        }
        str += "}";
        return str;
    }

    bool equals(const LongList& other) {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    int hashCode() {
        int h = 1;
        for (int i = 0; i < size; i++) {
            h = h * 31 + hash<long long>()(data[i]);
        }
        return h;
    }

    LongList clone() {
        LongList ans;
        ans.addAll(*this);
        return ans;
    }
};

class LongModular {
private:
    long long m;

public:
    LongModular(long long m) {
        this->m = m;
    }

    long long mul(long long a, long long b) {
        return b == 0 ? 0 : ((mul(a, b >> 1) << 1) % m + a * (b & 1)) % m;
    }
};

class LongPower {
private:
    LongModular modular;

public:
    LongPower(LongModular modular) {
        this->modular = modular;
    }

    long long pow(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        long long r = pow(x, n >> 1);
        r = modular.mul(r, r);
        if ((n & 1) == 1) {
            r = modular.mul(r, x);
        }
        return r;
    }
};

class Factorization {
public:
    static vector<long long> factorizeNumberPrime(long long x) {
        vector<long long> ans;
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

class GXMouseInTheCampus {
private:
    LongHashMap mu;
    LongHashMap euler;
    vector<long long> primes;

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

    void collect(LongList& list, long long x, int i) {
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
    void solve(int testNumber, istream& in, ostream& out) {
        long long m, x;
        in >> m >> x;

        primes = Factorization::factorizeNumberPrime(m);
        LongList allFactorOfM(20000);
        LongList tmpList(20000);
        LongList allPossiblePrimeFactor;
        for (long long p : primes) {
            allPossiblePrimeFactor.add(p);
            vector<long long> factors = Factorization::factorizeNumberPrime(p - 1);
            allPossiblePrimeFactor.insert(allPossiblePrimeFactor.end(), factors.begin(), factors.end());
        }
        allPossiblePrimeFactor.unique();

        collect(allFactorOfM, m, 0);
        LongPower power(LongModular(m));

        long long total = 1;
        for (int i = 0; i < allFactorOfM.getSize(); i++) {
            long long g = allFactorOfM.get(i);
            if (g == m) {
                continue;
            }
            long long mg = m / g;
            tmpList.clear();
            collect(tmpList, mg, 0);
            long long cnt = 0;
            for (int j = tmpList.getSize() - 1; j >= 0; j--) {
                long long t = tmpList.get(j);
                cnt += mu(t) * ((m - 1) / (t * g));
            }

            tmpList.clear();
            long long euler = euler(mg);
            LongList primeFactors = tmpList;
            for (int j = 0; j < allPossiblePrimeFactor.getSize(); j++) {
                long long p = allPossiblePrimeFactor.get(j);
                if (euler % p == 0) {
                    primeFactors.add(p);
                }
            }

            long long n = euler;
            for (int j = 0; j < primeFactors.getSize(); j++) {
                long long p = primeFactors.get(j);
                while (n % p == 0 && power.pow(x, n / p) % mg == 1) {
                    n /= p;
                }
            }

            if (cnt % n != 0) {
                throw runtime_error("Invalid state");
            }
            total += cnt / n;
        }

        out << total << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    GXMouseInTheCampus solver;
    solver.solve(1, cin, cout);

    return 0;
}
