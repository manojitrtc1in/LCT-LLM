#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdexcept>

using namespace std;

class NumberTheory {
public:
    int id11(int a, int b, int MOD) {
        return (a % MOD + b % MOD) % MOD;
    }

    long id11(long a, long b, long MOD) {
        return (a % MOD + b % MOD) % MOD;
    }

    int id19(int a, int b, int MOD) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    long id19(long a, long b, long MOD) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    int id15(int a, int b, int MOD) {
        return (a % MOD - b % MOD + MOD) % MOD;
    }

    long id15(long a, long b, long MOD) {
        return (a % MOD - b % MOD + MOD) % MOD;
    }

    int id26(int x, int n) {
        if (n == 0) return 1;
        else if (n % 2 == 0) return id26(x * x, n / 2);
        else return x * id26(x * x, (n - 1) / 2);
    }

    long id26(long x, long n) {
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

    vector<int> primeFactors(int n) {
        vector<int> factors;
        int limit = (int)sqrt(n);
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

    vector<long> primeFactors(long n) {
        vector<long> factors;
        long limit = (long)sqrt(n);
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
};

class InputReader {
private:
    istream &stream;
public:
    InputReader(istream &stream) : stream(stream) {}

    int nextInt() {
        int res;
        stream >> res;
        return res;
    }

    long nextLong() {
        long res;
        stream >> res;
        return res;
    }

    vector<int> id12(int n) {
        vector<int> array(n);
        for (int i = 0; i < n; ++i) array[i] = nextInt();
        return array;
    }

    vector<vector<int>> id0(int n, int m) {
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                matrix[i][j] = nextInt();
        return matrix;
    }

    vector<vector<int>> id0(int n) {
        return id0(n, n);
    }
};

class OutputWriter {
private:
    ostream &stream;
public:
    OutputWriter(ostream &stream) : stream(stream) {}

    void println(long i) {
        stream << i << endl;
    }

    void println(int i) {
        stream << i << endl;
    }

    void print(const vector<int> &array) {
        for (size_t i = 0; i < array.size(); ++i) {
            if (i != 0) stream << ' ';
            stream << array[i];
        }
    }

    void println(const vector<int> &array) {
        print(array);
        stream << endl;
    }
};

class ProblemSolver {
public:
    void id13(InputReader &in, OutputWriter &out, NumberTheory &nt) {
        int test = 1;

        while (test-- > 0) {
            int n = in.nextInt();
            vector<vector<int>> ar = in.id0(n, n);

            long sum = 0;
            for (int i = 0; i < n; i++) {
                sum += ar[i][i];
            }

            for (int i = 0; i < n; i++) {
                sum += ar[n - i - 1][i];
            }

            for (int i = 0; i < n; i++) {
                sum += ar[(n - 1) / 2][i];
            }

            for (int i = 0; i < n; i++) {
                sum += ar[i][(n - 1) / 2];
            }
            out.println(sum - ar[(n - 1) / 2][(n - 1) / 2] * 3);
        }
    }
};

int main() {
    InputReader in(cin);
    OutputWriter out(cout);
    NumberTheory nt;
    ProblemSolver problemSolver;
    problemSolver.id13(in, out, nt);
    return 0;
}
