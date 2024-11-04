





using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;



ll good_rand()
{
    return rand()*RAND_MAX+rand(); 

}
ll high_rand()
{
    ll ran=rand()*RAND_MAX;
    ran*=RAND_MAX;
    ran+=rand()*RAND_MAX+rand();
    return ran; 

}
template<class A> 

class myvector : public std::vector<A> 

{
public:
    A& operator[](int pos)
    {
        if (pos<0) pos=0;
        while (this->size() <= pos)
        {
            this->push_back({});
        }
        return std::vector<A>::operator[](pos);
    }
    void print(bool b=false)
    {
        unsigned int si=this->size();
        if (b) std::cout<<si<<std::endl;
        for (unsigned int i = 0; i < si; ++i)
        {
            std::cout << this->operator[](i) << " ";
        }
    }
    void printendl(bool b=false)
    {
        print(b);
        std::cout << std::endl;
    }
    void good_random_shuffle()
    {
        unsigned int si=this->size();
        for (unsigned int i=0; i<si-1; ++i)
        {
            unsigned int j=good_rand()%(si-i);
            j+=i;
            swap(this->operator[](i), this->operator[](j));
        }
    }
    template<class B>
    void read(B &n, bool b=false)
    {
        if (b) std::cin>>n;
        for (int i=0; i<n; ++i)
        {
            std::cin>>this->operator[](i);
        }
    }
    void push_to(int pos, int val)
    {
        while (this->size()>pos)
        {
            int newval=this->operator[](pos);
            this->operator[](pos)=val;
            val=newval;
            ++pos;
        }
        this->operator[](pos)=val;
    }
};
template<class A>
class myqueue: public std::queue<A>
{
public:
    A front() const
    {
        if (this->empty()) return{};
        return std::queue<A>::front();
    }
    A top() const
    {
        return front();
    }
    void pop()
    {
        if (this->empty()) return;
        std::queue<A>::pop();
    }
    A take()
    {
        A a = this->front();
        this->pop();
        return a;
    }
    void print(bool b=false)
    {
        while(!this->empty())
        {
            std::cout<<take()<<" ";
        }
    }
    void printendl(bool b=false)
    {
        print(b);
        std::cout<<std::endl;
    }
};
template<class A, class B=std::less<typename std::vector<A>::value_type> >

class mypriority_queue : public std::priority_queue<A, std::vector<A>, B>

{
public:
    A top() const
    {
        if (this->empty()) return{};
        return std::priority_queue<A, std::vector<A>, B>::top();
    }
    void pop()
    {
        if (this->empty()) return;
        std::priority_queue<A, std::vector<A>, B>::pop();
    }
    A take()
    {
        A a = this->top();
        this->pop();
        return a;
    }
    void print(bool b=false)
    {
        while(!this->empty())
        {
            std::cout<<take()<<" ";
        }
    }
    void printendl(bool b=false)
    {
        print(b);
        std::cout<<std::endl;
    }
};



























class modll
{
    static const ll mod = 998244353;
    ll modvalue = 0;
public:
    modll()
    {
        this->modvalue = 0;
    }
    modll(int x)
    {
        this->modvalue = x%mod;
    }
    modll(ll x)
    {
        this->modvalue = x % mod;
    }
    modll(const modll &x)
    {
        this->modvalue=x.modvalue;
    }
    ll getmodvalue() const
    {
        return modvalue;
    }
    static ll modpow(ll z, ll u)
    {
        if (u == 0) return 1;
        if (u == 1) return z;
        if (u % 2 == 0)
        {
            ll sa = modpow(z, u / 2);
            return (sa*sa) % mod;
        }
        return (z * modpow(z, u - 1)) % mod;
    }
    static modll fastpow(ll z, ll u)
    {
        modll a=modpow(z, u);
        return a;
    }
    static modll fact(ll z)
    {
        modll a=1;
        for (ll i=2; i<=z; ++i)
        {
            a*=i;
        }
        return a;
    }
    static modll choose(ll n, ll k)
    {
        modll a=1;
        

        for (ll i=n; n-i+1<=k; --i)
        {
            modll b=i;
            a=a*b;
        }
        for (ll i=2; i<=k; ++i)
        {
            modll b=i;
            a=a/b;
        }
        return a;
    }
    ll rec() const
    {
        return modll::modpow(modvalue, mod - 2);
    }
    modll operator+(const modll &x) const
    {
        modll a;
        a.modvalue=(this->modvalue + x.modvalue) % mod;
        return a;
    }
    modll operator-(const modll &x) const
    {
        modll a;
        a.modvalue = (mod + this->modvalue - x.modvalue) % mod;
        return a;
    }
    modll operator*(const modll &x) const
    {
        modll a;
        a.modvalue = (this->modvalue * x.modvalue) % mod;
        return a;
    }
    modll operator/(const modll &x) const
    {
        modll a;
        if (x.modvalue == 0) return a;
        a.modvalue = (this->modvalue * x.rec()) % mod;
        return a;
    }
    template<class A>
    modll operator+(A x) const
    {
        if (x<0) return this->operator-(-x);
        modll a;
        a.modvalue=(this->modvalue+x%mod)%mod;
        return a;
    }
    template<class A>
    modll operator-(A x) const
    {
        if (x<0) return this->operator+(-x);
        modll a;
        a.modvalue=(this->modvalue-(x%mod)+mod)%mod;
        return a;
    }
    template<class A>
    modll operator*(A x) const
    {
        if (x<0)
        {
            ll y=x/mod;
            y*=mod;
            y=x-y;
            x=y;
        }
        x%=mod;
        modll a;
        a.modvalue=(this->modvalue*x)%mod;
        return a;
    }
    template<class A>
    modll operator/(A x) const
    {
        if (x<0)
        {
            ll y=x/mod;
            y*=mod;
            y=x-y;
            x=y;
        }
        x%=mod;
        modll a;
        if (x==0) return a;
        modll b=x;
        a=*this/b;
        return a;
    }
    void operator=(modll x)
    {
        this->modvalue = x.modvalue;
    }
    template<class A>
    void operator=(A x)
    {
            this->modvalue = x % mod;
    }

    bool operator==(modll x) const
    {
        return (this->modvalue == x.modvalue);
    }

    template<class A>
    bool operator==(A x) const
    {
        return (this->modvalue == x);
    }

    bool operator<(modll x) const
    {
        return (this->modvalue < x.modvalue);
    }

    template<class A>
    bool operator<(A x) const
    {
        return (this->modvalue < x);
    }

    bool operator>(modll x) const
    {
        return (this->modvalue > x.modvalue);
    }
    template<class A>
    bool operator>(A x)
    {
        return (this->modvalue > x);
    }

    bool operator<=(modll x) const
    {
        return (this->modvalue <= x.modvalue);
    }

    template<class A>
    bool operator<=(A x) const
    {
        return (this->modvalue <= x);
    }

    bool operator>=(modll x) const
    {
        return (this->modvalue >= x.modvalue);
    }

    template<class A>
    bool operator>=(A x) const
    {
        return (this->modvalue >= x);
    }

    void operator+=(const modll &x)
    {
        this->modvalue += x.modvalue;
        this->modvalue %= mod;
    }

    template<class A>
    void operator+=(A x)
    {
        if (x < 0) this->operator+=(-1 * x);
        this->modvalue += x%mod;
        if (modvalue < 0)
        {
            this->modvalue *= -1;
            if (modvalue%mod == 0) modvalue = 0;
            else modvalue = mod-(modvalue % mod);
        }
        this->modvalue %= mod;
    }

    void operator-=(const modll &x)
    {
        this->modvalue -= x.modvalue;
        while (this->modvalue < 0) this->modvalue += mod;
        this->modvalue %= mod;
    }

    template<class A>
    void operator-=(A x)
    {
        if (x < 0) this->operator+=(-1 * x);
        this->modvalue -= x % mod;
        if (modvalue < 0)
        {
            this->modvalue *= -1;
            if (modvalue%mod == 0) modvalue = 0;
            else modvalue = mod - (modvalue % mod);
        }
        this->modvalue %= mod;
    }

    void operator*=(const modll &x)
    {
        this->modvalue *= x.modvalue;
        this->modvalue %= mod;
    }

    template<class A>
    void operator*=(A x)
    {
        bool neg = false;
        if (x < 0)
        {
            neg = true;
            x *= -1;
        }
        this->modvalue *= x % mod;
        if (modvalue < 0)
        {
            this->modvalue *= -1;
            if (modvalue%mod == 0) modvalue = 0;
            else modvalue = mod - (modvalue % mod);
        }
        this->modvalue %= mod;
        if (neg)
        {
            this->modvalue = mod - modvalue;
            this->modvalue %= mod;
        }
    }

    void operator/=(const modll &x)
    {
        if (x.modvalue == 0)
        {
            this->modvalue = 0;
            return;
        }
        this->modvalue = this->modvalue/x.modvalue;
        this->modvalue %= mod;
    }

    template<class A>
    void operator/=(A x)
    {
        bool neg = false;
        if (x < 0)
        {
            neg = true;
            x *= -1;
        }
        modll se = x%mod;
        this->operator/=(se);
        if (modvalue < 0)
        {
            this->modvalue *= -1;
            if (modvalue%mod == 0) modvalue = 0;
            else modvalue = mod - (modvalue % mod);
        }
        this->modvalue %= mod;
        if (neg)
        {
            this->modvalue = mod - modvalue;
            this->modvalue %= mod;
        }
    }

    modll operator++()
    {
        modvalue++;
        if (modvalue==mod) modvalue=0;
    }

    modll operator--()
    {
        modvalue--;
        if (modvalue<0) modvalue+=mod;
    }

    void print() const
    {
        std::cout << this->modvalue;
    }
    void printspace() const
    {
        std::cout << this->modvalue << " ";
    }
    void printendl() const
    {
        std::cout << this->modvalue <<std::endl;
    }
};
string yes="YES\n";
string no="NO\n";
string idk="N/A\n";







myvector<ll>w;
ll n, m, k, l, r, x, t;
mypriority_queue<ll, std::greater<ll>>pq;
myqueue<ll>q;
set<ll>s;
set<pair<ll,ll>>p;
int a[200005];

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
    {
        s.insert(i);
    }
    for (int i=0; i<m; ++i)
    {
        cin>>t;
        if (t==0)
        {
            cin>>l>>r>>x;
            if (x==0)
            {
                while (s.lower_bound(l)!=s.end())
                {
                    ll val = (*s.lower_bound(l));
                    if (val>r) break;
                    s.erase(val);
                    a[val]=1;
                }
            }
            else{
                if (p.empty())
                {
                    p.insert({l, r});
                }
                else{
                    auto it = p.lower_bound({l+1, 0});
                    bool _ok=true;
                    if (it!=p.end())
                    {
                        if ((*it).second<=r)
                        {
                            _ok=false;
                        }
                    }
                    if (_ok)
                    {
                        if (it!=p.begin())
                        {
                            --it;
                            if ((*it).first==l && (*it).second<=r)
                            {
                                _ok=false;
                            }
                            else{
                                while ((*it).second>=r)
                                {
                                    p.erase(it);
                                    if (p.empty()) break;
                                    it = p.lower_bound({l+1, 0});
                                    if (it==p.begin())
                                    {
                                        break;
                                    }
                                    --it;
                                }
                            }
                        }
                    }
                    if (_ok) p.insert({l, r});
                }
            }
        }
        else{
            cin>>x;
            if (a[x]==1)
            {
                cout<<no;
            }
            else
            {
                bool ill=false;
                if (!p.empty())
                {
                    auto it=p.lower_bound({x+1, 0});
                    if (it!=p.begin())
                    {
                        --it;
                        l=((*it).first);
                        r=((*it).second);
                        while (l<=x && r>=x)
                        {
                            if (*s.lower_bound(l)==x)
                            {
                                if (s.upper_bound(x)==s.end())
                                {
                                    ill=true;
                                }
                                else
                                {
                                    if (*s.upper_bound(x)>r)
                                    {
                                        ill=true;
                                    }
                                }
                            }
                            if (it==p.begin()) break;
                            --it;
                            l=((*it).first);
                            r=((*it).second);
                        }
                    }
                }
                if (ill)
                {
                    cout<<yes;
                }
                else{
                    cout<<idk;
                }
            }

        }
    }

}
