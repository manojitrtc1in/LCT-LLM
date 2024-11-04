from collections import defaultdict
import sys
import random

MOD = 7
INF = int(1e9)
LINF = int(1e18)
M = int(1e9 + 7)

class Modular:
    def __init__(self, value=0):
        self.value = value % MOD
        if self.value < 0:
            self.value += MOD

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

    def inv(self):
        return self.exp(MOD - 2)

    def exp(self, k):
        res = Modular(1)
        a = self
        while k:
            if k & 1:
                res *= a
            a *= a
            k >>= 1
        return res

    def __int__(self):
        return self.value

    def __eq__(self, other):
        return self.value == other.value

    def __ne__(self, other):
        return self.value != other.value

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

def dfs(v):
    vis[v] = True
    mask[0] |= 1 << v
    cur.append(v)

    for s in G[v]:
        if not vis[s]:
            dfs(s)

def count():
    sub = []
    for m in range(1 << C):
        if m & mask[0]:
            sub.append(m)
    sub.reverse()

    res = 0
    for m in sub:
        for v in cur:
            if m & (1 << v):
                dp[m] |= dp[m ^ (1 << v)] and ((m & masks[v] & mask[0]) == 0)
        if dp[m]:
            res = max(res, pct(m))
    return res

def solve():
    n = scanf_t(int)
    s = scanf_t(str)
    t = scanf_t(str)

    def get(c):
        return ord(c) - ord('a')

    for i in range(n):
        if s[i] != t[i]:
            a = get(s[i])
            b = get(t[i])
            G[a].append(b)
            G[b].append(a)
            masks[a] |= 1 << b

    res = 0
    dp[0] = True
    for i in range(C):
        if not vis[i]:
            mask[0] = 0
            cur.clear()
            dfs(i)
            tmp = count()
            res += 2 * len(cur) - 1 - tmp

    vis[:] = [False] * C
    masks[:] = [0] * C
    dp[:] = [False] * (1 << C)
    for i in range(C):
        G[i].clear()

    return res

def main():
    t = scanf_t(int)
    for _ in range(t):
        printf_t(solve())

C = 20
G = defaultdict(list)
cur = []
masks = [0] * C
dp = [False] * (1 << C)
vis = [False] * C
mask = [0]

if __name__ == "__main__":
    main()
