#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <limits>
#include <queue>
#include <cassert>

using namespace std;

const long BIG = 1000000007;

template<typename Type>
class FIFO {
public:
    struct Node {
        Type element;
        Node* next;
        Node(Type el, Node* n) : element(el), next(n) {}
    };

    Node* start;
    Node* end;

    FIFO() : start(nullptr), end(nullptr) {}

    bool isEmpty() {
        return start == nullptr;
    }

    Type peek() {
        return start->element;
    }

    Type pop() {
        Type result = start->element;
        start = start->next;
        return result;
    }

    void push(Type element) {
        Node* list = new Node(element, nullptr);
        if (start == nullptr) {
            start = list;
            end = list;
        } else {
            end->next = list;
            end = list;
        }
    }
};

void add(int p1, int p2, int c1, int c2, long count, long result[51][51][51][51]) {
    if (p1 >= 0 && p2 >= 0 && c1 >= 0 && c2 >= 0 && count > 0) {
        result[p1][p2][c1][c2] += count;
    }
}

void addPrevious(int p1, int p2, int c1, int c2, long count, long result[51][51][51][51]) {
    add(p1 - 1, p2, c1, c2, p1 * count, result);
    add(p1 + 1, p2 - 1, c1, c2, p2 * count, result);
}

void next(int d, long count, int p1, int p2, int c1, int c2, long result[51][51][51][51]) {
    if (p1 == 0 && p2 == 0) {
        if (d == 2) {
            addPrevious(c1, c2, 1, 0, count, result);
        } else {
            addPrevious(c1, c2, 0, 1, count, result);
        }
    }

    if (d == 2) {
        addPrevious(p1, p2, c1 + 1, c2, count, result);
        addPrevious(p1, p2, c1 - 1, c2, c1 * count, result);
        addPrevious(p1, p2, c1 + 1, c2 - 1, c2 * count, result);
    } else {
        addPrevious(p1, p2, c1, c2 + 1, count, result);
        addPrevious(p1, p2, c1, c2, c1 * count, result);
        addPrevious(p1, p2, c1 + 2, c2 - 1, c2 * count, result);
        addPrevious(p1, p2, c1 - 2, c2, c1 * (c1 - 1) / 2 * count, result);
        addPrevious(p1, p2, c1, c2 - 1, c1 * c2 * count, result);
        addPrevious(p1, p2, c1 + 2, c2 - 2, c2 * (c2 - 1) / 2 * count, result);
    }
}

long solve(int d[], int n) {
    long count[51][51][51][51] = {};
    if (d[0] == 2) {
        if (d[1] == 2) {
            count[1][0][1][0] = 1;
        } else {
            count[1][0][0][1] = 1;
        }
    } else {
        if (d[1] == 2) {
            count[0][1][1][0] = 1;
        } else {
            count[0][1][0][1] = 1;
        }
    }
    for (int u = 2; u < n; u++) {
        long countNext[51][51][51][51] = {};
        for (int p1 = 0; p1 <= n / 2; p1++) {
            for (int p2 = 0; p2 <= n / 2 && p1 + p2 < n; p2++) {
                for (int c1 = 0; c1 <= n / 2 && p1 + p2 + c1 < n; c1++) {
                    for (int c2 = 0; c2 <= n / 2 && p1 + p2 + c1 + c2 < n; c2++) {
                        next(d[u], count[p1][p2][c1][c2] % BIG, p1, p2, c1, c2, countNext);
                    }
                }
            }
        }
        copy(&countNext[0][0][0][0], &countNext[0][0][0][0] + 51 * 51 * 51 * 51, &count[0][0][0][0]);
    }
    return count[0][0][0][0] % BIG;
}

int main() {
    int n;
    cin >> n;
    int d[100];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    cout << solve(d, n) << endl;
    return 0;
}
