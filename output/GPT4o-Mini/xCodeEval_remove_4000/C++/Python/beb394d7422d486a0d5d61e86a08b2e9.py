from collections import deque
from itertools import accumulate
import sys
import random

class Integer:
    p = 998244353

    def __init__(self, t=0):
        self.v = t % self.p

    def __neg__(self):
        return Integer(self.p - self.v) if self.v else Integer(0)

    def __add__(self, other):
        return Integer((self.v + other.v) % self.p)

    def __sub__(self, other):
        return Integer((self.v - other.v) % self.p)

    def __mul__(self, other):
        return Integer((self.v * other.v) % self.p)

    def __truediv__(self, other):
        return self * self.inverse(other)

    def inverse(self):
        assert self.v
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
    n = int(sys.stdin.readline().strip())
    global policy
    policy = [[1] * 4 for _ in range(n - 1)]
    s = []
    x, v, p = [], [], []
    for _ in range(n):
        xi, vi, pi = map(int, sys.stdin.readline().strip().split())
        x.append(xi)
        v.append(vi)
        p.append(pi)
        s.append(Statistic(Integer(pi) / 100, len(s)))

    ans = Integer(0)
    cols = []
    for i in range(n - 1):
        tmp = {'i': i, 'tp': 2, 't1': x[i + 1] - x[i], 't2': v[i] + v[i + 1]}
        cols.append(tmp)
        if v[i] > v[i + 1]:
            tmp['tp'] = 1
            tmp['t2'] = v[i] - v[i + 1]
            cols.append(tmp)
        if v[i] < v[i + 1]:
            tmp['tp'] = 0
            tmp['t2'] = v[i + 1] - v[i]
            cols.append(tmp)

    cols.sort(key=lambda c: (c['t1'] * c['t2'], c['tp']))

    for c in cols:
        old = policy[c['i']][:]
        policy[c['i']] = [0] * 4
        policy[c['i']][c['tp']] = 1
        s[c['i']] = Statistic(Integer(p[c['i']]) / 100, c['i'])
        ans += s[c['i']].ans() * Integer(c['t1']) / c['t2']
        policy[c['i']] = old
        policy[c['i']][c['tp']] = 0
        s[c['i']] = Statistic(Integer(p[c['i']]) / 100, c['i'])
        if s[c['i']].ans().v == 0:
            break

    print(ans)

if __name__ == "__main__":
    main()
