#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template<typename T>
vector<T> RL() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<T> result;
    T value;
    while (iss >> value) {
        result.push_back(value);
    }
    return result;
}

int from_base(string X) {
    string base = "0123456789`~!@";
    int l = base.length();
    int r = 0;
    int e = 1;
    for (char c : X) {
        r += base.find(c) * e;
        e *= l;
    }
    return r;
}

void solve() {
    vector<int> RL_result = RL<int>();
    int N = RL_result[0];
    int mod = RL_result[1];
    vector<string> A = RL<string>();
    cout << from_base(A[N]) % mod << endl;
}

int main() {
    int T = 1;
    for (int t = 0; t < T; t++) {
        solve();
    }
    return 0;
}
