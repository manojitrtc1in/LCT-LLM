#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class FastReader {
    public:
        FastReader() {}

        string next() {
            string str;
            cin >> str;
            return str;
        }

        int nextInt() {
            return stoi(next());
        }

        long long nextLong() {
            return stoll(next());
        }

        double nextDouble() {
            return stod(next());
        }

        string nextLine() {
            string str;
            cin.ignore();
            getline(cin, str);
            return str;
        }
};

class Pair {
public:
    int first;
    int second;

    friend ostream& operator<<(ostream& os, const Pair& p) {
        os << p.first << " " << p.second;
        return os;
    }
};

class Main {
public:
    static int countDigit(long long n) {
        return (int)floor(log10(n) + 1);
    }

    static int sumOfDigits(long long n) {
        if (n < 0) return -1;

        int sum = 0;

        while (n > 0) {
            sum += (int)(n % 10);
            n /= 10;
        }

        return sum;
    }

    static long long arraySum(vector<int>& arr, int start, int end) {
        long long ans = 0;

        for (int i = start; i <= end; i++) ans += arr[i];

        return ans;
    }

    static int mod(int x) {
        return (x < 0) ? -x : x;
    }

    static long long mod(long long x) {
        return (x < 0) ? -x : x;
    }

    static void swapArray(vector<int>& arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++; end--;
        }
    }

    static vector<vector<int>> rotate(vector<vector<int>>& input) {
        int n = input.size();
        int m = input[0].size();
        vector<vector<int>> output(m, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                output[j][n - 1 - i] = input[i][j];
        return output;
    }

    static int countBits(long long n) {
        int count = 0;
        while (n != 0) {
            count++;
            n = (n) >> (1LL);
        }
        return count;
    }

    static bool isPowerOfTwo(long long n) {
        if (n == 0) return false;
        return ((n) & (n - 1)) == 0;
    }

    static int min(int a, int b, int c, int d) {
        vector<int> arr = {a, b, c, d};
        sort(arr.begin(), arr.end());
        return arr[0];
    }

    static int max(int a, int b, int c, int d) {
        vector<int> arr = {a, b, c, d};
        sort(arr.begin(), arr.end());
        return arr[3];
    }

    static string reverse(const string& input) {
        string str;
        for (int i = input.length() - 1; i >= 0; i--) {
            str += input[i];
        }
        return str;
    }

    static bool sameParity(long long a, long long b) {
        return (a % 2) == (b % 2);
    }

    static bool isPossibleTriangle(int a, int b, int c) {
        return (a + b > c) && (c + b > a) && (a + c > b);
    }

    static long long xnor(long long num1, long long num2) {
        if (num1 < num2) swap(num1, num2);
        num1 = togglebit(num1);
        return num1 ^ num2;
    }

    static long long togglebit(long long n) {
        if (n == 0) return 1;
        long long i = n;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return i ^ n;
    }

    static int xorOfFirstN(int n) {
        if (n % 4 == 0) return n;
        else if (n % 4 == 1) return 1;
        else if (n % 4 == 2) return n + 1;
        else return 0;
    }

    static int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    static long long gcd(long long a, long long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    static long long lcm(long long a, long long b) {
        return (a * b) / gcd(a, b);
    }

    static bool isPrime(long long n) {
        if (n == 1) return false;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    static const int MAXN = 10000001;
    static vector<int> spf(MAXN);

    static void sieve() {
        spf[1] = 1;
        for (int i = 2; i < MAXN; i++) spf[i] = i;
        for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
        for (int i = 3; i * i < MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAXN; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
    }

    static vector<int> getFactorization(int x) {
        vector<int> ret;
        while (x != 1) {
            ret.push_back(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }

    static void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1);
        vector<int> R(n2);

        for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];

        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    static void sort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            sort(arr, l, m);
            sort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    static long long knapsack(vector<int>& weight, vector<long long>& value, int maxWeight) {
        int n = value.size();
        vector<long long> dp(maxWeight + 1, 0);

        for (int i = 0; i < n; i++)
            for (int j = maxWeight; j >= weight[i]; j--)
                dp[j] = max(dp[j], value[i] + dp[j - weight[i]]);

        return dp[maxWeight];
    }

    static long long kadanesAlgorithm(vector<long long>& arr) {
        vector<long long> dp(arr.size());
        dp[0] = arr[0];
        long long max = dp[0];

        for (int i = 1; i < arr.size(); i++) {
            dp[i] = (dp[i - 1] > 0) ? dp[i - 1] + arr[i] : arr[i];
            if (dp[i] > max) max = dp[i];
        }

        return max;
    }

    static long long binarySearchGreater(vector<int>& arr, int start, int end, int val) {
        if (start > end) return 0;

        int mid = (start + end) / 2;

        if (arr[mid] <= val) {
            return binarySearchGreater(arr, mid + 1, end, val);
        } else {
            return binarySearchGreater(arr, start, mid - 1, val) + end - mid + 1;
        }
    }

    static void printArray(const vector<int>& arr, int si, int ei) {
        for (int i = si; i <= ei; i++) {
            cout << arr[i] << " ";
        }
    }

    static void printArrayln(const vector<int>& arr, int si, int ei) {
        for (int i = si; i <= ei; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    static void solve() {
        FastReader scn;

        int testcases = 1;

        for (int testcase = 1; testcase <= testcases; testcase++) {
            long long n = scn.nextLong();
            long long a1 = scn.nextLong();
            long long a2 = scn.nextLong();
            long long a3 = scn.nextLong();
            long long b1 = scn.nextLong();
            long long b2 = scn.nextLong();
            long long b3 = scn.nextLong();

            long long min = 0LL;

            if (b1 >= a1 + a2) {
                min = a3 - b2 - b3;
            } else if (b2 >= a3 + a2) {
                min = a1 - b1 - b3;
            } else if (b3 >= a1 + a3) {
                min = a2 - b2 - b1;
            } else {
                min = 0;
            }

            long long max = min(a1, b2) + min(a2, b3) + min(a3, b1);

            cout << min << " " << max << endl;
        }
    }

    static void main() {
        solve();
    }
};

int main() {
    Main::main();
    return 0;
}
