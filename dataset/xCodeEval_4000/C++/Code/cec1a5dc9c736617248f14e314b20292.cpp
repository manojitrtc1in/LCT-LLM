#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef uint64_t bu; 
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpl;
typedef vector<string> vs;
typedef vector<char> vc;
#define vb vector<bool>
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define LB lower_bound
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repr(i, a, b) for (ll i = a; i > b; i--)
#define rept(type, i, a, op, b, change) for (type i = a; i op b; i += change) 

#define repi(var,start,end,interval) for(ll var=start;(interval>0 and var<end) or (interval<0 and var>end);var+=interval)
#define cy cout << "YES"<<endl 
#define cn cout<<"NO"<<endl
#define F first
#define S second
#define PI 3.14159265358979323846
#define W(i,n) while(i<n)
#define Sort(v) sort(begin(v),end(v))
#define M 998244353
#define MAXN 10000001
#define MOD 1000000007
#define elif else if
#define INF 1e12+1


bool is_Smaller_str(string str1, string str2) 
{ 
	

	ll n1 = str1.length(), n2 = str2.length(); 

	if (n1 < n2) 
	return true; 
	if (n2 < n1) 
	return false; 

	for (int i=0; i<n1; i++) 
	if (str1[i] < str2[i]) 
		return true; 
	else if (str1[i] > str2[i]) 
		return false; 

	return false; 
}
ll mod(ll a,ll b)
{
    ll ans = a/b;
    ans*=b;
    ans = a-ans;
    return ans;
}


string find_Diff_str(string str1, string str2) 
{ 
	

	

	if (is_Smaller_str(str1, str2)) 
		swap(str1, str2); 

	

	string str = ""; 

	

	ll n1 = str1.length(), n2 = str2.length(); 

	

	reverse(str1.begin(), str1.end()); 
	reverse(str2.begin(), str2.end()); 
	
	ll carry = 0; 

	

	

	for (ll i=0; i<n2; i++) 
	{ 
		

		

		
		ll sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
		
		

		

		

		if (sub < 0) 
		{ 
			sub = sub + 10; 
			carry = 1; 
		} 
		else
			carry = 0; 

		str.push_back(sub + '0'); 
	} 

	

	for (ll i=n2; i<n1; i++) 
	{ 
		ll sub = ((str1[i]-'0') - carry); 
		
		

		if (sub < 0) 
		{ 
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
string find_sum_str(string str1, string str2) 
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

void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll Rselect(vector<ll> v, ll i, ll l, ll r); 

ll partition(vector<ll> v, ll l, ll r);
void scanc(vc& v,ll n)
{
    rep(i,0,n)
    {
        char num;
        cin>>num;
        v.pub(num);
    }
}
void scanP(vpl& v,ll n)
{
    rep(i,0,n)
    {
        ll num1,num2;
        cin>>num1>>num2;
        pair<ll,ll> p = {num1,num2};
        v.pub(p);
    }
}
template<typename T>
ostream& operator<<(ostream& stream, const vector<T>& vec) 

{
	for (auto& i : vec)
	{
		stream << i << ' ';
	}
	stream << '\n';
	return stream;
}

template<class T>
istream& operator>>(istream& stream, vector<T>& vec) 

{
	for (auto& i : vec)
	{
		stream >> i;
	}
	return stream;
}

void solve();


  
void scanN(vector<ll>&v,ll n)
{
    rep(i,0,n)
    {
        int num;
        cin>>num;
        v.pub(num);
    }
}
void scans(vector<string>& v,ll n)
{
    rep(i,0,n)
    {
        string s;
        cin>>s;
        v.pub(s);
    }
}

ll modfactorial(ll n,ll p)
{
    if(n>=p)
    return 0;
    ll result = 1;
    rep(i,1,n+1)
    {
        result = result*i;
        result = result%p;
    }
    return result;
}
ll MI(ll a, ll b,ll s0 = 1,ll s1 = 0)
{
    ll k = b;
    if(b == 0)
    return s0;
    else
    {
       return  MI(b,a%b,s1,s0-s1*(a/b));

    }
}
ll choose(ll a,ll b,ll c = MOD)
{
    if(a<b)
    return 0;
    ll x = modfactorial(a,c);
    ll y = modfactorial(b,c);
    ll z = modfactorial(a-b,c);
    ll y_ = MI(y,c,1,0);
    if(y_<0)
    y_ = y_+c;
    ll z_ = MI(z,c,1,0);
    if(z_<0)
    z_ = z_+c;
    ll mul = (x*y_)%c;
    mul = (mul*z_)%c;
    return mul;
}
void SOLT()
{
    int test;
    cin>>test;
    while(test--)
    {
        solve();
    }
}
ll modpow(ll n,ll p,ll k)
{
    n = n%k;
    ll res = 1;
    while(p>0)
    {
        if(p%2 == 1)
        res = res*n%k;
        n = n*n%k;
        p = p/2;
    }
    return res;
}
ll str_mod_num(string b,ll c)
{
    ll k = b.size();
    vll mod(k+1);
    mod[0] = 1;
    

    rep(i,1,k+1)
    {
        mod[i] = 10*mod[i-1];
        mod[i]%=c;
    }
    ll rem = 0;
    repr(i,k-1,-1)
    {
        ll num = b[i] - '0';
        num*=mod[k-1-i];
        num%=c;
        rem+=num;
        rem%=c;
    }
    return rem;
}
ll str_pow_str_mod_num(string b,string n,ll c)
{
    ll tr = n.size();
    ll rem = str_mod_num(b,c);
    ll time_pass = n[0] - '0';
    ll ans = modpow(rem,time_pass,c);
    rep(i,1,tr)
    {
         time_pass = n[i] - '0';
        ans = modpow(ans,10,c);
        ans*=modpow(rem,time_pass,c);
        ans%=c;
    }
    return ans;
}
bool isPrime(ll a) {
	for(ll i = 2; i * i <= a; ++i)
		if(a % i == 0)
			return false;
	return true;
}

bool useflushdivisible(ll a) {
	cout<<a<<endl;
	fflush(stdout);
	char sl[10];
	scanf("%s", sl);
	return sl[0] == 'y' || sl[0] == 'Y';
}
ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n =n/ i;
            result =result - result / i;
        }
    }
    if (n > 1)
        result =result - result / n;
    return result;
}
bool cmp(pair<ll,ll> x,pair<ll,ll> y)
{
    return x.F<y.F;
}
vll getfactors(ll n)
{
    vll factors;
    rep(i,1,sqrt(n)+1)
    {
        if(n%i == 0)
        {
            factors.pub(i);
            if(i!=(n/i))
            factors.pub(n/i);
        }
    }
    return factors;
}
ll Binary_Search(vector<ll>& a,ll low,ll high,ll key)
{
    if(high<low)
        return a[low-1];
    int mid  = (high+low)/2;
    if(key == a[mid])
        return a[mid];
    else if(key<a[mid])
        return Binary_Search(a,low,mid-1,key);
    return Binary_Search(a,mid+1,high,key);
}
class bigint
{
public:
    bigint()
    {
        x = "";
    }
    ll Length() const {
        return x.size();
    }
    char Char_i(ll i) const {
        ll n = x.size();
        if(i>=n)
        {
            throw invalid_argument("Invalid argument");
        }
        else
        {
            return x[i];
        }
    }
    void Push_back(char s)&
    {
        if(s - '0'<0||s-'0'>9)
            throw invalid_argument("Invalid argument");
        else
            x.push_back(s);
    }
    void Reverse()&
    {
        reverse(begin(x),end(x));
    }
    void Clear()&
    {
        x.clear();
    }
    char& operator [](ll i)
    {
        if(i>=x.size())
            throw invalid_argument("Invalid argument");
        return x[i];

    }
    void operator = (string str2)
    {
        x = str2;
    }
    string x;
};
void swap(bigint& x,bigint& y)
{
    bigint TEMP;
    for(ll i = 0;i<x.Length();i++)
    {
        TEMP.Push_back(x[i]);
    }
    x.Clear();
    for(ll i = 0;i<y.Length();i++)
    {
        x.Push_back(y[i]);
    }
    y.Clear();
    for(ll i =0;i<TEMP.Length();i++)
    {
        y.Push_back(TEMP[i]);
    }
    TEMP.Clear();

}
istream& operator >>(istream& stream,bigint& num)
{
    stream >>num.x;
    return stream;
}
ostream& operator <<(ostream& stream,bigint x)
{
    ll n = x.Length();
    for(int i = 0;i<n;i++)
        stream<<x[i];
        return stream;
}

bool operator < (bigint& str1,bigint& str2)
{
    ll n1 = str1.Length(), n2 = str2.Length();

	if (n1 < n2)
	return true;
	if (n2 < n1)
	return false;

	for (int i=0; i<n1; i++)
	if (str1.Char_i(i) < str2.Char_i(i))
		return true;
	else if (str1.Char_i(i)> str2.Char_i(i))
		return false;

	return false;
}
bool operator == (bigint& str1,bigint& str2)
{
    ll n1 = str1.Length();
    ll n2 = str2.Length();
    if (n1 < n2)
	return false;
	if (n2 < n1)
	return false;
	for (ll i=0; i<n1; i++)
	if (str1[i] != str2[i])
		return false;
    return true;

}
bool operator != (bigint& str1,bigint& str2)
{
    if(str1 == str2)
        return false;
    return true;
}
bool operator > (bigint& str1,bigint& str2)
{
    if(str1<str2)
        return false;
    if(str1 == str2)
        return false;
    return true;
}
bool operator <= (bigint& str1,bigint& str2)
{
    if(str1<str2||str1 == str2)
    {
        return true;
    }
    return false;
}
bool operator >= (bigint& str1,bigint& str2)
{
    if(str1>str2||str1 == str2)
        return true;
    return false;
}
bigint operator - (bigint str1,bigint str2)
{
    	

	

	if (str1<str2)
		swap(str1, str2);

	

	 bigint str;

	

	ll n1 = str1.Length(), n2 = str2.Length();

	

	str1.Reverse();
	str2.Reverse();

	ll carry = 0;

	

	

	for (ll i=0; i<n2; i++)
	{
		

		


		ll sub = ((str1[i]-'0')-(str2[i]-'0')-carry);

		

		

		

		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.Push_back(sub + '0');
	}

	

	for (ll i=n2; i<n1; i++)
	{
		ll sub = ((str1[i]-'0') - carry);

		

		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.Push_back(sub + '0');
	}

	

	str.Reverse();

	return str;
}
bigint operator + (bigint str1,bigint str2)
{
        

    

    if (str1.Length() > str2.Length())
        swap(str1, str2);

    

    bigint str;

    

    int n1 = str1.Length(), n2 = str2.Length();

    

    str1.Reverse();
    str2.Reverse();

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        

        

        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.Push_back(sum%10 + '0');

        

        carry = sum/10;
    }

    

    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.Push_back(sum%10 + '0');
        carry = sum/10;
    }

    

    if (carry)
        str.Push_back(carry+'0');

    

    str.Reverse();

    return str;
}
ll operator % (bigint b,ll c)
{
    ll k = b.Length();
    vector<ll> mod(k+1);
    mod[0] = 1;
    

    rep(i,1,k+1)
    {
        mod[i] = 10*mod[i-1];
        mod[i]%=c;
    }
    ll rem = 0;
    repr(i,k-1,-1)
    {
        ll num = b[i] - '0';
        num*=mod[k-1-i];
        num%=c;
        rem+=num;
        rem%=c;
    }
    return rem;
}
ll c = INF;
ll operator ^ (bigint b,bigint n) 

{
    ll tr = n.Length();
    ll rem = b%c;
    ll time_pass = n[0] - '0';
    ll ans = modpow(rem,time_pass,c);
    rep(i,1,tr)
    {
         time_pass = n[i] - '0';
        ans = modpow(ans,10,c);
        ans*=modpow(rem,time_pass,c);
        ans%=c;
    }
    return ans;
}
bigint operator * (bigint num1,bigint num2) 

{
    int len1 = num1.Length();
    int len2 = num2.Length();
    bigint zero;
        zero = "0";
    if (len1 == 0 || len2 == 0)
    {

    return zero;
    }

    

    

    vector<ll> result(len1 + len2, 0);

    

    

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
    return zero;

    

    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);
    bigint b;
    b = s;

    return b;
}
bigint operator / (bigint number,ll divisor) 

{
    

    bigint ans;
    bigint zero;
    zero = "0";
    

    

    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    

    

    

    while (number.Length() > idx) {
        

        

        ll c = temp/divisor;
          ans.Push_back(c+'0');
        

        if(idx!=number.Length()-1)
        temp = (temp % divisor) * 10 + number[++idx] - '0';
        else
            break;
    }

    

    if (ans.Length() == 0)
        return zero;

    

    return ans;
}
int main()
{
    FAST();
   srand(time(0));
 

 int test = 1;


 for(int tt = 1;tt<=test;tt++)
 solve();
	return 0;
}


void solve()
{
    bigint b,n;
  

    cin>>b>>n>>c;
    ll ans1 = b^n;
    bigint n1;
    bigint one;
    one = "1";
    n1 = n-one;
    ll ans2 = b^n1;
    ll ans = ans1-ans2;
    if(ans<=0)
    ans+=c;
    cout<<ans;
}





ll Rselect(vector<ll> v, ll i, ll l, ll r)
{
	if (l == r)
		return v[l];
	ll pivot = partition(v, l, r);
	if (pivot == i)
		return v[pivot - 1];
	else if (pivot < i)
	{
		return Rselect(v, i, pivot, r);
	}
	else
	{
		return Rselect(v, i, l, pivot - 2);
	}
}

ll partition(vector<ll> v, ll l, ll r)
{
	ll pivot_index = rand() % (r - l + 1) + l;
	swap(v[pivot_index], v[l]);
	ll i = l + 1, j = l + 1;
	while (j <= r)
	{
		if (v[j] < v[l])
		{
			swap(v[j], v[i]);
			i++;
		}
		j++;
	}
	swap(v[l], v[i - 1]);
	return i;
}