        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
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
            int ans=0,temp=0,n;
            read(n);
            for(int i=0;i<n;i++)
            {
                scanf("%d",&arr[i]);
                if(arr[i]<0)temp++;
            }
            if(temp==1||temp==0)printf("1\n");
            else
            printf("%d\n",temp/2+temp%2);
            temp=0;
            for(int i=0;i<n;i++)
            {
                if(arr[i]<0)temp++;
                ans++;
                if(temp>=3)
                {
                    temp=1;
                    printf("%d ",ans-1);ans=1;
                }
            }
            if(ans)
            {
                printf("%d",ans);
            }
            return 0;
        }



        

        

        


        

         



            

            
            

            


            
            

            


            

            
