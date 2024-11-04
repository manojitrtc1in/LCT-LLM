import math

def dist(a, b):
    return math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)

def distR(a, b):
    return (a[0] - b[0])**2 + (a[1] - b[1])**2

def cross(c, a, b):
    return (a[0] - c[0])*(b[1] - c[1]) - (b[0] - c[0])*(a[1] - c[1])

def crossOper(c, a, b):
    t = (a[0] - c[0])*(b[1] - c[1]) - (b[0] - c[0])*(a[1] - c[1])
    if abs(t) <= 1e-11:
        return 0
    return -1 if t < 0 else 1

def isIntersect(a, b, c, d):
    return crossOper(a, b, c) * crossOper(a, b, d) < 0 and crossOper(c, d, a) * crossOper(c, d, b) < 0

def isMiddle(s, m, t):
    return abs(s - m) <= 1e-11 or abs(t - m) <= 1e-11 or (s < m) != (t < m)

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
        x[0] = -x[0]
        return d
    if b < 0:
        d = euclide(a, -b, x, y)
        y[0] = -y[0]
        return d
    if b == 0:
        x[0] = 1
        y[0] = 0
        return a
    else:
        d = euclide(b, a % b, x, y)
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

def eularFunction(n):
    R = factorize(n)
    r = n
    for i in range(len(R)):
        r = r // R[i][0] * (R[i][0] - 1)
    return r

MAX_MATRIX_SIZE = 40

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
    A = [[0] * MAX_MATRIX_SIZE for _ in range(MAX_MATRIX_SIZE)]
    B = [[0] * MAX_MATRIX_SIZE for _ in range(MAX_MATRIX_SIZE)]
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
            C[i][j] = (A[i][j] + B[i][j]) % m

def subModMatrix(n, m, C, A, B):
    for i in range(n):
        for j in range(n):
            C[i][j] = (A[i][j] - B[i][j]) % m

def mulModMatrix(n, m, C, _A, _B):
    A = [[0] * MAX_MATRIX_SIZE for _ in range(MAX_MATRIX_SIZE)]
    B = [[0] * MAX_MATRIX_SIZE for _ in range(MAX_MATRIX_SIZE)]
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

def toInt64(s):
    return int(s)

def toDouble(s):
    return float(s)

def stoa(s):
    return list(map(int, s.split()))

def atos(n, A):
    return ' '.join(map(str, A[:n]))

def atov(n, A):
    return A[:n]

def vtoa(vi):
    return vi

def stov(s):
    return list(map(int, s.split()))

def vtos(vi):
    return ' '.join(map(str, vi))

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
        return str(self.a) + "/" + str(self.b)

    def __add__(self, other):
        return Fraction(self.a * other.b + other.a * self.b, self.b * other.b)

    def __sub__(self, other):
        return Fraction(self.a * other.b - other.a * self.b, self.b * other.b)

    def __mul__(self, other):
        return Fraction(self.a * other.a, self.b * other.b)

    def __truediv__(self, other):
        return Fraction(self.a * other.b, self.b * other.a)

dp = [[0] * 5005 for _ in range(5005)]

def main():
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

if __name__ == "__main__":
    main()
