














using namespace std;
const int maxn = 2e6 + 3;
typedef long long ll;

void read(int &x) {
	char ch; bool flag = 0;
	for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());
	for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar());
	x *= 1 - 2 * flag;
}


int arr[maxn];
int main() {
    int n;
    int k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
  double eta=(1-0.01*(double)k);
    sort(arr,arr+n);
    double l=arr[0],r=arr[n-1];
    for(int i=0;i<100;i++)
    {
        double mid=(l+r)/(2.0);
        double sum1=0,sum2=0;
        for(int j=0;j<n;j++)
        {
            if(mid>arr[j])sum1+=mid-arr[j];
            else sum2+=arr[j]-mid;
        }
        if(sum2*eta>sum1)l=mid;
        else r=mid;
    }    printf("%.8lf\n",r);
    return 0;
}



     


        

         



            

            
            

            


            
            

            


            

            
