#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
const long long mod2 = 998244353;

class InVoker {
public:
    static void main() {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<long long> a(n);
        input(a, n);
        sort(a.begin(), a.end());
        for (int i = 0; i < n / 2; i++) {
            long long temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - i - 1] = temp;
        }
        priority_queue<long long> pq;
        while (k-- >= 0) {
            pq.push(0);
        }
        long long gg = 0;
        for (int i = 0; i < n; i++) {
            long long cur = pq.top();
            pq.pop();
            gg += cur;
            cur += a[i];
            pq.push(cur);
        }
        cout << gg << endl;
    }

    static void sort(vector<int>& a) {
        sort(a.begin(), a.end());
    }

    static void sort(vector<long long>& a) {
        sort(a.begin(), a.end());
    }

    static void ruffleSort(vector<int>& a) {
        random_shuffle(a.begin(), a.end());
        sort(a.begin(), a.end());
    }

    static void ruffleSort(vector<long long>& a) {
        random_shuffle(a.begin(), a.end());
        sort(a.begin(), a.end());
    }

    static long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static void print(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }

    static void print(vector<long long>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }

    static void input(vector<long long>& a, int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    static void input(vector<int>& a, int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }
};

int main() {
    InVoker::main();
    return 0;
}
