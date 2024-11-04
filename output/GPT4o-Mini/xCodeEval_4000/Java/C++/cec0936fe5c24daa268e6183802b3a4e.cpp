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

    int read() {
        if (stream.eof()) {
            throw std::runtime_error("InputMismatchException");
        }
        return stream.get();
    }

    int readInt() {
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
                throw std::runtime_error("InputMismatchException");
            }
            res = res * 10 + (c - '0');
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    long readLong() {
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
                throw std::runtime_error("InputMismatchException");
            }
            res = res * 10 + (c - '0');
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    bool isSpaceChar(int c) {
        return std::isspace(c) || c == EOF;
    }

private:
    std::istream &stream;
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

class AMarcinAndTrainingCamp {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) {
        int n = in.readInt();
        std::vector<long> A = in.readLongArray(n);
        std::vector<int> B = in.readIntArray(n);
        std::vector<bool> used(n, false);
        std::vector<int> order(n);
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&A](int first, int second) {
            return A[first] < A[second];
        });
        long res = 0;
        std::reverse(order.begin(), order.end());
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
    AMarcinAndTrainingCamp solver;
    solver.solve(1, in, out);
    return 0;
}
