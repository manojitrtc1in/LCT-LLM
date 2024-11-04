













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
int arr[555][555];
signed main(){
    int n,k;
    cin>>n>>k;
    int kk=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<k; ++j)
            arr[i][j]=++kk;
    for (int i=1; i<=n; ++i)
        for (int j=k; j<=n; ++j)
            arr[i][j]=++kk;
    int sum=0;
    for (int i=1; i<=n; ++i) sum+=arr[i][k];
    cout<<sum<<en;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j)
            cout<<arr[i][j]<<" ";
        cout<<en;
    }
    return 0;
}
