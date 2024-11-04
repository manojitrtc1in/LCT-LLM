from typing import List, Tuple
import sys

mod = 10**9 + 7

def bits_count(v: int) -> int:
    v = v - ((v >> 1) & 0x55555555)
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333)
    return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24

def bits_count_ll(v: int) -> int:
    t = v >> 32
    p = (v & ((1 << 32) - 1))
    return bits_count(t) + bits_count(p)

def reverse_bits(x: int) -> int:
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1))
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2))
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4))
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8))
    return ((x >> 16) | (x << 16))

def sign(x: int) -> int:
    return (x > 0) - (x < 0)

def id0(x: int) -> bool:
    return x != 0 and (x & (x - 1)) == 0

def is_prime(x: int) -> bool:
    if x < 2:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

def normmod(x: int, m: int) -> int:
    x %= m
    if x < 0:
        x += m
    return x

def id6(x: int, y: int, m: int) -> int:
    res = x + y
    if res >= m:
        res -= m
    return res

def add(x: int, y: int) -> int:
    x += y
    if x >= mod:
        x -= mod
    return x

def id3(v: int) -> int:
    return 1 << (31 - (v.bit_length() - 1))

def solve2(x: int, y: int, k: int, bonus: int = 0) -> int:
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
        res = (txk * ty % mod * (txk + 1 + bonus * 2) + 
                solve2(x - tx, tx, k - tx, bonus + tx) +
                solve2(y - tx, tx, k - tx, bonus + tx) +
                solve2(x - tx, y - tx, k, bonus)) % mod
    else:
        res = (txk * y % mod * (txk + 1 + bonus * 2) + 
               solve2(x - tx, y, k - tx, bonus + tx)) % mod
    
    return res

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    q = int(data[0])
    results = []
    
    for i in range(1, q + 1):
        x1, y1, x2, y2, k = map(int, data[i].split())
        ans = (solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - 
                solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k)) % mod
        if ans < 0:
            ans += mod
        results.append(ans * pow(2, mod - 2, mod) % mod)
    
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()
