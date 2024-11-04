













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
#define sqrt(n) sqrt((long double) n)


#define all(c) (c).begin() , (c).end()
#define int long long
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int arr[100100];
signed main(signed argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n && m && arr[i] < 0; i++){
        arr[i] *= -1;
        m--;
    }
    sort(arr, arr + n);
    if(m & 1)
        arr[0] *= -1;
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    cout << sum << endl;
    return 0;
}
