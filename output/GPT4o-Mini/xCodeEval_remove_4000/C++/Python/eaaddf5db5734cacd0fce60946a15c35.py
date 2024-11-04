from collections import defaultdict
import sys
import math

input = sys.stdin.read
sys.setrecursionlimit(10**6)

class Field:
    def __init__(self, x=0, N=0):
        self.N = N
        self.v = x % N

    def pow(self, a, p):
        r = 1
        e = a
        while p:
            if p & 1:
                r = (r * e) % self.N
            e = (e * e) % self.N
            p >>= 1
        return r

    def inv(self, a):
        return self.pow(a, self.N - 2)

    def __add__(self, other):
        r = Field(self.v, self.N)
        r.v += other.v
        if r.v >= self.N:
            r.v -= self.N
        return r

    def __sub__(self, other):
        r = Field(self.v, self.N)
        r.v -= other.v
        if r.v < 0:
            r.v += self.N
        return r

    def __mul__(self, other):
        r = Field(self.v, self.N)
        r.v = (self.v * other.v) % self.N
        return r

    def __truediv__(self, other):
        return self * self.inv(other.v)

    def __str__(self):
        return str(self.v)

    @staticmethod
    def fact(t, N):
        F = [Field(1, N)] * (t + 1)
        for i in range(2, t + 1):
            F[i] = F[i - 1] * Field(i, N)
        return F

    @staticmethod
    def invfact(t, N):
        F = [Field(1, N)] * (t + 1)
        X = Field(1, N)
        for i in range(2, t + 1):
            X = X * Field(i, N)
        F[t] = Field(1, N) / X
        for i in range(t - 1, 1, -1):
            F[i] = F[i + 1] * Field(i + 1, N)
        return F

class DDostizhimieStroki:
    def __init__(self):
        self.MAXN = 200200
        self.st = [0] * self.MAXN
        self.p = [0] * self.MAXN
        self.f = [0] * self.MAXN
        self.s = ""
        self.t = ""
        self.h1 = [Field(0, 987655723)] * self.MAXN
        self.h2 = [Field(0, 987656927)] * self.MAXN
        self.p1 = Field(7, 987655723)
        self.p2 = Field(13, 987656927)

    def build_hash(self):
        cp = self.p1
        self.h1[0] = Field(ord(self.t[0]), 987655723)
        for i in range(1, len(self.t)):
            self.h1[i] = self.h1[i - 1] + Field(ord(self.t[i]), 987655723) * cp
            cp *= self.p1

        cp = self.p2
        self.h2[0] = Field(ord(self.t[0]), 987656927)
        for i in range(1, len(self.t)):
            self.h2[i] = self.h2[i - 1] + Field(ord(self.t[i]), 987656927) * cp
            cp *= self.p2

    def get_h(self, l, r):
        if l + self.f[l] - 1 >= r:
            return (-1, -1), -1

        b = self.st[l + self.f[l]]
        e = self.st[r - self.p[r]]

        length = e - b + 1

        hm1 = (self.h1[e] - self.h1[b - 1]) / self.p1.pow(b)
        if self.p[r] % 2 == 1:
            length += 1
            hm1 += self.p1.pow(e - b + 1)

        if self.f[l] % 2 == 1:
            length += 1
            hm1 = Field(1, 987655723) + hm1 * self.p1

        hm2 = (self.h2[e] - self.h2[b - 1]) / self.p2.pow(b)
        if self.p[r] % 2 == 1:
            hm2 += self.p2.pow(e - b + 1)

        if self.f[l] % 2 == 1:
            hm2 = Field(1, 987656927) + hm2 * self.p2

        return (hm1.v, hm2.v), length

    def id6(self, l, r):
        if l + self.f[l] - 1 >= r:
            return ""

        b = self.st[l + self.f[l]]
        e = self.st[r - self.p[r]]

        ans = self.t[b:e + 1]
        if self.p[r] % 2 == 1:
            ans += '1'
        if self.f[l] % 2 == 1:
            ans = '1' + ans
        return ans

    def solve(self):
        data = input().splitlines()
        n = int(data[0])
        self.s = data[1]
        n = len(self.s)

        self.s = '0' + self.s + '0'
        for i in range(len(self.s)):
            if self.s[i] == '1' and self.s[i + 1] == '1':
                i += 1
                continue

            self.t += self.s[i]
            self.st[i] = len(self.t) - 1

        self.p[0] = 0
        if self.s[0] == '1':
            self.p[0] = 1

        for i in range(1, len(self.s)):
            if self.s[i] == '0':
                self.p[i] = 0
            else:
                self.p[i] = self.p[i - 1] + 1

        self.f[len(self.s) - 1] = 0

        for i in range(len(self.s) - 1, -1, -1):
            if self.s[i] == '0':
                self.f[i] = 0
            else:
                self.f[i] = self.f[i + 1] + 1

        self.build_hash()

        q = int(data[2])
        results = []
        for i in range(q):
            a, b, c = map(int, data[3 + i].split())
            if self.get_h(a, a + c - 1) == self.get_h(b, b + c - 1):
                results.append("Yes")
            else:
                results.append("No")

        print("\n".join(results))

if __name__ == "__main__":
    solver = DDostizhimieStroki()
    solver.solve()
