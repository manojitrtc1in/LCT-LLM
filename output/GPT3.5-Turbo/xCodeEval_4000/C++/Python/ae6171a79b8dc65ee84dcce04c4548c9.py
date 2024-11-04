import math
import sys

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

def isUpperCase(c):
    return c >= 'A' and c <= 'Z'

def isLowerCase(c):
    return c >= 'a' and c <= 'z'

def isLetter(c):
    return isUpperCase(c) or isLowerCase(c)

def isDigit(c):
    return c >= '0' and c <= '9'

def toLowerCase(c):
    return chr(ord(c) + 32) if isUpperCase(c) else c

def toUpperCase(c):
    return chr(ord(c) - 32) if isLowerCase(c) else c

def toString(n):
    return str(n)

def toInt(s):
    return int(s)

def toInt64(s):
    return int(s)

def toDouble(s):
    return float(s)

def stoa(s, A):
    A = list(map(int, s.split()))

def atos(A):
    return ' '.join(map(str, A))

def atov(A):
    return A

def vtoa(vi):
    return vi

def stov(s):
    return list(map(int, s.split()))

def vtos(vi):
    return ' '.join(map(str, vi))

class Fraction:
    def __init__(self, a=0, b=1):
        d = math.gcd(a, b)
        a //= d
        b //= d
        if b < 0:
            a = -a
            b = -b
        self.a = a
        self.b = b

    def __str__(self):
        return str(self.a) + "/" + str(self.b)

    def __add__(self, other):
        return Fraction(self.a * other.b + other.a * self.b, self.b * other.b)

    def __sub__(self, other):
        return Fraction(self.a * other.b - other.a * self.b, self.b * other.b)

    def __mul__(self, other):
        return Fraction(self.a * other.a, self.b * other.b)

    def __truediv__(self, other):
        return Fraction(self.a * other.b, self.b * other.a)

MAXI = 2 << 29
pi = math.acos(-1.0)
eps = 1e-11

def startDBG():
    print("------------------- Start Debug -------------------\n\n")

def endDBG():
    print("\n\n------------------- End Debug -------------------\n")

def in():
    x = 0
    c = sys.stdin.read(1)
    while ord(c) - ord('0') >= 10:
        if c == '-':
            return -in()
        if not c:
            raise Exception
        c = sys.stdin.read(1)
    while ord(c) - ord('0') < 10:
        x = x * 10 + ord(c) - ord('0')
        c = sys.stdin.read(1)
    return x

def showVi(A):
    for i in range(len(A)):
        print(A[i], end=" ")

def showVii(A):
    for i in range(len(A)):
        print(A[i][0], A[i][1])

def showVs(A):
    for i in range(len(A)):
        print(A[i])

def showArray(A, n):
    for i in range(n):
        print(A[i], end=" ")

def MUOI(x):
    re = 1
    for i in range(x):
        re *= 10
    return re + x

def getVi(SOLUONG):
    REVI = []
    for i in range(SOLUONG):
        GETA = in()
        REVI.append(GETA)
    return REVI

def getVs(SOLUONG):
    REVS = []
    for i in range(SOLUONG):
        GETS = input()
        REVS.append(GETS)
    return REVS

def getVii(SOLUONG):
    REVII = []
    for i in range(SOLUONG):
        GETA, GETB = map(int, input().split())
        REVII.append((GETA, GETB))
    return REVII

def checkMod(n, m):
    return (n % m + m) % m

def multiplyMod(a, b, m):
    return ((a * b % m) + m) % m

def powerMod(p, e, m):
    if e == 0:
        return 1 % m
    elif e % 2 == 0:
        t = powerMod(p, e // 2, m)
        return multiplyMod(t, t, m)
    else:
        return multiplyMod(powerMod(p, e - 1, m), p, m)

def isPrimeNumber(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def sqr(x):
    return x * x

def lowbit(n):
    return (n^(n - 1))&n

def countbit(n):
    return 0 if n == 0 else 1 + countbit(n & (n - 1))

def C(m, n):
    if n > m:
        return 0
    re = 1
    for i in range(1, n + 1):
        re = re * (m - i + 1) // i
    return re

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

def euclide(a, b, x, y):
    if a < 0:
        d = euclide(-a, b, x, y)
        x = -x
        return d
    if b < 0:
        d = euclide(a, -b, x, y)
        y = -y
        return d
    if b == 0:
        x = 1
        y = 0
        return a
    else:
        d = euclide(b, a % b, x, y)
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

def eularFunction(n):
    R = factorize(n)
    r = n
    for i in range(len(R)):
        r = r // R[i][0] * (R[i][0] - 1)
    return r

MaxMatrixSize = 40

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
    A = [[0] * MaxMatrixSize for _ in range(MaxMatrixSize)]
    B = [[0] * MaxMatrixSize for _ in range(MaxMatrixSize)]
    for i in range(n):
        for j in range(n):
            A[i][j] = _A[i][j]
            B[i][j] = _B[i][j]
            C[i][j] = 0
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]

def addModMatrix(n, m, C, A, B):
    for i in range(n):
        for j in range(n):
            C[i][j] = checkMod(A[i][j] + B[i][j], m)

def subModMatrix(n, m, C, A, B):
    for i in range(n):
        for j in range(n):
            C[i][j] = checkMod(A[i][j] - B[i][j], m)

def mulModMatrix(n, m, C, _A, _B):
    A = [[0] * MaxMatrixSize for _ in range(MaxMatrixSize)]
    B = [[0] * MaxMatrixSize for _ in range(MaxMatrixSize)]
    for i in range(n):
        for j in range(n):
            A[i][j] = _A[i][j]
            B[i][j] = _B[i][j]
            C[i][j] = 0
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] = (C[i][j] + multiplyMod(A[i][k], B[k][j], m)) % m

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
