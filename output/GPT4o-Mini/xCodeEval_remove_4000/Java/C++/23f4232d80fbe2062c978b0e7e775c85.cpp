#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <fstream>
#include <sstream>
#include <stdexcept>

class IO {
public:
    static int readInt() {
        int number;
        std::cin >> number;
        return number;
    }

    static std::vector<int> readIntArray(char delimiter) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::vector<int> result;
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            result.push_back(std::stoi(token));
        }
        return result;
    }

    static void writeInt(int number, const std::string& end) {
        std::cout << number << end;
    }

    static void print() {
        std::cout.flush();
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

    static float gcd(float a, float b) {
        return b == 0 ? a : gcd(b, a);
    }

    static double gcd(double a, double b) {
        return b == 0 ? a : gcd(b, a);
    }

    static double lcm(double a, double b) {
        return a / gcd(a, b) * b;
    }

    static float lcm(float a, float b) {
        return a / gcd(a, b) * b;
    }

    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
};

template <typename T>
class Division {
private:
    T dividend;
    T divider;

    void reduce() {
        int gcd = Math::gcd(dividend, divider);
        dividend /= gcd;
        divider /= gcd;
    }

public:
    Division(T dividend, T divider) : dividend(dividend), divider(divider) {
        reduce();
    }

    Division add(const Division& other) const {
        T lcm = Math::lcm(divider, other.divider);
        T newDividend = (lcm / divider) * dividend + (lcm / other.divider) * other.dividend;
        return Division(newDividend, lcm);
    }

    Division multiply(const Division& other) const {
        return Division(dividend * other.dividend, divider * other.divider);
    }

    T getDividend() const { return dividend; }
    T getDivider() const { return divider; }
};

class Main {
public:
    static void main() {
        int i1 = IO::readInt();
        for (int i2 = 0; i2 < i1; i2++) {
            std::map<int, int> countValue;
            std::vector<int> quantity = IO::readIntArray(' ');
            std::vector<int> base = IO::readIntArray(' ');

            for (int i = 0; i < quantity[2]; i++) {
                countValue[base[i]]++;
            }

            int min = countValue.size();
            for (int i = quantity[2]; i < quantity[0]; i++) {
                if (--countValue[base[i - quantity[2]]] == 0) {
                    countValue.erase(base[i - quantity[2]]);
                }
                countValue[base[i]]++;
                min = std::min(min, static_cast<int>(countValue.size()));
            }
            IO::writeInt(min, "\n");
        }
        IO::print();
    }
};

int main() {
    Main::main();
    return 0;
}
