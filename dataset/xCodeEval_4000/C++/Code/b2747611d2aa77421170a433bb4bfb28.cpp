#include<bits/stdc++.h>

using namespace std;

int a[100010];
int b[100010],c[100010];

int main()
{
    int n,i;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(i = 0; i<n; i++)
    {
        scanf("%d%d",&b[i],&c[i]);
        a[b[i]]++;
    }
    for(i = 0; i<n; i++)
    {
        printf("%d %d\n",n-1+a[c[i]],2*(n-1)-(n-1+a[c[i]]));
    }
    return 0;



    


    
    

    
    

    
    
    
    

    



    
    
    
        

    
}
