#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class TaskB {
    long long x;

public:
    void solve(int testNumber, istream& in, ostream& out) {
        int count, ones;
        in >> count >> ones >> x;
        vector<int> a(count);
        for (int i = 0; i < count; i++) {
            a[i] = i + 1;
        }
        shuffle(count, a);
        vector<int> b(count, 0);
        fill(b.begin(), b.begin() + ones, 1);
        shuffle(count, b);
        vector<int> answer(count);
        int size = (count + 31) >> 5;
        vector<int> ready(size);
        vector<int> mask(size);
        for (int i = 0; i < size; i++) {
            for (int j = i * 32; j < (i + 1) * 32 && j < count; j++) {
                if (b[j] == 1) {
                    mask[i] += 1 << (j - i * 32);
                }
            }
        }
        vector<vector<int>> upMasks(32, vector<int>(size));
        vector<vector<int>> downMasks(32, vector<int>(size));
        for (int i = 0; i < 32; i++) {
            int filter;
            if (i == 0) {
                filter = -1;
            } else {
                filter = (1 << (32 - i)) - 1;
            }
            int otherShift = 32 - i;
            for (int j = 0; j < size; j++) {
                upMasks[i][j] = mask[j] & filter;
                downMasks[i][j] = mask[j] >> otherShift;
            }
        }
        vector<int> order = createOrder(a.size());
        reverse(order.begin(), order.end());
        for (int i : order) {
            int value = a[i];
            int shift = i & 31;
            int otherShift = 32 - shift;
            int filter;
            if (shift == 0) {
                filter = -1;
            } else {
                filter = (1 << (32 - shift)) - 1;
            }
            int start = i >> 5;
            int upTo = size - start - 1;
            int otherFilter = (1 << shift) - 1;
            if (otherFilter == -1) {
                otherFilter = 0;
            }
            for (int j = 0; j < upTo; j++) {
                if ((ready[j + start] >> shift & upMasks[shift][j]) != upMasks[shift][j]) {
                    for (int k = (j + start) * 32 + shift; k < (j + start + 1) * 32 && k < count; k++) {
                        if (b[k - i] == 1 && answer[k] == 0) {
                            answer[k] = value;
                            ready[k >> 5] += 1 << (k & 31);
                        }
                    }
                }
                if ((ready[j + start + 1] & downMasks[shift][j]) != downMasks[shift][j]) {
                    for (int k = (j + start + 1) * 32; k < (j + start + 1) * 32 + shift && k < count; k++) {
                        if (b[k - i] == 1 && answer[k] == 0) {
                            answer[k] = value;
                            ready[k >> 5] += 1 << (k & 31);
                        }
                    }
                }
            }
            if ((ready[upTo + start] >> shift & upMasks[shift][upTo]) != upMasks[shift][upTo]) {
                for (int k = (upTo + start) * 32 + shift; k < (upTo + start + 1) * 32 && k < count; k++) {
                    if (b[k - i] == 1 && answer[k] == 0) {
                        answer[k] = value;
                        ready[k >> 5] += 1 << (k & 31);
                    }
                }
            }
        }
        copy(answer.begin(), answer.end(), ostream_iterator<int>(out, " "));
        out << endl;
    }

protected:
    void shuffle(int count, vector<int>& a) {
        for (int i = 0; i < count; i++) {
            int index = next() % (i + 1);
            int temp = a[i];
            a[i] = a[index];
            a[index] = temp;
        }
    }

    int next() {
        x = (x * 37 + 10007) % 1000000007;
        return (int) x;
    }

    vector<int> createOrder(int size) {
        vector<int> order(size);
        for (int i = 0; i < size; i++)
            order[i] = i;
        return order;
    }

    void reverse(vector<int>& array) {
        for (int i = 0, j = array.size() - 1; i < j; i++, j--) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TaskB solver;
    solver.solve(1, cin, cout);

    return 0;
}
