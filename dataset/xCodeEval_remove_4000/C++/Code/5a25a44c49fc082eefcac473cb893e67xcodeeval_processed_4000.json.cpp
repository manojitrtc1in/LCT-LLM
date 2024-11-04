














using namespace std;
const int maxn = 2e5 + 3;
typedef long long ll;

void read(int &x) {
	char ch; bool flag = 0;
	for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());
	for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar());
	x *= 1 - 2 * flag;
}
int arr[maxn];
int tem[maxn],top=0;
int main() {
    int n,k;
    read(n),read(k);
    for(int i=0;i<n;i++){
        read(arr[i]);
        if(arr[i]<0){
           tem[top++]=i+1;
        }
    }
    if(top==0)

    {
        puts("0");
        return 0;
    }
    if(top>k){
        puts("-1");
        return 0;
    }
    for(int i=0;i<top-1;i++){
        tem[i]=tem[i+1]-tem[i]-1;
    }
    int temp = n-tem[top-1];
    sort(tem,tem+top-1);
    int ans=top*2;
 

    int left = k-top;
    for(int i=0;i<top-1;i++)
    {
        int fuck = tem[i];
        if(left-fuck>=0)
        {
            left-=fuck;
            ans-=2;
        }
        else break;
    }

    if(left-temp>=0)
    {
        ans-=1;
    }
    cout<<ans<<endl;
    return 0;
}




    


        

         



            

            
            

            


            
            

            


            

            
