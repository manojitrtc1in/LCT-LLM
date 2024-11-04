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
const int maxn = 2e4 + 3;
typedef long long ll;

void read(int &x) {
	char ch; bool flag = 0;
	for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());
	for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar());
	x *= 1 - 2 * flag;
}

int n;
int a[maxn],b[maxn];

int main() {
    int n;
    read(n);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n*(n-1)/2-1;i++){
        int l,r;
        read(l),read(r);
        a[l]++;
        a[r]++;
        b[l]++;
    }
    int a1=0,a2=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=n-1&&!a1)a1=i;
        if(a[i]!=n-1&&a1)a2=i;
    }
    if(b[a1]>b[a2])printf("%d %d\n",a1,a2);
    else printf("%d %d\n",a2,a1);
    return 0;
}




    


        

         



            

            
            

            


            
            

            


            

            
