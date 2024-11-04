
#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int i;
    int a[100001];
    int s[100001]={0},ans,x;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        int x=(i+1)%k;
        s[x]+=a[i];
    }
    int min=1000000000;
    for(i=1;i<k;i++)
    {
        if(min>s[i])
        {
            min=s[i];
            ans=i;
        }
    }
    if(min>s[0])
        ans=k;
    printf("%d\n",ans);
    return 0;
}


