import random
import math

l1, r1, l2, r2 = 0, 0, 0, 0
k = 0

def read():
    global l1, r1, l2, r2, k
    try:
        l1, r1, l2, r2, k = map(int, input().split())
        return True
    except:
        return False

def calc(x):
    s = str(x)
    cur = 1 << (len(s) - 1)
    ans = cur * 2 - 1
    fl = True
    for i in range(len(s)):
        if s[i] > '7':
            ans += 2 * cur
        elif s[i] > '4':
            ans += cur
        if s[i] != '7' and s[i] != '4':
            fl = False
            break
        cur >>= 1
    ans += fl
    return ans

nums = []

def brute(x, num):
    global nums
    nums.append(num)
    if x == 9:
        return
    brute(x + 1, num * 10 + 4)
    brute(x + 1, num * 10 + 7)

def solve():
    global nums
    nums = []
    brute(0, 0)
    nums.sort()
    tot = (r1 - l1 + 1) * (r2 - l2 + 1)

    ok = 0
    for i in range(1, len(nums) - k + 1):
        l = nums[i]
        r = nums[i + k - 1]
        pl = nums[i - 1] + 1
        pr = (nums[i + k] - 1) if (i + k < len(nums)) else math.inf + 7
        if l1 <= l and r <= r2:
            ll = max(l1, pl)
            rr = min(r2, pr)
            ok += max(0, min(l, r1) - ll + 1) * max(0, rr - max(r, l2) + 1)
        if l2 <= l and r <= r1:
            ll = max(l2, pl)
            rr = min(r1, pr)
            ok += max(0, min(l, r2) - ll + 1) * max(0, rr - max(r, l1) + 1)
    if k == 1:
        for it in nums:
            ok -= (l1 <= it <= r1) and (l2 <= it <= r2)

    print(ok / tot)

tc = int(input())
while tc > 0:
    read()
    solve()
    tc -= 1
