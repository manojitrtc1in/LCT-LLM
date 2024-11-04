import sys
import math
from collections import defaultdict

class Id2:
    
    def __init__(self):
        self.id5 = 'id5' in sys.argv
        self.in_file = sys.stdin if self.id5 else open("input.txt", "r")
        self.out_file = sys.stdout if self.id5 else open("output.txt", "w")
        self.tok = []

    def read_string(self):
        while not self.tok:
            self.tok = self.in_file.readline().strip().split()
        return self.tok.pop(0)

    def read_int(self):
        return int(self.read_string())

    def read_long(self):
        return int(self.read_string())

    def read_double(self):
        return float(self.read_string())

    def run(self):
        try:
            t1 = int(round(time.time() * 1000))
            self.solve()
            self.out_file.close()
            t2 = int(round(time.time() * 1000))
            print("Time =", t2 - t1, file=sys.stderr)
        except Exception as e:
            print(e, file=sys.stderr)
            sys.exit(-1)

    def solve(self):
        n = self.read_int() - 1
        m = self.read_int()
        a = self.read_int() - 1
        b = self.read_int() - 1
        i = a // m
        j = b // m
        l = a % m
        r = b if b == n else b % m

        if l == 0 and r == m - 1:
            print(1, file=self.out_file)
            return
        if j - i < 2:
            print(j - i + 1, file=self.out_file)
            return
        if (l != 0 and r == m - 1) or (l == 0 and r != m - 1):
            print(2, file=self.out_file)
            return
        if l - r == 1:
            print(2, file=self.out_file)
            return
        print(3, file=self.out_file)

    @staticmethod
    def gcd(a, b):
        if a == 0:
            return b
        return Id2.gcd(b % a, a)

    @staticmethod
    def lcm(a, b):
        return a // Id2.gcd(a, b) * b

    @staticmethod
    def binpow(a, n):
        if n == 0:
            return 1
        if n % 2 == 0:
            b = Id2.binpow(a, n // 2)
            return b * b
        else:
            return Id2.binpow(a, n - 1) * a

    @staticmethod
    def phi(n):
        p = Id2.sieve(int(math.ceil(math.sqrt(n))) + 2)
        phi = 1
        for prime in p:
            x = 1
            while n % prime == 0:
                n //= prime
                x *= prime
            phi *= x - x // prime
        if n != 1:
            phi *= n - 1
        return phi

    @staticmethod
    def sieve(n):
        b = [True] * (n + 1)
        b[0] = b[1] = False
        primes = []
        for i in range(2, n + 1):
            if b[i]:
                primes.append(i)
                for j in range(i * i, n + 1, i):
                    b[j] = False
        return primes

if __name__ == "__main__":
    Id2().run()
