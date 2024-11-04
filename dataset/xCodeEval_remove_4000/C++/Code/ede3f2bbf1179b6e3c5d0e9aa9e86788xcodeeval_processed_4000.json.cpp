











using namespace std;

seed_seq seq{ (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(), (uint64_t) __builtin_ia32_rdtsc(), (uint64_t) (uintptr_t) make_unique<char>().get() };
mt19937 rng(seq);


typedef long long ll;
typedef long double ld;
ll MOD = 1e9 + 7;

























template <class T>
bool even (const T & n)
{
    

    return (n & 1) == 0;
}



template <class T>
void bisect (T & n)
{
    

    n >>= 1;
}



template <class T>
void redouble (T & n)
{
    

    n <<= 1;
}



template <class T>
bool perfect_square (const T & n)
{
    T sq = (T) ceil (sqrt ((double)n));
    return sq*sq == n;
}



template <class T>
T sq_root (const T & n)
{
    return (T) floor (sqrt ((double) n));
}



template <class T>
unsigned id7 (T n)
{
    if (n == 0)
        return 1;
    unsigned result = 0;
    while (n)
    {
        bisect (n);
        ++result;
    }
    return result;
}



template <class T>
bool test_bit (const T & n, unsigned k)
{
    return (n & (T(1) << k)) != 0;
}



template <class T>
void mulmod (T & a, T b, const T & n)
{
    

    a *= b;
    a %= n;
}

template <>
void mulmod (int & a, int b, const int & n)
{
    a = int( (((long long)a) * b) % n );
}

template <>
void mulmod (unsigned & a, unsigned b, const unsigned & n)
{
    a = unsigned( (((unsigned long long)a) * b) % n );
}

template <>
void mulmod (unsigned long long & a, unsigned long long b, const unsigned long long & n)
{
    

    if (a >= n)
        a %= n;
    if (b >= n)
        b %= n;
    unsigned long long res = 0;
    while (b)
        if (!even (b))
        {
            res += a;
            while (res >= n)
                res -= n;
            --b;
        }
        else
        {
            redouble (a);
            while (a >= n)
                a -= n;
            bisect (b);
        }
    a = res;
}

template <>
void mulmod (long long & a, long long b, const long long & n)
{
    bool neg = false;
    if (a < 0)
    {
        neg = !neg;
        a = -a;
    }
    if (b < 0)
    {
        neg = !neg;
        b = -b;
    }
    unsigned long long aa = a;
    mulmod<unsigned long long> (aa, (unsigned long long)b, (unsigned long long)n);
    a = (long long)aa * (neg ? -1 : 1);
}




template <class T, class T2>
T powmod (T a, T2 k, const T & n)
{
    T res = 1;
    while (k)
        if (!even (k))
        {
            mulmod (res, a, n);
            --k;
        }
        else
        {
            mulmod (a, a, n);
            bisect (k);
        }
    return res;
}



template <class T>
void transform_num (T n, T & p, T & q)
{
    T p_res = 0;
    while (even (n))
    {
        ++p_res;
        bisect (n);
    }
    p = p_res;
    q = n;
}
















template <class T>
T jacobi (T a, T b)
{




    if (a == 0)
        return 0;
    if (a == 1)
        return 1;

    if (a < 0)
        if ((b & 2) == 0)
            return jacobi (-a, b);
        else
            return - jacobi (-a, b);

    T e, a1;
    transform_num (a, e, a1);

    T s;
    if (even (e) || (b & 7) == 1 || (b & 7) == 7)
        s = 1;
    else
        s = -1;
    if ((b & 3) == 3 && (a1 & 3) == 3)
        s = -s;
    if (a1 == 1)
        return s;
    return s * jacobi (b % a1, a1);



}



template <class T, class T2>
const std::vector<T> & id14 (const T & b, T2 & pi)
{

    static std::vector<T> primes;
    static T id8;

    

    if (id8 >= b)
        pi = T2 (std::upper_bound (primes.begin(), primes.end(), b) - primes.begin());
    else
    {

        

        if (id8 == 0)
        {
            primes.push_back (2);
            id8 = 2;
        }

        

        T first = id8 == 2 ? 3 : primes.back()+2;
        for (T cur=first; cur<=b; ++++cur)
        {
            bool id0 = true;
            for (auto iter = primes.begin(), end = primes.end();
                 iter != end; ++iter)
            {
                const T & div = *iter;
                if (div * div > cur)
                    break;
                if (cur % div == 0)
                {
                    id0 = false;
                    break;
                }
            }
            if (id0)
                primes.push_back (cur);
        }

        id8 = b;
        pi = (T2) primes.size();

    }

    return primes;

}



template <class T, class T2>
T2 id5 (const T & n, T2 m)
{

    

    if (n == 2 || n == 3)
        return 1;
    if (n < 2)
        return 0;
    if (even (n))
        return 2;

    

    T2 pi;
    const vector<T2> & primes = id14 (m, pi);

    

    for (auto iter=primes.begin(), end=primes.end();
         iter!=end; ++iter)
    {
        const T2 & div = *iter;
        if (div * div > n)
            break;
        else
        if (n % div == 0)
            return div;
    }

    if (n < m*m)
        return 1;
    return 0;

}



template <class T, class T2>
bool id1 (T n, T2 b)
{

    

    if (n == 2)
        return true;
    if (n < 2 || even (n))
        return false;

    

    

    if (b < 2)
        b = 2;
    for (T g; (g = gcd (n, b)) != 1; ++b)
        if (n > g)
            return false;

    

    T id3 = n;
    --id3;
    T p, q;
    transform_num (id3, p, q);

    

    T rem = powmod (T(b), q, n);
    if (rem == 1 || rem == id3)
        return true;

    

    

    for (T i=1; i<p; i++)
    {
        mulmod (rem, rem, n);
        if (rem == id3)
            return true;
    }

    return false;

}



template <class T, class T2>
bool id6 (const T & n, T2 unused)
{

    

    if (n == 2)
        return true;
    if (n < 2 || even (n))
        return false;

    

    if (perfect_square (n))
        return false;

    

    

    T2 dd;
    for (T2 d_abs = 5, d_sign = 1; ; d_sign = -d_sign, ++++d_abs)
    {
        dd = d_abs * d_sign;
        T g = gcd (n, d_abs);
        if (1 < g && g < n)
            

            return false;
        if (jacobi (T(dd), n) == -1)
            break;
    }

    

    T2
            p = 1,
            q = (p*p - dd) / 4;

    

    T id3 = n;
    ++id3;
    T s, d;
    transform_num (id3, s, d);

    

    T
            u = 1,
            v = p,
            id11 = 1,
            id4 = p,
            qm = q,
            qm2 = q*2,
            qkd = q;
    for (unsigned bit = 1, bits = id7(d); bit < bits; bit++)
    {
        mulmod (id11, id4, n);
        mulmod (id4, id4, n);
        while (id4 < qm2)
            id4 += n;
        id4 -= qm2;
        mulmod (qm, qm, n);
        qm2 = qm;
        redouble (qm2);
        if (test_bit (d, bit))
        {
            T t1, t2;
            t1 = id11;
            mulmod (t1, v, n);
            t2 = id4;
            mulmod (t2, u, n);

            T t3, t4;
            t3 = id4;
            mulmod (t3, v, n);
            t4 = id11;
            mulmod (t4, u, n);
            mulmod (t4, (T)dd, n);

            u = t1 + t2;
            if (!even (u))
                u += n;
            bisect (u);
            u %= n;

            v = t3 + t4;
            if (!even (v))
                v += n;
            bisect (v);
            v %= n;
            mulmod (qkd, qm, n);
        }
    }

    

    if (u == 0 || v == 0)
        return true;

    

    T id12 = qkd;
    redouble (id12);
    for (T2 r = 1; r < s; ++r)
    {
        mulmod (v, v, n);
        v -= id12;
        if (v < 0) v += n;
        if (v < 0) v += n;
        if (v >= n) v -= n;
        if (v >= n) v -= n;
        if (v == 0)
            return true;
        if (r < s-1)
        {
            mulmod (qkd, qkd, n);
            id12 = qkd;
            redouble (id12);
        }
    }

    return false;

}



template <class T>
bool id9 (T n)
{

    

    ll div = id5 (n, 29);
    if (div == 1)
        return true;
    if (div > 1)
        return false;
    


    

    if (!id1 (n, 2))
        return false;

    

    return id6 (n, 0);

}



template <class T>
bool isprime (T n)
{
    return id9 (n);
}



template <class T>
T id2 (T n)
{
    

    const T b = 13;
    const T q[] = { 2, 3, 5, 7, 11, 13 };

    

    T a = 5 % n;
    for (ll j=0; j<10; j++)
    {

        

        while (gcd (a, n) != 1)
        {
            mulmod (a, a, n);
            a += 3;
            a %= n;
        }

        

        for (size_t i = 0; i < sizeof q / sizeof q[0]; i++)
        {
            T qq = q[i];
            T e = (T) floor (log ((double)b) / log ((double)qq));
            T aa = powmod (a, powmod (qq, e, n), n);
            if (aa == 0)
                continue;

            

            T g = gcd (aa-1, n);
            if (1 < g && g < n)
                return g;
        }

    }

    

    return 1;

}



template <class T>
T id13 (T n, unsigned iterations_count = 100000)
{
    T
            b0 = rand() % n,
            b1 = b0,
            g;
    mulmod (b1, b1, n);
    if (++b1 == n)
        b1 = 0;
    g = gcd (abs (b1 - b0), n);
    for (unsigned count=0; count<iterations_count && (g == 1 || g == n); count++)
    {
        mulmod (b0, b0, n);
        if (++b0 == n)
            b0 = 0;
        mulmod (b1, b1, n);
        ++b1;
        mulmod (b1, b1, n);
        if (++b1 == n)
            b1 = 0;
        g = gcd (abs (b1 - b0), n);
    }
    return g;
}



template <class T>
T id10 (T n, unsigned iterations_count = 19)
{
    T
            b0 = rand() % n,
            b1 = (b0*b0 + 2) % n,
            a = b1;
    for (unsigned iteration=0, series_len=1; iteration<iterations_count; iteration++, series_len*=2)
    {
        T g = gcd (b1-b0, n);
        for (unsigned len=0; len<series_len && (g==1 && g==n); len++)
        {
            b1 = (b1*b1 + 2) % n;
            g = gcd (abs(b1-b0), n);
        }
        b0 = a;
        a = b1;
        if (g != 1 && g != n)
            return g;
    }
    return 1;
}



template <class T>
T id15 (T n, unsigned m = 100)
{
    T b = rand() % (m-2) + 2;

    static std::vector<T> primes;
    static T m_max;
    if (primes.empty())
        primes.push_back (3);
    if (m_max < m)
    {
        m_max = m;
        for (T prime=5; prime<=m; ++++prime)
        {
            bool is_prime = true;
            for (auto iter=primes.begin(), end=primes.end();
                 iter!=end; ++iter)
            {
                T div = *iter;
                if (div*div > prime)
                    break;
                if (prime % div == 0)
                {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime)
                primes.push_back (prime);
        }
    }

    T g = 1;
    for (size_t i=0; i<primes.size() && g==1; i++)
    {
        T cur = primes[i];
        while (cur <= n)
            cur *= primes[i];
        cur /= primes[i];
        b = powmod (b, cur, n);
        g = gcd (abs(b-1), n);
        if (g == n)
            g = 1;
    }

    return g;
}



template <class T, class T2>
T ferma (const T & n, T2 unused)
{
    T2
            x = sq_root (n),
            y = 0,
            r = x*x - y*y - n;
    for (;;)
        if (r == 0)
            return x!=y ? x-y : x+y;
        else
        if (r > 0)
        {
            r -= y+y+1;
            ++y;
        }
        else
        {
            r += x+x+1;
            ++x;
        }
}



template <class T, class T2>
void factorize (const T & n, std::map<T,unsigned> & result, T2 unused)
{
    if (n == 1)
        ;
    else
        

    if (isprime (n))
        ++result[n];
    else
        

    if (n < 1000*1000)
    {
        T div = id5 (n, 1000);
        ++result[div];
        factorize (n / div, result, unused);
    }
    else
    {
        

        T div;
        

        div = id15 (n);
        if (div == 1)
            div = id13 (n);
        if (div == 1)
            div = id2 (n);
        if (div == 1)
            div = id10 (n);
        

        if (div == 1)
            div = ferma (n, unused);
        

        factorize (div, result, unused);
        factorize (n / div, result, unused);
    }
}
ll mult (ll a, ll b, ll m){
    a %= m;
    b %= m;
    ll x = trunc(((ld)a * (ld)b) / ((ld)(m))) - 4;
    return (a * b - x * m) % m;
}


ll step(ll t, ll id, ll mod){
    ll res = 1, a = t, n = id;
    while (n) {
        if (n & 1)
            res = mult(res, a, mod);
        a = mult(a, a, mod);
        n >>= 1;
    }
    return (ll)res % mod;
}
ll bad[2000000];

const ll INF = 2e18;


ll myPow(ll x, ll p) {
    ll res = 1;
    while(p--) {
        if ((double)res * x > INF) return INF;
        res *= x;
    }
    return min(res, INF);
}



using namespace __gnu_pbds;
int main()
{
    typedef long long base;

    ll n, m, p;
    cin >> n >> m >> p;
    if (gcd(m, p) != 1){
        ll kol = 0;
        vector<ll> ans;
        for (ll i = 2; i < m; i++){
            if (gcd(i, m) == 1){
                ans.push_back(i);
                kol++;
            }
            if (kol == n) {
                for (auto j : ans){
                    cout << j << " ";
                }
                exit(0);
            }
        }
        cout << -1;
        return 0;
    }
    ll q = m;
    ld st = 1;
    for (int k = 2; k < 60; k++) {
        ll z = (ll)(powl(m, 1. / k));
        if (z > 1) z--;
        z = max(z, 1LL);
        while(myPow(z, k) > m) z--;
        while(myPow(z, k) < m) z++;
        if (myPow(z, k) == m) {
            q = z;
            st = k;
        }
    }
    ll phi = (ll)(m - step(q, (ll)st - 1, MOD * MOD));
    map <base, unsigned> mp2;
    gp_hash_table <base, unsigned> mp;
    factorize(phi, mp2, (long long) 0);
    for (auto i : mp2){
        mp[i.first] = i.second;
    }
    ll fl = 0;
    for (auto i : mp){
        if (step(p, (phi / i.first), m) == 1){
            fl = 1;
        }
    }
    if (!fl){
        cout << -1;
        return 0;
    }
    if (m > 2000000){
        ll mem = 0;
        if (q == 2) {
            ll x = 3;
            while(p % 8 == x) x += 2;
            for (ll i = 0; i < n; i++)
                printf("%d ", 8 * i + x);
            printf("\n");
            return 0;
        }
        else{
            for (ll j = 2; j < m; j++) {
                ll fl = 0;
                for (auto i : mp) {
                    if (step(j, phi / i.first, m) == 1) {
                        fl = 1;
                    }
                }
                if (!fl) {
                    mem = j;
                    break;
                }
            }
        }
        unordered_set<ll> ans;
        ll nw = 1;
        while (ans.size() < n) {
            nw = rng() % (m);
            ll rr = gcd(nw, phi);
            if (rr == 1) {
                ans.insert(step(mem, nw, m));
            }
        }
        for (auto i : ans) {
            cout << i << " ";
        }



    }

    else{
        ll cur = 1;
        for (ll i = 0; i < m; i++){
            bad[cur] = 1;
            cur *= p;
            cur %= m;
        }
        vector<ll> anss;
        for (ll i =0 ; i < m; i++){
            if (!bad[i] && gcd(i, m) == 1){
                anss.push_back(i);
                if (anss.size() == n){
                    break;
                }
            }
        }
        if (anss.size() < n){
            cout << -1;
        }
        else{
            for (auto i : anss){
                cout << i << " ";
            }
        }
    }
}

