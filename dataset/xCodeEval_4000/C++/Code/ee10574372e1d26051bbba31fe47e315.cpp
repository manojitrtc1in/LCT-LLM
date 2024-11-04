
 
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset> 
#define ll long long
using namespace std;
ll mod = 1000000007;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);


int mostFrequent(int arr[], int n)
{
    

    sort(arr, arr + n);
 
    

    int max_count = 1, res = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }
 
    

    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }
 
    return res;
}
 

       

       

       

int c[100001][2];
vector<vector<int> >d(100001);
void solve(){


int n;
cin>>n;
vector<int>a(n);
int col=2;
for(int i=0;i<n;i++){
    cin>>a[i];
   c[a[i]][0]=0;
   c[a[i]][1]=0;

}
for(int i=0;i<n;i++){
   c[a[i]][i%2]++;
}
sort(a.begin(),a.end());
for(int i=0;i<n;i++){
   c[a[i]][i%2]--;
}
for(int i=0;i<n;i++){
    if(c[a[i]][0]!=0 || c[a[i]][1]!=0){
        cout<<"NO"<<endl;
        return;
    }
}
cout<<"YES"<<endl;
}
int main()
{
    fast
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
int t;
cin>>t;
  while(t--)
    solve();
   

     
   
    return 0;
}
