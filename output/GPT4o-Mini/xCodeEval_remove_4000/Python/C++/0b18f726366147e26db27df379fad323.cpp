#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> RL() {
    int type = 0;
    string input;
    getline(cin, input);
    vector<int> result;
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        result.push_back(stoi(input.substr(0, pos)));
        input.erase(0, pos + 1);
    }
    result.push_back(stoi(input));
    return result;
}

string A[] = {"0", "1", "2", "6", "(", "D", "E3", "_&", "/51", "n`6", "n4>", "!rR2", "E+a*", "j61h1", "!3ab!", "q`t6"};

long long from_base(const string& X) {
    string base = "0123456789`~!@";
    int l = base.length();
    long long r = 0;
    long long e = 1;
    for (char c : X) {
        r += base.find(c) * e;
        e *= l;
    }
    return r;
}

void solve() {
    vector<int> input = RL();
    int N = input[0];
    int mod = input[1];
    cout << from_base(A[N]) % mod << endl;
}

int main() {
    int T = 1;
    for (int t = 0; t < T; t++) {
        solve();
    }
    return 0;
}
