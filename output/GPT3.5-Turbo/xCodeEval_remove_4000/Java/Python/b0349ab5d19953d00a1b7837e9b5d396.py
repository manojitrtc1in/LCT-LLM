import math

class id2:
    def __init__(self):
        self.id5 = True if "id5" in os.environ else False
        self.inp = sys.stdin if self.id5 else open("input.txt", "r")
        self.out = sys.stdout if self.id5 else open("output.txt", "w")
        self.tok = []
    
    def init(self):
        pass
    
    def readString(self):
        while not self.tok:
            self.tok = self.inp.readline().split()
        res = self.tok[0]
        self.tok = self.tok[1:]
        return res
    
    def readInt(self):
        return int(self.readString())
    
    def readLong(self):
        return int(self.readString())
    
    def readDouble(self):
        return float(self.readString())
    
    def run(self):
        try:
            t1 = time.time()
            self.init()
            self.solve()
            self.out.close()
            t2 = time.time()
            print("Time =", t2-t1, file=sys.stderr)
        except Exception as e:
            traceback.print_exc(file=sys.stderr)
            sys.exit(-1)
    
    def solve(self):
        n = self.readInt() - 1
        m = self.readInt()
        a = self.readInt() - 1
        b = self.readInt() - 1
        i = a // m
        j = b // m
        l = a % m
        r = m - 1 if b == n else b % m
        if l == 0 and r == m - 1:
            self.out.write("1")
            return
        if j - i < 2:
            self.out.write(str(j - i + 1))
            return
        if (l != 0 and r == m - 1) or (l == 0 and r != m - 1):
            self.out.write("2")
            return
        if l - r == 1:
            self.out.write("2")
            return
        self.out.write("3")
    
    def gcd(self, a, b):
        if a == 0:
            return b
        return self.gcd(b % a, a)
    
    def lcm(self, a, b):
        return a // self.gcd(a, b) * b
    
    def id8(self, a, b):
        if a == 0:
            return [b, 0, 1]
        d = self.id8(b % a, a)
        r = d[1]
        d[1] = d[2] - b // a * d[1]
        d[2] = r
        return d
    
    def binpow(self, a, n):
        if n == 0:
            return 1
        if n % 2 == 0:
            b = self.binpow(a, n // 2)
            return b * b
        else:
            return self.binpow(a, n - 1) * a
    
    def id1(self, a, n, m):
        if m == 1:
            return 0
        if n == 0:
            return 1
        if n % 2 == 0:
            b = self.id1(a, n // 2, m)
            return (b * b) % m
        else:
            return self.id1(a, n - 1, m) * a % m
    
    def phi(self, n):
        p = self.Sieve(math.ceil(math.sqrt(n)) + 2)
        phi = 1
        for i in range(len(p)):
            x = 1
            while n % p[i] == 0:
                n //= p[i]
                x *= p[i]
            phi *= x - x // p[i]
        if n != 1:
            phi *= n - 1
        return phi
    
    def f(self, n, x, k):
        if n == 0:
            return 1
        b = self.binpow(10, x - 1)
        c = n // b
        return (c if c < k else k) * self.binpow(k, x - 1) + (1 if c < k else 0) * self.f(n % b, x - 1, k)
    
    def fib(self, n):
        if n == 0:
            return 0
        if n % 2 == 0:
            f1 = self.fib(n // 2 - 1)
            f2 = self.fib(n // 2 + 1)
            return f2 * f2 - f1 * f1
        else:
            f1 = self.fib(n // 2)
            f2 = self.fib(n // 2 + 1)
            return f1 * f1 + f2 * f2
    
    def BigFib(self, n):
        if n == 0:
            return 0
        if n % 2 == 0:
            f1 = self.BigFib(n // 2 - 1)
            f1 = f1 * f1
            f2 = self.BigFib(n // 2 + 1)
            f2 = f2 * f2
            return f2 - f1
        else:
            f1 = self.BigFib(n // 2)
            f1 = f1 * f1
            f2 = self.BigFib(n // 2 + 1)
            f2 = f2 * f2
            return f2 + f1
    
    def d(self, p1, p2):
        return math.sqrt(self.d2(p1, p2))
    
    def d2(self, p1, p2):
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])
    
    def id9(self, n):
        if n == 1:
            return False
        if n % 2 == 0:
            return False
        for j in range(3, int(math.sqrt(n)) + 1, 2):
            if n % j == 0:
                return False
        return True
    
    def Sieve(self, n):
        b = [True] * (n + 1)
        b[0] = False
        b[1] = False
        j = 0
        for i in range(1, n + 1):
            if b[i]:
                j += 1
                if i * i <= n:
                    for k in range(i * i, n + 1, i):
                        b[k] = False
        p = [0] * j
        j = 0
        for i in range(2, n + 1):
            if b[i]:
                p[j] = i
                j += 1
        return p
    
    def id0(self, s):
        c = list(s)
        n = len(c)
        d = [[0] * n for _ in range(2)]
        l = 0
        r = -1
        for i in range(n):
            j = (0 if i > r else min(d[0][l + r - i + 1], r - i + 1)) + 1
            while i - j >= 0 and i + j - 1 < n and c[i - j] == c[i + j - 1]:
                j += 1
            d[0][i] = j - 1
            if i + d[0][i] - 1 > r:
                r = i + d[0][i] - 1
                l = i - d[0][i]
        l = 0
        r = -1
        for i in range(n):
            j = (0 if i > r else min(d[1][l + r - i], r - i)) + 1
            while i - j >= 0 and i + j < n and c[i - j] == c[i + j]:
                j += 1
            d[1][i] = j - 1
            if i + d[1][i] > r:
                r = i + d[1][i]
                l = i - d[1][i]
        return d
    
    def Permutation:
        def __init__(self, n):
            self.n = n
            self.a = [0] * n
            for i in range(n):
                self.a[i] = i
        
        def nextPermutation(self):
            i = self.n - 2
            while i >= 0 and self.a[i] >= self.a[i + 1]:
                i -= 1
            if i == -1:
                return False
            jMin = i + 1
            for j in range(self.n - 1, i, -1):
                if self.a[i] < self.a[j] and self.a[j] < self.a[jMin]:
                    jMin = j
            self.swap(i, jMin)
            for j in range(1, (self.n - i) // 2 + 1):
                self.swap(i + j, self.n - j)
            return True
        
        def get(self, i):
            return self.a[i]
        
        def swap(self, i, j):
            r = self.a[i]
            self.a[i] = self.a[j]
            self.a[j] = r
    
    class Fraction:
        def __init__(self, numerator=0, denominator=1):
            self.numerator = numerator
            self.denominator = denominator
            self.Cancellation()
        
        def Cancellation(self):
            g = self.gcd(abs(self.numerator), abs(self.denominator))
            self.numerator //= g
            self.denominator //= g
            if self.denominator < 0:
                self.numerator *= -1
                self.denominator *= -1
        
        def __str__(self):
            s = ""
            if self.numerator == 0:
                return "0"
            if self.numerator < 0:
                s += "-"
            if abs(self.numerator) >= self.denominator:
                s += str(abs(self.numerator) // self.denominator) + " "
            if abs(self.numerator) % self.denominator != 0:
                s += str(abs(self.numerator) % self.denominator)
            else:
                s = s[:-1]
            if self.denominator != 1:
                s += "/" + str(self.denominator)
            return s
        
        def add(self, f):
            fResult = Fraction()
            fResult.denominator = self.lcm(self.denominator, f.denominator)
            fResult.numerator = self.numerator * fResult.denominator // self.denominator + f.numerator * fResult.denominator // f.denominator
            fResult.Cancellation()
            return fResult
        
        def subtract(self, f):
            fResult = Fraction()
            fResult.denominator = self.lcm(self.denominator, f.denominator)
            fResult.numerator = self.numerator * fResult.denominator // self.denominator - f.numerator * fResult.denominator // f.denominator
            fResult.Cancellation()
            return fResult
        
        def multiply(self, f):
            fResult = Fraction()
            fResult.numerator = self.numerator * f.numerator
            fResult.denominator = self.denominator * f.denominator
            fResult.Cancellation()
            return fResult
        
        def divide(self, f):
            fResult = Fraction()
            fResult.numerator = self.numerator * f.denominator
            fResult.denominator = self.denominator * f.numerator
            fResult.Cancellation()
            return fResult
        
        def __lt__(self, f):
            g = self.gcd(self.denominator, f.denominator)
            res = self.numerator * (f.denominator // g) - f.numerator * (self.denominator // g)
            if res < 0:
                return True
            if res > 0:
                return False
            return False
        
        def clone(self):
            fResult = Fraction(self.numerator, self.denominator)
            return fResult
        
        def floor(self):
            fResult = self.clone()
            fResult.numerator = (fResult.numerator // fResult.denominator) * fResult.denominator
            return fResult
        
        def ceil(self):
            fResult = self.clone()
            fResult.numerator = ((fResult.numerator // fResult.denominator) + 1) * fResult.denominator
            return fResult
        
        def binpow(self, n):
            if n == 0:
                return Fraction(1)
            if n % 2 == 0:
                f = self.binpow(n // 2)
                return f.multiply(f)
            else:
                return self.binpow(n - 1).multiply(self)
        
        def gcd(self, a, b):
            if a == 0:
                return b
            return self.gcd(b % a, a)
        
        def lcm(self, a, b):
            return a // self.gcd(a, b) * b
    
    def main():
        id2().run()
    
    if __name__ == "__main__":
        main()
