import sys
import random
from collections import defaultdict
from math import gcd, factorial

MODULO = 1000 * 1000 * 1000 + 7

class E:
    def __init__(self):
        self.inverse_n_minus_1_factorial = 0

    def solve(self):
        n = self.read_int()
        s = self.read_long()
        f = self.read_long_array(n)

        coeffs = defaultdict(int)
        coeffs[0] = 1

        class Pair:
            def __init__(self, power, coeff):
                self.power = power
                self.coeff = coeff

        for size in f:
            coeff_entries = []
            for power, coeff in list(coeffs.items()):
                next_power = power + size + 1
                coeff_entries.append(Pair(next_power, -coeff))

            for coeff_entry in coeff_entries:
                coeffs[coeff_entry.power] += coeff_entry.coeff

        n_minus_1_factorial = self.mult_sequence(1, n - 1)
        self.inverse_n_minus_1_factorial = self.inverse(n_minus_1_factorial)

        answer = 0
        for power, coeff in coeffs.items():
            if s >= power:
                need = s - power
                answer = self.add(answer, self.mult(self.binom(n + need - 1, need), coeff))

        print(answer)

    def mult_sequence(self, start, end):
        res = 1
        for i in range(start, end + 1):
            res = self.mult(res, i)
        return res

    def inverse(self, x):
        return self.binpow(x, MODULO - 2)

    def binpow(self, base, power):
        if power == 0:
            return 1
        if power % 2 == 0:
            half = self.binpow(base, power // 2)
            return self.mult(half, half)
        else:
            prev = self.binpow(base, power - 1)
            return self.mult(prev, base)

    def binom(self, n, k):
        return self.mult(self.mult_sequence(k + 1, n), self.inverse_n_minus_1_factorial)

    def add(self, a, b):
        return (a % MODULO + b % MODULO) % MODULO

    def mult(self, a, b):
        return (a % MODULO) * (b % MODULO) % MODULO

    def read_int(self):
        return int(sys.stdin.readline().strip())

    def read_long(self):
        return int(sys.stdin.readline().strip())

    def read_long_array(self, size):
        return list(map(int, sys.stdin.readline().strip().split()))

    def main(self):
        self.solve()

if __name__ == "__main__":
    E().main()
