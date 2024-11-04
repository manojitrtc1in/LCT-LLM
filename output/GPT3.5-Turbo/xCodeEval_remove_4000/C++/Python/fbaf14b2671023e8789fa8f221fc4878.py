def dist(a, b):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5

def cross(c, a, b):
    return (a[0] - c[0]) * (b[1] - c[1]) - (b[0] - c[0]) * (a[1] - c[1])

def crossOper(c, a, b):
    t = (a[0] - c[0]) * (b[1] - c[1]) - (b[0] - c[0]) * (a[1] - c[1])
    if abs(t) <= eps:
        return 0
    return -1 if t < 0 else 1

def isIntersect(a, b, c, d):
    return crossOper(a, b, c) * crossOper(a, b, d) < 0 and crossOper(c, d, a) * crossOper(c, d, b) < 0

def isMiddle(s, m, t):
    return abs(s - m) <= eps or abs(t - m) <= eps or (s < m) != (t < m)

def gcd(a, b):
    if a < 0:
        return gcd(-a, b)
    if b < 0:
        return gcd(a, -b)
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    if a < 0:
        return lcm(-a, b)
    if b < 0:
        return lcm(a, -b)
    return a * (b // gcd(a, b))

def id12(a, b, x, y):
    if a < 0:
        d = id12(-a, b, x, y)
        x[0] = -x[0]
        return d
    if b < 0:
        d = id12(a, -b, x, y)
        y[0] = -y[0]
        return d
    if b == 0:
        x[0] = 1
        y[0] = 0
        return a
    else:
        d = id12(b, a % b, x, y)
        t = x[0]
        x[0] = y[0]
        y[0] = t - (a // b) * y[0]
        return d

def factorize(n):
    R = []
    i = 2
    while i * i <= n:
        if n % i == 0:
            C = 0
            while n % i == 0:
                C += 1
                n //= i
            R.append((i, C))
        i += 1
        if i > n // i:
            i = n
    if n > 1:
        R.append((n, 1))
    return R

def id1(n):
    R = factorize(n)
    r = n
    for i in range(len(R)):
        r = r // R[i][0] * (R[i][0] - 1)
    return r

def showMatrix(n, A):
    for i in range(n):
        for j in range(n):
            print(A[i][j], end="")
        print()

def identityMatrix(n, A):
    for i in range(n):
        for j in range(n):
            A[i][j] = 1 if i == j else 0

def addMatrix(n, C, A, B):
    for i in range(n):
        for j in range(n):
            C[i][j] = A[i][j] + B[i][j]

def subMatrix(n, C, A, B):
    for i in range(n):
        for j in range(n):
            C[i][j] = A[i][j] - B[i][j]

def mulMatrix(n, C, _A, _B):
    A = [[0] * n for _ in range(n)]
    B = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            A[i][j] = _A[i][j]
            B[i][j] = _B[i][j]
            C[i][j] = 0
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]

def id5(n, m, C, A, B):
    for i in range(n):
        for j in range(n):
            C[i][j] = (A[i][j] + B[i][j]) % m

def id4(n, m, C, A, B):
    for i in range(n):
        for j in range(n):
            C[i][j] = (A[i][j] - B[i][j]) % m

def id8(n, m, C, _A, _B):
    A = [[0] * n for _ in range(n)]
    B = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            A[i][j] = _A[i][j]
            B[i][j] = _B[i][j]
            C[i][j] = 0
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m

def C(m, n):
    if n > m:
        return 0
    re = 1
    for i in range(1, n + 1):
        re = re * (m - i + 1) // i
    return re

def powerMod(p, e, m):
    if e == 0:
        return 1 % m
    elif e % 2 == 0:
        t = powerMod(p, e // 2, m)
        return (t * t) % m
    else:
        return (powerMod(p, e - 1, m) * p) % m

def checkMod(n, m):
    return (n % m + m) % m

def multiplyMod(a, b, m):
    return ((a * b) % m + m) % m

def id13(n):
    if n <= 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def sqr(x):
    return x * x

def lowbit(n):
    return (n ^ (n - 1)) & n

def countbit(n):
    return 0 if n == 0 else 1 + countbit(n & (n - 1))

def toString(n):
    return str(n)

def toInt(s):
    return int(s)

def id0(s):
    return int(s)

def toDouble(s):
    return float(s)

def stoa(s, A):
    A = list(map(int, s.split()))

def atos(A):
    return " ".join(map(str, A))

def atov(A):
    return A

def vtoa(vi):
    return vi

def stov(s):
    return list(map(int, s.split()))

def vtos(vi):
    return " ".join(map(str, vi))

def Fraction:
    def __init__(self, a=0, b=1):
        d = gcd(a, b)
        a //= d
        b //= d
        if b < 0:
            a = -a
            b = -b
        self.a = a
        self.b = b

    def toString(self):
        return str(self.a) + "/" + str(self.b)

def operator+(p, q):
    return Fraction(p.a * q.b + q.a * p.b, p.b * q.b)

def operator-(p, q):
    return Fraction(p.a * q.b - q.a * p.b, p.b * q.b)

def operator*(p, q):
    return Fraction(p.a * q.a, p.b * q.b)

def operator/(p, q):
    return Fraction(p.a * q.b, p.b * q.a)

dp = [[0] * 5005 for _ in range(5005)]

s = input()
t = input()
sz1 = len(s)
sz2 = len(t)
for i in range(sz1):
    for j in range(sz2):
        if s[i] == t[j]:
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j] + 1
        else:
            dp[i + 1][j + 1] = dp[i + 1][j]
re = 0
for i in range(sz1):
    re += dp[i + 1][sz2]
print(re)
