#include <bits/stdc++.h>
using namespace std;

const int mod = pow(10, 9) + 7;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dx9[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy9[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

const double eps = 1e-10;
vector<int> primeNumbers;

void primeSieve(int n) {
    bitset<1000001> bitset;
    for (long long i = 0; i < n; i++) {
        if (i == 0 || i == 1) {
            bitset.set(i);
            continue;
        }
        if (bitset[i]) continue;
        primeNumbers.push_back(i);
        for (long long j = i; j <= n; j += i)
            bitset.set(j);
    }
}

int countDivisors(long long number) {
    if (number == 1) return 1;
    vector<int> primeFactors;
    int index = 0;
    long long curr = primeNumbers[index];
    while (curr * curr <= number) {
        while (number % curr == 0) {
            number = number / curr;
            primeFactors.push_back(curr);
        }
        index++;
        curr = primeNumbers[index];
    }

    if (number != 1) primeFactors.push_back(number);
    int current = primeFactors[0];
    int totalDivisors = 1;
    int currentCount = 2;
    for (int i = 1; i < primeFactors.size(); i++) {
        if (primeFactors[i] == current) {
            currentCount++;
        } else {
            totalDivisors *= currentCount;
            currentCount = 2;
            current = primeFactors[i];
        }
    }
    totalDivisors *= currentCount;
    return totalDivisors;
}

int primeExponentsCount(int n) {
    if (n <= 1)
        return 0;
    int sqrt = (int)sqrt(n);
    int remainingNumber = n;
    int result = 0;
    for (int i = 2; i <= sqrt; i++) {
        while (remainingNumber % i == 0) {
            result++;
            remainingNumber /= i;
        }
    }

    if (remainingNumber > 1) {
        result++;
    }
    return result;
}

bool next_permutation(vector<int>& p) {
    for (int a = p.size() - 2; a >= 0; --a)
        if (p[a] < p[a + 1])
            for (int b = p.size() - 1;; --b)
                if (p[b] > p[a]) {
                    int t = p[a];
                    p[a] = p[b];
                    p[b] = t;
                    for (++a, b = p.size() - 1; a < b; ++a, --b) {
                        t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                    }
                    return true;
                }
    return false;
}

long long getNcR(int n, int r) {
    long long p = 1, k = 1;
    if (n - r < r) r = n - r;

    if (r != 0) {
        while (r > 0) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    } else {
        p = 1;
    }
    return p;
}

bool isVowel(char c) {
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

void sort(vector<int>& a) {
    sort(a.begin(), a.end());
}

void sort(vector<long long>& a) {
    sort(a.begin(), a.end());
}

int binomialCoeff(int n, int k) {
    int C[k + 1];

    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

class MyScanner {
   public:
    MyScanner() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }
    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }
    double nextDouble() {
        double x;
        cin >> x;
        return x;
    }
    string nextLine() {
        string s;
        getline(cin, s);
        return s;
    }
    string next() {
        string s;
        cin >> s;
        return s;
    }
};

int main() {
    MyScanner sc;
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str = sc.nextLine();
    vector<char> inp(str.begin(), str.end());
    int n = str.length();

    vector<string> pos = {"00", "25", "50", "75"};
    int count = 0;

    if (inp.size() == 1) {
        if (inp[0] == '0' || inp[0] == 'X' || inp[0] == '_') count++;
    } else {
        for (string cstr : pos) {
            int X = -1;

            int idx = 0;
            bool possible = true;
            for (int i = n - 2; i < n; i++) {
                char curr = inp[i];
                char strcurr = cstr[idx];
                idx++;

                if (curr == '_')
                    continue;
                else if (curr == 'X') {
                    if (X == -1) {
                        X = (strcurr - '0');
                    } else {
                        if (X != strcurr - '0') {
                            possible = false;
                            break;
                        }
                    }
                } else {
                    if (curr != strcurr) {
                        possible = false;
                        break;
                    }
                }
            }

            if (!possible) continue;

            if (str.length() == 2) {
                if (cstr[0] == '0') continue;

                count++;
                continue;
            }

            vector<char> ninp = inp;

            int cntX = 0;
            for (char ch : inp) {
                if (ch == 'X') cntX++;
            }

            if (X != -1 || cntX == 0) {
                if (X != -1) {
                    for (int k = 0; k < str.length(); k++) {
                        ninp[k] = inp[k] == 'X' ? (char)(X + '0') : inp[k];
                    }
                }

                if (ninp[0] == '0') continue;
                int counter = 1;
                for (int k = 0; k < str.length() - 2; k++) {
                    if (ninp[k] == '_') {
                        if (k == 0) {
                            counter = counter * 9;
                        } else {
                            counter = counter * 10;
                        }
                    }
                }

                count += counter;
            } else {
                if (ninp[0] == '0') continue;

                int counter = 1;
                for (int k = 0; k < str.length() - 2; k++) {
                    if (ninp[k] == '_') {
                        if (k == 0) {
                            counter = counter * 9;
                        } else {
                            counter = counter * 10;
                        }
                    }
                }

                if (ninp[0] == 'X') {
                    counter = counter * 9;
                } else {
                    counter = counter * 10;
                }

                count += counter;
            }
        }
    }

    cout << count << endl;

    return 0;
}
