


using namespace std;







typedef long long int LL ;

int a1[101010],a2[101010];
int abs(int a)
{
    if(a>=0) return a;
    else     return -a;
}
int main(){
    int n;
    int sum1=0,sum2=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a1[i]);
        sum1=sum1+a1[i];
        scanf("%d",&a2[i]);
        sum2=sum2+a2[i];
    }

    int mx=abs(sum2-sum1),s1,s2,pre=0,tem;
    for(int i=1;i<=n;i++)
    {
        

        s1=sum1-a1[i]+a2[i];
        s2=sum2-a2[i]+a1[i];

        tem = abs(s1-s2);
        if( tem>mx){
            mx=tem;
            pre=i;
        }

        
        
    }
    printf("%d\n",pre);

    return 0;
}












