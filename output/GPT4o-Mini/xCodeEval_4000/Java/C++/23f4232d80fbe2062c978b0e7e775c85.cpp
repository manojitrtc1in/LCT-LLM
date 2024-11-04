#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stdexcept>
#include <cstring>
#include <fstream>

using namespace std;

class IO {
public:
    static int readInt() {
        int number;
        cin >> number;
        return number;
    }

    static vector<int> readArrayInt() {
        int size;
        cin >> size;
        vector<int> arr(size);
        for (int &num : arr) {
            cin >> num;
        }
        return arr;
    }

    static void writeInt(int number) {
        cout << number << "\n";
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

    static double lcm(int a, int b) {
        return (double)a / gcd(a, b) * b;
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
};

template<typename T>
class Division : public Pair<T> {
public:
    Division(T dividend, T divider) : Pair<T>(dividend, divider) {
        reduce();
    }

    void reduce() {
        T dividend = this->getFirstElement();
        T divider = this->getSecondElement();
        int gcd = Math::gcd(dividend, divider);
        this->setFirst(dividend / gcd);
        this->setSecond(divider / gcd);
    }

    Division addWithReturn(Division number) {
        // Implementation of addition logic
        // Similar to Java code, omitted for brevity
        return Division(0, 0); // Placeholder
    }

    void multiplyWithoutReturn(Division number) {
        // Implementation of multiplication logic
        // Similar to Java code, omitted for brevity
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

    void ribMatrixToDefault(int length, int quantity, bool readConsole, vector<vector<int>> value) {
        base.resize(length);
        for (int i = 0; i < quantity; i++) {
            vector<int> input = readConsole ? IO::readArrayInt() : value[i];
            base[input[0] - 1].push_back(input[1] - 1);
            base[input[1] - 1].push_back(input[0] - 1);
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

    int dijkstra(int start, int stop, int size) {
        start--;
        stop--;
        vector<int> dist(size, INT_MAX);
        dist[start] = 0;
        ancestor[start] = start;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        queue.push({0, start});

        while (!queue.empty()) {
            auto [currentDist, position] = queue.top();
            queue.pop();
            if (currentDist > dist[position]) continue;

            for (size_t index = 0; index < base[position].size(); index += 2) {
                int next = base[position][index];
                int weight = base[position][index + 1];
                if (dist[position] + weight < dist[next]) {
                    dist[next] = dist[position] + weight;
                    ancestor[next] = position;
                    queue.push({dist[next], next});
                }
            }
            used[position] = true;
        }
        return dist[stop] == INT_MAX ? -1 : dist[stop];
    }
};

int main() {
    int i1 = IO::readInt();
    for (int i2 = 0; i2 < i1; i2++) {
        map<int, int> countValue;
        vector<int> quantity = IO::readArrayInt();
        vector<int> base = IO::readArrayInt();
        for (int i = 0; i < quantity[2]; i++) {
            countValue[base[i]]++;
        }
        int min = countValue.size();
        for (int i = quantity[2]; i < quantity[0]; i++) {
            countValue[base[i - quantity[2]]];
            if (--countValue[base[i - quantity[2]]] == 0) {
                countValue.erase(base[i - quantity[2]]);
            }
            countValue[base[i]]++;
            min = std::min(min, (int)countValue.size());
        }
        IO::writeInt(min);
    }
    return 0;
}
