import sys
import math
from collections import deque

class ProblemC_76:
    
    def __init__(self):
        self.online_judge = 'ONLINE_JUDGE' in sys.argv
        self.in_file = sys.stdin if self.online_judge else open("input.txt", "r")
        self.out_file = sys.stdout if self.online_judge else open("output.txt", "w")
    
    def read_string(self):
        return next(self.tokenizer)
    
    def read_int(self):
        return int(self.read_string())
    
    def read_long(self):
        return int(self.read_string())
    
    def read_double(self):
        return float(self.read_string())
    
    def run(self):
        try:
            self.tokenizer = iter(self.in_file.read().split())
            self.solve()
        except Exception as e:
            print(e, file=sys.stderr)
            sys.exit(-1)
        finally:
            if not self.online_judge:
                self.in_file.close()
                self.out_file.close()
    
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
        return ProblemC_76.gcd(b % a, a)

    @staticmethod
    def lcm(a, b):
        return a // ProblemC_76.gcd(a, b) * b

    @staticmethod
    def binpow(a, n):
        if n == 0:
            return 1
        if n % 2 == 0:
            b = ProblemC_76.binpow(a, n // 2)
            return b * b
        else:
            return ProblemC_76.binpow(a, n - 1) * a

    @staticmethod
    def binpowmod(a, n, m):
        if m == 1:
            return 0
        if n == 0:
            return 1
        if n % 2 == 0:
            b = ProblemC_76.binpowmod(a, n // 2, m)
            return (b * b) % m
        else:
            return ProblemC_76.binpowmod(a, n - 1, m) * a % m

    @staticmethod
    def phi(n):
        p = ProblemC_76.sieve(int(math.ceil(math.sqrt(n))) + 2)
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
        is_prime = [True] * (n + 1)
        is_prime[0] = is_prime[1] = False
        primes = []
        for i in range(2, n + 1):
            if is_prime[i]:
                primes.append(i)
                for j in range(i * i, n + 1, i):
                    is_prime[j] = False
        return primes

if __name__ == "__main__":
    ProblemC_76().run()
