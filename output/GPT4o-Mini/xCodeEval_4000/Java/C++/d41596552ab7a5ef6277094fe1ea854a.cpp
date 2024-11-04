#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

using namespace std;

class InputReader {
public:
    InputReader(istream &stream) : stream(stream) {}

    void readIntArrays(vector<vector<int>> &arrays) {
        for (size_t i = 0; i < arrays[0].size(); i++) {
            for (size_t j = 0; j < arrays.size(); j++) {
                arrays[j][i] = readInt();
            }
        }
    }

    vector<int> readIntArray(int size) {
        vector<int> array(size);
        for (int i = 0; i < size; i++) {
            array[i] = readInt();
        }
        return array;
    }

    int readInt() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw invalid_argument("InputMismatchException");
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

private:
    istream &stream;
    int read() {
        if (stream.eof()) {
            throw invalid_argument("InputMismatchException");
        }
        return stream.get();
    }

    bool isSpaceChar(int c) {
        return isspace(c);
    }
};

class OutputWriter {
public:
    OutputWriter(ostream &outputStream) : writer(outputStream) {}

    void printLine(long long i) {
        writer << i << endl;
    }

private:
    ostream &writer;
};

class TaskC {
public:
    void solve(int testNumber, InputReader &in, OutputWriter &out) {
        int x = in.readInt();
        int k = in.readInt();
        int n = in.readInt();
        int q = in.readInt();
        vector<int> c = in.readIntArray(k);
        vector<int> p(q), w(q);
        in.readIntArrays({p, w});
        orderBy(p, w);
        decreaseByOne(p);
        vector<int> id(1 << k, -1);
        vector<int> byId(1 << k);
        int size = 0;
        for (int i = 0; i < (1 << k); i++) {
            if (__builtin_popcount(i) == x) {
                id[i] = size;
                byId[size++] = i;
            }
        }
        vector<vector<long long>> baseMat(size, vector<long long>(size, LLONG_MAX));
        vector<vector<vector<long long>>> specMat(q, vector<vector<long long>>(size, vector<long long>(size, LLONG_MAX)));
        for (int i = 0; i < size; i++) {
            int ii = byId[i];
            if ((ii & 1) == 0) {
                baseMat[id[ii]][id[ii >> 1]] = 0;
                for (int j = 0; j < q; j++) {
                    specMat[j][id[ii]][id[ii >> 1]] = 0;
                }
            } else {
                int ni = ii >> 1;
                for (int j = 0; j < k; j++) {
                    if ((ni >> j & 1) == 0) {
                        baseMat[id[ii]][id[ni + (1 << j)]] = c[j];
                        for (int l = 0; l < q; l++) {
                            specMat[l][id[ii]][id[ni + (1 << j)]] = c[j] + w[l];
                        }
                    }
                }
            }
        }
        vector<vector<long long>> current(size, vector<long long>(size));
        makeOne(current);
        vector<vector<long long>> temp(size, vector<long long>(size));
        vector<vector<long long>> temp1(size, vector<long long>(size));
        vector<vector<long long>> temp2(size, vector<long long>(size));
        int start = 0;
        for (int i = 0; i <= q; i++) {
            int stop = n - x;
            if (i < q) {
                stop = min(stop, p[i]);
            }
            power(baseMat, stop - start, temp1, temp2);
            multiply(temp, current, temp1);
            if (stop == n - x) {
                current = temp;
                break;
            } else {
                multiply(current, temp, specMat[i]);
                start = stop + 1;
            }
        }
        long long answer = current[id[(1 << x) - 1]][id[(1 << x) - 1]];
        for (int i = 0; i < q; i++) {
            if (p[i] >= n - x) {
                answer += w[i];
            }
        }
        out.printLine(answer);
    }

private:
    void power(const vector<vector<long long>> &base, int exponent, vector<vector<long long>> &result, vector<vector<long long>> &temp) {
        if (exponent == 0) {
            makeOne(result);
            return;
        }
        if ((exponent & 1) == 0) {
            power(base, exponent >> 1, temp, result);
            multiply(result, temp, temp);
        } else {
            power(base, exponent - 1, temp, result);
            multiply(result, temp, base);
        }
    }

    void multiply(vector<vector<long long>> &c, const vector<vector<long long>> &a, const vector<vector<long long>> &b) {
        for (size_t i = 0; i < c.size(); i++) {
            for (size_t j = 0; j < c.size(); j++) {
                c[i][j] = LLONG_MAX;
                for (size_t k = 0; k < c.size(); k++) {
                    if (a[i][k] != LLONG_MAX && b[k][j] != LLONG_MAX) {
                        c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
                    }
                }
            }
        }
    }

    void makeOne(vector<vector<long long>> &current) {
        fill(current.begin(), current.end(), vector<long long>(current.size(), LLONG_MAX));
        for (size_t i = 0; i < current.size(); i++) {
            current[i][i] = 0;
        }
    }

    void orderBy(vector<int> &base, vector<int> &...arrays) {
        vector<int> order = order(base);
        order(order, base);
        for (auto &array : arrays) {
            order(order, array);
        }
    }

    vector<int> order(const vector<int> &array) {
        vector<int> order(array.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&array](int first, int second) {
            return array[first] < array[second];
        });
        return order;
    }

    void order(const vector<int> &order, vector<int> &array) {
        vector<int> tempInt(order.size());
        for (size_t i = 0; i < order.size(); i++) {
            tempInt[i] = array[order[i]];
        }
        copy(tempInt.begin(), tempInt.end(), array.begin());
    }

    void decreaseByOne(vector<int> &...arrays) {
        for (auto &array : arrays) {
            for (auto &value : array) {
                value--;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    InputReader in(cin);
    OutputWriter out(cout);
    TaskC solver;
    solver.solve(1, in, out);
    return 0;
}
