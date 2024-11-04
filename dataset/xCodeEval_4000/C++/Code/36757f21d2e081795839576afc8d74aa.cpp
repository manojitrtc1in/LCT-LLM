#include <cstdlib>
#include <string>
#include <iostream>
#include <unordered_set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;
typedef long long ll;

#ifdef CODEFORCES_2019_02_25_3_H
int codeforces_2019_02_25_1() {
#else
int main() {
#endif
    ll n;
    cin >> n;

    

    

    

    

    

    

    

    

    
    vector<string> input;
    vector<string> sorted;
    for (ll i = 0; i < 2 * n - 2; i++) {
        string temp;
        cin >> temp;
        input.push_back(temp);
        sorted.push_back(temp);
    }
    sort(sorted.begin(), sorted.end(), 
        [&](string a, string b) { 
        if (a.size() > b.size())
            return true; 
        return false; 
    });

    string possible1;
    string possible2;
    bool flag1 = true;
    bool flag2 = true;
    vector<char> res1;
    vector<char> res2;

    possible1 = sorted[1].at(0) + sorted[0];
    possible2 = sorted[0].at(0) + sorted[1];
    ll poslen = possible1.size();

    unordered_set<string> used1;
    unordered_set<string> used2;
    for (ll i = 0; i < input.size(); i++) {
        ll f1s = possible1.find(input[i]);
        ll f1e = possible1.find(input[i], poslen-input[i].size());
        ll s2s = possible2.find(input[i]);
        ll s2e = possible2.find(input[i], poslen-input[i].size());
        if (f1s != 0 && f1e != poslen - input[i].size()) {
            flag1 = false;
        } 
        else {
            if (f1s == 0 && used1.find(input[i]) == used1.end()) {
                res1.push_back('P');
                used1.emplace(input[i]);
            }
            else res1.push_back('S');
        }

        if (s2s != 0 && s2e != poslen - input[i].size()) {
            flag2 = false;
        }
        else {
            if (s2s == 0 && used2.find(input[i]) == used2.end()) {
                res2.push_back('P');
                used2.emplace(input[i]);
            }
            else res2.push_back('S');
        }
    }

    if (flag1) {
        for (const auto& elem : res1) {
            cout << elem;
        }
    } else {
        for (const auto& elem : res2) {
            cout << elem;
        }
    }
    return 0;
}
