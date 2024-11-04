#include<bits/stdc++.h>
using namespace std;
long long nh[105][105];
struct node
{
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
} a[600005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,m;
        scanf("%lld%lld",&n,&m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%1lld",&nh[i][j]);
            }
        }
        int num=0;
        for(int i=1; i<=n/2*2; i=i+2)
        {
            for(int j=1; j<=m-2; j++)
            {
                if(nh[i+1][j]==1&&nh[i][j]==1)
                {
                    num++;
                    a[num].x1=i;
                    a[num].y1=j;
                    a[num].x2=i+1;
                    a[num].y2=j+1;
                    a[num].x3=i;
                    a[num].y3=j+1;
                    num++;
                    a[num].x1=i+1;
                    a[num].y1=j;
                    a[num].x2=i+1;
                    a[num].y2=j+1;
                    a[num].x3=i;
                    a[num].y3=j+1;
                    nh[i+1][j]=0;
                    nh[i][j]=0;
                }
                else if(nh[i][j]==1)
                {
                    num++;
                    a[num].x1=i;
                    a[num].y1=j;
                    a[num].x2=i+1;
                    a[num].y2=j+1;
                    a[num].x3=i;
                    a[num].y3=j+1;
                    nh[i][j]=(nh[i][j]+1)%2;
                    nh[i][j+1]=(nh[i][j+1]+1)%2;
                    nh[i+1][j+1]=(nh[i+1][j+1]+1)%2;
                }
                else if(nh[i+1][j]==1)
                {
                    num++;
                    a[num].x1=i+1;
                    a[num].y1=j;
                    a[num].x2=i+1;
                    a[num].y2=j+1;
                    a[num].x3=i;
                    a[num].y3=j+1;
                    nh[i+1][j]=(nh[i+1][j]+1)%2;
                    nh[i][j+1]=(nh[i][j+1]+1)%2;
                    nh[i+1][j+1]=(nh[i+1][j+1]+1)%2;
                }
            }
        }
        if(n%2==1)
        {
            for(int i=n-1; i<=n; i=i+2)
            {
                for(int j=1; j<=m-2; j++)
                {
                    
                    if(nh[i][j]==1&&nh[i+1][j]==1)
                    {
                        num++;
                        a[num].x1=i;
                        a[num].y1=j;
                        a[num].x2=i+1;
                        a[num].y2=j+1;
                        a[num].x3=i;
                        a[num].y3=j+1;
                        num++;
                        a[num].x1=i+1;
                        a[num].y1=j;
                        a[num].x2=i+1;
                        a[num].y2=j+1;
                        a[num].x3=i;
                        a[num].y3=j+1;
                        nh[i+1][j]=0;
                    nh[i][j]=0;
                    }
                    else if(nh[i][j]==1)
                    {
                        num++;
                        a[num].x1=i;
                        a[num].y1=j;
                        a[num].x2=i+1;
                        a[num].y2=j+1;
                        a[num].x3=i;
                        a[num].y3=j+1;
                        nh[i][j]=(nh[i][j]+1)%2;
                        nh[i][j+1]=(nh[i][j+1]+1)%2;
                        nh[i+1][j+1]=(nh[i+1][j+1]+1)%2;
                    }
                    else if(nh[i+1][j]==1)
                    {
                        num++;
                        a[num].x1=i+1;
                        a[num].y1=j;
                        a[num].x2=i+1;
                        a[num].y2=j+1;
                        a[num].x3=i;
                        a[num].y3=j+1;
                        nh[i+1][j]=(nh[i+1][j]+1)%2;
                        nh[i][j+1]=(nh[i][j+1]+1)%2;
                        nh[i+1][j+1]=(nh[i+1][j+1]+1)%2;
                    }
                }
            }
        }
        for(int i=1; i<=n-2; i++)
        {
            if(nh[i][m]==1&&nh[i][m-1]==1)
            {
                num++;
                a[num].x1=i;
                a[num].y1=m;
                a[num].x2=i+1;
                a[num].y2=m;
                a[num].x3=i+1;
                a[num].y3=m-1;
                num++;
                a[num].x1=i;
                a[num].y1=m-1;
                a[num].x2=i+1;
                a[num].y2=m;
                a[num].x3=i+1;
                a[num].y3=m-1;
                nh[i][m]=1;
                nh[i][m-1]=1;
            }
            else if(nh[i][m]==1)
            {
                num++;
                a[num].x1=i;
                a[num].y1=m;
                a[num].x2=i+1;
                a[num].y2=m;
                a[num].x3=i+1;
                a[num].y3=m-1;
                nh[i][m]=(nh[i][m]+1)%2;
                nh[i+1][m-1]=(nh[i+1][m-1]+1)%2;
                nh[i+1][m]=(nh[i+1][m]+1)%2;
            }
            else if(nh[i][m-1]==1)
            {
                num++;
                a[num].x1=i;
                a[num].y1=m-1;
                a[num].x2=i+1;
                a[num].y2=m;
                a[num].x3=i+1;
                a[num].y3=m-1;
                nh[i][m-1]=(nh[i][m-1]+1)%2;
                nh[i+1][m-1]=(nh[i+1][m-1]+1)%2;
                nh[i+1][m]=(nh[i+1][m]+1)%2;
            }
        }
        if(nh[n-1][m-1]==0&&nh[n-1][m]==0&&nh[n][m-1]==0&&nh[n][m]==0)
        {
            ;
        }

        else if(nh[n-1][m-1]==0&&nh[n-1][m]==0&&nh[n][m-1]==0&&nh[n][m]==1)
        {
            num++;
            a[num].x1=n;
            a[num].y1=m;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n-1;
            a[num].y3=m;
            num++;
            a[num].x1=n;
            a[num].y1=m;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m-1;
            num++;
            a[num].x1=n;
            a[num].y1=m;
            a[num].x2=n-1;
            a[num].y2=m;
            a[num].x3=n;
            a[num].y3=m-1;
        }

        else if(nh[n-1][m-1]==0&&nh[n-1][m]==0&&nh[n][m-1]==1&&nh[n][m]==0)
        {
            num++;
            a[num].x1=n;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m;
            a[num].x3=n-1;
            a[num].y3=m-1;
            num++;
            a[num].x1=n;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m;
            a[num].x3=n;
            a[num].y3=m;
            num++;
            a[num].x1=n;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
        }

        else if(nh[n-1][m-1]==0&&nh[n-1][m]==0&&nh[n][m-1]==1&&nh[n][m]==1)
        {
            num++;
            a[num].x1=n;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n-1;
            a[num].y3=m;
            num++;
            a[num].x1=n;
            a[num].y1=m;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n-1;
            a[num].y3=m;
        }

        else if(nh[n-1][m-1]==0&&nh[n-1][m]==1&&nh[n][m-1]==0&&nh[n][m]==0)
        {
            num++;
            a[num].x1=n-1;
            a[num].y1=m;
            a[num].x2=n;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
            num++;
            a[num].x1=n-1;
            a[num].y1=m;
            a[num].x2=n;
            a[num].y2=m-1;
            a[num].x3=n-1;
            a[num].y3=m-1;
            num++;
            a[num].x1=n-1;
            a[num].y1=m;
            a[num].x2=n;
            a[num].y2=m;
            a[num].x3=n-1;
            a[num].y3=m-1;
        }

        else if(nh[n-1][m-1]==0&&nh[n-1][m]==1&&nh[n][m-1]==0&&nh[n][m]==1)
        {
            num++;
            a[num].x1=n-1;
            a[num].y1=m;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m-1;
            num++;
            a[num].x1=n;
            a[num].y1=m;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m-1;
        }

        else if(nh[n-1][m-1]==0&&nh[n-1][m]==1&&nh[n][m-1]==1&&nh[n][m]==0)
        {
            num++;
            a[num].x1=n-1;
            a[num].y1=m;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
            num++;
            a[num].x1=n;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
        }

        else if(nh[n-1][m-1]==0&&nh[n-1][m]==1&&nh[n][m-1]==1&&nh[n][m]==1)
        {
            num++;
            a[num].x1=n;
            a[num].y1=m-1;
            a[num].x2=n;
            a[num].y2=m;
            a[num].x3=n-1;
            a[num].y3=m;
        }

        else if(nh[n-1][m-1]==1&&nh[n-1][m]==0&&nh[n][m-1]==0&&nh[n][m]==0)
        {
            num++;
            a[num].x1=n-1;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m;
            a[num].x3=n;
            a[num].y3=m-1;
            num++;
            a[num].x1=n-1;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m;
            a[num].x3=n;
            a[num].y3=m;
            num++;
            a[num].x1=n-1;
            a[num].y1=m-1;
            a[num].x2=n;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
        }

        else if(nh[n-1][m-1]==1&&nh[n-1][m]==0&&nh[n][m-1]==0&&nh[n][m]==1)
        {
            num++;
            a[num].x1=n-1;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m;
            a[num].x3=n;
            a[num].y3=m-1;
            num++;
            a[num].x1=n;
            a[num].y1=m;
            a[num].x2=n-1;
            a[num].y2=m;
            a[num].x3=n;
            a[num].y3=m-1;
        }

        else if(nh[n-1][m-1]==1&&nh[n-1][m]==0&&nh[n][m-1]==1&&nh[n][m]==0)
        {
            num++;
            a[num].x1=n-1;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m;
            a[num].x3=n;
            a[num].y3=m;
            num++;
            a[num].x1=n;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m;
            a[num].x3=n;
            a[num].y3=m;
        }

        else if(nh[n-1][m-1]==1&&nh[n-1][m]==0&&nh[n][m-1]==1&&nh[n][m]==1)
        {
            num++;
            a[num].x1=n-1;
            a[num].y1=m-1;
            a[num].x2=n;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
        }

        else if(nh[n-1][m-1]==1&&nh[n-1][m]==1&&nh[n][m-1]==0&&nh[n][m]==0)
        {
            num++;
            a[num].x1=n-1;
            a[num].y1=m-1;
            a[num].x2=n;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
            num++;
            a[num].x1=n-1;
            a[num].y1=m;
            a[num].x2=n;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
        }

        else if(nh[n-1][m-1]==1&&nh[n-1][m]==1&&nh[n][m-1]==0&&nh[n][m]==1)
        {
            num++;
            a[num].x1=n-1;
            a[num].y1=m;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
        }

        else if(nh[n-1][m-1]==1&&nh[n-1][m]==1&&nh[n][m-1]==1&&nh[n][m]==0)
        {
            num++;
            a[num].x1=n-1;
            a[num].y1=m;
            a[num].x2=n;
            a[num].y2=m-1;
            a[num].x3=n-1;
            a[num].y3=m-1;
        }

        else if(nh[n-1][m-1]==1&&nh[n-1][m]==1&&nh[n][m-1]==1&&nh[n][m]==1)
        {
            num++;
            a[num].x1=n;
            a[num].y1=m-1;
            a[num].x2=n;
            a[num].y2=m;
            a[num].x3=n-1;
            a[num].y3=m;
            num++;
            a[num].x1=n-1;
            a[num].y1=m;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
            num++;
            a[num].x1=n-1;
            a[num].y1=m-1;
            a[num].x2=n;
            a[num].y2=m-1;
            a[num].x3=n;
            a[num].y3=m;
            num++;
            a[num].x1=n;
            a[num].y1=m-1;
            a[num].x2=n-1;
            a[num].y2=m-1;
            a[num].x3=n-1;
            a[num].y3=m;
        }

        printf("%d\n",num);
        int sum=0;
        for(int i=1; i<=num; i++)
        {
            if(a[i].x1==4&&a[i].y1==3) sum++;
            if(a[i].x2==4&&a[i].y2==3) sum++;
            if(a[i].x3==4&&a[i].y3==3) sum++;
            printf("%d %d %d %d %d %d\n",a[i].x1,a[i].y1,a[i].x2,a[i].y2,a[i].x3,a[i].y3);
        }
        

    }
    return 0;
}
