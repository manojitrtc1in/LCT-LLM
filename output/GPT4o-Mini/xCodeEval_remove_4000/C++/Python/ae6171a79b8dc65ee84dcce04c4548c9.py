from collections import defaultdict
import sys
import math

def startDBG():
    print("------------------- Start Debug -------------------\n")

def endDBG():
    print("\n\n------------------- End Debug -------------------\n")

def in_int():
    return int(sys.stdin.readline().strip())

def showVi(A):
    print(" ".join(map(str, A)))

def id2(A):
    for a in A:
        print(a[0], a[1])

def showVs(A):
    for a in A:
        print(a)

def showArray(A):
    print(" ".join(map(str, A)))

def MUOI(x):
    return 10 ** x + x

def getVi(id6):
    return [in_int() for _ in range(id6)]

def getVs(id6):
    return [input().strip() for _ in range(id6)]

def id3(id6):
    return [tuple(map(int, input().split())) for _ in range(id6)]

def checkMod(n, m):
    return (n % m + m) % m

def multiplyMod(a, b, m):
    return (a * b % m + m) % m

def powerMod(p, e, m):
    if e == 0:
        return 1 % m
    elif e % 2 == 0:
        t = powerMod(p, e // 2, m)
        return multiplyMod(t, t, m)
    else:
        return multiplyMod(powerMod(p, e - 1, m), p, m)

def id13(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def sqr(x):
    return x * x

def lowbit(n):
    return n ^ (n - 1) & n

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

def id12(a, b):
    if a < 0:
        d = id12(-a, b)
        return d
    if b < 0:
        d = id12(a, -b)
        return d
    if b == 0:
        return a
    else:
        d = id12(b, a % b)
        return d

def factorize(n):
    R = []
    for i in range(2, n + 1):
        if n % i == 0:
            C = 0
            while n % i == 0:
                C += 1
                n //= i
            R.append((i, C))
    if n > 1:
        R.append((n, 1))
    return R

def id1(n):
    R = factorize(n)
    r = n
    for i in range(len(R)):
        r = r // R[i][0] * (R[i][0] - 1)
    return r

id9 = 40

def showMatrix(n, A):
    for i in range(n):
        print(" ".join(map(str, A[i])))

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
    A = [[_A[i][j] for j in range(n)] for i in range(n)]
    B = [[_B[i][j] for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            C[i][j] = 0
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]

def id5(n, m, C, A, B):
    for i in range(n):
        for j in range(n):
            C[i][j] = checkMod(A[i][j] + B[i][j], m)

def id4(n, m, C, A, B):
    for i in range(n):
        for j in range(n):
            C[i][j] = checkMod(A[i][j] - B[i][j], m)

def id8(n, m, C, _A, _B):
    A = [[_A[i][j] for j in range(n)] for i in range(n)]
    B = [[_B[i][j] for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            C[i][j] = 0
            for k in range(n):
                C[i][j] = (C[i][j] + multiplyMod(A[i][k], B[k][j], m)) % m

def dist(a, b):
    return math.sqrt(sqr(a[0] - b[0]) + sqr(a[1] - b[1]))

def distR(a, b):
    return sqr(a[0] - b[0]) + sqr(a[1] - b[1])

def cross(c, a, b):
    return (a[0] - c[0]) * (b[1] - c[1]) - (b[0] - c[0]) * (a[1] - c[1])

def crossOper(c, a, b):
    t = (a[0] - c[0]) * (b[1] - c[1]) - (b[0] - c[0]) * (a[1] - c[1])
    if abs(t) <= 1e-11:
        return 0
    return -1 if t < 0 else 1

def isIntersect(a, b, c, d):
    return crossOper(a, b, c) * crossOper(a, b, d) < 0 and crossOper(c, d, a) * crossOper(c, d, b) < 0

def isMiddle(s, m, t):
    return abs(s - m) <= 1e-11 or abs(t - m) <= 1e-11 or (s < m) != (t < m)

def id11(c):
    return 'A' <= c <= 'Z'

def id14(c):
    return 'a' <= c <= 'z'

def isLetter(c):
    return isDigit(c) or isLetter(c)

def isDigit(c):
    return '0' <= c <= '9'

def id7(c):
    return c.lower() if id11(c) else c

def id10(c):
    return c.upper() if id14(c) else c

def toString(n):
    return str(n)

def toInt(s):
    return int(s)

def id0(s):
    return int(s)

def toDouble(s):
    return float(s)

def stoa(s):
    return list(map(int, s.split()))

def atos(A):
    return " ".join(map(str, A))

def atov(A):
    return list(A)

def vtoa(vi):
    return list(vi)

def stov(s):
    return list(map(int, s.split()))

def vtos(vi):
    return " ".join(map(str, vi))

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

    def toString(self):
        return f"{self.a}/{self.b}"

def operator_add(p, q):
    return Fraction(p.a * q.b + q.a * p.b, p.b * q.b)

def operator_sub(p, q):
    return Fraction(p.a * q.b - q.a * p.b, p.b * q.b)

def operator_mul(p, q):
    return Fraction(p.a * q.a, p.b * q.b)

def operator_div(p, q):
    return Fraction(p.a * q.b, p.b * q.a)

dp = [[0] * 5005 for _ in range(5005)]
M = 1000000007

def main():
    s = input().strip()
    t = input().strip()
    sz1 = len(s)
    sz2 = len(t)
    for i in range(sz1 + 1):
        for j in range(sz2 + 1):
            dp[i][j] = 0
    for i in range(sz1):
        for j in range(sz2):
            dp[i + 1][j + 1] = (dp[i + 1][j] + (s[i] == t[j]) * (dp[i][j] + 1)) % M
    re = 0
    for i in range(sz1):
        re = (re + dp[i + 1][sz2]) % M
    print(re)

if __name__ == "__main__":
    main()
