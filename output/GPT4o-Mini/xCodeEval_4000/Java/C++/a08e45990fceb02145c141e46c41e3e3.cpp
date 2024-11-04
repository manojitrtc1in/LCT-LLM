#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include <fstream>

using namespace std;

class B {
private:
    static const string ENTER;
    static const string EXIT;
    static const int MAX_STACK_SIZE = 128;

    static void solve() {
        int n, m;
        cin >> n >> m;

        vector<bool> canBeLeader(n, true);
        vector<bool> used(n, false);
        unordered_set<int> wasBefore;

        struct Event {
            bool enter;
            int index;

            Event(const string& type, int index) : enter(type == ENTER), index(index) {}
        };

        vector<Event> inputEvents;
        for (int i = 0; i < m; ++i) {
            string type;
            int index;
            cin >> type >> index;
            inputEvents.emplace_back(type, index - 1);
        }

        int meetingSize = 0;
        for (const auto& inputEvent : inputEvents) {
            if (!inputEvent.enter && !used[inputEvent.index]) {
                wasBefore.insert(inputEvent.index);
            }
            used[inputEvent.index] = true;
        }

        set<int> zeros;
        meetingSize = wasBefore.size();
        for (const auto& event : inputEvents) {
            if (event.enter) {
                if (meetingSize != 0) {
                    canBeLeader[event.index] = false;
                } else {
                    zeros.insert(event.index);
                }
                ++meetingSize;
            } else {
                --meetingSize;
                if (meetingSize != 0) {
                    canBeLeader[event.index] = false;
                } else {
                    zeros.insert(event.index);
                }
            }
        }

        if (zeros.size() > 1) {
            for (int index : zeros) {
                canBeLeader[index] = false;
            }
        } else if (zeros.size() == 1) {
            int zeroEnter = *zeros.begin();
            if (!wasBefore.empty() && wasBefore.find(zeroEnter) == wasBefore.end()) {
                canBeLeader[zeroEnter] = false;
            }
        }

        vector<int> possibleLeaders;
        for (int i = 0; i < n; ++i) {
            if (canBeLeader[i]) possibleLeaders.push_back(i);
        }

        cout << possibleLeaders.size() << endl;
        for (int leader : possibleLeaders) {
            cout << (leader + 1) << " ";
        }
        cout << endl;
    }

public:
    static void main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        solve();
    }
};

const string B::ENTER = "+";
const string B::EXIT = "-";

int main() {
    B::main();
    return 0;
}
