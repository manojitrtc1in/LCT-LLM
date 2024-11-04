from collections import defaultdict
import sys
import random

class Modular:
    MOD_VAL = 7

    def __init__(self, value=0):
        self.value = value % self.MOD_VAL
        if self.value < 0:
            self.value += self.MOD_VAL

    def exp(self, k):
        res = Modular(1)
        a = self
        while k:
            if k & 1:
                res *= a
            a *= a
            k >>= 1
        return res

    def inv(self):
        return self.exp(self.MOD_VAL - 2)

    def __add__(self, other):
        return Modular(self.value + other.value)

    def __sub__(self, other):
        return Modular(self.value - other.value)

    def __neg__(self):
        return Modular(-self.value)

    def __mul__(self, other):
        return Modular(self.value * other.value)

    def __truediv__(self, other):
        return self * other.inv()

    def __eq__(self, other):
        return self.value == other.value

    def __ne__(self, other):
        return self.value != other.value

    def __int__(self):
        return self.value

    def __repr__(self):
        return str(self.value)

def scanf_t(type):
    if type == int:
        return int(sys.stdin.readline().strip())
    elif type == float:
        return float(sys.stdin.readline().strip())
    elif type == str:
        return sys.stdin.readline().strip()
    # Add more types as needed

def printf_t(value, end='\n'):
    print(value, end=end)

def dag(g, cur):
    n = len(cur)
    dp = [False] * (1 << n)
    reach = [0] * n

    for i in range(n):
        for s in g[cur[i]]:
            reach[i] |= 1 << cur.index(s)

    res = 0
    dp[0] = True
    for m in range(1 << n):
        for i in range(n):
            if m & (1 << i):
                dp[m] |= dp[m ^ (1 << i)] and (reach[i] & m) == 0
        if dp[m]:
            res = max(res, bin(m).count('1'))

    return res

def solve():
    n = scanf_t(int)
    s = scanf_t(str)
    t = scanf_t(str)

    C = 20
    G = defaultdict(list)
    g = defaultdict(list)

    for i in range(n):
        if s[i] != t[i]:
            a = ord(s[i]) - ord('a')
            b = ord(t[i]) - ord('a')
            G[a].append(b)
            G[b].append(a)
            g[a].append(b)

    cur = []
    vis = [False] * C

    def dfs(v):
        vis[v] = True
        cur.append(v)
        for s in G[v]:
            if not vis[s]:
                dfs(s)

    res = 0
    for i in range(C):
        if not vis[i]:
            cur.clear()
            dfs(i)
            s = dag(g, cur)
            res += 2 * len(cur) - 1 - s

    return res

def main():
    t = scanf_t(int)
    for _ in range(t):
        printf_t(solve())

if __name__ == "__main__":
    main()
