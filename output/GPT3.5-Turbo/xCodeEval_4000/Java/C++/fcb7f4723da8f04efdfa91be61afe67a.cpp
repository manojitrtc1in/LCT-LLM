#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Count {
    int count = 0;
    long long cost = 0;

    void increment(long long cost) {
        if (count >= k) return;
        this->cost += cost;
        count++;
    }
};

class D {
    int k;
    void solver() {
        int n;
        cin >> n;
        cin >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        unordered_map<int, Count> counts;
        counts[0] = Count();
        for (int number : arr) {
            int num = number;
            int cost = 0;
            while (num > 0) {
                if (counts.find(num) == counts.end()) counts[num] = Count();
                counts[num].increment(cost);
                num = num / 2;
                cost++;
            }
            counts[0].increment(cost);
        }
        long long ans = LLONG_MAX;
        for (auto& count : counts) {
            if (count.second.count >= k)
                ans = min(ans, count.second.cost);
        }
        cout << ans << endl;
    }
};

int main() {
    D d;
    d.solver();
    return 0;
}
