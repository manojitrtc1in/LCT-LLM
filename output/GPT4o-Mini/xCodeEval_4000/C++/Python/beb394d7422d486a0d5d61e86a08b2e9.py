import sys
from collections import deque
from itertools import accumulate
from math import gcd
from functools import reduce
from random import randint, choice

def fast_input():
    return sys.stdin.readline().strip()

def fast_output():
    sys.stdout.write

class Integer:
    p = 998244353

    def __init__(self, value=0):
        self.v = value % self.p

    def __neg__(self):
        return Integer(-self.v)

    def __add__(self, other):
        return Integer((self.v + other.v) % self.p)

    def __sub__(self, other):
        return Integer((self.v - other.v) % self.p)

    def __mul__(self, other):
        return Integer((self.v * other.v) % self.p)

    def __truediv__(self, other):
        return self * self.inverse(other)

    def inverse(self):
        return pow(self, self.p - 2)

    def __repr__(self):
        return str(self.v)

class Statistic:
    def __init__(self, pr=0, pos=0):
        self.p = [[1 - pr, 0], [0, pr]]
        self.l = self.r = pos

    def merge(self, a, b):
        self.l = a.l
        self.r = b.r
        m = a.r
        self.p = [[0, 0], [0, 0]]
        for k in range(2):
            for l in range(2):
                if k == 0 and l == 1 and policy[m][3]:
                    self.p[0][0] += a.p[0][k] * b.p[l][0]
                elif k == 0 and l == 0 and policy[m][0]:
                    self.p[0][0] += a.p[0][k] * b.p[l][0]
                elif k == 1 and l == 1 and policy[m][1]:
                    self.p[0][0] += a.p[0][k] * b.p[l][0]
                elif k == 1 and l == 0 and policy[m][2]:
                    self.p[0][0] += a.p[0][k] * b.p[l][0]

    def ans(self):
        return sum(self.p[i][j] for i in range(2) for j in range(2))

policy = []

def main():
    n = int(fast_input())
    global policy
    policy = [[1] * 4 for _ in range(n - 1)]
    s = []
    x, v, p = [], [], []
    
    for _ in range(n):
        xi, vi, pi = map(int, fast_input().split())
        x.append(xi)
        v.append(vi)
        p.append(pi)
        s.append(Statistic(Integer(pi) / 100, len(s)))

    ans = Integer(0)
    cols = []
    
    for i in range(n - 1):
        t1 = x[i + 1] - x[i]
        t2 = v[i] + v[i + 1]
        cols.append((i, 2, t1, t2))
        
        if v[i] > v[i + 1]:
            cols.append((i, 1, t1, v[i] - v[i + 1]))
        if v[i] < v[i + 1]:
            cols.append((i, 0, t1, v[i + 1] - v[i]))

    cols.sort(key=lambda c: (c[2] * c[3]))

    for c in cols:
        old = policy[c[0]][:]
        policy[c[0]] = [0] * 4
        policy[c[0]][c[1]] = 1
        s[c[0]] = Statistic(Integer(p[c[0]]) / 100, c[0])
        ans += s[c[0]].ans() * Integer(c[3])
        policy[c[0]] = old
        policy[c[0]][c[1]] = 0
        s[c[0]] = Statistic(Integer(p[c[0]]) / 100, c[0])
        if s[c[0]].ans().v == 0:
            break

    print(ans)

if __name__ == "__main__":
    main()
