#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stdexcept>
#include <fstream>
#include <sstream>

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

    static void writeInt(int number) {
        std::cout << number << "\n";
    }
};

class Math {
public:
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static float gcd(float a, float b) {
        return b == 0 ? a : gcd(b, std::fmod(a, b));
    }

    static double gcd(double a, double b) {
        return b == 0 ? a : gcd(b, std::fmod(a, b));
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

    static long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
};

template<typename T>
class Division {
private:
    T first;
    T second;

    void reduce() {
        int gcd = Math::gcd(first, second);
        first /= gcd;
        second /= gcd;
    }

public:
    Division(T dividend, T divider) : first(dividend), second(divider) {
        reduce();
    }

    Division add(const Division& number) {
        T lcm = Math::lcm(second, number.second);
        T newFirst = (lcm / second) * first + (lcm / number.second) * number.first;
        return Division(newFirst, lcm);
    }

    Division multiply(const Division& number) {
        return Division(first * number.first, second * number.second);
    }

    void print() const {
        std::cout << first << "/" << second;
    }
};

class Main {
public:
    static void main() {
        int i1 = IO::readInt();
        for (int i2 = 0; i2 < i1; i2++) {
            std::unordered_map<int, int> countValue;
            std::vector<int> quantity = IO::readIntArray(' ');
            std::vector<int> base = IO::readIntArray(' ');

            for (int i = 0; i < quantity[2]; i++) {
                countValue[base[i]]++;
            }
            int min = countValue.size();

            for (int i = quantity[2]; i < quantity[0]; i++) {
                countValue[base[i - quantity[2]]]--;
                if (countValue[base[i - quantity[2]]] == 0) {
                    countValue.erase(base[i - quantity[2]]);
                }
                countValue[base[i]]++;
                min = std::min(min, static_cast<int>(countValue.size()));
            }
            IO::writeInt(min);
        }
    }
};

int main() {
    Main::main();
    return 0;
}
