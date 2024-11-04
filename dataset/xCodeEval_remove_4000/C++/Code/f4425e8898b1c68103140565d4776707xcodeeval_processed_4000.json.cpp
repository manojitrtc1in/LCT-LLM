      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      using namespace std;
      int main()
      {

      
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
      


            std::ios::sync_with_stdio(false);
            int T;
           T=1;
            

            while(T--)
            {
                  
                  int n,m;

                  cin>>n>>m;

                  int x=n+1;
                  int y=m+1;

                  int a[x];
                  int b[y];

                  for(int i=0;i<x;i++) {
                        cin>>a[i];
                  }

                  for(int j=0;j<y;j++) {
                        cin>>b[j];
                  }

                  if((n>m)&&min(n,m)!=0) {
                        if((a[0]>0&&b[0]>0)||(a[0]<0&&b[0]<0)) {
                              cout<<"Infinity";
                        }
                        else {
                              cout<<"-Infinity";
                        }
                  }

                  else if(m>n) {
                        cout<<"0/1";
                  }


                

                 else if(m==0&&n==1) {
                        if(a[0]<0) {
                              cout<<"-";
                        }
                        cout<<"Infinity";
                 }

            

                 else if(m==0&&n>1) {
                        if((a[0]>0&&b[0]<0)||(a[0]<0&&b[0]>0)) {
                              cout<<"-";
                        }
                        cout<<"Infinity";
                 }

                 else if(n==m) {

                        if(a[0]<0&&b[0]>0||a[0]>0&&b[0]<0) {
                              cout<<"-";
                        }

                  cout<<(abs(a[0])/__gcd(abs(a[0]),abs(b[0])))<<"/"<<(abs(b[0])/__gcd(abs(a[0]),abs(b[0])));
                 }


                  else if(n>0&&m>0) {

                        int upper=a[0];
                        int lower=b[0];

                        while(n>0) {
                              upper*=n;
                              n--;
                        }

                        while(m>0) {
                              lower*=m;
                              m--;
                        }


                        if(upper<0&&lower>0||upper>0&&lower<0) {
                              cout<<"-";
                        }

                        upper=abs(upper);
                        lower=abs(lower);
                       

                        cout<<(upper/__gcd(upper,lower))<<"/"<<(lower/__gcd(upper,lower));

                  }



            }
            return 0;
      }