






























#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <time.h>
using namespace std;




















































































#define vc   vector 
#define sz(v)  (int)(v.size())
#define pb(a)  push_back(a)
#define each(it,s)  for(auto it = s.begin(); it != s.end(); it++)
#define rep(i, b, n)  for(int i = (b); i < (n); i++)
#define all(v)  v.begin(), v.end()
#define FI  first
#define SE  second
#define rr(i,j,n,m) for(int i=0;i<n;i++) for(int j=0;j<m;j++)
#define NO  cout << "NO"
#define YES cout << "YES"
#define ex(n) return n;
typedef long long int lli;
typedef long long ll;
typedef double db;









































































































class BigInteger
{
public: 
    BigInteger()
    {
        _data.push_back(0);
    }
    
    BigInteger(long long x)
    {
        while(x)
        {
            _data.push_back(x % _base);
            x /= _base;
        }
        
        if(_data.empty()) _data.push_back(0);
    }
    
    BigInteger(unsigned long long x)
    {
        while(x)
        {
            _data.push_back(x % _base);
            x /= _base;
        }
        
        if(_data.empty()) _data.push_back(0);
    }
 
    BigInteger(int x) : BigInteger((long long)x) {}
    BigInteger(unsigned int x) : BigInteger((unsigned long long)x) {}
    BigInteger(short x) : BigInteger((long long)x) {}
    BigInteger(unsigned short x) : BigInteger((unsigned long long)x) {}
    BigInteger(char x) : BigInteger((long long)x) {}
    BigInteger(unsigned char x) : BigInteger((unsigned long long)x) {}
 
    BigInteger(std::string &s)
    {
        for(int i = (int)s.size(); i > 0; i -= 9)
            if(i < 9)
                _data.push_back(atoi(s.substr(0, i).data()));
            else
                _data.push_back(atoi(s.substr(i - 9, 9).data()));
        
        while(_data.size() > 1 && _data.back() == 0)
            _data.pop_back();
    }
    
    BigInteger(const char *s)  
    {
        std::string d = s;
        
        for(int i = (int)d.size(); i > 0; i -= 9)
            if(i < 9)
                _data.push_back(atoi(d.substr(0, i).data()));
            else
                _data.push_back(atoi(d.substr(i - 9, 9).data()));
        
        while(_data.size() > 1 && _data.back() == 0)
            _data.pop_back();
    }
    
    BigInteger(const BigInteger& b)
    {
        _data.resize(b._data.size());
        std::copy(b._data.begin(), b._data.end(), _data.begin());
    }
    
    void ToString(char *s) const
    {
        sprintf(s, "%d", _data.empty() ? 0 : _data.back());
        for(int i = (int)_data.size() - 2; i >= 0; i--)
            sprintf(s, "%s%09d", s, _data[i]);
    }
    
    std::string ToString() const
    {
        char *buff = (char*)malloc(20);
        
        sprintf(buff, "%d", _data.empty() ? 0 : _data.back());
        std::string res = buff;
        
        for(int i = (int)_data.size() - 2; i >= 0; i--)
        {
            sprintf(buff, "%09d", _data[i]);
            res += buff;
        }
            
        free(buff);
        
        return res;
    }
    
    friend const BigInteger operator+(BigInteger &i);
    friend const BigInteger& operator++(BigInteger &i);
    friend const BigInteger& operator--(BigInteger &i);
    friend const BigInteger operator++(BigInteger &i, int);
    friend const BigInteger operator--(BigInteger &i, int);
    
    friend const BigInteger operator+(const BigInteger &c, const BigInteger &b);
    friend const BigInteger operator-(const BigInteger &c, const BigInteger &b);
    friend const BigInteger operator*(const BigInteger &a, const BigInteger &b);
    friend const BigInteger operator/(const BigInteger &a, const BigInteger &b);
    friend const BigInteger operator%(const BigInteger &a, const BigInteger &b);
    
    friend BigInteger& operator+=(BigInteger &a, const BigInteger &b);
    friend BigInteger& operator-=(BigInteger &a, const BigInteger &b);
    friend BigInteger& operator*=(BigInteger &a, const BigInteger &b);
    friend BigInteger& operator/=(BigInteger &a, const BigInteger &b);
    friend BigInteger& operator%=(BigInteger &a, const BigInteger &b);
    
    friend bool operator==(const BigInteger &a, const BigInteger &b);
    friend bool operator<=(const BigInteger &a, const BigInteger &b);
    friend bool operator>=(const BigInteger &a, const BigInteger &b);
    friend bool operator<(const BigInteger &a, const BigInteger &b);
    friend bool operator>(const BigInteger &a, const BigInteger &b);
    friend bool operator!=(const BigInteger &a, const BigInteger &b);
    
    
    
    friend std::istream& operator>>(std::istream &is, BigInteger &i)
    {
        std::string s;
        is >> s;
        i = BigInteger(s);
        return is;
    }
    
    friend std::ostream& operator<<(std::ostream &os, const BigInteger &i)
    {
        os << i.ToString();
        return os;
    }
    
private:
    static const int _base = 1000 * 1000 * 1000;
    std::vector<int> _data;
    
    int _cmp(const BigInteger &a, const BigInteger &b) const 

    {
        if(a._data.size() > b._data.size()) return 1;
        if(a._data.size() < b._data.size()) return -1;
        
        for(int i = (int)a._data.size() - 1; i >= 0; i--)
        {
            if(a._data[i] > b._data[i]) return 1;
            if(a._data[i] < b._data[i]) return -1;
        }
        
        return 0;
    }
    
    BigInteger _div_short(const BigInteger &c, int b, int &mod) const
    {
        mod = 0;
        BigInteger a = c;
        for(int i = (int)a._data.size() - 1; i >= 0; i--) 
        {
            long long cur = a._data[i] + mod * 1ll * BigInteger::_base;
            a._data[i] = int(cur / b);
            mod = int(cur % b);
        }
        
        while (a._data.size() > 1 && a._data.back() == 0)
            a._data.pop_back();
        
        return a;
    }
    
    bool _is_zero() const
    {
        return _data.size() == 1 && _data[0] == 0;
    }
};
 
const BigInteger operator+(const BigInteger &i) 
{
    return BigInteger(i);
}
 
const BigInteger& operator++(BigInteger &i) 
{
    int j = 0;
    i._data[0]++;
    
    while(i._data[j] >= BigInteger::_base)
    {
        if(j == (int)i._data.size() - 1) i._data.push_back(1); else i._data[j + 1]++;
        i._data[j] -= BigInteger::_base;
        j++;
    }
    
    return i;
}
 
const BigInteger operator++(BigInteger &i, int) 
{
    BigInteger old = BigInteger(i);
    
    int j = 0;
    i._data[0]++;
    
    while(i._data[j] >= BigInteger::_base)
    {
        if(j == (int)i._data.size() - 1) i._data.push_back(1); else i._data[j + 1]++;
        i._data[j] -= BigInteger::_base;
        j++;
    }
    
    return old;
}
 


const BigInteger& operator--(BigInteger &i) 
{
    if(!i._is_zero()) i = i - 1;
    return i;
}
 


const BigInteger operator--(BigInteger &i, int) 
{
    BigInteger old = BigInteger(i);
    if(!i._is_zero()) i = i - 1;
    return old;
}
 
const BigInteger operator+(const BigInteger &c, const BigInteger &b)
{
    BigInteger a = c;
        
    int carry = 0;
    for(size_t i = 0; i < std::max(a._data.size(), b._data.size()) || carry; i++) 
    {
        if(i == a._data.size()) a._data.push_back(0);
        a._data[i] += carry + (i < b._data.size() ? b._data[i] : 0);
        carry = a._data[i] >= BigInteger::_base;
        if(carry) a._data[i] -= BigInteger::_base;
    }   
        
    return a;       
}
 
const BigInteger operator-(const BigInteger &c, const BigInteger &b)
{
    if(c < b) throw std::invalid_argument("a - b, a must b greater or equal zero");
    BigInteger a = c;
        
    int carry = 0;
    for(size_t i = 0; i < b._data.size() || carry; i++) 
    {
        a._data[i] -= carry + (i < b._data.size() ? b._data[i] : 0);
        carry = a._data[i] < 0;
        if(carry) a._data[i] += BigInteger::_base;
    }
        
    while(a._data.size() > 1 && a._data.back() == 0)
        a._data.pop_back();
            
    return a;       
}
 
const BigInteger operator*(const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    c._data.resize(a._data.size() + b._data.size());
        
    for(size_t i = 0; i < a._data.size(); i++)
        for(int j = 0, carry = 0; j < (int)b._data.size() || carry; j++) 
        {
            long long cur = c._data[i + j] + a._data[i] * 1ll * (j < (int)b._data.size() ? b._data[j] : 0) + carry;
            c._data[i + j] = int(cur % BigInteger::_base);
            carry = int(cur / BigInteger::_base);
        }
            
    while(c._data.size() > 1 && c._data.back() == 0)
        c._data.pop_back();
            
    return c;       
}
 


const BigInteger operator/(const BigInteger &a, const BigInteger &b)
{
    if(b._is_zero()) throw std::invalid_argument("division by zero");
    BigInteger l = 0, r = a + 1, m;
    int t;
    while(r - l > 1)
    {
        

        m = a._div_short(r + l, 2, t);
        if(b * m <= a) l = m; else r = m;
    }
    return l;
}
 


const BigInteger operator%(const BigInteger &a, const BigInteger &b)
{
    if(b._is_zero()) throw std::invalid_argument("division by zero");
    BigInteger l = 0, r = a + 1, m;
    int t;
    while(r - l > 1)
    {
        

        m = a._div_short(r + l, 2, t);
        if(b * m <= a) l = m; else r = m;
    }
    return a - b * l;
}
 
BigInteger& operator+=(BigInteger &a, const BigInteger &b)
{
    int carry = 0;
    for(size_t i = 0; i < std::max(a._data.size(), b._data.size()) || carry; i++) 
    {
        if(i == a._data.size()) a._data.push_back(0);
        a._data[i] += carry + (i < b._data.size() ? b._data[i] : 0);
        carry = a._data[i] >= BigInteger::_base;
        if(carry) a._data[i] -= BigInteger::_base;
    }   
    return a;
}
 
BigInteger& operator-=(BigInteger &a, const BigInteger &b)
{
    int carry = 0;
    for(size_t i = 0; i < b._data.size() || carry; i++) 
    {
        a._data[i] -= carry + (i < b._data.size() ? b._data[i] : 0);
        carry = a._data[i] < 0;
        if(carry) a._data[i] += BigInteger::_base;
    }
        
    while(a._data.size() > 1 && a._data.back() == 0)
        a._data.pop_back();
            
    return a;
}
 
BigInteger& operator*=(BigInteger &a, const BigInteger &b)
{
    a = a * b;
    return a;
}
 
BigInteger& operator/=(BigInteger &a, const BigInteger &b)
{
    a = a / b;
    return a;
}
 
BigInteger& operator%=(BigInteger &a, const BigInteger &b)
{
    a = a % b;
    return a;
}
 
bool operator==(const BigInteger& a, const BigInteger& b)
{
    return a._cmp(a, b) == 0;
}
 
bool operator<=(const BigInteger& a, const BigInteger& b)
{
    return a._cmp(a, b) <= 0;
}
 
bool operator>=(const BigInteger& a, const BigInteger& b)
{
    return a._cmp(a, b) >= 0;
}
 
bool operator<(const BigInteger& a, const BigInteger& b)
{
    return a._cmp(a, b) < 0;
}
 
bool operator>(const BigInteger& a, const BigInteger& b)
{
    return a._cmp(a, b) > 0;
}
 
bool operator!=(const BigInteger& a, const BigInteger& b)
{
    return a._cmp(a, b) != 0;
}
BigInteger binpow (BigInteger a, BigInteger n) 
{
  if (n == 0) return 1; 
  if (n % 2 == 1) return binpow (a, n-1) * a; 
   else {
     BigInteger b = binpow (a, n/2);
     return b * b;
  }
}
BigInteger gcd (BigInteger a, BigInteger b) {
 if (b == 0)
  return a;
 else
  return gcd (b, a % b);
}


















int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

















struct element                      
{
    int x;                            
    element *Next;                     
};
class List                         
{
    element *Head; 

    public:
    List() {Head = NULL;}             
    ~List();                           
    void Add(int x);                   
    void Show();     
    void Delete();
    void Sort(); 
};
List::~List()                       
{
    while (Head != NULL)            
    {
        element *temp = Head->Next; 
        delete Head;                
        Head = temp;               
    }
}
void List::Add(int x)               
{
    element *temp = new element;       
    temp->x = x;                        
    temp->Next = Head;                  
    Head = temp;                        
}
void List::Show()                   
{
    element *temp=Head;                
 
    while (temp != NULL)               
    {
        cout << temp->x << " ";          
        temp = temp->Next;              
    }
}
void List::Delete()
{
    int k;
    cin >> k;
    element *temp=Head;
    element *prev = 0;
    while (temp)
    {
        element *next = temp->Next;
        if (temp->x == k )
        {
            if (prev) prev->Next = next;
            delete temp;
        }
        else
        {
            prev = temp;
        }
        temp = next;
    }
}
void List::Sort()
{
    element *temp=Head;  
    while(temp->Next)
    {
        if(temp->x >temp->Next->x)
        {
            swap(temp->x,temp->Next->x);
            temp=temp->Next;
            Sort();
        }
        else
            temp=temp->Next;
    }
}

















int main() 
{ 
    int n,m,l; 
    cin>>n>>m>>l; 
    int *a=new int [n];
    vector <bool> str; 
    int k=0; 
    bool fl=false; 
    for(int i=0;i<n;i++) 
    { 
        cin >> a[i];
        str.push_back(false); 
        if(a[i]>l) 
            str[i]=true; 
        if(a[i]>l)
            fl=true; 
        else 
            if(fl==true) 
            { 
                fl=false; 
                k++; 
            } 
    } 
    if(fl==true)
        k++; 
        
    for(int i=0;i<m;i++) 
    { 
        int t; 
        cin >> t; 
        if(t==0)
            cout << k << endl; 
        else 
        { 
            int p, d; 
            cin >> p >> d; 
            if(str[p-1]==false)
            {
                a[p-1]+=d; 
                if(a[p-1]>l) 
                { 
                    str[p-1]=true; 
                    if(p-1>0 && p-1<n-1) 
                    { 
                        if(str[p-2]==1&&str[p]==1)
                            k--; 
                        else 
                            if(str[p-2]==0&&str[p]==0)
                                k++; 
                    } 
                    else 
                        if(p-1==0) 
                        { 
                            if(str[p]==0)
                                k++; 
                        } 
                        else 
                            if(p-1==n-1) 
                            { 
                                if(str[p-2]==0)
                                    k++; 
                            } 
                } 
            } 
        }
    } 
}