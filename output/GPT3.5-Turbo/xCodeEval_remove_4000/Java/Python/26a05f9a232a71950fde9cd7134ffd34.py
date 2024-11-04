import sys
from collections import defaultdict
from math import comb

MODULO = 1000 * 1000 * 1000 + 7

def solve():
    n = int(input())
    s = int(input())

    f = id12(n)

    coeffs = defaultdict(int)
    coeffs[0] = 1

    class Pair:
        def __init__(self, power, coeff):
            self.power = power
            self.coeff = coeff

    for size in f:
        coeffEntries = []
        for power, coeff in coeffs.items():
            nextPower = power + size + 1
            coeffEntries.append(Pair(nextPower, -coeff))

        for coeffEntry in coeffEntries:
            coeffs[coeffEntry.power] += coeffEntry.coeff

    id25 = multSequence(1, n - 1)
    id34 = inverse(id25)

    answer = 0
    for power, coeff in coeffs.items():
        if s >= power:
            need = s - power
            answer = add(answer, mult(comb(n + need - 1, need), coeff))

    print(answer)

def multSequence(start, end):
    res = 1
    for i in range(start, end + 1):
        res = mult(res, i)

    return res

def inverse(x):
    return binpow(x, MODULO - 2)

def binpow(base, power):
    if power == 0:
        return 1

    if power & 1 == 0:
        half = binpow(base, power >> 1)
        return mult(half, half)
    else:
        prev = binpow(base, power - 1)
        return mult(prev, base)

def binom(n, k):
    return mult(multSequence(k + 1, n), id34)

def add(a, b):
    return ((a % MODULO + b % MODULO) % MODULO + MODULO) % MODULO

def mult(a, b):
    return (a % MODULO) * (b % MODULO) % MODULO

def main():
    solve()

if __name__ == "__main__":
    main()
