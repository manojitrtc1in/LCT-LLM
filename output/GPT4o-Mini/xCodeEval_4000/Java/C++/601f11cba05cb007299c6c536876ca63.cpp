#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

class Abra {
public:
    void run() {
        long beginTime = clock();
        init();
        solve();
        long endTime = clock();
        if (!oj) {
            cout << "Memory used = " << (getMemoryUsage()) << endl;
            cout << "Running time = " << (endTime - beginTime) << endl;
        }
        out.flush();
    }

private:
    ifstream br;
    ofstream out;
    bool oj;

    void init() {
        oj = getenv("ONLINE_JUDGE") != nullptr;
        if (oj) {
            br.clear();
            br.rdbuf(cin.rdbuf());
            out.clear();
            out.rdbuf(cout.rdbuf());
        } else {
            br.open("input.txt");
            out.open("output.txt");
        }
    }

    long getMemoryUsage() {
        // Placeholder for memory usage calculation
        return 0;
    }

    int nextInt() {
        int x;
        br >> x;
        return x;
    }

    void solve() {
        int w = nextInt();
        if (w == 2) {
            out << "NO";
            return;
        }
        if (w % 2 == 0) out << "YES"; else out << "NO";
    }
};

int main() {
    Abra abra;
    abra.run();
    return 0;
}
