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
        return self * other.inv()
    
    def __pos__(self) -> 'Modular':
        return self
    
    def __neg__(self) -> 'Modular':
        return Modular(-self.value)
    
    def __pow__(self, k: int) -> 'Modular':
        res = Modular(1)
        a = self
        while k:
            if k & 1:
                res *= a
            a *= a
            k >>= 1
        return res
    
    def inv(self) -> 'Modular':
        return self ** (MOD - 2)
    
    def __int__(self) -> int:
        return self.value
    
    def __str__(self) -> str:
        return str(self.value)
    
    def __eq__(self, other: 'Modular') -> bool:
        return self.value == other.value
    
    def __ne__(self, other: 'Modular') -> bool:
        return self.value != other.value


def dag(g: List[List[int]], cur: List[int]) -> int:
    def get(v: int) -> int:
        return cur.index(v)
    
    n = len(cur)
    dp = [False] * (1 << n)
    reach = [0] * n
    
    for i in range(n):
        for s in g[cur[i]]:
            reach[i] |= 1 << get(s)
    
    res = 0
    dp[0] = True
    for m in range(1 << n):
        for i in range(n):
            if m & (1 << i):
                dp[m] = dp[m] or (dp[m ^ (1 << i)] and ((reach[i] & m) == 0))
        if dp[m]:
            res = max(res, bin(m).count('1'))
    
    return res


def solve() -> int:
    n = int(input())
    s = input()
    t = input()
    
    G = [[] for _ in range(26)]
    g = [[] for _ in range(26)]
    for i in range(n):
        if s[i] != t[i]:
            a = ord(s[i]) - ord('a')
            b = ord(t[i]) - ord('a')
            G[a].append(b)
            G[b].append(a)
            g[a].append(b)
    
    cur = []
    vis = [False] * 26
    def dfs(v: int) -> None:
        vis[v] = True
        cur.append(v)
        for s in G[v]:
            if not vis[s]:
                dfs(s)
    
    res = 0
    for i in range(26):
        if not vis[i]:
            cur.clear()
            dfs(i)
            s = dag(g, cur)
            res += 2 * len(cur) - 1 - s
    
    return res


def main() -> None:
    t = int(input())
    for _ in range(t):
        print(solve())


if __name__ == '__main__':
    main()
