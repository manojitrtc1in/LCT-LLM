#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <random>

using namespace std;

class InputReader {
private:
    istringstream stream;

public:
    InputReader(istream &input) {
        string buffer;
        getline(input, buffer);
        stream = istringstream(buffer);
    }

    long long readLong() {
        long long value;
        stream >> value;
        return value;
    }
};

class OutputWriter {
private:
    ostream &output;

public:
    OutputWriter(ostream &outputStream) : output(outputStream) {}

    void printLine(long long value) {
        output << value << endl;
    }
};

class Task {
private:
    map<long long, int> map;
    map<long long, vector<long long>> divides;
    long long dp[2][1000]; // Adjust size as needed
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

public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) {
        long long A = in.readLong();
        for (long long i = 1; i * i <= A; i++) {
            if (A % i == 0) {
                process(i);
                if (i * i != A) process(A / i);
            }
        }

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
};

class Main {
public:
    static void main() {
        InputReader in(cin);
        OutputWriter out(cout);
        Task solver;
        solver.solve(1, in, out);
    }
};

int main() {
    Main::main();
    return 0;
}
