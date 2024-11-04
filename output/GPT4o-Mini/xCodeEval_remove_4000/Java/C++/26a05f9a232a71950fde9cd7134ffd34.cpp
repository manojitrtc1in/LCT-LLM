#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

const long long MODULO = 1000000007;

class E {
private:
    static random_device rnd;
    long long id34;

    long long add(long long a, long long b) {
        return ((a % MODULO + b % MODULO) % MODULO + MODULO) % MODULO;
    }

    long long mult(long long a, long long b) {
        return (a % MODULO) * (b % MODULO) % MODULO;
    }

    long long inverse(long long x) {
        return binpow(x, MODULO - 2);
    }

    long long binpow(long long base, long long power) {
        if (power == 0) return 1;
        if (power % 2 == 0) {
            long long half = binpow(base, power / 2);
            return mult(half, half);
        } else {
            long long prev = binpow(base, power - 1);
            return mult(prev, base);
        }
    }

    long long multSequence(long long start, long long end) {
        long long res = 1;
        for (long long i = start; i <= end; ++i) {
            res = mult(res, i);
        }
        return res;
    }

    long long binom(long long n, long long k) {
        return mult(multSequence(k + 1, n), id34);
    }

    void solve() {
        int n;
        long long s;
        cin >> n >> s;

        vector<long long> f = id12(n);
        map<long long, long long> coeffs;
        coeffs[0] = 1;

        struct Pair {
            long long power, coeff;
            Pair(long long power, long long coeff) : power(power), coeff(coeff) {}
        };

        for (long long size : f) {
            vector<Pair> coeffEntries;
            for (const auto& coeffEntry : coeffs) {
                long long power = coeffEntry.first;
                long long coeff = coeffEntry.second;

                long long nextPower = power + size + 1;
                coeffEntries.emplace_back(nextPower, -coeff);
            }

            for (const Pair& coeffEntry : coeffEntries) {
                coeffs[coeffEntry.power] = add(coeffs[coeffEntry.power], coeffEntry.coeff);
            }
        }

        long long id25 = multSequence(1, n - 1);
        id34 = inverse(id25);

        long long answer = 0;
        for (const auto& coeffEntry : coeffs) {
            long long power = coeffEntry.first;
            long long coeff = coeffEntry.second;

            if (s >= power) {
                long long need = s - power;
                answer = add(answer, mult(binom(n + need - 1, need), coeff));
            }
        }

        cout << answer << endl;
    }

    vector<long long> id12(int size) {
        vector<long long> array(size);
        for (int index = 0; index < size; ++index) {
            cin >> array[index];
        }
        return array;
    }

public:
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

random_device E::rnd;

int main() {
    E e;
    e.run();
    return 0;
}
