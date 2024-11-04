#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

class Main {
public:
    void run() {
        int n = 310000000;
        int m = 100000;

        int l, r;
        cin >> l >> r;
        long long res = calc(r + 1) - calc(l);
        cout << res << endl;
    }

private:
    int n = 310000000, m = 100000;
