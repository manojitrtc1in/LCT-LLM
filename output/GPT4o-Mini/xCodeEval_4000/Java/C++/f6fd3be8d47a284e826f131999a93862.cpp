#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <string>
#include <sstream>
#include <iomanip>
#include <numeric>

using namespace std;

const string IMPOSSIBLE = "IMPOSSIBLE";
const string POSSIBLE = "POSSIBLE";
const string YES = "YES";
const string NO = "NO";
const long MOD = 1'000'000'007;

class MyScanner {
    ifstream inFile;
    stringstream ss;

public:
    MyScanner(istream &is) {
        ss.clear();
        ss.str("");
        string line;
        while (getline(is, line)) {
            ss << line << '\n';
        }
    }

    int nextInt() {
        int x;
        ss >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        ss >> x;
        return x;
    }

    string next() {
        string s;
        ss >> s;
        return s;
    }

    void close() {
        inFile.close();
    }
};

class MyPrintWriter {
    ostream &out;

public:
    MyPrintWriter(ostream &os) : out(os) {}

    void println(long long ans) {
        out << ans << '\n';
    }

    void println(int ans) {
        out << ans << '\n';
    }

    void println(bool ans) {
        out << (ans ? YES : NO) << '\n';
    }

    void printAns(const vector<long long> &arr) {
        if (!arr.empty()) {
            out << arr[0];
            for (size_t i = 1; i < arr.size(); ++i) {
                out << " " << arr[i];
            }
        }
    }

    void println(const vector<long long> &arr) {
        printAns(arr);
        out << '\n';
    }
};

class Round818E {
    MyPrintWriter out;
    MyScanner in;

    int n;
    long long ans;
    vector<long long> check;

    void getInput() {
        n = in.nextInt();
    }

    void printOutput() {
        out.println(ans);
    }

    long long gcd(long long a, long long b) {
        if (a < b) swap(a, b);
        while (b > 0) {
            long long r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    void solve() {
        vector<vector<int>> primeFactors(n + 1);
        for (int i = 2; i <= n; i++) {
            if (primeFactors[i].empty()) {
                primeFactors[i].push_back(i);
                if (n / i >= i) {
                    for (int j = i * i; j <= n; j += i) {
                        if (primeFactors[j].empty())
                            primeFactors[j].push_back(i);
                    }
                }
            } else {
                int prime = primeFactors[i][0];
                int rest = i / prime;
                while (rest % prime == 0)
                    rest /= prime;
                if (rest > 1)
                    for (int factor : primeFactors[rest])
                        primeFactors[i].push_back(factor);
            }
        }

        ans = 0;
        check.resize(n + 1);
        for (long long g = 1; g <= n; g++) {
            if (g * 2 + 1 > n)
                break;
            long long cnt = 0;
            long long sum = 0;

            for (int ap = 2; ap <= n; ap++) {
                if (g * (ap + 1) + 1 > n)
                    break;

                long long maxBp = min(ap - 1, (n - 1) / g - ap);
                long long currCnt = maxBp;
                sum += maxBp * (maxBp + 1) / 2 % MOD;

                int k = primeFactors[ap].size();
                for (int mask = 1; mask < (1 << k); mask++) {
                    long long curr = 1;
                    int sign = 1;
                    for (int pos = 0; pos < k; pos++) {
                        if ((mask & (1 << pos)) > 0) {
                            curr *= primeFactors[ap][pos];
                            sign *= -1;
                        }
                    }

                    long long s = min((ap - 1) / curr, (n - 1 - g * ap) / curr / g);
                    currCnt += s * sign;
                    sum += curr * s * (s + 1) / 2 * sign;
                }

                cnt += currCnt;
                sum += currCnt * ap;
                sum %= MOD;
            }

            cnt *= 2;
            sum *= g * 2;

            cnt++;
            sum += g * 2;

            cnt %= MOD;
            sum %= MOD;
            if (sum < 0)
                sum += MOD;

            check[(int)g] -= ans;
            long long k = gcd(g, n);
            ans += g * n / k * cnt % MOD;
            ans -= g / k * sum % MOD;
            check[(int)g] += ans;
        }
        ans %= MOD;
        if (ans < 0)
            ans += MOD;
    }

public:
    Round818E(istream &input, ostream &output) : in(input), out(output) {}

    void run() {
        bool isFileIO = true;
        initIO(isFileIO);

        getInput();
        solve();
        printOutput();
    }

    void initIO(bool isFileIO) {
        if (!isFileIO) {
            in = MyScanner(cin);
            out = MyPrintWriter(cout);
        }
    }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    Round818E sol(inputFile.is_open() ? inputFile : cin, outputFile.is_open() ? outputFile : cout);
    sol.run();
    return 0;
}
