#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stdexcept>

std::string nextWord();
int nextInt();
long long id3();
double id6();

int main() {
    std::string path = nextWord();
    int x = 0, y = 0;
    std::unordered_map<long long, bool> visited;
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
            printf("BUG\n");
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
            printf("BUG\n");
            return 0;
        }
        visited[x * 1000 + y] = true;
    }
    printf("OK\n");
    return 0;
}

std::istringstream lineScanner;
std::istringstream wordScanner;

std::string nextWord() {
    std::string word;
    while (wordScanner >> word) {
        return word;
    }
    std::string line;
    if (std::getline(lineScanner, line)) {
        wordScanner.clear();
        wordScanner.str(line);
        return nextWord();
    }
    throw std::runtime_error("nextWord: EOF reached");
}

int nextInt() {
    std::string word = nextWord();
    try {
        return std::stoi(word);
    } catch (const std::exception& e) {
        throw std::runtime_error(e.what());
    }
}

long long id3() {
    std::string word = nextWord();
    try {
        return std::stoll(word);
    } catch (const std::exception& e) {
        throw std::runtime_error(e.what());
    }
}

double id6() {
    std::string word = nextWord();
    try {
        return std::stod(word);
    } catch (const std::exception& e) {
        throw std::runtime_error(e.what());
    }
}
