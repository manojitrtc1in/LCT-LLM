import sys
from collections import defaultdict
import math
import random

mod = 998244353

def main():
    ttt = 1
    while ttt > 0:
        A = input().strip()
        if len(A) == 1 and A[0] == '0':
            print("1")
            return
        if A[0] == '0':
            print("0")
            return
        if len(A) == 1:
            if A[0] == 'X' or A[0] == '_':
                print("1")
                return
        dp = [[[-1] * 11 for _ in range(25)] for _ in range(len(A) + 1)]
        print(go(A, 0, 0, 10, dp))
        ttt -= 1

def go(A, i, pv, v, dp):
    if i == len(A):
        return 1 if pv == 0 else 0
    if dp[i][pv][v] != -1:
        return dp[i][pv][v]
    ans = 0
    if A[i] == '_':
        for j in range(10):
            if i == 0 and j == 0:
                continue
            y = (pv * 10 + j) % 25
            ans += go(A, i + 1, y, v, dp)
    elif A[i] == 'X':
        if v != 10:
            ans += go(A, i + 1, (pv * 10 + v) % 25, v, dp)
        else:
            for j in range(10):
                if i == 0 and j == 0:
                    continue
                y = (pv * 10 + j) % 25
                ans += go(A, i + 1, y, j, dp)
    else:
        ans += go(A, i + 1, (pv * 10 + int(A[i])) % 25, v, dp)
    dp[i][pv][v] = ans
    return ans

def find(A, a):
    if A[a] == a:
        return a
    return find(A, A[a])

def update(bit, i, x):
    while i < len(bit):
        bit[i] += x
        i += (i & -i)

def sum(bit, i):
    ans = 0
    while i > 0:
        ans += bit[i]
        i -= (i & -i)
    return ans

def add(map, v):
    if v not in map:
        map[v] = 1
    else:
        map[v] += 1

def remove(map, v):
    if v in map:
        map[v] -= 1
        if map[v] == 0:
            del map[v]

def upper(A, k, si, ei):
    l, u = si, ei
    ans = -1
    while l <= u:
        mid = (l + u) // 2
        if A[mid] <= k:
            ans = mid
            l = mid + 1
        else:
            u = mid - 1
    return ans

def lower(A, k, si, ei):
    l, u = si, ei
    ans = -1
    while l <= u:
        mid = (l + u) // 2
        if A[mid] <= k:
            l = mid + 1
        else:
            ans = mid
            u = mid - 1
    return ans

def copy(A):
    return A[:]

def input_array(n):
    return list(map(int, input().split()))

def sum_array(A):
    return sum(A)

def reverse(A):
    A.reverse()

def fill(dp):
    for i in range(len(dp)):
        for j in range(len(dp[i])):
            for k in range(len(dp[i][j])):
                dp[i][j][k] = -1

def power(x, y, p):
    if y == 0:
        return 1
    if x == 0:
        return 0
    res = 1
    x = x % p
    while y > 0:
        if y % 2 == 1:
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res

def prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    sq = int(math.sqrt(n))
    for i in range(5, sq + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    return True

if __name__ == "__main__":
    main()
