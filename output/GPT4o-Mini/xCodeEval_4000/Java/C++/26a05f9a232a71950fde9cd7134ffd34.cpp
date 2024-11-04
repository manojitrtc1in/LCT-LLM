#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

using namespace std;

const long long MODULO = 1000000007;

class E {
private:
    static random_device rnd;
    long long inverseNMinus1Factorial;

    long long mult(long long a, long long b) {
        return (a % MODULO) * (b % MODULO) % MODULO;
    }

    long long add(long long a, long long b) {
        return ((a % MODULO + b % MODULO) % MODULO + MODULO) % MODULO;
    }

    long long binpow(long long base, long long power) {
        if (power == 0) return 1;
        if (power % 2 == 0) {
            long long half = binpow(base, power / 2);
            return mult(half, half);
        } else {
            return mult(base, binpow(base, power - 1));
        }
    }

    long long inverse(long long x) {
        return binpow(x, MODULO - 2);
    }

    long long multSequence(long long start, long long end) {
        long long res = 1;
        for (long long i = start; i <= end; ++i) {
            res = mult(res, i);
        }
        return res;
    }

    long long binom(long long n, long long k) {
        return mult(multSequence(k + 1, n), inverseNMinus1Factorial);
    }

    void solve() {
        int n;
        long long s;
        cin >> n >> s;

        vector<long long> f(n);
        for (int i = 0; i < n; ++i) {
            cin >> f[i];
        }

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

        long long nMinus1Factorial = multSequence(1, n - 1);
        inverseNMinus1Factorial = inverse(nMinus1Factorial);

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

public:
    void run() {
        try {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout << fixed << setprecision(12);

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
