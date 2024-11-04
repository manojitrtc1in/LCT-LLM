#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::vector<std::vector<char>> board(8, std::vector<char>(8));
    
    for (int i = 0; i < 8; i++) {
        std::string line;
        std::getline(std::cin, line);
        for (int j = 0; j < 8; j++) {
            board[i][j] = line[j];
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

    std::cout << total << std::endl;

    return 0;
}
