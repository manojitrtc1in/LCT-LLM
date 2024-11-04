#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

struct Position {
    int row;
    int id;
    Position* last;
    Position* next;
    Position* link;

    Position(int row, int id) : row(row), id(id), last(nullptr), next(nullptr), link(nullptr) {}

    bool operator<(const Position& other) const {
        if (row != other.row) {
            return row < other.row;
        }
        return id < other.id;
    }

    long long value(int r) const {
        if (link == nullptr) {
            return 0;
        }
        return (row - last->row) * (r - link->row);
    }
};

class TaskE {
public:
    void solve() {
        int r, c, n, k;
        cin >> r >> c >> n >> k;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            x[i]--;
            y[i]--;
        }
        vector<Position> headPosition(k), tailPosition(k);
        for (int i = 0; i < k; i++) {
            headPosition[i] = Position(-1, -1);
            if (i != 0) {
                headPosition[i].last = &headPosition[i - 1];
                headPosition[i - 1].next = &headPosition[i];
            }
        }
        for (int i = 0; i < k; i++) {
            tailPosition[i] = Position(r, -2);
            if (i != 0) {
                tailPosition[i].last = &tailPosition[i - 1];
                tailPosition[i - 1].next = &tailPosition[i];
            }
        }
        vector<Position> positions(n);
        for (int i = 0; i < n; i++) {
            positions[i] = Position(x[i], i);
        }
        long long answer = 0;
        for (int i = 0; i < c; i++) {
            int at = 0;
            while (at < n && y[at] < i) {
                at++;
            }
            for (int j = 0; j < k - 1; j++) {
                headPosition[j + 1].link = &tailPosition[j];
            }
            set<Position> positionSet;
            positionSet.insert(headPosition[k - 1]);
            positionSet.insert(tailPosition[0]);
            headPosition[k - 1].next = &tailPosition[0];
            tailPosition[0].last = &headPosition[k - 1];
            long long delta = 0;
            for (int j = i; j < c; j++) {
                while (at < n && y[at] == j) {
                    auto where = positionSet.lower_bound(positions[at]);
                    auto current = where;
                    for (int l = 1; l < k; l++) {
                        delta -= current->value(r);
                        current = current->last;
                    }
                    auto next = where->next;
                    delta -= next->value(r);
                    current = &positions[at];
                    where->next = current;
                    current->last = where;
                    next->last = current;
                    current->next = next;
                    current->link = (k == 1) ? current : where->link;
                    positionSet.insert(current);
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
        cout << answer << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    TaskE solver;
    solver.solve();

    return 0;
}
