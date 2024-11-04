MOD = int(1e9) + 7
INF = 0x3f3f3f3f
INFF = 0x3f3f3f3f3f3f3f3f
EPS = 1e-9
OO = 1e20
PI = acos(-1.0)

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def checkMin(a, b):
    return b < a

def checkMax(a, b):
    return a < b

def checkUpd(a, b, c):
    return c(b, a)

def min(a, b, c):
    return min(min(a, b), c)

def max(a, b, c):
    return max(max(a, b), c)

def min(a, b, c, d):
    return min(min(a, b), min(c, d))

def max(a, b, c, d):
    return max(max(a, b), max(c, d))

def min(a, b, c, d, e):
    return min(min(min(a,b),min(c,d)),e)

def max(a, b, c, d, e):
    return max(max(max(a,b),max(c,d)),e)

def sqr(a):
    return a*a

def cub(a):
    return a*a*a

def ceil(x, y):
    return (x - 1) / y + 1

def abs(x):
    return x if x > 0 else -x

def sgn(x):
    return -1 if x < -EPS else 1 if x > EPS else 0

def cos(a, b, c):
    return (sqr(a)+sqr(b)-sqr(c))/(2*a*b)

def cot(x):
    return 1./tan(x)

def sec(x):
    return 1./cos(x)

def csc(x):
    return 1./sin(x)

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

def pdt(a, b, c, d):
    return pdt(pdt(a, b), pdt(c, d))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

class Int:
    def __init__(self, val):
        self.val = val % MOD
        if self.val < 0:
            self.val += MOD

    def __iadd__(self, rhs):
        self.val += rhs
        if self.val >= MOD:
            self.val -= MOD
        return self

    def __add__(self, rhs):
        return sum(self.val, rhs)

    def __isub__(self, rhs):
        self.val -= rhs
        if self.val < 0:
            self.val += MOD
        return self

    def __sub__(self, rhs):
        return dff(self.val, rhs)

    def __imul__(self, rhs):
        self.val = (self.val * rhs) % MOD
        return self

    def __mul__(self, rhs):
        return pdt(self.val, rhs)

    def __idiv__(self, rhs):
        self.val = (self.val * _I(rhs)) % MOD
        return self

    def __div__(self, rhs):
        return qtt(self.val, rhs)

    def __neg__(self):
        return MOD - self.val

def reverse_bits(x):
    x = ((x >> 1) & 0x5555555555555555) | ((x << 1) & 0xaaaaaaaaaaaaaaaa)
    x = ((x >> 2) & 0x3333333333333333) | ((x << 2) & 0xcccccccccccccccc)
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0f) | ((x << 4) & 0xf0f0f0f0f0f0f0f0)
    x = ((x >> 8) & 0x00ff00ff00ff00ff) | ((x << 8) & 0xff00ff00ff00ff00)
    x = ((x >>16) & 0x0000ffff0000ffff) | ((x <<16) & 0xffff0000ffff0000)
    x = ((x >>32) & 0x00000000ffffffff) | ((x <<32) & 0xffffffff00000000)
    return x

def clz(x):
    return __builtin_clz(x)

def clz(x):
    return __builtin_clzll(x)

def ctz(x):
    return __builtin_ctz(x)

def ctz(x):
    return __builtin_ctzll(x)

def lg2(x):
    return -1 if not x else 31 - clz(x)

def lg2(x):
    return -1 if not x else 63 - clz(x)

def low_idx(x):
    return -1 if not x else ctz(x)

def low_idx(x):
    return -1 if not x else ctz(x)

def high_idx(x):
    return lg2(x)

def high_idx(x):
    return lg2(x)

def parity(x):
    return __builtin_parity(x)

def parity(x):
    return __builtin_parityll(x)

def count_bits(x):
    return __builtin_popcount(x)

def count_bits(x):
    return __builtin_popcountll(x)

def lcm(a, b):
    return a*b/gcd(a,b)

def INC(a, b):
    a += b
    if a >= MOD:
        a -= MOD

def DEC(a, b):
    a -= b
    if a < 0:
        a += MOD

def MUL(a, b):
    a = (a * b) % MOD

def RDD():
    while True:
        c = getchar()
        if c == '-' or c.isdigit():
            break
    if c == '-':
        x = 0
        while True:
            c = getchar()
            if not c.isdigit():
                break
            x = x * 10 + ord(c) - ord('0')
        return '0' - x
    else:
        x = ord(c) - ord('0')
        while True:
            c = getchar()
            if not c.isdigit():
                break
            x = x * 10 + ord(c) - ord('0')
        return x

def RF():
    while True:
        c = getchar()
        if c == '-' or c == '.' or c.isdigit():
            break
    if c == '-':
        if getchar() == '.':
            x = 0
            l = 1
            while True:
                c = getchar()
                if not c.isdigit():
                    break
                x = x * 10 + ord(c) - ord('0')
                l *= 10
            return 0.0 - x / l
        else:
            x = 0
            while True:
                c = getchar()
                if not c.isdigit():
                    break
                x = x * 10 + ord(c) - ord('0')
            return '0' - x
    else:
        if c == '.':
            x = 0
            l = 1
            while True:
                c = getchar()
                if not c.isdigit():
                    break
                x = x * 10 + ord(c) - ord('0')
                l *= 10
            return x / l
        else:
            x = ord(c) - ord('0')
            while True:
                c = getchar()
                if not c.isdigit():
                    break
                x = x * 10 + ord(c) - ord('0')
            return x

def RS(s):
    return scanf("%s", s)

def RD(x):
    c = getchar()
    while not c.isdigit():
        c = getchar()
    x = ord(c) - ord('0')
    while True:
        c = getchar()
        if not c.isdigit():
            break
        x = x * 10 + ord(c) - ord('0')
    return x

def RDD(x):
    c = getchar()
    while c != '-' and not c.isdigit():
        c = getchar()
    if c == '-':
        x = 0
        while True:
            c = getchar()
            if not c.isdigit():
                break
            x = x * 10 + ord(c) - ord('0')
        return '0' - x
    else:
        x = ord(c) - ord('0')
        while True:
            c = getchar()
            if not c.isdigit():
                break
            x = x * 10 + ord(c) - ord('0')
        return x

def RS(s):
    return scanf("%s", s)

def reverse_bits(x):
    x = ((x >> 1) & 0x5555555555555555) | ((x << 1) & 0xaaaaaaaaaaaaaaaa)
    x = ((x >> 2) & 0x3333333333333333) | ((x << 2) & 0xcccccccccccccccc)
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0f) | ((x << 4) & 0xf0f0f0f0f0f0f0f0)
    x = ((x >> 8) & 0x00ff00ff00ff00ff) | ((x << 8) & 0xff00ff00ff00ff00)
    x = ((x >>16) & 0x0000ffff0000ffff) | ((x <<16) & 0xffff0000ffff0000)
    x = ((x >>32) & 0x00000000ffffffff) | ((x <<32) & 0xffffffff00000000)
    return x

def clz(x):
    return __builtin_clz(x)

def clz(x):
    return __builtin_clzll(x)

def ctz(x):
    return __builtin_ctz(x)

def ctz(x):
    return __builtin_ctzll(x)

def lg2(x):
    return -1 if not x else 31 - clz(x)

def lg2(x):
    return -1 if not x else 63 - clz(x)

def low_idx(x):
    return -1 if not x else ctz(x)

def low_idx(x):
    return -1 if not x else ctz(x)

def high_idx(x):
    return lg2(x)

def high_idx(x):
    return lg2(x)

def parity(x):
    return __builtin_parity(x)

def parity(x):
    return __builtin_parityll(x)

def count_bits(x):
    return __builtin_popcount(x)

def count_bits(x):
    return __builtin_popcountll(x)

def lcm(a, b):
    return a*b/gcd(a,b)

def INC(a, b):
    a += b
    if a >= MOD:
        a -= MOD

def DEC(a, b):
    a -= b
    if a < 0:
        a += MOD

def MUL(a, b):
    a = (a * b) % MOD

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def RDD():
    while True:
        c = getchar()
        if c == '-' or c.isdigit():
            break
    if c == '-':
        x = 0
        while True:
            c = getchar()
            if not c.isdigit():
                break
            x = x * 10 + ord(c) - ord('0')
        return '0' - x
    else:
        x = ord(c) - ord('0')
        while True:
            c = getchar()
            if not c.isdigit():
                break
            x = x * 10 + ord(c) - ord('0')
        return x

def RF():
    while True:
        c = getchar()
        if c == '-' or c == '.' or c.isdigit():
            break
    if c == '-':
        if getchar() == '.':
            x = 0
            l = 1
            while True:
                c = getchar()
                if not c.isdigit():
                    break
                x = x * 10 + ord(c) - ord('0')
                l *= 10
            return 0.0 - x / l
        else:
            x = 0
            while True:
                c = getchar()
                if not c.isdigit():
                    break
                x = x * 10 + ord(c) - ord('0')
            return '0' - x
    else:
        if c == '.':
            x = 0
            l = 1
            while True:
                c = getchar()
                if not c.isdigit():
                    break
                x = x * 10 + ord(c) - ord('0')
                l *= 10
            return x / l
        else:
            x = ord(c) - ord('0')
            while True:
                c = getchar()
                if not c.isdigit():
                    break
                x = x * 10 + ord(c) - ord('0')
            return x

def RS(s):
    return scanf("%s", s)

def RD(x):
    c = getchar()
    while not c.isdigit():
        c = getchar()
    x = ord(c) - ord('0')
    while True:
        c = getchar()
        if not c.isdigit():
            break
        x = x * 10 + ord(c) - ord('0')
    return x

def RDD(x):
    c = getchar()
    while c != '-' and not c.isdigit():
        c = getchar()
    if c == '-':
        x = 0
        while True:
            c = getchar()
            if not c.isdigit():
                break
            x = x * 10 + ord(c) - ord('0')
        return '0' - x
    else:
        x = ord(c) - ord('0')
        while True:
            c = getchar()
            if not c.isdigit():
                break
            x = x * 10 + ord(c) - ord('0')
        return x

def RS(s):
    return scanf("%s", s)

def reverse_bits(x):
    x = ((x >> 1) & 0x5555555555555555) | ((x << 1) & 0xaaaaaaaaaaaaaaaa)
    x = ((x >> 2) & 0x3333333333333333) | ((x << 2) & 0xcccccccccccccccc)
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0f) | ((x << 4) & 0xf0f0f0f0f0f0f0f0)
    x = ((x >> 8) & 0x00ff00ff00ff00ff) | ((x << 8) & 0xff00ff00ff00ff00)
    x = ((x >>16) & 0x0000ffff0000ffff) | ((x <<16) & 0xffff0000ffff0000)
    x = ((x >>32) & 0x00000000ffffffff) | ((x <<32) & 0xffffffff00000000)
    return x

def clz(x):
    return __builtin_clz(x)

def clz(x):
    return __builtin_clzll(x)

def ctz(x):
    return __builtin_ctz(x)

def ctz(x):
    return __builtin_ctzll(x)

def lg2(x):
    return -1 if not x else 31 - clz(x)

def lg2(x):
    return -1 if not x else 63 - clz(x)

def low_idx(x):
    return -1 if not x else ctz(x)

def low_idx(x):
    return -1 if not x else ctz(x)

def high_idx(x):
    return lg2(x)

def high_idx(x):
    return lg2(x)

def parity(x):
    return __builtin_parity(x)

def parity(x):
    return __builtin_parityll(x)

def count_bits(x):
    return __builtin_popcount(x)

def count_bits(x):
    return __builtin_popcountll(x)

def lcm(a, b):
    return a*b/gcd(a,b)

def INC(a, b):
    a += b
    if a >= MOD:
        a -= MOD

def DEC(a, b):
    a -= b
    if a < 0:
        a += MOD

def MUL(a, b):
    a = (a * b) % MOD

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

def pdt(a, b, c, d):
    return pdt(pdt(a, b), pdt(c, d))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

def pdt(a, b, c, d):
    return pdt(pdt(a, b), pdt(c, d))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

def pdt(a, b, c, d):
    return pdt(pdt(a, b), pdt(c, d))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

def pdt(a, b, c, d):
    return pdt(pdt(a, b), pdt(c, d))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

def pdt(a, b, c, d):
    return pdt(pdt(a, b), pdt(c, d))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

def pdt(a, b, c, d):
    return pdt(pdt(a, b), pdt(c, d))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

def pdt(a, b, c, d):
    return pdt(pdt(a, b), pdt(c, d))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

def pdt(a, b, c, d):
    return pdt(pdt(a, b), pdt(c, d))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

def pdt(a, b, c, d):
    return pdt(pdt(a, b), pdt(c, d))

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    c = 1
    while b:
        if b&1:
            c *= a
        a *= a
        b >>= 1
    return c

def pow(a, b):
    return pow(a, b)

def DIV(a, b):
    a = (a * _I(b)) % MOD

def qtt(a, b):
    return pdt(a, _I(b))

def gcd(m, n, x, y):
    x = 1
    y = 0
    xx = 0
    yy = 1
    while True:
        q = m / n
        m %= n
        if not m:
            x = xx
            y = yy
            return n
        x -= q * xx
        y -= q * yy
        q = n / m
        n %= m
        if not n:
            return m
        xx -= q * x
        yy -= q * y

def sum(a, b):
    a += b
    if a >= MOD:
        a -= MOD
    return a

def dff(a, b):
    a -= b
    if a < 0:
        a += MOD
    return a

def pdt(a, b):
    return (a * b) % MOD

def sum(a, b, c):
    return sum(a, sum(b, c))

def sum(a, b, c, d):
    return sum(sum(a, b), sum(c, d))

def pdt(a, b, c):
    return pdt(a, pdt(b, c))

