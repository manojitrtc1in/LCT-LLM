import sys
from typing import List, Tuple

MOD = 7

class Modular:
    def __init__(self, value: int = 0):
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
        return Modular(0) - self

    def __pow__(self, power: int) -> 'Modular':
        res = Modular(1)
        a = self
        while power > 0:
            if power & 1:
                res *= a
            a *= a
            power >>= 1
        return res

    def __eq__(self, other: 'Modular') -> bool:
        return self.value == other.value

    def __ne__(self, other: 'Modular') -> bool:
        return self.value != other.value

    def inv(self) -> 'Modular':
        return self.__pow__(MOD - 2)

    def __str__(self) -> str:
        return str(self.value)

    def __repr__(self) -> str:
        return str(self.value)

def solve() -> int:
    n = int(input())
    s = input()
    t = input()

    def get(c: str) -> int:
        return ord(c) - ord('a')

    G = [[] for _ in range(20)]
    masks = [0] * 20

    for i in range(n):
        if s[i] != t[i]:
            a = get(s[i])
            b = get(t[i])
            G[a].append(b)
            G[b].append(a)
            masks[a] |= 1 << b

    C = 20
    dp = [False] * (1 << C)
    vis = [False] * C

    def dfs(v: int) -> None:
        vis[v] = True
        mask = 1 << v
        cur = [v]

        for s in G[v]:
            if not vis[s]:
                dfs(s)

    def count() -> int:
        sub = []
        for m in range(mask, -1, -1):
            sub.append(m)

        res = 0
        for m in sub:
            for v in cur:
                if m & (1 << v):
                    dp[m] |= dp[m ^ (1 << v)] and ((m & masks[v] & mask) == 0)
            if dp[m]:
                res = max(res, bin(m).count('1'))
        return res

    res = 0
    dp[0] = True
    for i in range(C):
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
