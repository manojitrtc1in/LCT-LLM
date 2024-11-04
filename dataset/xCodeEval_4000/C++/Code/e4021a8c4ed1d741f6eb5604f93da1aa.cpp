#include<bits/stdc++.h>
#include <ctime>
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#define endl '\n'
using namespace std;
#define please return
#define ac 0
#define pb push_back
#define debug cout<<"又卡了吧,sb"<<'\n'
#define ll long long
#define int long long
const int mod = 998244353;
typedef pair<int, int> pii;
bool cmp(ll x, ll y)
{
    return x > y;
}
long long lcm(ll x, ll y)
{
    int temp = __gcd(x, y);
    return x * y / temp;
}
int kmp(string s1, string p1)
{
    string s;
    s += "1";
    s += s1;
    string p;
    p += "1";
    p += p1;
    int n = s1.length();
    int m = p1.length();
    int ne[m + 5];
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && p[i] != p[j + 1])j = ne[j];
        if (p[i] == p[j + 1])j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && s[i] != p[j + 1])j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m)
        {
            j = ne[j];
            return 1;
        }
    }
    return 0;
}







#define MAXN 9999
#define MAXSIZE 100
#define DLEN 4

long long ksm(long long a, long long b)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
class BigNum
{
private:
	int a[MAXSIZE];    

	int len;       

public:
	BigNum() { len = 1; memset(a, 0, sizeof(a)); }   

	BigNum(const int);       

	BigNum(const char*);     

	BigNum(const BigNum&);  

	BigNum& operator=(const BigNum&);   


	friend istream& operator >> (istream&, BigNum&);   

	friend ostream& operator<<(ostream&, BigNum&);   


	BigNum operator+(const BigNum&) const;   

	BigNum operator-(const BigNum&) const;   

	BigNum operator*(const BigNum&) const;   

	BigNum operator/(const int&) const;    

	BigNum operator*(const double&)const;

	BigNum operator^(const int&) const;    

	int    operator%(const int&) const;    

	bool   operator>(const BigNum& T)const;   

	bool   operator>(const int& t)const;      


	void print();       

};
BigNum BigNum::operator*(const double& other)const
{
	string temp1 = to_string(other);
	int cnt;
	for (int i = temp1.length() - 1; i >= 0; i--)
	{
		if (temp1[i] == '0') continue;
		else { cnt = i; break; }
	}
	string temp;
	for (int i = 0; i <= cnt; i++)
		temp += temp1[i];
	int len1 = 0;
	int len2 = 0;
	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] == '.') break;
		len1++;
	}
	long long ans1 = 0;
	long long ans2 = 0;
	int pos = 0;
	while (pos < len1)
	{
		ans1 = ans1 * 10 + (temp[pos] - '0');
		pos++;
	}
	pos = len1 + 1;
	while (pos < temp.length())
	{
		ans2 = ans2 * 10 + (temp[pos] - '0');
		pos++;
		len2++;
	}
	BigNum te3(ans1);
	BigNum te4(ans2);
	BigNum te1 = (*this) * te3;
	BigNum te2 = (*this) * te4;
	te2 = te2 / (ksm(10, len2));
	te1 = te1 + te2;
	return te1;

}
BigNum::BigNum(const int b)     

{
	int c, d = b;
	len = 0;
	memset(a, 0, sizeof(a));
	while (d > MAXN)
	{
		c = d - (d / (MAXN + 1)) * (MAXN + 1);
		d = d / (MAXN + 1);
		a[len++] = c; 

	}
	a[len++] = d;
}
BigNum::BigNum(const char* s)     

{
	int t, k, index, l, i;
	memset(a, 0, sizeof(a));
	l = strlen(s);
	len = l / DLEN;

	if (l % DLEN) 

		len++;
	index = 0;
	for (i = l - 1; i >= 0; i -= DLEN)

	{

		t = 0;
		k = i - DLEN + 1;

		if (k < 0)
			k = 0;

		for (int j = k; j <= i; j++) 

			t = t * 10 + s[j] - '0';
		a[index++] = t;
	}
}
BigNum::BigNum(const BigNum& T) : len(T.len)  

{
	int i;
	memset(a, 0, sizeof(a));
	for (i = 0; i < len; i++)
		a[i] = T.a[i];
}
BigNum& BigNum::operator=(const BigNum& n)   

{
	int i;
	len = n.len;
	memset(a, 0, sizeof(a));
	for (i = 0; i < len; i++)
		a[i] = n.a[i];
	return *this;
}



BigNum BigNum::operator+(const BigNum& T) const   

{
	BigNum t(*this);
	int i, big;      

	big = T.len > len ? T.len : len;
	for (i = 0; i < big; i++)
	{
		t.a[i] += T.a[i];
		if (t.a[i] > MAXN)
		{
			t.a[i + 1]++;
			t.a[i] -= MAXN + 1;
		}
	}
	if (t.a[big] != 0)
		t.len = big + 1;
	else
		t.len = big;
	return t;
}
BigNum BigNum::operator-(const BigNum& T) const   

{
	int i, j, big;
	bool flag;
	BigNum t1, t2;
	if (*this > T)
	{
		t1 = *this;
		t2 = T;
		flag = 0;
	}
	else
	{
		t1 = T;
		t2 = *this;
		flag = 1;
	}
	big = t1.len;
	for (i = 0; i < big; i++)
	{
		if (t1.a[i] < t2.a[i])
		{
			j = i + 1;
			while (t1.a[j] == 0)
				j++;
			t1.a[j--]--;
			while (j > i)
				t1.a[j--] += MAXN;
			t1.a[i] += MAXN + 1 - t2.a[i];
		}
		else
			t1.a[i] -= t2.a[i];
	}
	t1.len = big;
	while (t1.a[len - 1] == 0 && t1.len > 1)
	{
		t1.len--;
		big--;
	}
	if (flag)
		t1.a[big - 1] = 0 - t1.a[big - 1];
	return t1;
}

BigNum BigNum::operator*(const BigNum& T) const
{
	BigNum ret;
	int i, j, up;
	int temp, temp1;
	for (i = 0; i < len; i++)
	{
		up = 0;
		for (j = 0; j < T.len; j++)
		{
			temp = a[i] * T.a[j] + ret.a[i + j] + up;
			if (temp > MAXN)
			{
				temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
				up = temp / (MAXN + 1);
				ret.a[i + j] = temp1;
			}
			else
			{
				up = 0;
				ret.a[i + j] = temp;
			}
		}
		if (up != 0)
			ret.a[i + j] = up;
	}
	ret.len = i + j;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
BigNum BigNum::operator/(const int& b) const   

{
	BigNum ret;
	int i, down = 0;
	for (i = len - 1; i >= 0; i--)
	{
		ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
		down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
	}
	ret.len = len;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
int BigNum::operator %(const int& b) const    

{
	int i, d = 0;
	for (i = len - 1; i >= 0; i--)
	{
		d = ((d * (MAXN + 1)) % b + a[i]) % b;
	}
	return d;
}
BigNum BigNum::operator^(const int& n) const    

{
	BigNum t, ret(1);
	int i;
	if (n < 0)
		exit(-1);
	if (n == 0)
		return 1;
	if (n == 1)
		return *this;
	int m = n;
	while (m > 1)
	{
		t = *this;
		for (i = 1; i << 1 <= m; i <<= 1)
		{
			t = t * t;
		}
		m -= i;
		ret = ret * t;
		if (m == 1)
			ret = ret * (*this);
	}
	return ret;
}
bool BigNum::operator>(const BigNum& T) const   

{
	int ln;
	if (len > T.len)
		return true;
	else if (len == T.len)
	{
		ln = len - 1;
		while (a[ln] == T.a[ln] && ln >= 0)
			ln--;
		if (ln >= 0 && a[ln] > T.a[ln])
			return true;
		else
			return false;
	}
	else
		return false;
}
bool BigNum::operator >(const int& t) const    

{
	BigNum b(t);
	return *this > b;
}
ostream& operator<<(ostream& out, BigNum& b)   

{
	int i;
	cout << b.a[b.len - 1];
	for (i = b.len - 2; i >= 0; i--)
	{
		cout.width(DLEN);
		cout.fill('0');
		cout << b.a[i];
	}
	return out;
}

istream& operator >> (istream& in, BigNum& b)   

{
	char ch[MAXSIZE * 4];
	int i = -1;
	in >> ch;
	int l = strlen(ch);
	int count = 0, sum = 0;
	for (i = l - 1; i >= 0;)
	{
		sum = 0;
		int t = 1;
		for (int j = 0; j < 4 && i >= 0; j++, i--, t *= 10)
		{
			sum += (ch[i] - '0') * t;
		}
		b.a[count] = sum;
		count++;
	}
	b.len = count++;
	return in;

}
int tra(string str)
{
    int ans=0;
    for(int i=0;i<str.length();i++)
    {
        ans=ans*10;
        ans+=str[i]-'0';
    }
    return ans;
}
void solve()
{
	int n,x,y;
	cin>>n>>x>>y;
	
	int now=x+y;
	if(now==0)
	{
		cout<<-1<<'\n';
		return;
	}
	else 
	{
		if((n-1)%now!=0)
		{
			cout<<-1<<'\n';
			return;
		}
		else 
		{
			if(x==0||y==0)
			{
				vector<int>b(n+1,0);
				if(x==0)
				{
				int cnt=2;
				int now=0;
				for(int i=1;i<n;++i)
				{
					if(now==y)
					{
						cnt=i+1;
						now=0;
					}
					b[i]=cnt;
					now++;
				}
			}
			else
			{
				int cnt=2;
				int now=0;
				for(int i=1;i<n;++i)
				{
					
					if(now==x)
					{
						now=0;
						cnt=i+1;
					}
					b[i]=cnt;
					now++;
				}
			}
			for(int i=1;i<=n-1;i++)
			cout<<b[i]<<" ";
			cout<<'\n';
			}
			else {
				cout<<-1<<'\n';
			return;
			}
		}

	}
}
signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    int t;
    t = 1;
    

    cin >> t;
    while (t--)
    {
        solve();
    }
    please ac;

}