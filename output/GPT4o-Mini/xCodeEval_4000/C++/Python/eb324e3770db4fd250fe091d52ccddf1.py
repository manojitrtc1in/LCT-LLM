import sys
import math
from collections import defaultdict
from functools import reduce

mod = 1000000007

def add(x, y):
    x += y
    if x >= mod:
        x -= mod
    return x

def sub(x, y):
    x -= y
    if x < 0:
        x += mod
    return x

def powlog2(v):
    return 1 << (31 - (v.bit_length() - 1))

def solve2(x, y, k, bonus=0):
    if x <= 0 or y <= 0 or k <= 0:
        return 0
    if x < y:
        x, y = y, x
    if (x & (x - 1)) == 0 and (y & (y - 1)) == 0:
        k = min(k, x)
        return k * y % mod * (k + 1 + bonus * 2) % mod
    
    ty = powlog2(y)
    tx = powlog2(x)
    res = 0
    txk = min(tx, k)
    
    if tx == ty:
        res = txk * ty % mod * (txk + 1 + bonus * 2) % mod
        res = add(res, solve2(x - tx, tx, k - tx, bonus + tx))
        res = add(res, solve2(y - tx, tx, k - tx, bonus + tx))
        res = add(res, solve2(x - tx, y - tx, k, bonus))
    else:
        res = txk * y % mod * (txk + 1 + bonus * 2) % mod
        res = add(res, solve2(x - tx, y, k - tx, bonus + tx))
    
    return res

def main():
    input = sys.stdin.read
    data = input().split()
    
    q = int(data[0])
    index = 1
    results = []
    
    for _ in range(q):
        x1 = int(data[index])
        y1 = int(data[index + 1])
        x2 = int(data[index + 2])
        y2 = int(data[index + 3])
        k = int(data[index + 4])
        index += 5
        
        ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k)
        ans %= mod
        if ans < 0:
            ans += mod
        
        results.append(ans * pow(2, mod - 2, mod) % mod)
    
    print("\n".join(map(str, results)))

if __name__ == "__main__":
    main()
