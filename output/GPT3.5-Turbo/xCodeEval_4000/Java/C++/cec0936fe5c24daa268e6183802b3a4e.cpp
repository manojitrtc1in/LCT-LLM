#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class AMarcinAndTrainingCamp {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int n;
        in >> n;
        vector<long long> A(n);
        vector<int> B(n);
        vector<bool> used(n, false);
        vector<int> order(n);
        for (int i = 0; i < n; i++) {
            in >> A[i];
        }
        for (int i = 0; i < n; i++) {
            in >> B[i];
        }
        for (int i = 0; i < n; i++) {
            order[i] = i;
        }
        sort(order.begin(), order.end(), [&](int i, int j) {
            return A[i] > A[j];
        });
        long long res = 0;
        for (int idx = 0; idx < n; ) {
            int to = idx;
            while (to + 1 < n && A[order[to + 1]] == A[order[idx]]) {
                to++;
            }
            bool valid = to > idx;
            if (!valid) {
                for (int i = 0; i < idx; i++) {
                    if (used[i] && (A[order[i]] & A[order[idx]]) == A[order[idx]]) {
                        valid = true;
                    }
                }
            }
            if (valid) {
                for (int i = idx; i <= to; i++) {
                    res += B[order[i]];
                    used[i] = true;
                }
            }
            idx = to + 1;
        }
        out << res << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    AMarcinAndTrainingCamp solver;
    solver.solve(1, cin, cout);
    return 0;
}
