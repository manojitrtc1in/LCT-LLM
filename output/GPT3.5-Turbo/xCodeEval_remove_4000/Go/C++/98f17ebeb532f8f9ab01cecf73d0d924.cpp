#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        string line;
        getline(cin, line);
        vector<string> words = split(line, ' ');
        for (int j = 0; j < 8; j++) {
            board[i][j] = words[j][0];
        }
    }
    int total = 0;
    for (int i = 0; i < 8; i++) {
        int count = 0;
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'B') {
                count++;
            }
        }
        if (count == 8) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = 'A';
            }
            total++;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[j][i] == 'B') {
                total++;
                break;
            }
        }
    }
    cout << total << endl;
    return 0;
}
