#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

class LongModular {
private:
    long m;

public:
    LongModular(long m) {
        this->m = m;
    }

    long mul(long a, long b) {
        return b == 0 ? 0 : ((mul(a, b >> 1) << 1) % m + a * (b & 1)) % m;
    }

    long plus(long a, long b) {
        return valueOf(a + b);
    }

    long valueOf(long a) {
        a %= m;
        if (a < 0) {
            a += m;
        }
        return a;
    }
};

class LongPower {
private:
    LongModular modular;

public:
    LongPower(LongModular modular) {
        this->modular = modular;
    }

    long pow(long x, long n) {
        if (n == 0) {
            return 1;
        }
        long r = pow(x, n >> 1);
        r = modular.mul(r, r);
        if ((n & 1) == 1) {
            r = modular.mul(r, x);
        }
        return r;
    }
};

class LongMillerRabin {
private:
    LongModular modular;
    LongPower power;
    random_device rd;
    mt19937 gen;

public:
    LongMillerRabin() {
        gen = mt19937(rd());
    }

    bool mr(long n, int s) {
        if (n <= 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        modular = LongModular(n);
        power = LongPower(modular);
        for (int i = 0; i < s; i++) {
            long x = uniform_int_distribution<long>(2, n - 2)(gen);
            if (!mr0(x, n)) {
                return false;
            }
        }
        return true;
    }

private:
    bool mr0(long x, long n) {
        long exp = n - 1;
        while (true) {
            long y = power.pow(x, exp);
            if (y != 1 && y != n - 1) {
                return false;
            }
            if (y != 1 || exp % 2 == 1) {
                break;
            }
            exp = exp / 2;
        }
        return true;
    }
};

class LongPollardRho {
private:
    LongMillerRabin mr;
    LongModular modular;
    LongPower power;
    random_device rd;
    mt19937 gen;

public:
    LongPollardRho() {
        gen = mt19937(rd());
    }

    long findFactor(long n) {
        if (mr.mr(n, 3)) {
            return n;
        }
        modular = LongModular(n);
        while (true) {
            long f = findFactor0(uniform_int_distribution<long>(0, n - 1)(gen), uniform_int_distribution<long>(0, n - 1)(gen), n);
            if (f != -1) {
                return f;
            }
        }
    }

    unordered_map<long, long> findAllFactors(long n) {
        unordered_map<long, long> factors;
        findAllFactors(factors, n);
        return factors;
    }

private:
    void findAllFactors(unordered_map<long, long>& factors, long n) {
        if (n == 1) {
            return;
        }
        long f = findFactor(n);
        if (f == n) {
            long value = factors[f];
            factors[f] = value * f;
            return;
        }
        findAllFactors(factors, f);
        findAllFactors(factors, n / f);
    }

    long findFactor0(long x, long c, long n) {
        long xi = x;
        long xj = x;
        int j = 2;
        int i = 1;
        while (i < n) {
            i++;
            xi = modular.plus(modular.mul(xi, xi), c);
            long g = __gcd(n, abs(xi - xj));
            if (g != 1 && g != n) {
                return g;
            }
            if (i == j) {
                j = j << 1;
                xj = xi;
            }
        }
        return -1;
    }
};

class GXMouseInTheCampus {
private:
    unordered_map<long, long> mu;
    unordered_map<long, long> euler;
    vector<long> primes;

public:
    GXMouseInTheCampus() {
        mu[1] = 1;
        euler[1] = 1;
    }

    long oneOfPrimeFactor(long x) {
        for (long p : primes) {
            if (x % p == 0) {
                return p;
            }
        }
        return x;
    }

    void populate(long x) {
        long factor = oneOfPrimeFactor(x);
        long cnt = 0;
        long y = x;
        while (y % factor == 0) {
            cnt++;
            y /= factor;
        }
        if (cnt > 1) {
            mu[x] = 0;
        } else {
            mu[x] = -mu[y];
        }
        euler[x] = euler[y] * (x / y - x / y / factor);
    }

    long mu(long x) {
        auto it = mu.find(x);
        if (it == mu.end()) {
            populate(x);
            return mu[x];
        }
        return it->second;
    }

    long euler(long x) {
        auto it = euler.find(x);
        if (it == euler.end()) {
            populate(x);
            return euler[x];
        }
        return it->second;
    }

    void solve(long m, long x) {
        LongPollardRho pollardRho;
        primes = pollardRho.findAllFactors(m);
        vector<long> allFactorOfM;
        vector<long> tmpList;
        vector<long> allPossiblePrimeFactor;
        for (long p : primes) {
            allPossiblePrimeFactor.push_back(p);
            vector<long> primeFactors = Factorization::factorizeNumberPrime(p - 1);
            allPossiblePrimeFactor.insert(allPossiblePrimeFactor.end(), primeFactors.begin(), primeFactors.end());
        }
        sort(allPossiblePrimeFactor.begin(), allPossiblePrimeFactor.end());
        allPossiblePrimeFactor.erase(unique(allPossiblePrimeFactor.begin(), allPossiblePrimeFactor.end()), allPossiblePrimeFactor.end());

        collect(allFactorOfM, m, 0);
        LongPower power(LongModular(m));

        long total = 1;
        for (int i = 0; i < allFactorOfM.size(); i++) {
            long g = allFactorOfM[i];
            if (g == m) {
                continue;
            }
            long mg = m / g;
            tmpList.clear();
            collect(tmpList, mg, 0);
            long cnt = 0;
            for (int j = tmpList.size() - 1; j >= 0; j--) {
                long t = tmpList[j];
                cnt += mu(t) * ((m - 1) / (t * g));
            }

            tmpList.clear();
            long euler = euler(mg);
            vector<long> primeFactors;
            for (int j = 0; j < allPossiblePrimeFactor.size(); j++) {
                long p = allPossiblePrimeFactor[j];
                if (euler % p == 0) {
                    primeFactors.push_back(p);
                }
            }

            long n = euler;
            for (int j = 0; j < primeFactors.size(); j++) {
                long p = primeFactors[j];
                while (n % p == 0 && power.pow(x, n / p) % mg == 1) {
                    n /= p;
                }
            }

            if (cnt % n != 0) {
                throw runtime_error("Invalid state");
            }
            total += cnt / n;
        }

        cout << total << endl;
    }

    void collect(vector<long>& list, long x, int i) {
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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    GXMouseInTheCampus solver;
    long m, x;
    cin >> m >> x;
    solver.solve(m, x);

    return 0;
}
