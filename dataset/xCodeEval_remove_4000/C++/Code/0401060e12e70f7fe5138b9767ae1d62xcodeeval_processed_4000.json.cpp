
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



























bool id8(string str1, string str2) 
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


string id4(string str1, string str2) 
{ 
	

	

	if (id8(str1, str2)) 
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
string id2(string str1, string str2) 
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

ll id3(ll n,ll p)
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
    ll x = id3(a,c);
    ll y = id3(b,c);
    ll z = id3(a-b,c);
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
ll id6(string b,ll c)
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
ll id7(string b,string n,ll c)
{
    ll tr = n.size();
    ll rem = id6(b,c);
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

bool id1(ll a) {
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
vll id0(ll n)
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
        str = "";
    }
    bigint(const string& x)
    {
        str = x;
    }
    bigint(const char* x)
    {
        str = x;
    }
    ll Length() const {
        return str.size();
    }
    void Push_back(char s)
    {
       if((s - '0'<0||s-'0'>9)&&s!='-')
            throw invalid_argument("Invalid argument");
        else
            str.push_back(s);
    }
    void Reverse()
    {
        reverse(begin(str),end(str));
    }
    void Clear()
    {
        str.clear();
    }
    char& operator [](ll i)
    {
        if(i>=str.size())
            throw invalid_argument("Invalid argument");
        return str[i];

    }
    void operator=(const char* x)
    {
        str = x;
    }
    void operator=(string x)
    {
        str = x;
    }
    ll bigint_to_int()

    {
        reverse(begin(str),end(str));
        ll ind = str.size();
        repr(i,str.size()-1,-1)
        {
            if(str[i]!='0'&&str[i]!='-')
            {
                ind = i+1;
                break;
            }
        }
        ll ans = 0;
        for(ll i = 0;i<ind;i++)
        {
            ans+=((str[i] - '0')*(pow(10,i)));
        }
        if(str[str.size()-1] == '-')
            ans = -ans;
        return ans;
    }
    void Clip()
    {
        ll ind = -1;
        ll t = -1;
        if(str[0] == '-')
            t = 1;
        else
            t = 0;
        for(ll i = t;i<str.size();i++)
        {
            if(str[i]!='0')
            {
                ind = i;
                break;
            }
        }
        if(ind == -1)
            str = "0";
        else
        {
            string p = str;
            bool nag = false;
            if(str[0] == '-')
                nag = true;
            str.clear();
            if(nag)
                str.push_back('-');
            for(ll i = ind;i<p.size();i++)
                str.push_back(p[i]);
        }

    }
    void Abs()
    {
        string p;
       
         if(str[0] == '-')
        {
            for(ll i = 1;i<str.size();i++)
            {
                p.push_back(str[i]);
            }
            str = p;
        }
        else
        {
            for(ll i = 0;i<str.size();i++)
                p.push_back(str[i]);
            str = p;
        }

    }
    void Neg()
    {
        string p;
       
         if(str[0] == '-')
        {
            for(ll i = 1;i<str.size();i++)
            {
                p.push_back(str[i]);
            }
            str = p;
        }
        else if(str[0]!='-')
        {

            p.push_back('-');
            bool ind = false;
            for(ll i = 0;i<str.size();i++)
            {
                if(ind)
                p.push_back(str[i]);
                if(!ind&&str[i]!='0')
                {
                    ind = true;
                    p.push_back(str[i]);
                }
            }
            if(p.size()!=1)
            str = p;
            else
                str = "0";
        }
    }
    string str;
};
bigint operator - (bigint str1,bigint str2);
bigint operator + (bigint str1,bigint str2);
bigint operator * (bigint num1,bigint num2);
bigint operator / (bigint number,ll divisor);
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
    stream >>num.str;
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
    str1.Clip();
    str2.Clip();
    ll n1 = str1.Length(), n2 = str2.Length();
    if(str1[0] == '-'&&str2[0]!='-')
        return true;
    if(str1[0] != '-'&&str2[0] == '-')
        return false;
    if(str1[0] == '-'&&str2[0] == '-')
    {
        str1.Abs();
        str2.Abs();
        return str2<str1;
    }
	if (n1 < n2)
	return true;
	if (n2 < n1)
	return false;

	for (int i=0; i<n1; i++)
	if (str1[i] < str2[i])
		return true;
	else if (str1[i]> str2[i])
		return false;

	return false;
}
bool operator == (bigint& str1,bigint& str2)
{
    str1.Clip();
    str2.Clip();
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
    	

	

	bigint s1 = str1,s2 = str2;
	s1.Abs();
	s2.Abs();
	bool swapped = false;
	if (s1<s2)
    {
		swap(str1, str2);
		swapped = true;
    }
    bigint zero = "0";
    if(str1<zero&&str2<zero)
    {
        str1.Abs();
        str2.Abs();
        bigint str = str2 - str1;
        str.Clip();
        if(!swapped)
        {
            str.Neg();
            return str;
        }
        else
        {
            

            return str;
        }
    }
    else if(str2<zero)
    {
        str2.Abs();
        bigint str = str1+str2;
        str.Clip();
        if(!swapped)
            return str;
        else
        {
            str.Neg();
            return str;
        }
    }
    else if(str1<zero)
    {
        str1.Abs();
        bigint str = str1+str2;
        if(!swapped)
        {
            str.Neg();
            return str;
        }
        else
        {
            return str;
        }
    }
	

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
    str.Clip();
    if(swapped)
    str.Neg();
	return str;
}
bigint operator + (bigint str1,bigint str2)
{
        

    

    bigint s1 = str1;
    bigint s2 = str2;
    s1.Abs();
    s2.Abs();
    if (s1.Length()>s2.Length())
    {
        swap(str1, str2);
    }
    bigint zero = "0";
    bigint str;
    if(str2<zero&&str1<zero)
    {
        str1.Abs();
        str2.Abs();
        str = str1+str2;
        str.Clip();
        str.Neg();
        return str;
    }
    if(str1<zero)
    {
        str1.Abs();
        str = str2 - str1;
        str.Clip();
        return str;
    }
    if(str2<zero)
    {
        str2.Abs();
        str = str1 - str2;
        str.Clip();
        return str;
    }
    

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
    str.Clip();
    return str;
}
bigint convert(ll n) 

{
    bigint res;
    ll m = n;
    n = abs(n);
    while(n>0)
    {
        ll rem = n%10;
        char c = rem+'0';
        res.Push_back(c);
        n/=10;
    }
    if(m<0)
    {
        res.Push_back('-');
    }
    res.Reverse();
    res.Clip();
    return res;
}
ll operator % (bigint b,ll c)
{
    bool neg = false;
    bigint zero = "0";
    if(b<zero)
    {
        neg = true;
        b.Abs();
    }
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
    if(!neg)
    return rem;
    else
    {
        rem = c-rem;
        return rem;
    }
}
bigint operator * (bigint num1,bigint num2) 

{
    bigint zero;
        zero= "0";
    if(num1<zero&&num2<zero)
    {
        num1.Abs();
        num2.Abs();
        bigint ans = num1*num2;
        ans.Clip();
        return ans;
    }
    else if(num1<zero||num2<zero)
    {
        num1.Abs();
        num2.Abs();
        bigint ans = num1*num2;
        ans.Neg();
        ans.Clip();
        return ans;
    }
    int len1 = num1.Length();
    int len2 = num2.Length();
    if (len1 == 0 || len2 == 0)
    {
        return zero;
    }

    

    

    vector<ll> result(len1 + len2, 0);

    

    

    int id5 = 0;
    int id9 = 0;

    

    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        

        

        id9 = 0;

        

        for (int j=len2-1; j>=0; j--)
        {
            

            int n2 = num2[j] - '0';

            

            

            

            int sum = n1*n2 + result[id5 + id9] + carry;

            

            carry = sum/10;

            

            result[id5 + id9] = sum % 10;

            id9++;
        }

        

        if (carry > 0)
            result[id5 + id9] += carry;

        

        

        id5++;
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
    b.Clip();
    return b;
}
bigint operator / (bigint number,ll divisor) 

{
    

    bigint ans;
    bigint zero;
    zero = "0";
    if(number<zero&&divisor<0)
    {
        number.Abs();
        divisor = -divisor;
        ans = number/divisor;
        return ans;
    }
    else if(divisor == 0)
    {
        throw invalid_argument("Invalid argument");
        return zero;
    }
    else if(number<zero||divisor<0)
    {
        number.Abs();
        divisor = abs(divisor);
        ans = number/divisor;
        ans.Neg();
        return ans;
    }
    

    

    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
    {
        if(idx!=number.Length()-1)
        temp = temp * 10 + (number[++idx] - '0');
        else
            break;
    }

    

    

    

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
bigint operator ^ (bigint b,bigint n)
{
    bigint res;
    res = "1";
    bigint zero;
    zero = "0";
  

    while(n>zero)
    {
        if(n%2 == 1)
        {
            bigint temp;
            temp = res*b;
            res = temp;
         

        }
        bigint temp;
        temp = b*b;
        b = temp;
       

        temp = n/2;
        n = temp;
    }
    res.Clip();
    return res;

}
ll powmod(bigint b,bigint n,ll MODULO) 

{
    ll tr = n.Length();
    ll rem;
    rem = b%MODULO;
    ll time_pass = n[0] - '0';
   

  ll ans = 0;
   ans = modpow(rem,time_pass,MODULO);
    rep(i,1,tr)
    {
        ans = modpow(ans,10,MODULO);
        time_pass = n[i] - '0';
        ans = ans*modpow(rem,time_pass,MODULO);

        ans%=MODULO;
    }
    return ans;
}
bigint Min(bigint a,bigint b)
{
    if(a<=b)
        return a;
    return b;
}
bigint Max(bigint a,bigint b)
{
    if(a>=b)
        return a;
    return b;
}
bigint Binary_Form(bigint a) 

{
    bigint zero = "0";
   

   bigint ans;
    while(a>zero)
    {
        ll rem = a%2;
        ans.Push_back(rem + '0');
        bigint temp = a/2;
        a = temp;
    }
    ans.Reverse();
    return ans;
}
bigint bin_dec(bigint a) 

{
    ll n = a.Length();
    bigint two = "2";
    bigint ans = "0";
    repr(i,n-1,-1)
    {
        bigint I = convert(i);
        bigint temp = two^I;
        bigint one = convert(a[n-1-i] - '0');
        temp = temp*one;
        ans = ans + temp;
    }
    return ans;
}
bigint operator & (bigint a,bigint b)
{
    bigint a1 = Binary_Form(a);
    bigint b1 = Binary_Form(b);
    if(a1<b1)
    {
        swap(a1,b1);
    }
    ll n1 = a1.Length();
    ll n2 = b1.Length();
    a1.Reverse();
    b1.Reverse();
    bigint ans;
    for(ll i = 0;i<n1;i++)
    {
        if(i<n2)
        {
            ll num1 = a1[i] - '0';
            ll num2 = b1[i] - '0';
            ll num = num1&num2;
            ans.Push_back(num+'0');
        }
        else
        {
            ans.Push_back('0');
        }
    }
    ans.Reverse();
    ans = bin_dec(ans);
    ans.Clip();
    return ans;
}
bigint operator | (bigint a,bigint b)
{
    bigint a1 = Binary_Form(a);
    bigint b1 = Binary_Form(b);
    if(a1<b1)
    {
        swap(a1,b1);
    }
    ll n1 = a1.Length();
    ll n2 = b1.Length();
    a1.Reverse();
    b1.Reverse();
    bigint ans;
    for(ll i = 0;i<n1;i++)
    {
        if(i<n2)
        {
            ll num1 = a1[i] - '0';
            ll num2 = b1[i] - '0';
            ll num = num1|num2;
            ans.Push_back(num+'0');
        }
        else
        {
            ans.Push_back(a1[i]);
        }
    }
    ans.Reverse();
    ans = bin_dec(ans);
    ans.Clip();
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
    ll c;
    cin>>b>>n>>c;
    ll ans1 = powmod(b,n,c);
    

    bigint n1 = n-"1";
   

    bigint zero = "0";
    ll ans2 = powmod(b,n1,c);
    

    ll ans = ans1 - ans2;
   

    while(ans<=0)
    {
        ans+=c;
    }
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