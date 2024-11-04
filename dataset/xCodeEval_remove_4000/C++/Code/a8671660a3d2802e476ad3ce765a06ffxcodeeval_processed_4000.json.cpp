
















 


 





























 





 
using namespace std;
 
 
void print_width(ll x) {
 
    std::cout << std::fixed;
    std::cout << std::setprecision(x);
}
 
ll power(ll x, ll y, ll p = MOD)
{ 
    ll res = 1;      

 
    x = x % p;  

                

 
    while (y > 0) 
    { 
        

        if (y & 1) 
            res = (res * x) % p; 
 
        

        y = y >> 1; 

        x = (x * x) % p;   
    } 
    return res; 
} 
 
void printArr(ll a[], ll n) {
    f(n)
        cout << a[i] << " ";
    cout << endl;
}
 
void printVector(std::vector<ll> v) {
    f(v.size())
        cout << v[i] << " ";
    cout << endl;
}
 
void id0(std::vector<pair<ll, ll>> v) {
    f(v.size())
        pp2(v[i].first, v[i].second);
    cout << endl;
}
 
ll Min(ll a, ll b, ll c) {
    if (a < b and a < c)
        return a;
    if (b < c)
        return b;
    return c;
}
 
void initialize(ll arr[], ll n) {
    for (ll i = 0; i <= n; i++)
        arr[i] = i;
}
 
ll root(ll arr[], ll i) {
 
    while (arr[i] != i) {
        arr[ i ] = arr[ arr[ i ] ] ; 
        i = arr[i];
    }
    return i;
 
}
 
void Union(ll arr[], ll a, ll b) {
    ll root_a = root(arr, a);
    ll root_b = root(arr, b);
 
    arr[root_a] = root_b;
}
 
 
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else return gcd(b, a % b);
}
 
ll id1(ll x, ll y)
{ 
    ll res = 1;      

 
 
    while (y > 0) 
    { 
        

        if (y & 1) 
            res = (res * x); 
 
        

        y = y >> 1; 

        x = (x * x);   
    } 
    return res; 
} 
 
long double dpower(long double x, ll y) { 
    long double res = 1;      

 
 
    while (y > 0) 
    { 
        

        if (y & 1) 
            res = (res * x); 
 
        

        y = y >> 1; 

        x = (x * x);   
    } 
    return res; 
}
 
std::vector<ll> vsum(std::vector<ll> a) {
 
    std::vector<ll> s(a.size());
    s[0] = a[0];
    flr (i, 1, a.size() - 1) {
        s[i] = s[i - 1] + a[i];
    }
    return s;
}

std::vector<ld> id2(std::vector<ld> a) {
 
    std::vector<ld> s(a.size());
    s[0] = a[0];
    flr (i, 1, a.size() - 1) {
        s[i] = s[i - 1] + a[i];
    }
    return s;
}
 
bool comp( pair<ll, ll> a, pair<ll, ll> b) {
    ll x = a.second * b.first;
    ll y = a.first * b.second;
 
    if (x <= y)
        return false;
    else
        return true;
}
 
bool is_cap(char a) {
 
    if (a <= 'Z' and a >= 'A')
        return true;
    else
        return false;
}
 
bool is_small(char a) {
 
    if (a <= 'z' and a >= 'a')
        return true;
    else
        return false;
}
 
string addition(string str1, string str2) 
{ 
    string str = ""; 
    if (str1.size() > str2.size())  {
        swap(str1, str2); 
    }
 
    int n1 = str1.size(), n2 = str2.size(); 
  
    reverse(all(str1)); 
    reverse(all(str2)); 
  
    int carry;
    carry = 0;
    for (int i = 0; i<n1; i++) { 
        int sum;
        sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.pb(sum%10 + '0'); 
  
        carry = sum / 10; 
    } 
  
    for (int i=n1; i<n2; i++)  { 
        int sum;
        sum = ((str2[i]-'0')+carry); 
        str.pb(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
        str.pb(carry+'0'); 
  
    reverse(all(str)); 
  
    return str; 
} 
 
bool mcomp(ll a, ll b, ll c, ll d) {
 
    if (a == b and b == c and c == d)
        return true;
    else
        return false;
 
}
 

 






 










 






            

















ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
  




ll nCr(ll n, ll r, ll p) 
{ 
   

   if (r==0) 
      return 1; 
  
    

    

    

    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 
 
ll c2(ll n) {
    return (n * (n - 1)) / 2;
}


void time() {
    
    cout << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    
}



string multiply(string num1, string num2) 
{ 
    int n1 = num1.size(); 
    int n2 = num2.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
   
    

    

    vector<int> result(n1 + n2, 0); 
   
    

    

    int id3 = 0;  
    int id4 = 0;  
       
    

    for (int i=n1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
   
        

        

        id4 = 0;  
           
        

        for (int j=n2-1; j>=0; j--) 
        { 
            

            int n2 = num2[j] - '0'; 
   
            

            

            

            int sum = n1*n2 + result[id3 + id4] + carry; 
   
            

            carry = sum/10; 
   
            

            result[id3 + id4] = sum % 10; 
   
            id4++; 
        } 
   
        

        if (carry > 0) 
            result[id3 + id4] += carry; 
   
        

        

        id3++; 
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









  






  





ll sti(string s) {

    ll ans = 0;
    ll p = 1;

    for (ll i = s.size() - 1; i >= 0; i--) {
        ans = (ans + ((ll)(s[i] - '0') * p) % mod) % mod;
        p = (p * 10) % mod;
    }
    return ans;

}



















































int lps(char *seq, int i, int j) 
{ 


if (i == j) 
    return 1; 
  




if (seq[i] == seq[j] && i + 1 == j) 
    return 2; 
  


if (seq[i] == seq[j]) 
    return lps (seq, i+1, j-1) + 2; 
  


return max( lps(seq, i, j-1), lps(seq, i+1, j) ); 
} 

























































bitset<64> left_child(bitset<64> node) {

    f (64) {

        if (node[i] == 1) {

            if (i == 0)
                break;

            node[i] = 0;
            node[i - 1] = 1;
            break;

        }

    }
    return node;

}

bitset<64> right_child(bitset<64> node) {

    f (64) {

        if (node[i] == 1) {

            if (i == 0)
                break;

            node[i - 1] = 1;
            break;

        }

    }
    return node;

}

bitset<64> parent(bitset<64> node, bitset<64> root) {

    if (node == root)
        return node;

    f (64) {

        if (node[i] == 1) {

            


            if (node[i + 1] == 0) {
                node[i + 1] = 1;
                node[i] = 0;
                break;
            }
        
            else if (node.count() > 1) {

                node[i] = 0;
                break;

            }
            break;
        }

    }
    return node;
}

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);

int myrand(int mo) {
    return mt()%mo;
}

int main() {
 
    

    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
 
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 
    

    print_width(15);


    ll n, k;
    cin >> n >> k;

    ll mat[n][n];

    ll p = 1;

    flr (i, 0, n - 1) {
        flr (j, 0, k - 2) {
            mat[i][j] = p;
            p++;
        }
    }

    ll sum = 0;
    flr (i, 0, n - 1) {
        flr (j, k - 1, n - 1) {

            if (j == k - 1)
                sum += p;

            mat[i][j] = p;
            p++;
        }
    }

    pp1(sum);
    flr (i, 0, n - 1) {
        flr (j, 0, n - 1) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    

    return 0;
}