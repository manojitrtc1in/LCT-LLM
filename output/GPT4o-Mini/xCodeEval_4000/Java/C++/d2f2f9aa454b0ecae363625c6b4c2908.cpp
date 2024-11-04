#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;

class IO {
public:
    static int readInt() {
        int number;
        cin >> number;
        return number;
    }

    static vector<int> readArrayInt(const string& split) {
        string line;
        cin.ignore();
        getline(cin, line);
        stringstream ss(line);
        vector<int> result;
        string token;
        while (getline(ss, token, ' ')) {
            result.push_back(stoi(token));
        }
        return result;
    }

    static void writeInt(int number, const string& end) {
        cout << number << end;
    }

    static void print() {
        cout.flush();
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
        return b == 0 ? a : gcd(b, fmod(a, b));
    }

    static double gcd(double a, double b) {
        return b == 0 ? a : gcd(b, fmod(a, b));
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
class Pair {
private:
    T first;
    T second;

public:
    Pair(T obj, T obj1) : first(obj), second(obj1) {}

    T getFirstElement() {
        return first;
    }

    T getSecondElement() {
        return second;
    }

    void setFirst(T element) {
        first = element;
    }

    void setSecond(T element) {
        second = element;
    }

    bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }
};

template<typename T>
class Division : public Pair<T> {
public:
    Division(T dividend, T divider) : Pair<T>(dividend, divider) {
        reduce();
    }

    static Division<T> createDivision(T dividend, T divider) {
        return Division<T>(dividend, divider);
    }

    void reduce() {
        T Dividend = this->getFirstElement();
        T Divider = this->getSecondElement();
        int gcd = Math::gcd(Dividend, Divider);
        this->setFirst(Dividend / gcd);
        this->setSecond(Divider / gcd);
    }

    Division addWithReturn(Division number) {
        return add(number, 1);
    }

private:
    Division add(Division number, int function) {
        // Implement addition logic similar to Java version
        // ...
        throw std::runtime_error("Unsupported operation");
    }
};

class Graph {
private:
    vector<vector<int>> base;
    vector<bool> used;
    int quantity;
    vector<int> ancestor;

public:
    void start(int length) {
        used.resize(length, false);
        ancestor.resize(length, -1);
        quantity = 0;
    }

    void ribMatrixToDefault(int length, int quantity, bool readConsole, vector<vector<int>>& value) {
        base.resize(length);
        vector<vector<int>> inputBase(length);
        for (int i = 0; i < quantity; i++) {
            vector<int> input = readConsole ? IO::readArrayInt(" ") : value[i];
            inputBase[input[0] - 1].push_back(input[1] - 1);
            inputBase[input[1] - 1].push_back(input[0] - 1);
        }
        for (int i = 0; i < length; i++) {
            base[i] = inputBase[i];
        }
        start(length);
    }

    void dfs(int position) {
        used[position] = true;
        quantity++;
        for (int next : base[position]) {
            if (!used[next]) {
                ancestor[next] = position;
                dfs(next);
            } else if (next != ancestor[position]) {
                throw runtime_error("Cycle detected");
            }
        }
    }

    // Implement other methods as needed...
};

int main() {
    int i1 = IO::readInt();
    for (int i2 = 0; i2 < i1; i2++) {
        map<int, int> countValue;
        vector<int> quantity = IO::readArrayInt(" ");
        vector<int> base = IO::readArrayInt(" ");
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
            min = std::min(min, (int)countValue.size());
        }
        IO::writeInt(min, "\n");
    }
    IO::print();
    return 0;
}
