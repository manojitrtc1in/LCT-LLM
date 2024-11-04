#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
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

    static vector<int> readIntArray(char delimiter) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> result;
        string token;
        while (getline(ss, token, delimiter)) {
            result.push_back(stoi(token));
        }
        return result;
    }

    static void writeInt(int number, const string& end) {
        cout << number << end;
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

    static double lcm(double a, double b) {
        return a / gcd(a, b) * b;
    }

    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
};

template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    Pair(T obj, T obj1) : first(obj), second(obj1) {}

    T getFirst() { return first; }
    T getSecond() { return second; }

    void setFirst(T element) { first = element; }
    void setSecond(T element) { second = element; }

    bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }
};

template <typename T>
class Division : public Pair<T> {
public:
    Division(T dividend, T divider) : Pair<T>(dividend, divider) {
        reduce();
    }

    void reduce() {
        if constexpr (is_same<T, int>::value) {
            int gcdValue = Math::gcd(this->getFirst(), this->getSecond());
            this->setFirst(this->getFirst() / gcdValue);
            this->setSecond(this->getSecond() / gcdValue);
        }
        // Add similar cases for long, float, double if needed
    }

    Division add(Division number) {
        // Implement addition logic
        // Similar to the Java code
    }

    Division multiply(Division number) {
        // Implement multiplication logic
        // Similar to the Java code
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

    void readGraph(int length, int quantity) {
        base.resize(length);
        for (int i = 0; i < quantity; i++) {
            vector<int> input = IO::readIntArray(' ');
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
                int neighbor = base[position][index];
                int weight = base[position][index + 1];
                if (dist[position] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[position] + weight;
                    ancestor[neighbor] = position;
                    queue.push({dist[neighbor], neighbor});
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
        vector<int> quantity = IO::readIntArray(' ');
        vector<int> base = IO::readIntArray(' ');

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
            min = min < countValue.size() ? min : countValue.size();
        }
        IO::writeInt(min, "\n");
    }
    return 0;
}
