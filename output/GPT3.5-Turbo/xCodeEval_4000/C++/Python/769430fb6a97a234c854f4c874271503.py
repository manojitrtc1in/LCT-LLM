import math

def solve(ind, ti, st, f, pd, dp, memo, num):
    if ind == len(num):
        return (st > 0 and f == pd)
    
    if memo[ind][ti][st][f][pd]:
        return dp[ind][ti][st][f][pd]
    
    res = 0
    memo[ind][ti][st][f][pd] = 1
    
    if ti:
        for i in range(num[ind]):
            if i == 0:
                res += solve(ind + 1, 0, st, f, i, dp, memo, num)
            if i > 0:
                if st == 0:
                    res += solve(ind + 1, 0, 1, i, i, dp, memo, num)
                else:
                    res += solve(ind + 1, 0, st, f, i, dp, memo, num)
        
        if num[ind] == 0:
            res += solve(ind + 1, 1, st, f, 0, dp, memo, num)
        else:
            if st == 0:
                res += solve(ind + 1, 1, 1, num[ind], num[ind], dp, memo, num)
            else:
                res += solve(ind + 1, 1, st, f, num[ind], dp, memo, num)
    
    else:
        for i in range(10):
            if i == 0:
                res += solve(ind + 1, 0, st, f, i, dp, memo, num)
            if i > 0:
                if st == 0:
                    res += solve(ind + 1, 0, 1, i, i, dp, memo, num)
                else:
                    res += solve(ind + 1, 0, st, f, i, dp, memo, num)
    
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
    dp = [[[[[0 for _ in range(10)] for _ in range(10)] for _ in range(2)] for _ in range(2)] for _ in range(20)]
    memo = [[[[[0 for _ in range(10)] for _ in range(10)] for _ in range(2)] for _ in range(2)] for _ in range(20)]
    
    ans = solve(0, 1, 0, 0, 0, dp, memo, num)
    
    num.clear()
    dp = [[[[[0 for _ in range(10)] for _ in range(10)] for _ in range(2)] for _ in range(2)] for _ in range(20)]
    memo = [[[[[0 for _ in range(10)] for _ in range(10)] for _ in range(2)] for _ in range(2)] for _ in range(20)]
    
    k = l
    
    while l:
        num.append(l % 10)
        l //= 10
    
    num.reverse()
    n = len(num)
    ans -= solve(0, 1, 0, 0, 0, dp, memo, num)
    
    num.clear()
    
    while k:
        num.append(k % 10)
        k //= 10
    
    ans += (num[0] == num[len(num) - 1])
    print(ans)

if __name__ == "__main__":
    main()
