import math

def dist(a, b):
    return math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)

def distR(a, b):
    return (a[0] - b[0])**2 + (a[1] - b[1])**2

def cross(c, a, b):
    return (a[0] - c[0])*(b[1] - c[1]) - (b[0] - c[0])*(a[1] - c[1])

def crossOper(c, a, b):
    t = (a[0] - c[0])*(b[1] - c[1]) - (b[0] - c[0])*(a[1] - c[1])
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
        x = -x
        return d
    if b < 0:
        d = id12(a, -b, x, y)
        y = -y
        return d
    if b == 0:
        x = 1
        y = 0
        return a
    else:
        d = id12(b, a % b, x, y)
        t = x
        x = y
        y = t - (a // b) * y
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
            print(A[i][j], end='')
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

def toString(n):
    return str(n)

def toInt(s):
    return int(s)

def toDouble(s):
    return float(s)

def stoa(s, A):
    n = 0
    for v in s.split():
        A[n] = int(v)
        n += 1

def atos(n, A):
    s = ''
    for i in range(n):
        if i > 0:
            s += ' '
        s += str(A[i])
    return s

def atov(n, A):
    vi = []
    for i in range(n):
        vi.append(A[i])
    return vi

def vtoa(vi):
    n = len(vi)
    A = [0] * n
    for i in range(n):
        A[i] = vi[i]
    return A

def stov(s):
    vi = []
    for v in s.split():
        vi.append(int(v))
    return vi

def vtos(vi):
    s = ''
    for i in range(len(vi)):
        if i > 0:
            s += ' '
        s += str(vi[i])
    return s

class Fraction:
    def __init__(self, a=0, b=1):
        d = gcd(a, b)
        a //= d
        b //= d
        if b < 0:
            a = -a
            b = -b
        self.a = a
        self.b = b

    def __str__(self):
        return str(self.a) + '/' + str(self.b)

    def __add__(self, other):
        return Fraction(self.a * other.b + other.a * self.b, self.b * other.b)

    def __sub__(self, other):
        return Fraction(self.a * other.b - other.a * self.b, self.b * other.b)

    def __mul__(self, other):
        return Fraction(self.a * other.a, self.b * other.b)

    def __truediv__(self, other):
        return Fraction(self.a * other.b, self.b * other.a)

dp = [[0] * 5005 for _ in range(5005)]

M = 1000000007

s = input()
t = input()
sz1 = len(s)
sz2 = len(t)
for i in range(sz1):
    for j in range(sz2):
        dp[i + 1][j + 1] = (dp[i + 1][j] + (s[i] == t[j]) * (dp[i][j] + 1)) % M
re = 0
for i in range(sz1):
    re = (re + dp[i + 1][sz2]) % M
print(re)
