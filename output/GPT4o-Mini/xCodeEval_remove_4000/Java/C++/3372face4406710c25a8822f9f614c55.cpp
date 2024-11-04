#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <iomanip>

class InputReader {
public:
    InputReader(std::istream &stream) : stream(stream) {}

    int read() {
        if (stream.eof()) throw std::runtime_error("InputMismatchException");
        return stream.get();
    }

    int readInt() {
        int c = read();
        while (isWhitespace(c)) c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') throw std::runtime_error("InputMismatchException");
            res = res * 10 + (c - '0');
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    long long readLong() {
        int c = read();
        while (isWhitespace(c)) c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long long res = 0;
        do {
            if (c < '0' || c > '9') throw std::runtime_error("InputMismatchException");
            res = res * 10 + (c - '0');
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }

private:
    std::istream &stream;

    static bool isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF;
    }
};

class OutputWriter {
public:
    OutputWriter(std::ostream &outputStream) : writer(outputStream) {}

    void print(const std::vector<int> &array) {
        for (size_t i = 0; i < array.size(); i++) {
            if (i != 0) writer << ' ';
            writer << array[i];
        }
    }

    void printLine(const std::vector<int> &array) {
        print(array);
        writer << '\n';
    }

private:
    std::ostream &writer;
};

class TaskB {
    long long x;

public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) {
        int count = in.readInt();
        int ones = in.readInt();
        x = in.readLong();
        std::vector<int> a(count);
        for (int i = 0; i < count; i++) {
            a[i] = i + 1;
        }
        shuffle(count, a);
        std::vector<int> b(count, 0);
        std::fill(b.begin(), b.begin() + ones, 1);
        shuffle(count, b);
        std::vector<int> answer(count, 0);
        int size = (count + 31) >> 5;
        std::vector<int> ready(size, 0);
        std::vector<int> mask(size, 0);
        for (int i = 0; i < size; i++) {
            for (int j = i * 32; j < (i + 1) * 32 && j < count; j++) {
                if (b[j] == 1) {
                    mask[i] += 1 << (j - i * 32);
                }
            }
        }
        std::vector<std::vector<int>> upMasks(32, std::vector<int>(size));
        std::vector<std::vector<int>> downMasks(32, std::vector<int>(size));
        for (int i = 0; i < 32; i++) {
            int filter = (i == 0) ? -1 : (1 << (32 - i)) - 1;
            int otherShift = 32 - i;
            for (int j = 0; j < size; j++) {
                upMasks[i][j] = mask[j] & filter;
                downMasks[i][j] = mask[j] >> otherShift;
            }
        }
        std::vector<int> order = createOrder(a);
        std::reverse(order.begin(), order.end());
        for (int i : order) {
            int value = a[i];
            int shift = i & 31;
            int otherShift = 32 - shift;
            int filter = (shift == 0) ? -1 : (1 << (32 - shift)) - 1;
            int start = i >> 5;
            int upTo = size - start - 1;
            int otherFilter = (1 << shift) - 1;
            if (otherFilter == -1) {
                otherFilter = 0;
            }
            for (int j = 0; j < upTo; j++) {
                if ((ready[j + start] >> shift & upMasks[shift][j]) != upMasks[shift][j]) {
                    for (int k = (j + start) * 32 + shift; k < (j + start + 1) * 32 && k < count; k++) {
                        if (b[k - i] == 1 && answer[k] == 0) {
                            answer[k] = value;
                            ready[k >> 5] += 1 << (k & 31);
                        }
                    }
                }
                if ((ready[j + start + 1] & downMasks[shift][j]) != downMasks[shift][j]) {
                    for (int k = (j + start + 1) * 32; k < (j + start + 1) * 32 + shift && k < count; k++) {
                        if (b[k - i] == 1 && answer[k] == 0) {
                            answer[k] = value;
                            ready[k >> 5] += 1 << (k & 31);
                        }
                    }
                }
            }
            if ((ready[upTo + start] >> shift & upMasks[shift][upTo]) != upMasks[shift][upTo]) {
                for (int k = (upTo + start) * 32 + shift; k < (upTo + start + 1) * 32 && k < count; k++) {
                    if (b[k - i] == 1 && answer[k] == 0) {
                        answer[k] = value;
                        ready[k >> 5] += 1 << (k & 31);
                    }
                }
            }
        }
        out.printLine(answer);
    }

protected:
    void shuffle(int count, std::vector<int> &a) {
        for (int i = 0; i < count; i++) {
            int index = next() % (i + 1);
            std::swap(a[i], a[index]);
        }
    }

private:
    int next() {
        x = (x * 37 + 10007) % 1000000007;
        return static_cast<int>(x);
    }

    std::vector<int> createOrder(const std::vector<int> &array) {
        std::vector<int> order(array.size());
        for (size_t i = 0; i < array.size(); i++) {
            order[i] = i;
        }
        return order;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    InputReader in(std::cin);
    OutputWriter out(std::cout);
    TaskB solver;
    solver.solve(1, in, out);
    return 0;
}
