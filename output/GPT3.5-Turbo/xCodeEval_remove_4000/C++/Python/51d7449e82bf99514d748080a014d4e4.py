class Z:
    def __init__(self, x):
        self.x = x

    def __sub__(self, a):
        self.x -= a.x
        if self.x < 0:
            self.x += mod

    def __add__(self, a):
        self.x += a.x
        if self.x >= mod:
            self.x -= mod

    def __mul__(self, a):
        self.x = (self.x * a.x) % mod

    def __str__(self):
        return str(self.x)


def finv(x):
    if x.x < 2:
        return x
    return Z(mod - mod // x.x) * finv(Z(mod % x.x))


def fpow(a, b):
    s = Z(1)
    while b:
        if b & 1:
            s *= a
        a *= a
        b >>= 1
    return s


def init_inverse(n, inv):
    inv[0] = inv[1] = Z(1)
    for i in range(2, n):
        inv[i] = Z(mod - mod // i) * inv[mod % i]


def id0(n, fac, ifac):
    fac[0] = Z(1)
    init_inverse(n, ifac)
    for i in range(1, n):
        fac[i] = fac[i - 1] * Z(i)
        ifac[i] = ifac[i - 1] * ifac[i]


class FastDiv:
    def __init__(self, p):
        self.t = (1 << 64) // p
        self.i = mul_inv(p)

    def divide(self, n):
        return n * self.i <= self.t

    def divide(self, n):
        return abs(n) * self.i <= self.t

    def mul_inv(self, n):
        x = n
        for i in range(5):
            x *= 2 - n * x
        return x


class FastMod:
    def __init__(self, b):
        self.m = (1 << 64) // b
        self.b = b

    def reduce(self, a):
        q = (self.m * a) >> 64
        r = a - q * self.b
        return r - self.b if r >= self.b else r


class vector(list):
    def __init__(self, plain=[]):
        super().__init__(plain)

    def unique(self):
        self[:] = sorted(set(self))

    def concat(self, rhs):
        self.extend(rhs)

    def includes(self, x):
        return x in self

    def forEach(self, func):
        for item in self:
            func(item)

    def lower_bound(self, x):
        return bisect_left(self, x)

    def upper_bound(self, x):
        return bisect_right(self, x)

    def sort(self, func=None):
        self[:] = sorted(self, key=func)

    def slice(self, l, r):
        return vector(self[l:r])

    def from_set(self, src):
        self[:] = sorted(src)

    def _map(self, func):
        return vector(map(func, self))

    def map(self, func):
        return self._map(func)

    def __str__(self):
        return "[" + ",".join(map(str, self)) + "]"


class string(str):
    def __init__(self, plain=""):
        super().__init__(plain)

    def join(self, vet):
        return self.join(map(str, vet))

    def split(self, dim):
        return vector(self.split(dim))

    @staticmethod
    def format(fm, *args):
        return string(fm % args)


def to_string(x):
    return str(x)


def to_string(s):
    return s


def to_string(s):
    return s


def to_string(x):
    return str(x)


def to_string(ctn):
    return "[" + ",".join(map(to_string, ctn)) + "]"


def to_string(ctn):
    result = "{"
    flag = False
    for it in ctn:
        if flag:
            result += ","
        flag = True
        result += to_string(it)
    return result + "}"


def read_digit():
    x = getc()
    while not x.isdigit():
        x = getc()
    return int(x)


def read_alpha():
    x = getc()
    while not x.isalpha():
        x = getc()
    return x


def read_lower():
    x = getc()
    while not x.islower():
        x = getc()
    return x


def read_upper():
    x = getc()
    while not x.isupper():
        x = getc()
    return x


def read_digit():
    x = 0
    f = False
    c = getc()
    while not c.isdigit():
        f ^= c == '-'
        c = getc()
    while c.isdigit():
        x = x * 10 + ord(c) - ord('0')
        c = getc()
    if f:
        x = -x
    return x


def read(x):
    x = read_digit()


def read(x):
    x = read_alpha()


def read(x):
    x = read_lower()


def read(x):
    x = read_upper()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
    x = read_digit()


def read(x):
