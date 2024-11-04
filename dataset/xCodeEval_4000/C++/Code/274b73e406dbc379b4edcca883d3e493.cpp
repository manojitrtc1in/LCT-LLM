#include <bits/stdc++.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<limits.h>



using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define inc(x) int x;	cin>>x;
#define printarr(x,n) for(int i=0; i<n; ++i) cout<<x[i]<<" "; cout<<endl
#define print2arr(x,n,m) for(int i=0; i<n; ++i) {for(int j=0; j<m; ++j) {cout<<x[i][j]<<" ";} cout<<endl;}  cout<<endl


#define For(i, st, end) for(int i=st; i<end; ++i)


#define dv(v) for(int x:v) cout<<x<<" "; cout<<endl;
#define ceili()


#define int                     long long
#define ll                      long long
#define ld                      long double
#define endl                    "\n"
#define vi                      vector<int>
#define vpl                     vector<pair<long long ,long long>>
#define pii                     pair<int,int> 	
#define mii                     map<int,int>
#define pb                      push_back
#define ppb                     pop_back
#define ff                      first
#define ss                      second  
#define YES                     cout <<"YES"<<endl
#define yes                     cout <<"YES"<<endl
#define NO                      cout <<"NO"<<endl
#define no                      cout <<"NO"<<endl
#define MOD                     1000000007
#define INF                     LONG_MAX
#define NINF                    LONG_MIN
#define hehe                    cout<<"hehe\n"












































ll power(long long x, long long y){
    int res = 1;     

    x = x % MOD; 

                

    if (x == 0) return 0; 

    while (y > 0){
        

        if (y & 1)
            res = (res*x) % MOD;
        

        y = y>>1; 

        x = (x*x) % MOD;
    }
    return res;
}
ll _ceil(long long x, long long y){
    if(x%y==0){
        return x/y;
    }
    else{
        return ((x/y) + 1);
    }
}
int lcm(long long a, long long b){return (a / __gcd(a, b)) * b;}
int gcd(long long a, long long b){return __gcd(a,b);}
int hcf(long long a, long long b){return __gcd(a,b);}
bool sortbysec(const pair<long long,long long> &a,const pair<long long,long long> &b){return (a.second < b.second);}
bool isPerfectSquare(long double x){
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
bool isPowerOfTwo(ll n){
    if(n==0)
            return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
int binarySearch(int arr[], int l, int r, int x){
    if (r >= l){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
string xoring(string a, string b, int n){
    string ans = "";
    
    

    

    for (int i = 0; i < n; i++)
    {
        

        if (a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    return ans;
}
int binaryToDecimal(int n){
    int num = n;
    int dec_value = 0;

    

    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
        

        

    }
    return count;
}

string multiply(string num1, string num2){   
    

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




ll lengthOfLIS(vector<ll>& a)
{
    ll n = a.size();
    vector<ll> len;
    for(ll i = 0; i < n; i++)
    {
        auto lb = upper_bound(len.begin(), len.end(), a[i]);
        if(lb != len.end())
        {
            *lb = min(*lb, a[i]);
        }
        else
        {
            len.push_back(a[i]);
        }
    }
    return len.size();
}

int sum1(int a[], int size){
    int sum =0;
    For(i,0,size){
        For(j,i+1,size){
            sum += (a[i]+a[j])*(a[i]+a[j]);
        }
    }
    return sum;
}


const int size_dp = 2001;




vi ar[200001];
int vis[2001], col[2001];

int dfs(int node){
    vis[node]=1;
    

    int maxa = 0;
    for(int child: ar[node]){
        if(!vis[child]){
            if(child>node && child>maxa){
                maxa = child;
            }
            dfs(child);
            

            

            

        }
        

        

        

        

        

    }
    if(maxa==0){
        return -1;
    }
    return maxa;

    

    

    

    


    


}

void solve(){
   
    int n,m;
    cin>>n;
    int a[n];
    For(i,0,n){
        cin>>a[i];
    }
    int count=0;
    int st = 0,en=n-1;
    For(i,0,n){
        if(a[i]==0){
            st=i-1;
            break;
        }
        count++;
    }
    for(int i=n-1; i>-1; --i){
        if(a[i]==0){
            en=i+1;
            break;
        }
    }
    if(count==n) cout<<0<<endl;
    else
    cout<<en-st<<endl;
}
















































































































































































































signed main(){
    fastio;
    

    

    

    

    

    

    

    

    

    

    

    

    


    


    
    
    

    

    int tt = 1;
    cin>>tt;
    

    For(i,0,tt){
        

        

        solve();
    }



}






























































































































