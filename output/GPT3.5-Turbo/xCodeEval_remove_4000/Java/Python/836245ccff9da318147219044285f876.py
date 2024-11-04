import sys
from typing import List
from random import randint

class FastReader:
    def __init__(self):
        self.buffer = []
        self.pointer = 0
    
    def next(self) -> str:
        if self.pointer >= len(self.buffer):
            self.buffer = input().split()
            self.pointer = 0
        self.pointer += 1
        return self.buffer[self.pointer - 1]
    
    def nextInt(self) -> int:
        return int(self.next())
    
    def nextLong(self) -> int:
        return int(self.next())
    
    def nextDouble(self) -> float:
        return float(self.next())
    
    def nextLine(self) -> str:
        return input()

class id1:
    def __init__(self):
        self.mod = 1000000007
        self.mod2 = 998244353
        self.inp = FastReader()
    
    def main(self):
        n = self.inp.nextInt()
        a = [0] * n
        self.input(a, n)
        
        if n > 66:
            print(1)
            return
        
        pref = [0] * (n + 1)
        pref[1] = a[0]
        for i in range(1, n):
            pref[i + 1] = pref[i] ^ a[i]
        
        gg = 34
        for c in range(n - 1):
            for left in range(c, -1, -1):
                for right in range(c + 1, n):
                    if self.xor(left, c) > self.xor(c + 1, right):
                        gg = min(gg, right - left - 1)
        
        print(gg if gg != 34 else -1)
    
    def xor(self, i: int, j: int) -> int:
        return pref[j + 1] ^ pref[i]
    
    def sort(self, a: List[int]) -> None:
        a.sort()
    
    def id0(self, a: List[int]) -> None:
        n = len(a)
        for i in range(n):
            j = randint(0, n - 1)
            a[i], a[j] = a[j], a[i]
        a.sort()
    
    def fact(self, n: int) -> List[int]:
        fact = [0] * (n + 1)
        fact[0] = 1
        for i in range(1, n + 1):
            fact[i] = self.mul(i, fact[i - 1])
        return fact
    
    def invFact(self, fact: List[int], n: int) -> List[int]:
        invFact = [0] * (n + 1)
        invFact[n] = self.power(fact[n], self.mod - 2)
        for i in range(n - 1, -1, -1):
            invFact[i] = self.mul(invFact[i + 1], i + 1)
        return invFact
    
    def init(self, n: int) -> None:
        fact = self.fact(n)
        invFact = self.invFact(fact, n)
        return fact, invFact
    
    def modInv(self, x: int) -> int:
        return self.power(x, self.mod - 2)
    
    def nCr(self, fact: List[int], invFact: List[int], n: int, r: int) -> int:
        if n < r or r < 0:
            return 0
        return self.mul(fact[n], self.mul(invFact[r], invFact[n - r]))
    
    def mul(self, a: int, b: int) -> int:
        return a * b % self.mod
    
    def add(self, a: int, b: int) -> int:
        return (a + b) % self.mod
    
    def power(self, x: int, y: int) -> int:
        gg = 1
        while y > 0:
            if y % 2 == 1:
                gg = self.mul(gg, x)
            x = self.mul(x, x)
            y //= 2
        return gg
    
    @staticmethod
    def gcd(a: int, b: int) -> int:
        return a if b == 0 else id1.gcd(b, a % b)
    
    def printList(self, a: List[int]) -> None:
        print(" ".join(map(str, a)))
    
    def input(self, a: List[int], n: int) -> None:
        for i in range(n):
            a[i] = self.inp.nextLong()

if __name__ == "__main__":
    g = id1()
    g.main()
