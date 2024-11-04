




long double pi = acos(-1);

class BigInteger {
private :
    bool positiv = true;
    std::vector <int> digits;
public :
    BigInteger() {};
    BigInteger(const std::string &x) {
        positiv = true;
        if (x.size() == 0) digits.push_back(0);
        else {
            for (int i = x.size() - 1;i >= 0;i--)
                if (x[i] >= '0' && x[i] <= '9') digits.push_back((int)((x[i])-'0'));
            if (x[0] == '-') positiv = false;
            while (digits.size() > 0 && digits.back() == 0) digits.pop_back();
            if (digits.size() == 0) {positiv = true;digits.push_back(0);}
        }
    }
    ~BigInteger() {
        digits.clear();
        digits.push_back(0);
        positiv = true;
    }
    BigInteger (const int &x) {
        positiv = (x >= 0);
        int y = x;
        if (x < 0) y = -x;
        while (y > 0) {
            digits.push_back(y % 10);
            y/=10;
        }
        if (!digits.size()) {positiv = true;digits.push_back(0);}
    }
    bool operator== (const BigInteger &x) const{
    	 BigInteger zm1 = (*this);
        BigInteger zm2 = x;
        while (zm1.digits.size() > 0 && zm1.digits.back() == 0) zm1.digits.pop_back();
        if (!zm1.digits.size()) {zm1.positiv = true;zm1.digits.push_back(0);}
        while (zm2.digits.size() > 0 && zm2.digits.back() == 0) zm2.digits.pop_back();
        if (!zm2.digits.size()) {zm2.positiv = true;zm2.digits.push_back(0);}
        if (positiv != x.positiv) return false;
        if (zm1.digits.size() != zm2.digits.size()) return false;
        for (int i = 0;i < (int)zm1.digits.size();i++)
            if (zm2.digits[i] != zm1.digits[i]) return false;
        return true;
    }
    bool operator< (const BigInteger &x) const{
    	BigInteger zm1 = (*this);
        BigInteger zm2 = x;
        while (zm1.digits.size() > 0 && zm1.digits.back() == 0) zm1.digits.pop_back();
        if (!zm1.digits.size()) {zm1.positiv = true;zm1.digits.push_back(0);}
        while (zm2.digits.size() > 0 && zm2.digits.back() == 0) zm2.digits.pop_back();
        if (!zm2.digits.size()) {zm2.positiv = true;zm2.digits.push_back(0);}
        

        if (zm1 == zm2) return false;
        if (zm1.positiv != zm2.positiv) return !zm1.positiv;
        if (!positiv) {
            BigInteger z1 = zm1;
            BigInteger z2 = zm2;
            z1 = z1.abs();
            z2 = z2.abs();
            return (!(z1 < z2));
        }
        if (zm1.digits.size() != zm2.digits.size()) return (zm1.digits.size() < zm2.digits.size());
        for (int i = zm1.digits.size() - 1;i >= 0;i--)
            if (zm1.digits[i] != zm2.digits[i]) return (zm1.digits[i] < zm2.digits[i]);
        return false;
    }
    bool operator> (const BigInteger &x) const{
        

        if (x == (*this)) return false;
        return (!((*this) < x));
    }
    bool operator!= (const BigInteger &x) const{
        return !(x == (*this));
    }
    bool operator<= (const BigInteger &x) const {
        if (x == (*this)) return true;
        return ((*this) < x);
    }
    bool operator>= (const BigInteger &x) const {
        if (x == (*this)) return true;
        return ((*this) > x);
    }
    std::string toString() const{
        std::string ans = "";
        if (!positiv) ans+='-';
        for (int i = (int)digits.size() - 1;i >= 0;i--)
            ans+=((char)((digits[i])+'0'));
        if (ans.size() == 0) ans = "0";
        return ans;
    }
    explicit operator bool() {
        

        if (digits[0] == 0 && digits.size() == 1) return false;
        else return true;
    }
    BigInteger &operator+=(const BigInteger& x) {
        if (x.positiv == positiv) {
            int carry = 0;
            for (int i = 0;i < (int)digits.size() || i < (int)x.digits.size() || carry;i++)
            {
                if (i == (int)digits.size()) digits.push_back(0);
                if (i < (int)x.digits.size()) {
                    digits[i]+=(carry + x.digits[i]);
                }
                else digits[i]+=carry;
                carry = (digits[i] / 10);
                digits[i]%=10;
            }
            while (digits.size() > 0 && digits.back() == 0) digits.pop_back();
            if (!digits.size()) digits.push_back(0);
            return (*this);
        }
        else {
            BigInteger w = (*this);
            BigInteger zz = x;
            if (w.abs() > zz.abs()) {
                w.raznost_(zz);
                (*this) = w;
                return (*this);
            }
            else {
                BigInteger a1 = (*this);
                BigInteger a2 = x;
                a2.raznost_(a1);
                return (*this = a2);
            }
        }
    }
    void raznost_(const BigInteger &x) {
        int carry = 0;
        for (int i = 0;i < (int)x.digits.size() || carry;i++)
        {
            if (i < (int)x.digits.size()) digits[i]-=(carry + x.digits[i]);
            else digits[i]-=carry;
            carry = (digits[i] < 0);
            if (carry != 0) digits[i]+=10;
        }
        while (digits.size() > 0 && digits.back() == 0) digits.pop_back();
        if (!digits.size()) {positiv = true;digits.push_back(0);}
    }
    BigInteger abs() const{
        BigInteger wow = (*this);
        wow.positiv = true;
        return wow;
    }
    BigInteger &operator= (const BigInteger &x) {
        positiv = x.positiv;
        digits = x.digits;
        return (*this);
    }
    BigInteger &operator-= (const BigInteger &x) {
        if (positiv == x.positiv) {
            BigInteger w = (*this);
            BigInteger zz = x;
            if (w.abs() >= zz.abs()) {w.raznost_(zz);
                (*this) = w;
                return (*this);}
            else {
                BigInteger a1 = (*this);
                BigInteger a2 = x;
                a2.raznost_(a1);
                a2.positiv = (!a2.positiv);
                return (*this = a2);
            }
        }
        else {
            int carry = 0;
            for (int i = 0;i < (int)digits.size() || i < (int)x.digits.size() || carry;i++)
            {
                if (i == (int)digits.size()) digits.push_back(0);
                if (i < (int)x.digits.size()) {
                    digits[i]+=(carry + x.digits[i]);
                }
                else digits[i]+=carry;
                carry = (digits[i] / 10);
                digits[i]%=10;
            }
            while (digits.size() > 0 && digits.back() == 0) digits.pop_back();
            if (!digits.size()) digits.push_back(0);
            return (*this);
        }
    }
    typedef std::complex <long double> ftype; 


    inline void FFT (std::vector <ftype> &p, bool inv) {
        int n = (int)p.size();
        if (n == 1) return;
        std::vector <ftype> a(n / 2);
        std::vector <ftype> b(n / 2);
        for (int i = 0;i < n / 2;i++)
        {
            a[i] = p[i * 2];
            b[i] = p[i * 2 + 1];
        }
        FFT(a, inv);
        FFT(b, inv);
        long double h = 2 * pi / n;
        if (inv) h*=-1;
        ftype w(1),wn(cos(h),sin(h));
        for (int i = 0;i < n / 2;i++)
        {
            p[i] = a[i] + w * b[i];
            p[i + n / 2] = a[i] - w * b[i];
            if (inv) {
                p[i]/=2;
                p[i + n / 2]/=2;
            }
            w*=wn;
        }
    }

    inline std::vector <int> multiply (std::vector <int> a,std::vector <int> b)
    {
        std::vector <ftype> x (a.begin(),a.end());
        std::vector <ftype> y (b.begin(),b.end());
        int m = 1;
        while (m < std::max((int)a.size(),(int)b.size())) m*=2;
        m*=2;
        x.resize(m);
        y.resize(m);
        FFT(x, 0);
        FFT(y, 0);
        for (int i = 0;i < m;i++)
            x[i]*=y[i];
        FFT(x, 1);
        std::vector <int> ans(m);
        for (int i = 0;i < m;i++)
            ans[i] = (int)(x[i].real() + 0.5);
        return ans;
    }
    BigInteger &operator*= (const BigInteger& x) {
        if ((*this) == 0) return (*this);
        if (x == 0) {
            (*this) = x;
            return (*this);
        }
        
        std::vector <int> zj = multiply(digits,x.digits);
        int ptr = (int)zj.size() - 1;
        while (ptr >= 0 && zj[ptr] == 0) --ptr;
        int carry = 0;
        positiv = (!(positiv ^ x.positiv));
        std::vector <int> ans;
        ans.resize(ptr + 1);
        for (int i = 0;i <= ptr || carry;i++)
        {
            if (i > ptr) ans.push_back(0);
            ans[i] = (zj[i] + carry);
            carry = (zj[i] + carry) / 10;
            ans[i]%=10;
        }
        digits = ans;
        return (*this);
    }
    BigInteger &operator/= (const BigInteger& x) {
        if ((*this) == 0) {return (*this);}
        BigInteger ans;
        ans.digits.resize(digits.size());
        BigInteger cur;
        for (int i = digits.size() - 1;i >= 0;i--)
        {
            cur.digits.insert(cur.digits.begin(),0);
            while (cur.digits.size() > 0 && cur.digits.back() == 0) cur.digits.pop_back();
            if (cur.digits.size() == 0) {cur.positiv = true;cur.digits.push_back(0);}
            cur.digits[0] = digits[i];
            int nd = -1;
            int left = 0;
            int right = 9;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if ((x.abs() * mid).abs() <= cur.abs()) {
                    nd = mid;
                    left = mid + 1;
                }
                else right = mid - 1;
            }
            cur-=x.abs() * nd;
            ans.digits[i] = nd;
        }
        if (positiv != x.positiv) ans.positiv = false;
        else ans.positiv = true;
        while (ans.digits.size() > 0 && ans.digits.back() == 0) ans.digits.pop_back();
        if (ans.digits.size() == 0) {ans.positiv = true;ans.digits.push_back(0);}
        *this = ans;
        return (*this);
    }
    BigInteger &operator%= (const BigInteger& x) {
        BigInteger ans;
        ans.digits.resize(digits.size());
        BigInteger cur;
        for (int i = digits.size() - 1;i >= 0;i--)
        {
            cur.digits.insert(cur.digits.begin(),0);
            while (cur.digits.size() > 0 && cur.digits.back() == 0) cur.digits.pop_back();
            if (!cur.digits.size()) cur.digits.push_back(0);
            cur.digits[0] = digits[i];
            int nd = -1;
            int left = 0;
            int right = 9;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if ((x.abs() * mid).abs() <= cur.abs()) {
                    nd = mid;
                    left = mid + 1;
                }
                else right = mid - 1;
            }
            cur-=x.abs() * nd;
            ans.digits[i] = nd;
        }
        while (cur.digits.size() > 0 && cur.digits.back() == 0) cur.digits.pop_back();
        cur.positiv = positiv;
        if (!cur.digits.size()) {cur.positiv = true;cur.digits.push_back(0);}
        *this = cur;
        positiv = true;
        return (*this);
    }
    friend BigInteger operator+ (const BigInteger &x, const BigInteger &y) {
        BigInteger ans;
        ans = x;
        ans+=y;
        return ans;
    }
    BigInteger operator- () {
        BigInteger ans;
        ans = (*this);
        if (ans == 0) return ans;
        ans.positiv = (!ans.positiv);
        return ans;
    }
    friend BigInteger operator- (const BigInteger &x, const BigInteger &y) {
        BigInteger ans;
        ans = x;
        ans-=y;
        return ans;
    }
    friend BigInteger operator* (const BigInteger &x, const BigInteger &y) {
        BigInteger ans;
        ans = x;
        ans*=y;
        return ans;
    }
    friend BigInteger operator/ (const BigInteger &x, const BigInteger &y) {
        BigInteger ans;
        ans = x;
        ans/=y;
        return ans;
    }
    friend BigInteger operator% (const BigInteger &x, const BigInteger &y) {
        BigInteger ans;
        ans = x;
        ans%=y;
        return ans;
    }
    BigInteger operator--() {
        *this-=1;
        return *this;
    }
    BigInteger operator++() {
        *this+=1;
        return *this;
    }
    BigInteger operator--(int) {
        BigInteger ans = (*this);
        --(*this);
        return ans;
    }
    BigInteger operator++(int) {
        BigInteger ans = (*this);
        ++(*this);
        return ans;
    }
    friend std::istream& operator>>(std::istream &in, BigInteger &x) {
        std::string S;
        in >> S;
        x = BigInteger(S);
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const BigInteger &x) {
        out << x.toString();
        return out;
    }
};
BigInteger gcd (BigInteger a,BigInteger b) {
    if (!b) return a;
    else return gcd(b, a % b);
}
class Rational {
private :
    BigInteger ch;
    BigInteger znam;
    bool positiv = true;
public :
    Rational() {
        positiv = true;
        ch = 0;
        znam = 1;
    };
    Rational (BigInteger x) {
        positiv = (x >= 0);
        ch = x;
        znam = 1;
    }
    Rational (BigInteger x,BigInteger y) {
        ch = x;
        znam = y;
        if (znam < 0) {
            ch = (-ch);
            znam = (-znam);
        }
    }
    Rational (int x) {
        positiv = (x >= 0);
        ch = x;
        znam = 1;
    }
    Rational (int x,int y) {
        positiv = (x >= 0);
        ch = x;
        znam = y;
        if (znam < 0) {
            ch = (-ch);
            znam = (-znam);
        }
    }
    Rational &operator+= (const Rational& x) {
        if (x.positiv == positiv) {
            Rational ans;
            ans.positiv = positiv;
            ans.znam = (znam * x.znam) / gcd(znam,x.znam);
            ans.ch = (ch * (ans.znam / znam)) + (x.ch * (ans.znam / x.znam));
            *this = ans;
            return (*this);
        }
        else {
            Rational ans;
            ans.znam = (znam * x.znam) / gcd(znam,x.znam);
            ans.ch = (ch * (ans.znam / znam) + (x.ch * (ans.znam / x.znam)));
            *this = ans;
            return (*this);
        }
    }
    Rational &operator-= (const Rational& x) {
        Rational ans;
        ans.znam = (znam * x.znam) / gcd(znam,x.znam);
        ans.ch = (ch * (ans.znam / znam) - (x.ch * (ans.znam / x.znam)));
        *this = ans;
        return (*this);
    }
    Rational &operator*= (const Rational& x) {
        Rational ans;
        ans.ch = ch * x.ch;
        ans.znam = znam * x.znam;
        BigInteger zv = gcd(ans.ch,ans.znam);
        ans.ch/=zv;
        ans.znam/=zv;
        *this = ans;
        return (*this);
    }
    Rational &operator/= (const Rational& x) {
        Rational av;
        av = x;
        std::swap(av.ch,av.znam);
        return (*this*=av);
    }
    friend Rational operator+ (const Rational& x,const Rational& y) {
        Rational ans = x;
        ans+=y;
        return ans;
    }
    friend Rational operator- (const Rational& x,const Rational& y) {
        Rational ans = x;
        ans-=y;
        return ans;
    }
    friend Rational operator* (const Rational& x,const Rational& y) {
        Rational ans = x;
        ans*=y;
        return ans;
    }
    friend Rational operator/ (const Rational& x,const Rational& y) {
        Rational ans = x;
        ans/=y;
        return ans;
    }
    bool operator< (const Rational& x) const{
        Rational ans = (*this - x);
        if (ans.ch > 0) return false;
        else return true;
    }
    bool operator> (const Rational& x) const{
        Rational ans = (*this - x);
        if (ans.ch > 0) return true;
        else return false;
    }
    bool operator>= (const Rational& x) const{
        Rational ans = (*this - x);
        if (ans.ch >= 0) return true;
        else return false;
    }
    bool operator<= (const Rational& x) const{
        Rational ans = (*this - x);
        if (ans.ch <= 0) return true;
        else return false;
    }
    bool operator== (const Rational& x) const{
        Rational ans = (*this - x);
        if (ans.ch == 0) return true;
        else return false;
    }
    bool operator!= (const Rational& x) const{
        Rational ans = (*this - x);
        if (ans.ch == 0) return false;
        else return true;
    }
    std::string toString() const {
        std::string ans = "";
        ans+=ch.toString();
        ans+='/';
        ans+=znam.toString();
        return ans;
    }
    Rational operator-() {
        ch = -ch;
        return (*this);
    }
    std::string asDecimal(size_t precision = 0) {
        std::string ans = "";
        Rational vm = (*this);
        if (vm.ch < 0) {
            ans+='-';
            vm.ch = vm.ch.abs();
        }
        BigInteger cm = vm.ch / vm.znam;
        BigInteger ham = vm.ch % vm.znam;
        ans+=cm.toString();
        ans+='.';
        for (size_t i = 0;i < precision;i++)
        {
            if (ham == 0) {
                ans+='0';
            }
            else {
                ham*=10;
                int left = 0;
                int right = 9;
                int nd = -1;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if ((mid * vm.znam) <= ham) {
                        nd = mid;
                        left = mid + 1;
                    }
                    else right = mid - 1;
                }
                ans+=(char)((nd)+'0');
                ham-=(nd * vm.znam);
            }
        }
        return ans;
    }
    explicit operator double() {
        std::string am = asDecimal(15);
        return atof(am.c_str());
    }
};
inline BigInteger binpow (BigInteger n,BigInteger m) {
    BigInteger ans = 1;
    while (m > 0) {
        if (m % 2) ans*=n;
        n*=n;
        m/=2;
    }
    return ans;
}




int32_t n;
pll a[(int32_t)(1e6) + 1];
inline void init() {
    std::cin>>n;
    for (int32_t i = 0;i < n;i++)
        std::cin>>a[i].first>>a[i].second;
}
int ans = 0;
inline void output() {
    std::cout<<ans;
    exit(0);
}
 
inline void solve() {
    for (int32_t i = 0;i < n;i++)
    {
        for (int32_t j = i + 1;j < n;j++)
        {
            if (a[i].first == a[j].first || a[i].first == a[j].second || a[i].second == a[j].first || a[i].second == a[j].second) ++ans;
        }
    }
}
 
int32_t main() {




int m;
m = 10;
m-=9;
while (m--)
{
    init();
    solve();
    output();
}
}
