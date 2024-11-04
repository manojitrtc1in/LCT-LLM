#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string path;
    cin >> path;

    int x = 0, y = 0;
    unordered_set<long long> visited;
    visited.insert(0);
    
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

        if (visited.count(x * 1000 + y)) {
            printf("BUG\n");
            return 0;
        }

        int count = 0;
        if (visited.count((x - 1) * 1000 + y)) count++;
        if (visited.count((x + 1) * 1000 + y)) count++;
        if (visited.count(x * 1000 + (y - 1))) count++;
        if (visited.count(x * 1000 + (y + 1))) count++;

        if (count > 1) {
            printf("BUG\n");
            return 0;
        }

        visited.insert(x * 1000 + y);
    }
    printf("OK\n");
    return 0;
}
