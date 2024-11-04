import math

def gooood(x):
    if x < 3:
        return x == 2
    if (x & 3) != 1:
        return False
    top = int(math.sqrt(x))
    for i in range(2, top+1):
        if x % i == 0:
            return False
    return True

l = int(input())
r = int(input())
lb = math.ceil(l / 100000)
rb = math.ceil(r / 100000)
ans = 0

if lb == rb:
    for i in range(l, r+1):
        if gooood(i):
            ans += 1
    print(ans)
else:
    for i in range(lb + 1, rb - 1):
        ans += a[i]
    for i in range(l, lb * 100000 + 1):
        if gooood(i):
            ans += 1
    for i in range((rb - 1) * 100000 + 1, r+1):
        if gooood(i):
            ans += 1
    print(ans)
