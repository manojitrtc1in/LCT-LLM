





















































































using namespace std;




bool id13(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}

bool id9(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.second > b.second);
}





long long id0(long long x){
    int s = 0;
    while (x != 0) {
      s += x % 10;
      x = x / 10;
   }
    return s;
}




int id5(string str){
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



bool id4 (long long x) 
{ 
  
  return x && (!(x&(x-1))); 
}


long long digitNO(long long num){
    double eps = 1e9;
    return floor(log10(num)) + 1 + eps;
}

string id7(long long n){
    string s;
    stringstream ss;
    ss << n;
    s = ss.str();

    return s;
}


long long id12(long long number){
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



void id6(int A[], int n)
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
        

        int id11 = rand_partition(A, start, end);
        quick_sort(A, start, id11 - 1); 

        quick_sort(A, id11 + 1, end);   

    }
}



ll MAX1;
void id3(int A[], int Aux[], int Out[], int n)
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

void id8(int n){
    sieve[0] = sieve[1] = 1;

    

    prime.push_back(2);

    

    for(long long i = 4; i<=n; i+=2){
        sieve[i] = 1;
    }

    long long id10 = sqrt(n);
    
    

    

    for(long long i = 3; i<= id10; i+=2){
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

void id1(long long n){
    long long id10 = sqrt(n);

    for(long long i = 0; i<prime.size() && prime[i] <= id10; i++){
        if(sieve[n] == 0) break;
        if(n % prime[i] == 0){
            while(n % prime[i] == 0){
                n /= prime[i];
                primeFactors.push_back(prime[i]);
            }
            id10 = sqrt(n);
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


int id2(int n){
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
    int id10 = sqrt(n);
    for(int i = 0; i<prime.size() && prime[i] <= id10; i++){
        if(n % prime[i] == 0){
            while(n % prime[i] == 0)
            {
                n/=prime[i];
            }
            id10 = sqrt(n);
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