








using namespace std;
const int inf = 1e9;





















































































































































































































































































































































































































































































































































































































































































































































































































bool id0(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'y')
        return true;
    else
        return false;
}
















































































































ll sumDigits(ll n)
{
    ll rem = 0;
    while (n)
    {
        rem += n % 10;
        n /= 10;
    }
    return rem;
}
bool sortedA(vector<int> arr,int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}
bool sortedD(vector<int> arr,int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            return false;
    return true;
}































































































































































































bool id2(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.second < b.second);
}
ll mod_mul(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll getFact(ll n){
    if(n==0 or n==1){
        return 1;
    }
    ll f=1;
    for(ll i=1;i<=n;i++){
        f*=i;
    }
    return f;
}
ll getNumber(ll n){
    ll sum=1;
    while(n>0){
        ll v = getFact(n%10);
        sum*=getFact(n%10);
        n/=10;
    }
    
    return sum;
}
vector<int> factors;
void primeFactors(ll n)
{
   
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n = n/2;
    }
 
    
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        
        while (n % i == 0)
        {
            factors.push_back(i);
            n = n/i;
        }
    }
 
    
    if (n > 2)
        factors.push_back(n);
}
string ch[10]={"","","2","3","223","5","53","7","7222","7332"};




string rev(string s,ll l, ll r){
    while(l<r){
        swap(s[l],s[r]);
        l++;
        r--;
    }
    return s;

}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v) {
        cout << "\n"<< v;
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}
bool id1(string expr)
{  
    stack<char> s;
    char x;
  
    

    for (int i = 0; i < expr.length(); i++) 
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{') 
        {
            

            s.push(expr[i]);
            continue;
        }
  
        

        

        

        if (s.empty())
            return false;
  
        switch (expr[i]) {
        case ')':
              
            

            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
  
        case '}':
  
            

            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
  
        case ']':
  
            

            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
  
    

    return (s.empty());
}
int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        cout << s << nl;
    }

    return 0;   

}