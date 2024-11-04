#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <list>
#include <set>
#include <iterator>

using namespace std;

class InputReader {
public:
    InputReader(istream &stream) : stream(stream) {}

    int read() {
        if (stream.eof()) return -1;
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
            if (c < '0' || c > '9') throw invalid_argument("InputMismatchException");
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
            if (c < '0' || c > '9') throw invalid_argument("InputMismatchException");
            res = res * 10 + (c - '0');
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    bool isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

private:
    istream &stream;
};

class OutputWriter {
public:
    OutputWriter(ostream &outputStream) : writer(outputStream) {}

    void printLine(long long i) {
        writer << i << endl;
    }

    void printLine() {
        writer << endl;
    }

private:
    ostream &writer;
};

class Task {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) {
        long long A = in.readLong();
        for (long long i = 1; i * i <= A; i++) {
            if (A % i == 0) {
                process(i);
                if (i * i != A) process(A / i);
            }
        }
        dp.resize(2, vector<long long>(map.size(), 0));
        dp[0][map[1]] = 1;
        int idx = 0;
        for (const auto &i : divides) {
            idx ^= 1;
            for (const auto &j : map) {
                int j2 = j.second;
                dp[idx][j2] = dp[idx ^ 1][j2];
                for (const auto &x : divides[i.first]) {
                    if (j.first % x == 0) {
                        dp[idx][j2] += dp[idx ^ 1][map[j.first / x]];
                    }
                }
            }
        }
        out.printLine(dp[idx][map[A]]);
    }

private:
    map<long long, int> map;
    map<long long, vector<long long>> divides;
    vector<vector<long long>> dp;
    int idx = 0;

    long long prime(long long n) {
        if (n <= 1) return -1;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) n /= i;
                return n == 1 ? i : -1;
            }
        }
        return n;
    }

    void process(long long x) {
        map[x] = idx++;
        long long p = prime(x - 1);
        if (p > 0) {
            divides[p].push_back(x);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    InputReader in(cin);
    OutputWriter out(cout);
    Task solver;
    solver.solve(1, in, out);
    return 0;
}
