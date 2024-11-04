from collections import defaultdict
from typing import List, Tuple

class ModInt:
    def __init__(self, val=0, mod=998244353):
        self.mod = mod
        self.val = val % mod

    def __add__(self, other):
        return ModInt(self.val + other.val, self.mod)

    def __sub__(self, other):
        return ModInt(self.val - other.val, self.mod)

    def __mul__(self, other):
        return ModInt(self.val * other.val, self.mod)

    def __truediv__(self, other):
        return self * self.inverse(other)

    def inverse(self, other):
        assert other.val != 0
        a, b, u, v = self.mod, other.val, 0, 1
        while b:
            t = a // b
            a, b = b, a - t * b
            u, v = v, u - t * v
        return ModInt(u, self.mod)

    def __repr__(self):
        return str(self.val)

class Solver:
    def __init__(self):
        self.n = int(input())
        self.tree = defaultdict(list)
        self.dp = [[ModInt() for _ in range(3)] for _ in range(self.n)]
        
        for _ in range(self.n - 1):
            a, b = map(int, input().split())
            a -= 1
            b -= 1
            self.tree[a].append(b)
            self.tree[b].append(a)

        self.treedp(0, -1)
        rdp = self.dp[0]
        print(rdp[0] + rdp[2])

    def leaf(self, v):
        return len(self.tree[v]) == 1

    def treedp(self, now, pre):
        ndp = self.dp[now]
        ndp[2] = ModInt(1)
        for to in self.tree[now]:
            if to == pre:
                continue
            tmp = [ModInt() for _ in range(3)]
            self.treedp(to, now)
            tdp = self.dp[to]

            for i in range(3):
                tmp[i] = tdp[2] * ndp[i]

            tmp[0] += ndp[2] * tdp[2] + ndp[1] * tdp[2]
            tmp[0] += (ndp[1] + ndp[2]) * tdp[1]
            tmp[0] += ModInt(2) * ndp[0] * tdp[0]
            tmp[1] += (ndp[1] * 2 + ndp[2]) * tdp[0]
            tmp[2] += ndp[2] * tdp[0]

            self.dp[now] = tmp

def main():
    Solver()

if __name__ == "__main__":
    main()
