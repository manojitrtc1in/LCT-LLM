




using namespace std;

int arr[301000],n,pc=0,cb=0;

int main()

{
    scanf(" %d",&n);

    for(int i=0; i<n; i++)
    {
        scanf(" %d",&arr[i]);
        if(i>0&&arr[i-1]>arr[i])
        {
            pc++;
            cb=i;
        }

    }if(arr[n-1]>arr[0])pc++,cb=n;
    

    if(pc>=2)printf("-1\n");
    else if(pc==0)printf("0\n");
    else printf("%d\n",n-cb);
    return 0;
}
