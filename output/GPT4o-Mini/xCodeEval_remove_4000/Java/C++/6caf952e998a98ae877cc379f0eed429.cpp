#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;

class InputReader {
public:
    InputReader(istream &stream) : stream(stream) {}

    int read() {
        return stream.get();
    }

    int readInt() {
        int res;
        stream >> res;
        return res;
    }

    long readLong() {
        long res;
        stream >> res;
        return res;
    }

    string readString() {
        string res;
        stream >> res;
        return res;
    }

    char readCharacter() {
        return stream.get();
    }

    double readDouble() {
        double res;
        stream >> res;
        return res;
    }

private:
    istream &stream;
};

class OutputWriter {
public:
    OutputWriter(ostream &outputStream) : writer(outputStream) {}

    void print(int value) {
        writer << value;
    }

    void printLine(int value) {
        writer << value << endl;
    }

    void printLine() {
        writer << endl;
    }

private:
    ostream &writer;
};

class Task {
public:
    virtual void solve(int testNumber, InputReader &in, OutputWriter &out) = 0;
};

class A : public Task {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) override {
        string str = in.readString();
        int ret = 0, n = str.length(), c = 0;
        for (int i = 1; i < n; i++) {
            if (str[i] != str[i - 1]) {
                ret += c % 2;
                c = 0;
            } else {
                c++;
            }
        }
        ret += c % 2;
        out.printLine(ret);
    }
};

class B : public Task {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) override {
        string str = in.readString();
        string ret;
        for (char c : str) {
            if (c == '>') ret += "1000";
            else if (c == '<') ret += "1001";
            else if (c == '+') ret += "1010";
            else if (c == '-') ret += "1011";
            else if (c == '.') ret += "1100";
            else if (c == ',') ret += "1101";
            else if (c == '[') ret += "1110";
            else ret += "1111";
        }
        int n = 0;
        for (char c : ret) n = (2 * n + c - '0') % 1000003;
        out.printLine(n);
    }
};

class C : public Task {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) override {
        // Implementation for C
    }
};

class D : public Task {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) override {
        // Implementation for D
    }
};

class E : public Task {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) override {
        // Implementation for E
    }
};

class F : public Task {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) override {
        // Implementation for F
    }
};

class Main {
public:
    static void main() {
        InputReader in(cin);
        OutputWriter out(cout);
        Task *solver = new A();
        solver->solve(1, in, out);
        delete solver;
    }
};

int main() {
    Main::main();
    return 0;
}
