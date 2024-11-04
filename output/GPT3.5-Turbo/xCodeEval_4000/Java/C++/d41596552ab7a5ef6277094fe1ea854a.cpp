#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class IntList {
public:
    virtual int get(int index) = 0;
    virtual void set(int index, int value) = 0;
    virtual void addAt(int index, int value) = 0;
    virtual void removeAt(int index) = 0;
    virtual int size() = 0;
};

class IntArrayList : public IntList {
private:
    int size;
    vector<int> data;

public:
    IntArrayList() {
        size = 0;
    }

    IntArrayList(int capacity) {
        data.resize(capacity);
        size = 0;
    }

    IntArrayList(vector<int>& arr) {
        data = arr;
        size = arr.size();
    }

    int get(int index) {
        return data[index];
    }

    void set(int index, int value) {
        data[index] = value;
    }

    void addAt(int index, int value) {
        data.insert(data.begin() + index, value);
        size++;
    }

    void removeAt(int index) {
        data.erase(data.begin() + index);
        size--;
    }

    int size() {
        return size;
    }
};

class IntStream {
public:
    virtual int get(int index) = 0;
    virtual int size() = 0;
};

class IntArray : public IntStream {
private:
    vector<int> data;

public:
    IntArray(vector<int>& arr) {
        data = arr;
    }

    int get(int index) {
        return data[index];
    }

    int size() {
        return data.size();
    }
};

class Sorter {
private:
    static const int INSERTION_THRESHOLD = 16;

    static void quickSort(IntList* list, int from, int to, int remaining) {
        if (to - from < INSERTION_THRESHOLD) {
            insertionSort(list, from, to);
            return;
        }
        if (remaining == 0) {
            heapSort(list, from, to);
            return;
        }
        remaining--;
        int pivotIndex = (from + to) >> 1;
        int pivot = list->get(pivotIndex);
        list->set(pivotIndex, list->get(to));
        list->set(to, pivot);
        int storeIndex = from;
        int equalIndex = to;
        for (int i = from; i < equalIndex; i++) {
            int value = list->get(i);
            if (value < pivot) {
                list->set(i, list->get(storeIndex));
                list->set(storeIndex++, value);
            } else if (value == pivot) {
                list->set(i--, list->get(--equalIndex));
                list->set(equalIndex, value);
            }
        }
        quickSort(list, from, storeIndex - 1, remaining);
        quickSort(list, equalIndex + 1, to, remaining);
    }

    static void heapSort(IntList* list, int from, int to) {
        for (int i = (to + from - 1) >> 1; i >= from; i--) {
            siftDown(list, i, to, from);
        }
        for (int i = to; i > from; i--) {
            int temp = list->get(from);
            list->set(from, list->get(i));
            list->set(i, temp);
            siftDown(list, from, i - 1, from);
        }
    }

    static void siftDown(IntList* list, int start, int end, int delta) {
        int value = list->get(start);
        while (true) {
            int child = ((start - delta) << 1) + 1 + delta;
            if (child > end) {
                return;
            }
            int childValue = list->get(child);
            if (child + 1 <= end && list->get(child + 1) > childValue) {
                child++;
                childValue = list->get(child);
            }
            if (value >= childValue) {
                return;
            }
            list->set(start, childValue);
            start = child;
        }
    }

    static void insertionSort(IntList* list, int from, int to) {
        for (int i = from + 1; i <= to; i++) {
            int value = list->get(i);
            for (int j = i - 1; j >= from; j--) {
                if (list->get(j) <= value) {
                    break;
                }
                list->set(j + 1, list->get(j));
                list->set(j, value);
            }
        }
    }

public:
    static void sort(IntList* list) {
        quickSort(list, 0, list->size() - 1, (int) (log(list->size()) * 5 / 2));
    }
};

class InputReader {
private:
    istream& stream;

public:
    InputReader(istream& stream) : stream(stream) {}

    void readIntArrays(vector<vector<int>>& arrays) {
        for (int i = 0; i < arrays[0].size(); i++) {
            for (int j = 0; j < arrays.size(); j++) {
                stream >> arrays[j][i];
            }
        }
    }

    vector<int> readIntArray(int size) {
        vector<int> array(size);
        for (int i = 0; i < size; i++) {
            stream >> array[i];
        }
        return array;
    }
};

class OutputWriter {
private:
    ostream& writer;

public:
    OutputWriter(ostream& writer) : writer(writer) {}

    void printLine(long long i) {
        writer << i << endl;
    }
};

class TaskC {
public:
    void solve(int testNumber, InputReader& in, OutputWriter& out) {
        int x, k, n, q;
        in.readIntArrays({&x, &k, &n, &q});
        vector<int> c = in.readIntArray(k);
        vector<int> p(q), w(q);
        in.readIntArrays({&p, &w});

        IntList* cList = new IntArrayList(c);
        Sorter::sort(cList);
        IntList* pList = new IntArrayList(p);
        IntList* wList = new IntArrayList(w);

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
                        baseMat[id[ii]][id[ni + (1 << j)]] = cList->get(j);
                        for (int l = 0; l < q; l++) {
                            specMat[l][id[ii]][id[ni + (1 << j)]] = cList->get(j) + wList->get(l);
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
                stop = min(stop, pList->get(i));
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
            if (pList->get(i) >= n - x) {
                answer += wList->get(i);
            }
        }

        out.printLine(answer);
    }

    void power(vector<vector<long long>>& base, int exponent, vector<vector<long long>>& result, vector<vector<long long>>& temp) {
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

    void multiply(vector<vector<long long>>& c, vector<vector<long long>>& a, vector<vector<long long>>& b) {
        int size = c.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                c[i][j] = LLONG_MAX;
                for (int k = 0; k < size; k++) {
                    if (a[i][k] != LLONG_MAX && b[k][j] != LLONG_MAX) {
                        c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
                    }
                }
            }
        }
    }

    void makeOne(vector<vector<long long>>& current) {
        int size = current.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                current[i][j] = LLONG_MAX;
            }
            current[i][i] = 0;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, k, n, q;
    cin >> x >> k >> n >> q;
    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }
    vector<int> p(q), w(q);
    for (int i = 0; i < q; i++) {
        cin >> p[i] >> w[i];
    }

    InputReader in(cin);
    OutputWriter out(cout);
    TaskC solver;
    solver.solve(1, in, out);

    return 0;
}
