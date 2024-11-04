class Field:
    def __init__(self, x=0):
        self.v = x % 1000000007

    def pow(self, p):
        return self ^ p

    def __pow__(self, p):
        r = 1
        e = self.v
        while p:
            if p & 1:
                r = (r * e) % 1000000007
            e = (e * e) % 1000000007
            p >>= 1
        return Field(r)

    def __iadd__(self, o):
        if self.v + o.v >= 1000000007:
            self.v += o.v - 1000000007
        else:
            self.v += o.v
        return self

    def __isub__(self, o):
        if self.v < o.v:
            self.v -= o.v - 1000000007
        else:
            self.v -= o.v
        return self

    def __imul__(self, o):
        self.v = (self.v * o.v) % 1000000007
        return self

    def __idiv__(self, o):
        return self *= self.inv(o.v)

    def __add__(self, o):
        r = Field(self)
        return r += o

    def __sub__(self, o):
        r = Field(self)
        return r -= o

    def __mul__(self, o):
        r = Field(self)
        return r *= o

    def __div__(self, o):
        r = Field(self)
        return r /= o

    def __neg__(self):
        if self.v:
            return Field(1000000007 - self.v)
        else:
            return Field(0)

    def __iadd__(self):
        self.v += 1
        if self.v == 1000000007:
            self.v = 0
        return self

    def __add__(self):
        r = Field(self)
        return r += 1

    def __isub__(self):
        self.v -= 1
        if self.v == -1:
            self.v = 1000000007 - 1
        return self

    def __sub__(self):
        r = Field(self)
        return r -= 1

    def __eq__(self, o):
        return o.v == self.v

    def __ne__(self, o):
        return o.v != self.v

    def __int__(self):
        return self.v

    def fact(t):
        F = [1] * (t + 1)
        for i in range(2, t + 1):
            F[i] = F[i - 1] * i
        return F

    def invfact(t):
        F = [1] * (t + 1)
        X = 1
        for i in range(2, t + 1):
            X = X * i
        F[t] = 1 / X
        for i in range(t - 1, 2, -1):
            F[i] = F[i + 1] * (i + 1)
        return F


class Ring:
    @staticmethod
    def div(p, q, N):
        t = 0
        nt = 1
        r = N
        nr = q
        while nr:
            qq = r / nr
            t -= qq * nt
            r -= qq * nr
            t, nt = nt, t
            r, nr = nr, r
        t = t if t >= 0 else t + N
        r = r if r >= 0 else r + N
        if gcd(p, N) % r:
            return 0
        return (t * p / r) % N


hash1 = Field(7)
p1 = hash1

hash2 = Field(13)
p2 = hash2


MAXN = 200200

st = [0] * MAXN
p = [0] * MAXN
f = [0] * MAXN

s = ""
t = ""

h1 = [0] * MAXN
h2 = [0] * MAXN


def buildHash():
    global t, h1, h2, p1, p2
    cp = p1
    h1[0] = t[0]
    for i in range(1, len(t)):
        h1[i] = h1[i - 1] + t[i] * cp
        cp *= p1

    cp = p2
    h2[0] = t[0]
    for i in range(1, len(t)):
        h2[i] = h2[i - 1] + t[i] * cp
        cp *= p2


def getH(l, r):
    global t, st, p, f, p1, p2
    if l + f[l] - 1 >= r:
        return ((-1, -1), -1)

    b = st[l + f[l]]
    e = st[r - p[r]]

    len = e - b + 1

    hm1 = (h1[e] - h1[b - 1]) / p1.pow(b)
    if p[r] % 2 == 1:
        len += 1
        hm1 += p1.pow(e - b + 1)

    if f[l] % 2 == 1:
        len += 1
        hm1 = 1 + hm1 * p1

    hm2 = (h2[e] - h2[b - 1]) / p2.pow(b)
    if p[r] % 2 == 1:
        hm2 += p2.pow(e - b + 1)

    if f[l] % 2 == 1:
        hm2 = 1 + hm2 * p2

    return ((hm1, hm2), len)


def getH2(l, r):
    global t, st, p, f
    if l + f[l] - 1 >= r:
        return (-1, -1)

    b = st[l + f[l]]
    e = st[r - p[r]]

    ans = t[b:e + 1]
    if p[r] % 2 == 1:
        ans += '1'
    if f[l] % 2 == 1:
        ans = '1' + ans
    return ans


def solve(n, s, q):
    global t, st, p, f
    fastIO()

    s = '0' + s + '0'

    for i in range(len(s)):
        if s[i] == '1' and s[i + 1] == '1':
            i += 1
            continue

        t += s[i]
        st[i] = len(t) - 1

    p[0] = 0
    if s[0] == '1':
        p[0] = 1

    for i in range(1, len(s)):
        if s[i] == '0':
            p[i] = 0
        else:
            p[i] = p[i - 1] + 1

    f[len(s) - 1] = 0

    for i in range(len(s) - 1, -1, -1):
        if s[i] == '0':
            f[i] = 0
        else:
            f[i] = f[i + 1] + 1

    buildHash()

    for i in range(q):
        a, b, c = map(int, input().split())

        if getH(a, a + c - 1) == getH(b, b + c - 1):
            print("Yes")
        else:
            print("No")


n = int(input())
s = input()
q = int(input())
solve(n, s, q)
