#include <algorithm>
#include <stack>
#include <istream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
#include <set>
#include <cstdio>
#define FR(i,n) for(int i=0;i<n;i++)
#define MAX 2005
#define mkp pair <int,int>
using namespace std;
const int maxn = 2e6 + 3;
typedef long long ll;

void read(int &x) {
	char ch; bool flag = 0;
	for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());
	for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar());
	x *= 1 - 2 * flag;
}


 double arr[maxn];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
     double l=arr[0],r=arr[n-1];
    while(r-l>1e-8)
    {
         double mid=(r+l)/2.0,sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)sum1+=arr[i]-mid;
            if(arr[i]<mid)sum2+=mid-arr[i];
        }
        if(sum1*(100-k)/100.0>sum2)l=mid;
        else r=mid;
    }
    printf("%.8lf\n",r);
    return 0;
}


     


        

         



            

            
            

            


            
            

            


            

            
