#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class InputReader {
public:
    InputReader(std::istream &stream) : stream(stream) {}

    std::vector<long> readLongArray(int size) {
        std::vector<long> array(size);
        for (int i = 0; i < size; i++) {
            array[i] = readLong();
        }
        return array;
    }

    std::vector<int> readIntArray(int size) {
        std::vector<int> array(size);
        for (int i = 0; i < size; i++) {
            array[i] = readInt();
        }
        return array;
    }

private:
    std::istream &stream;

    int read() {
        int c = stream.get();
        if (c == EOF) {
            throw std::runtime_error("InputMismatchException");
        }
        return c;
    }

    int readInt() {
        int c = read();
        while (isWhitespace(c)) {
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
                throw std::runtime_error("InputMismatchException");
            }
            res = res * 10 + (c - '0');
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    long readLong() {
        int c = read();
        while (isWhitespace(c)) {
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
                throw std::runtime_error("InputMismatchException");
            }
            res = res * 10 + (c - '0');
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    static bool isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF;
    }
};

class OutputWriter {
public:
    OutputWriter(std::ostream &outputStream) : writer(outputStream) {}

    void printLine(long i) {
        writer << i << std::endl;
    }

private:
    std::ostream &writer;
};

class ArrayUtils {
public:
    static std::vector<int> createOrder(int size) {
        std::vector<int> order(size);
        std::iota(order.begin(), order.end(), 0);
        return order;
    }

    static std::vector<int> order(const std::vector<long> &array) {
        auto order = createOrder(array.size());
        std::sort(order.begin(), order.end(), [&array](int first, int second) {
            return array[first] < array[second];
        });
        return order;
    }

    static void reverse(std::vector<int> &array) {
        std::reverse(array.begin(), array.end());
    }
};

class Solver {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) {
        int n = in.readInt();
        std::vector<long> A = in.readLongArray(n);
        std::vector<int> B = in.readIntArray(n);
        std::vector<bool> used(n, false);
        auto order = ArrayUtils::order(A);
        long res = 0;
        ArrayUtils::reverse(order);

        for (int idx = 0; idx < n;) {
            int to = idx;
            while (to + 1 < n && A[order[to + 1]] == A[order[idx]]) {
                to++;
            }
            bool valid = to > idx;
            if (!valid) {
                for (int i = 0; i < idx; i++) {
                    if (used[i] && (A[order[i]] & A[order[idx]]) == A[order[idx]]) {
                        valid = true;
                    }
                }
            }
            if (valid) {
                for (int i = idx; i <= to; i++) {
                    res += B[order[i]];
                    used[i] = true;
                }
            }
            idx = to + 1;
        }
        out.printLine(res);
    }
};

int main() {
    InputReader in(std::cin);
    OutputWriter out(std::cout);
    Solver solver;
    solver.solve(1, in, out);
    return 0;
}
