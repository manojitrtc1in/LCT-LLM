#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;






#define __int64 long long

class Int
{
    int* arr;
    int sign;
public:
    static int size;
    static int max;

    Int(string a="0");
    Int(const Int& a);
    ~Int();

    Int& operator=(const Int& a);
    Int& operator=(const string& a);        

    int operator>(const Int& a) const;
    int operator<(const Int& a) const ;
    int operator==(const Int& a) const ;
    int operator!=(const Int& a) const ;
    int operator>=(const Int& a)const ;
    int operator<=(const Int& a)const ;

    int operator>(const string& a) const ;
    int operator<(const string& a)const ;
    int operator==(const string& a)const ;
    int operator!=(const string& a)const ;
    int operator>=(const string& a)const ;
    int operator<=(const string& a)const ;


    const Int operator-() const;

    Int& operator+=(const Int& a);
    Int operator+(const Int& a) const;
    Int& operator+=(const string& a);
    Int operator+(const string& a) const;

    Int& operator-=(const Int& a);
    Int operator-(const Int& a) const;
    Int& operator-=(const string& a);
    Int operator-(const string& a) const;

    Int& operator*=(const Int& a);
    Int operator*(const Int& a) const;
    Int& operator*=(const string& a);
    Int operator*(const string& a) const;

    string to_str();

    friend istream& operator>>(istream& in, Int& a);
    friend ostream& operator<<(ostream& out, const Int& a);

    int* get_arr() const;
    int get_sign() const;
    void set_sign(int k);

    static void set_size(int k);
    static int num(string a);
    static string str(int a);
    static Int abs(Int a);
};


int Int::size;
int Int::max=1000000000;



Int::Int(string a)
{
    int i;
    arr=new int[Int::size+1];
    for(i=0;i<=Int::size;i++)
        arr[i]=0;
    sign=0;
    if(a[0]=='-')
    {
        sign=1;
        a.erase(0, 1);
    }
    arr[0]=0;
    while(a.size()>9)
    {
        arr[0]++;
        arr[arr[0]]=Int::num(a.substr(a.size()-9, 9));
        a.erase(a.size()-9, 9);     
    }
    arr[0]++;
    arr[arr[0]]=Int::num(a);
}
Int::Int(const Int& a)
{
    int i;  
    arr=new int[Int::size+1];
    for(i=0;i<=Int::size;i++)
        arr[i]=0;
    arr[0]=a.get_arr()[0];
    for(i=1;i<=arr[0];i++)
        arr[i]=a.get_arr()[i];
    sign=a.get_sign();
}



Int& Int::operator=(const Int& a)
{
    if(this!=&a)
    {
        delete[] arr;

        int i;
        arr=new int[Int::size+1];
        for(i=0;i<=Int::size;i++)
            arr[i]=0;
        arr[0]=a.get_arr()[0];
        for(i=1;i<=arr[0];i++)
            arr[i]=a.get_arr()[i];
        sign=a.get_sign();
    }
    return *this;
}
Int::~Int()
{
    delete[] arr;
}
Int& Int::operator=(const string& a)
{
    return (*this)=Int(a);
}

int Int::operator>(const Int& a) const 
{
    int* brr=a.get_arr(), i;
    if(sign!=a.get_sign())
        return sign<a.get_sign();
    if(sign==0)
    {
        if(arr[0]!=brr[0])
            return arr[0]>brr[0];       
        for(i=arr[0];i>=1;i--)
            if(arr[i]!=brr[i])
                return arr[i]>brr[i];
        return 0;
    }
    if(arr[0]!=brr[0])
        return arr[0]<brr[0];   
    for(i=arr[0];i>=1;i--)
        if(arr[i]!=brr[i])
            return arr[i]<brr[i];
    return 0;   
}
int Int::operator<(const Int& a) const 
{
    return a>(*this);
}
int Int::operator==(const Int& a)const 
{
    return !(a>(*this) || a<(*this));
}
int Int::operator!=(const Int& a)const 
{
    return !((*this)==a);
}
int Int::operator<=(const Int& a)const 
{
    return !((*this)>a);
}
int Int::operator>=(const Int& a)const 
{
    return !((*this)<a);
}

int Int::operator>(const string& a)const 
{
    return (*this)>Int(a);
}
int Int::operator<(const string& a)const 
{
    return Int(a)>(*this);
}
int Int::operator==(const string& a)const 
{
    return !(Int(a)>(*this) || Int(a)<(*this));
}
int Int::operator!=(const string& a)const 
{
    return !((*this)==a);
}
int Int::operator<=(const string& a)const 
{
    return !((*this)>Int(a));
}
int Int::operator>=(const string& a)const 
{
    return !((*this)<Int(a));
}

const Int Int::operator-() const
{
    Int c(*this);
    c.set_sign((sign+1)%2);
    return c;
}

Int& Int::operator+=(const Int& a)
{
    int* brr=a.get_arr();
    int carry=0, i;

    if((*this)<"0")
    {
        if(a<"0")
        {
            if(arr[0]>=brr[0])
            {
                for(i=1;i<=brr[0];i++)
                {
                    arr[i]=arr[i]+brr[i]+carry;
                    carry=arr[i]/Int::max;
                    arr[i]%=Int::max;
                }
                while(carry)
                {
                    arr[i]=arr[i]+carry;
                    carry=arr[i]/Int::max;
                    arr[i]%=Int::max;
                    i++;
                }
                if(i==arr[0]+2)
                    arr[0]++;
            }
            else
            {
                Int c(*this), d(a);
                (*this)=(d+=c);
            }
        }
        else
        {
            if(*this==(-a))
                (*this)="0";            
            else
            if(-(*this)>a)
            {
                for(i=1;i<=brr[0];i++)
                {
                    arr[i]=arr[i]-brr[i]+carry;
                    if(arr[i]<0)
                    {
                        carry=-1;
                        arr[i]+=Int::max;
                    }
                    else
                        carry=0;
                }
                while(carry)
                {
                    arr[i]=arr[i]+carry;
                    if(arr[i]<0)
                    {
                        carry=-1;
                        arr[i]+=Int::max;
                    }
                    else
                        carry=0;
                    i++;
                }
                while(arr[arr[0]]==0 && arr[0]>1)
                    arr[0]--;
            }
            else
            {
                Int c(*this), d(a);
                (*this)=(d+=c);
            }
        }
    }
    else
    {
        

        if(a<"0")
        {
            if(*this==-a)
                (*this)="0";            
            else
            if(*this>-a)
            {
                for(i=1;i<=brr[0];i++)
                {
                    arr[i]=arr[i]-brr[i]+carry;
                    if(arr[i]<0)
                    {
                        carry=-1;
                        arr[i]+=Int::max;
                    }
                    else
                        carry=0;
                }
                while(carry)
                {
                    arr[i]=arr[i]+carry;
                    if(arr[i]<0)
                    {
                        carry=-1;
                        arr[i]+=Int::max;
                    }
                    else
                        carry=0;
                    i++;
                }
                while(arr[arr[0]]==0 && arr[0]>1)
                    arr[0]--;
            }
            else
            {
                Int c(*this), d(a);
                (*this)=(d+=c);
            }
        }
        else
        {
            Int c(-(*this)), d(-a);
            (*this)=-(d+=c);        
        }
    }
    return *this;
}
Int Int::operator+(const Int& a) const
{
    return Int(*this)+=a;
}
Int& Int::operator+=(const string& a)
{
    return (*this)+=Int(a);
}
Int Int::operator+(const string& a) const
{
    return Int(*this)+=a;
}
Int operator+(const string& a, const Int& b)
{
    return b+a;
}

Int& Int::operator-=(const Int& a)
{
    return *this+=-a;
}
Int Int::operator-(const Int& a) const
{
    return Int(*this)-=a;
}
Int& Int::operator-=(const string& a)
{
    return (*this)-=Int(a);
}
Int Int::operator-(const string& a) const
{
    return Int(*this)-=a;
}
Int operator-(const string& a, const Int& b)
{
    return -(b-a);
}

Int& Int::operator*=(const Int& a)
{
    int i;
    if(a=="0")
        (*this)="0";
    else
    if(a==str(Int::max))
    {
        if((*this)!="0")
        {
            for(i=arr[0];i>=1;i--)
                arr[i+1]=arr[i];
            arr[1]=0;
            arr[0]++;       
        }
    }
    else
    if(Int::abs(a)<str(Int::max))
    {
        __int64 tmp;
        int carry=0;
        int* brr=a.get_arr();
        for(i=1;i<=arr[0];i++)
        {
            tmp=(__int64)arr[i]*(__int64)brr[1]+(__int64)carry;
            arr[i]=tmp%(__int64)Int::max;
            carry=tmp/(__int64)Int::max;
        }
        if(carry)
        {
            arr[i]=carry;
            arr[0]++;
        }
    }
    else
    {
        Int tmp, res=(string)"0";
        int* brr=a.get_arr();
        for(i=brr[0];i>=1;i--)
        {
            tmp=(*this)*str(brr[i]);
            res=res*str(Int::max)+tmp;
        }
        (*this)=res;
    }
    sign=(sign+a.get_sign())%2;
    return *this;
}
Int Int::operator*(const Int& a) const
{
    Int c(*this);
    return c*=a;
}
Int& Int::operator*=(const string& a)
{
    return (*this)*=Int(a);
}
Int Int::operator*(const string& a) const
{
    return Int(*this)*=a;
}
Int operator*(const string& a, const Int& b)
{
    return b*a;
}

istream& operator>>(istream& in, Int& a)
{
    string b;
    in>>b;
    int h=0;
    if(b[0]=='-')
    {
        h=1;
        b.erase(0, 1);
    }
    while(b[0]=='0' && b.size()!=1)
        b.erase(0, 1);
    if(b[0]!='0' && h)
        b.insert(0, "-");
    a=b;
    return in;
}
ostream& operator<<(ostream& out, const Int& a)
{
    int i, j, k;
    int* brr=a.get_arr();
    if(a.get_sign())
        out<<'-';
    out<<brr[brr[0]];
    for(i=brr[0]-1;i>=1;i--)
    {
        k=Int::max;
        for(j=0;j<9;j++)
            out<<(brr[i]%k)/(k/=10);
    }   
    return out;
}

string Int::to_str()
{
    string res;
    int i, j, k;
    if(sign)
        res="-";
    res+=Int::str(arr[arr[0]]);
    for(i=arr[0]-1;i>=1;i--)
    {
        k=Int::max;
        for(j=0;j<9;j++)
            res+=Int::str((arr[i]%k)/(k/=10));
    }   
    return res;
}



int* Int::get_arr() const
{
    return arr;
}
int Int::get_sign() const
{
    return sign;
}
void Int::set_sign(int k)
{
    sign=k;
}



Int Int::abs(Int a)
{
    return a<"0"?-a:a;      
}
int Int::num(string a)
{
    int res=0, i;
    for(i=0;i<a.size();i++)
        res=res*10+a[i]-'0';
    return res;
}
string Int::str(int a)
{
    string res="";
    int h=(a<0?1:0);    
    a=(a<0?-a:a);
    while(a!=0)
    {
        res=(char)(a%10+'0')+res;
        a/=10;
    }
    if(res.size()==0)
        res="0";
    if(h)
        res="-"+res;
    return res;
}
void Int::set_size(int k)
{
    Int::size=k;
};

int qanak;

Int solve(const string& s, int h = 0)
{
    vector <bool> u(26, false);
    Int answer = "1";
    int k = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '?')
            k++;
        if (s[i] >= 'A' && s[i] <= 'Z')
            u[s[i] - 'A'] = true;
    }
    for (int i = 0; i < k; ++i)
        qanak++;
        

    k = 0;
    for (int i = 0; i < 26; ++i)
        if (u[i])
            k++;
    if (k>10)
        return 0;
    for (int i = 0; i < k; ++i)     
        answer *= Int::str(10 - i - h);
    return answer;
}

int main ()
{
    qanak = 0;
    Int::set_size(12);
    Int answer = "0";
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        if (s[0] == '?' || (s[0] >= 'A' && s[0] <= 'Z'))
            answer = "9";
        else
            answer = "1";
        cout << answer << endl;
        return 0;
    }
    if (s[0] == '?')
    {
        string st = s;
        st.erase(0, 1);
        answer = "9" * solve(st);       
    }
    else if (s[0] >= 'A' && s[0] <= 'Z')
    {
        for (int k = 1; k < 10; ++k)
        {
            string st = s;
            qanak = 0;
            for (int i = 0; i < st.size(); ++i)
                if (st[i] == s[0])
                    st[i] = (char)('0' + k);            
            answer += solve(st, 1);
        }
    } else answer = solve(s);
    cout << answer;
    for (int i = 0; i < qanak; ++i)
        cout << 0;
    cout << endl;
}