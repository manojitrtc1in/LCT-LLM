#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stdexcept>

using namespace std;

string nextWord();
int nextInt();
int64_t nextInt64();
double nextFloat64();

int main() {
    string path = nextWord();
    int x = 0, y = 0;
    unordered_map<int64_t, bool> visited;
    visited[0] = true;
    for (char c : path) {
        switch (c) {
            case 'U':
                y--;
                break;
            case 'D':
                y++;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
        }
        if (visited.find(x * 1000 + y) != visited.end()) {
            cout << "BUG" << endl;
            return 0;
        }
        int count = 0;
        if (visited.find((x - 1) * 1000 + y) != visited.end()) {
            count++;
        }
        if (visited.find((x + 1) * 1000 + y) != visited.end()) {
            count++;
        }
        if (visited.find(x * 1000 + y - 1) != visited.end()) {
            count++;
        }
        if (visited.find(x * 1000 + y + 1) != visited.end()) {
            count++;
        }
        if (count > 1) {
            cout << "BUG" << endl;
            return 0;
        }
        visited[x * 1000 + y] = true;
    }
    cout << "OK" << endl;
    return 0;
}

string nextWord() {
    string word;
    cin >> word;
    return word;
}

int nextInt() {
    string word = nextWord();
    int res;
    try {
        res = stoi(word);
    } catch (const exception& e) {
        throw runtime_error("Invalid integer: " + word);
    }
    return res;
}

int64_t nextInt64() {
    string word = nextWord();
    int64_t res;
    try {
        res = stoll(word);
    } catch (const exception& e) {
        throw runtime_error("Invalid integer: " + word);
    }
    return res;
}

double nextFloat64() {
    string word = nextWord();
    double res;
    try {
        res = stod(word);
    } catch (const exception& e) {
        throw runtime_error("Invalid float: " + word);
    }
    return res;
}
