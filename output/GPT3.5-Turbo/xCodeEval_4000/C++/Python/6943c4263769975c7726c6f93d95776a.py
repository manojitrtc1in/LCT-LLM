import math

def check(x):
    if x == 2:
        return True
    if x % 4 != 1:
        return False
    
    F = False
    for d in range(2, int(math.sqrt(x)) + 1):
        if x % d == 0:
            return False
        if d * d != x and is_prime[x - d * d]:
            F = True
    return F

l, r = map(int, input().split())
ret = 0
B = 100 * 1000
MN = 3e8 + 10

is_prime = [False] * int(MN)

for d in range(1, int(math.sqrt(MN)) + 1):
    is_prime[d * d] = True

pl = l // B
pr = r // B

if l // B == r // B:
    for i in range(l, r + 1):
        ret += check(i)
    print(ret)
    exit()

for i in range(pl + 1, pr):
    ret += prec[i]

for i in range(l, (pl + 1) * B):
    ret += check(i)

for i in range(r, pr * B - 1, -1):
    ret += check(i)

print(ret)
