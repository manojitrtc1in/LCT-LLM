#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

class B {
private:
    static const string ENTER;
    static const string EXIT;
    static const int id15 = 128;

    static void timeInit(clock_t &timeBegin) {
        timeBegin = clock();
    }

    static void time(clock_t timeBegin) {
        clock_t timeEnd = clock();
        cerr << "Time = " << (double)(timeEnd - timeBegin) / CLOCKS_PER_SEC << endl;
    }

    static int readInt() {
        int value;
        cin >> value;
        return value;
    }

    static string readString() {
        string value;
        cin >> value;
        return value;
    }

    void solve() {
        int n = readInt();
        int m = readInt();

        vector<bool> id33(n, true);
        vector<Event> inputEvents(m);

        for (int i = 0; i < m; ++i) {
            inputEvents[i] = Event(readString(), readInt() - 1);
        }

        unordered_set<int> wasBefore;
        vector<bool> used(n, false);

        for (const auto& inputEvent : inputEvents) {
            if (!inputEvent.enter && !used[inputEvent.index]) {
                wasBefore.insert(inputEvent.index);
            }
            used[inputEvent.index] = true;
        }

        set<int> zeros;
        int meetingSize = wasBefore.size();

        for (const auto& event : inputEvents) {
            if (event.enter) {
                if (meetingSize != 0) {
                    id33[event.index] = false;
                } else {
                    zeros.insert(event.index);
                }
                ++meetingSize;
            } else {
                --meetingSize;
                if (meetingSize != 0) {
                    id33[event.index] = false;
                } else {
                    zeros.insert(event.index);
                }
            }
        }

        if (zeros.size() > 1) {
            for (int index : zeros) {
                id33[index] = false;
            }
        } else if (zeros.size() == 1) {
            int zeroEnter = *zeros.begin();
            if (!wasBefore.empty() && wasBefore.find(zeroEnter) == wasBefore.end()) {
                id33[zeroEnter] = false;
            }
        }

        vector<int> id14;
        for (int i = 0; i < n; ++i) {
            if (id33[i]) id14.push_back(i);
        }

        cout << id14.size() << endl;
        for (int leader : id14) {
            cout << (leader + 1) << " ";
        }
        cout << endl;
    }

public:
    void run() {
        try {
            clock_t timeBegin;
            timeInit(timeBegin);
            solve();
            time(timeBegin);
        } catch (exception &e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }

    static void main() {
        B b;
        b.run();
    }

    class Event {
    public:
        bool enter;
        int index;

        Event(string type, int index) {
            this->enter = (type == ENTER);
            this->index = index;
        }
    };
};

const string B::ENTER = "+";
const string B::EXIT = "-";

int main() {
    B::main();
    return 0;
}
