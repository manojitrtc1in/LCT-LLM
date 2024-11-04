#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
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
            getline(cin, str);
            return str;
        }
};

int countDigit(long long n) {
    return (int)floor(log10(n) + 1);
}

int id2(long long n) {
    if (n < 0) return -1;
    int sum = 0;
    while (n > 0) {
        sum += (int)(n % 10);
        n /= 10;
    }
    return sum;
}

long long arraySum(int arr[], int start, int end) {
    long long ans = 0;
    for (int i = start; i <= end; i++) ans += arr[i];
    return ans;
}

int mod(int x) {
    return (x < 0) ? -x : x;
}

long long mod(long long x) {
    return (x < 0) ? -x : x;
}

void swapArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; end--;
    }
}

int** rotate(int** input, int n, int m) {
    int** output = new int*[m];
    for (int i = 0; i < m; i++) output[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            output[j][n - 1 - i] = input[i][j];
    return output;
}

int countBits(long long n) {
    int count = 0;
    while (n != 0) {
        count++;
        n = (n) >> (1LL);
    }
    return count;
}

bool id0(long long n) {
    return (n == 0) ? false : (((n) & (n - 1)) == 0);
}

int min(int a, int b, int c, int d) {
    int arr[4] = {a, b, c, d};
    sort(arr, arr + 4);
    return arr[0];
}

int max(int a, int b, int c, int d) {
    int arr[4] = {a, b, c, d};
    sort(arr, arr + 4);
    return arr[3];
}

string reverse(const string& input) {
    string str = "";
    for (int i = input.length() - 1; i >= 0; i--) {
        str += input[i];
    }
    return str;
}

bool sameParity(long long a, long long b) {
    return (a % 2) == (b % 2);
}

bool id5(int a, int b, int c) {
    return (a + b > c && c + b > a && a + c > b);
}

long long xnor(long long num1, long long num2) {
    if (num1 < num2) swap(num1, num2);
    num1 = togglebit(num1);
    return num1 ^ num2;
}

long long togglebit(long long n) {
    if (n == 0) return 1;
    long long i = n;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return i ^ n;
}

int id6(int n) {
    if (n % 4 == 0) return n;
    else if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    else return 0;
}

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

bool isPrime(long long n) {
    if (n == 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

const int sieve = 1000000;
bool prime[sieve + 1];

void id4() {
    for (int i = 4; i <= sieve; i++) {
        prime[i] = true;
        i++;
    }
    for (int p = 3; p * p <= sieve; p++) {
        if (!prime[p]) {
            for (int i = p * p; i <= sieve; i += p)
                prime[i] = true;
        }
        p++;
    }
}

void sortD(int arr[], int s, int e) {
    sort(arr + s, arr + e + 1);
    int i = s, j = e;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++; j--;
    }
}

void sortD(long arr[], int s, int e) {
    sort(arr + s, arr + e + 1);
    int i = s, j = e;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++; j--;
    }
}

long long id1(long long arr[], long long sum) {
    unordered_map<long long, long long> map;
    int n = sizeof(arr) / sizeof(arr[0]);
    long long prefixsum = 0;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        prefixsum += arr[i];
        if (sum == prefixsum) count++;
        if (map.find(prefixsum - sum) != map.end()) {
            count += map[prefixsum - sum];
        }
        if (map.find(prefixsum) != map.end()) {
            map[prefixsum]++;
        } else {
            map[prefixsum] = 1;
        }
    }
    return count;
}

vector<int> id3(const string& str, const string& pat) {
    vector<int> list;
    int n = str.length();
    int m = pat.length();
    string q = pat + " ";
    vector<int> lps(n + m + 1);
    longestPefixSuffix(lps, q, (n + m + 1));
    for (int i = m + 1; i < (n + m + 1); i++) {
        if (lps[i] == m) {
            list.push_back(i - 2 * m);
        }
    }
    return list;
}

void longestPefixSuffix(vector<int>& lps, const string& str, int n) {
    lps[0] = 0;
    for (int i = 1; i <= n - 1; i++) {
        int l = lps[i - 1];
        while (l > 0 && str[i] != str[l]) {
            l = lps[l - 1];
        }
        if (str[i] == str[l]) {
            l++;
        }
        lps[i] = l;
    }
}

void eulerTotientFunction(int arr[], int n) {
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 2; i <= n; i++) {
        if (arr[i] == i) {
            arr[i] = i - 1;
            for (int j = 2 * i; j <= n; j += i) {
                arr[j] = (arr[j] * (i - 1)) / i;
            }
        }
    }
}

long long nCr(int n, int k) {
    long long ans = 1;
    k = k > n - k ? n - k : k;
    for (int j = 1; j <= k; j++, n--) {
        if (n % j == 0) {
            ans *= n / j;
        } else if (ans % j == 0) {
            ans = ans / j * n;
        } else {
            ans = (ans * n) / j;
        }
    }
    return ans;
}

vector<int> allFactors(int n) {
    vector<int> list;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                list.push_back(i);
            } else {
                list.push_back(i);
                list.push_back(n / i);
            }
        }
    }
    return list;
}

vector<long long> allFactors(long long n) {
    vector<long long> list;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                list.push_back(i);
            } else {
                list.push_back(i);
                list.push_back(n / i);
            }
        }
    }
    return list;
}

const int MAXN = 10000001;
int spf[MAXN];

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
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

void sort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void sort(long arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(long arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    long L[n1], R[n2];
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
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

long long knapsack(int weight[], long long value[], int maxWeight) {
    int n = sizeof(value) / sizeof(value[0]);
    long long dp[maxWeight + 1];
    fill(dp, dp + maxWeight + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = maxWeight; j >= weight[i]; j--)
            dp[j] = max(dp[j], value[i] + dp[j - weight[i]]);
    return dp[maxWeight];
}

long long kadanesAlgorithm(long arr[]) {
    long dp[sizeof(arr) / sizeof(arr[0])];
    dp[0] = arr[0];
    long max = dp[0];
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {
        dp[i] = (dp[i - 1] > 0) ? dp[i - 1] + arr[i] : arr[i];
        if (dp[i] > max) max = dp[i];
    }
    return max;
}

long long kadanesAlgorithm(int arr[]) {
    long dp[sizeof(arr) / sizeof(arr[0])];
    dp[0] = arr[0];
    long max = dp[0];
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {
        dp[i] = (dp[i - 1] > 0) ? dp[i - 1] + arr[i] : arr[i];
        if (dp[i] > max) max = dp[i];
    }
    return max;
}

long long binarySearchGreater(int arr[], int start, int end, int val) {
    if (start > end) return 0;
    int mid = (start + end) / 2;
    if (arr[mid] <= val) {
        return binarySearchGreater(arr, mid + 1, end, val);
    } else {
        return binarySearchGreater(arr, start, mid - 1, val) + end - mid + 1;
    }
}

string swapString(const string& a, int i, int j) {
    string b = a;
    swap(b[i], b[j]);
    return b;
}

void generatePermutation(string str, int start, int end) {
    if (start == end - 1) {
        cout << str << endl;
    } else {
        for (int i = start; i < end; i++) {
            str = swapString(str, start, i);
            generatePermutation(str, start + 1, end);
            str = swapString(str, start, i);
        }
    }
}

long long factMod(long long n, long long mod) {
    if (n <= 1) return 1;
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * i) % mod;
    }
    return ans;
}

long long power(long long x, long long n) {
    if (n == 0) return 1LL;
    if (n == 1) return x;
    long long ans = 1LL;
    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * x;
        }
        n /= 2;
        x = x * x;
    }
    return ans;
}

long long powerMod(long long x, long long n, long long mod) {
    if (n == 0) return 1LL;
    if (n == 1) return x;
    long long ans = 1;
    while (n > 0) {
        if (n % 2 == 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return ans;
}

long long lowerBound(long arr[], long k) {
    long ans = -1;
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] <= k) {
            ans = arr[mid];
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int lowerBound(int arr[], int k) {
    int ans = -1;
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] <= k) {
            ans = arr[mid];
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

long long upperBound(long arr[], long k) {
    long ans = -1;
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] >= k) {
            ans = arr[mid];
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int upperBound(int arr[], int k) {
    int ans = -1;
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] >= k) {
            ans = arr[mid];
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

void printArray(int arr[], int si, int ei) {
    for (int i = si; i <= ei; i++) {
        cout << arr[i] << " ";
    }
}

void printArrayln(int arr[], int si, int ei) {
    for (int i = si; i <= ei; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printLArray(long arr[], int si, int ei) {
    for (int i = si; i <= ei; i++) {
        cout << arr[i] << " ";
    }
}

void printLArrayln(long arr[], int si, int ei) {
    for (int i = si; i <= ei; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printtwodArray(int** ans, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

long long modPow(long long a, long long x, long long p) {
    long long res = 1;
    while (x > 0) {
        if (x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

long long modInverse(long long a, long long p) {
    return modPow(a, p - 2, p);
}

long long modBinomial(long long n, long long k, long long p) {
    long long numerator = 1;
    for (int i = 0; i < k; i++) {
        numerator = (numerator * (n - i)) % p;
    }
    long long denominator = 1;
    for (int i = 1; i <= k; i++) {
        denominator = (denominator * i) % p;
    }
    return (numerator * modInverse(denominator, p)) % p;
}

vector<int>* tree;

void countNoOfNodesInsubtree(int child, int par, int dp[]) {
    int count = 1;
    for (int x : tree[child]) {
        if (x == par) continue;
        countNoOfNodesInsubtree(x, child, dp);
        count += dp[x];
    }
    dp[child] = count;
}

void depth(int child, int par, int dp[], int d) {
    dp[child] = d;
    for (int x : tree[child]) {
        if (x == par) continue;
        depth(x, child, dp, d + 1);
    }
}

void dfs(int sv, bool vis[]) {
    vis[sv] = true;
    for (int x : tree[sv]) {
        if (!vis[x]) {
            dfs(x, vis);
        }
    }
}

void solve() {
    FastReader scn;

    vector<long long> list;
    vector<long long> listl;
    vector<int> lista;
    vector<int> listb;

    unordered_map<int, int> map;
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;

    set<int> set;
    set<int> setx;
    set<int> sety;

    stringstream sb;

    int testcases = 1;

    for (int testcase = 1; testcase <= testcases; testcase++) {
        long long n = scn.nextLong();
        long long x = n;

        for (long long i = 2; i * i <= n; i++) {
            if (x % i == 0) {
                while (x % i == 0) {
                    list.push_back(i);
                    x = x / i;
                }
            }
        }

        if (x > 1) list.push_back(x);

        if (n == 1) {
            cout << 1 << endl;
            cout << 0 << endl;
        } else if (list.size() == 2) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
            if (list.size() == 1) cout << 0 << endl;
            else {
                long long ans = (list[0] * list[1]);
                cout << ans << endl;
            }
        }

        sb.str("");
        list.clear();
        listb.clear();
        map.clear();
        map1.clear();
        map2.clear();
        set.clear();
        sety.clear();
    }
}

int main() {
    solve();
    return 0;
}

class Pair {
    public:
        int first;
        int second;

        string toString() {
            stringstream ss;
            ss << first << " " << second;
            return ss.str();
        }
};
