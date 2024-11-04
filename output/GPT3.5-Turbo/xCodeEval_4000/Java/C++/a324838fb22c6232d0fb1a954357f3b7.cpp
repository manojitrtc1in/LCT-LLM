#include <iostream>
#include <vector>
#include <cmath>
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
        if (n == 0)
            return 1;
        else if (n % 2 == 0)
            return binaryExponentiation(x * x, n / 2);
        else
            return x * binaryExponentiation(x * x, (n - 1) / 2);
    }

    long binaryExponentiation(long x, long n) {
        long result = 1;
        while (n > 0) {
            if (n % 2 == 1)
                result *= x;
            x = x * x;
            n /= 2;
        }
        return result;
    }

    int modularExponentiation(int x, int n, int MOD) {
        if (n == 0)
            return 1 % MOD;
        else if (n % 2 == 0)
            return modularExponentiation(modularMultiplication(x, x, MOD), n / 2, MOD);
        else
            return modularMultiplication(x, modularExponentiation(modularMultiplication(x, x, MOD), (n - 1) / 2, MOD), MOD);
    }

    long modularExponentiation(long x, long n, long MOD) {
        long result = 1;
        while (n > 0) {
            if (n % 2 == 1)
                result = modularMultiplication(result, x, MOD);
            x = modularMultiplication(x, x, MOD);
            n /= 2;
        }
        return result;
    }

    long factorials(long n) {
        if (n == 0)
            return 1;
        return n * factorials(n - 1);
    }

    vector<int> distinctPrimeFactors(int n) {
        vector<int> factorials;
        int limit = sqrt(n);
        if (n % 2 == 0) {
            factorials.push_back(2);
            while (n % 2 == 0)
                n /= 2;
        }
        for (int i = 3; i <= limit; i += 2) {
            if (n % i == 0) {
                factorials.push_back(i);
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 2)
            factorials.push_back(n);
        return factorials;
    }

    vector<long> distinctPrimeFactors(long n) {
        vector<long> factorials;
        long limit = sqrt(n);
        if (n % 2 == 0) {
            factorials.push_back(2);
            while (n % 2 == 0)
                n /= 2;
        }
        for (long i = 3; i <= limit; i += 2) {
            if (n % i == 0) {
                factorials.push_back(i);
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 2)
            factorials.push_back(n);
        return factorials;
    }

    vector<int> primeFactors(int n) {
        vector<int> factorials;
        int limit = sqrt(n);
        if (n % 2 == 0) {
            factorials.push_back(2);
            while (n % 2 == 0)
                n /= 2;
        }
        for (int i = 3; i <= limit; i += 2) {
            if (n % i == 0) {
                factorials.push_back(i);
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 2)
            factorials.push_back(n);
        return factorials;
    }

    vector<long> primeFactors(long n) {
        vector<long> factorials;
        long limit = sqrt(n);
        if (n % 2 == 0) {
            factorials.push_back(2);
            while (n % 2 == 0)
                n /= 2;
        }
        for (long i = 3; i <= limit; i += 2) {
            if (n % i == 0) {
                factorials.push_back(i);
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 2)
            factorials.push_back(n);
        return factorials;
    }

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }
};

class A1_177 {
public:
    class ProblemSolver {
    public:
        void solveTheProblem() {
            int test = 1;

            while (test-- > 0) {
                int n;
                cin >> n;
                vector<vector<int>> ar(n, vector<int>(n));
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cin >> ar[i][j];
                    }
                }

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
                cout << sum - ar[(n - 1) / 2][(n - 1) / 2] * 3 << endl;
            }
        }
    };

    class InputReader {
    private:
        bool finished = false;
        int curChar;
        int numChars;
        vector<char> buf;
        istream& stream;

    public:
        InputReader(istream& stream) : stream(stream) {}

        int read() {
            if (numChars == -1) {
                throw runtime_error("InputMismatchException");
            }
            if (curChar >= numChars) {
                curChar = 0;
                buf.resize(1024);
                numChars = stream.read(&buf[0], buf.size());
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        int peek() {
            if (numChars == -1) {
                return -1;
            }
            if (curChar >= numChars) {
                curChar = 0;
                buf.resize(1024);
                numChars = stream.read(&buf[0], buf.size());
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar];
        }

        int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw runtime_error("InputMismatchException");
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw runtime_error("InputMismatchException");
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        string nextLine() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            string res;
            do {
                if (Character::isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res;
        }

        bool isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        vector<int> nextIntArray(int n) {
            vector<int> array(n);
            for (int i = 0; i < n; ++i)
                array[i] = nextInt();
            return array;
        }

        vector<int> nextSortedIntArray(int n) {
            vector<int> array = nextIntArray(n);
            sort(array.begin(), array.end());
            return array;
        }

        vector<int> nextSumIntArray(int n) {
            vector<int> array(n);
            array[0] = nextInt();
            for (int i = 1; i < n; ++i)
                array[i] = array[i - 1] + nextInt();
            return array;
        }

        vector<long> nextLongArray(int n) {
            vector<long> array(n);
            for (int i = 0; i < n; ++i)
                array[i] = nextLong();
            return array;
        }

        vector<long> nextSumLongArray(int n) {
            vector<long> array(n);
            array[0] = nextInt();
            for (int i = 1; i < n; ++i)
                array[i] = array[i - 1] + nextInt();
            return array;
        }

        vector<vector<int>> nextIntMatrix(int n, int m) {
            vector<vector<int>> matrix(n, vector<int>(m));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    matrix[i][j] = nextInt();
            return matrix;
        }

        vector<vector<int>> nextIntMatrix(int n) {
            return nextIntMatrix(n, n);
        }
    };

    class OutputWriter {
    private:
        ostream& writer;

    public:
        OutputWriter(ostream& writer) : writer(writer) {}

        void print(int x) {
            writer << x;
        }

        void print(long x) {
            writer << x;
        }

        void print(const string& s) {
            writer << s;
        }

        void print(const vector<int>& array) {
            for (int i = 0; i < array.size(); i++) {
                if (i != 0) {
                    writer << ' ';
                }
                writer << array[i];
            }
        }

        void print(const vector<long>& array) {
            for (int i = 0; i < array.size(); i++) {
                if (i != 0) {
                    writer << ' ';
                }
                writer << array[i];
            }
        }

        void print(const vector<char>& array) {
            for (int i = 0; i < array.size(); i++) {
                if (i != 0) {
                    writer << ' ';
                }
                writer << array[i];
            }
        }

        void print(const vector<string>& array) {
            for (int i = 0; i < array.size(); i++) {
                if (i != 0) {
                    writer << ' ';
                }
                writer << array[i];
            }
        }

        void print(const vector<vector<int>>& matrix) {
            for (int i = 0; i < matrix.size(); ++i) {
                println(matrix[i]);
            }
        }

        void print(const vector<vector<long>>& matrix) {
            for (int i = 0; i < matrix.size(); ++i) {
                println(matrix[i]);
            }
        }

        void print(const vector<vector<char>>& matrix) {
            for (int i = 0; i < matrix.size(); ++i) {
                println(matrix[i]);
            }
        }

        void print(const vector<vector<string>>& matrix) {
            for (int i = 0; i < matrix.size(); ++i) {
                println(matrix[i]);
            }
        }

        void println() {
            writer << endl;
        }

        void println(int x) {
            writer << x << endl;
        }

        void println(long x) {
            writer << x << endl;
        }

        void println(const string& s) {
            writer << s << endl;
        }

        void println(const vector<int>& array) {
            print(array);
            writer << endl;
        }

        void println(const vector<long>& array) {
            print(array);
            writer << endl;
        }

        void println(const vector<char>& array) {
            print(array);
            writer << endl;
        }

        void println(const vector<string>& array) {
            print(array);
            writer << endl;
        }

        void println(const vector<vector<int>>& matrix) {
            for (int i = 0; i < matrix.size(); ++i) {
                println(matrix[i]);
            }
        }

        void println(const vector<vector<long>>& matrix) {
            for (int i = 0; i < matrix.size(); ++i) {
                println(matrix[i]);
            }
        }

        void println(const vector<vector<char>>& matrix) {
            for (int i = 0; i < matrix.size(); ++i) {
                println(matrix[i]);
            }
        }

        void println(const vector<vector<string>>& matrix) {
            for (int i = 0; i < matrix.size(); ++i) {
                println(matrix[i]);
            }
        }
    };

public:
    static void main() {
        NumberTheory nt;
        ProblemSolver problemSolver;
        InputReader in(cin);
        OutputWriter out(cout);
        problemSolver.solveTheProblem();
        out.flush();
    }
};

int main() {
    A1_177::main();
    return 0;
}
