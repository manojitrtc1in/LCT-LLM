#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <limits>
#include <random>
#include <set>
#include <iterator>
#include <utility>

using namespace std;

class InputReader {
public:
    InputReader() {}

    int readInt() {
        int res;
        cin >> res;
        return res;
    }

    void readIntArrays(vector<int>& arr) {
        for (auto& x : arr) {
            x = readInt();
        }
    }
};

class OutputWriter {
public:
    void printLine(long long x) {
        cout << x << endl;
    }

    void printLine(int a, int b) {
        cout << a << " " << b << endl;
    }
};

class IntervalTree {
protected:
    int size;

public:
    IntervalTree(int size) : size(size) {
        int nodeCount = max(1, __builtin_popcount(size) << 2);
        initData(size, nodeCount);
        init();
    }

    virtual void initData(int size, int nodeCount) = 0;
    virtual void initAfter(int root, int left, int right, int middle) = 0;
    virtual void initBefore(int root, int left, int right, int middle) = 0;
    virtual void initLeaf(int root, int index) = 0;
    virtual void updatePostProcess(int root, int left, int right, int from, int to, long long delta, int middle) = 0;
    virtual void updatePreProcess(int root, int left, int right, int from, int to, long long delta, int middle) = 0;
    virtual void updateFull(int root, int left, int right, int from, int to, long long delta) = 0;
    virtual long long queryPostProcess(int root, int left, int right, int from, int to, int middle, long long leftResult, long long rightResult) = 0;
    virtual void queryPreProcess(int root, int left, int right, int from, int to, int middle) = 0;
    virtual long long queryFull(int root, int left, int right, int from, int to) = 0;
    virtual long long emptySegmentResult() = 0;

    void init() {
        if (size == 0) return;
        init(0, 0, size - 1);
    }

private:
    void init(int root, int left, int right) {
        if (left == right) {
            initLeaf(root, left);
        } else {
            int middle = (left + right) >> 1;
            initBefore(root, left, right, middle);
            init(2 * root + 1, left, middle);
            init(2 * root + 2, middle + 1, right);
            initAfter(root, left, right, middle);
        }
    }
};

class LongIntervalTree : public IntervalTree {
protected:
    long long* value;
    long long* delta;

public:
    LongIntervalTree(int size) : IntervalTree(size) {
        initData(size, 0);
    }

    void initData(int size, int nodeCount) override {
        value = new long long[nodeCount];
        delta = new long long[nodeCount];
    }

    // Implement other pure virtual functions...
};

class Task {
    vector<int> L, R, A, B, C, max, best;
    vector<int> orderV, orderC;
    map<int, int> map;
    LongIntervalTree* tree;

public:
    void solve(int testNumber, InputReader& in, OutputWriter& out) {
        int n = in.readInt(), m = in.readInt();
        L.resize(n);
        R.resize(n);
        A.resize(m);
        B.resize(m);
        C.resize(m);
        max.resize(m);
        best.resize(m);
        orderV.resize(n);
        orderC.resize(m);

        in.readIntArrays(L);
        in.readIntArrays(R);
        in.readIntArrays(A);
        in.readIntArrays(B);
        in.readIntArrays(C);

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

        tree = new LongIntervalTree(map.size());
        process1(n, m, out);
        process2(n, m);
        process3(n, m);

        long long ret = 0;
        int aux = -1;
        for (int i = 0; i < m; i++) {
            long long x = 1LL * max[i] * C[i];
            if (x > ret) {
                ret = x;
                aux = i;
            }
        }
        out.printLine(ret);
        if (ret > 0) out.printLine(best[aux] + 1, aux + 1);
    }

    void process1(int n, int m, OutputWriter& out) {
        // Implementation...
    }

    void process2(int n, int m) {
        // Implementation...
    }

    void process3(int n, int m) {
        // Implementation...
    }
};

int main() {
    InputReader in;
    OutputWriter out;
    Task solver;
    solver.solve(1, in, out);
    return 0;
}
