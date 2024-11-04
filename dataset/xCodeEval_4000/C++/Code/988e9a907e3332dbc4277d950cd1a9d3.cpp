
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define ulli unsigned long long int
#define lli long long int
#define ll long long 
#define dd double
#define endl "\n"
#define all(x) x.begin(),x.end()
#define allar(a,n) a,a+n
#define mod 1000000007
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define limit 1000000000000000000



using namespace std;
lli prm[1000001];
vector<lli>phi(1000000);
vector<lli>arr(1000000);
lli mulmod(lli a, lli b,lli c){
    lli x = 0,y=a%c;
    while(b > 0){
    if(b%2 == 1){
        x = (x+y)%c;
    }
    y = (y*2LL)%c;
    b /= 2;
    }
    return x%c;
}
 
lli binPower(lli a , lli n , lli m)
{
	lli res = 1;
 
	while(n)
	{
		if(n & 1)
		res = mulmod(res , a , m);
 
		n >>= 1;
		a = mulmod(a , a , m);
	}
 
	return res % m;
}
int printNcR(int n, int r) 
{ 
  
    
    long long p = 1, k = 1; 
  
    
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
  
            

            long long m = __gcd(p, k); 
  
            

            

            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
  
        

        

        

    } 
  
    else
        p = 1; 
  
    

    return p; 
} 
lli find_max(lli ar[],lli n)
{
	lli x=ar[0];
	for(int i=0;i<n;i++)if(ar[i]>x)x=ar[i];
	return x;
	
}
lli power(lli x,lli y,lli m)
{
	lli res=1;
	while(y)
	{
		if(y%2!=0)
		{
			res=(res%m*x%m)%m;
			y--;
		}
		else
		{
			x=(x%m*x%m)%m;
			y/=2;
		}
	}
	return res%m;
}
void prosieve(int maxn)
{
	
	lli ar[maxn+1];
	lli cnt=0;
	for(int i=0;i<1000001;i++)prm[i]=0;
	for(int i=0;i<maxn+1;i++)ar[i]=1;
	ar[1]=0;
	ar[0]=0;
	for(int i=2;i*i<=maxn;i++)
	{
		if(ar[i]==1)
		{
			cnt=0;
			for(int j=2*i;j<=maxn;j+=i)
			{
				if(ar[j]==1)
				cnt++;
				
				ar[j]=0;
			}
			prm[i]=cnt+1;
			cnt=0;		
		}
	}
}
int xnor(int a, int b) 
{ 
    

    if (a < b) 
        swap(a, b);  
  
    if (a == 0 && b == 0)  
        return 1;  
  
    int a_rem = 0; 

    int b_rem = 0; 

  
    

    

    int count = 0;  
  
    

    int xnornum = 0; 
  
    

    while (a)  
    { 
        

        a_rem = a & 1;  
  
        

        b_rem = b & 1;  
  
        

        

        if (a_rem == b_rem)         
            xnornum |= (1 << count); 
          
        

        count++;  
        a = a >> 1; 
        b = b >> 1;  
    } 
    return xnornum; 
} 
lli binary(lli x,ll y,lli i,lli j)
{
	if((x+i)==(y+j))return 1;
	lli cnt=1;
	lli x1=x+i;
	lli y1=y+j;
	for(int i=0;i<10;i++)
	{
	

	
		if(x1==y1)return cnt;
		x1+=x;
		y1+=y;
		cnt++;
	}
	
	return -1;
}
bool fermat_prime(lli n,lli iter=5)
{
	if(n==4)
	return n==2||n==3;
	
	for(int i=0;i<iter;i++)
	{
		lli a=2+rand()%(n-3);
		if(binPower(a,n-1,n)!=1)
		return false;
	}
	return true;
}
bool isprm(lli n)
{
	lli c=0;
	if(n==1)return false;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)c++;
	}
	if(c>0)return false;
	else return true;
}

  




lli modInverse(lli a, lli p) 
{ 
    return power(a, p - 2, p); 
} 

int phie(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
void phi_1_to_n(lli n) {
    
    phi[0] = 0;
    phi[1] = 1;
    for (lli i = 2; i <= n; i++)
        phi[i] = i;

    for (lli i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (lli j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
   	for(int i=1;i<n;i++)
   	{
   		phi[i]=i-phi[i];
	}
	for(int i=1;i<n;i++)
   	{
   		phi[i]+=phi[i-1];
	}
}


bool isvalid(lli ar[],lli n,lli mid,lli m)
{

	lli sum=0;
	for(int i=0;i<n;i++)
	{
		if(ar[i]>mid)sum+=ar[i]-mid;
	}
	if(sum>=m)return true;
	else return false;
}
lli binser(lli ar[],lli n,lli m)
{
	lli l=0,res=0;
	ll r=*max_element(ar,ar+n);
	while(l<=r)
	{
		lli mid=l+(r-l)/2;
		if(isvalid(ar,n,mid,m)==true)
		{
			res=mid;
			l=mid+1;
		}
		else 
		{
			r=mid-1;
		}
	}
	return res;
}
void init(lli dp[],string str)
{
	lli p=31;
	lli power=1;
	dp[0]=0;
	for(int i=1;i<=str.length();i++)
	{
		dp[i]=dp[i-1]+(str[i-1]-'A')*power;
		power*=p;
	}
}
void rabin_karp(string s,string t)
{
		const int p = 31; 
    	const int m = 1e9 + 9;
    	int S = s.length(), T = t.length();

    	vector<long long> p_pow(max(S, T)); 
    	p_pow[0] = 1; 
    	for (int i = 1; i < (int)p_pow.size(); i++) 
        	p_pow[i] = (p_pow[i-1] * p) % m;

    	vector<long long> h(T + 1, 0); 
    	for (int i = 0; i < T; i++)
        	h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    	long long h_s = 0; 
    	for (int i = 0; i < S; i++) 
        	h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

   		 vector<int> occurences;
    	for (int i = 0; i + S - 1 < T; i++) { 
        	long long cur_h = (h[i+S] + m - h[i]) % m; 
        	if (cur_h == h_s * p_pow[i] % m)
            	occurences.push_back(i);
    	}
    	if(occurences.size()==0)
    	{
    		cout<<"Not Found"<<endl;
		}
		else 
		{
			cout<<occurences.size()<<endl;
			for(int i=0;i<occurences.size();i++)
			{
				cout<<occurences[i]+1<<" ";
			}
			cout<<endl;
		}
}
string bigmultiply(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
  
    

    

    vector<int> result(len1 + len2, 0); 
  
    

    

    int i_n1 = 0;  
    int i_n2 = 0;  
      
    

    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
  
        

        

        i_n2 = 0;  
          
        

        for (int j=len2-1; j>=0; j--) 
        { 
            

            int n2 = num2[j] - '0'; 
  
            

            

            

            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
  
            

            carry = sum/10; 
  
            

            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
  
        

        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
  
        

        

        i_n1++; 
    } 
  
    

    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
  
    

    

    if (i == -1) 
    return "0"; 
  
    

    string s = ""; 
      
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
}
string longDivision(string number, int divisor) 
{ 
     
    

  
    
    int idx = 0; 
    int temp = number[idx] - '0'; 
    int m;
    while (temp < divisor) 
        temp = temp * 10 + (number[++idx] - '0'); 
  
   
    while (number.size() > idx) { 
        
        

  
        m=temp%divisor;
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
  	if(m==0)
  	{
  		return "1";
	  }
	  else return "0";
     
    

        

  
   
    

} 
bool isSmaller(string str1, string str2)
{
    

    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}
 


string findDiff(string str1, string str2)
{
    

    

    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    

    string str = "";
 
    

    int n1 = str1.length(), n2 = str2.length();
 
    

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    

    

    for (int i = 0; i < n2; i++) {
        

        

 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        

        

        

        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    

    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        

        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    

    reverse(str.begin(), str.end());
 
    return str;
}
string findSum(string str1, string str2) 
{ 
    

    

    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    

    string str = ""; 
  
    

    int n1 = str1.length(), n2 = str2.length(); 
  
    

    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        

        

        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        

        carry = sum/10; 
    } 
  
    

    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    

    if (carry) 
        str.push_back(carry+'0'); 
  
    

    reverse(str.begin(), str.end()); 
  
    return str; 
}
lli possible(lli k,lli ar[],lli n)
{
	lli possiblesum[k+1]={'\0'};
	possiblesum[0]=1;
	
	for(int i=0;i<n;i++)
	{
		for(int j=k;j>=ar[i];j--)
		{
			if(possiblesum[j-ar[i]]==1)
			possiblesum[j]=1;
		}
	}
	return possiblesum[k];
}
lli prime(lli x)
{
	if(isprm(x)==true)return x;
	else return prime(x+1);
	
} 
bool dig(lli n,lli x)
{
	while(n>0)
	{
		if(x==(n%10))return true;
		
		n/=10;
	}
	return false;
 }
 bool isodd(lli i) 
{ 
    if (i % 2 != 0) 
        return true; 
    else
        return false; 
} 
bool iseven(lli i) 
{ 
    if (i % 2 != 0) 
        return true; 
    else
        return false; 
}  

void permute(string a, int l, int r,set<string>&v)
{
    
    if (l == r)
        v.insert(a);
    else
    {
        

        for (int i = l; i <= r; i++)
        {
 
            

            swap(a[l], a[i]);
 
            

            permute(a, l+1, r,v);
 
            

            swap(a[l], a[i]);
        }
    }
}
bool comp (pair<int,int>&a , pair<int,int>&b)
{
	return a.first>b.first;
}
lli sumBase(lli n, lli k,lli ans) {
        
        lli sum_digit = 0;
        
        while(n){
            
            sum_digit += n%k;
            if(sum_digit>=ans)return ans;
            n = n/k;
        }
        
   return sum_digit;
}
int main()
{
	fast
	lli t;
	cin>>t;
	while(t--)
	{
		lli a,b;
		cin>>a>>b;
		lli xr=0;
		
		xr=(a-1)%4;
		lli ans=0;
		if(xr==0)ans=a-1;
		else if(xr==1)ans=1;
		else if(xr==2)ans=a;
		else if(xr==3)ans=0;








		xr=ans;
		lli answer=xr^b;
		
		if(xr==b)
		{
			cout<<a<<endl;
			continue;
		}
		if(((xr)^b)==a)
		cout<<a+2<<endl;
		else
		cout<<a+1<<endl;
	}
	
	return 0;
	
}


