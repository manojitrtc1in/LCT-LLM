





using namespace std;
int k,m;
void res(int s,int n){
     int dem=10;
     if(s>k) return;
     if(k-s<10){
                while(m&&dem<100){cout<<dem<<"0"<<k-s;
                if(n<10) cout<<"000";
                 else if(n<100) cout<<"00";
                 else if(n<1000) cout<<"0";
                 cout<<n<<endl;m--;dem++;}
                return;
                }
     else if(k-s<100) cout<<"00"<<k-s;
     else if(k-s<1000) cout<<"0"<<k-s;
     else if(k-s<10000) cout<<k-s;
     if(n<10) cout<<"000";
     else if(n<100) cout<<"00";
     else if(n<1000) cout<<"0";
     cout<<n<<endl;
     m--;
     }
void process(){
     int a,b,c,d,s;
     f(i,0,9999)
     {
     bool x[10000]={0};                      
     a=i;
     d=a%10;a/=10;c=a%10;a/=10;b=a%10;a/=10;
     s=a*b*c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+b+c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+b+c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-b+c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a-b+c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+b-c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+b-c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-b-c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a-b-c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+b+c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+b+c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-b+c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a-b+c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+b-c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+b-c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-b-c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a-b-c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*b+c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*b-c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*b-c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*b+c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a*b-c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a*b+c-d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a*b+c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a*b-c+d; if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-(a+b*c+d); if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-(-a+b*c+d); if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-(a+b*c-d); if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-(-a+b*c-d); if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b*c+d); if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a+b*c+d); if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b*c-d); if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a+b*c-d); if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+b+c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+b-c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-b+c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-b-c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+b+c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+b-c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a-b+c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=10*a+b+c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-10*a-b+c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=10*a+b-c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=10*a+b+c-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=10*a+b-c-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=10*a+b+10*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=10*a+b-10*c-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-10*a-b+10*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+b+10*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+b-10*c-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-b+10*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+b+10*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a-b+10*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+10*b+c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-10*b-c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+10*b+c-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+10*b+c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+10*b+c-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a+b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a-b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b-c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a-b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a+b-c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a-b-c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b+c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(-b+c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b-c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b+c-d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(-b-c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b-c-d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(-b+c-d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b)*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b)*c-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a+b)*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a+b)*c-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a-b)*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a-b)*c-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a-b)*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+b*(c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-b*(c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+b*(c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+b*(-c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-b*(-c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+b*(-c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b)*(c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a-b)*(c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b)*(c-d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a-b)*(c-d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a+b)*(c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b)*(-c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b+c)+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b+c)-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b-c)+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b-c)-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(-b+c)+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(-b+c)-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(-b-c)+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+(b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+(b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+(-b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+(-b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a+(b-c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a+(b-c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a-(b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=10*a+b+c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=10*a+b-c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-10*a-b+c*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*b+10*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*b-10*c-d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=-a*b+10*c+d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a*b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a*b-c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b*c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a-b*c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a+b*c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a*b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b*c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b*c-d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(-b*c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b+c*d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b-c*d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(-b+c*d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(10*a+b)*(c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(10*a+b)*(c-d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(10*a+b)*(-c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a+b)*(10*c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(a-b)*(10*c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=(-a+b)*(10*c+d);if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(b-c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     s=a*(-b+c)*d;if(s>0&&x[s]==0){x[s]++;res(s,i);} if(m==0) return;
     
     }
     }
void process1(){
     for(int i=0;i<m;i++)
     if(i<10) cout<<"0000000"<<i<<endl;
     else if(i<100) cout<<"000000"<<i<<endl;
     else if(i<1000) cout<<"00000"<<i<<endl;
     else if(i<10000) cout<<"0000"<<i<<endl;
     else if(i<100000) cout<<"000"<<i<<endl;
     else if(i<1000000) cout<<"00"<<i<<endl;
     }     
main(){
       cin>>k>>m;
       if(k==0) process1();
       else
       process();         
      

       }
