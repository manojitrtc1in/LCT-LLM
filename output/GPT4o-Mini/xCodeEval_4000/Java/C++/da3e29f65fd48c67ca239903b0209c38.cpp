#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>
#include <stdexcept>
#include <fstream>

using namespace std;

class IO {
public:
    static int readInt() {
        int value;
        cin >> value;
        return value;
    }

    static long readLong() {
        long value;
        cin >> value;
        return value;
    }

    static vector<int> readArrayInt(char delimiter) {
        string line;
        getline(cin, line);
        vector<int> result;
        size_t pos = 0;
        while ((pos = line.find(delimiter)) != string::npos) {
            result.push_back(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        result.push_back(stoi(line));
        return result;
    }

    static void writeInt(int number, const string& end = "\n") {
        cout << number << end;
    }

    static void writeLong(long number, const string& end = "\n") {
        cout << number << end;
    }
};

class Math {
public:
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static double lcm(int a, int b) {
        return static_cast<double>(a) / gcd(a, b) * b;
    }

    static long factorial(int number) {
        if (number < 0) return 0;
        return solveFactorial(number);
    }

private:
    static long solveFactorial(int number) {
        return number > 0 ? solveFactorial(number - 1) * number : 1;
    }
};

class Main {
public:
    static void main() {
        int g = IO::readInt();
        int sh = IO::readInt();
        int j = IO::readInt();
        int p = IO::readInt();
        int priceFirst = IO::readInt();
        int priceSecond = IO::readInt();
        long answer = 0;

        if (priceFirst <= priceSecond) {
            answer = min({sh, j, p});
            p -= answer;
            answer *= priceSecond;
            answer += (min(p, g) * priceFirst);
        } else {
            answer = min(g, p);
            p -= answer;
            answer *= priceFirst;
            answer += (min({sh, j, p}) * priceSecond);
        }
        IO::writeLong(answer);
    }
};

int main() {
    Main::main();
    return 0;
}
