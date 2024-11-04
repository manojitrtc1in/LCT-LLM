import sys
from typing import List, Tuple
from math import acos
from random import seed, randint
from time import time

sys.setrecursionlimit(10**6)

# Constants
INF = int(1e9)
INF64 = int(1e18)
MOD = int(1e9) + 7
EPS = 1e-9
PI = acos(-1.0)
CR = 7
BITS = 15

# Typedefs
li = int
ld = float
pt = Tuple[int, int]

# Operator overloading
def pair_str(a: Tuple, b: Tuple) -> str:
    return f"({a[0]}, {a[1]})"

def vector_str(v: List) -> str:
    res = "["
    for i in range(len(v)):
        if i:
            res += ", "
        res += str(v[i])
    res += "]"
    return res

# Random number generator
seed(time())

# Modular integer class
class Mint:
    def __init__(self, v: int = 0):
        if v < 0:
            v = v % MOD + MOD
        if v >= MOD:
            v %= MOD
        self.val = int(v)
    
    @staticmethod
    def inv_mod(a: int, m: int = MOD) -> int:
        g = m
        r = a
        x = 0
        y = 1

        while r != 0:
            q = g // r
            g %= r
            g, r = r, g
            x -= q * y
            x, y = y, x
        
        return x if x >= 0 else x + m
    
    def __add__(self, other: 'Mint') -> 'Mint':
        return Mint(self.val + other.val)
    
    def __sub__(self, other: 'Mint') -> 'Mint':
        return Mint(self.val - other.val)
    
    def __mul__(self, other: 'Mint') -> 'Mint':
        return Mint(self.val * other.val)
    
    def __truediv__(self, other: 'Mint') -> 'Mint':
        return self * other.inv()
    
    def __iadd__(self, other: 'Mint') -> 'Mint':
        self.val += other.val
        if self.val >= MOD:
            self.val -= MOD
        return self
    
    def __isub__(self, other: 'Mint') -> 'Mint':
        self.val -= other.val
        if self.val < 0:
            self.val += MOD
        return self
    
    def __imul__(self, other: 'Mint') -> 'Mint':
        self.val = (self.val * other.val) % MOD
        return self
    
    def __itruediv__(self, other: 'Mint') -> 'Mint':
        return self * other.inv()
    
    def __pow__(self, p: int) -> 'Mint':
        if p < 0:
            return self.inv() ** (-p)
        
        a = self
        result = Mint(1)

        while p > 0:
            if p & 1:
                result *= a
            a *= a
            p >>= 1

        return result
    
    def __neg__(self) -> 'Mint':
        return Mint(0) if self.val == 0 else Mint(MOD - self.val)
    
    def __eq__(self, other: 'Mint') -> bool:
        return self.val == other.val
    
    def __ne__(self, other: 'Mint') -> bool:
        return self.val != other.val
    
    def __lt__(self, other: 'Mint') -> bool:
        return self.val < other.val
    
    def __gt__(self, other: 'Mint') -> bool:
        return self.val > other.val
    
    def __le__(self, other: 'Mint') -> bool:
        return self.val <= other.val
    
    def __ge__(self, other: 'Mint') -> bool:
        return self.val >= other.val
    
    def inv(self) -> 'Mint':
        return Mint.inv_mod(self.val)
    
    def __int__(self) -> int:
        return self.val
    
    def __float__(self) -> float:
        return self.val
    
    def __str__(self) -> str:
        return str(self.val)
    
    def __repr__(self) -> str:
        return str(self.val)

# Global variables
n: li
dp: List[List[List[List[Mint]]]]
cnt: List[List[List[Mint]]]
dp2: List[List[Mint]]

# Read input
def read() -> bool:
    global n
    try:
        n = int(input())
        return True
    except EOFError:
        return False

# Precalculate values
def precalc():
    global dp, cnt
    dp = [[[[Mint(0) for _ in range(1 << BITS)] for _ in range(CR)] for _ in range(BITS + 1)] for _ in range(CR)]
    cnt = [[[Mint(0) for _ in range(1 << BITS)] for _ in range(CR)] for _ in range(CR)]
    for i in range(CR):
        dp[i][0][i][0] = Mint(1)
    for cs in range(CR):
        for i in range(BITS):
            for ct in range(CR):
                for x in range(1 << BITS):
                    if dp[cs][i][ct][x] != Mint(0):
                        for cc in range(CR + 1):
                            dp[cs][i + 1][(ct + cc) // 2][(((ct + cc) % 2) << i) | x] += dp[cs][i][ct][x]
    for i in range(CR):
        for j in range(CR):
            for x in range(1 << BITS):
                cnt[i][j][x] = dp[i][BITS][j][x]

# Solve the problem
def solve():
    global dp2
    dp2 = [[Mint(0) for _ in range(CR)] for _ in range(5)]
    dp2[0][0] = Mint(1)
    for i in range(4):
        x = n & ((1 << BITS) - 1)
        n >>= BITS
        for j in range(CR):
            for k in range(CR):
                dp2[i + 1][k] += dp2[i][j] * cnt[j][k][x]
    print(int(dp2[4][0]))

# Main function
def main():
    precalc()
    tc = int(input())
    while tc > 0:
        read()
        solve()
        tc -= 1

# Execute the main function
if __name__ == "__main__":
    main()
