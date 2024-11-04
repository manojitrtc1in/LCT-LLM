#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <random>

using namespace std;

class E {
public:
    void solver() {
        long long n;
        cin >> n;
        vector<long long> ar = id23(3);
        vector<long long> br = id23(3);
        long long mxWins = 0;
        long long id19 = 0;
        long long draws = 0;

        for (int i = 0; i < 3; i++) {
            mxWins += min(ar[i], br[(i + 1) % 3]);
            long long mxLose = min(br[i], ar[(i + 1) % 3]);
            long long mxDraw = min(br[i], ar[i]);
            id19 += min(br[i], mxLose + mxDraw);
        }
        cout << n - id19 << " " << mxWins << endl;
    }

private:
    vector<long long> id23(int n) {
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        return a;
    }
};

int main() {
    E e;
    e.solver();
    return 0;
}
