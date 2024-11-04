#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <sstream>

using namespace std;

class FastInput {
    istream &is;
    string buffer;
public:
    FastInput(istream &is) : is(is) {}

    long long readLong() {
        if (buffer.empty()) {
            is >> buffer;
        }
        long long val = stoll(buffer);
        buffer.clear();
        return val;
    }
};

class FastOutput {
    ostream &os;
    stringstream cache;

public:
    FastOutput(ostream &os) : os(os) {}

    void println(long long c) {
        cache << c << endl;
        flush();
    }

    void flush() {
        os << cache.str();
        cache.str("");
    }
};

class LongList {
    vector<long long> data;

public:
    void add(long long x) {
        data.push_back(x);
    }

    long long get(int i) {
        return data[i];
    }

    int size() {
        return data.size();
    }

    void clear() {
        data.clear();
    }

    vector<long long> toArray() {
        return data;
    }

    void unique() {
        sort(data.begin(), data.end());
        auto last = unique(data.begin(), data.end());
        data.erase(last, data.end());
    }
};

class id1 {
    unordered_map<long long, long long> map;

public:
    void put(long long x, long long y) {
        map[x] = y;
    }

    long long get(long long x) {
        return map.count(x) ? map[x] : 0;
    }
};

class Factorization {
public:
    static LongList id13(long long x) {
        LongList ans;
        for (long long i = 2; i * i <= x; i++) {
            if (x % i != 0) continue;
            ans.add(i);
            while (x % i == 0) {
                x /= i;
            }
        }
        if (x > 1) {
            ans.add(x);
        }
        return ans;
    }
};

class id3 {
    id1 mu;
    id1 euler;
    vector<long long> primes;

    void populate(long long x) {
        long long factor = id0(x);
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
        euler.put(x, eulerFunc(y) * (x / y - x / y / factor));
    }

    long long id0(long long x) {
        for (long long p : primes) {
            if (x % p == 0) {
                return p;
            }
        }
        return x;
    }

    long long muFunc(long long x) {
        long long ans = mu.get(x);
        if (ans == 0) {
            populate(x);
            ans = mu.get(x);
        }
        return ans;
    }

    long long eulerFunc(long long x) {
        long long ans = euler.get(x);
        if (ans == 0) {
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
    void solve(long long m, long long x, FastOutput &out) {
        primes = Factorization::id13(m).toArray();
        LongList id9;
        LongList tmpList;
        LongList id2;

        for (long long p : primes) {
            id2.add(p);
            LongList factors = Factorization::id13(p - 1);
            for (int j = 0; j < factors.size(); j++) {
                id2.add(factors.get(j));
            }
        }
        id2.unique();

        collect(id9, m, 0);
        long long total = 1;

        for (int i = 0; i < id9.size(); i++) {
            long long g = id9.get(i);
            if (g == m) continue;
            long long mg = m / g;
            tmpList.clear();
            collect(tmpList, mg, 0);
            long long cnt = 0;

            for (int j = tmpList.size() - 1; j >= 0; j--) {
                long long t = tmpList.get(j);
                cnt += muFunc(t) * ((m - 1) / (t * g));
            }

            tmpList.clear();
            long long euler = eulerFunc(mg);
            LongList primeFactors;

            for (int j = 0; j < id2.size(); j++) {
                long long p = id2.get(j);
                if (euler % p == 0) {
                    primeFactors.add(p);
                }
            }

            long long n = euler;
            for (int j = 0; j < primeFactors.size(); j++) {
                long long p = primeFactors.get(j);
                while (n % p == 0) {
                    n /= p;
                }
            }

            if (cnt % n != 0) {
                throw runtime_error("Illegal State");
            }
            total += cnt / n;
        }

        out.println(total);
    }
};

int main() {
    FastInput in(cin);
    FastOutput out(cout);
    long long m = in.readLong();
    long long x = in.readLong();

    id3 solver;
    solver.solve(m, x, out);

    return 0;
}
