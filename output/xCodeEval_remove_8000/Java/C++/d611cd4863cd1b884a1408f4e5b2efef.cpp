#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <set>
#include <random>
#include <cassert>

using namespace std;

template<typename T>
class InputReader {
public:
    T read() {
        T value;
        cin >> value;
        return value;
    }

    vector<T> readVector(int size) {
        vector<T> vec(size);
        for (int i = 0; i < size; i++) {
            vec[i] = read();
        }
        return vec;
    }
};

template<typename T>
class OutputWriter {
public:
    void print(T value) {
        cout << value;
    }

    void printLine(T value) {
        cout << value << endl;
    }

    void printVector(const vector<T>& vec) {
        for (const T& value : vec) {
            cout << value << " ";
        }
        cout << endl;
    }
};

class Main {
public:
    static void main() {
        InputReader<long long> in;
        OutputWriter<long long> out;
        long long A = in.read();

        map<long long, int> mp;
        map<long long, vector<long long>> divides;
        vector<vector<long long>> dp(2, vector<long long>(mp.size()));

        int idx = 0;
        vector<long long> list;

        for (long long i = 1; i * i <= A; i++) {
            if (A % i == 0) {
                process(i, mp, divides, idx, list);
                if (i * i != A) {
                    process(A / i, mp, divides, idx, list);
                }
            }
        }

        dp[0][mp[1LL]] = 1;
        idx = 0;

        for (const auto& entry : divides) {
            idx ^= 1;

            for (const auto& j : mp) {
                int j2 = j.second;
                dp[idx][j2] = dp[idx ^ 1][j2];
                for (const auto& x : entry.second) {
                    if (j.first % x == 0) {
                        dp[idx][j2] += dp[idx ^ 1][mp[j.first / x]];
                    }
                }
            }
        }

        out.printLine(dp[idx][mp[A]]);
    }

    static long long prime(long long n) {
        if (n <= 1) return -1;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n /= i;
                }
                return n == 1 ? i : -1;
            }
        }
        return n;
    }

    static void process(long long x, map<long long, int>& mp, map<long long, vector<long long>>& divides, int& idx, vector<long long>& list) {
        mp[x] = idx++;
        long long p = prime(x - 1);
        if (p > 0) {
            if (divides.find(p) == divides.end()) {
                divides[p] = vector<long long>();
            }
            divides[p].push_back(x);
        }
    }
};

int main() {
    Main::main();
    return 0;
}
