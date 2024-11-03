



using namespace std;





















bool pal(string n)
{
    int a[26]={0};
    int c=0;
    for(int i=0;i<n.size();i++)
        a[n[i]-'a']++;
    for(int i=0;i<26;i++)
        {
            if(a[i]&1)
                c++;
        }
    if(n.size()%2==1&&c==1) return true;
    else if(n.size()%2==0&&c==0) return true;
    else return false;
    

}





bool isprime(ll n)
{
    if(n<2) return false;
    if(n==2||n==3) return true;
    if(n%2==0||n%3==0) return false;
    for(ll i=3;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
const int mod=1e9+7;
ll power(ll a,ll b)
{
    ll ans=1;
    while(b--)
    {
        ans*=a;
        ans%=mod;
    }
    return ans%mod;
}
ll fast_power(ll b,ll p)
{
    if(p==0) return 1;
    ll r=fast_power(b,p/2);
    ll rr=r*r;
    if(p&1) rr=rr*b;
    return rr;
}
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}


long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
bool comp(pair<ll,ll>f,pair<ll,ll>s)
{
    if(f.first==s.first) return f.second<s.second;
    return f.first>s.first;
}
string multiply(string n1, string n2)
{
    if(n1=="0"||n2=="0") return "0";
    string s(n1.size()+n2.size(),'0');
    for(int i=n1.size()-1;i>=0;i--)
    {
        for(int j=n2.size()-1;j>=0;j--)
        {
            ll num=((n1[i]-'0')*(n2[j]-'0'))+s[i+j+1]-'0';

            s[i+j+1]=(num%10)+'0';
            s[i+j]+=(num/10);
        }
    }
    for(int i=0;i<s.size();i++)if(s[i]!='0') return s.substr(i);
}





vector<ll>v;
int arr[3]={1,2,3};
void solve(int i,int n,int arr[])
{
    if(i==n){for(auto &i:v)
    {
        cout<<i<<" ";
    }cout<<endl;}
    else
    {
        cout<<"i "<<i<<endl;
        v.push_back(arr[i]);
        solve(i+1,n,arr);
        cout<<"j "<<i<<endl;
        v.pop_back();
        solve(i+1,n,arr);
    }
}
int main()
{
    shady
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
         
        
        ll c=0;
        ll mx=0;
        ll temp=arr[n-1];
        for(ll i=n-2;i>=0;i--)
        {
            if(arr[i]>temp)
            {
                c++;
                temp=arr[i];
            }
            

            

        }
         cout<<c<<"\n";

        

        

        

        

        

        

        
    }
    
 return 0;
}
    
        

        
  

    

    







    


    
    









        
    

    
    
    
    
    

    

    
        
        
        

       

         

       












    

    

    

    
    










    
        

        

          

           

        

 
 



        
            

           
            

            

       
        
        
   

    
    
   

    
    

        

        

        

        

        

        

        

        

        

        
        

        

    
    

   

     
     
     

    
   



  

  
 
    

    

    

    

    

    

    

    

    

    

    

   
      

     
  



             
               
             
             

             

             
                


                

                

                   


                

               

             

              


         

         

           




     
         

    
    

    
   
    
    

       

    
    
        

        


        

        

    

    


    
    
    
  



    
    
    
      

    



    

    

    

    

    
        

        
      

   





    
    


    
        
      
    
    
    

    

    

    

    

    

    
               

  
 































   

  

