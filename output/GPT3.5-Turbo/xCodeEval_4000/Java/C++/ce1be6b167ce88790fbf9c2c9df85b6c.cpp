#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <bitset>
#include <fstream>
#include <numeric>
#include <cassert>
#include <functional>
#include <random>
#include <chrono>
#include <climits>
using namespace std;

class E {
public:
    void solver() {
        long long n;
        cin >> n;
        vector<long long> ar(3), br(3);
        for (int i = 0; i < 3; i++) {
            cin >> ar[i];
        }
        for (int i = 0; i < 3; i++) {
            cin >> br[i];
        }
        long long mxWins = 0;
        long long mxLosesOrDraw = 0;
        long long draws = 0;
        for (int i = 0; i < 3; i++) {
            mxWins += min(ar[i], br[(i + 1) % 3]);
            long long mxLose = min(br[i], ar[(i + 1) % 3]);
            long long mxDraw = min(br[i], ar[i]);
            mxLosesOrDraw += min(br[i], mxLose + mxDraw);
        }
        cout << n - mxLosesOrDraw << " " << mxWins << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    E e;
    e.solver();

    return 0;
}
