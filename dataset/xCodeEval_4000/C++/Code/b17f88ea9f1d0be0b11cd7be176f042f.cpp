
#include <iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<string>

using namespace std;

int main() {
    int n, k,n1;
    cin >> n >> k;
    n1 = n;
    for (int i = 0; i < k; i++) {
        cout << n1 << " ";
        n1--;
    }
    for (int i = 0; i < n - k; i++) {
        cout << i + 1 << " ";
    }
    return 0;
}