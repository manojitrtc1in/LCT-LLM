import sys
from typing import List, Tuple

MOD = 998244353

def solve(n: int, k: int, f: int) -> int:
    ans = 0

    ways = [0] * (f + 2 + f + 2)
    suffix = [0] * (f + 2)

    for i in range(k + 1):
        ways[i] = 1
    ways[f + 1] = max(0, k - f)

    for i in range(n):
        if i < n - 1:
            square(ways)
            suffix[f + 1] = sum(ways[j] for j in range(len(ways) - 1, f, -1)) % MOD
            for j in range(f, -1, -1):
                suffix[j] = (suffix[j + 1] + ways[j]) % MOD

            for j in range(k + 1):
                val = suffix[j]
                val += ways[j] * (k - j)
                val %= MOD
                ways[j] = val

            ways[f + 1] = suffix[f + 1] * max(0, k - f) % MOD
            ways[k + 1:] = [0] * (f + 2)

        else:
            ans = sum(ways[j] * ways[f - j] % MOD for j in range(f + 1)) % MOD

    return ans

def pow(a: int, k: int, p: int) -> int:
    m = k
    ans = 1
    curr = a

    while m > 0:
        if m & 1 == 1:
            ans *= curr
            ans %= p
        m >>= 1
        curr *= curr
        curr %= p

    return ans

def inverse(a: int, p: int) -> int:
    return pow(a, p - 2, p)

def fft(a: List[int], is_inverted_fft: bool) -> None:
    n = len(a)

    for i in range(1, n):
        bit = n >> 1
        j = 0
        while j & bit:
            j ^= bit
            bit >>= 1
        j ^= bit

        if i < j:
            a[i], a[j] = a[j], a[i]

    for length in range(2, n + 1, length << 1):
        wlen = pow(ROOT_INV, length, MOD) if is_inverted_fft else pow(ROOT, length, MOD)
        for i in range(0, n, length):
            w = 1
            for j in range(length // 2):
                u = a[i + j]
                v = a[i + j + length // 2] * w % MOD
                a[i + j] = (u + v) % MOD
                a[i + j + length // 2] = (u - v) % MOD
                w = w * wlen % MOD

    if is_inverted_fft:
        inv = inverse(n, MOD)
        for i in range(n):
            a[i] = a[i] * inv % MOD

def square(a: List[int]) -> None:
    fft(a, False)
    for i in range(len(a)):
        a[i] = a[i] * a[i] % MOD
    fft(a, True)

def main() -> None:
    n, k, f = map(int, input().split())
    ans = solve(n, k, f)
    print(ans)

if __name__ == "__main__":
    main()
