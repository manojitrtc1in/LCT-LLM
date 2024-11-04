import sys
import random

MOD = 1000 * 1000 * 1000 + 7

def read_int():
    return int(sys.stdin.readline().strip())

def id5(value):
    print(value)

def solve():
    a = read_int()
    b = read_int()
    
    r = 0
    for i in range(1, b):
        r += i
        if r >= MOD:
            r -= MOD

    res = a * r % MOD

    k = 0
    for i in range(1, a + 1):
        k += i * r % MOD
        if k >= MOD:
            k -= MOD

    res += b * k % MOD
    if res >= MOD:
        res -= MOD

    id5(res)

def main():
    random.seed()
    solve()

if __name__ == "__main__":
    main()
