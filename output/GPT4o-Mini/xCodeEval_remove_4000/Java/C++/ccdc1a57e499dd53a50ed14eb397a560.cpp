#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <queue>
#include <set>
#include <cassert>

using namespace std;

class IntervalTree {
protected:
    int size;
    vector<long> value, delta;

public:
    IntervalTree(int size) : size(size) {
        int nodeCount = max(1, (1 << (int)ceil(log2(size))) << 2);
        value.resize(nodeCount);
        delta.resize(nodeCount);
        init();
    }

    virtual void init() {
        if (size == 0) return;
        init(0, 0, size - 1);
    }

    void init(int root, int left, int right) {
        if (left == right) {
            initLeaf(root, left);
        } else {
            int middle = (left + right) / 2;
            initBefore(root, left, right, middle);
            init(2 * root + 1, left, middle);
            init(2 * root + 2, middle + 1, right);
            initAfter(root, left, right, middle);
        }
    }

    virtual void initLeaf(int root, int index) = 0;
    virtual void initBefore(int root, int left, int right, int middle) = 0;
    virtual void initAfter(int root, int left, int right, int middle) = 0;

    void update(int from, int to, long delta) {
        update(0, 0, size - 1, from, to, delta);
    }

    void update(int root, int left, int right, int from, int to, long delta) {
        if (left > to || right < from) return;
        if (left >= from && right <= to) {
            updateFull(root, left, right, from, to, delta);
            return;
        }
        int middle = (left + right) / 2;
        id10(root, left, right, from, to, delta, middle);
        update(2 * root + 1, left, middle, from, to, delta);
        update(2 * root + 2, middle + 1, right, from, to, delta);
        id5(root, left, right, from, to, delta, middle);
    }

    virtual void updateFull(int root, int left, int right, int from, int to, long delta) = 0;
    virtual void id5(int root, int left, int right, int from, int to, long delta, int middle) = 0;
    virtual void id10(int root, int left, int right, int from, int to, long delta, int middle) = 0;

    long query(int from, int to) {
        return query(0, 0, size - 1, from, to);
    }

    long query(int root, int left, int right, int from, int to) {
        if (left > to || right < from) return 0; // Neutral value
        if (left >= from && right <= to) return queryFull(root, left, right, from, to);
        int middle = (left + right) / 2;
        id9(root, left, right, from, to, middle);
        long leftResult = query(2 * root + 1, left, middle, from, to);
        long rightResult = query(2 * root + 2, middle + 1, right, from, to);
        return id8(root, left, right, from, to, middle, leftResult, rightResult);
    }

    virtual long queryFull(int root, int left, int right, int from, int to) = 0;
    virtual void id9(int root, int left, int right, int from, int to, int middle) = 0;
    virtual long id8(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult) = 0;
};

class Task {
    vector<int> L, R, A, B, C, max, best;
    vector<int> orderV, orderC;
    IntervalTree* tree;
    map<int, int> map;

public:
    void solve(int testNumber, istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        bool flag = n == 200000 && m == 200000;
        L.resize(n);
        R.resize(n);
        A.resize(m);
        B.resize(m);
        C.resize(m);
        max.resize(m);
        best.resize(m);
        orderV.resize(n);
        orderC.resize(m);
        for (int i = 0; i < n; i++) in >> L[i] >> R[i];
        for (int i = 0; i < m; i++) in >> A[i] >> B[i] >> C[i];
        for (int i = 0; i < n; i++) orderV[i] = i;
        for (int i = 0; i < m; i++) orderC[i] = i;

        vector<int> arr(2 * (n + m));
        for (int i = 0; i < n; i++) {
            arr[2 * i] = L[i];
            arr[2 * i + 1] = R[i];
        }
        for (int i = 0; i < m; i++) {
            arr[2 * (n + i)] = A[i];
            arr[2 * (n + i) + 1] = B[i];
        }
        sort(arr.begin(), arr.end());
        int idx = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i == 0 || arr[i] != arr[i - 1]) {
                map[arr[i]] = idx++;
            }
        }
        tree = new IntervalTree(map.size());
        process1(n, m, out);
        process2(n, m);
        process3(n, m);
        long ret = 0;
        int aux = -1;
        for (int i = 0; i < m; i++) {
            long x = 1L * max[i] * C[i];
            if (x > ret) {
                ret = x;
                aux = i;
            }
        }
        out << ret << endl;
        if (ret > 0) out << best[aux] + 1 << " " << aux + 1 << endl;
    }

    void process1(int n, int m, ostream& out) {
        sort(orderV.begin(), orderV.end(), [&](int a, int b) {
            return L[a] < L[b];
        });
        sort(orderC.begin(), orderC.end(), [&](int a, int b) {
            return A[a] < A[b];
        });

        int v = 0, c = 0, ret = 0, idx = -1, x;
        while (v < n || c < m) {
            for (; v < n && (c == m || L[orderV[v]] <= A[orderC[c]]); v++) {
                x = orderV[v];
                if (R[x] > ret) {
                    ret = R[x];
                    idx = x;
                }
            }
            for (; c < m && (v == n || A[orderC[c]] < L[orderV[v]]); c++) {
                x = orderC[c];
                int length = min(ret, B[x]) - A[x];
                if (length > max[x]) {
                    max[x] = length;
                    best[x] = idx;
                }
            }
        }
    }

    void process2(int n, int m) {
        sort(orderV.begin(), orderV.end(), [&](int a, int b) {
            return R[a] < R[b];
        });
        sort(orderC.begin(), orderC.end(), [&](int a, int b) {
            return B[a] < B[b];
        });
        int v = 0, c = 0;
        while (v < n || c < m) {
            for (; v < n && (c == m || R[orderV[v]] <= B[orderC[c]]); v++) {
                int x = orderV[v];
                tree->update(map[L[x]], 1L * (R[x] - L[x]) * n + x);
            }
            for (; c < m && (v == n || B[orderC[c]] < R[orderV[v]]); c++) {
                int x = orderC[c];
                long aux = tree->query(map[A[x]], map[B[x]]);
                int length = (int)(aux / n), y = (int)(aux % n);
                if (length > max[x]) {
                    max[x] = length;
                    best[x] = y;
                }
            }
        }
    }

    void process3(int n, int m) {
        int v = n - 1, c = m - 1, ret = numeric_limits<int>::max(), idx = -1, x;
        while (v >= 0 || c >= 0) {
            for (; v >= 0 && (c == -1 || R[orderV[v]] >= B[orderC[c]]); v--) {
                x = orderV[v];
                if (L[x] < ret) {
                    ret = L[x];
                    idx = x;
                }
            }
            for (; c >= 0 && (v == -1 || B[orderC[c]] > R[orderV[v]]); c--) {
                x = orderC[c];
                int length = B[x] - max(ret, A[x]);
                if (length > max[x]) {
                    max[x] = length;
                    best[x] = idx;
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Task solver;
    solver.solve(1, cin, cout);
    return 0;
}
