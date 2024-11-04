import math

def prime(x):
    if x < 2:
        return False
    j = 2
    while j * j <= x:
        if x % j == 0:
            return False
        if j == 2:
            j += 1
        else:
            j += 2
    return True

def ans(x):
    j = x // 100000
    ret = 0
    if x >= 2:
        ret += 1
    for i in range(j + 1):
        ret += f[i]
    if j > 0:
        ret -= 1

    b = j * 100000
    b += 1
    
    for i in range(b, x + 1, 4):
        if prime(i):
            ret += 1
    return ret

l, r = map(int, input().split())

print(ans(r) - ans(l - 1))
