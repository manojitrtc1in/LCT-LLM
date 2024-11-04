#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <random>
#include <string>
#include <sstream>

using namespace std;

const string id8 = "id8";
const string id10 = "id10";
const string YES = "YES";
const string NO = "NO";
const long MOD = 998244353;
const int RADIX = 10;

class MyScanner {
    ifstream br;
public:
    MyScanner(const string& filename) {
        br.open(filename);
    }

    MyScanner() {
        br.open("input.txt");
    }

    ~MyScanner() {
        br.close();
    }

    string next() {
        string s;
        br >> s;
        return s;
    }

    int nextInt() {
        int x;
        br >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        br >> x;
        return x;
    }

    double nextDouble() {
        double x;
        br >> x;
        return x;
    }

    vector<int> nextPairs(int n) {
        vector<int> xy[2];
        for (int i = 0; i < n; i++) {
            xy[0].push_back(nextInt());
            xy[1].push_back(nextInt());
        }
        return {xy[0], xy[1]};
    }
};

class id4 {
    ofstream out;
public:
    id4(const string& filename) {
        out.open(filename);
    }

    ~id4() {
        out.close();
    }

    void println(long long ans) {
        out << ans << endl;
    }

    void println(const vector<long long>& arr) {
        for (size_t i = 0; i < arr.size(); i++) {
            if (i > 0) out << " ";
            out << arr[i];
        }
        out << endl;
    }
};

class id3 {
    id4 out;
    MyScanner in;

    void initIO(bool id7) {
        if (getenv("ONLINE_JUDGE") == nullptr && id7) {
            in = MyScanner("input.txt");
            out = id4("output.txt");
        } else {
            in = MyScanner();
            out = id4("output.txt");
        }
    }

    void run() {
        bool isDebug = false;
        bool id7 = true;
        bool id1 = false;

        initIO(id7);

        int t = id1 ? in.nextInt() : 1;

        for (int i = 1; i <= t; ++i) {
            int n = in.nextInt();
            int m = in.nextInt();
            vector<int> u = in.nextPairs(m)[0];
            vector<int> v = in.nextPairs(m)[1];

            if (isDebug) {
                out.println("Test " + to_string(i));
            }

            long ans = solve2(u, v, n);
            out.println(ans);

            if (isDebug)
                out.flush();
        }
    }

    void validate(const vector<int>& u, const vector<int>& v, int n) {
        set<string> set;
        vector<vector<int>> cmp(RADIX, vector<int>(RADIX, 0));
        for (int i = 0; i < u.size(); i++) {
            int small = min(u[i], v[i]);
            int large = max(u[i], v[i]);
            cmp[small][large] = -1;
            cmp[large][small] = 1;
        }

        long long curr = 0;
        long long limit = pow(RADIX, n);
        stringstream sb;
        while (curr < limit) {
            sb.str("");
            sb << curr;
            string s = sb.str();
            int padding = n - s.length();
            sb.str(string(padding, '0') + s);
            vector<char> arr(sb.str().begin(), sb.str().end());
            sort(arr.begin(), arr.end(), [&](char o1, char o2) {
                return cmp[o1 - '0'][o2 - '0'] < 0;
            });

            set.insert(string(arr.begin(), arr.end()));
            curr++;
        }
        out.println(set.size());
        for (const auto& str : set) {
            out.println(str);
        }
    }

    long solve2(const vector<int>& u, const vector<int>& v, int n) {
        vector<long> dp(1 << RADIX, 0);
        for (int j = 0; j < RADIX; j++) {
            dp[1 << j] = 1;
        }

        vector<vector<int>> cmp(RADIX, vector<int>(RADIX, 0));
        int m = u.size();
        for (int i = 0; i < m; i++) {
            int small = min(u[i], v[i]);
            int larger = max(u[i], v[i]);
            cmp[small][larger] = -1;
            cmp[larger][small] = 1;
        }

        vector<vector<bool>> isValid(1 << RADIX, vector<bool>(RADIX, false));
        vector<vector<int>> map(1 << RADIX, vector<int>(RADIX, 0));

        for (int mask = 0; mask < (1 << RADIX); mask++) {
            for (int j = 0; j < RADIX; j++) {
                bool ok = true;
                int next = 1 << j;
                for (int k = 0; k < RADIX; k++) {
                    if ((1 << k & mask) == 0)
                        continue;

                    if (cmp[j][k] == 0) {
                    } else if (cmp[j][k] == -1) {
                        next |= 1 << k;
                    } else {
                        ok = false;
                    }
                }
                isValid[mask][j] = ok;
                map[mask][j] = next;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            vector<long> next(1 << RADIX, 0);
            for (int mask = 0; mask < (1 << RADIX); mask++) {
                for (int j = 0; j < RADIX; j++) {
                    if (!isValid[mask][j])
                        continue;
                    int mask2 = map[mask][j];
                    long val = next[mask2] + dp[mask];
                    next[mask2] = val < MOD ? val : val - MOD;
                }
            }
            dp = next;
        }

        long sum = 0;
        for (int mask = 0; mask < (1 << RADIX); mask++)
            sum += dp[mask];

        return sum % MOD;
    }

public:
    static void main() {
        id3 sol;
        sol.run();
    }
};

int main() {
    id3::main();
    return 0;
}
