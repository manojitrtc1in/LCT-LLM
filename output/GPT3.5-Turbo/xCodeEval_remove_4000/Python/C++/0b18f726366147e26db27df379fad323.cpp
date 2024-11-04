#include <iostream>
#include <vector>
#include <sstream>

template<typename T>
std::vector<T> RL() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<T> result;
    T value;
    while (iss >> value) {
        result.push_back(value);
    }
    return result;
}

int from_base(std::string X) {
    std::string base = "0123456789`~!@";
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
    std::vector<int> RL_values = RL<int>();
    int N = RL_values[0];
    int mod = RL_values[1];
    std::vector<std::string> A = RL<std::string>();
    std::cout << from_base(A[N]) % mod << std::endl;
}

int main() {
    int T = 1;
    for (int t = 0; t < T; t++) {
        solve();
    }
    return 0;
}
