#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

class Pair {
public:
    int idx, val;
    Pair(int idx, int val) : idx(idx), val(val) {}
    bool operator<(const Pair& other) const {
        return val < other.val;
    }
};

class Solution {
private:
    static const int MOD = 1000000007;
    long count = 0;
    vector<set<int>> ts[200000];
    vector<int> adj[200000];
    bool visited[200000];
    int par[200000];

public:
    void dfs(int start, int root) {
        visited[start] = true;
        par[start] = root;
        for (int i : adj[start]) {
            if (!visited[i]) {
                dfs(i, start);
            }
        }
    }

    void soln() {
        int a, b, x, y, z;
        cin >> a >> b >> x >> y >> z;
        long ans = 0;
        if ((long)a < 2 * (long)x) {
            ans += 2 * (long)x - a;
            a = 0;
        } else {
            a -= 2 * x;
        }
        if ((long)b < 3 * (long)z) {
            ans += 3 * (long)z - b;
            b = 0;
        } else {
            b -= 3 * z;
        }
        if (a < b) {
            y = max(0, y - a);
            b -= a;
            a = 0;
        } else {
            y = max(0, y - b);
            b = a - b;
            a = 0;
        }
        if (y > b) {
            ans += b + 2 * (y - b);
        } else {
            ans += y;
        }
        cout << ans << endl;
    }

    int bfsPair(int arr[][100], bool visited[][100], int x1, int y1, int x2, int y2) {
        queue<Pair> q;
        visited[x1][y1] = true;
        int level = 1;
        int increamenter = 0;

        if (x1 - 1 >= 0 && arr[x1 - 1][y1] == 1) increamenter++;
        if (y1 - 1 >= 0 && arr[x1][y1 - 1] == 1) increamenter++;
        if (y1 + 1 < 100 && arr[x1][y1 + 1] == 1) increamenter++;
        if (x1 + 1 < 100 && arr[x1 + 1][y1] == 1) increamenter++;

        q.push(Pair(x1, y1));
        int i = 0;
        while (!q.empty()) {
            Pair p = q.front();
            q.pop();

            int x = p.idx, y = p.val;
            if (x - 1 >= 0 && y >= 0 && x - 1 < 100 && y < 100) {
                if (!visited[x - 1][y] && arr[x - 1][y] == 1) {
                    q.push(Pair(x - 1, y));
                    visited[x - 1][y] = true;
                }
            }
            if (x >= 0 && y - 1 >= 0 && x < 100 && y - 1 < 100) {
                if (!visited[x][y - 1] && arr[x][y - 1] == 1) {
                    q.push(Pair(x, y - 1));
                    visited[x][y - 1] = true;
                }
            }
            if (x >= 0 && y + 1 >= 0 && x < 100 && y + 1 < 100) {
                if (!visited[x][y + 1] && arr[x][y + 1] == 1) {
                    q.push(Pair(x, y + 1));
                    visited[x][y + 1] = true;
                }
            }
            if (x + 1 >= 0 && y >= 0 && x + 1 < 100 && y < 100) {
                if (!visited[x + 1][y] && arr[x + 1][y] == 1) {
                    q.push(Pair(x + 1, y));
                    visited[x + 1][y] = true;
                }
            }
            if (x == x2 && y == y2) return level;

            if (increamenter == 0) {
                level++;
                increamenter = q.size();
            }
            increamenter--;
        }
        return -1;
    }

    void bfs(vector<int> gp[], int s, bool visited[], int dist[]) {
        queue<int> qu;
        int level = 1;
        int increamenter;

        if (gp[s].size() > 0) {
            increamenter = gp[s].size() + 1;
        } else return;

        visited[s] = true;
        qu.push(s);
        while (!qu.empty()) {
            int temp = qu.front();
            qu.pop();

            increamenter--;
            dist[temp] = level * 6;
            for (int i = 0; i < gp[temp].size(); i++) {
                if (!visited[gp[temp][i]]) {
                    visited[gp[temp][i]] = true;
                    qu.push(gp[temp][i]);
                }
            }
            if (increamenter == 0) {
                level++;
                increamenter = qu.size();
            }
        }
    }

    static int maxSubArraySum(int a[], int size) {
        int max_so_far = INT_MIN, max_ending_here = 0;

        for (int i = 0; i < size; i++) {
            max_ending_here += a[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }

    static vector<int> allprime(int n) {
        vector<int> arr;
        arr.push_back(2);
        for (int i = 3; i < n; i += 2) {
            bool flag = false;
            for (int j = 0; j < arr.size(); j++) {
                if (i % arr[j] == 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) arr.push_back(i);
        }
        return arr;
    }

    static int fact(int n) {
        int ans = 1;
        for (int i = 1; i <= n; i++) ans = (ans * i) % MOD;
        return ans;
    }

    static long gcd(long x, long y) {
        if (x % y == 0)
            return y;
        else
            return gcd(y, x % y);
    }

    static int BinarySearch(int a[], int low, int high, int target) {
        if (low > high)
            return -1;
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
            return mid;
        if (a[mid] > target)
            high = mid - 1;
        if (a[mid] < target)
            low = mid + 1;
        return BinarySearch(a, low, high, target);
    }

    static string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    static long pow(long n, long p, long m) {
        long result = 1;
        if (p == 0) return 1;
        if (p == 1) return n;
        while (p != 0) {
            if (p % 2 == 1)
                result *= n;
            if (result >= m)
                result %= m;
            p >>= 1;
            n *= n;
            if (n >= m)
                n %= m;
        }
        return result;
    }

    static long pow(long n, long p) {
        long result = 1;
        if (p == 0) return 1;
        if (p == 1) return n;
        while (p != 0) {
            if (p % 2 == 1)
                result *= n;
            p >>= 1;
            n *= n;
        }
        return result;
    }

    static void radixSort(int f[], int n) {
        int to[n];
        {
            int b[65537] = {0};
            for (int i = 0; i < n; i++)
                b[1 + (f[i] & 0xffff)]++;
            for (int i = 1; i <= 65536; i++)
                b[i] += b[i - 1];
            for (int i = 0; i < n; i++)
                to[b[f[i] & 0xffff]++] = f[i];
            swap(f, to);
        }
        {
            int b[65537] = {0};
            for (int i = 0; i < n; i++)
                b[1 + (f[i] >>> 16)]++;
            for (int i = 1; i <= 65536; i++)
                b[i] += b[i - 1];
            for (int i = 0; i < n; i++)
                to[b[f[i] >>> 16]++] = f[i];
            swap(f, to);
        }
    }

    static int nextPowerOf2(int a) {
        int b = 1;
        while (b < a) {
            b <<= 1;
        }
        return b;
    }

    static bool PointInTriangle(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
        int s = p2 * p5 - p1 * p6 + (p6 - p2) * p7 + (p1 - p5) * p8;
        int t = p1 * p4 - p2 * p3 + (p2 - p4) * p7 + (p3 - p1) * p8;

        if ((s < 0) != (t < 0))
            return false;

        int A = -p4 * p5 + p2 * (p5 - p3) + p1 * (p4 - p6) + p3 * p6;
        if (A < 0.0) {
            s = -s;
            t = -t;
            A = -A;
        }
        return s > 0 && t > 0 && (s + t) <= A;
    }

    static float area(int x1, int y1, int x2, int y2, int x3, int y3) {
        return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    }

    static bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;

        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

    static long sort(int a[], int n) {
        int b[n];
        return mergeSort(a, b, 0, n - 1);
    }

    static long mergeSort(int a[], int b[], long left, long right) {
        long c = 0;
        if (left < right) {
            long mid = left + (right - left) / 2;
            c = mergeSort(a, b, left, mid);
            c += mergeSort(a, b, mid + 1, right);
            c += merge(a, b, left, mid + 1, right);
        }
        return c;
    }

    static long merge(int a[], int b[], long left, long mid, long right) {
        long c = 0;
        int i = left, j = mid, k = left;
        while (i <= mid - 1 && j <= right) {
            if (a[i] > a[j]) {
                b[k++] = a[i++];
            } else {
                b[k++] = a[j++];
                c += mid - i;
            }
        }
        while (i <= mid - 1) b[k++] = a[i++];
        while (j <= right) b[k++] = a[j++];
        for (i = left; i <= right; i++)
            a[i] = b[i];
        return c;
    }
};

int main() {
    Solution sol;
    sol.soln();
    return 0;
}
