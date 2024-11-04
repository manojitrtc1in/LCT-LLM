#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

using namespace std;

class NumberTheory {
public:
    int modularAddition(int a, int b, int MOD) {
        return (a % MOD + b % MOD) % MOD;
    }

    long modularAddition(long a, long b, long MOD) {
        return (a % MOD + b % MOD) % MOD;
    }

    int modularMultiplication(int a, int b, int MOD) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    long modularMultiplication(long a, long b, long MOD) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    int modularSubtraction(int a, int b, int MOD) {
        return (a % MOD - b % MOD + MOD) % MOD;
    }

    long modularSubtraction(long a, long b, long MOD) {
        return (a % MOD - b % MOD + MOD) % MOD;
    }

    int binaryExponentiation(int x, int n) {
        if (n == 0) return 1;
        else if (n % 2 == 0) return binaryExponentiation(x * x, n / 2);
        else return x * binaryExponentiation(x * x, (n - 1) / 2);
    }

    long binaryExponentiation(long x, long n) {
        long result = 1;
        while (n > 0) {
            if (n % 2 == 1) result *= x;
            x = x * x;
            n /= 2;
        }
        return result;
    }

    long factorials(long n) {
        if (n == 0) return 1;
        return n * factorials(n - 1);
    }

    vector<int> distinctPrimeFactors(int n) {
        vector<int> factors;
        int limit = (int) sqrt(n);
        if (n % 2 == 0) {
            factors.push_back(2);
            while (n % 2 == 0) n /= 2;
        }
        for (int i = 3; i <= limit; i += 2) {
            if (n % i == 0) {
                factors.push_back(i);
                while (n % i == 0) n /= i;
            }
        }
        if (n > 2) factors.push_back(n);
        return factors;
    }

    vector<long> distinctPrimeFactors(long n) {
        vector<long> factors;
        long limit = (long) sqrt(n);
        if (n % 2 == 0) {
            factors.push_back(2);
            while (n % 2 == 0) n /= 2;
        }
        for (long i = 3; i <= limit; i += 2) {
            if (n % i == 0) {
                factors.push_back(i);
                while (n % i == 0) n /= i;
            }
        }
        if (n > 2) factors.push_back(n);
        return factors;
    }

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }
};

class ProblemSolver {
public:
    void solveTheProblem() {
        int test = 1;

        while (test-- > 0) {
            int n;
            cin >> n;
            vector<vector<int>> ar(n, vector<int>(n));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    cin >> ar[i][j];

            long sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += ar[i][i];
            }

            for (int i = 0; i < n; ++i) {
                sum += ar[n - i - 1][i];
            }

            for (int i = 0; i < n; ++i) {
                sum += ar[(n - 1) / 2][i];
            }

            for (int i = 0; i < n; ++i) {
                sum += ar[i][(n - 1) / 2];
            }
            cout << sum - ar[(n - 1) / 2][(n - 1) / 2] * 3 << endl;
        }
    }
};

int main() {
    ProblemSolver problemSolver;
    problemSolver.solveTheProblem();
    return 0;
}
