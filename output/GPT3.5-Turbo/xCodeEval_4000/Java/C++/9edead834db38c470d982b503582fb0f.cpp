#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int mod = pow(10, 9) + 7;
int n;
int m;
int a[105][105][105];
string st[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    int m;
    cin >> n >> m;
    long long a[m];
    
    for(int i=0; i<m; i++)
        a[i] = n/m;
    for(int i=1; i<=n%m; i++)
        a[i]++;
    
    long long b[m];
    for(int i=0; i<m; i++) {
        int t = ((i)%m * (i)%m)%m;
        b[t] += a[i];
    }
    long long ans = 0;
    for(int i=0; i<m; i++) {
        if(i==0) {
            ans += (b[i]*(b[i]));
        }
        else {
            ans += b[i] * b[m-i];
        }
    }
    cout << ans << endl;

    return 0;
}
