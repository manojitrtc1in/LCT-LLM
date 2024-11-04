import sys
from typing import List, Tuple
from collections import defaultdict
from math import pow


MOD = 998244353


def solve(u: List[int], v: List[int], n: int) -> int:
    RADIX = 10
    m = len(u)

    num = [1] * RADIX
    multipliers = [[1] * RADIX for _ in range(RADIX)]

    for i in range(m):
        small = min(u[i], v[i])
        large = max(u[i], v[i])
        multipliers[large][small] = 0

    for _ in range(1, n):
        num2 = [0] * RADIX
        for j in range(RADIX):
            for k in range(RADIX):
                num2[j] += num[k] * multipliers[j][k] % MOD
            num2[j] %= MOD
        num = num2

    return sum(num) % MOD


def main() -> None:
    input = sys.stdin.readline
    output = sys.stdout.write

    t = 1
    for _ in range(t):
        n, m = map(int, input().split())
        u = []
        v = []
        for _ in range(m):
            a, b = map(int, input().split())
            u.append(a)
            v.append(b)
        ans = solve(u, v, n)
        output(str(ans) + '\n')


if __name__ == "__main__":
    main()
