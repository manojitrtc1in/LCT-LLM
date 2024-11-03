#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

class FastReader {
public:
    FastReader() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    string next() {
        string s;
        cin >> s;
        return s;
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }

    double nextDouble() {
        double x;
        cin >> x;
        return x;
    }

    string nextLine() {
        string s;
        getline(cin, s);
        return s;
    }
};

class Main {
public:
    static void solve() {
        FastReader scn;

        vector<long long> list;
        vector<long long> listl;
        vector<int> lista;
        vector<int> listb;

        unordered_map<int, int> map;

        unordered_map<int, int> map1;
        unordered_map<int, int> map2;

        unordered_set<int> set;

        unordered_set<int> setx;
        unordered_set<int> sety;

        string ans = "";

        int testcases = 1;

        for (int testcase = 1; testcase <= testcases; testcase++) {
            long long n = scn.nextLong();
            long long x = n;

            for (long long i = 2; i * i <= n; i++) {
                if (x % i == 0) {
                    while (x % i == 0) {
                        list.push_back(i);
                        x = x / i;
                    }
                }
            }

            if (x > 1) {
                list.push_back(x);
            }

            if (n == 1) {
                cout << 1 << endl;
                cout << 0 << endl;
            } else if (list.size() == 2) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;

                if (list.size() == 1) {
                    cout << 0 << endl;
                } else {
                    long long ans = list[0] * list[1];
                    cout << ans << endl;
                }
            }

            ans = "";
            list.clear();
            listb.clear();
            map.clear();
            map1.clear();
            map2.clear();
            set.clear();
            sety.clear();
        }
    }
};

int main() {
    Main::solve();
    return 0;
}
