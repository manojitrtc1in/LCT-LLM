import math

def umax(a, b):
    if a < b:
        a = b

def umin(a, b):
    if a > b:
        a = b

def abs(a):
    if a > 0:
        return a
    else:
        return -a

def gcd(a, b):
    return math.gcd(a, b)

def lcm(a, b):
    return a // gcd(a, b) * b

def modpow(a, n, temp):
    res = 1
    y = a
    while n > 0:
        if n & 1:
            res = (res * y) % temp
        y = (y * y) % temp
        n //= 2
    return res % temp

def ison(mask, pos):
    return (mask & (1 << pos))

def cbit(n):
    k = 0
    while n:
        n &= (n - 1)
        k += 1
    return k

def nbit(n):
    k = 0
    while n:
        n //= 2
        k += 1
    return k

mod = 10**9 + 7

def sgn(x):
    return -1 if x < 0 else bool(x)

eps = 1e-7
pi = math.acos(-1.0)

def inc(x, y):
    x += y
    if x >= mod:
        x -= mod

def dec(x, y):
    x -= y
    if x < 0:
        x += mod

def chmax(x, y):
    if y > x:
        x = y

def mulm(x, y):
    x *= y
    if x >= mod:
        x -= mod

def xo(i):
    if (i & 3) == 0:
        return i
    if (i & 3) == 1:
        return 1
    if (i & 3) == 2:
        return i + 1
    return 0

def solve(ind, ti, st, f, pd, dp, memo, num, n):
    if ind == n:
        return (st > 0) and (f == pd)
    if memo[ind][ti][st][f][pd]:
        return dp[ind][ti][st][f][pd]
    res = 0
    memo[ind][ti][st][f][pd] = 1
    if ti:
        for i in range(num[ind]):
            if i == 0:
                res += solve(ind + 1, 0, st, f, i, dp, memo, num, n)
            if i > 0:
                if st == 0:
                    res += solve(ind + 1, 0, 1, i, i, dp, memo, num, n)
                else:
                    res += solve(ind + 1, 0, st, f, i, dp, memo, num, n)
        if num[ind] == 0:
            res += solve(ind + 1, 1, st, f, 0, dp, memo, num, n)
        else:
            if st == 0:
                res += solve(ind + 1, 1, 1, num[ind], num[ind], dp, memo, num, n)
            else:
                res += solve(ind + 1, 1, st, f, num[ind], dp, memo, num, n)
    else:
        for i in range(10):
            if i == 0:
                res += solve(ind + 1, 0, st, f, i, dp, memo, num, n)
            if i > 0:
                if st == 0:
                    res += solve(ind + 1, 0, 1, i, i, dp, memo, num, n)
                else:
                    res += solve(ind + 1, 0, st, f, i, dp, memo, num, n)
    dp[ind][ti][st][f][pd] = res
    return res

def main():
    l, r = map(int, input().split())
    num = []
    while r:
        num.append(r % 10)
        r //= 10
    num.reverse()
    n = len(num)
    ans = 0
    dp = [[[[[0] * 10] * 10] * 2] * 2] * 20
    memo = [[[[[0] * 10] * 10] * 2] * 2] * 20
    ans = solve(0, 1, 0, 0, 0, dp, memo, num, n)
    num.clear()
    dp = [[[[[0] * 10] * 10] * 2] * 2] * 20
    memo = [[[[[0] * 10] * 10] * 2] * 2] * 20
    k = l
    while l:
        num.append(l % 10)
        l //= 10
    num.reverse()
    n = len(num)
    ans -= solve(0, 1, 0, 0, 0, dp, memo, num, n)
    num.clear()
    while k:
        num.append(k % 10)
        k //= 10
    ans += (num[0] == num[n - 1])
    print(ans)

if __name__ == "__main__":
    main()
