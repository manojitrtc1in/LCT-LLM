













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
typedef long long ll;
using namespace std;
int arr[100100],cnt[100100];
signed main(signed argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int max1=0,max2=0;
    for (int i=1; i<=n; ++i){
        cin>>arr[i];
        if (arr[i]>max1){
            cnt[arr[i]]--;
        }else{
            if (arr[i]<max1 && arr[i]>max2){
                ++cnt[max1];
            }
        }
        if (arr[i]>max1){
            max2=max1;
            max1=arr[i];
        }else
            if (arr[i]>max2)
                max2=arr[i];
       

    }
    int x=1;
    if (n==1){
        cout<<1<<en;
        return 0;
    }
    for (int i=2; i<=n; ++i){
        

        if (cnt[arr[i]]>cnt[arr[x]]) x=i;
        if (cnt[arr[i]]==cnt[arr[x]]) if (arr[x]>arr[i]) x=i;
    }
    cout<<arr[x]<<en;
    return 0;
}
