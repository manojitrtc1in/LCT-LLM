











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
#define double long double
#define all(c) (c).begin() , (c).end()
#define int long long
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
struct point{
    int x, y;
};
struct box{
    bool iss;
    point left,right;
};
box arr[200200];
box pref[200200];
box sufix[200200];
box combine(box a, box b){
    box ans;
    ans.iss=0;
    if ((!a.iss) || (!b.iss))
        return ans;
    ans.iss=1;
    if (a.left.x>b.right.x){
        ans.iss=0;
    }
    if (b.left.x>a.right.x){
        ans.iss=0;
    }
    if (a.left.y>b.right.y){
        ans.iss=0;
    }
    if (b.left.y>a.right.y){
        ans.iss=0;
    }
    ans.left.x=max(a.left.x,b.left.x);
    ans.right.x=min(a.right.x,b.right.x);
    ans.left.y=max(a.left.y,b.left.y);
    ans.right.y=min(a.right.y,b.right.y);
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; ++i){
        cin>>arr[i].left.x>>arr[i].left.y>>arr[i].right.x>>arr[i].right.y;
        arr[i].iss=1;
    }
   

    pref[0].left.x=-1000000000;
    pref[0].left.y=-1000000000;
    pref[0].right.x=1000000000;
    pref[0].right.y=1000000000;
    pref[0].iss=1;
    pref[n+1]=pref[0];
    sufix[0]=pref[0];
    sufix[n+1]=pref[0];
    for (int i=1; i<=n; ++i)
        pref[i]=combine(arr[i], pref[i-1]);
    for (int i=n; i>=1; --i)
        sufix[i]=combine(sufix[i+1], arr[i]);
    box ans;
    for (int i=1; i<=n; ++i){
        if (pref[i-1].iss && sufix[i+1].iss){
           

            ans=combine(pref[i-1], sufix[i+1]);
            if (ans.iss){
                

                cout<<ans.left.x<<" "<<ans.left.y<<en;
                return 0;
            }
        }
        
    }
    return 0;
}
