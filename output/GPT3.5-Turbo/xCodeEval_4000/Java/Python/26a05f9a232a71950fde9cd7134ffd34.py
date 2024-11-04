import math
import sys
from collections import defaultdict
from typing import List, Tuple


def solve() -> None:
    n, s = map(int, input().split())
    f = list(map(int, input().split()))

    coeffs = defaultdict(int)
    coeffs[0] = 1

    for size in f:
        coeff_entries = []
        for power, coeff in coeffs.items():
            next_power = power + size + 1
            coeff_entries.append((next_power, -coeff))

        for power, coeff in coeff_entries:
            coeffs[power] += coeff

    n_minus_1_factorial = mult_sequence(1, n - 1)
    inverse_n_minus_1_factorial = inverse(n_minus_1_factorial)

    answer = 0
    for power, coeff in coeffs.items():
        if s >= power:
            need = s - power
            answer = add(answer, mult(binom(n + need - 1, need), coeff))

    print(answer)


def mult_sequence(start: int, end: int) -> int:
    res = 1
    for i in range(start, end + 1):
        res = mult(res, i)

    return res


def inverse(x: int) -> int:
    return binpow(x, MODULO - 2)


def binpow(base: int, power: int) -> int:
    if power == 0:
        return 1

    if power & 1 == 0:
        half = binpow(base, power >> 1)
        return mult(half, half)
    else:
        prev = binpow(base, power - 1)
        return mult(prev, base)


def binom(n: int, k: int) -> int:
    return mult(mult_sequence(k + 1, n), inverse_n_minus_1_factorial)


def add(a: int, b: int) -> int:
    return ((a % MODULO + b % MODULO) % MODULO + MODULO) % MODULO


def mult(a: int, b: int) -> int:
    return (a % MODULO) * (b % MODULO) % MODULO


def main() -> None:
    n = int(input())
    s = int(input())
    f = list(map(int, input().split()))

    coeffs = defaultdict(int)
    coeffs[0] = 1

    for size in f:
        coeff_entries = []
        for power, coeff in coeffs.items():
            next_power = power + size + 1
            coeff_entries.append((next_power, -coeff))

        for power, coeff in coeff_entries:
            coeffs[power] += coeff

    n_minus_1_factorial = mult_sequence(1, n - 1)
    inverse_n_minus_1_factorial = inverse(n_minus_1_factorial)

    answer = 0
    for power, coeff in coeffs.items():
        if s >= power:
            need = s - power
            answer = add(answer, mult(binom(n + need - 1, need), coeff))

    print(answer)


if __name__ == "__main__":
    MODULO = 1000 * 1000 * 1000 + 7
    main()
