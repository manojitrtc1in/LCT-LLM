from collections import defaultdict
import sys
import math

mod = 10**9 + 7

def bits_count(v):
    v = v - ((v >> 1) & 0x55555555)
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333)
    return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24

def reverse_bits(x):
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1))
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2))
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4))
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8))
    return (x >> 16) | (x << 16)

def sign(x):
    return (x > 0) - (x < 0)

def id0(x):
    return x != 0 and (x & (x - 1)) == 0

def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

def normmod(x, m):
    x %= m
    if x < 0:
        x += m

def id6(x, y, m):
    res = x + y
    if res >= m:
        res -= m
    return res

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def id1(a, b):
    if not a:
        return (0, 1, b)
    y1, x, d = id1(b % a, a)
    x = y1 - (b // a) * x
    return (x, y1, d)

def add(x, y):
    x += y
    if x >= mod:
        x -= mod

def id3(v):
    return 1 << (31 - (v).bit_length() + 1)

def solve2(x, y, k, bonus=0):
    if x <= 0 or y <= 0 or k <= 0:
        return 0
    if x < y:
        x, y = y, x
    if (x & (x - 1)) == 0:
        k = min(k, x)
        return k * y % mod * (k + 1 + bonus * 2) % mod

    ty = id3(y)
    tx = id3(x)
    res = 0
    txk = min(tx, k)

    if tx == ty:
        res = txk * ty % mod * (txk + 1 + bonus * 2) % mod
        add(res, solve2(x - tx, tx, k - tx, bonus + tx))
        add(res, solve2(y - tx, tx, k - tx, bonus + tx))
        add(res, solve2(x - tx, y - tx, k, bonus))
    else:
        res = txk * y % mod * (txk + 1 + bonus * 2) % mod
        add(res, solve2(x - tx, y, k - tx, bonus + tx))

    return res

def main():
    input = sys.stdin.read
    data = input().splitlines()
    q = int(data[0])
    results = []
    
    for i in range(1, q + 1):
        x1, y1, x2, y2, k = map(int, data[i].split())
        ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k)
        ans %= mod
        if ans < 0:
            ans += mod
        results.append(int(ans * pow(2, mod - 2, mod) % mod))
    
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()
