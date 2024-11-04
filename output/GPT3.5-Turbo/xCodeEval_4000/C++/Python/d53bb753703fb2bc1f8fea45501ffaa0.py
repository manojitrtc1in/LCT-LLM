from typing import List, Tuple

class Modular:
    def __init__(self, value: int):
        self.value = value % self.MOD
        if self.value < 0:
            self.value += self.MOD

    def __add__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value + other.value)

    def __iadd__(self, other: 'Modular') -> 'Modular':
        self.value += other.value
        if self.value >= self.MOD:
            self.value -= self.MOD
        return self

    def __sub__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value - other.value)

    def __isub__(self, other: 'Modular') -> 'Modular':
        self.value -= other.value
        if self.value < 0:
            self.value += self.MOD
        return self

    def __mul__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value * other.value % self.MOD)

    def __imul__(self, other: 'Modular') -> 'Modular':
        self.value = (self.value * other.value) % self.MOD
        return self

    def __truediv__(self, other: 'Modular') -> 'Modular':
        return self * other.inv()

    def __itruediv__(self, other: 'Modular') -> 'Modular':
        return self.__imul__(other.inv())

    def __pos__(self) -> 'Modular':
        return self

    def __neg__(self) -> 'Modular':
        return Modular(-self.value)

    def __eq__(self, other: 'Modular') -> bool:
        return self.value == other.value

    def __ne__(self, other: 'Modular') -> bool:
        return self.value != other.value

    def __str__(self) -> str:
        return str(self.value)

    def __repr__(self) -> str:
        return str(self.value)

    def inv(self) -> 'Modular':
        return self.exp(self.value, self.MOD - 2)

    def exp(self, a: int, k: int) -> 'Modular':
        res = Modular(1)
        while k:
            if k & 1:
                res *= a
            a *= a
            k >>= 1
        return res

    MOD = 7

def solve() -> int:
    C = 20
    G = [[] for _ in range(C)]
    masks = [0] * C
    dp = [False] * (1 << C)
    vis = [False] * C
    mask = 0

    def dfs(v: int) -> None:
        nonlocal mask
        vis[v] = True
        mask |= 1 << v
        cur.append(v)
        for s in G[v]:
            if not vis[s]:
                dfs(s)

    def count() -> int:
        sub = []
        m = mask
        while m:
            sub.append(m)
            m = (m - 1) & mask
        sub.reverse()

        res = 0
        for m in sub:
            for v in cur:
                if m & (1 << v):
                    dp[m] |= dp[m ^ (1 << v)] & ((m & masks[v] & mask) == 0)
            if dp[m]:
                res = max(res, bin(m).count('1'))
        return res

    n = int(input())
    s = input()
    t = input()

    def get(c: str) -> int:
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
            mask = 0
            cur = []
            dfs(i)
            tmp = count()
            res += 2 * len(cur) - 1 - tmp

    vis = [False] * C
    masks = [0] * C
    dp = [False] * (1 << C)
    for i in range(C):
        G[i].clear()

    return res

t = int(input())
for _ in range(t):
    print(solve())
