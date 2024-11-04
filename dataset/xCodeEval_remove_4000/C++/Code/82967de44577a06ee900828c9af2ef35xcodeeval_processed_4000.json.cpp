




























using namespace std;

typedef long long ll;
typedef long double ld;

bool binarySearch(ll arr[],ll _start, ll _end)
{
    

    if(_start>=_end)
        return true;

    ll mid=(_start+_end)/2;
    if(arr[mid]<arr[_start] || arr[mid]>arr[_end])
        return false;
    else
    {
        bool W1=binarySearch(arr, _start+1,_end);
        bool W2=binarySearch(arr, _start,_end-1);
        return (W1 && W2);
    }

}

int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
        return n;

    int temp[n];
    int j = 0;
    for (int i=0; i<n-1; i++)
        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];

    temp[j++] = arr[n-1];
    for (int i=0; i<j; i++)
        arr[i] = temp[i];

    return j;
}

ll id6(ll n)
{
    ll counter = 0;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                counter++;
            else
                counter = counter + 2;
        }
    }
    return counter;
}
long long factorial(long long n)
{
    long long res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
bitset<500001> Primes;
int id12(int n)
{
    Primes[0] = 1;
    for (int i = 3; i <= n; i += 2)
    {
        if (Primes[i / 2] == 0)
        {
            for (int j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}

long double id18(ll n)
{
    ll counter=0;
    while (n % 2 == 0)
    {
        counter++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            counter++;
            n = n/i;
        }
    }
    if (n > 2)
        counter++;
    return counter;
}

int* primeFactors(int n)
{
    int* arr = new int[n];
    int counter=0;
    while (n % 2 == 0)
    {
        arr[counter] = 2;
        counter++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            arr[counter] = i;
            counter++;
            n = n/i;
        }
    }
    if (n > 2)
        arr[counter] = n;
    return arr;
}

bool isPrime(ll n)
{
    bool isPrime=true;
    if (n == 0 || n == 1)
    {
        isPrime = false;
    }
    else
    {
        for (int i = 2; i <= ((1ll)*n) / 2; ++i)
        {
            if (n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}

int* id4(int n)
{
    int* arr = new int[n];
    for (int i=0; i<n; i++)
    {
        arr[i] = i*i;
    }
    return arr;
}

string delete_index(string s, char c, int idx)
{
    int nth = 0;
    for (int i = 0 ; s.size(); i++)
    {
        if (c == s[i])
            nth++;
        if (nth == idx)
            return s.substr(0, i) + s.substr(i+1, s.size());
    }
    return "";
}
int id14(int n, int sum, char* out,
                       int index)
{
    

    if (index > n || sum < 0)
        return 0;

    

    if (index == n)
    {
        

        

        if(sum == 0)
        {
            out[index] = '\0';
            cout << out << " ";
        }
        return 0;
    }

    

    

    for (int i = 0; i <= 9; i++)
    {
        out[index] = i + '0';
        id14(n, sum - i, out, index + 1);
    }
}
int id1(int n, int sum)
{
    

    char out[n + 1];

    

    

    for (int i = 1; i <= 9; i++)
    {
        out[0] = i + '0';
        id14(n, sum - i, out, 1);
    }
}
ll digits(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        ll x=n%10;
        n = n / 10;
        sum+=x;
    }
    return sum;
}

void remove(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it)
    {
        end = std::remove(it + 1, end, *it);
    }
    v.erase(end, v.end());
}

void printSet(set<ll> myset)
{
    cout<<"My Set ";
    for (auto it = myset.begin(); it != myset.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
}

void printStack(stack<ll> s)
{
    cout<<"My Stack ";
    while(!s.empty())
    {
        cout<< s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

stack<ll> sortFunction(stack<ll> &mainStack)
{
    stack<ll> AuxStack;
    while (!mainStack.empty())
    {
        ll temp = mainStack.top();
        mainStack.pop();
        while (!AuxStack.empty() && AuxStack.top() > temp)
        {
            mainStack.push(AuxStack.top());
            AuxStack.pop();
        }
        AuxStack.push(temp);
    }
    return AuxStack;
}

void showVec(vector<char> v)
{
    for(int i=0; i<v.size(); i++)
        cout<<v[i];
    cout<<endl;
}

int GetMedian(multiset<int>& data)
{
    const size_t n = data.size();
    int median = 0;

    auto iter = data.cbegin();
    advance(iter, n / 2);

    

    if (n % 2 == 0)
    {
        const auto iter2 = iter--;
        median = (*iter + *iter2) / 2;    

    }
    else
    {
        median = *iter;
    }

    return median;
}


ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}


int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
ll id16(ll n)
{
    ll counter=0;
    for(int i=1; i<=n; i++)
    {
        if(isPrime(i))
            counter++;
    }
    return counter;
}


bool id21(char ch)
{
    bool id21 = false;
    if(ch=='a'|| ch=='e'||ch=='i'||ch=='o'||ch=='u' ||ch=='U'||ch=='A'||ch=='E'||ch=='I'||ch=='O')
        id21=true;
    return id21;
}
ll getIndex(vector<ll> v, ll K)
{
    auto it = find(v.begin(), v.end(), K);

    if (it != v.end())
    {
        ll index = it - v.begin();

        return index;
    }

}

ll id13(ll num)
{
    ll sum=0;
    while(num>0)
    {
        ll x=num%10;
        sum+=x;
        num/=10;
    }
    return sum;
}
vector<ll> slicing(vector<ll>& arr,int X, int Y)
{

    

    auto start = arr.begin() + X;
    auto endd = arr.begin() + Y + 1;

    

    vector<ll> result(Y - X + 1);

    

    copy(start, endd, result.begin());

    arr.erase(start, endd);
    

    return result;
}
void printResult(vector<ll>& ans)
{
    for (auto it=ans.begin(); it!=ans.end(); it++)
    {
        cout<<*it<<' ';
    }
}
string removeDuplicates(string str)
{
    

    int index = 0;

    

    for (int i=0; i<str.size(); i++)
    {

        

        int j;
        for (j=0; j<i; j++)
            if (str[i] == str[j])
                break;

        if (j == i)
            str[index++] = str[i];
    }

    return str;
}






int Print(int a,int b)
{
    if(b==0)
        return a;

    return (b,a%b);
}
void mergeTwo(ll arr[],int start,int mid,int endd)
{
    int id9=mid-start+1, id19=endd-mid;
    ll left[id9],right[id19];

    for(int i=0; i<id9; i++)
        left[i]=arr[start+i];

    for(int i=0; i<id19; i++)
        right[i]=arr[mid+1+i];

    int i=start,j=0;
}
int LcM(int a,int b)
{
    return ((a*b)/Print(a,b));
}
void loop(int arr[],int endd)
{
    for(int i=0; i<endd; i++)
        cin>>arr[i];
}

void id22(int q,int& x,int& y)
{
    int next=x-y*q;
    x=y;
    y=next;
}
const long int a = 1000000000;
long long int fac1 = 1,fac2=1,fac;
long long int ncr(int n,int r)
{
    for(int i=r; i>=1; i--,n--)
    {
        fac1 = fac1 * n;
        if(fac1%i==0)
            fac1 = fac1/i;
        else
            fac2 = fac2 * i;
    }
    fac = fac1/fac2;
    return fac%a;
}

ll mod=1e9+7;
ll fastpower(ll base,ll power,ll modulo=1000000007)
{
    

    if(power==1)
        return base;

    ll half=fastpower(base,power/2,modulo);

    ll res = ( (half%modulo) * (half%modulo) )%modulo;
    if(power % 2 != 0)
        res=(res*(base%modulo))%modulo;

    return res%modulo;
}

ll nCr(ll n,ll r)
{
    

    if(r==0 || n==0)
    {
        fac=fac1/fac2;
        return fac%a;
    }

    fac1 = fac1 * n;
    if(fac1%r==0)
        fac1 = fac1/r;
    else
        fac2 = fac2 * r;

    return nCr(n-1,r-1);
}

ll id10(int n,int r)
{
    return 1ll*factorial(n)*fastpower((factorial(r)) % mod,mod-2,mod) % mod;
}
ll id11(ll n,ll modulo)
{
    return (fastpower(n,modulo-2,modulo)+modulo)%modulo;
}
string addBinary(string A, string B)
{
    

    

    

    

    

    if (A.length() > B.length())
        return addBinary(B, A);

    

    

    int diff = B.length() - A.length();

    

    

    

    string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');

    A = padding + A;
    string res;
    char carry = '0';

    for (int i = A.length() - 1; i >= 0; i--)
    {
        

        if (A[i] == '1' && B[i] == '1')
        {
            if (carry == '1')
                res.push_back('1'), carry = '1';
            else
                res.push_back('0'), carry = '1';
        }
        

        else if (A[i] == '0' && B[i] == '0')
        {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        }
        

        

        else if (A[i] != B[i])
        {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }

    

    

    if (carry == '1')
        res.push_back(carry);
    

    reverse(res.begin(), res.end());

    

    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
        index++;
    return (res.substr(index));
}

bool isreal(ll arr[],ll n,ll tar,int idx, ll sum)
{
    

    if(idx==n)
        return tar==sum;

    bool w1 = isreal(arr,n,tar,idx+1,sum+arr[idx]);
    bool w2 = isreal(arr,n,tar,idx+1,sum-arr[idx]);
    bool w3 = isreal(arr,n,tar,idx+1,sum/arr[idx]);
    bool w4 = isreal(arr,n,tar,idx+1,sum*arr[idx]);

    return w1||w2||w3||w4;
}

ll id3(int x,int moves,int dis)
{
    

    if(moves==0)
        return abs(x);

    ll w1=id3(x+dis,moves-1,dis);
    ll w2=id3(x-dis,moves-1,dis);

    return min(abs(w1),abs(w2));
}
ll id7(deque<ll> dq)
{
    deque<ll>dq2=dq;
    ll maxi=dq2.front();
    dq2.pop_front();

    while(!dq2.empty())
    {
        ll a=dq2.front();

        if(maxi<a)
            maxi=a;
        dq2.pop_front();
    }
    return maxi;
}
void id0()

{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string>stac;
    map<string, int>mp;
    for(int i=0; i<s.size()-1; i++)
    {
        string tmp="";
        tmp+=s[i];
        tmp+=s[i+1];
        stac.push_back(tmp);
    }
    for(int i=0; i<stac.size(); i++)
    {
        mp[stac[i]]++;
    }
    auto pr = std::max_element(mp.begin(), mp.end(), [](const auto &x, const auto &y)
    {
        return x.second < y.second;
    });

    cout << pr->first;
}
void swapp(int *n,int *m)
{
    int tmp =*n;
    *n =*m;
    *m=tmp;
}
string id20(string s)
{

    int n = s.length();
    string str="";
    if (n == 0)
        return str;

    for(int i=0; i<n-1; i++)
    {
        if(s[i]!=s[i+1])
        {
            str+=s[i];
        }
    }

    str.push_back(s[n-1]);
    return str;
}
string freq(string &a,int n)
{
    string tmp=a;
    for(int i=1; i<=n; i++)
        a+=tmp;

    return a;
}

ll arr[200001];
bool isthree(int n,int idx,ll sum,int cnt)
{
    if(sum%10==3 && cnt==3)
        return true;
    if(idx==n)
        return false;

    bool W1=isthree(n,idx+1,sum+arr[idx],cnt+1);
    bool W2=isthree(n,idx+1,sum,cnt);

    return (W1||W2);
}
ll seg[200005];

int index(int l,int r,int x)
{
    

    if(l==r)
        return -1;

    int mid=(l+r)/2;

    if(seg[mid]!=x)
        return mid+1;

    index( mid+1,r, x);
    index( l,mid-1, x);
}
void printbinary(int num)
{
    if(num<1)
    {
        cout<<num;
        return;
    }

    printbinary(num>>1);
    cout<<(num&1);
}
int id5(int num,int cnt=0)
{
    if(num<=0)
        return cnt;

    return id5((num&(num-1)),cnt+1);
}
int id2(int n)
{
    return n& ~(n-1);
}

int getbit(int n,int idx)
{
    return (n>>idx)&1;
}

void id8(char& n,int idx)
{
    n|=(1<<idx);
}
int id15(int n,int idx)
{
    return n ^ (1<<idx);
}
ll mask(ll first,ll arr[],int n,int idx,ll y)
{
    

    if(idx==n && first==y)
        return first;
    else if(idx==n && first!=y)
        return 0;

    ll W1=mask(first+arr[idx], arr,n, idx+1,y);
    ll W2=mask((first^arr[idx]), arr, n, idx+1,y);

    return (W1 || W2);
}
void id17(set<ll>&s)
{
    ll tp= *s.begin();
    tp+=tp&9;
    s.insert(tp);
}
int product(int a,int b,int x,int y,int n,int mini)
{
    if(n < 0 || a==x && b==y)
        return mini;

    int w1=INT_MAX,w2=INT_MAX;

    if(a-1>=x)
        w1=product(a-1,b,x,y,n-1,a*b);
    if(b-1>=y)
        w2=product(a,b-1,x,y,n-1,a*b);

    return min(w1,w2);
}
ll countDigit(long long n)
{
    if (n == 0)
        return 1;
    int counter = 0;
    while (n != 0)
    {
        n = n / 10;
        ++counter;
    }
    return counter;
}

map<char,int>mp;
string uniqu(string s,int idx)
{
    string tp=s;
    tp.erase(tp.begin() + idx);
    if(tp>=s)
    {
        mp[s[idx]]--;
        return tp;
    }
    else
        return s;
}
bool id12(ll n)
{
    bool prime[n + 1],x = true;
    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {

            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    ll cnt=0;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
            cnt++;
    }

    if(cnt != 3)
        x = false;

    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);


    int t;
    cin>>t;
    string s;
    while(t--)
    {
        int n;
        cin>>n;
        ll arr[n],prod=1,tp=n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<n; i++)
        {
            if(arr[i]%2==0)
            {
                while(arr[i]%2==0)
                {
                    arr[i]/=2;
                    tp--;
                }
            }
        }

        int cnt=0;
        vector<int>v;
        for(int i=n-1; i>=0; i--)
        {
            if(tp>0 && (i+1) % 2 ==0)
            {
                int cnt=0,x=i+1;
                while(x % 2 == 0)
                {
                    x/=2;
                    cnt++;
                }
                v.push_back(cnt);
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0; i<v.size(); i++)
        {
            if(tp>0)
            {
                tp-=v[i];
                cnt++;
            }
        }

        if(tp>0)
            cout<<-1;
        else
            cout<<cnt;

        cout<<Endl;
    }





    
    
    

    
    

    
    

    
    

    
    

    
    

    
    


    

    

    return 0;
}
