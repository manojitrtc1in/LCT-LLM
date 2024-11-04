


#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <time.h>
#include <clocale>
#include <fstream>
#include <conio.h>
#include <random> 
#include <utility>
#include <bitset>

using namespace std;

#define forx(i,n) for(int i(0);i < n;i++)
#define vec vector
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()

typedef long L;
typedef long long LL;
typedef long double LD;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<double> vdouble;
typedef vector<vector<double>> vvdouble;
typedef vec<bool> vbool;
typedef vec<vec<bool>> vvbool;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;
typedef unsigned long long ull;
typedef unsigned int ui;
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;
const LL base  = 1e9+7;
inline LL Sqr(LL a){return a*a;}
struct Tripple
{
    int first;
    int second;
    int third;

    void make_tripple(int a,int b,int c)
    {
        first  = a;
        second = b;
        third  = c;
    }
};
bool cmp1(Tripple a,Tripple b)
{
    return a.first < b.first;
}
bool cmp2(Tripple a,Tripple b)
{
    return a.second < b.second;
}
bool cmp3(Tripple a,Tripple b)
{
    return a.third < b.third;
}




class big_num
{
protected:
    vector<int> big;
    bool flag;



    

    big_num sumofbig(big_num& tmp)
    {
        size_t length = max(big.size(),tmp.big.size())+1;
        big_num q(*this);
        
        for(int i(0);i < (int)(length-1);i++)
        {
            if(i == (q.big.size()-1))
                q.big.push_back(0);
            if(i == (tmp.big.size()-1))
                tmp.big.push_back(0);

            q.big[i] += tmp.big[i];
            q.big[i+1] += q.big[i]/10;
            q.big[i] %= 10;
        }

        while(q.big.size() > 1 && q.big.back() == 0)
            q.big.pop_back();

        while(tmp.big.size() > 1 && tmp.big.back() == 0)
            tmp.big.pop_back();
        
        return q;
    }
    

    big_num razofbig(big_num& a)
    {
        big_num ans(*this);

        size_t length = ans.big.size();

        for(size_t i(a.big.size());i < ans.big.size();i++)
            a.big.push_back(0);


        for(size_t i = 0;i < length;i++)
        {
            if(i == (length-1))
            {
                ans.big[i] = ans.big[i] - a.big[i];
            }else
            {
                if(ans.big[i] >= a.big[i])
                    ans.big[i] -= a.big[i];
                else
                {
                    ans.big[i] = ans.big[i] + 10 - a.big[i];
                    int index = i;
                    while(!ans.big[index+1])
                    {
                        ans.big[index+1] = 9;
                        index++;
                    }
                    ans.big[index + 1]--;
                }
            }
        }

        while(ans.big.size() > 1 && ans.big.back() == 0)
            ans.big.pop_back();

        while(a.big.size() > 1 && a.big.back() == 0)
            a.big.pop_back();

        return ans;
    }
public:


    big_num()
    {
        big.clear();
        big.push_back(0);
        flag = true;

    }
    big_num(const LL& at)
    {
        LL a = at;
        if(a < 0)
            flag = false;

        else
            flag = true;

        while(a)
        {
            big.push_back(a%10);
            a /= 10;
        }

        if(a == 0)big.push_back(0);

        while(big.size() > 1 && big.back() == 0)
            big.pop_back();
    }
    big_num(const vint &a, const bool &fl)
    {
        big = a;
        flag = fl;
    }
    big_num(const big_num &v)
    {
        if(v.flag)
            flag = true;
        else
            flag = false;

        big.clear();
        big.insert(big.end(),v.big.begin(),v.big.end());

        while(big.size() > 1 && big.back() == 0)
            big.pop_back();
    }
    big_num(const string &a)
    {
        big.clear();

        if(a[0] == '-')
        {
            flag = false;
    
            for(int i(a.length()-1);i >= 1;i--)
            {
                big.push_back((int)a[i] - 48);
            }
        }else
        {
            flag = true;

            for(int i(a.length()-1);i >= 0;i--)
            {
                big.push_back((int)a[i] - 48);
            }
        }

        while(big.size() > 1 && big.back() == 0)
            big.pop_back();
    }
    ~big_num()
    {
        big.clear();
    }



    operator LL()
    {
        if(big.size() > 18) return 0;

        LL ans = 0;

        for(int i(big.size() - 1);i >= 0;i--) ans = ans * 10 + big[i];

        return ans;
    }
    LL toll(vint a, vint::iterator s, vint::iterator f)
    {
        LL ans = 0;

        s--;
        f--;

        for(auto i = s; i != f;i--) ans = ans * 10 + *i;

        return ans;
    }



    friend std::ostream& operator<<(std::ostream& os,const big_num& a)
    {
        if(!a.flag)
            os << "-";

        for(int i(a.big.size()-1);i >= 0;i--)
        {
            os << a.big[i];
        }

        return os;
    }
    friend std::istream& operator>>(std::istream& is,big_num& a)
    {
        string str;
        a.big.clear();
        is >> str;

        if(str[0] == '-')
        {
            a.flag = false;
            str.erase(str.begin(),str.begin()+1);
        }else
            a.flag = true;

        for(int i(str.length()-1);i >= 0;i--)
        {
            a.big.push_back(str[i]-48);
        }

        while(a.big.size() > 1 && a.big.back() == 0)
            a.big.pop_back();

        return is;
    }
    const big_num& operator=(const big_num &v)
    {
        if(v.flag)
            flag = true;
        else
            flag = false;

        big.clear();
        big.insert(big.end(),v.big.begin(),v.big.end());

        return *this;
    }
    const big_num& operator=(const LL& at1)
    {
        big_num ans(at1);
        (*this) = ans;
        return *this;
    }
    const big_num& operator=(const string &a)
    {
        big.clear();

        if(a[0] == '-')
        {
            flag = false;
    
            for(int i(a.length()-1);i >= 1;i--)
            {
                big.push_back((int)a[i] - 48);
            }
        }else
        {
            flag = true;

            for(int i(a.length()-1);i >= 0;i--)
            {
                big.push_back((int)a[i] - 48);
            }
        }

        while(big.size() > 1 && big.back() == 0)
            big.pop_back();

        return *this;
    }


    bool operator> (const big_num& b)

    {
        if(flag && !b.flag)
            return true;
        if(!flag && b.flag)
            return false;

        if(flag && b.flag)
        {
            if(big.size() > b.big.size())
                return true;
            if(big.size() < b.big.size())
                return false;

            for(int i(b.big.size()-1);i >= 0;i--)
            {
                if(big[i] > b.big[i])
                    return true;
                if(big[i] < b.big[i])
                    break;
            }
        
            return false;

        }else
        {
            if(big.size() > b.big.size())
                return false;
            if(big.size() < b.big.size())
                return true;

            for(int i(big.size()-1);i >= 0;i--)
            {
                if(big[i] < b.big[i])
                    return true;
                if(big[i] > b.big[i])
                    break;
            }
            return false;
        }
    }
    bool operator==(const big_num& b)
    {
        if(big.size() != b.big.size() || flag != b.flag)
                return false;
    
        for(size_t i(0);i < big.size();i++)
        {
            if(big[i] != b.big[i])
                return false;
        }
        return true;
    
    }
    bool operator< (const big_num& b)

    {
        if(flag && !b.flag)
            return false;
        if(!flag && b.flag)
            return true;

        if(flag && b.flag)
        {
            if(big.size() > b.big.size())
                return false;
            if(big.size() < b.big.size())
                return true;

            for(int i(big.size()-1);i >= 0;i--)
            {
                if(big[i] < b.big[i])
                    return true;
                if(big[i] > b.big[i])
                    break;
            }
            return false;
        }else
        {
            if(big.size() > b.big.size())
                return true;
            if(big.size() < b.big.size())
                return false;

            for(int i(b.big.size()-1);i >= 0;i--)
            {
                if(big[i] > b.big[i])
                    return true;
                if(big[i] < b.big[i])
                    break;
            }
        
            return false;
        }
    }
    bool operator>=(const big_num& b)
    {
        if(!((*this) < b))
            return true;
        else
            return false;
    }
    bool operator<=(const big_num& b)
    {
        if(!((*this) > b))
            return true;
        else
            return false;
    }
    bool operator!=(const big_num& b)
    {
        if((*this) == b)
            return false;
        else
            return true;
    }


    big_num operator- (big_num&  b)
    {
        big_num ans;

        if(flag)
        {
            if(b.flag)
            {
                if((*this) >= b)
                {
                    ans = (*this).razofbig(b);
                    ans.flag = true;
                }else
                {
                    ans = b.razofbig(*this);
                    ans.flag = false;
                }
            }else
            {
                ans = b.sumofbig(*this);
                ans.flag = true;
            }
        }else
        {
            if(b.flag)
            {
                ans = b.sumofbig(*this);
                ans.flag = false;
            }else
            {
                if(b <= (*this))
                {
                    ans = b.razofbig(*this);
                    ans.flag = true; 
                }else
                {
                    ans = (*this).razofbig(b);
                    ans.flag = false;
                }
            }
        }

        return ans;
    }
    big_num operator+ (big_num&  b)
    {
        big_num ans;

        if(flag)
        {
            if(b.flag)
            {
                ans = b.sumofbig(*this);
                ans.flag = true;
            }else
            {
                if((*this) >= -b)
                {
                    ans = (*this).razofbig(b);
                    ans.flag = true;
                }else
                {
                    ans = b.razofbig(*this);
                    ans.flag = false;
                }
            }
        }else
        {
            if(b.flag)
            {
                if(-(*this) >= b)
                {
                    ans = (*this).razofbig(b);
                    ans.flag = false;
                }else
                {
                    ans = b.razofbig(*this);
                    ans.flag = true;
                }
            }else
            {
                ans = b.sumofbig(*this);
                ans.flag = false;
            }
        }
        
        return ans;
    }
    void    operator+=(big_num&  b)
    {
        (*this) = (*this) + b;
    }
    void    operator-=(big_num&  b)
    {
        (*this) = (*this) - b;
    }
    big_num operator- (const LL& b)
    {
        big_num tmp(b);
        big_num ans;
        ans = (*this) - tmp;
        return ans;
    }
    big_num operator+ (const LL& b)
    {
        big_num tmp(b);
        big_num ans = (*this) + tmp;
        return ans;
    }
    void    operator+=(const LL& b)
    {
        (*this) = (*this) + b;
    }
    void    operator-=(const LL& b)
    {
        (*this) = (*this) - b;
    }
    big_num operator* (const LL& b)
    {
        big_num ans(*this);
        LL carry = 0;
            for (size_t i=0; i<ans.big.size() || carry; ++i) {
                if (i == ans.big.size())
                    ans.big.push_back (0);
                    long long cur = carry + ans.big[i] * b;
                    ans.big[i] = cur % 10;
                    carry = cur/10;
        }
        while (ans.big.size() > 1 && ans.big.back() == 0)
            ans.big.pop_back();
        return ans;
    }
    void    operator*=(const LL& b)
    {
        (*this) = (*this) * b;
    }
    big_num operator* (big_num& b)
    {
        vec<big_num> tmp;

        if((*this) >= b)
        {
            for(int i(0);i < b.big.size();i++)
            {
                tmp.push_back( (*this) * (LL)(b.big[i]) );
            }
        }else
        {
            for(int i(0);i < big.size();i++)
            {
                tmp.push_back( b * (LL)big[i] );
            }
        }

        int ind = 1;

        big_num ans(tmp[0]);

        for(int i(1);i < tmp.size();i++)
        {
            for(int j(0);j < ind;j++)
            {
                tmp[i] *= 10;
            }
            ind++;

            ans += tmp[i];
        }

        return ans;
    }
    void    operator*=(big_num& b)
    {
        (*this) = (*this) * b;
    }

    


    pair<big_num, LL> del(const LL &tt)
    {
        if(big.size() <= 18)
        {
            LL A = LL(*this);
            return mp(big_num(A / tt), A % tt);
        }


        big_num tmp(tt);
        big_num th = *this;
        if(*this < tmp) return mp(0, tt);
        if(*this == tmp) return mp(1, 0);

        LL v = tt;
        int cnt = 0;

        while(v) {cnt++, v /= 10;}

        LL b = th.toll(th.big, th.big.end(),th.big.end() - cnt);
        vint a;
        
        if(b < tt) cnt++, b = th.toll(th.big, th.big.end(), th.big.end() - cnt);

        while(b >= tt)
        {
            a.push_back(b / tt);
            b = b - tt * (b / tt);

            for(int i(big.size()-1-cnt);i >= 0;i--)
            {
                if(b < tt) b = b * 10 + big[i];
                else {cnt = big.size() - 1 - i;break;}
            }
        }
        reverse(ALL(a));

        bool ttt;

        if(b < 0) if(this->flag) ttt = 0; else ttt = 1;
        else if(this->flag) ttt = 1; else ttt = 0;
        return mp(big_num(a, ttt), b * (ttt?1 : -1));
    }

    big_num operator / (const LL &b) { return (*this).del(b).first;}
    big_num operator % (const LL &b) { return (*this).del(b).second;}

    




    

    big_num operator-()
    {
        big_num q(*this);

        if(flag)
            q.flag = false;
        else
            q.flag = true;
        return q;
    }
    

    big_num abs()
    {
        big_num ans(*this);
        ans.flag = true;

        return ans;
    }
    

    big_num sqr()
    {
        return (*this) * (*this);
    }


};










bool solve()
{
    ios_base::sync_with_stdio(0);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    srand(time(NULL));
    

    


    int n, score;
    string name;

    cin >> n;

    map<string, int> a;
    map<string, vec<pii>> b;
    
    for(int i(0);i < n;i++)
    {
        cin >> name >> score;
        a[name] += score;
        b[name].push_back(mp(a[name], i));
    }

    LL mx = -inf;
    string ans = "";
    int moment = -1;

    for(auto i : a) mx = max(mx, i.second * 1ll);

    for(auto i : a)
    {
        if(i.second != mx) continue;

        int tmp = -1;

        for(auto j : b[i.first]) if(j.first >= mx) {tmp = j.second;break;}

        if(moment == -1 || tmp < moment)
        {
            moment = tmp;
            ans = i.first;
        }
    }

    cout << ans << '\n';

    

    return true;
}

int main(int argc,char **argv)
{
    

    solve();

    return 0;
}