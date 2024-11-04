from collections import defaultdict
import sys

mod = 10**9 + 7

def bits_count(v):
    v = v - ((v >> 1) & 0x55555555)
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333)
    return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24

def bits_count_ll(v):
    t = v >> 32
    p = (v & ((1 << 32) - 1))
    return bits_count(t) + bits_count(p)

def reverse_bits(x):
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1))
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2))
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4))
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8))
    return ((x >> 16) | (x << 16))

def sign(x):
    return (x > 0) - (x < 0)

def id0(x):
    return x != 0 and (x & (x - 1)) == 0

def print_array(a):
    print(" ".join(map(str, a)))

def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

def normmod(x, m):
    x %= m
    if x < 0:
        x += m

def id5(x, y, m):
    res = x + y
    if res >= m:
        res -= m
    return res

def add(x, y):
    x += y
    if x >= mod:
        x -= mod

def sub(x, y):
    x -= y
    if x < 0:
        x += mod

def solve2(x, y, k, bonus=0):
    if x <= 0 or y <= 0 or k <= 0:
        return 0
    if x < y:
        x, y = y, x
    ty = 1
    while ty * 2 <= y:
        ty *= 2
    tx = 1
    while tx * 2 <= x:
        tx *= 2
    res = 0
    txk = min(tx, k)
    if tx == ty:
        res = txk * (txk + 1) % mod * ty + bonus * txk * 2 % mod * ty
        res %= mod
        add(res, solve2(x - tx, tx, k - tx, bonus + tx))
        add(res, solve2(y - tx, tx, k - tx, bonus + tx))
        add(res, solve2(x - tx, y - tx, k, bonus))
    else:
        res = txk * (txk + 1) % mod * y + bonus * txk * 2 % mod * y
        res %= mod
        add(res, solve2(x - tx, y, k - tx, bonus + tx))
    return res

def powmod(x, n, m):
    res = 1
    while n:
        if n & 1:
            res = (res * x) % m
        x = (x * x) % m
        n >>= 1
    return res

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

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
        results.append(ans * powmod(2, mod - 2, mod) % mod)
    
    print("\n".join(map(str, results)))

if __name__ == "__main__":
    main()
