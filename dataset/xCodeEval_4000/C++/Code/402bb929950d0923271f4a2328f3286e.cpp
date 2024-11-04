






















#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define     fRead           freopen("input.txt","r",stdin)
#define     fWrite          freopen("output.txt","w",stdout)
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)

#define     ll              long long int
#define     ul              unsigned long long int
#define     dl              double
#define     st              string

#define     pb              push_back
#define     po              pop_back

#define     nl              endl
#define     rtz             return 0
#define     rt              return 

#define     N               cout << "No" << endl
#define     Y               cout << "Yes" << endl

#define     gcd(a, b)       __gcd(a, b)
#define     lcm(a, b)       (a * b) / gcd(a, b)

#define     mem(a,v)        memset(a,v,sizeof(a))
#define     mod             1000000007
#define     mp              make_pair
#define     ins             insert
#define     rev             reverse
#define     _max            *max_element
#define     _min            *min_element
#define     SUM             accumulate
#define     BS              binary_search

#define     vec             vector <ll>
#define     PL              pair <ll,ll>
#define     vecp            vector < pair <ll, ll> >
#define     vecpp           vector < pair <ll, pair <ll, ll> > >
#define     se              set <ll>
#define     mapi            map<ll,ll>


#define     rep(i, l, r)        for(long long i = l; i<r; i++)
#define     repi(p, l, r, i)    for(long long p = l; p<r; p+=i)
#define     repb(i, r, l)       for(long long i = r; i>l; i--)
#define     repbd(p, r, l, d)   for(long long p = r; i>l; i-=d)

#define     max3(a, b, c)       max(a, max(b, c))
#define     max4(a, b, c, d)    max(max(a, b), max(c, d))
#define     min3(a, b, c)       min(a, min(b, c))
#define     min4(a, b, c, d)    min(min(a, b), min(c, d))

#define     vsort(v)            sort(v.begin(),v.end())
#define     all(container)      container.begin(), container.end()
#define     iterate(v, it)      for(vector< long long >::const_iterator it = v.begin(); it != v.end(); it++)

#define     BIG                 300000

using namespace std;




bool sortinrevbyfirst(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}

bool sortinrevbysecond(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.second > b.second);
}





long long sumofdigits(long long x){
    int s = 0;
    while (x != 0) {
      s += x % 10;
      x = x / 10;
   }
    return s;
}




int checkDiffDigits(string str){
    for(int i = 0; i<str.size(); i++){
        for(int j = i+1; j<str.size();j++){
            if(str[i] == str[j]){
                return false;
                break;
            }
        }
    }
    return true;
}



bool isPowerOfTwo (long long x) 
{ 
  
  return x && (!(x&(x-1))); 
}


long long digitNO(long long num){
    double eps = 1e9;
    return floor(log10(num)) + 1 + eps;
}

string converttostring(long long n){
    string s;
    stringstream ss;
    ss << n;
    s = ss.str();

    return s;
}


long long reversedigits(long long number){
    long long reverse = 0;
    long long rem;
    while(number!=0)    
  {    
     rem=number%10;      
     reverse=reverse*10+rem;    
     number/=10;    
  }

  return reverse;
}














void bubble_sort( int A[ ], int n ) {
      int temp;
      for(int k = 0; k< n-1; k++) {
           

           for(int i = 0; i < n-k-1; i++) {
                  if(A[ i ] > A[ i+1] ) {
                       

                       temp = A[ i ];
                       A[ i ] = A[ i+1 ];
                       A[ i + 1] = temp ;
                   }
           }
     }
 }



void selection_sort (int A[ ], int n) {
    

    int minimum;
    

    for (int i = 0; i < n - 1; i++)
    {
        

        minimum = i;
        

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minimum])
            { 

                minimum = j;
            }
        }
        

        swap(A[minimum], A[i]);
    }
}



void insertion_sort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        
        int temp = A[i];
        int j = i;

        
        while (temp < A[j - 1] && j > 0)
        {
            

            A[j] = A[j - 1];
            j = j - 1;
        }
        

        A[j] = temp;
    }
}



void merge(int A[], int start, int mid, int end)
{
    

    int p = start, q = mid + 1;

    int Arr[end - start + 1], k = 0;

    for (int i = start; i <= end; i++)
    {
        if (p > mid) 

            Arr[k++] = A[q++];

        else if (q > end) 

            Arr[k++] = A[p++];

        else if (A[p] < A[q]) 

            Arr[k++] = A[p++];

        else
            Arr[k++] = A[q++];
    }
    for (int p = 0; p < k; p++)
    {
        
        A[start++] = Arr[p];
    }
}
void merge_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2; 

        merge_sort(A, start, mid);   

        merge_sort(A, mid + 1, end); 


        

        merge(A, start, mid, end);
    }
}



int partition(int A[], int start, int end)
{
    int i = start + 1;
    int piv = A[start]; 

    for (int j = start + 1; j <= end; j++)
    {
        

        if (A[j] < piv)
        {
            swap(A[i], A[j]);
            i += 1;
        }
    }
    swap(A[start], A[i - 1]); 

    return i - 1;             

}
int rand_partition(int A[], int start, int end)
{
    

    int random = start + rand() % (end - start + 1);

    swap(A[random], A[start]);       

    return partition(A, start, end); 

}
void quick_sort(int A[], int start, int end)
{
    if (start < end)
    {
        

        int piv_pos = rand_partition(A, start, end);
        quick_sort(A, start, piv_pos - 1); 

        quick_sort(A, piv_pos + 1, end);   

    }
}



ll MAX1;
void counting_sort(int A[], int Aux[], int Out[], int n)
{
    

    for (int i = 0; i <= MAX1; i++)
        Aux[i] = 0;

    
    for (int j = 0; j < n; j++)
        Aux[A[j]]++;

    
    for (int i = 1; i <= MAX1; i++)
        Aux[i] = Aux[i] + Aux[i - 1];
    

    for (int j = n - 1; j >= 0; j--)
    {
        Out[Aux[A[j]] - 1] = A[j];
        Aux[A[j]] = Aux[A[j]] - 1;
    }
}


vector <long long> prime; 
bool sieve[1000000];

void primeseive(int n){
    sieve[0] = sieve[1] = 1;

    

    prime.push_back(2);

    

    for(long long i = 4; i<=n; i+=2){
        sieve[i] = 1;
    }

    long long sqrtn = sqrt(n);
    
    

    

    for(long long i = 3; i<= sqrtn; i+=2){
        if(sieve[i] == 0){
            for(long long j = i*i; j<=n; j+=2*i){
                sieve[j] = 1;
            }
        }
    }

    

    for(long long i = 3; i<=n ; i+=2){
        if(sieve[i] == 0) prime.push_back(i);
    }
}





vector <long long> primeFactors;

void primeFactorize(long long n){
    long long sqrtn = sqrt(n);

    for(long long i = 0; i<prime.size() && prime[i] <= sqrtn; i++){
        if(sieve[n] == 0) break;
        if(n % prime[i] == 0){
            while(n % prime[i] == 0){
                n /= prime[i];
                primeFactors.push_back(prime[i]);
            }
            sqrtn = sqrt(n);
        }
    }
    if(n!=1) primeFactors.push_back(n);
}



long long gcd(long long n1, long long n2){
    while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    return n1;
}



long long LCM(long long n1, long long n2){
    long long max = (n1 > n2) ? n1 : n2;
    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            return max;
        }
        else
            ++max;
    } while (true);
}

int arr[1001];



void BFS(ll source, vector < ll > adj[]){
    queue < ll > q;
    ll isVisited[100000] = {0};
    ll parents[100000] = {0};

    ll s = source;
    ll level = 1;

    isVisited[s] = 1;
    q.push(adj[s][0]);
    while (!q.empty())
    {
        s = q.front();
       if(s == 0){
           

           q.pop();
           continue;
       }
       if(s!=0){
           arr[s]++;
       }

        q.pop();
        for(auto it = adj[s].begin(); it!=adj[s].end(); ++it){
            if(!isVisited[*it]){
                isVisited[*it] = 1;
                q.push(*it);
            }
        }

        q.push(0);    
    }
    
}


int reversenum(int n){
    int reverse = 0, rem = 0;
    while(n!=0)    
  {    
     rem=n%10;      
     reverse=reverse*10+rem;    
     n/=10;    
  }
  return reverse;
}



int euphi(int n){
    int res = n; 
    int sqrtn = sqrt(n);
    for(int i = 0; i<prime.size() && prime[i] <= sqrtn; i++){
        if(n % prime[i] == 0){
            while(n % prime[i] == 0)
            {
                n/=prime[i];
            }
            sqrtn = sqrt(n);
            res /= prime[i];
            res *= prime[i] - 1;
        }
    }
}

int lps(string str) 
{ 
   int n = str.size(); 
   int i, j, cl; 
   int L[n][n];  
  
   for (i = 0; i < n; i++) 
      L[i][i] = 1; 
  
   
    for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (str[i] == str[j] && cl == 2) 
               L[i][j] = 2; 
            else if (str[i] == str[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
  
    return L[0][n-1]; 
}








main(){
    fast;

    ll n; cin >> n;

    string gols[n+1];
    string a ="", b = "";
    
    for (size_t i = 0; i < n; i++)
    {
        string x; cin >> x;
        gols[i] = x;
        if(gols[i] != a && a == "") a = gols[i];
        else if(b == "" && gols[i] != a && gols[i] != b)b = gols[i];
    }
    
    int ac, bc;
    ac = bc = 0;

    for (size_t i = 0; i < n; i++)
    {
        if(gols[i] == a) ac++;
        else bc++;
    }

    if(ac > bc) cout << a;
    else cout << b;
    
    
    
    rtz;
}