

using namespace std;



const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18+1;





ll factorize(long long n){
        ll count=0,count1=2;
        ll k=n;
        while(!(n%2)){
            n=n>>1;
            count++;
        }

       
if(count)
 count1++;
     
for(int i =3;i<=sqrt(n);i+=2)
  {  count=0;
    while(n%i==0)
    {
        count++;
        n=n/i;
    }
    if(count)
        count1++;
}
 


        if(n>2)
        {   count1++;
            if(k==n)
                count1=count1-1;
        }
     

    return count1;
}


 bool isprime(ll n){
    if(n==1||n==0)
       return false;
    if(n==2||n==3)
       return true;
    if(n%2==0)
        return false;
for(int i=3;i<=sqrt(n);i+=2)
{   
     if(n%i==0)
      {  return false;

      }
      
}

return true;
}

ll binarySearch(vector<pair<ll, ll> >&arr, ll l, ll r, ll x)
{
    if (r >= l) {
        ll mid = l + (r - l) / 2;

        

        

        if (arr[mid].first == x)
            return mid;

        

        

        if (arr[mid].first > x)
            return binarySearch(arr, l, mid - 1, x);

        

        

        return binarySearch(arr, mid + 1, r, x);
    }

    

    

    return -1;
}



bool id0(const pair<ll,ll> &a,
                   const pair<ll,ll> &b)
{      
          return a.second<b.second;
}































    
    



















   


    



 







        











































































  
     































  










ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
           

    


 

























































































































































ll countzero(ll n){
  ll temp=0;
  ll count=0;
  while(temp==0)
  {
    temp=n%10;
    n/=10;
    if(temp==0)
      count++;

  }
  return count;
}


string longDivision(string number, int divisor,int & count)
{
  
    string ans;
 
  
    int idx = 0;
    int temp = number[idx] - '0';

    while (temp < divisor)
       { temp = temp * 10 + (number[++idx] - '0');
          count++;}
 
   
    while (number.size() > idx) {
        
        ans += (temp / divisor) + '0';
 
          cout<<temp%divisor<<nline;
        temp = (temp % divisor) * 10 + number[++idx] - '0';
        count++;
        if(temp%divisor==0)
          break;
    }
            ll i= count;
            

        while(number[i]=='0'){
          ans+='0';
          i++;
        }
    
    if (ans.length() == 0)
        return "0";
 
    
    return ans;
}
bool isPalindrome(string s) {
    int n = s.length();
  
    for (int i = 0; i < (n / 2) + 1; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}
















           


           


          






            





























      
       


























































        




























             









              






























              































































       














































































































































































































 


 

 

 

 


 


  














 






   
    




 




























































  


















  




  
  void solve(){

ll n;
cin>>n;
    
ll val=1;
ll mark=-1;
ll count=0;

for(int i=1;i<n;i++)
{
    if(__gcd(n,(ll)i)==1)
      {
        count++;
        val=(val*i)%n;}
}
   

   

      if(val!=1)
        mark=val%n;
        if(mark!=-1&&mark!=1)
          count--;
       

      cout<<count<<nline;
      for(int i=1;i<n;i++)
       { if(i!=mark&&__gcd(n,(ll)i)==(ll)1)
          cout<<i<<" ";
       }

         cout<<nline;
}   



  
  





















































































  

  

  

  

  

  

  

  

  

  

  

                
  

  

  

  

  

  

               
  

  

                   
  

  

            

            

            

            

            

            

                
            

            

            

            

            

            

            

            

            


            

        
 

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  


  

  


 








int main()
{









    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   

    for (int t = 1; t <= tc; t++) {
        

        solve( );

    }
    return 0;
}