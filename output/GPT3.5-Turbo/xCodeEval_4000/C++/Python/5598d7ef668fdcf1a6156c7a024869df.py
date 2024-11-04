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

def stoa(s):
    return list(map(int, s.split()))

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

dp = [[0] * 5005 for _ in range(5005)]
M = 1000000007

s = input()
t = input()
for i in range(len(s)):
    for j in range(len(t)):
        if s[i] == t[j]:
            dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j] + 1) % M
        else:
            dp[i + 1][j + 1] = dp[i + 1][j]
re = 0
sz = len(t)
for i in range(len(s)):
    re = (re + dp[i + 1][sz]) % M
print(re)