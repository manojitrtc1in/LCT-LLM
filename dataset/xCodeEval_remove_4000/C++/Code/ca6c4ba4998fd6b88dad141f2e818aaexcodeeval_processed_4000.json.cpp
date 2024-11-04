




using namespace std;

class HI
{
    friend ostream &operator<<(ostream &, HI &);
    friend istream &operator>>(istream &, HI &);
    friend void id1(int n, HI &hi);
    friend void printHI(HI &);
    friend void id0(HI &hi);
    friend void clearHI(HI &hi);
    friend void swapHI(HI &a, HI &b);
public:
    HI maxHI(HI &a, HI &b);
    HI factHI(int b);
    HI sqrtHI(HI &hi);
    HI nokHI(HI a, HI b);
    HI nodHI(HI a, HI b);
    HI();
    HI(int a);
    HI(const char *, int);
    HI operator*=(HI &hi);
    HI operator+=(HI &hi);
    HI operator-=(HI &hi);
    HI operator/=(HI &hi);
    HI operator%=(HI &hi);
    HI operator^(int n);
    HI operator/(HI &);
    HI operator%(HI &);
    HI operator+(HI &);
    HI operator-(HI &);
    HI operator=(HI );
    HI operator=(int a);
    HI operator=(const char *);
    HI operator++();
    HI operator--();
    HI operator*(HI &);
    bool operator<=(HI &);
    bool operator!=(HI &);
    bool operator>=(HI &);
    bool operator<(HI &);
    bool operator==(HI &);
    bool operator>(HI &);
    int *ar, termInd;
    short zn;
    const int Sz;
    HI sub(HI &, HI&);
};

HI::HI():Sz(MAX)
{
    ar = new int [MAX];
    for(int i = 0; i < MAX; i++)
        ar[i] = 0;
    termInd = zn = 0;
}

HI::HI(int a):Sz(MAX)
{
    ar = new int [MAX];
    int i;
    for(i = 0; i < MAX; i++)
        ar[i] = 0;
    termInd = zn = 0;
    if(a < 0)
    {
        a *= -1;
        zn = 1;
    }
    if(a)
    {
        i = 0;
        while(a != 0)
        {
            ar[i] = a % 10;
            i++;
            a /= 10;
        }
        termInd = i;
    }
    else
        termInd++;
}

HI::HI(const char * ch, int arSz):Sz(arSz)
{
    zn = 0;
    int i, ln, jh;
    ln = strlen(ch);
    ar = new int [MAX];
    for(i = 0; i < MAX; i++)
        ar[i] = 0;
    if(ch[0] == '-')
    {
        zn = 1;
        ln--;
    }
    for (jh = 0; jh < Sz; jh++)
        ar[jh] = 0;
    for (i = ln - 1; i >= 0; i--)
        ar[ln - i - 1] = ch[i + zn] - '0';
    termInd = ln;
}



    HI art;
    char STR[MAX];



void printHI(HI &hi)
{
    id0(hi);
    int i = hi.termInd - 1;
    if(hi.zn == 1 && !(hi.termInd == 1 && hi.ar[0] == 0))
        printf("-");
    while (i >= 0)
        printf("%d", hi.ar[i--]);
}

void id0(HI &hi)
{
    while(hi.termInd > 0)
        if(hi.ar[hi.termInd - 1] == 0)
            hi.termInd--;
        else
            break;
    if(hi.termInd == 0)
        hi.termInd++;
}

void clearHI(HI &hi)
{
    int i;
    for(i = 0; i < hi.termInd; i++)
        hi.ar[i] = 0;
    hi.termInd = hi.zn = 0;
}

void swapHI(HI &a, HI &b)
{
    HI t;
    t = a;
    a = b;
    b = t;
}

void id1(int n, HI &hi)
{
    int i;
    hi.termInd += n;
    for(i = hi.termInd; i >= n; i--)
    {
        hi.ar[i] = hi.ar[i-n];
        hi.ar[i-n] = 0;
    }
    id0(hi);
}

ostream & operator<<(ostream &o, HI &hi)
{
    int i = hi.termInd - 1;
    if (i == -1)
        cout << 0;
    else if(hi.zn == 1)
        cout << "-";
    while (i >= 0)
        o << hi.ar[i--];
return o;
}

istream & operator>>(istream &o, HI &hi)
{
   cin >> STR;
   hi = STR;
   return o;
}

bool HI::operator==(HI &hi)
{
    if(zn != hi.zn)
        return false;
    int ind = termInd - 1;
    if (termInd == hi.termInd)
    {
        while (ar[ind] == hi.ar[ind])
        {
		    if (ind == 0)
                break;
		    ind--;
        }
        return ar[ind] == hi.ar[ind];
    }
    return false;
}

bool HI::operator!=(HI &hi)
{
    return !(*this == hi);
}

bool HI::operator>(HI &hi)
{
    if(*this == hi)
        return false;
    if(zn > hi.zn)
        return false;
    if(hi.zn > zn)
        return true;
    int ind = termInd - 1;
    if (termInd == hi.termInd)
    {
        while (ar[ind] == hi.ar[ind])
        {
            if (ind == 0)
                break;
		    ind--;
		}
		if(zn == 0)
            return ar[ind] > hi.ar[ind];
		else
            return !(ar[ind] > hi.ar[ind]);
    }
    if(zn == 0)
        return termInd > hi.termInd;
    else
        return !(termInd > hi.termInd);
}

bool HI::operator>=(HI &hi)
{
    bool t = *this > hi;
    if(t)
        return t;
    else
        return *this == hi;
}

bool HI::operator<(HI &hi)
{
    return !(*this >= hi);
}

bool HI::operator<=(HI &hi)
{
    return !(*this > hi);
}

HI HI::operator=(int a)
{
    clearHI(*this);
    int i = 0;
    if(a < 0)
    {
        a *= -1;
        zn = 1;
    }
    if(a)
    {
        while(a != 0)
        {
            ar[i] = a % 10;
            i++;
            a /= 10;
        }
        termInd = i;
    }
    else
        termInd++;
return *this;
}

HI HI::operator=(HI hi)
{
    int i = 0;
    *this = 0;
    while (i < hi.termInd)
        this->ar[i] = hi.ar[i++];
    termInd = hi.termInd;
    zn = hi.zn;
return *this;
}

HI HI::operator=(const char * ch)
{
    *this = 0;
    int ln, i;
    ln = strlen(ch);
    if(ch[0] == '-')
    {
        zn = 1;
        ln--;
    }
    for (i = ln - 1; i >= 0; i--)
        ar[ln - i - 1] = ch[i + zn] - '0';
    termInd = ln;
return *this;
}

HI HI::operator++()
{
    int i;
    if(zn == 1)
    {
        zn = 0;
        --(*this);
        zn = 1;
        if(termInd == 1 && ar[0] == 0)
            zn = 0;
        return *this;
    }
    ar[0]++;
    for(i = 0; i < termInd; i++)
        if(ar[i] > 9)
        {
            ar[i] = 0;
            ar[i + 1]++;
        }
        else
            break;
    if(ar[termInd] != 0)
        termInd++;
return *this;
}

HI HI::operator+(HI &hi)
{
    HI tm;
    if(zn == 1 && hi.zn == 1)
        tm.zn = 1;
    else if(zn == 0 && hi.zn == 1)
    {
        hi.zn = 0;
        tm = (*this - hi);
        hi.zn = 1;
        return tm;
    }
    else if(zn == 1 && hi.zn == 0)
    {
        zn = 0;
        tm = (hi - *this);
        zn = 1;
        return tm;
    }
    int t = 0, c = 0, tmp = termInd;
    if (tmp < hi.termInd)
        tmp = hi.termInd;
    while (t < tmp)
    {
        tm.ar[t] = (ar[t] + hi.ar[t] + c) % 10;
        c = (ar[t] + hi.ar[t] + c) / 10;
        t++;
    }
    if (c)
        tm.ar[t++] = c;
    tm.termInd = t;
return tm;
}

HI HI::operator+=(HI &hi)
{
    if(zn == 0 && hi.zn == 1)
    {
        hi.zn = 0;
        *this -= hi;
        hi.zn = 1;
        return *this;
    }
    else if(zn == 1 && hi.zn == 0)
    {
        zn = 0;
        *this -= hi;
        if(zn == 1)
            zn = 0;
        else
            zn = 1;
        return *this;
    }
    else if(zn == 1 && hi.zn == 1)
    {
        zn = 0;
        hi.zn = 0;
        *this += hi;
        zn = 1;
        hi.zn = 1;
        return *this;
    }
    int t = 0, c = 0, tmp = termInd, Tmp;
    if (tmp < hi.termInd)
        tmp = hi.termInd;
    while (t < tmp)
    {
         Tmp = ar[t];
         ar[t] = (ar[t] + hi.ar[t] + c) % 10;
         c = (Tmp + hi.ar[t] + c) / 10;
         t++;
    }
    if (c)
        ar[t++] += c;
    termInd = t;
return *this;
}

HI HI::operator--()
{
    int i, c;
    if(zn == 1)
    {
        zn = 0;
        ++(*this);
        zn = 1;
        if(termInd == 1 && ar[0] == 0)
            zn = 0;
        return *this;
    }
    ar[0]--;
    if(ar[0] == -1 && termInd == 1)
    {
        ar[0] = 1;
        zn = 1;
    }
    else if(ar[0] == -1)
    {
        for(i = 1; i < termInd; i++)
            if(ar[i] != 0)
                break;
        c = i;
        for(i = 1; i < c; i++)
            ar[i] = 9;
        ar[0] += 10;
        ar[c]--;
    }
    id0(*this);
return *this;
}

HI HI::operator-(HI &hi)
{
    HI t;
    t = sub(*this, hi);
return t;
}

HI HI::sub(HI &a, HI &b)
{
    HI t;
    if(a.zn == 1 && b.zn == 1)
    {
        zn = 0;
        b.zn = 0;
        t = sub(b,a);
        a.zn = b.zn = 1;
        return t;
    }
    else if(a.zn == 0 && b.zn == 1)
    {
        b.zn = 0;
        t = a + b;
        b.zn = 1;
        return t;
    }
    else if(a.zn == 1 && b.zn == 0)
    {
        a.zn = 0;
        t = a + b;
        a.zn = t.zn = 1;
        return t;
    }
    if(a == b)
    {
        t.termInd++;
        return t;
    }
    else if(a < b)
    {
        t = sub(b,a);
        t.zn = 1;
        return t;
    }
    int i, j;
    t = a;
    for(i = 0; i < b.termInd; i++)
        if(t.ar[i] >= b.ar[i]) t.ar[i] -= b.ar[i];
        else
        {
            for(j = i + 1; j < t.termInd; j++)
            {
                if(t.ar[j] != 0)
                    break;
                t.ar[j] = 9;
            }
            t.ar[j]--;
            t.ar[i] += 10;
            t.ar[i] -= b.ar[i];
        }
    id0(t);
return t;
}

HI HI::operator-=(HI &hi)
{
    if(zn == 0 && hi.zn == 1)
    {
        hi.zn = 0;
        *this += hi;
        hi.zn = 1;
        return *this;
    }
    else if(zn == 1 && hi.zn == 0)
    {
        zn = 0;
        *this += hi;
        zn = 1;
        return *this;
    }
    else if(zn == 1 && hi.zn == 1)
    {
        hi.zn = 0;
        *this += hi;
        hi.zn = 1;
        return *this;
    }
    if(hi > *this)
    {
        HI t;
        t = hi - *this;
        *this = t;
        zn = 1;
        return *this;
    }
    int i, k, c;
    for(i = 0; i < termInd; i++)
        if(ar[i] < hi.ar[i])
        {
            for(k = i + 1; k < termInd; k++)
                if(ar[k] != 0)
                    break;
            c = k;
            ar[c]--;
            for(k = c - 1; k > i; k--)
                ar[k] = 9;
            ar[i] += (10 - hi.ar[i]);
        }
        else
            ar[i] -= hi.ar[i];
    id0(*this);
return *this;
}

HI HI::operator/(HI &hi)
{
    HI t, tm;
    int i, h, g, q, q1;
    q = zn;
    q1 = hi.zn;
    zn = hi.zn = h = 0;
    for(i = termInd - 1; i >= 0; i--)
    {
        id1(1, t);
        t.ar[0] = ar[i];
        g = 0;
        while(true)
        {
            if(hi > t) break;
            g++;
            t -= hi;
        }
        if(h == 1 || g != 0)
        {
            h = 1;
            id0(t);
            id1(1, tm);
            tm.ar[0] = g;
        }
    }
    zn = q;
    hi.zn = q1;
    if(zn != hi.zn)
        tm.zn = 1;
return tm;
}

HI HI::operator/=(HI &hi)
{
    clearHI(art);
    art = 0;
    HI t;
    int i, h, g, q, q1;
    q = zn;
    q1 = hi.zn;
    zn = hi.zn = h = 0;
    for(i = termInd - 1; i >= 0; i--)
    {
        id1(1, t);
        t.ar[0] = ar[i];
        g = 0;
        while(true)
        {
            if(hi > t)
                break;
            g++;
            t -= hi;
        }
        if(h == 1 || g != 0)
        {
            h = 1;
            id0(t);
            id1(1, art);
            art.ar[0] = g;
        }
    }
    zn = q;
    hi.zn = q1;
    if(zn != hi.zn)
        art.zn = 1;
    id0(art);
    *this = art;
return *this;
}

HI HI::operator%(HI &hi)
{
    HI t;
    int i, q, q1;
    q = zn;
    q1 = hi.zn;
    zn = hi.zn = 0;
    for(i = termInd - 1; i >= 0; i--)
    {
        id1(1, t);
        t.ar[0] = ar[i];
        while(true)
        {
            if(hi > t)
                break;
            t -= hi;
        }
        id0(t);
    }
    zn = q;
    hi.zn = q1;
    id0(t);
return t;
}

HI HI::operator%=(HI &hi)
{
    art = 0;
    int i, q, q1;
    q = zn;
    q1 = hi.zn;
    zn = hi.zn = 0;
    for(i = termInd - 1; i >= 0; i--)
    {
        id1(1, art);
        art.ar[0] = ar[i];
        while(true)
        {
            if(hi > art)
                break;
            art -= hi;
        }
        id0(art);
    }
    zn = q;
    hi.zn = q1;
    id0(art);
    *this = art;
return *this;
}

HI HI::operator*(HI &hi)
{
    int i, j, c, tmp;
    i = j = c = tmp = 0;
    HI t;
    if(zn != hi.zn)
        t.zn = 1;
    for (i = 0; i < termInd; i++)
    {
        c = 0;
        for (j = 0; j < hi.termInd; j++)
        {
		    tmp = t.ar[i + j] + ar[i] * hi.ar[j] + c;
		    t.ar[i+j] = tmp % 10;
		    c = tmp / 10;
        }
        t.ar[i + hi.termInd] = c;
    }
    t.termInd = hi.termInd + termInd;
    if (!c)
        t.termInd--;
    id0(t);
return t;
}

HI HI::operator*=(HI &hi)
{
    art = 0;
    int i, j, c, tmp;
    i = j = c = tmp = 0;
    for (i = 0; i < termInd; i++)
    {
        c = 0;
        for (j = 0; j < hi.termInd; j++)
        {
		    tmp = art.ar[i + j] + ar[i] * hi.ar[j] + c;
		    art.ar[i + j] = tmp % 10;
		    c = tmp / 10;
        }
        art.ar[i + hi.termInd] = c;
    }
    if (c)
        art.termInd = hi.termInd + termInd;
    else
        art.termInd = hi.termInd + termInd - 1;
    id0(art);
    if(zn != hi.zn)
        art.zn = 1;
    *this = art;
return *this;
}

HI HI::operator^(int n)
{
    HI y = 1, x;
    x = *this;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            y *= x;
            n--;
        }
        n /= 2;
        x *= x;
    }
    if(zn == 1 && n % 2 == 1)
        y.zn = 1;
return y;
}

HI factHI(int b)
{
    int i, c, n;
    HI t = 1;
    n = b;
    for(b = 1; b <= n; b++)
    {
        c = 0;
        for(i = 0; i < t.termInd; i++)
        {
            t.ar[i] = t.ar[i] * b + c;
            c = t.ar[i] / 10;
            t.ar[i] %= 10;
        }
        if(c)
        {
            i = t.termInd;
            while(c != 0)
            {
                t.ar[i] = c % 10;
                i++;
                c /= 10;
            }
            t.termInd = i;
        }
    }
return t;
}


HI sqrtHI(HI &hi)
{
    HI T, tm, w = 0, r = 0, h2 = 2;
    int i, pt;
    pt = hi.termInd;
    if (hi.termInd % 2 > 0)
        pt++;
    pt--;
    while (pt >= 0)
    {
        id1(2, r);
        if(r.termInd == 1 && r.ar[0] == 0)
            r.termInd++;
        r.ar[0] = hi.ar[pt - 1];
        r.ar[1] = hi.ar[pt];
        id0(r);
        i = 0;
        w = tm;
        id1(1, w);
        w *= h2;
        while(true)
        {
            i++;
            ++w;
            T = i;
            T *= w;
            if(T > r)
                break;
        }
        i--;
        id1(1, tm);
        tm.ar[0] = i;
        --w;
        T = i;
        T *= w;
        r -= T;
        pt -= 2;
   }
   id0(tm);
return tm;
}

HI nodHI(HI a, HI b)
{
    if(b > a)
        swapHI(a, b);
    while(true)
    {
        a %= b;
        swapHI(a, b);
        if(b.termInd == 1 && b.ar[0] == 0)
            break;
    }
return a;
}

HI nokHI(HI a, HI b)
{
    HI t;
    HI nod;
    t = a * b;
    nod = nodHI(a, b);
    t /= nod;
return t;
}

HI maxHI(HI &a, HI &b)
{
    if(a > b)
        return a;
    else
        return b;
}

HI ans[5002], us[2002];

int main()
{




    char dd[7];
    int n, x, i, j, u[2002], b;
    HI now, xxx = 2, a;
    cin>> n;
    for (i=0; i<2002; i++)
        us[i] = -1;
    memset(u, false, sizeof(u));
    for (i=0; i<5002; i++)
        ans[i] = 0;
    for (i=1; i<=n; i++)
    {
        scanf("%s%d", dd, &x);
        if (dd[0] == 'w')
        {
            u[x] = true;
            if (us[x] < ans[i-1])
                us[x] = ans[i-1];
            ans[i] = ans[i-1];
            continue;
        }
        if (u[x])
        {
            now = 1;
            a = 2;
            b = x;
            while (b > 0)
            {
                if (b%2 == 1)
                    now *= a;
                a *= a;
                b >>= 1;
            }
            

            now += us[x];
            if (now < ans[i-1])
                ans[i] = ans[i-1];
            else
                ans[i] = now;
        }
        else
            ans[i] = ans[i-1];
    }
    cout<< ans[n];
    return 0;
}




