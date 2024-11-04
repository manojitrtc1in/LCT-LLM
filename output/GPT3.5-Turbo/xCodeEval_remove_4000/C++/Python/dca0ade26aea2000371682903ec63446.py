import sys
from typing import List, Tuple

sys.setrecursionlimit(10**6)

MOD = 998244353
root = 3

class Mint:
    def __init__(self, value: int = 0):
        self.value = value % MOD
    
    def __add__(self, other: 'Mint') -> 'Mint':
        if isinstance(other, Mint):
            return Mint((self.value + other.value) % MOD)
        return Mint((self.value + other) % MOD)
    
    def __sub__(self, other: 'Mint') -> 'Mint':
        if isinstance(other, Mint):
            return Mint((self.value - other.value) % MOD)
        return Mint((self.value - other) % MOD)
    
    def __mul__(self, other: 'Mint') -> 'Mint':
        if isinstance(other, Mint):
            return Mint((self.value * other.value) % MOD)
        return Mint((self.value * other) % MOD)
    
    def __pow__(self, power: int) -> 'Mint':
        res = Mint(1)
        base = self.value
        while power > 0:
            if power & 1:
                res *= base
            base *= base
            power >>= 1
        return res
    
    def __eq__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value == other.value
        return self.value == other
    
    def __ne__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value != other.value
        return self.value != other
    
    def __lt__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value < other.value
        return self.value < other
    
    def __le__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value <= other.value
        return self.value <= other
    
    def __gt__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value > other.value
        return self.value > other
    
    def __ge__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value >= other.value
        return self.value >= other
    
    def __str__(self) -> str:
        return str(self.value)
    
    def __repr__(self) -> str:
        return str(self.value)
    
    def __int__(self) -> int:
        return self.value
    
    def __index__(self) -> int:
        return self.value
    
    def __bool__(self) -> bool:
        return bool(self.value)
    
    def inv(self) -> 'Mint':
        return self ** (MOD - 2)
    
    def __radd__(self, other: 'Mint') -> 'Mint':
        return self + other
    
    def __rsub__(self, other: 'Mint') -> 'Mint':
        return other - self
    
    def __rmul__(self, other: 'Mint') -> 'Mint':
        return self * other
    
    def __rpow__(self, other: int) -> 'Mint':
        return Mint(other) ** self
    
    def __neg__(self) -> 'Mint':
        return Mint(-self.value)
    
    def __pos__(self) -> 'Mint':
        return self
    
    def __abs__(self) -> 'Mint':
        return self
    
    def __invert__(self) -> 'Mint':
        return self.inv()
    
    def __round__(self, n: int = 0) -> 'Mint':
        return self
    
    def __floor__(self) -> 'Mint':
        return self
    
    def __ceil__(self) -> 'Mint':
        return self
    
    def __trunc__(self) -> 'Mint':
        return self

def id1(n: int, f: List[Mint], inv: bool) -> None:
    L = 30
    g = [Mint(0)] * L
    ig = [Mint(0)] * L
    p2 = [Mint(0)] * L
    
    def sub(x: List[Mint], y: List[Mint], same: bool) -> None:
        s = 1
        while s < n:
            s *= 2
        
        z = [Mint(0)] * s
        for i in range(n):
            z[i] = x[i]
        
        if not same:
            w = [Mint(0)] * s
            for i in range(n):
                w[i] = y[i]
            
            for i in range(s):
                z[i] *= w[i]
        else:
            for i in range(s):
                z[i] *= z[i]
        
        if inv:
            for i in range(s):
                z[i] *= Mint(s).inv()
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        if not inv:
            for i in range(s):
                z[i] *= Mint(s).inv()
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
            z[i] = int(z[i])
        
        for i in range(s):
            z[i] = Mint(int(z[i]))
        
        for i in range(s):
