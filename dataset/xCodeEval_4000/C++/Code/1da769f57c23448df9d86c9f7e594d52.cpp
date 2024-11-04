













#pragma GCC optimize("O3")
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <stack>
#include <ctime>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <bitset>


#define en "\n"
#define sqrt(n) sqrt((double) n)
#define double long double
#define all(c) (c).begin() , (c).end()
#define int long long
#define mem0(a) memset(a,0,sizeof(a))
typedef unsigned long long ull;
using namespace std;
const double EPS = 1e-9;
vector<double> l,r;
int N, M, K, H, W, L, R;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (b == 1) {
            r.push_back(a);
        }
        else l.push_back(a);
    }
    sort(all(l)); sort(all(r));
    int lindex = 0;
    int ans = 0;
    for (auto i : r) {
        while (1) {
            if (lindex == l.size()) {
                cout << ans << en;
                return 0;
            }
            if (i > l[lindex]) {
                lindex++;
                continue;
            }
            if (l[lindex] < 0 && l[lindex] + M>0) {
                break;
            }
            double dis = l[lindex] + M;
            double t = (l[lindex] + M - i) / 2;
            if (abs(dis / t - 1) + EPS > K) {
                lindex++;
            }
            else break;
        }
        ans += l.size() - lindex;
    }
    cout << ans << en;
    return 0;
}
