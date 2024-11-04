from collections import defaultdict

mod = int(1e9 + 7)

def solve(ind, ti, st, f, pd):
    if ind == n:
        return 1 if st > 0 and f == pd else 0
    if memo[ind][ti][st][f][pd]:
        return dp[ind][ti][st][f][pd]
    
    res = 0
    memo[ind][ti][st][f][pd] = 1
    if ti:
        for i in range(num[ind]):
            if i == 0:
                res += solve(ind + 1, 0, st, f, i)
            if i > 0:
                if st == 0:
                    res += solve(ind + 1, 0, 1, i, i)
                else:
                    res += solve(ind + 1, 0, st, f, i)
        if num[ind] == 0:
            res += solve(ind + 1, 1, st, f, 0)
        else:
            if st == 0:
                res += solve(ind + 1, 1, 1, num[ind], num[ind])
            else:
                res += solve(ind + 1, 1, st, f, num[ind])
    else:
        for i in range(10):
            if i == 0:
                res += solve(ind + 1, 0, st, f, i)
            if i > 0:
                if st == 0:
                    res += solve(ind + 1, 0, 1, i, i)
                else:
                    res += solve(ind + 1, 0, st, f, i)
    
    dp[ind][ti][st][f][pd] = res
    return res

l, r = map(int, input().split())

num = []
while r:
    num.append(r % 10)
    r //= 10
num.reverse()
n = len(num)

ans = 0
dp = [[[[[0] * 10 for _ in range(10)] for _ in range(2)] for _ in range(2)] for _ in range(20)]
memo = [[[[[0] * 10 for _ in range(10)] for _ in range(2)] for _ in range(2)] for _ in range(20)]
ans = solve(0, 1, 0, 0, 0)

num.clear()
dp = [[[[[0] * 10 for _ in range(10)] for _ in range(2)] for _ in range(2)] for _ in range(20)]
memo = [[[[[0] * 10 for _ in range(10)] for _ in range(2)] for _ in range(2)] for _ in range(20)]
k = l
while l:
    num.append(l % 10)
    l //= 10
num.reverse()
n = len(num)
ans -= solve(0, 1, 0, 0, 0)

num.clear()
while k:
    num.append(k % 10)
    k //= 10
ans += 1 if num[0] == num[-1] else 0

print(ans)
