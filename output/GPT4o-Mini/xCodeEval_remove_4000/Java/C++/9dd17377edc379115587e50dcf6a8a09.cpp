#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <iterator>

using namespace std;

class Position {
public:
    int row;
    int id;
    Position* last;
    Position* next;
    Position* link;

    Position(int row, int id) : row(row), id(id), last(nullptr), next(nullptr), link(nullptr) {}

    bool operator<(const Position& o) const {
        if (row != o.row) {
            return row < o.row;
        }
        return id < o.id;
    }

    long value(int r) {
        if (link == nullptr) {
            return 0;
        }
        return (row - last->row) * (r - link->row);
    }
};

class TaskE {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int r, c, n, k;
        in >> r >> c >> n >> k;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            in >> x[i];
        }
        for (int i = 0; i < n; i++) {
            in >> y[i];
        }

        for (int i = 0; i < n; i++) {
            x[i]--;
            y[i]--;
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return y[a] < y[b];
        });

        vector<Position*> headPosition(k);
        for (int i = 0; i < k; i++) {
            headPosition[i] = new Position(-1, -1);
            if (i != 0) {
                headPosition[i]->last = headPosition[i - 1];
                headPosition[i - 1]->next = headPosition[i];
            }
        }

        vector<Position*> tailPosition(k);
        for (int i = 0; i < k; i++) {
            tailPosition[i] = new Position(r, -2);
            if (i != 0) {
                tailPosition[i]->last = tailPosition[i - 1];
                tailPosition[i - 1]->next = tailPosition[i];
            }
        }

        vector<Position*> positions(n);
        for (int i = 0; i < n; i++) {
            positions[i] = new Position(x[i], i);
        }

        long answer = 0;
        for (int i = 0; i < c; i++) {
            int at = 0;
            while (at < n && y[at] < i) {
                at++;
            }
            for (int j = 0; j < k - 1; j++) {
                headPosition[j + 1]->link = tailPosition[j];
            }
            set<Position*> setPositions;
            setPositions.insert(headPosition[k - 1]);
            setPositions.insert(tailPosition[0]);
            headPosition[k - 1]->next = tailPosition[0];
            tailPosition[0]->last = headPosition[k - 1];
            long delta = 0;

            for (int j = i; j < c; j++) {
                while (at < n && y[at] == j) {
                    Position* where = *setPositions.lower_bound(positions[at]);
                    Position* current = where;
                    for (int l = 1; l < k; l++) {
                        delta -= current->value(r);
                        current = current->last;
                    }
                    Position* next = where->next;
                    delta -= next->value(r);
                    current = positions[at];
                    where->next = current;
                    current->last = where;
                    next->last = current;
                    current->next = next;
                    current->link = (k == 1) ? current : where->link;
                    setPositions.insert(current);
                    delta += next->value(r);
                    delta += current->value(r);
                    current = where;
                    for (int l = 1; l < k; l++) {
                        current->link = current->link->last;
                        delta += current->value(r);
                        current = current->last;
                    }
                    at++;
                }
                answer += delta;
            }
        }
        out << answer << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    TaskE solver;
    solver.solve(1, cin, cout);
    return 0;
}
