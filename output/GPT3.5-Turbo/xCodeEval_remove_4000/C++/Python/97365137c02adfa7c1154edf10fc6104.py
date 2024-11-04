import sys
from typing import List, Tuple

sys.setrecursionlimit(10**6)

class Modular:
    def __init__(self, value: int, MOD: int = 7):
        self.value = value % MOD
        if self.value < 0:
            self.value += MOD

    def __add__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value + other.value)

    def __iadd__(self, other: 'Modular') -> 'Modular':
        self.value += other.value
        if self.value >= MOD:
            self.value -= MOD
        return self

    def __sub__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value - other.value)

    def __isub__(self, other: 'Modular') -> 'Modular':
        self.value -= other.value
        if self.value < 0:
            self.value += MOD
        return self

    def __mul__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value * other.value)

    def __imul__(self, other: 'Modular') -> 'Modular':
        self.value = (self.value * other.value) % MOD
        return self

    def __truediv__(self, other: 'Modular') -> 'Modular':
        return self * other.inv()

    def __itruediv__(self, other: 'Modular') -> 'Modular':
        return self.__imul__(other.inv())

    def __pos__(self) -> 'Modular':
        return self

    def __neg__(self) -> 'Modular':
        return Modular(-self.value)

    def __pow__(self, k: int) -> 'Modular':
        res = Modular(1)
        while k:
            if k & 1:
                res *= self
            self *= self
            k >>= 1
        return res

    def inv(self) -> 'Modular':
        return self ** (MOD - 2)

    def __int__(self) -> int:
        return self.value

    def __str__(self) -> str:
        return str(self.value)

    def __repr__(self) -> str:
        return str(self.value)

def solve() -> int:
    n = int(input())
    s = input()
    t = input()

    G = [[] for _ in range(20)]
    masks = [0] * 20
    dp = [False] * (1 << 20)
    vis = [False] * 20

    def dfs(v: int) -> None:
        vis[v] = True
        mask = 1 << v
        cur.append(v)

        for s in G[v]:
            if not vis[s]:
                dfs(s)

    def count() -> int:
        sub = []
        m = mask
        while m:
            sub.append(m)
            m &= (m - 1)
        sub.reverse()

        res = 0
        for m in sub:
            for v in cur:
                if m & (1 << v):
                    dp[m] |= dp[m ^ (1 << v)] & ((m & masks[v] & mask) == 0)
            if dp[m]:
                res = max(res, bin(m).count('1'))
        return res

    for i in range(n):
        if s[i] != t[i]:
            a = ord(s[i]) - ord('a')
            b = ord(t[i]) - ord('a')
            G[a].append(b)
            G[b].append(a)
            masks[a] |= 1 << b

    res = 0
    dp[0] = True
    for i in range(20):
        if not vis[i]:
            mask = 0
            cur = []
            dfs(i)
            tmp = count()
            res += 2 * len(cur) - 1 - tmp

    return res

def main() -> None:
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()
